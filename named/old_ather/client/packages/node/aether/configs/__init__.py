from ..io.logger import Logger
from .settings import W3Settings
from generality.fileIO import _readFile
from os.path import isdir,isfile
from web3 import Web3


class Configuration( Logger , W3Settings ):
	def __init__( self ):
		self.config = _readFile( self._confPath , True )
		Logger.__init__( self )
		W3Settings.__init__( self )
		if not set( ['CALLER', 'CHAINS', 'AETHER'] ).issubset( set( self.config.keys() ) ) :
			self.log_error( 3 , set( self.config.keys() ) )
		try:
			for i in list( self.config.keys() ):
				if i == 'CALLER' :
					assert self.config[i]['pvtKey']  != '' , _getAssertStr( 1 )
					assert self.config[i]['pubKey']  != '' , _getAssertStr( 2 )
				elif ( i == 'CHAINS' ):
					assert type( self.config[i]['chainIds'] ) == list , _getAssertStr( 3 )
					assert len( self.config[i]['chainIds'] ) >= 1 , _getAssertStr( 4 )
					for j in self.config[i]['chainIds']:
						assert str( j ) in list( self.config[i].keys() ) , _getAssertStr( 5 )
				else:
					continue
		except:
			self.log_error( 3 )		

	def conf_chains( self , return_type=str ):

		return [int( _chain ) if return_type == int else str( _chain ) for _chain in self.config['CHAINS']['chainIds']]

	def chain_wss( self , chainId=0 ):

		return self.config['CHAINS'][str( chainId )][ 'wss' ]

	def chain_contracts( self , chainId=0 ):
		
		return self.config['AETHER']['contracts']

	def contract_mirrors( self , contract_name , event_name='' ):
		_idx = self.config['AETHER']['contracts'].index( contract_name )
		if event_name:
			return self.config['AETHER']['mirrors'][_idx].get( event_name , None )
		return self.config['AETHER']['mirrors'][_idx]		

	def contract_abi( self , contract_name ):
		_idx = self.config['AETHER']['contracts'].index( contract_name )
		return self.config['AETHER']['abis'][_idx]

	def contract_address( self , chainId , contract_name ):
		_idx = self.config['AETHER']['contracts'].index( contract_name )
		return self.config['AETHER']['addresses'][_idx]

	def sign( self , transaction ):

		return Web3().eth.account.sign_transaction( transaction , private_key=self.config['CALLER']['pvtKey'] )

	def caller( self ):

		return self.config['CALLER']['pubKey']

