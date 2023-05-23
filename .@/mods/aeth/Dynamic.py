from generality.w3 import connect_wss,init_contract,execViewCall,_bytesToHex
from generality.fileIO import _readFile,_writeFile
from generality.key_value import mkdict,rddict
from os.path import isfile
from os import getcwd
from copy import deepcopy
from .Aether import Aether
from generality.constants import ZERO_ADDRESS

'''
Making 0xAether dynamic is all about having the correct calls
to the correct contracts and updating when necessary


@params : self._cachePath
'''

class Dynamic(Aether):

	def __init__(self):
		self.cachePath=""
		try:
			if self._cachePath == '':
				self._cachePath = getcwd()
			if not isfile( self._cachePath ):
				self.log_warn( 1 )
				return self.__update( self.Cache() ) 
			return self.__update( self._read_cache() )
		except:
			self._cachePath = getcwd()

	def __update( self , new_cache ):
		assert( new_cache )
		_writeFile( self._cachePath , new_cache , True , True )
		self.cache = self._read_cache()

	def __dump( self ):

		return self.__update( self.cache )

	def __cache( self , cType=None ):
		_cache = self.cache.get( 'CACHE' )
		return _cache if not cType else _cache.get( cType , None )

	def __record_txn( self , _txn ):
		__txn = _txn['TRANSACTION']
		_kcheck = __txn['KchecK']
		_txns = self.cache_txns()
		for txn in _txns:
			if txn['KchecK'] == _kcheck :
				return False
		_txns.append( __txn )
		return self._sort( _txns )

	def __prune_txn( self , _kchk ):
		pruned_hashes = [kcheck for kcheck in self.cache_hashes() if kcheck != _kchk]
		self.cache['CACHE']['AETHERING_BLK']['HASHES'] = pruned_hashes
		self.cache['CACHE']['AETHERING_BLK']['TXN_COUNT'] = len( pruned_hashes )
		return self.__update( self.cache )

	def __aether_blk( self , _blk ):
		__blk = _blk['BLOCK']
		self.cache['CACHE']['AETHERING_BLK'] = __blk
		self.cache['CACHE']['TRANSACTION_RCRD'] = []
		return self.__update( self.cache )

	def __replace_status( self , _status ):
		__status = _status['STATUS']
		self.cache['CACHE']['CURRENT_STAT'] = __status
		return self.__update( self.cache )

	def _empty( self , arg ):
		_type = type( arg )
		if _type == dict:
			values = []
			_dictKeys = list( arg.keys() )
			for i in _dictKeys:
				value = arg.get( i )
				if value != '0x' or value != b'' or value != [] or value != 0:
					values.append( value )
			return len( _dictKeys ) != len( values )
		elif _type == list:
			if ( len( arg ) >= 1 ) and ( 0 not in arg ):
				return arg
		elif _type == str:
			if arg and ( arg != '0x' ):
				return arg
		elif _type == int:
			if arg and ( arg != 0 ):
				return arg
		else:
			print('unable to check for NE for %s with type : %s'%( arg , _type ) )
			return None

	def _sort( self , txns ):
		reference_cids = self.roll_acids()
		_txnRoll = [[] for i in reference_cids]
		__txns = []
		for txn in txns:
			cidIdx = txn['0xA']['AETHERING_CHAIN']
			_txnRoll[reference_cids.index( cidIdx )].append( txn )
		for cid_txns in _txnRoll:
			__txns.extend( cid_txns )
		return self._txn_record_update( __txns )

	def _txn_record_update( self , txns_sorted ):
		_cache = deepcopy( self.cache )
		_cache['CACHE']['TRANSACTION_RCRD'] = txns_sorted
		return self.__update( _cache )

	def _read_cache( self ):

		return _readFile( self._cachePath , True )

	def not_empty( self , *args ):
		
		return all( [self._empty( i ) for i in args ] )

	def roll_acids( self ):
		( roll , roll_cids ) = ( self.cache_acid() , self.cache_chains() )
		_arr1,_arr2 = [],[]
		chg_flag = False
		for i in roll_cids:
			if chg_flag:
				_arr2.append( i )
			elif i == roll:
				chg_flag = True
				_arr2.append( i )
			else:
				_arr1.append( i )
		return [*_arr2,*_arr1]		

	def add_to_cache( self , transaction=None , block=None , status=None ):
		if transaction:
			return self.__record_txn( transaction )
		elif block:
			return self.__aether_blk( block )
		elif status:
			return self.__replace_status( status )
		else:
			self.log_error( 16 )
		return self.cache

	def sync( self ):
		_status = self.cache_status()
		_prevMH = _status['PREV_MASTERHASH']
		_abn = _status['AETHER_BLOCKNUM']
		_athrer = _status['AETHERING_ADDRESS']
		_kchks = [TXN['KchecK'] for TXN in self.cache_txns()]
		block_vars = [_prevMH,_abn,_kchks,_athrer]
		if self.not_empty( block_vars ):
			_block = self.Block( *block_vars )
			self.__aether( _block )
			print('synced')
		else:
			print('unable to sync due to Block')

	def purge_hash( self , kcheck ):
		if kcheck and ( kcheck in self.cache_hashes() ):
			self.__prune_txn( kcheck )

	def cache_txns( self ):
		_txns = self.__cache( cType='TRANSACTION_RCRD' )
		return _txns if _txns else []

	def cache_txn( self , txn_index=0 ):

		return self.cache_txns()[txn_index]

	def cache_0xA( self , txn_index=0 ):

		return self.cache_txn( txn_index=txn_index )['0xA']

	def cache_status( self ):
		_status = self.__cache( cType='CURRENT_STAT' )
		return _status if _status else {}

	def cache_blocknums( self ):

		return self.cache_status()['NATIVE_BLOCKNUMS']

	def cache_ablocknum( self ):

		return self.cache_status()['AETHER_BLOCKNUM']

	def cache_chains( self ):

		return self.cache_status()['CHAIN_IDS']

	def cache_pmasterhash( self ):

		return self.cache_status()['PREV_MASTERHASH']

	def cache_aethering( self ):

		return self.cache_status()['AETHERING_ADDRESS']

	def cache_acid( self ):
		_status = self.cache_status()
		return _status['ACID_ROLL']

	def cache_block( self ):
		_block = self.__cache( cType='AETHERING_BLK' )
		return _block if _block else {}

	def cache_hashes( self ):

		return self.cache_block()['HASHES']

	def cache_masterhash( self ):

		return self.cache_block()['MASTERHASH']

	def cache_txncount( self ):

		return self.cache_block()['TXN_COUNT']

	def cache_aetherer( self ):

		return self.cache_block()['AETHERER']






if __name__ == '__main__':
	d = Dynamic()