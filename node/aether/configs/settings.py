from generality.key_value import mkdict
from generality.w3 import init_contract,connect_wss
from ..utils import all_of
from .. import onchain
from copy import deepcopy

'''
	self.w3 = {
		conn_cidN = Web3(wss_n),
		conn_cidM,
		conn_cidN_contractK = Web3.eth.contract(addr&abi for contractK),
		conn_cidM_contractJ,
		conn_cidN_contractK_eventI = Web3.eth.contract.events[eventI],
		conn_cidM_contractJ_eventY,
	} 
'''	
class W3Settings:
	def __init__( self ):
		self.pollInterval = 5 # int( 280 / count_filter ) # testing purposes 
		self.w3 = {}
		try:
			for chain in self.conf_chains():
				self.add_w3_connection( chain )
				for contract in self.chain_contracts( chain ):
					self.add_w3_contract( chain , contract )
					for event in self.w3_events( chain , contract ):
						self.add_w3_filter( chain , contract , event )
						self.add_a3_mirror( chain , contract , event.event_name )

		except Exception as ex :
			self.log_error( 4 )		

	def add_w3_connection( self , chainId ):
		temp_CONN = self.a_conn( chainId )
		temp_WSS = connect_wss( self.chain_wss( chainId ) )
		self.log_data( data='<CID, CONNECTED?> : <%s, %s> '%( chainId , str( temp_WSS.isConnected() ) ) )
		return self.w3.update( mkdict( temp_CONN , temp_WSS ) )

	def add_w3_contract( self , chainId , contractName ):
		temp_ABI = self.contract_abi( contractName )
		temp_ADDR = self.contract_address( chainId , contractName )
		temp_CONTRACT = init_contract( self.w3_conn( chainId ) , temp_ADDR , temp_ABI )
		self.log_data( data='<CID, CONTRACT> : <%s, %s> '%( str( chainId ) , str( contractName ) ) )
		return self.w3.update( mkdict( self.a_contract( chainId , contractName ) , temp_CONTRACT ) )

	def add_w3_filter( self , chainId , contractName , event , from_block='0' ):
		temp_FILTER = event.createFilter( fromBlock=from_block )
		return self.w3.update( mkdict( self.a_filter( chainId , contractName , event.event_name ) , temp_FILTER ) )
	
	def add_a3_mirror( self , chainId , contractName , event_name ):
		temp_MIRROR = KMirror( contractName , event_name , self.contract_mirrors( contractName , event_name ) )
		return self.w3.update( mkdict( self.a_mirror( chainId , contractName , event_name ) , temp_MIRROR ) )

	def a_conn( self , chain_ ):

		return '%s_conn'%( str( chain_ ) )

	def a_contract( self , chain_ , contract_ ):

		return '%s_%s_contract'%( str( chain_ ) , str( contract_ ) )

	def a_filter( self , chain_ , contract_ , filter_ ):

		return '%s_%s_%s_filter'%( str( chain_ ) , str( contract_ ) , str( filter_ ) )

	def a_mirror( self , chain_ , contract_ , event_ ):

		return '%s_%s_%s_mirror'%( str( chain_ ) , str( contract_ ) , str( event_ ) )

	def a_settings( self , chain_ ):

		return '%s_settings'%( str( chain_ ) )

	def w3_mirror( self , chainId , contractName , eventName ):

		return self.w3.get( self.a_mirror( chainId , contractName , eventName ) )

	def w3_conn( self , chainId ):

		return self.w3.get( self.a_conn( chainId ) )

	def w3_conns( self ):

		return all_of( self , attrType=self.w3_conn )

	def w3_contract( self , chainId , contractName ):

		return self.w3.get( self.a_contract( chainId , contractName ) )

	def w3_contracts( self ):

		return all_of( self , attrType=self.w3_contract )

	def w3_contractExists( self , w3_contract ):
		if type( w3_contract ) == str:
			return True if self.w3_contract( w3_contract ) else False
		return True if w3_contract else False

	def w3_events( self , chainId , contractName ):

		return list( self.w3_contract( chainId , contractName ).events )

	def w3_filter( self , chainId , contractName , eventName ):

		return self.w3.get( self.a_filter( chainId , contractName , eventName ) )

	def w3_filters( self ):

		return all_of( self , attrType=self.w3_filter )

	def w3_blocknum( self , chainId ):

		return self.w3.get( self.a_conn( chainId ) ).eth.blockNumber;

	def w3_blocknums( self ):
		_blocknums = []
		for chain in self.conf_chains():
			_blocknums.append( self.w3_blocknum( chain ) )
		return _blocknums

	def w3_checkTxn( self , chainId , txn_hash ):
		if not txn_hash:
			return
		_txnCheck = self.w3_conn( chainId ).eth.getTransaction( txn_hash )
		if not _txnCheck:
			return False
		return True 
	
	def w3_nonce( self , chainId ):

		return self.w3_conn( chainId ).eth.get_transaction_count( self.caller() , 'pending' )

	def w3_gasPrice( self , chainId ):

		return self.w3_conn( chainId ).eth.gas_price

	def w3_txnParams( self , chainId , transaction ):

		return transaction.buildTransaction({ 'from' : self.caller() , 'nonce' : self.w3_nonce( chainId ) , 'gasPrice': self.w3_gasPrice( chainId )} )

	def w3_sendTxn( self , chainId , transaction ):

		return self._sendTxn( chainId , self.w3_txnParams( chainId , transaction ) )

	def _sendTxn( self , chainId , transaction ):
		_w3 = self.w3_conn( chainId )
		return _w3.toHex( _w3.eth.send_raw_transaction( self.sign( transaction ).rawTransaction ) )


class KMirror:
	def __init__( self , from__ , by__ , to__ ):
		self.from__ = from__
		self.by__ = by__
		self.to__ = to__
		self.reflection__ = [eval( 'onchain.%s.%s'%( self.from__ , i ) ) for i in self.to__]
	
	def __from__( self ):
		return self.from__

	def __by__( self ):
		return self.by__

	def __to__( self ):
		return self.to__

	def __reflection__( self ):
		return self.reflection__

	def reflect( self , *arjs , **kwarjs ):
		_result = self.reflection__[0]( arjs , kwarjs )
		for _ray in self.reflection__[1:]:
			_result = _ray( _result )	
		return _result