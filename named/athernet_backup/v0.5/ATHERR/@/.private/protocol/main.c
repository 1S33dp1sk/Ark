#include <stdio.h>


int main( int argc , char **argv ) {
	if ( argc == 2 && argv[1][0] != '\0' ) {
		#ifndef AtherNode
			#include "@source/node.h"
		#endif	
		ather_node( argv[1] );
	}
	else if ( argc >= 2 ) {
		#ifndef AtherX
			#include "@source/xather.h"
		#endif
		_xather__( argv[1] , &*(&argv[2]) );
	}
	else {
		#ifndef AtherShell
			#include "@source/shell.h"
		#endif
		ather_shell();
	}
}


