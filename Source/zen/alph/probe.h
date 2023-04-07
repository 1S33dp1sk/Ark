/// probe \\\

#ifndef __probe__h
	// this should provide all the
	// `HAVE_**` as 1 if they can be accessed/exsits 
	// && the `CCC_HEADERS` as 1
	#include "../charm.h"
	#define __probe__h "alph_0x96"
	#define __probe_h "ATHERNET_mrkj"
	#define __probe_version 0x0001
	#define __probe_cs__ 0x0700
	#define __hn_max sysconf(_SC_HOST_NAME_MAX)
	#define HOSTNAME_MAX __hn_max == -1 ? 1 : __hn_max
	#define __ln_max sysconf(_SC_LOGIN_NAME_MAX)
	#define LOGNAME_MAX __ln_max == -1 ? 1 : __ln_max
	#define __fd_max sysconf(_SC_OPEN_MAX)
	#define FDOPEN_MAX __fd_max == -1 ? 0 : __fd_max 
	#ifdef __probe_cs__
			// get the total number of elements allocated for by `arr||_` 
		#define arr_size(_) (sizeof(_))/(sizeof((_)[0]))
			// nai_max : __yb_max_y 
		#define __yb_max_y 8
				// supported natives < 1 ... 9 >
		#define bid_max 3
				// blockchain identitfer must be 3 characters
		#define max_path __sa__dsls
				// maximum for os dependent path is 4096 bytes 
		#define mpath_max __sa__npr
				// mount path must be less than 512 bytes
		#define max_str __sa__pi
				// maximum consumable length for a misc string 
		#define baddr_max max_str
				// blockchain address is 256 bytes max
		#define dstr_max max_str
				// {sub,named,toplevel} domain must be less than 128 bytes each
		#define __s_alias "atherpoint"
				// localhost ipv4 loopback interface unix alias
		#define __s_local "127.0.0.1"
				// localhost ipv4 loopback interface address
		#define __s_localv6 "::1"
				// localhost ipv6 shorthand loopback interface  
		#define __s_local2v6 "0:0:0:0:0:0:0:1"
				// localhost ipv6 loopback interface address
		#define __s_global "0.0.0.0"
				// outgoing ipv4 interface address
	#endif
	#ifndef __utypes__
		#ifndef uchar
			#define uchar unsigned char
		#endif
		#ifndef ulong
			#define ulong long
		#endif	
		#ifndef ullong
			#define ullong unsigned long long
		#endif
	#endif
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
#ifdef __ccc_name
	#ifndef __ccc__h
		#ifdef HAVE_UNISTD_H
			#include <unistd.h>
		#endif
		#ifdef HAVE_STRING_H
			#include <string.h>
		#endif
	#endif
#endif

#ifdef __idx_name
	#ifndef __idx__h
		#ifdef HAVE_UNISTD_H
			#include <unistd.h>
		#endif
		#ifdef HAVE_SYS_TYPES_H
			#include <sys/types.h>
		#endif
		#ifdef HAVE_STRING_H
			#include <string.h>
		#endif
		#ifdef DEBUG
			#include <stdio.h>
		#endif
		#ifdef CCC_HEADERS
			#include "../charm.h"
		#endif
	#endif
#endif

#ifdef __anet_name
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

#ifdef __nai_name
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

#ifdef __netpoint_name
	#ifndef __netpoint__h 
		#include <stdio.h>
	    #include <stdlib.h>
	    #include <sys/wait.h>
		#include <sys/select.h>
		#include <sys/types.h>
		#include <sys/socket.h>
	    #include <signal.h>
	    #include <netinet/in.h>
	    #include <errno.h>
		#include <netdb.h>
		#include <arpa/inet.h>
	    #include <string.h>
		#define __netpoint__h 1
	#endif
#endif

#ifdef __ap_name
	#ifndef __point__h
		#include <unistd.h>
		#include <stdio.h>
		#include <string.h>
		#include <fcntl.h>
		#include <sys/stat.h>
		#define __point__h 1
	#endif
#endif

#ifdef __hbar_name
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

#ifdef __lbb_name
	#ifndef __lbb__h
		#include <unistd.h>
		#include <stdint.h>
		#include <stdio.h>
		#include <string.h>	
		#include <regex.h>
		#include <fcntl.h>
		#include <ifaddrs.h>
		#include <sys/types.h>
		#include <sys/stat.h>
		#define __lbb__h 1
	#endif
#endif

#ifdef __enk_name
	#ifndef __enk__h
	    #include <stdio.h>
	    #include <stdarg.h>
	    #include <string.h>
	    #include <ctype.h>
	    #include <stdint.h>
		#define __enk__h 1
	#endif
#endif



#ifdef __enti_name
	#include <stdlib.h>
	#include <stdio.h>
#endif

#ifdef __kurl_name
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

