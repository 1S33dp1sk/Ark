from web3 import Web3

ZERO_ADDRESS = '0x0000000000000000000000000000000000000000'

def connect_wss( _wss : str ) :
	try:
		return Web3( Web3.WebsocketProvider( _wss ) )
	except:
		raise GeneratorError( 'Cannot Establish Connection ' , str( _wss ) )

def get_balance( _w3 : Web3 , callerAddr : str ) -> str :

	return _w3.eth.get_balance( _w3.toChecksumAddress( callerAddr ) )

