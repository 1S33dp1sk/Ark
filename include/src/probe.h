///probe\\\

#ifndef __probe__h
	#define __probe__h "p0x0001"
	#define __probe_h "@hernet"
	#define __probe_version 0x0001
	#define __probe_cs__ 0x0700
	#ifdef __probe_cs__
		// can convert to network & host byte order via byte definition
		#define arr_size( _ ) ( sizeof( _ ) ) / ( sizeof( ( _ )[0] ) )
				// get the size of array. does not support char *s, but can be easily extended to match '\0'
		#define nai_max 0x3
				// supported natives < 0 , 1 , 2 , 3 >
		#define bid_max nai_max
				// blockchain identitfer must be 3 characters
		#define max_path 0x1000
				// maximum for os dependent path is 4096 bytes 
		#define mpath_max 0x200
				// mount path must be less than 512 bytes
		#define max_str 0x100
				// maximum consumable length for a misc string 
		#define baddr_max max_str
				// blockchain address is 256 bytes max
		#define dstr_max max_str
				// {sub,named,toplevel} domain must be less than 128 bytes each
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
	#endif

	static ulong level = 0;
#endif



/**
** required headers **
 * unistd.h
 * 
 * stdlib.h
 * stddef.h
 * stdint.h
 * stdio.h
 * 
 * string.h
 * regex.h
 * fcntl.h
 * netdb.h
 * 
 * sys/stat.h
 * sys/types.h
 * 
 * arpa/inet.h
**/

#if defined( __anet_name )
	#ifndef __anet__h
		#include <unistd.h>
		#include <stdlib.h>
		#include <stddef.h>
		#include <stdio.h>
		#include <string.h>
		#include <sys/stat.h>
		#define __anet__h 1
	#endif
#endif

#if defined( __nai_name )
	#ifndef __nai__h
		#include <unistd.h>
		#include <stdlib.h>
		#include <stdio.h>
		#include <string.h>
		#include <netdb.h>
		#include <sys/stat.h>
		#include <arpa/inet.h>
		#define __nai__h 1
	#endif
#endif

#if defined( __ap_name )
	#ifndef __point__h
		#include <unistd.h>
		#include <stdio.h>
		#include <string.h>
		#include <fcntl.h>
		#include <sys/stat.h>
		#define __point__h 1
	#endif
#endif

#if defined( __hbar_name )
	#ifndef __hbar__h
		#include <unistd.h>
		#include <stdlib.h>
		#include <stddef.h>
		#include <stdint.h>
		#include <stdio.h>
		#include <string.h>
		#include <fcntl.h>
		#include <sys/types.h>
		#include <sys/stat.h>
		#define __hbar__h 1
	#endif
#endif

#if defined( __lbb_name )
	#ifndef __lbb__h
		#include <unistd.h>
		#include <stdint.h>
		#include <stdio.h>
		#include <string.h>	
		#include <regex.h>
		#include <fcntl.h>
		#include <sys/types.h>
		#include <sys/stat.h>
		#define __lbb__h 1
	#endif
#endif

#if defined( __enti_name )
	#include <stdlib.h>
	#include <stdio.h>
#endif

#if defined( __kurl_name )
	#ifndef __kurl__h
		#ifndef __ap_name
			#include "point/point.h"
		#endif
		#ifndef __lbb_name
			#include "lbb/lbb.h"
		#endif
		#ifndef __hbar_name
			#include "hbar/hbar.h"
		#endif
		#ifndef __nai_name
			#include "nai/nai.h"
		#endif
		#define __kurl__h 1
	#endif
#endif



















































// /**
// improv : add GNU|OS dependent MAX LIMITS
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




