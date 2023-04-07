// #include "types.h"
#include "helpers.h"


int main( int argc , char *argv[] ) {
	char *arg = (char*) argv[1];
	if ( argc >= 1 ) {
		printf("%s :: %x" , arg , super_fast_hash( arg , strlen( arg ) ) );
	} 
	return 0;
}