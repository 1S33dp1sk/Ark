from .fileIO import _readFile

def _recGet( _obj : dict , *keys ) :
	for i in keys:
		if i in _obj.keys():
			if len(keys) > 1:
				return _recGet( _obj[i] , *[j for j in keys if j != i] )
			else:
				return _obj[i]
	return None

def _jsonGET( _filePath : str , _key : str ) :

	return _readFile( _filePath , True )[_key]

def mkdict( _dictName:str , _dict:dict ) -> dict : 
	
	return({ _dictName : _dict })

def rddict( _dict: dict ) -> tuple :
	_key = list( _dict )[0]
	_value = _dict.get( _key )
	return _key,_value

