from os.path import isfile,isdir
from sys import argv
from string import ascii_lowercase,hexdigits
from json import loads,dumps
from web3 import Web3
from eth_abi import encode,is_encodable
from re import sub
from random import randint

# Web3
ZERO_ADDRESS = '0x0000000000000000000000000000000000000000'

ARGS=argv

def _bytesToHex( _bytes: bytes ) -> str :
	if type( _bytes ) != bytes:
		return ''
	return '0x%s'%str( _bytes.hex() )

def _hexify( _hexList: list ) -> str:
	if type( _hexList ) != list:
		return ''
	return '0x%s'%''.join( [i.replace( '0x' , '' ) for i in _hexList] )

def _connectRpc( _rpc : str ) -> Web3 :

	return Web3 ( Web3.HTTPProvider( _rpc ) )

def _connectWss( _wss : str ) :

	return Web3 ( Web3.WebsocketProvider( _wss ) )

def _initContract( _w3 : Web3 , _addr : str , _abi : str ) : 

	return _w3.eth.contract( address = _addr , abi = _abi )

def _getBalance( _w3 : Web3 , callerAddr : str ) -> str :

	return _w3.eth.get_balance( _w3.toChecksumAddress( callerAddr ) )

def _getNonce( _w3 : Web3 , callerAddr : str ) -> int :

	return _w3.eth.get_transaction_count( callerAddr )

def execViewCall( _contract , _function : str , *args , _from=ZERO_ADDRESS ) :
	w3_function = _contract.get_function_by_name( _function )
	if _from != ZERO_ADDRESS :
		return w3_function( *args ).call({'from':_from})
	return w3_function( *args ).call() 

def execActionCall( _contract , _w3 : Web3 , _function : str , _params : dict , _pvt : str , *args ) :
	w3_function = _contract.get_function_by_name( _function )
	_txn = w3_function( *args ).buildTransaction( _params )
	txn = _w3.eth.send_raw_transaction( _w3.eth.account.sign_transaction( _txn, private_key=_pvt ).rawTransaction )
	return _w3.toHex( txn )


def all_of( self , attrType ):
	__all = []
	if attrType == self.w3_conn:
		for i in self.conf_chains( return_type=int ):
			__all.append( { self.a_conn( i ) : attrType( i ) } )
		return __all
	elif attrType == self.w3_contract:
		for i in self.conf_chains( return_type=int ):
			for j in self.chain_contracts( i ):
				__all.append( { self.a_contract( i , j ) : attrType( i , j ) } )
		return __all
	elif attrType == self.w3_events:
		return self.w3_events()
	else:
		for i in self.conf_chains( return_type=int ):
			for j in self.chain_contracts( i ):
				for k in self.w3_events( i , j ):
					__all.append( { self.a_filter( i , j , k.event_name ) :  attrType( i , j , k.event_name ) } )
		return __all

def _partial( _dict ):
	assert( type( _dict ) == dict )
	values = []
	_dictKeys = list( _dict.keys() )
	for i in _dictKeys:
		value = _dict.get( i )
		if value != '0x' or value != b'' or value != [] or value != 0:
			values.append( value )
	return len( _dictKeys ) != len( values )

def pathify( self , aether_path : str , node_name : str ):
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



# Generality
def _readFile( _filePath : str , _parse : bool = False ) -> str :
	if not isfile( _filePath ) :
		raise GenErr( 'no_file' , _filePath )
		quit()
	try:
		with open( _filePath , 'r' ) as fin:
			if( _parse ):
				return loads( fin.read() )
			return fin.read()
	except:
		with open( _filePath , 'r' ) as fin:
			string = fin.read()
			string = sub(",[ \t\r\n]+}", "}", string)
			string = sub(",[ \t\r\n]+\]", "]", string)
			if( _parse ):
					return loads( string )
			return string

