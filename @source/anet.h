/// athernet \\\

#define kurl__init__hat "__entry__"


#if !defined( check_file )
	#include "sys/stat.h"
	extern int __file_exsits( char *_name ) {
		struct stat __st;
		return stat( _name , &__st ) == 0;	
	}
#endif
#define check_file __file_exsits
#if !defined( stdptr )
	#include <stddef.h>
    size_t __size_ptr( unsigned _lvl ) {
    	unsigned long quant_bc = 1 , __level = ( int ) _lvl;
        while ( __level > 0 ){
            quant_bc *=4;
            __level--;
        }
    	return ( size_t ) quant_bc;
	}
	#include <stdlib.h>
	void *__gen_ptr( size_t __size ) {
#define __kurl_size __size
		if ( ( __size % 4 ) == 0 ) {
			return malloc( __size );
		}
	}
#endif
#define stdptr __gen_ptr
#if !defined( __kurl_version )
	#include "kurl/kurl.h"
#endif
#if !defined( __lbb_name )
	#define lbb_init 1
	#include "lbb/lbb.h"
#endif












// /**
// definitions :: <improv : add GNU|OS dependent MAX LIMITS>
// **/
// #if ( !defined( aliaslist ) && !defined( lvl_st )  )
// 	#define lvl_st struct level_aliases
// 	struct level_aliases {
// 		unsigned lnum;
// 		char *lname;
// 		char *lnetname;
// 	} __aliaslist[] = { 
// 		{	0 ,	"agent"	, "hostnet"		},
// 		{	1 ,	"local"	, "intranet"	},
// 		{	2 ,	"globe"	, "internet"	},
// 		{	3 ,	"block"	, "chainnet"	}
// 	};
// #endif
// #define aliaslist __aliaslist



// #if defined( point_name__ )

// 	#include "point/point.h"
// #endif



// #ifndef __anet_h__
// 	#include "anet.h"
// #endif

// #ifndef point
//     #include "point/point.h"
// #endif

// #ifndef hbar
//     #include "hbar/hbar.h"
// #endif

// #ifndef lbb
//     #include "lbb/lbb.h"
// #endif

// #ifndef nai
//     #include "nai/nai.h"
// #endif 



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


// #ifndef __kurl_probe__
// 	#define __kurl_probe__ upgrade_probe
// 	#define url_r( u_ ) u_ > nin ? 1 : 0
// 	#define url_l( u_ ) u_ < pin ? 1 : 0
// 	#define url__( __ ) __ == nin ? -1 : __ == pin ? 1 : 0
// 	#define levelof( __ ) sizeof( __ ) == sizeof( int ) ? \
// 		0 : sizeof( __ ) == sizeof( long ) ? \
// 		1 : sizeof( __ ) == sizeof( long long ) ? \
// 		2 : sizeof( __ ) > sizeof( long long ) * 2 ? \
// 		3 : 0
// 	#define decode_probe( p__ ) p__>>1
// 	#define upgrade_probe( p__ ) p__ == 0x0001 ? \
// 			p__|= 0x0010 : p__ == 0x0011 ? \
// 			p__|= 0x0100 : p__ == 0x0111 ? \
// 			p__|= 0x1000 : p__ == 0x1111 ? \
// 			p__&= 0x0000 : 0
// #endif




// // TODO :: convert to strict bytes instead of arpa/inet




// #if defined( __lbb_name )
// 	#include <regex.h>
// #endif

// #if defined( __nai_name )
// 	#include <netinet/in.h>
// 	#include <sys/socket.h>
// 	#include <netdb.h>
// 	#include <arpa/inet.h>
// #endif

// #if !defined( __hat__ )
// 	#include "kurl/kurl.h"
// #endif
