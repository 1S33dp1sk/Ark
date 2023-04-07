#include "kat.h"



static char template_call[23] = "K @ athername {\n\tmor\n}";



int main( int argc , char **argv ) {
	// if ( argc < 2 ){
	// 	printf( "usage :: kat /path/to/file\n" );
	// 	return 1;
	// }
	// get contents of file.

	printf( "\nkat :<compiler>: self\n" );
	int total_calls;
	kommand __k__;
	kall *__kall;
	__k__.ops = &__kall;
	__k__.ops_count = 0;
	__k__.__raw = template_call;
	__k__.__len = strlen( template_call );

	if ( ( total_calls = atomic( &__k__ ) ) > 0 )
		printf( "total amount of calls :: %d\n" , total_calls );
	



	return 0;
}