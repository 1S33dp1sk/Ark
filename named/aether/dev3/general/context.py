
from sys import argv

from .error import ConfErr,GenErr
from .fileIO import _readFile,_writeFile
from .formatting import clear,frmtSTR,unicode_number,_formatArgs
from .key_value import _recGet,_jsonGET,mkdict,rddict
from .randomness import getRandomString,getRandomHex
from .w3 import _bytesToHex,_hexify,_connectRpc,_connectWss,_initContract,_getBalance,_getNonce,execViewCall,execActionCall
from .constants import configuration_errors,general_errors,ZERO_ADDRESS

def assertion( func ):
	def _inner( *args , **kwargs ):
		self = args[0]
		if not all( [i for i in args] ) and not all( [kwargs.get( i ) for i in kwargs.keys()] ):
			return self.log_error( 13 , func.__name__ )
		return func( *args , **kwargs )
	return _inner
# Context Execution
if __name__ == '__main__':
	if len( argv ) > 1:
		_filename = argv[1] if ( argv[1].startswith( './' ) or argv[1].startswith( '/' ) ) else './%s'%argv[1]
		exec( open( _filename ).read() )
	else:
		raise GenErr( 'no_path' )
