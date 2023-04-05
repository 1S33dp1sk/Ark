from asyncio import get_event_loop,gather
from .listener import main_loop

def start( self ):
	self.loop = get_event_loop()
	try:
		self.log_status( True )
		self.loop.run_until_complete( gather( main_loop( self ) ) )
	finally:
		self.log_status( False )
		self.loop.close()
