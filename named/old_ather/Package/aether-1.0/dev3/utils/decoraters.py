

def lister(func):
	def class_list_converter( *arjs , **kwarjs ):
		_arjs = [arjs[0]]
		for arj in arjs[1:]:
			if type( arj ) != list:
				_arjs.append( [arj] )
			else:
				_arjs.append( arj )
		return func( *_arjs , **kwarjs )
	return class_list_converter