from os.path import isfile
from json import loads,dumps
from re import sub
from ..errors import GenErr


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