def _writeFile( _filePath : str , _data : str , _parse = False , _enforce = False ) -> str :
	if isfile( _filePath ) and not _enforce :
		_check = input( ' Generality : Are you sure you want to overwrite <%s> (y/n) ? '%_filePath )
		if _check != 'y' or _check != 'yes':
			return
	with open( _filePath , 'w' ) as fout:
		if _parse:
			return fout.write( dumps( _data, indent=4 ) )
		return fout.write( _data , indent=4 )

def _recGet( _obj : dict , *keys ) :
	for i in keys:
		if i in _obj.keys():
			if len(keys) > 1:
				return _recGet( _obj[i] , *[j for j in keys if j != i] )
			else:
				return _obj[i]
	return None

def _jsonGET( _filePath : str , _key : str ) :

	return _readFile( _filePath , True )[_key]

def __populate( _dictName:str , _dict:dict ) -> dict : 
	
	return({ _dictName : _dict })

def __trim( _dict: dict ) -> tuple :
	
	return list( _dict )[0]

def clear():

	print( 100 * '\n' )

def frmtSTR( _str , remove='' , upper=False , lower=False ):
	if remove:
		temp = str( _str ).replace( remove , '' )
	if upper:
		temp = temp.upper()
	if lower:
		temp = temp.lower()
	return temp

def unicode_number( num ):
	return {
		0 : '\U0001D7E2',
		1 : '\U0001D7E3',
		2 : '\U0001D7E4',
		3 : '\U0001D7E5',
		4 : '\U0001D7E6',
		5 : '\U0001D7E7',
		6 : '\U0001D7E8',
		7 : '\U0001D7E9',
		8 : '\U0001D7EA',
		9 : '\U0001D7EB'
	}.get( int( num ) , None )

# Randomness
def getRandomString( _chars: int ) -> str:
	temp = ''
	lowercase_length = len( ascii_lowercase )
	for i in range( _chars ):
		temp += ascii_lowercase[ randint( 0 , lowercase_length ) ]
	return temp

def getRandomHex( _bytes: int ) -> str :
	temp = '0x'
	hexcase_length = len( hexdigits )
	for i in range( _bytes * 2 ):
		temp += str( hexdigits[ randint( 0 , hexcase_length - 1 ) ] )
	return temp


# Exceptions
def _formatArgs( args: list ) -> str :
	_arglog = ""
	for argument in args:
		_arglog += "%s\n"%str( argument )
	return _arglog

class ConfErr(Exception):
	def __init__( self , errorNo , *args ):
		self.errorNo = errorNo
		self.message = 'ConfigurationError :: Errorno %s -> %s : %s'%( str( errorNo ) , self._getConfErrStr( errorNo ) , _formatArgs( args ) )
		super().__init__( self.message )
	def _getConfErrStr( self , errorNo: int ) -> str :
		_switch = {
			1:'The supplied url for chainId is not a wss endpoint.',
			2:'Cannot determine the chainId(s) supplied by the `rpc.conf.json` file.',
			3:'A connection to the WSS endpoint cannot be established.',
			4:'Unable to obtain all Aether contracts addresses from the router.',
			5:'Could not obtain a public address from the private key supplied.',
			6:'Enivroment path specified is not a directory.',
			7:'Enivroment path does not contain the required `rpc.conf.json` , `env.conf.json` files.',
			8:'Node configurations are not found.'
		}
		return _switch.get( errorNo , None )

class GenErr(Exception):
	def __init__( self , errorName , *args ):
		self.errorName = errorName
		self.message = 'GeneralityError :: Errorno %s -> %s : %s'%( errorName , self._getGenErrStr() , _formatArgs( args ) )
		super().__init__( self.message )
	def _getGenErrStr( self ) -> str :
		_switch = {
			'no_file':'No such file.',
			'no_path':'No node path specified.',
			'not_bytes':'Not a bytes type'
		}
		return _switch.get( self.errorName , None )

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





