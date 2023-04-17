#!/bin/python3

from asyncio import get_event_loop,sleep,gather
from inspect import getfullargspec,stack
from copy import deepcopy

class COLORING:
	NC='\033[0m'
	VIOLET='\033[1;94m'
	EVIOLET='\033[1;35m'
	AVIOLET='\033[1;36m'
	GREY='\033[1;37m'
	DARK_GREY='\033[0;37m'
	GREEN='\033[1;32m'
	RED='\033[0;31m'
	YELLOW='\033[1;33m'

class CONTRACTS:
	NODE = 'AETHER_NODE'
	PROXY = 'AETHER_PROXY'
	DAO = 'AETHER_DAO'
	TOKEN = 'AETHER_TOKEN'
	BOND = 'AETHER_BOND'
	HUB = 'AETHER_HUB'
	FACTORY = 'AETHER_FACTORY'
	KEEPER = 'AETHER_KEEPER'

class DAOVARS:
	PROPOSAL_TIME = 'proposalTime'
	SIGNERS_THRESHOLD = 'signersThreshold'
	NODE_THRESHOLD = 'nodeThreshold'
	NODE_STAKING_TIME = 'nodeStakingTime'
	BOND_MATURITY_TIME = 'bondMaturityTime'
	TRANSACTION_THRESHOLD = 'transactionThreshold'
	HOLDER_THRESHOLD = 'holderThreshold'
	REWARDS_TREASURY = 'rewardsTreasury'
	TREASURY_THRESHOLD = 'treasuryThreshold'
	DEPLETION_MULTIPLIER = 'depletionMultiplier'
	DEPLETION_DIVISOR = 'depletionDivisor'
	REWARD_LEDGER = 'rewardLedger'
	GAS_PRICE = 'gasPrice'
	TARGET_GAS = 'targetGas'
	TARGET_TRANSACTIONS = 'targetTransactions'
	MAX_BPB = 'MaxBPB'
	MAX_TPB = 'MaxTPB'

class _0xANodeErr( Exception ):
	def __init__( self , errorNo:int , errorStr:str , *args:tuple ):
		self._message = 'ConfigurationError :: Errorno %s -> %s : %s'%( str( errorNo ) , errorStr , _formatArgs( args ) )
		super().__init__( self._message )

