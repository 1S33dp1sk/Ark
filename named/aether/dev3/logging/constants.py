from dataclasses import dataclass



@dataclass
class Colors:
	NO_COLOR: str = '\033[0m'
	VIOLET: str = '\033[1;94m'
	PINK: str = '\033[1;35m'
	BLUE: str = '\033[1;36m'
	WHITE: str = '\033[1;37m'
	GREEN: str = '\033[1;32m'
	RED: str = '\033[0;31m'
	YELLOW: str = '\033[1;33m'