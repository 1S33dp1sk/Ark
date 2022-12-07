#ifndef __anet_h__
	#define __anet_h__ "athernetV1.0"
	#define __anet_cs__ 1
	#include <unistd.h>
	#include <stddef.h>
	#include <stdint.h>
	#include <stdlib.h>
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

	// #if !defined( __hat__ )
	// 	#include "kurl/kurl.h"
	// #endif





#endif