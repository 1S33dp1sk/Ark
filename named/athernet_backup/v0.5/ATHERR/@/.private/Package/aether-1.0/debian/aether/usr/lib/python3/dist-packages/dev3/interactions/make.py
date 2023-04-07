from ..errors import ConfErr
from ..utils.w3 import connect_wss
from ..logging import Logger

def make_connections( self ):
	for _chain in self.chain_ids:
		try:
			chain_attrs = self.__getattribute__( _chain )
			chain_attrs.update( {'w3' : connect_wss( chain_attrs.get( 'wss' , None ) )} )
			self.__setattr__( _chain , chain_attrs )
		except:
			raise ConfErr( 3 , _chain )




def make_all( self ):
	make_connections( self )
	make_filters( self )
	make_functions( self )