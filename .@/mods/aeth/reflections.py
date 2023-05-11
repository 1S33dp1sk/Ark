from .. import onchain
from ..errors.Throwable import ConfErr
from ..errors import _getAssertStr
from ..constants.chains import chain_names,chain_symbols,chain_ids,cid_chains
from generality.w3 import Web3,get_balance,ZERO_ADDRESS,connect_wss
from generality.key_value import mkdict
from generality.formatting import to_snake_case
from generality.fileIO import _readFile,_writeFile
from inspect import getmembers,isclass,isfunction



''' L(isten) E(valuate) S(end)/R(ecognize)'''
class Reflection:
	def __init__( self , _dirpath : str ):
		self.default = mkdict( 'AETHER' , {'mirrors':[],'abis':[],'contracts':[],'addresses':[]} )
		self.__update( mkdict( 'CHAINS' , {'chainIds':[]} ) )
		self.__update( mkdict( 'CALLER' , {} ) )
		self._defaultPath = _dirpath

	def __to( self , c ):
		self.__connectTo = [self.secure_class( i ) for i in c]
		self.default['AETHER']['contracts'].extend( self.__connectTo )
		return self.__connectTo

	def __on( self , n ):
		self.__mirrorOn = [i for i in n]
		self.default['AETHER']['mirrors'].extend( self.__mirrorOn )
		return self.__mirrorOn

	def __at( self , a ):
		self.__reflectAt = list( filter( lambda _at : _at != ZERO_ADDRESS , a ) )
		self.default['AETHER']['addresses'].extend( self.__reflectAt )
		return self.__reflectAt

	def __which( self , b ):
		self.__whichC = list( filter( lambda _b : len( _b ) != 0 , b ) )
		self.default['AETHER']['abis'].extend( self.__whichC )
		return self.__whichC

	def __update( self , _dict ):
		
		return self.default.update( _dict )

	def __fromKEY( self , _pvtKey : str ) -> dict :
		try:
			_w3 = Web3()
			pubKey = _w3.eth.account.from_key( _pvtKey ).address
			return {'pvtKey' : _pvtKey, 'pubKey' : pubKey}
		except:
			raise ConfErr( 5 )
			quit()

	def __EBM( self , eb_eval ):
		try:
			init_ebm = getmembers( eb_eval , predicate=isclass )
			if len( init_ebm ) > 0:
				return init_ebm[0]
		except:
			pass

	def __EBR( self , eb_eval ):
		try:
			init_ebr = getmembers( eb_eval , predicate=isfunction )
			if len( init_ebr ) > 0:
				return init_ebr[0]
		except:
			raise ConfErr( 11 )

	def _getChainName( self , _chainProp : str ) -> str :
		chain_name = chain_names.get( _chainProp , None )
		if not chain_name:
			raise ConfErr(10)
		return chain_name

	def _getChainSymbol( self , _chainName : str ) -> str :
		chain_symbol = chain_symbols.get( _chainName , None )
		if not chain_symbol:
			raise ConfErr(10)
		return chain_symbol

	def _getChainId( self , _chainSymbol : str ) -> str :
		chain_id = chain_ids.get( _chainSymbol , None )
		if not chain_id:
			raise ConfErr(10)
		return chain_id

	def _getChainProps( self , _chainProp ):
		_name = self._getChainName( _chainProp )
		_symbol = self._getChainSymbol( _name )
		_id = self._getChainId( _symbol )
		return ( _name , _symbol , _id )

	def _getDynamicConfig( self , envJSON : dict , wssJSON : dict , abisJSON : dict , mirrorJSON : dict ) -> dict :
		_connect = envJSON.get( 'CONNECT_TO' , [] )
		__connect = [_connect] if type( _connect ) != list else _connect 
		self.__to( __connect )

		_mirrors = [mirrorJSON.get( i ) for i in __connect]
		__mirrors = [_mirrors] if type( _mirrors ) != list else _mirrors
		self.__on( __mirrors )

		_aether = [envJSON.get( i ) for i in __connect]
		__aether = [_aether] if type( _aether ) != list else _aether
		self.__at( __aether )

		_abis = [abisJSON.get( i ) for i in __connect]
		__abis = [_abis] if type( _abis ) != list else _abis
		self.__which( __abis )

		_chainNames = list( filter( lambda cid: wssJSON.get( cid ) != 'NE' , wssJSON ) )
		_chainProps = [self._getChainProps( i ) for i in _chainNames]
		_chainIds = [str( i[-1] ) for i in _chainProps]
		_chainWSS = [wssJSON.get( i ) for i in _chainNames]
		assert all( [connect_wss( wss_endpoint ).isConnected() for wss_endpoint in _chainWSS] ) , _getAssertStr( 6 )

		self.__update( mkdict( 'CHAINS' , mkdict( 'chainIds' , _chainIds ) ) )
		self.__update( mkdict( 'CALLER', self.__fromKEY( envJSON['CALLER_PVTKEY'] ) ) )

		for idx,_ in enumerate( _chainIds ):
			self.default['CHAINS'].update( mkdict( _ , {
					'wss': _chainWSS[idx],
					'balance': get_balance( connect_wss( _chainWSS[idx] ) , self.default['CALLER']['pubKey'] ),
					'chainId': int( _ ),
					'chainName' : _chainNames[idx],
					'chainSymbol' : _chainProps[idx][1],
				} ) )
		return True

	''' would be a better implementation if annonymous events are used ''' 
	def _getAbiEvents( self , _contractAbi : list ) -> dict :
		
		return list( filter( lambda itm: itm.get( 'type' ) == 'event' , _contractAbi ) )

	''' need to try @deployed for `onchain` directory parsing'''
	def _getAetherActions( self , mirrorJSON : dict , abisJSON : dict ) -> dict :
		self.__mirrors__ = []
		_contracts = set( mirrorJSON ).intersection( abisJSON )
		for c in _contracts:
			events_abi = self._getAbiEvents( abisJSON.get( c ) )
			for e_abi in events_abi:
				e_ebm = self._initAbiMirror( self.secure_class( c ) , e_abi )
		return True

	'''ethereum binary mirror EBM'''
	def _initAbiMirror( self , secure_CN : str , _abi : dict ) -> dict :
		__km = KMirror()
		__attrs = {
			'__by__': secure_CN,
			'__event__':_abi.get( 'name' , 'Annonymus' ),
			'__abi__':_abi,
			'__mirror__': eval( 'onchain.%s'%secure_CN )
		}
		for attr in __attrs:
			__km.__setattr__( attr , __attrs.get( attr ) )
		self.__mirrors__.append( __km )		

	def secure_class( self , class_name : str ):

		return '%s'%to_snake_case( str( class_name.replace( '.' , '' ) ) )

	def remake( self ) -> dict:
		_env = _readFile( '%s/%s'%( self._defaultPath , 'env.conf.json' ) , True )
		_wss = _readFile( '%s/%s'%( self._defaultPath , 'rpc.conf.json' ) , True )
		_abis = _readFile( '%s/%s'%( self._defaultPath , 'ABIS.json' ) , True )
		_mrr = _readFile( '%s/%s'%( self._defaultPath , 'mirror.json' ) , True )
		self._getDynamicConfig( _env , _wss , _abis , _mrr )
		# self._getAetherActions( _mrr , _abis )
		_writeFile( '%s/%s'%( self._defaultPath , 'config.json' ) , self.default , True , True )




if __name__ == '__main__':
	_ = Reflection(".")

