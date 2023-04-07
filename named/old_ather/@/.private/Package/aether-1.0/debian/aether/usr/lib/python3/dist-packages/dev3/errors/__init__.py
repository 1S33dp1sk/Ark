from .constants import _getErrorStr,_getConfErrStr,_getGenErrStr



def _formatArjs( arjs: list ) -> str :
	_arjlog = ': ' if len( arjs ) > 0 else ''
	for arj in arjs:
		_arjlog += "%s\n"%str( arj )
	return _arjlog

class ExecErr( Exception ):
	def __init__( self , errorNo:int , *arjs:tuple ):
		self._message = '\n\n\tExecutionError :: Errorno %s -> %s %s'%( str( errorNo ) , _getErrorStr( errorNo ) , _formatArjs( arjs ) )
		super().__init__( self._message )

class ConfErr(Exception):
	def __init__( self , errorNo , *arjs ):
		self.errorNo = errorNo
		self.message = '\n\n\tConfigurationError :: Errorno %s -> %s %s'%( str( errorNo ) , _getConfErrStr( errorNo ) , _formatArjs( arjs ) )
		super().__init__( self.message )

class GenErr(Exception):
	def __init__( self , errorName , *arjs ):
		self.errorName = errorName
		self.message = '\n\n\tGeneralError -> %s %s'%( _getGenErrStr( errorName ) , _formatArjs( arjs ) )
		super().__init__( self.message )

class ParsrErr( Exception ):
	def __init__( self , errorName , *arjs ):
		self.errorName = errorName
		self.message = '\n\n\tParserError -> %s %s'%( _getGenErrStr( errorName ) , _formatArjs( arjs ) )
		super().__init__( self.message )


class GeneratorError(Exception):
	def __init__( self , errStr , *arjs ):
		self.message = '\n\n\tGeneratorError -> %s %s'%( errStr , str( arjs ) )
		super().__init__( self.message )	