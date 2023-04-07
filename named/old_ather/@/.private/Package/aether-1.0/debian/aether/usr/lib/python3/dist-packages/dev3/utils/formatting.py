from re import sub


def secure_class( self , class_name : str ):

	return '%s'%to_snake_case( str( class_name.replace( '.' , '' ) ) )

def to_snake_case( name ):
	name = sub( '(.)([A-Z][a-z]+)' , r'\1_\2' , name )
	name = sub( '__([A-Z])' , r'_\1' , name )
	name = sub( '([a-z0-9])([A-Z])' , r'\1_\2' , name )
	return name.lower()

def mkdict( _dictName:str , _dict:dict ) -> dict : 
	
	return({ _dictName : _dict })