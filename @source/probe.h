/**
definitions :: <improv : add GNU|OS dependent MAX LIMITS>
**/
#define max_str 256
#define max_path 4096
#define init_kurl 0x0001
#define arr_size( _ ) ( sizeof( _ ) ) / ( sizeof( ( _ )[0] ) )

int __file_exsits( char *_name ) {
	struct stat __st;
	return stat( _name , &__st ) == 0;	
}

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
	return __al__( __ ) ;
}
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
// can convert to network & host byte order
// via byte definition
#define s_local "127.0.0.1"
		// localhost ipv4 loopback interface address
#define s_local_alias "localhost"
		// localhost ipv4 loopback interface unix alias
#define s_localv6 "::1"
		// localhost ipv6 shorthand loopback interface  
#define s_local2v6 "0:0:0:0:0:0:0:1"
		// localhost ipv6 loopback interface address
#define s_global "0.0.0.0"
		// outgoing ipv4 interface address
#define nai_max 3
		// supported natives < 0 , 1 , 2 , 3 >
#define mpath_max 512
		// mount path must be less than 512 bytes
#define saddr_max 16
		// socket address max is ipv6 which is 16 bytes
#define dstr_max 128
		// {sub,named,toplevel} domain must be less than 128 bytes each
#define baddr_max 256
		// blockchain address is 256 bytes max
#define bid_max 3
		// blockchain identitfer must be 3 characters
struct level_aliases {
	unsigned lnum;
	char *lname;
	char *lnetname;
} aliaslist[] = { 
	{	0 ,	"agent"	, "hostnet"		},
	{	1 ,	"local"	, "intranet"	},
	{	2 ,	"globe"	, "internet"	},
	{	3 ,	"block"	, "chainnet"	}
};

#ifndef point
	#include "point/point.h"
#endif

#ifndef hbar
	#include "hbar/hbar.h"
#endif

#ifndef lbb
	#include "lbb/lbb.h"
#endif

#ifndef nai
	#include "nai/nai.h"
#endif 

