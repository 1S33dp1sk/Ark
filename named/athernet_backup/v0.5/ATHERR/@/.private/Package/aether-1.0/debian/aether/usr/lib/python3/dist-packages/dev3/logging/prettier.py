from .constants import Colors

def unicode_number( num ):
	return {
		0 : '\U0001D7E2',
		1 : '\U0001D7E3',
		2 : '\U0001D7E4',
		3 : '\U0001D7E5',
		4 : '\U0001D7E6',
		5 : '\U0001D7E7',
		6 : '\U0001D7E8',
		7 : '\U0001D7E9',
		8 : '\U0001D7EA',
		9 : '\U0001D7EB'
	}.get( int( num ) , None )


class Prettier:
	def __init__( self ):
		pass

	def header( self , node_name='' , colored=True ):
		if not colored:
			_base = 'MOR-Server'
			_base += ' : %s'%node_name if node_name else ''
			return _base
		_base = '%sMOR-Server%s'%( Colors.VIOLET , Colors.NO_COLOR )
		_base += ' : %s'%node_name if node_name else ''
		return '%s :: '%_base

	def body( self , arjs , num_lines=1 , num_tabs=0 , colored=True ):
		_base = '\n'.join( ['\n' for i in range( int( num_lines / 2 ) )] )
		_base += ' \t'.join( ['\t' for i in range( num_tabs)] )
		_base += '\n'.join( ['\n' for i in range( int( num_lines / 2 ) )] )
		for _arj in arjs:
			_base += '%s'%str( _arj ) if colored else '%s %s %s\n'%( Colors.WHITE , str( _arj ) , Colors.NO_COLOR )
		return '%s'%_base

	def vars( self , kwarjs , colored=True ):
		_base = '<%s>'%', '.join( [arj for arj in kwarjs.keys()] )
		_base += ' : '
		_base += '<%s>'%', '.join( [str( val ) for val in kwarjs.values()] )
		return self.body( _base )

	def make_pretty( self , arjs , kwarjs ):
		_base = self.header()
		_base += self.body( arjs ) if arjs else ''
		_base += self.vars( kwarjs ) if kwarjs else ''
		return '%s'%_base



