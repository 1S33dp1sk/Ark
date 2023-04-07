from os.path import isdir
from .utils import pathify
from .tru import Dynamic
from .configs import Configuration
from .looping.controller import start


class Node( Dynamic , Configuration ):
	def __init__( self , aether_path='' , node_name='' ):
		pathify( self , aether_path , node_name )
		Dynamic.__init__( self )
		Configuration.__init__( self )
		start( self )

	def handle_entry( self , chainId , contractName , entry ):
		print( chainId )
		print( contractName )
		_event = entry['event']
		print( _event )
		_args = dict( entry['args'] )
		print( _args )
		print( self.w3_mirror( chainId , contractName , _event ).__reflection__() )
		print( self.w3_mirror( chainId , contractName , _event).reflect( _args ) )
