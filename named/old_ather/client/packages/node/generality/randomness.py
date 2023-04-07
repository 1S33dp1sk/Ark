from random import randint
from string import ascii_lowercase,hexdigits

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
