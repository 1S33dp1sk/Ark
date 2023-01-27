from generality.formatting import _formatArgs
from ..constants.error import _getConfWarnStr,_getErrorStr,_getWarningStr,_getAssertStr

class ExecErr( Exception ):
	def __init__( self , errorNo:int , *args:tuple ):
		self._message = 'ExecutionError :: Errorno %s -> %s : %s'%( str( errorNo ) , _getErrorStr( errorNo ) , _formatArgs( args ) )
		super().__init__( self._message )

class ConfErr(Exception):
	def __init__( self , errorNo , *args ):
		self.errorNo = errorNo
		self.message = 'ConfigurationError :: Errorno %s -> %s : %s'%( str( errorNo ) , _getConfErrStr( errorNo ) , _formatArgs( args ) )
		super().__init__( self.message )

class GenErr(Exception):
	def __init__( self , errorName , *args ):
		self.errorName = errorName
		self.message = 'GeneralityError :: Errorno %s -> %s : %s'%( errorName , _getGenErrStr() , _formatArgs( args ) )
		super().__init__( self.message )

