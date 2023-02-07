from re import sub

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

# courtesy of python community wiki on so
# https://stackoverflow.com/questions/1175208/elegant-python-function-to-convert-camelcase-to-snake-case
def to_snake_case( name ):
	name = sub( '(.)([A-Z][a-z]+)' , r'\1_\2' , name )
	name = sub( '__([A-Z])' , r'_\1' , name )
	name = sub( '([a-z0-9])([A-Z])' , r'\1_\2' , name )
	return name.lower()

# Exceptions
def _formatArgs( args: list ) -> str :
	_arglog = ""
	for argument in args:
		_arglog += "%s\n"%str( argument )
	return _arglog


