from inspect import isclass
from .constants import class_required_arjs
from ..errors import ConfErr

def configurize( _instance , _dict : dict ):
	for _conf in _dict:
		conf_dict = _dict.get( _conf )
		for _attr in conf_dict:
			_instance.__setattr__( _attr , conf_dict.get( _attr ) )

def check_attributes( _instance ):
	if set( class_required_arjs ).issubset( _instance.__dir__() ):
		if all( [arj for arj in _instance.__dict__] ):
			return True
	return False

def safe_configurize( _instance , _dict ):
	configurize( _instance , _dict )
	configured = check_attributes( _instance )
	if not configured:
		raise ConfErr( 1 )


def pathify( _instance , _logPath , _execPath ):
	if _logPath:
		self._logPath = _logPath
	if _execPath:
		self._execPath = _execPath