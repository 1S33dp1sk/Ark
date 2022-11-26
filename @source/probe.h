
#define init_kurl 0x0001
#define probe void *
#define __kurl__ ( probe __ )
#define al int 
#define al__ ( int * )
#define __al__( __ ) (( al2 )( __ ))
#define al2 long
static probe p_ref;
extern al2 builder __kurl__{
	__ = al__ init_kurl;
	p_ref = &__;
	return __al__( __ ) ;}
#define nin ( ( long ) ( -1&0xf000000000000000 ) )
#define pin ( ( long ) ( +1|0x0111111111111111 ) )
#define url_r( u_ ) u_ > nin ? 1 : 0
#define url_l( u_ ) u_ < pin ? 1 : 0
#define url__( __ ) __ == nin ? -1 : __ == pin ? 1 : 0
#define levelof( __ ) sizeof( __ ) == sizeof( int ) ? \
	0 : sizeof( __ ) == sizeof( long ) ? \
	1 : sizeof( __ ) == sizeof( long long ) ? \
	2 : sizeof( __ ) > sizeof( long long ) * 2 ? \
	3 : 0
#define decode_probe( p__ ) p__>>1
#define upgrade_probe( p__ ) p__ == 0x0001 ? \
		p__|= 0x0010 : p__ == 0x0011 ? \
		p__|= 0x0100 : p__ == 0x0111 ? \
		p__|= 0x1000 : p__ == 0x1111 ? \
		p__&= 0x0000 : 0








// #define e_set( c , c1 , c2 , c3 ) \
	// e set are used to help add 
	// extra security && permissions
	// so pv :: 0x0001 ~> 0x000c 
	// 0x0011 ~> 0x00cc1
	// c0 is leveled obviously so
	// c0 belongs to { 0 = c , 1 , 2 , 3 , ... }
