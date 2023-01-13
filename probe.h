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
	static unsigned long level = 0;
	static void ___next () {\
		level+=1;\
	}
	#ifndef ulong
		#define ulong unsigned long
	#endif
#endif

#ifndef aprocessor
	#define aprocessor "ap__u_charm"
	// # it's c but not really
	// the number of tabs control the access level allowed
	// # 0 -> nodef
	const static char __control = '\t';
	// # 2 -> command ( default_args || supplied_args )
	const static char _ignored[6] = { '@' , '#' , ':' , '=' , '\s' }; // regexs ::: [@|@&#|#] || #{:,=,\s}
	// # 3 -> define
	unsigned long count_tabs( void *__ , unsigned char _ ) {
		unsigned char *__c = (unsigned char *) __;
		unsigned long _r = 0;
		while ( __c != '\t' ) {
			if ( _ == 'l' ) {
				__c-=2;
			}
			_r+=1;
			__c+=1;
		}
		return _r;
	}
	// # 4 -> kmem_alloc( base_ , _size )
	void *kmem_alloc( unsigned long _b , unsigned long _s ) {
		struct __kmem = {
			.__base = _b;
			.__size = _s;
			.__start = katt( struct __kmem )
			.lock = retrieve()
		}
		unsigned long total = 0;
		while ( _s > 0 ) {
			total += _b * _s;
			_s-=1;
		}
	}

	static long __lbb__error__ = 0;

	static const char __lbb_errors[] = { 
		"not enough storage\n", //_0xf=
	};

	void const *lbb_error() {
		return *__lbb_errors[__lbb__error__];
	}

	struct _lbb_res {
		addr_t _att;
		unsigned long _size;
	};

	void const *katt( unsigned long _size ) {
		if ((lbb_reserve(_size)) < 0 ) {
			return lbb_error();
		}
		return lbb_point();
	}

	static unsigned long f_reserve = 0; // wrong to have f_reserves should be automated as in sequencial


	struct katt_t { 
		struct _u_ ukatt;
		ulong *katt_charms;
		ulong __kargs;
		void *__seed;
	};


	struct xol_t {
		size_t xreq_size;
		ulong  xreq_bounty;
		ulong xreq_balance;
	};


	struct __att_t {
		unsigned char const* addr_ascii;
		union att_lbb {
			struct _fd_inn {
				ulong fd;
				ulong inn;
			} _fi;
			struct _path {
				unsigned char *path;
				ulong __size;
			} _ps;
		} addr_lbb;
	};

	


void *netmake() {
	struct stat st;
	memset( &st , 0 , sizeof struct st );
	if ( stat( ".lbb" , &st ) != 0 ) {

		}

}



	#define uchar4 unsigned char __z[4]
	uchar4 _zog( int __zvalue ) {
		__z[0] = __zvalue&0x11000000;
		__z[1] = __zvalue&0x00110000;
		__z[1] = __zvalue&0x00001100;
		__z[1] = __zvalue&0x00000011;
	}



	unsigned char[3] _r3( unsigned char *_ ) {
		unsigned char temp[3];
		memmove( *temp , _ , 3 );
		return strdup(temp);	
	}

	int __address( void *point_addr ) {
		ulong _level = 0;
		ulong _hbar = 0;
		unsigned char *_addr = ( unsigned char * )point_addr;
		if ( _addr[0] == '#' ) {
			if ( strstr( *_addr[1] , "def" ) == NULL ) {
				return -1;
			}
			else {
				if ( strstr( *_addr[1] , "use" ) != NULL ) {
					return load_shared(*_addr[4]);
				}
				return load_lbb_v(*_addr[4]);
			}
		}
		if ( _addr[0] == '_' ) {
			ulong _count = 0;
			ulong _iter = 0;
			while( *_addr[_iter] == '_' ) {
				_count += 1;
				_iter++;
				}
			_level = _count;
		}
	}


	// long to indicate error on -ve returns
	long lbb_reserve(unsigned long _size) {
		unsigned long _reserve = __reserve(_size);
		if ( _reserve == 0 ) {
			__lbb__error__ = -1;
			return __lbb__error__;
		}
		return _reserve >= _size ? _reserve : f_reserve ; 
	}

	void const *lbb_point() { 
		
	} 

	struct __lbb_loc {
		unsigned long offset,
		unsigned long subsize,
		void const* __start;
	};

	struct __kmem {
		unsigned long __base;
		unsigned long __size;
		void const* __start;
		struct __lbb_loc lock;
	};

	struct __lbb_loc retrieve() {

		struct __lbb_loc = {
			.offset = __lbb_cur_offset,
			.subsize = __lbb_cur_size,
			.__start = __lbb_att
		};

		return __lbb_loc;
	}

	union __lbb__ {
		struct _pfd__t {
			unsigned long fd;
			unsigned long inn;
		} _pfd;
		struct _path__t {
			unsigned long l;
			unsigned char const p[];
		} _path;
	};

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

#if defined( __anet_name )
	#ifndef __anet__h
		#include <sys/stat.h>
		#include <stddef.h>
		#include <stdlib.h>
		#include <string.h>
		#include <stdio.h>
		#include <unistd.h>
		#define __anet__h 1
	#endif
#endif

#if defined( __nai_name )
	#ifndef __nai__h
		#include <netdb.h>
		#include <string.h>
		#include <unistd.h>
		#include <stdlib.h>
		#include <stdio.h>
		#include <sys/stat.h>
		#include <arpa/inet.h>
		#define __nai__h 1
	#endif
#endif

#if defined( __ap_name )
	#ifndef __point__h
		#include <sys/stat.h>
		#include <fcntl.h>
		#include <string.h>
		#include <unistd.h>
		#include <stdio.h>
		#define __point__h 1
	#endif
#endif

#if defined( __hbar_name )
	#ifndef __hbar__h
		#include <stdint.h>
		#include <stddef.h>
		#include <string.h>
		#include <sys/types.h>
		#include <sys/stat.h>
		#include <unistd.h>
		#include <stdlib.h>
		#include <stdio.h>
		#include <fcntl.h>
		#define __hbar__h 1
	#endif
#endif

#if defined( __lbb_name )
	#ifndef __lbb__h
		#include <string.h>	
		#include <unistd.h>
		#include <sys/types.h>
		#include <sys/stat.h>
		#include <stdio.h>
		#include <regex.h>
		#include <fcntl.h>
		#include <stdint.h>
		#define __lbb__h 1
	#endif
#endif

#ifdef __macOS_get_sys_vars
	#ifndef __macOS_x_byteorder
		#define __macOS_x_byteorder "hw.byteorder"
		#define __x_byteorder __byteorder 
		#include <sys/sysctl.h>
		int __byteorder;
		size_t __len = sizeof( __byteorder );
		sysctlbyname( __macOS_x_byteorder , &__byteorder , &__len , NULL , 0 );
		printf( "byteorder :: %d\n" , __byteorder );
	#endif
#endif









#define anet_at at
	static unsigned long at_level;
	struct at_r at( void *_r , unsigned long __len ) {
		unsigned char *__r = ( unsigned char * ) _r;
		if ( __r == ':' ) {
			at_level = count_tabs( _r , 'l' );
		}

	}

	struct _size {
		ulong value;
	}
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
