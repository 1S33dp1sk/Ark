from .aether_hub import ATxnReceive,ATxnRequest,ABlockBind,NodeRegistered
from .hello_world import logTxn
from inspect import getfullargspec
from sys import argv

class _0xAEngine:
	def __init__( self ):
		pass


	# def reaction_table( self )
	# def 

	def handle_entry( self , chainId , entry ):
		action = entry['event']
		params = entry['args']
		'''
		can easily retreive events
		from the contract ABI
		once done, please rename `reaction` -> `mirror`
		'''
		reaction = {
			'ATxnReceive'		:	self.ATxnReceive,
			'ATxnRequest'		:	self.ATxnRequest,
			'ABlockBind'		:	self.ABlockBind,
			'NodeRegistered'	:	self.NodeRegistered
		}.get( action , lambda: 'Unknown Event' )
		func_args = [chainId]
		for i in getfullargspec( reaction ).args[2:]:
			func_args.append( params.get( i ) )
		return reaction( *func_args )

if __name__ == __main__:
	_ = _0xAEngine()
	_.handle_entry(1, argv)