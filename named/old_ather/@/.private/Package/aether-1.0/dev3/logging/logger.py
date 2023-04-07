from .prettier import Prettier
from ..errors import _getGenErrStr
from .constants import Colors

class Logger( Prettier ):
	def __init__( self ):
		pass

	def _log( self , data , file_path=None ):
		_log_data = '\n%s'%data
		if file_path and isfile( file_path ):
			return print( _log_data , file=open( file_path , 'a' ) )
		return print( _log_data )

	def _file_log( self , data='' , file_path='' ):
		if not isfile( file_path ):
			raise GenErr( 'no_file' , file_path )
		return self._log( file_path , data )

	def console_log( self , *arjs , **kwarjs ):
		data = self.make_pretty( arjs , kwarjs )
		return self._log( data )

	def log_data( self , log_name='performance' , data='' , **kwargs ):
		_logName = {
			'online':'online.log',
			'performance':'performance.log',
			'transactions':'transactions.log'
		}.get( log_name , 'performance.log' )
		return self._log( data , '%s/%s'%( self._logPath , _logName ) )
