#include "probe.h"
#include <sys/types.h>
//@her specific
#include "pipes.h"
#include "sexec.h"



int main( int argc , char **argv ) {

	if ( argc != 2 ) {
		printf( "usage :: %s @callhub\n" , argv[0] );
		return -1;
	}

	char *fifo_path = argv[1];
	int __pathlen = strlen( fifo_path ) - 1;

	if ( fifo_path[0] != '/' ) {
		printf( "e -> the path supplied is not absolute.\n" );
		return -1;
	}

	if ( fifo_path[__pathlen] != '/' ) {
		printf( "e -> the path supplied is not a full directory path\n" );
		return -2;
	}

	strcat( fifo_path , "@point" );


	if ( __sys_entry( fifo_path ) == 1 ) {
		printf( "no atherpoint found.\n" );
		printf( "creating atherpoint -> %s :: " , fifo_path );
		int _ced = mkfifo( fifo_path , S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH );
		if ( _ced == 0 ) {
			printf( "DEF\n FIFO created successfully\n" );
			return 0;
		}
		else {
			printf( "NO DEF\n FIFO cannot be created\n" );
			return -3;
		}
	}
}