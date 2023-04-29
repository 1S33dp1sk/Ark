#!/usr/bin/python3 
# from asyncio import get_event_loop,sleep,gather
# from inspect import getfullargspec,stack
# from copy import deepcopy


from sys import argv
from _configs	import Contracts, DaoVars
from _dynamic	import log,Node
from _utils		import GenErr, Settings


def temp(_args):
	if not _args:
		raise GenErr('no_path')
	else:
		log("Bridge")
		for i, _arg in enumerate(_args):
			print("\nargc : %d :: %s\n"%(i, _arg))
	x = Node(_args[0], _args[1])
	return 0

# Context Execution
if __name__=='__main__':
	log(".PY ")
	temp(argv)

