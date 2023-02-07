from generality.formatting import unicode_number
from ..constants.colors import *
class Prettier:
	def __init__( self ):
		pass

	def header__( self , node_name='NE' , colored=True ):
		if not colored:
			return '\n 0xANode : %s'%node_name
		return '\n %s0xANode%s : %s'%( COLOR_VIOLET , COLOR_NC , node_name  )		

	def tabbed__( self , *arjs , num_lines=1 , num_tabs=2 , colored=True):
		if len( arjs ) > 1:
			return '\n\t'
		_base = '\n'.join(['\n' for i in range(int(num_lines/2))])
		_base += '\t'.join(['\t' for i in range(num_tabs)])
		_base += '\n'.join(['\n' for i in range(int(num_lines/2))])
		for _arj in arjs:
			_base += '%s'%str( _arj ) if colored else '%s %s %s\n'%( COLOR_GREY , str( _arj ) , COLOR_NC )
		return _base

	def update__( self , chain_id=0 , action_name='NE' , colored=True ):
		
		return '\n\t\t%s <CID, ACTION> : <%s, %s> '%( COLOR_GREY if colored else '' , chain_id , action_name )

	def frame__block( self , block_num , block_masterhash , block_aetherer ):
		_block = '\u0F3A  Aether Block #%s %s %s is Binding\t\u0F3B\t'%( COLOR_GREEN , str( block_num ) , COLOR_NC )
		_block += '\n  Block MASTERHASH \u227D %s\t Block Aetherer : %s'%( str( block_masterhash ) , str( block_aetherer ) )
		return _block

	def frame__transaction( self , txn_hash , txn_cids , txn_native , txn_0xA ):
		_txn = '\n\t\t\U0001D4DAchec\U0001D4DA : %s\t\t\t\tCHAIN_IDS \u21F6 < %s >'%( str( txn_hash ) , ', '.join( [str( cid ) for cid in txn_cids] ))
		_txn += '\n\t\test \u20BF %s\t\t\t\t\t0xAether DATA : %s '%( ''.join( [unicode_number( i ) if i.isdigit() else str( i ) for i in str( txn_native )] ) , str( txn_0xA ))
		return _txn