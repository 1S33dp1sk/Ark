from generality.w3 import execViewCall,_bytesToHex
from ..constants.contract_names import AETHER_HUB

def ATxnReceive( self , chainId=0 , ATxnHash="" , **kwargs ):
	_atxnHash = _bytesToHex( ATxnHash )
	txnData = self.w3_atxnHash( chainId , _atxnHash )
	txnData = [_bytesToHex( i ).lower() if type( i ) == bytes else i for i in txnData]
	self.cache_txn( *txnData )
	self.transaction_log( chainId , _atxnHash , txnData[0] , '-' , '0x%s'%''.join( [ i[2:].lower() if type( i ) is str else '' for i in txnData] ) )
	self.dump_cache()

def ATxnRequest( self , chainId=0 , ATxnHash="" , ATxnResult=False , **kwargs ):

	return self.fulfilled_log( chainId , ATxnHash )

def ABlockBind( self , chainId=0 , ABlockNum=0 , ABlockMasterHash=b'' , ABlockTxnCount=0 , ABlockAethering=b'' , NBlockNum=0 , **kwargs ):
	chainId = int( chainId )
	_ablock_num = int( ABlockNum )
	_ablock_masterHash = _bytesToHex( ABlockMasterHash )
	_ablock_txnCount = int( ABlockTxnCount )
	_ablock_aethering = _bytesToHex( ABlockAethering )
	_ablock_nativeBlockNum = int( NBlockNum )
	_ablock_transactions = self.aether_txns()
	if len( _ablock_transactions ) != _ablock_txnCount:
		_ablock_transactions = []			
	self.cache_block( _ablock_masterHash , _ablock_num , _ablock_transactions , _ablock_aethering )
	self.block_log( chainId , _ablock_num , _ablock_masterHash , _ablock_aethering )

def NodeRegistered( self , chainId=0 , ANodeAddress='0x' , ANodePos=0 , ANodesPtr=0 , **kwargs ):

	return self.status_log( chainId , node_registered=ANodeAddress , node_position=ANodePos , nodes_pointer=ANodesPtr )

def _getTxnParams( self , _transaction=None ):
	_params =[]
	for i in _transaction.keys():
		if i in ['FROM','TO','SELECTOR','ARGUMENTS']:
			_params.append( _transaction.get( i ) )
	return _params

def _makeTxn( self , aTransaction={} ):
	if not aTransaction:
		self.log_error( 17 )
	return _hexify( self._getTxnParams( aTransaction ) )


def syncAether( self , *arj , **kwarj ):
	print('is syncing...')
	pass

def commitTransaction( self , chainId , txnBytes ):
	if self.FLAG_CT == txnBytes:
		return False
	_contract = self.w3_contract( chainId , AETHER_HUB )
	_txn = _contract.functions.commitTransaction( txnBytes )
	self.FLAG_CT = txnBytes
	return self.w3_sendTxn( chainId , _txn )

def execBlock( self , chainId , blockBytes ):
	if self.FLAG_EB >= self.w3_aetherblocknum( chainId ):
		return False
	_contract = self.w3_contract( chainId , AETHER_HUB )
	_txn = _contract.functions.execBlock( blockBytes )
	self.FLAG_EB = self.w3_aetherblocknum( chainId ) + 1
	return self.w3_sendTxn( chainId , _txn )

def submitMasterHash( self , chainId , masterHash ):
	if masterHash != self.w3_masterhash( chainId ):
		return False
	_contract = self.w3_contract( chainId , AETHER_HUB )
	_txn = _contract.functions.submitMasterHash( masterHash )
	return self.w3_sendTxn( chainId , _txn )

def aetherBlock( self , chainId=0 ): 
	_status = self.aether_status()
	aetherer = _status['AETHERING_ADDRESS']
	_txns = self.aether_txns()
	_block = self.Block( _status['PREV_MASTERHASH'] , _status['AETHER_BLOCKNUM'] , [i['KchecK'] for i in _txns] , aetherer )['BLOCK']
	if aetherer == self.w3_0xA( chainId ):
		txn_hash = self.execBlock( chainId , self.encode_block( block=_block ) )
		print( txn_hash )
		if txn_hash:
			self.cache_block( _block['MASTERHASH'] , self.w3_aetherblocknum( chainId ) , _block['HASHES'] , _block['AETHERER'] )
			self.log_data( data='<CID , EXEC_BLOCK> : <%s , %s>'%( str( chainId ) , txn_hash ) )
			return txn_hash

def aetherStep( self , chainId=0 ):
	_status = self.aether_status()
	aether_blocknum = _status['AETHER_BLOCKNUM']
	if aether_blocknum == self.w3_aetherblocknum( chainId ):
		txn_hash = self.submitMasterHash( chainId , self.aether_status()['PREV_MASTERHASH'] )
		if txn_hash :
			self.log_data( data='<CID, SBMT_TXN> : <%s, %s>'%( str( chainId ) , str( txn_hash ) ) )
			return txn_hash
