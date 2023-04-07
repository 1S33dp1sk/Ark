#include "../probe.h"

static sha3_context __sha3c;
static const char help_message[110] = "\n@auth ( usage :: auth [level] [combo] )\n levels :\n 1 : ascii password\n 2 : auth token\n 3 : signed message\n";



char *__sha3_str( char *__ );


int main( int argc , char **argv ) { 

	if ( argc != 3 ) {
		printf( help_message );
		return -1;
	}

	char __lhash = argv[1][0];
	char *__tohash = argv[2];
	int tohash_len = strlen( __tohash );

	if ( tohash_len < 5 ) {
		printf( "ather authnication requires at least `5` chars\n" );
		return -2;
	}

	switch ( __lhash ) {
		case '1':
			printf( "atomic ( %s )\n\t:: " , __tohash );
			break;
		case '2':
			printf( "local/global ( %s )\n\t:: " , __tohash );
			break;
		case '3':
			printf( "universal ( %s )\n\t:: " , __tohash );
			break;
		default:
			printf( help_message );
			return -3;
	}

	char *hashstr = __sha3_str( __tohash );
	printf( "%s\n" , hashstr );
}


char *__sha3_str( char *__ ) {
	#define HSTR_LEN 256
	char hashstr[HSTR_LEN];
	memset( &hashstr , 0 , sizeof( hashstr ) );

	sha3_init256( &__sha3c );
	sha3_set_flags( &__sha3c , 1 );
	sha3_update( &__sha3c , __ , strlen( __ ) );
	uint8_t *__hash = ( uint8_t *) sha3_finalize( &__sha3c );

	to_hashstr( hashstr , __hash );

	return strdup( hashstr );
}
