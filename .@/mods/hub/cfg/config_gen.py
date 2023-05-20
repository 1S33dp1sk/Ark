

def _getRouterAddresses( aether_names : list , chainWss : str , routerAddr : str , routerAbi : list ) -> dict :
	_w3 = _connectWss( chainWss )
	a_addresses = {}
	contract = _initContract( _w3 , routerAddr , routerAbi )
	for i in aether_names:
		try:
			a_addresses.update( __populate( i , execViewCall( contract , 'getAetherAddress' , i ) ) )
		except:
			a_addresses.append( None )
	return a_addresses

def _getEnvAddresses( aether_names : list , envJSON : dict ) -> list :
	temp = {}
	for name in aether_names:
		temp_addr = envJSON['%s_ADDR'%name.replace( 'AETHER_' , '' )]
		temp.update( __populate( name , temp_addr ) )
	return temp

def _getConnectTo( contractNames : list ) -> dict :
	temp = {}
	for i in contractNames:
		temp.update( __populate( i , '' ) )	
	return temp

def _getABIS( aether_names : list , aether_abis : dict ) -> dict :
	temp_abis = {}
	for name in aether_names:
		temp_abis.update( __populate( name , aether_abis[name] ) )
	return temp_abis


def getConf( conf_arr : list , chainId : str ) -> dict :
	for i,n in enumerate( conf_arr ):
		if( list( n.keys() )[0] == chainId ):
			return conf_arr[i][chainId]
	return None

def checkEnvDir( _dirpath : str ) -> bool :
	if not isdir( _dirpath ):
		raise ConfErr( 6 )
		quit()
	return True

def checkEnvFiles( _dirpath : str ) -> bool :
	_fileRpc = '%s/%s'%( _dirpath ,'rpc.conf.json' ) 
	_fileEnv = '%s/%s'%( _dirpath ,'env.conf.json' )
	if not isfile( _fileRpc ) or not isfile( _fileEnv ) :
		raise ConfErr( 7 , _fileRpc , _fileEnv )
		quit()


def _getStaticProps( _mirrors : dict , _abis : dict ) -> dict :
	reflections = {
		'contracts':_mirrors 
		'actions':[],
		'reactions':[]
	}
	for mirror in _mirrors:
		for reflect in _mirrors[mirror]:
			reflections['actions'].append( str( reflect ) )
			reflections['reactions'].append( str( _mirrors[mirror][reflect] ) )
	



if __name__ == '__main__':
	print("Hello")
	getJsons( argv[-1] )























