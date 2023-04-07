from dataclasses import dataclass,field
from functools import wraps
from copy import deepcopy
from .utils import _readFile
from .utils.types import Trigger
from .configs import safe_configurize,pathify
from .logging import Logger
from .interactions import start,make_all
from .errors import ParsrErr

'''

						MORS 
				Mirror-Or-Reply Server

mors attributes 
	
	chain_ids	::	list of strings for all chain_ids
	pvt_key		::	used for signing transactions
	pub_key		::	used in view functions 
	interfaces	::	reconfigured abi to contain a dict of `functions` && `events`
	contracts	::	list of contract names
	addresses	::	respective addresses


THE ONLY THING CURRENTLY MISSING FROM THIS AWESOME AWESOME PACKAGE
is the :
	all_chains( mors , func , chains=chain_ids )
'''





class MORS( object ):
	def __init__( self , executer , config , log_path='' , exec_path='' ):
		safe_configurize( self , _readFile( config , True ) if type( config ) == str else config )
		make_all( self )
		self.log = Logger()
		self.LISTENERS = dict()
		self.pollInterval = 5

	def _event( self , event_name ):
		for idx,iFace in enumerate( self.interfaces ):
			for event in iFace.get( 'events' ):
				if event.get( 'name' ) == event_name:
					return ( event_name , self.contracts[idx] , self.addresses[idx] )
		raise ParsrErr( 'event_not_found' , event_name )

	def registerTrigger( self , name , contract , chains , callback , addresses ):
		if name in self.LISTENERS.keys():
			_mirror = self.LISTENERS.get( name , None )
			assert _mirror and not any( [] )
		assert name and name not in self.LISTENERS.keys() , 'Found Duplicate MOR for < %s > event'%name
		self.LISTENERS.update( { name : Trigger( self , name , contract , callback , chains , addresses ) } )

	def event( self , name , contract='' , chains=[] , func=None ):
		_name = name if type( name ) == list else [name] 
		( e_name , e_contract , e_address ) = self._event( name )
		_contract = contract if contract else e_contract 
		_chains = chains if type( chains ) == list else [chains]
		if any( _chains ):
			assert set( [str( c ) for c in _chains] ).issubset( self.chain_ids ) , "One or more of chains : < %s > are not configured"%_chains
		else:
			_chains = self.chain_ids
		_addresses = e_address if type( e_address ) == list else [e_address]
		@wraps( func )
		def decorator_event( func ):
			assert callable( func ) , "Callback function not defined."
			return self.registerTrigger( name , _contract , _chains , func , _addresses )
		return decorator_event

	def run( self ):
		for _chain in self.chain_ids:
			self.log.console_log( CID=_chain , CONNECTED=True )
		self.log.console_log( 'Running...  Press ( CTRL + C to exit )\n' )
		start( self )