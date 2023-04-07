
def _addNodeAddress( _nodePath: str , _addr:str ):
	_w3 = Web3()
	_csAddr = _w3.toChecksumAddress( _addr )
	_filepathENV = '%s/.conf/env.conf.json'%_nodePath
	_filepathCONFIG = '%s/.conf/config.json'%_nodePath
	if not isfile( _filepathENV ) or not isfile( _filepathCONFIG ) :
		raise ConfErr( 8 , _nodePath )
		quit()
	temp_env = _readFile( _filepathENV , True )
	temp_env["NODE_ADDR"] = _csAddr
	_writeFile( _filepathENV , temp_env , True , True )
	temp_conf = _readFile( _filepathCONFIG , True )
	_chains = temp_conf["CHAINS"]["chainIds"]
	for j in _chains:
		temp_conf["CHAINS"][str(j)]["contracts"]["AETHER_NODE"] = _csAddr
	_writeFile( _filepathCONFIG , temp_conf , True , True )




if __name__ == '__main__':
	_addNodeAddress( argv[-2] , argv[-1] )