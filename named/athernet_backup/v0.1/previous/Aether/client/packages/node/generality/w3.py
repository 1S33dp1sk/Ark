from web3 import Web3
from .constants import ZERO_ADDRESS
# Web3

def _bytesToHex( _bytes: bytes ) -> str :
	if type( _bytes ) != bytes:
		return ''
	return '0x%s'%str( _bytes.hex() )

def _hexify( _hexList: list ) -> str:
	if type( _hexList ) != list:
		return ''
	return '0x%s'%''.join( [i.replace( '0x' , '' ) for i in _hexList] )

def connect_rpc( _rpc : str ) -> Web3 :

	return Web3 ( Web3.HTTPProvider( _rpc ) )

def connect_wss( _wss : str ) :

	return Web3 ( Web3.WebsocketProvider( _wss ) )

def init_contract( _w3 : Web3 , _addr : str , _abi : str ) : 

	return _w3.eth.contract( address = _addr , abi = _abi )

def get_balance( _w3 : Web3 , callerAddr : str ) -> str :

	return _w3.eth.get_balance( _w3.toChecksumAddress( callerAddr ) )

def get_nonce( _w3 : Web3 , callerAddr : str ) -> int :

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