class Logger:
	def __init__( self ):
		pass

	def _getErrorStr( self , errorNo:int ) -> str :
		_switch = {
			0:'NodeID cannot be empty',
			1:'Not a valid Aether path',
			2:'Unable to find a correct configuration file',
			3:'Version of configuration file does not match the execution version',
			4:'Unable to create a dynamic web3 instance',
			5:'Aether cannot form the variable',
			6:'Aether cannot decode variable to bytes',
			7:'Not a valid node path',
			8:'Not a valid log path',
			9:'Execution file is not in the correct path',
			10:'Filters cannot be created with the supplied parameters',
			11:'Cache & J-Cache cannot be equal while collapsing and rebuilding',
			12:'Immutable status is already set',
			13:'Unable to cache transaction',
			14:'Could not fetch last aethering masterhash',
			15:'Cannot fetch last aethering block',
			16:'Unkown cache object',
			17:'Cannot create transaction',
			18:'Cannot create an aetherblock',
			19:'Unable to encode transaction',
			20:'Unable to encode block',
			21:'Unable to encode status',
			22:'Unable to encode cache'
		}
		return _switch.get( errorNo , None )

	def _getWarningStr( self , warningNo:int ) -> str :
		_switch = {
			1:'No dynamic cache and no BLOCK-cache file not found',
			2:'Cannot append logs to file',
			3:'Ambigous transaction',
			4:'Masterhash not constant across blockchains, resolving',
			5:'Waiting for aetherer to submit the current block before resolving'
		}
		return _switch.get( warningNo , None )

	def _fileLog( self , append_file , data ):
		_log_data = '\n\t0xANode : %s -> '%self.node_name
		_log_data = '\n\t\t %s'%data
		print( _log_data , file=append_file )

	def _consoleLog( self , data ):
		if not data:
			return
		_log_data = '\n\t%s0xANode%s: %s -> %s'%( self.COLORS.VIOLET , self.COLORS.NC , self.node_name , stack()[1][3] )
		_log_data += '\n\t\t%s %s %s'%( self.COLORS.GREY , data , self.COLORS.NC )
		print( _log_data )

	def _chainLog( self , chainId , data ):
		if not data:
			return
		_log_data = '\n\t%s0xANode%s: %s -> '%( self.COLORS.VIOLET , self.COLORS.NC , self.node_name )
		_log_data += '\n\t\t%s<CID, ACTION> : <%s, %s> -> '%( self.COLORS.GREY , chainId , stack()[1][3] )
		_log_data += '\n\t\t\t %s %s'%( data , self.COLORS.NC ) if data else 'ROUTINE'
		print( _log_data )

	def _log( self , file_path , data ):
		try:
			_logFile = open( file_path , 'a' )
			self._fileLog( _logFile , data )
			self._consoleLog( data )
		except:
			self.log_warn( 2 )

	def block_log( self , chainId=0 , block_num=0 , block_masterhash='0x' , block_aetherer='0x' , **kwargs ):
		_block = '\u0F3A\tAether Block #%s %s %s is Binding\t\u0F3B\t'%( self.COLORS.GREEN , str( block_num ) , self.COLORS.GREY )
		_block += '\n\t\tBlock MASTERHASH \u227D %s'%str( block_masterhash )
		_block += '\n\t\tBlock Aetherer : %s'%str( block_aetherer )
		self._chainLog( chainId , _block )
		self.log_data( 'BLOCK : %s :: Binding'%str( block_num ) )

	def transaction_log( self , chainId=0 , txn_hash='0x' , txn_cids=[] , txn_native=0 , txn_0xA='0x' , **kwargs ):
		_txn = '\n\t\t\U0001D4DAchec\U0001D4DA : %s\n'%str( txn_hash )
		_txn += '\n\t\tCHAIN_IDS \u21F6 < %s >\n'%', '.join( [str( cid ) for cid in txn_cids] )
		_txn += '\n\t\t\u20BFitcoin est %s\n'%''.join( [unicode_number( i ) if i.isdigit() else str( i ) for i in str( txn_native )] )
		_txn += '\n\t\t0xAether DATA : %s \n'%str( txn_0xA )
		self._chainLog( chainId , _txn )
		self.log_data( 'TRANSACTION : %s '%txn_hash )

	def status_log( self , chainId=0 , **kwargs ):
		_status = '\t\t0xAether Node ID#%s'%str( self.node_name )
		_status = ''.join( ['\n\t\t%s\t: %s'%( i.upper() , kwargs.get( i ) ) for i in kwargs] )
		self._chainLog( chainId , _status )

	def fulfilled_log( self , chainId=0 , txn_has='0x' , **kwargs ):
		_fulfilment = 'Aether Request : %s \u2714'%str( txn_hash )
		self._consoleLog( chainId , _fulfilment )

	def log_error( self , error_id=0 , *args ):
		_errStr = self._getErrorStr( error_id )
		self.log_data( data='ERROR : %s.'%_errStr ) 
		raise _0xANodeErr( error_id , _errStr , args )
		quit()

	def log_warn( self , warning_id=0 ):
		_warnStr = self._getWarningStr( warning_id )
		return self.log_data( data='WARNING : %s.'%_warnStr )

	def log_status( self , status ):
		_statusStr = 'STATUS : '
		_statusStr += 'ONLINE' if status else 'OFFLINE'
		return self.log_data( log_name='online' , data=_statusStr )

	def log_data( self , log_name='performance' , data='' , **kwargs ):
		_logName = {
			'online':'online.log',
			'performance':'performance.log',
			'transactions':'transactions.log'
		}.get( log_name , 'performance.log' )
		return self._log( '%s/%s'%( self._logPath , _logName ) , data )

