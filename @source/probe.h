#ifndef probe
	#define probe void *

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
/**
definitions :: <improv : add GNU|OS dependent MAX LIMITS>
**/
#ifndef __anet_constants
	#define __anet_constants__ 1
	#define init_kurl 0x0001
	#define arr_size( _ ) ( sizeof( _ ) ) / ( sizeof( ( _ )[0] ) )
#endif
#define __anet_constants __anet_constants__

#if ( !defined( __file_exsits ) && !defined( check_file ) )
	#include <sys/stat.h>
	#ifndef check_file
		extern int check_file( char *_name ) {
			struct stat __st;
			return stat( _name , &__st ) == 0;	
		}
	#endif
#endif
#define __file_exsits check_file

#ifndef __kurl_probe__
	#define __kurl_probe__
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
#endif


#if ( !defined( aliaslist ) && !defined( lvl_st )  )
	#define lvl_st level_aliases
	struct level_aliases {
		unsigned lnum;
		char *lname;
		char *lnetname;
	} __aliaslist[] = { 
		{	0 ,	"agent"	, "hostnet"		},
		{	1 ,	"local"	, "intranet"	},
		{	2 ,	"globe"	, "internet"	},
		{	3 ,	"block"	, "chainnet"	}
	};
#endif
#define __aliaslist aliaslist


// #define __kurl__( __ ) \
	// 		do {\
	// 			__ = al__ init_kurl;\
	// 			p_ref = &__;\
	// 			return __al__( __ );\
	// 		} while ( 0 )
	// 	#define al int 
	// 	#define al__ ( int * )
	// 	#define __al__( __ ) (( al2 )( __ ))
	// 	#define al2 long
	// 	static probe p_ref;
	// 	#ifndef builder
	// 		#define builder 
	// 		extern al2 builder __kurl__( p_ref ) {
	// 			__ = al__ init_kurl;
	// 			p_ref = &__;
	// 			return __al__( __ ) ;
	// 		}
	// 	#endif
	// 	#define nin ( ( long ) ( -1&0xf000000000000000 ) )
	// 	#define pin ( ( long ) ( +1|0x0111111111111111 ) )

#include <sys/stat.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <stdint.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>
#include <regex.h>
#include <stdlib.h>
#include <netdb.h>
// TODO :: convert to strict bytes instead of arpa/inet
#include <arpa/inet.h>
#endif
