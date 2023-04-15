from eth_abi import is_encodable,encode_abi
from inspect import getfullargspec
from generality.key_value import mkdict,rddict
from generality.w3 import Web3

'''
	0xAether 

The Aether is simply a structure, a very simple one, but one nonetheless,

The Aether has 3 different phases :

	0 -> Zero stage

	x -> Pseudo stage

	A -> Aether stage

at any given stage, the movement is restricted that it causes the structure to collapse
on itself before reaching the next stage. At the moment of reaching the "next" stage, 
another structure presents itself as a result of the collapse.
'''

class Aether:
	def __init__( self ):
		pass

	def __status__( self , NATIVE_BLOCKNUMS=[0] , AETHER_BLOCKNUM=0 , CHAIN_IDS=[0] , PREV_MASTERHASH='0x' , AETHERING_ADDRESS='0x' , ACID_ROLL=[0] ):
		return mkdict( 'STATUS' , {
			'NATIVE_BLOCKNUMS': NATIVE_BLOCKNUMS,
			'AETHER_BLOCKNUM': AETHER_BLOCKNUM,
			'CHAIN_IDS': CHAIN_IDS,
			'PREV_MASTERHASH': PREV_MASTERHASH,
			'AETHERING_ADDRESS':AETHERING_ADDRESS,
			'ACID_ROLL':ACID_ROLL
		})

	def type__status( self ):
		
		return ['uint256[]','uint256','uint256[]','bytes32','bytes20']

	def __transaction__( self , FROM='0x' , TO='0x' , SELECTOR='0x' , ARGUMENTS='0x', CHAIN_IDS=[0] , KchecK='0x' , AETHERING_CHAIN=0 , NONCE=0 ):
		return mkdict( 'TRANSACTION' , {
			'0xA': {
				'AETHERING_CHAIN':AETHERING_CHAIN,
				'NONCE':NONCE
			},
			'FROM' : FROM,
			'TO' : TO,
			'SELECTOR': SELECTOR,
			'ARGUMENTS': ARGUMENTS,
			'CHAIN_IDS':CHAIN_IDS,
			'KchecK':KchecK
		})

	def type__transaction( self ):

		return ['address','address','bytes4','bytes','uint256[]','bytes16']

	def __block__( self , MASTERHASH='0x' , AETHERER='0x' , HASHES=[] ):
		return mkdict( 'BLOCK' , {
			'MASTERHASH': MASTERHASH,
			'TXN_COUNT': len( HASHES ),
			'AETHERER': AETHERER,
			'HASHES': HASHES,
		})

	def type__block( self ):

		return ['bytes32','bytes20','bytes16[]']

	def __cache__( self , STATUS={} , TRANSACTIONS=[] , BLOCK={} ):
		return mkdict( 'CACHE' , {
			'CURRENT_STAT': STATUS['STATUS'] if STATUS else self.__status__()['STATUS'],
			'TRANSACTION_RCRD': [ i['TRANSACTION'] for i in TRANSACTIONS ] if TRANSACTIONS else [] ,
			'AETHERING_BLK': BLOCK['BLOCK'] if BLOCK else self.__block__()['BLOCK'],
		})

	def type__cache( self , transaction_count=1 ):
		cache_types = []
		cache_types.extend( self.type__status() )
		cache_types.extend( [self.type__transaction() for i in range( transaction_count )] )
		cache_types.extend( self.type__block() )
		return cache_types


	def __MASTERHASH( self , *args ):
		
		return self._K256EncodePacked( *self._KParams( args ) ) # bytes32 value

	def __KchecK( self , *args ):
		
		return self._K256Encode( *self._KParams( args ) )[:34] # bytes16 value

	def _K256Encode( self , _types=[] , _values=[] ):
		_encoded = self.encode( _types , _values )
		return Web3.solidityKeccak(['bytes'] , [Web3.toHex( _encoded )]).hex() 

	def _K256EncodePacked( self , _types=[] , _values=[] ):
		for _,_type in enumerate( _types ):
			if '[]' in _type:
				_types[_] = 'bytes'
				_values[_] = self.encodePacked( _values[_] )
		return Web3.solidityKeccak( _types , _values ).hex() 

	def _KParams( self , _args=[] ):
		( _types , _values ) = ( [] , [] )
		for _arg in _args :
			( _type , _value ) = rddict( _arg )
			_types.append( _type )
			_values.append( _value )
		return ( _types , _values )

	def k256_encodePacked( self , types=[] , values=[] ):

		return self._K256EncodePacked( types , values )

	def k256_encode( self , types=[] , values=[] ):

		return self._K256Encode( types , values )

	def encodePacked( self , hex_arr=[] ):
		b_b16Hex = '0x'
		for _b16 in hex_arr :
			b_b16Hex += _b16[2:].ljust( 64 , '0' )
		return b_b16Hex

	def encode( self , _types=[] , _values=[] ):
		for _,_type in enumerate( _types ):
			_val = _values[_]
			if not is_encodable( _type , _val ):
				if type( _val ) == str and _val.startswith('0x') :
					try:
						_values[_] = Web3.toBytes( hexstr=_val )
					except:
						raise _0xANodeErr( 6 , _val )
				elif type( _val ) == list :
					 try:
					 	_values[_] = list( filter( None , [Web3.toBytes(hexstr=i) if type( i ) == str else None for i in _val] ) )
					 except:
					 	raise _0xANodeErr( 6 , _val )
		return encode_abi( _types , _values )


	def Transaction( self , cids_ , from_ , to_ , select_ , args_ , acid_ , nonce_ ):
		kparams = [mkdict('address',from_) , mkdict('address', to_) , mkdict('bytes4',select_) , mkdict('bytes',args_) , mkdict('uint256[]',cids_)]
		return self.__transaction__( from_ , to_ , select_ , args_ , cids_ , self.__KchecK( *kparams ) , acid_ , nonce_ )

	def encode_transaction( self , transaction=None ):
		if not transaction:
			return self.log_error( 19 )
		_txns = []
		for i in transaction.values():
			del i['0xA']
			_txns.append( i )
		return encode( _types=self.type__transaction() , _values=_txns )


	def Block( self , masterhash_ , aetherblocknum_ , hashes_ , aetherer_ ):
		kparams = [mkdict('bytes32',masterhash_) , mkdict('uint256',aetherblocknum_) , mkdict('bytes16[]',hashes_) , mkdict('bytes20',aetherer_)]
		return self.__block__( self.__MASTERHASH( *kparams ) , aetherer_ , hashes_ )

	def encode_block( self , block=None ):
		if not block:
			return self.log_error( 20 )
		return self.encode( _types=self.type__block() , _values=[i for i in block.values()])


	def Status( self , blocknums_ , aetherblocknum_ , chain_ids , prevmasterhash_ , aetherer_ , acidroll_ ):

		return self.__status__( blocknums_ , aetherblocknum_ , chain_ids , prevmasterhash_ , aetherer_ , acidroll_ )

	def encode_status( self , status=None ):
		if not status:
			return self.log_error( 21 )
		return self.encode( _types=self.type__status() , _values=[i for i in status.values()])


	def Cache( self , status_={} , transactions_=[] , block_={} ):
		_status = status_ if status_ else self.__status__()
		_transactions = transactions_ if type( transactions_ ) == list else [transactions_] if transactions_ else []
		_block = block_ if block_ else self.__block__()
		return self.__cache__( _status , _transactions , _block )

=