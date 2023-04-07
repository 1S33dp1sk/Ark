from inspect import stack
from os.path import isfile

from ..constants.error import _getErrorStr,_getWarningStr
from ..errors import ExecErr
from ..constants.colors import *
from .prettier import Prettier


class Logger( Prettier ):
	def __init__( self ):
		pass

	def _log( self , file_path='' , data='' ):
		if isfile( file_path ):
			self.file_log( open( file_path , 'a' ) , data )
		return self.prompt_log( data )

	def file_log( self , append_file , data ):
		_log_data = '\n%s'%data
		print( _log_data , file=append_file )

	def prompt_log( self , data ):
		if not data:
			return
		_log_data = self.header__( self.node_name )
		_log_data += self.tabbed__( data )
		print( _log_data )

	def aether_log( self , chainId , data ):
		if not data:
			return
		_log_data = self.header__( self.node_name )
		_log_data += self.update__( chainId , stack()[1][3] )
		_log_data += self.tabbed__( data ) 
		print( _log_data )

	def block_log( self , chainId=0 , block_num=0 , block_masterhash='0x' , block_aetherer='0x' , **kwargs ):
		_frame = self.frame__block( block_num , block_masterhash , block_aetherer )
		self.aether_log( chainId , _frame )
		self.log_data( 'BLOCK : %s :: Binding'%str( block_num ) )

	def transaction_log( self , chainId=0 , txn_hash='0x' , txn_cids=[] , txn_native='0.1251612' , txn_0xA='0x' , **kwargs ):
		_frame = self.frame__transaction( txn_hash , txn_cids , txn_native , txn_0xA )
		self.aether_log( chainId , _txn )
		self.log_data( 'TRANSACTION : %s '%txn_hash )

	def status_log( self , chainId=0 , **kwargs ):
		_status = '\t\t0xAether Node ID#%s'%str( self.node_name )
		_status = ''.join( ['\n\t\t%s\t: %s'%( i.upper() , kwargs.get( i ) ) for i in kwargs] )
		self.aether_log( chainId , _status )

	def fulfilled_log( self , chainId=0 , txn_hash='0x' , **kwargs ):
		_fulfilment = 'Aether Request : %s \u2714'%str( txn_hash )
		self.prompt_log( chainId , _fulfilment )

	def log_error( self , error_id=0 , *args ):
		_errStr = _getErrorStr( error_id )
		self.log_data( data='%sERROR%s : %s.'%( COLOR_RED , COLOR_NC , _errStr) ) 
		raise ExecErr( error_id , _errStr , args )
		quit()

	def log_warn( self , warning_id=0 ):
		_warnStr = _getWarningStr( warning_id )
		return self.prompt_log( data='%sWARNING%s : %s.'%( COLOR_YELLOW , COLOR_NC , _warnStr) )

	def log_status( self , status ):
		_statusStr = 'STATUS : '
		_statusStr += 'ONLINE' if status else 'OFFLINE'
		return self.prompt_log( data=_statusStr )

	def log_data( self , log_name='performance' , data='' , **kwargs ):
		try:
			_logName = {
				'online':'online.log',
				'performance':'performance.log',
				'transactions':'transactions.log'
			}.get( log_name , 'performance.log' )
			return self._log( '%s/%s'%( self._logPath , _logName ) , data )
		except:
			return
