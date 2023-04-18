#!/usr/bin/python3 
# from asyncio import get_event_loop,sleep,gather
# from inspect import getfullargspec,stack
# from copy import deepcopy


from sys import argv
from _configs	import Contracts, DaoVars
from _dynamic	import log,Node
from _utils		import GenErr, Settings

# Context Execution
if __name__=='__main__':
	log("Bridge")
	if argv:
		for i, _arg in enumerate(argv):
			print("%d : %s"%(i, _arg))
		if len(argv) > 1:
			_filename = argv[1] if ( argv[1].startswith( './' ) or argv[1].startswith( '/' ) ) else './%s'%argv[1]
			exec( open( _filename ).read() )
		else:
			raise GenErr( 'no_path' )

