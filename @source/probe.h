#include "point/point.h"
#include "lbb/lbb.h"
#include "hbar/hbar.h"
#include "nai/nai.h"

#define init_kurl 0x0001
#define probe void *
#define __kurl__ ( probe __ )
static probe p_ref;

#define al int 
#define al__ ( int * )
#define __al__( __ ) (( al2 )( __ ))
#define al2 long

#define levelof( __ ) sizeof( __ ) == sizeof( int ) ? \
	0 : sizeof( __ ) == sizeof( long ) ? \
	1 : sizeof( __ ) == sizeof( long long ) ? \
	2 : sizeof( __ ) > sizeof( long long ) * 2 ? \
	3 : 0

#define decode_probe( p__ ) \
	p__>>1

#define upgrade_probe( p__ ) p__ == 0x0001 ? \
		p__|= 0x0010 : p__ == 0x0011 ? \
		p__|= 0x0100 : p__ == 0x0111 ? \
		p__|= 0x1000 : p__ == 0x1111 ? \
		p__&= 0x0000 : 0

#define temp( p__ ) \
		do { p__+=8; } while( 0 );

int log_al( al2 _val ) {
	printf( "probe : value : %lx\n" , _val );
	return 0;
}

int log_url( probe _ref ) {
	printf( "probe : ref = %p \n" , _ref );
	return 0;
}



extern al2 builder __kurl__{
	__ = al__ init_kurl;
	p_ref = &__;
	return __al__( __ ) ;
}











// #define e_set( c , c1 , c2 , c3 ) \
	// e set are used to help add 
	// extra security && permissions
	// so pv :: 0x0001 ~> 0x000c 
	// 0x0011 ~> 0x00cc1
	// c0 is leveled obviously so
	// c0 belongs to { 0 = c , 1 , 2 , 3 , ... }
