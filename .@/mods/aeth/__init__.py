#!/usr/bin/python3 
# from asyncio import get_event_loop,sleep,gather
# from inspect import getfullargspec,stack
# from copy import deepcopy


from sys import argv
from _configs	import Contracts, DaoVars
from _aether	import log, Logger, Configuration, Node
from _utils		import _getCaller, GenErr, Settings


def temp(_args):
	if not _args:
		raise GenErr('no_path')
	else:
		log("Bridge")
		for i, _arg in enumerate(_args):
			print("\nargc : %d :: %s\n"%(i, _arg))
	x = Node(i for i in _args)
	return 0




# Context Execution
if __name__=='__main__':
	logger = Logger()
	config = Configuration()
	if not argv or ',' not in argv[1]:
		pass
	_args_list = argv[1].split(',')
	_caller = _args_list[0]
	_alias = _args_list[1].strip()
	_others = _args_list[2:]
	public_address = _getCaller(_caller)
	_auth3 = {
		'srv':'aeth',
		'domain':"d-cloud.io",
		"path":"@charms/d.run/",
		"alias":"@charms/d.lbb/%s"%(str(_alias)),
		"address":str(public_address['pubKey']),
	}
	print(_auth3)
	with open(_auth3['alias'], 'a') as fout:
		fout.write(public_address['pubKey'])


