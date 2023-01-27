from .constants import general_errors,configuration_errors
from .formatting import _formatArgs

class ConfErr(Exception):
	def __init__( self , errorNo , *args ):
		self.errorNo = errorNo
		self.message = 'ConfigurationError :: Errorno %s -> %s : %s'%( str( errorNo ) , self._getConfErrStr( errorNo ) , _formatArgs( args ) )
		super().__init__( self.message )
	def _getConfErrStr( self , errorNo: int ) -> str :

		return configuration_errors.get( errorNo , None )

class GenErr(Exception):
	def __init__( self , errorName , *args ):
		self.errorName = errorName
		self.message = 'GeneralityError :: Errorno %s -> %s : %s'%( errorName , self._getGenErrStr() , _formatArgs( args ) )
		super().__init__( self.message )
	def _getGenErrStr( self ) -> str :

		return general_errors.get( self.errorName , None )
