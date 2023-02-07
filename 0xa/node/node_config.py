from aether.configs.reflections import Reflection
from sys import argv

if __name__ == '__main__':
	_reflect = Reflection( argv[-1] )
	_reflect.remake()