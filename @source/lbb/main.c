#include "lbb.h"



int main( int argc , char **argv ) {

	struct seam *lines;

	__lbb ud;
	memset( &ud , 0 , sizeof( ud ) );
	strcpy( ud.lbb_path , __LBB_NAME );

	if ( exists( ud ) == -1 ) {
		printf( "no lbb found, creating one\n" );
		create( ud );
	}
	else {
		printf( "lbb found, initializing...\n");
		init( ud );
	}

	if ( !status( ud ) ) {
		printf( "lbb status cannot be determined\n" );
		return 1;
	}
	printf( "lbb : size = %d bytes\n" , size( ud ) );	

	if ( ud.lbb_fd <= 0 ) {
		printf( "lbb file cannot be accessed\n" );
		return 2;
	}
	printf( "lbb : fd = %d\n" , ud.lbb_fd );


	int compilation_res = compile_lbb( __read( &ud ) , &lines );

	#ifdef VERBOSE_DEBUG
		printf( "\n lines = \n k :: %.*s\n v :: %.*s\n" , 
		(lines[0].key).tal , (lines[0].key).sptr , 
		(lines[0].wry).tal , (lines[0].wry).sptr );
	#endif

	switch ( argc ) {
		case 2:
			__query( &ud , argv[1] );
			break;
		case 3:
			lbb_append( &ud , argv[1] , argv[2] );
			break;
		default:
			printf( "usage :: @lbb [key] [value]\n" );
			break;
	}

	cleanup( ud , lines );
	return 0;
}