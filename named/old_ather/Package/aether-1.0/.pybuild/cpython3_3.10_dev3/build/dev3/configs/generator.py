from inspect import getmembers,isclass,isfunction
from web3 import Web3
from os.path import isfile
from json import loads,dumps
from ..utils import lister,_readFile,_writeFile,to_snake_case
from ..errors import GeneratorError
from ..utils.w3 import connect_wss,get_balance,ZERO_ADDRESS
from ..utils.formatting import mkdict
from .constants import chain_names,chain_symbols,chain_ids,cid_chains



''' L(isten) E(valuate) S(end)'''
class LES:
	def __init__( self , _dirpath : str ):
		self.default = mkdict( 'IDENTITY' , {'interfaces':[],'contracts':[],'addresses':[]} )
		self.__update( mkdict( 'CHAINS' , {'chain_ids':[]} ) )
		self.__update( mkdict( 'CALLER' , {} ) )
		self._defaultPath = _dirpath

	def __EVENT( self , e_abi ):
		e_name = e_abi.get( 'name' , None )
		assert e_name , 'Unknown event name'
		return { 'name' : e_name , 'abi' : e_abi }

	def __FUNCTION( self , f_abi ):
		f_name = f_abi.get( 'name' , None )
		f_type = f_abi.get( 'stateMutability' , None )
		return { 'name' : f_name , 'type' : f_type , 'abi' : f_abi }

	@lister
	def __INTERFACE( self , contract_abis ):
		_abis = list( filter( lambda _abi : len( _abi ) != 0 , contract_abis ) )
		self.__howWhich = []
		for __abi in _abis:
			_events = [ self.__EVENT( _e ) for _e in filter( lambda abi_ : abi_.get('type') == 'event' , __abi )  ]
			_functions = [ self.__FUNCTION( _f ) for _f in filter( lambda _abi : _abi.get('type') == 'function' , __abi )  ]
			self.__howWhich.append( { 'events': _events , 'functions': _functions , 'abi': __abi } )
		self.default['IDENTITY']['interfaces'].extend( self.__howWhich )
		return self.__howWhich

	@lister
	def __CONTRACTS( self , contract_names ):
		self.__connectTo = [cn for cn in contract_names]
		if len( self.__connectTo ) == 0 :
			raise GeneratorError( 'Unable to create an IDENTITY.\nNo contract connections specified, add contracts in env file `CONNECT_TO`.' )
		self.default['IDENTITY']['contracts'].extend( self.__connectTo )
		return self.__connectTo

	@lister
	def __ADDRESSES( self , contract_addresses ):
		self.__reflectAt = list( filter( lambda _addr : _addr != ZERO_ADDRESS , contract_addresses ) )
		self.default['IDENTITY']['addresses'].extend( self.__reflectAt )
		return self.__reflectAt

	def __update( self , _dict ):
		
		return self.default.update( _dict )

	def __fromKEY( self , _pvt_key : str ) -> dict :
		try:
			_w3 = Web3()
			pub_key = _w3.eth.account.from_key( _pvt_key ).address
			return {'pvt_key' : _pvt_key, 'pub_key' : pub_key}
		except:
			raise GeneratorError( 'Cannot generate public key from private key supplied.' , _pvt_key )

	def _getChainName( self , _chainProp : str ) -> str :
		chain_name = chain_names.get( _chainProp , None )
		if not chain_name:
			return to_snake_case( _chainProp )
			# raise GeneratorError( 'Unknown chain name' , _chainProp )
		return chain_name

	def _getChainSymbol( self , _chainName : str ) -> str :
		chain_symbol = chain_symbols.get( _chainName , None )
		if not chain_symbol:
			return _chainName[:3]
			# raise GeneratorError( 'Unknown chain symbol' , _chainName )
		return chain_symbol

	def _getChainId( self , _chainSymbol : str , _chainURL ) -> str :
		chain_id = chain_ids.get( _chainSymbol , None )
		if not chain_id:
			try:
				_w3 = connect_wss( _chainURL )
				chain_id = _w3.eth.chain_id
			except:
				raise GeneratorError( 'Cannot Establish WSS Connection' , _chainURL )
		return chain_id

	def _getChainProps( self , _chainProp ):
		( _chainURL , _chainName ) = _chainProp
		_name = self._getChainName( _chainName )
		_symbol = self._getChainSymbol( _name )
		_id = self._getChainId( _symbol , _chainURL )
		return ( _name , _symbol , _id )

	def _getDynamicConfig( self , envJSON : dict , wssJSON : dict , abisJSON : dict ) -> dict :
		__connect = self.__CONTRACTS( envJSON.get( 'CONNECT_TO' ) )
		self.__ADDRESSES( [envJSON.get( i ) for i in __connect] )
		self.__INTERFACE( [abisJSON.get( i ) for i in __connect] )

		_chains = []
		for idx,_cWSS in enumerate( wssJSON ):
			wssURL = wssJSON.get( _cWSS )
			if wssURL != 'NE' :
				_chains.append( ( wssURL , _cWSS ) )

		_chainProps = [self._getChainProps( i ) for i in _chains]
		_chain_ids = [str( i[-1] ) for i in _chainProps]
		_chainWSS = [i[0] for i in _chains]
		assert all( [connect_wss( wss_endpoint ).isConnected() for wss_endpoint in _chainWSS] ) , 'Cannot connect to all chains with supplied WSS endpoint'

		self.__update( mkdict( 'CHAINS' , mkdict( 'chain_ids' , _chain_ids ) ) )
		self.__update( mkdict( 'CALLER', self.__fromKEY( envJSON['CALLER_PVTKEY'] ) ) )

		for idx,_ in enumerate( _chain_ids ):
			self.default['CHAINS'].update( mkdict( _ , {
					'wss': _chainWSS[idx],
					'balance': get_balance( connect_wss( _chainWSS[idx] ) , self.default['CALLER']['pub_key'] ),
					'chain_id': int( _ ),
					'chain_name' : _chainProps[idx][0],
					'chain_symbol' : _chainProps[idx][1],
				} ) )
		return True

	''' would be a better implementation if annonymous events are used ''' 
	def _getAbiEvents( self , _contractAbi : list ) -> dict :
		
		return list( filter( lambda itm: itm.get( 'type' ) == 'event' , _contractAbi ) )

	def secure_class( self , class_name : str ):

		return '%s'%to_snake_case( str( class_name.replace( '.' , '' ) ) )

	def remake( self ) -> dict:
		_env = _readFile( '%s/%s'%( self._defaultPath , 'env.json' ) , True )
		_wss = _readFile( '%s/%s'%( self._defaultPath , 'rpc.json' ) , True )
		_abis = _readFile( '%s/%s'%( self._defaultPath , 'ABIS.json' ) , True )
		self._getDynamicConfig( _env , _wss , _abis )
		_writeFile( '%s/%s'%( self._defaultPath , 'config.json' ) , self.default , True , True )


