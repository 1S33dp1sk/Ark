#include "point.h"



int main( int argc , char **argv ) {

	char *__path = argc >= 2 ? ( ( char * )argv[1] ) : "";
	int __level = argc == 3 ? argv[2][0] - '0' : 0;
	
	ap __;
	memset( &__ , 0 , sizeof( __ ) );


    #ifdef DEBUG
        printf( "@point :: checking FIFO for atherpoint\n" );
    #endif
    if ( !__ap_fifo( &__ ) ) {
        #ifdef DEBUG
            printf( "@point :: no atherpoint found, attempting to create one\n" );
        #endif
        if ( !__ap_make() ) {
            printf( "@point :: unable to create atherpoint\n" );
            return 2;
        }
    }

    __.lbb_fd = __ap_entry( __path , __level );


	return applier( &__ );
}
