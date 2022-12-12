///probe\\\

static unsigned long level = 1;
static char ___next () {\
	level+=1;\
};

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
		#define saddr_max 0x10
				// socket address max is ipv6 which is 16 bytes
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
	
	#ifndef __hat__
		#include "kurl/hat.h"
	#endif
#endif

#ifndef __yx__h
	#define __yx__h 1
	#include "yx/yx.h"
#endif

#ifndef __hbar__h
	#define __hbar__h 1
	#include <stdint.h>
	#include <stddef.h>
	#include <string.h>
	#include <sys/types.h>
	#include <sys/stat.h>
	#include <unistd.h>
	#include <stdlib.h>
	#include <stdio.h>
	#include <fcntl.h>
#endif

#ifndef __lbb__h
	#define __lbb__h 1
	#include <string.h>	
	#include <unistd.h>
	#include <sys/types.h>
	#include <sys/stat.h>
	#include <stdio.h>
	#include <regex.h>
	#include <fcntl.h>
	#include <stdint.h>
#endif