'''
	0xAether

The Aether is simply a structure, a very simple one, but one nonetheless,

The Aether has 3 different phases :

	0 -> Zero stage

	x -> Pseudo stage

	A -> Aether stage

at any given stage, the movement is restricted that it causes the structure to collapse
on itself before reaching the next stage, with that being said, at the moment of reaching
the "next" stage, another structure rebuilds to be any of the other 2 stages.

'''
class Aether:
	def __init__( self ):
		self.COLORS = COLORING()
		self.CN = CONTRACTS()

	def __mkdict( self , _dictName , _dict ) : 

		return( {_dictName : _dict} )

	def __rddict( self , _dict ) :

		return list( _dict.items() )[0]

	def __status__( self , NATIVE_BLOCKNUMS=[] , AETHER_BLOCKNUM=0 , CHAIN_IDS=[] , PREV_MASTERHASH='0x' , AETHERING_ADDRESS='0x' ):
		return self.__mkdict( 'STATUS' , {
			'NATIVE_BLOCKNUMS': NATIVE_BLOCKNUMS,
			'AETHER_BLOCKNUM': AETHER_BLOCKNUM,
			'CHAIN_IDS': CHAIN_IDS,
			'PREV_MASTERHASH': PREV_MASTERHASH,
			'AETHERING_ADDRESS':AETHERING_ADDRESS,
		})

	def type__status( self ):
		
		return ['uint256[]','uint256','uint256[]','bytes32','bytes20']

	def __transaction__( self , FROM='0x' , TO='0x' , SELECTOR='0x' , ARGUMENTS='0x', CHAIN_IDS=[] , KchecK='0x' ):
		return self.__mkdict( 'TRANSACTION' , {
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
		return self.__mkdict( 'BLOCK' , {
			'MASTERHASH': MASTERHASH,
			'TXN_COUNT': len( HASHES ),
			'AETHERER': AETHERER,
			'HASHES': HASHES,
		})

	def type__block( self ):

		return ['bytes32','uint256','bytes20','bytes16[]']

	def __cache__( self , STATUS={} , TRANSACTIONS=[] , BLOCK={} ):
		return self.__mkdict( 'CACHE' , {
			'NXT_STATUS': STATUS['STATUS'],
			'TRANSACTION_RCRD': [ i['TRANSACTION'] for i in TRANSACTIONS ],
			'AETHERING_BLK': BLOCK['BLOCK'],
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
			( _type , _value ) = self.__rddict( _arg )
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

	def Transaction( self , cids_ , from_ , to_ , select_ , args_ ):
		kparams = [self.__mkdict('address',from_) , self.__mkdict('address', to_) , self.__mkdict('bytes4',select_) , self.__mkdict('bytes',args_) , self.__mkdict('uint256[]',cids_)]
		return self.__transaction__( from_ , to_ , select_ , args_ , cids_ , self.__KchecK( *kparams ) )

	def encode_transaction( self , transaction=None ):
		if not transaction:
			return self.log_error( 19 )
		return encode( _types=self.type__transaction() , _values=[ i for i in transaction.values()])

	def Block( self , masterhash_ , aetherblocknum_ , hashes_ , aetherer_ ):
		kparams = [self.__mkdict('bytes32',masterhash_) , self.__mkdict('uint256',aetherblocknum_) , self.__mkdict('bytes16[]',hashes_) , self.__mkdict('bytes20',aetherer_)]
		return self.__block__( self.__MASTERHASH( *kparams ) , aetherer_ , hashes_ )

	def encode_block( self , block=None ):
		if not block:
			return self.log_error( 20 )
		return self.encode( _types=self.type__block() , _values=[i for i in block.values()])

	def Status( self , blocknums_ , aetherblocknum_ , chain_ids , prevmasterhash_ , aetherer_ ):

		return self.__status__( blocknums_ , aetherblocknum_ , chain_ids , prevmasterhash_ , aetherer_ )

	def encode_status( self , status=None ):
		if not status:
			return self.log_error( 21 )
		return self.encode( _types=self.type__status() , _values=[i for i in status.values()])

	def Cache( self , status_={} , transactions_=[] , block_={} ):
		_status = status_ if status_ else self.__status__()
		_transactions = transactions_ if type( transactions_ ) == list else [transactions_] if transactions_ else []
		_block = block_ if block_ else self.__block__()
		return self.__cache__( _status , _transactions , _block )

	# def encode_cache( self , cache=None ):
	# 	if not cache:
	# 		return self.log_error( 22 )
	# 	vals = []
	# 	txn_count = len( cache['TRANSACTION_RCRD'] )
	# 	vals.extend([i for i in cache['NXT_STATUS'].values()])
	# 	vals.extend([i for i in cache['BLOCK_TRANSACTIONS'].values()])
	# 	vals.extend([i for i in cache['AETHERING_BLOCK'].values()])
	# 	return self.encode( _types=self.type__cache( transaction_count=txn_count ) , _values=vals)

class Configuration:
	def __init__( self ):
		self.config = _readFile( self._confPath , True )
		self.__check()

	def __check( self ):
		if not set( ['CALLER', 'CHAINS', 'ABIS'] ).issubset( set( self.config.keys() ) ) :
			self.log_error( 3 , set( self.config.keys() ) )
		try:
			for i in list( self.config.keys() ):
				if i == 'CALLER' :
					assert( self.config[ i ][ 'pvtKey' ]  != '' )
					assert( self.config[ i ][ 'pubKey' ]  != '' )
				elif ( i == 'CHAINS' ):
					assert( type( self.config[ i ][ 'chainIds' ] ) == list and len( self.config[ i ][ 'chainIds' ] ) >= 1 )
					for j in self.config[ i ][ 'chainIds' ]:
						assert( str( j ) in list( self.config[ i ].keys() ) )
				else:
					continue
		except:
			self.log_error( 3 )		

	def conn( self , chain_ ):
		
		return '%s_conn'%( str( chain_ ) )

	def chain_settings( self , chain_ ):

		return '%s_settings'%( str( chain_ ) )

	def contract( self , chain_ , contract_ ):
		
		return '%s_%s_contract'%( str( chain_ ) , str( contract_ ) )

	def filter( self , chain_ , contract_ , filter_ ):
		
		return '%s_%s_%s_filter'%( str( chain_ ) , str( contract_ ) , str( filter_ ) )

	def conf_chains( self , return_type=str ):
			
		return [int( _chain ) if return_type == int else str( _chain ) for _chain in self.config['CHAINS']['chainIds']]

	def chain_wss( self , chainId=0 ):

		return self.config[ 'CHAINS' ][ str( chainId ) ][ 'wss' ]

	def chain_contracts( self , chainId=0 ):
		
		return list(  self.config[ 'CHAINS' ][ str( chainId ) ][ 'contracts' ].keys() )

	def contract_abi( self , contract_name ):

		return self.config['ABIS'][contract_name]

	def contract_address( self , chainId , contract_name ):

		return self.config[ 'CHAINS' ][ str( chainId ) ][ 'contracts' ][ contract_name ]

	def sign( self , transaction ):

		return Web3().eth.account.sign_transaction( transaction , private_key=self.config['CALLER']['pvtKey'] )

	def caller( self ):

		return self.config['CALLER']['pubKey']

class Settings:
	def __init__( self , DAO_contract ):
		 pass
	def __new__( self , DAO_contract ):
		temp = DAOVARS()
		DAOVARS = list(filter(None,[ i if not i[0].startswith('_') else None for i in temp.__class__.__dict__.items()]))
		DAO_VARS = {}
		for _var in self.DAOVARS:
			DAO_VARS.update( __populate( _var[0] , eval( 'DAO_contract.functions.%s().call()'%_var[1] ) ) )
		return DAO_VARS

class Dynamic( Aether , Configuration ):
	def __init__( self ):
		self.__conf()
		self.__check()

	def assertion( func ):
		def _inner( *args , **kwargs ):
			self = args[0]
			if not all( [i for i in args] ) and not all( [kwargs.get( i ) for i in kwargs.keys()] ):
				return self.log_error( 13 , func.__name__ )
			return func( *args , **kwargs )
		return _inner

	def __status( self , _status=None ):
		if not _status:
			_status = self.cache['NXT_STATUS'] 
		try:
			return _status if not 'STATUS' in _status.keys() else _status.get('STATUS')
		except:
			return {}

	def __transaction( self , _txn=None , _idx=False ):
		if not _txn:
			_txn = self.cache['TRANSACTION_RCRD'][_idx if isdigit( _idx ) else -1]
		try:
			return _txn if not 'TRANSACTION' in _txn.keys() else _txn['TRANSACTION']
		except:
			return {}

	def __transactions( self , _txn=None , _txns=None ):
		__txn = self.__transaction( _txn=_txn )
		if not _txns:
			_txns = self.cache['TRANSACTION_RCRD']
		try:
			txns_ = [__txn]
			for txn in _txns:
				txns_.append( self.__transaction( _txn=txn ) )
			return txns_
		except:
			return []

	def __block( self , _block=None ):
		if not _block:
			_block = self.cache['AETHERING_BLK']
		try:
			return _block if 'BLOCK' not in _block.keys() else _block['BLOCK']
		except:
			return {}

	def __cache( self , _cache=None ):
		if not _cache:
			_cache = self.cache
		try:
			return _cache if 'CACHE' not in _cache.keys() else _cache['CACHE']
		except:
			return {}

	def __update( self , new_cache ):
		assert( new_cache )
		_writeFile( self._cachePath , new_cache , True , True )
		self.cache = _readFile( self._cachePath , True )
		if not self._aethering():
			self.cache_resync()

	def __check( self ):
		if not isfile( self._cachePath ):
			self.log_warn( 1 )
			return self.__update( self.__cache( self.Cache() ) ) 
		return self.__update( self._getCache() )

	def __conf( self ):
		(self.FLAG_CT,self.FLAG_EB,self.FLAG_MH)=( None , 0 , None )
		self.pollInterval = 5 # int( 280 / count_filter ) # testing purposes 
		self.w3 = {}
		'''
			self.w3 = {
				conn_cidN = Web3(rpc_n),
				conn_cidM,
				conn_cidN_contractK = Web3.eth.contract(addr&abi for contractK),
				conn_cidM_contractJ,
				conn_cidN_contractK_eventI = Web3.eth.contract.events[eventI],
				conn_cidM_contractJ_eventY,
			} 
		'''	
		try:
			for chain in self.conf_chains():
				self._addW3Connection( chain )
				for contract in self.chain_contracts( chain ):
					self._addW3Contract( chain , contract )
					for event in self.w3_events( chain , contract ):
						self._addW3Filter( chain , contract , event )
				if self.contractExists( self.w3_contract( chain , self.CN.DAO ) ):
					self._addW3Settings( chain , self.w3_contract( chain , self.CN.DAO ))
		except:
			self.log_error( 4 )

	def _aethering( self ):

		return not self._partial( self.aether_status() )

	def w3_aetherStatus( self , chainId=0 ):
		native_blocknums = self.w3_nativeblocknums()
		aether_blocknum = self.w3_aetherblocknum( chainId )
		chain_ids = self.w3_aetherChains( chainId )
		prev_masterhash = self.w3_masterhash( chainId )
		aetherer = self.w3_aetherer( chainId )
		return self.Status( native_blocknums , aether_blocknum , chain_ids , prev_masterhash , aetherer )

	def _getAetherState( self ):
		_chains = self.conf_chains()
		self.log_data( data='\n\t\t <CIDS> : <%s> :: CACHE_SYNC '%( str( _chains ) ) )
		_state = None
		count = 0
		while not _state:
			count += 1
			_state = self.w3_aetherStatus( _chains[0] )
			if not all( [self.w3_aetherStatus( i ) == _state for i in _chains[1:]] ):
				_state = None
				print('attempting to fix')
			if count > 3:
				break
		return _state

	def _all_of( self , attrType ):
		__all = []
		if attrType == self.w3_conn:
			for i in self.conf_chains( return_type=int ):
				__all.append( attrType( i ) )
			return __all
		elif attrType == self.w3_contract:
			for i in self.conf_chains( return_type=int ):
				for j in self.chain_contracts( i ):
					__all.append( attrType( i , j ) )
			return __all
		elif attrType == self.w3_events:
			return self.w3_events()
		else:
			for i in self.conf_chains( return_type=int ):
				for j in self.chain_contracts( i ):
					for k in self.w3_events( i , j ):
						__all.append( attrType( i , j , k ) )
			return __all

	def _partial( self , _dict ):
		assert( type( _dict ) == dict )
		values = []
		_dictKeys = list( _dict.keys() )
		for i in _dictKeys:
			value = _dict.get( i )
			if value != '0x' or value != b'' or value != [] or value != 0:
				values.append( value )
		return len( _dictKeys ) != len( values )

	def _getCache( self ):

		return _readFile( self._cachePath , True )

	def _addW3Settings( self , chain , daoContract ):

		self.w3.update( self._Aether__mkdict( self.chain_settings( chain ) , Settings( daoContract ) ) )
		self.log_data( data='<CID, DAO_SETTINGS!> : <%s, %s> '%( chainId , str( self.w3.get( self.chain_settings( chain ) ) ) ) )

	def _addW3Connection( self , chainId ):
		temp_CONN = self.conn( chainId )
		temp_WSS = _connectWss( self.chain_wss( chainId ) )
		self.log_data( data='<CID, CONNECTED?> : <%s, %s> '%( chainId , str( temp_WSS.isConnected() ) ) )
		self.w3.update( self._Aether__mkdict( temp_CONN , temp_WSS ) )

	def _addW3Contract( self , chainId , contractName ):
		temp_ABI = self.contract_abi( contractName )
		temp_ADDR = self.contract_address( chainId , contractName )
		temp_CONTRACT = _initContract( self.w3_conn( chainId ) , temp_ADDR , temp_ABI )
		self.log_data( data='<CID, CONTRACT> : <%s, %s> '%( str( chainId ) , str( contractName ) ) )
		self.w3.update( self._Aether__mkdict( self.contract( chainId , contractName ) , temp_CONTRACT ) )

	def _addW3Filter( self , chainId , contractName , event ):
		temp_FILTER = event.createFilter( fromBlock='0' )
		self.w3.update( self._Aether__mkdict( self.filter( chainId , contractName , event.event_name ) , temp_FILTER ) )

	def contractExists( self , w3_contract ):
		if type( w3_contract ) == str:
			return True if self.w3_contract( w3_contract ) else False
		return True if w3_contract else False
	
	def empty_cache( self ):

		return self.__cache( self.Cache() )

	def w3_conn( self , chainId ):

		return self.w3.get( self.conn( chainId ) )

	def w3_conns( self ):

		return self._all_of( attrType=self.w3_conn )

	def w3_contract( self , chainId , contractName ):

		return self.w3.get( self.contract( chainId , contractName ) )

	def w3_contracts( self ):

		return self._all_of( attrType=self.w3_contract )

	def w3_events( self , chainId , contractName ):

		return list( self.w3_contract( chainId , contractName ).events )
	
	def w3_filter( self , chainId , contractName , eventName ):

		return self.w3.get( self.filter( chainId , contractName , eventName ) )

	def w3_filters( self ):

		return self._all_of( attrType=self.w3_filter )

	def w3_blocknum( self , chainId ):

		return self.w3.get( self.conn( chainId ) ).eth.blockNumber;

	def w3_nativeblocknum( self , chainId ):

		return execViewCall( self.w3_contract( chainId , self.CN.HUB ) , 'nativeBlockNum' )

	def w3_nativeblocknums( self ):
		_nativeblocknums = []
		for chain in self.conf_chains():
			_nativeblocknums.append( self.w3_nativeblocknum( chain ) )
		return _nativeblocknums

	def w3_blocknums( self ):
		_blocknums = []
		for chain in self.conf_chains():
			_blocknums.append( self.w3_blocknum( chain ) )
		return _blocknums

	def w3_aetherblocknum( self , chainId ):

		return execViewCall( self.w3_contract( chainId , self.CN.HUB ) , 'aetherBlockNum' )
	
	def w3_aetherblocknums( self ):
		_aetherblocknums = []
		for chain in self.conf_chains():
			_aetherblocknums.append( self.w3_aetherblocknum( chain ) )
		return _aetherblocknums

	def w3_masterhash( self , chainId ):

		return _bytesToHex( execViewCall( self.w3_contract( chainId , self.CN.HUB ) , 'MASTER_HASH' ) )

	def w3_aetherer( self , chainId ):

		return _bytesToHex( execViewCall( self.w3_contract( chainId , self.CN.HUB ) , 'aetheringAddress' ) )

	def w3_0xA( self , chainId ):

		return _bytesToHex( execViewCall( self.w3_contract( chainId , self.CN.HUB ) , 'callerAAddress' , _from=self.caller() ) )

	def w3_atxnHash( self , chainId , atxn_hash ):

		return execViewCall( self.w3_contract( chainId , self.CN.HUB ) , 'getATransaction' , atxn_hash )

	def w3_nonce( self , chainId ):
		
		return self.w3_conn( chainId ).eth.get_transaction_count( self.caller() , 'pending' )

	def w3_step( self ):
		_step = [ execViewCall( self.w3_contract( chain , self.CN.HUB ) , 'stepper' , _from=self.caller() ) for chain in self.conf_chains() ]
		return _step[0] if all([i for i in _step]) else False

	def w3_sten( self ):
		_step = [ execViewCall( self.w3_contract( chain , self.CN.HUB ) , 'stenner' , _from=self.caller() ) for chain in self.conf_chains() ]
		return _step[0] if all([i for i in _step]) else False

	def w3_stek( self ):
		_step = [ execViewCall( self.w3_contract( chain , self.CN.HUB ) , 'stekker' , _from=self.caller() ) for chain in self.conf_chains() ]
		return _step[0] if all([i for i in _step]) else False

	def w3_aetherChains( self , chainId ):

		return execViewCall( self.w3_contract( chainId , self.CN.HUB ) , 'aether_chains' )

	def _sendTxn( self , chainId , transaction ):
		_w3 = self.w3_conn( chainId )
		return _w3.toHex( _w3.eth.send_raw_transaction( self.sign( transaction ).rawTransaction ) )

	def w3_gasPrice( self , chainId ):

		return self.w3_conn( chainId ).eth.gas_price

	def w3_txnParams( self , chainId , transaction ):

		return transaction.buildTransaction({ 'from' : self.caller() , 'nonce' : self.w3_nonce( chainId ) , 'gasPrice': self.w3_gasPrice( chainId )} )

	def w3_sendTxn( self , chainId , transaction ):

		return self._sendTxn( chainId , self.w3_txnParams( chainId , transaction ) )

	def w3_checkTxn( self , chainId , txn_hash ):
		_txnCheck = self.w3_conn( chainId ).eth.getTransaction( txn_hash )
		if not _txnCheck:
			print('Transaction failed')
			return False
		print('Transaction success : %s'%txn_hash)
		return True 

	def add_to_cache( self , transaction=None , block=None , status=None ):
		if transaction:
			self.cache['BLOCK_TRANSACTIONS'] = self.__transactions( _txn=transaction )
		elif block:
			self.cache['AETHERING_BLOCK'] = self.__block( _block=block )
			self.dump_cache()
		elif status:
			self.cache['IMMUTABLE_STATUS'] = self.__status( _status=status )
		else:
			self.log_error( 16 )
		return self.cache

	@assertion
	def cache_txn( self , txn_cids , txn_from , txn_to , txn_select , txn_args , txn=None ):
		if txn:
			return self.add_to_cache( transaction=txn )
		return self.add_to_cache( transaction=self.Transaction( txn_cids , txn_from , txn_to , txn_select , txn_args ) )

	@assertion
	def cache_block( self , block_masterhash , block_num , block_transactions , block_aetherer , block=None ):
		if block:
			return self.add_to_cache( block=block )
		return self.add_to_cache( block=self.Block( block_masterhash , block_num , block_transactions , block_aetherer ) )

	def cache_status( self , native_blocknums , aether_blocknum , aethering_chainIds , prev_masterhash , aetherer_addr , status=None ):
		if status:
			return self.add_to_cache( status=status )
		return self.add_to_cache( status=self.Status( native_blocknums , aether_blocknum , aethering_chainIds , prev_masterhash , aetherer_addr ) )

	def cache_resync( self , status={} , transactions=[] , block={} ):
		if not status:
			status = self._getAetherState()
		return self.__update( self.Cache( status_=status , transactions_=transactions , block_=block ) )

	def aether_txns( self ):
		_txns = self.aether_cache( cType='BLOCK_TRANSACTIONS' )
		return _txns if _txns else []

	def aether_status( self ):
		_status = self.aether_cache( cType='IMMUTABLE_STATUS' )
		return _status if _status else {}

	def aether_block( self ):
		_block = self.aether_cache( cType='AETHERING_BLOCK' )
		return _block if _block else {}

	def aether_cache( self , cType=None ):
		_cache = self.__cache( self.cache )
		return _cache if not cType else _cache.get( cType , None )

	def update_nativeBlocknums( self ):
		self.cache['IMMUTABLE_STATUS']['NATIVE_BLOCKNUMS'] = self.w3_blocknums()
		return self.dump_cache()

	def dump_cache( self ):

		return self.__update( self.cache )

class Node( Dynamic , Logger , Configuration ):
	def __init__( self , aether_path : str , node_name : str ):
		self._pathify( aether_path , node_name )
		Configuration.__init__( self )
		Aether.__init__( self )
		Dynamic.__init__( self )

	def _pathify( self , aether_path : str , node_name : str ):
		self.node_name = node_name
		if not self.node_name:
			self.log_error( 0 )

		self.aether_path = aether_path
		if not isdir( aether_path ):
			self.log_error( 1 )

		self.node_path = '%s/nodes/%s.node'%( self.aether_path , self.node_name )
		if not isdir( self.node_path ):
			self.log_error( 7 )

		self._logPath =  '%s/logs'%self.aether_path
		if not isdir( self._logPath ):
			self.log_error( 8 )

		self._execPath = '%s/__%s__'%( self.node_path , node_name )
		if not isfile( self._execPath ):
			self.log_error( 9 )

		self._confPath = '%s/.conf/config.json'%self.node_path
		if not isfile( self._confPath ):
			self.log_error( 2 )

		self._cachePath = '%s/.A-block.json'%self.node_path

	async def _loop( self ):
		loop_interrupt = 1
		_chain_id = 0 
		while True:
			#trustmebro
			temp = list( filter( None , [ ( '%s'%i , self.w3.get( '%s'%i ) ) if '_filter' in '%s'%i else None for i in list( self.w3.keys() ) ] ) )
			'''
				loop throughout the eventFilters created every 
				X seconds = pollInterval + totalFilters/300  
				300s ~ 5 minutes before the WSS endpoint serving 
				closes idle connections.
			'''
			for eventFilter in temp :
				if len( eventFilter ) > 1:

					( filter_name , aether_filter ) = eventFilter
					( chain_id , aether_main , aether_contract , aether_event , filter_main ) = filter_name.split('_')
					contract_name = '%s_%s'%( aether_main , aether_contract )
					
					if chain_id != _chain_id:
						self.leccy( chain_id )
						_chain_id = chain_id
					# self.log_data( data='<CID, FILTER> : <%s, %s> -> Getting entries.'%( str( chain_id ) , str( aether_event ) ) )

					eventEntries = aether_filter.get_new_entries()

					if len( eventEntries ) > 0:
						for aether_entry in eventEntries:
							self.handle_entry( chain_id , aether_entry )
							loop_interrupt = 0

				await sleep( self.pollInterval )
				
			loop_interrupt += 1

			self.log_data( data='LOOP : <%s> -> uninteruptted.'%( str( loop_interrupt ) ) )

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

	def commitTransaction( self , chainId , txnBytes ):
		if self.FLAG_CT == txnBytes:
			return False
		_contract = self.w3_contract( chainId , self.CN.HUB )
		_txn = _contract.functions.commitTransaction( txnBytes )
		self.FLAG_CT = txnBytes
		return self.w3_sendTxn( chainId , _txn )

	def execBlock( self , chainId , blockBytes ):
		if self.FLAG_EB >= self.w3_aetherblocknum( chainId ):
			return False
		_contract = self.w3_contract( chainId , self.CN.HUB )
		_txn = _contract.functions.execBlock( blockBytes )
		self.FLAG_EB = self.w3_aetherblocknum( chainId ) + 1
		return self.w3_sendTxn( chainId , _txn )

	def submitMasterHash( self , chainId , masterHash ):
		if self.FLAG_MH != self.w3_masterhash( chainId ):
			return False
		_contract = self.w3_contract( chainId , self.CN.HUB )
		_txn = _contract.functions.submitMasterHash( masterHash )
		self.FLAG_MH = masterHash
		return self.w3_sendTxn( chainId , _txn )

	def aetherBlock( self , chainId=0 ): 
		_status = self.aether_status()
		aetherer = _status['AETHERING_ADDRESS']
		_txns = self.aether_txns()
		_block = self.Block( _status['PREV_MASTERHASH'] , _status['AETHER_BLOCKNUM'] , [i['KchecK'] for i in _txns] , aetherer )['BLOCK']
		if aetherer == self.w3_0xA( chainId ):
			txn_hash = self.execBlock( chainId , self.encode_block( block=_block ) )
			if txn_hash:
				self.cache_block( _block['MASTERHASH'] , self.w3_aetherblocknum( chainId ) , _block['HASHES'] , _block['AETHERER'] )
				self.log_data( data='<CID , EXEC_BLOCK> : <%s , %s>'%( str( chainId ) , txn_hash ) )
				return txn_hash

	def aetherStep( self , chainId=0 ):
		_status = self.aether_status()
		aether_blocknum = _status['AETHER_BLOCKNUM']
		if aether_blocknum == self.w3_aetherblocknum( chainId ):
			txn_hash = self.submitMasterHash( chainId , self.aether_block()['MASTERHASH'] )
			if txn_hash :
				self.log_data( data='<CID, SBMT_TXN> : <%s, %s>'%( str( chainId ) , str( txn_hash ) ) )
				return txn_hash

	def _stekker( self , chainId=0 ):
		self.log_data( data='<CID, STEK> : <%s, %s>'%( str( chainId ) , self.w3_aetherblocknum() )  )
		for chain in self.conf_chains():
			_res = self.w3_checkTxn( chain , self.aetherBlock( chain ) )
		return True if all([i for i in _res]) else False

	def _stenner( self , chainId=0 ):

		return True if self.w3_sten() else False

	def _stepper( self , chainId=0 ):
		self.log_data( data='<CID, STEP> : <%s, %s>'%( str( chainId ) , str( self.w3_blocknum( chainId ) ) ) )
		for chain in self.conf_chains():
			_res = self.w3_checkTxn( chain , self.aetherStep( chain ) )
		return True if all([i for i in _res]) else False

	def leccy( self , chainId=0 ):
		# if self.w3_step():
		# 	self._stepper()
		# 	if self.w3_stek():
		# 		self._stekker()
		# elif self.w3_sten():
		# 	self._stenner()
		# else:
		# 	return
		pass

	def handle_entry( self , chainId , entry ):
		action = entry['event']
		params = entry['args']
		'''
		can easily retreive events
		from the contract ABI
		once done, please rename `reaction` -> `mirror`
		'''
		reaction = {
			'ATxnReceive'		:	self.ATxnReceive,
			'ATxnRequest'		:	self.ATxnRequest,
			'ABlockBind'		:	self.ABlockBind,
			'NodeRegistered'	:	self.NodeRegistered
		}.get( action , lambda: 'Unknown Event' )
		func_args = [chainId]
		for i in getfullargspec( reaction ).args[2:]:
			func_args.append( params.get( i ) )
		return reaction( *func_args )

	def start( self ):
		self.loop = get_event_loop()
		try:
			self.log_status( True )
			self.loop.run_until_complete( gather( self._loop() ) )
		finally:
			self.log_status( False )
			self.loop.close()


cfg = Configuration()
	print('cfg ')

if __name__ == '__main__':
	cfg = Configuration()
	print('cfg ')
	# sys.argv[-2] -> path
	# sys.argv[-1] -> node name
	# node = Node( argv[-2] , argv[-1] )
	# node.start()