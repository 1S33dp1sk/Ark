from asyncio import get_event_loop,gather
from .looping import main_loop

def start( self ):
	self.loop = get_event_loop()
	try:
		self.loop.run_until_complete( gather( main_loop( self ) ) )
	finally:
		self.loop.close()
