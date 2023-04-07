#include "misc.h"
static sha3_context __sha3;
#include "lbb.h"


// the filesize for the lbb
// and the atype are global
// should be defined as a
// static or external var

int main( int argc , char **argv ) {

	if ( argc < 2 ) {
		printf("usage :: lbb (key/hash) [value]\n");
		return 2;
	}

	struct lbb _lbb = {0};
	nit_lbb( &_lbb , argv[1] , 0 );
	lbb_kv( &_lbb , "main" , "self" );
	lbb_kv_h( &_lbb , "main" , "self" );
	lbb_kv_hh( &_lbb , "main" , "self" );
	save_lbb( &_lbb );

	return 0;
}			