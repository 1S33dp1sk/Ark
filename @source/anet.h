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
<<<<<<< HEAD
	#include <stdio.h>
	#include <sys/types.h>
	#include <sys/stat.h>
	#include <string.h>
	#include <fcntl.h>

	#ifdef __anet_cs__
// can convert to network & host byte order via byte definition
		#define arr_size( _ ) ( sizeof( _ ) ) / ( sizeof( ( _ )[0] ) )
				// get the size of array. does not support char *s, but can be easily extended to match '\0'
		#define max_path 4096
				// maximum consumable length for os-path string 
		#define max_str 256
				// maximum consumable length for a misc string 
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
	#endif
	
	#if defined( __lbb_name )
		#include <regex.h>
	#endif

	#if defined( __nai_name )
		#include <netinet/in.h>
		#include <sys/socket.h>
		#include <netdb.h>
		#include <arpa/inet.h>
	#endif

	#if defined( __kurl_name )
	    #if ( !defined( kurl0 ) && defined( __kurl_version ) )
	        #include "kurl/the_0kurl.h"
	    #endif
	    #if ( defined( kurl0 ) && !defined( kurl1 ) )
	        #include "kurl/the_1kurl.h"
	    #endif
	    #if ( defined( kurl1 ) && !defined( kurl2 ) )
	        #include "kurl/the_2kurl.h"
	    #endif
	    #if ( defined( kurl2 ) && !defined( kurl3 ) )
	        #include "kurl/the_3kurl.h"
	    #endif
	    #if !defined( __hat__ )
	        #include "kurl/hat.h"
	    #endif	
	#endif



#endif
=======
	void *__gen_ptr( size_t __size ) {
		if ( ( __size % 4 ) == 0 ) {
#define __kurl_size __size
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
>>>>>>> 5c2d5f4 (alignments)
