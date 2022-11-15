#include "hbar.h"
#include <stdio.h>

/**
 * NOTICE :: missing file hashing
 */


char *hash_bar( char *hbar_in , unsigned level , char *hbar_out )  {

    int _ilen = strlen( hbar_in );
    uint8_t *__hash;

    switch ( level ) {
        case 0: 
        	sprintf( hbar_out , "@%x" , super_fast_hash( hbar_in , _ilen ) ); 
        	break;
        case 1:
            sha3_init384( &__sha3 );
            sha3_set_flags( &__sha3 , 1 );
            sha3_update( &__sha3 , hbar_in , _ilen );
            __hash = ( uint8_t * ) sha3_finalize( &__sha3 );
            __htostr( hbar_out , __hash );
            break;
        case 2:
            sha3_init512( &__sha3 );
            sha3_set_flags( &__sha3 , 0 );
            sha3_update( &__sha3 , hbar_in , _ilen );
            __hash = ( uint8_t * ) sha3_finalize( &__sha3 );
            __htostr( hbar_out , __hash );
            break;
        case 3:
        default:
            sha3_init256( &__sha3 );
            sha3_set_flags( &__sha3 , 1 );
            sha3_update( &__sha3 , hbar_in , _ilen );
            __hash = ( uint8_t * ) sha3_finalize( &__sha3 );
            __htostr( hbar_out , __hash );
            break;
    }
    return hbar_out;
}




int main( int argc , char **argv ) {

	if ( argc != 3 ) {
		printf( "usage :: @hbar [level] [value/filepath]\n" );
		return 1;
	}

	if ( strlen( argv[1] ) != 1 ) {
		printf( "usage : hbar @levels : <0,1,2,3>\n" );
		return 1;
	}

	unsigned hbar_level;
	char __hbar[MAX_STR] , *tohash = strdup( argv[2] );

	switch ( argv[1][0] ) {
		case 48: hbar_level = 0; break;
		case 49: hbar_level = 1; break;
		case 50: hbar_level = 2; break;
		case 51: hbar_level = 3; break;
		default: printf( "usage : hbar @levels : <0,1,2,3>\n" ); return 1;
	}

	hash_bar( tohash , hbar_level , __hbar );

    printf( "%s\n" , __hbar );
	return 0;
}
