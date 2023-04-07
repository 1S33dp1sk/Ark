from os.path import isdir,isfile

def all_of( self , attrType ):
	__all = []
	if attrType == self.w3_conn:
		for i in self.conf_chains( return_type=int ):
			__all.append( { self.a_conn( i ) : attrType( i ) } )
		return __all
	elif attrType == self.w3_contract:
		for i in self.conf_chains( return_type=int ):
			for j in self.chain_contracts( i ):
				__all.append( { self.a_contract( i , j ) : attrType( i , j ) } )
		return __all
	elif attrType == self.w3_events:
		return self.w3_events()
	else:
		for i in self.conf_chains( return_type=int ):
			for j in self.chain_contracts( i ):
				for k in self.w3_events( i , j ):
					__all.append( { self.a_filter( i , j , k.event_name ) :  attrType( i , j , k.event_name ) } )
		return __all

def _partial( _dict ):
	assert( type( _dict ) == dict )
	values = []
	_dictKeys = list( _dict.keys() )
	for i in _dictKeys:
		value = _dict.get( i )
		if value != '0x' or value != b'' or value != [] or value != 0:
			values.append( value )
	return len( _dictKeys ) != len( values )

def pathify( self , aether_path : str , node_name : str ):
	self.node_name = node_name
	if not self.node_name:
		self.log_error( 0 )

	self.aether_path = aether_path
	if not isdir( aether_path ):
		self.log_error( 1 )

	self.node_path = '%s/nodes/%s.node'%( self.aether_path , self.node_name )
	if not isdir( self.node_path ):
		self.log_error( 7 )

	self._logPath =  '%s/logs'%self.aether_path
	if not isdir( self._logPath ):
		self.log_error( 8 )

	self._execPath = '%s/__%s__'%( self.node_path , node_name )
	if not isfile( self._execPath ):
		self.log_error( 9 )

	self._confPath = '%s/.conf/config.json'%self.node_path
	if not isfile( self._confPath ):
		self.log_error( 2 )

	self._cachePath = '%s/.A-block.json'%self.node_path
