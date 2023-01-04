<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
#ifndef probe
    #define probe 
=======
>>>>>>> 4947f52 (v0.01-NS)
=======
#ifndef probe
<<<<<<< HEAD
    #define probe
>>>>>>> 757e790 (shared library for point)
=======
    #define probe 
>>>>>>> 96d62a9 (created a dynamic shared library resulting in ./shared/* .o files)
/***
 * async-safe defined in POSIX 
 * _Exit(), 
 * _exit(), 
 * abort(), 
 * accept(), 
 * access(), 
 * aio_error(), 
 * aio_return(), 
 * aio_suspend(), 
 * alarm(), 
 * bind(), 
 * cfgetispeed(), 
 * cfgetospeed(), 
 * cfsetispeed(), 
 * cfsetospeed(), 
 * chdir(), 
 * chmod(), 
 * chown(), 
 * clock_gettime(), 
 * close(), 
 * connect(), 
 * creat(), 
 * dup(), 
 * dup2(), 
 * execle(), 
 * execve(), 
 * fchmod(), 
 * fchown(), 
 * fcntl(), 
 * fdatasync(), 
 * fork(), 
 * fpathconf(), 
 * fstat(),
 * fsync(), 
 * ftruncate(), 
 * getegid(), 
 * geteuid(), 
 * getgid(), 
 * getgroups(), 
 * getpeername(), 
 * getpgrp(), 
 * getpid(), 
 * getppid(), 
 * getsockname(), 
 * getsockopt(), 
 * getuid(), 
 * kill(), 
 * link(), 
 * listen(), 
 * lseek(), 
 * lstat(), 
 * mkdir(), 
 * mkfifo(),
 * open(), 
 * pathconf(), 
 * pause(), 
 * pipe(), 
 * poll(), 
 * posix_trace_event(), 
 * pselect(), 
 * raise(), 
 * read(), 
 * readlink(), 
 * recv(), 
 * recvfrom(), 
 * recvmsg(), 
 * rename(), 
 * rmdir(), 
 * select(), 
 * sem_post(), 
 * send(), 
 * sendmsg(), 
 * sendto(), 
 * setgid(), 
 * setpgid(), 
 * setsid(), 
 * setsockopt(), 
 * setuid(), 
 * shutdown(), 
 * sigaction(), 
 * sigaddset(), 
 * sigdelset(), 
 * sigemptyset(), 
 * sigfillset(), 
 * sigismember(), 
 * sleep(), 
 * signal(), 
 * sigpause(), 
 * sigpending(), 
 * sigprocmask(), 
 * sigqueue(), 
 * sigset(), 
 * sigsuspend(), 
 * sockatmark(), 
 * socket(), 
 * socketpair(), 
 * stat(), 
 * symlink(), 
 * sysconf(), 
 * tcdrain(), 
 * tcflow(), 
 * tcflush(), 
 * tcgetattr(), 
 * tcgetpgrp(), 
 * tcsendbreak(), 
 * tcsetattr(), 
 * tcsetpgrp(), 
 * time(), 
 * timer_getoverrun(), 
 * timer_gettime(), 
 * timer_settime(), 
 * times(), 
 * umask(), 
 * uname(), 
 * unlink(), 
 * utime(), 
 * wait(), 
 * waitpid(), 
 * write()
 ***/

#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
<<<<<<< HEAD
<<<<<<< HEAD

// VERBOSE LOGGING
#define DEBUG
=======
// #include "point.h"

=======
>>>>>>> 96d62a9 (created a dynamic shared library resulting in ./shared/* .o files)

// VERBOSE LOGGING
#define DEBUG
<<<<<<< HEAD
// #define HASH_DEBUG
>>>>>>> 4947f52 (v0.01-NS)
=======
>>>>>>> 757e790 (shared library for point)

// MAX LIMITS
#define MAX_STR 256
#define MAX_PATH 4096

<<<<<<< HEAD
<<<<<<< HEAD
// STRING DEFS
#define OXATHER "0xather"
#define __F_LBB ".lbb"
#define SYMB__NN '@'

void log_stat( struct stat st );

/*************************************************************/


#ifndef _NO_DEFS
    #define _NO_DEFS
    #define emp ""
    int isempty( char *v ) {
        return strcmp( emp , v );
    }
    int iszero( int v ) {
        return v == 0;
    }
    int isnull( char *v ) {
        return v == NULL;
    }
#endif

#ifndef _UNI_PATHS
    #define _UNI_PATHS
    char *__path_unix( char *__path , char *__filename ) {
        int path_len = strlen( __path ) - 1 , fname_len = strlen( __filename ) - 1;
        if ( __path[path_len] != '/' && __filename[0] != '/' ) {
            strncat( __path , "/\0" , 2 );
        }
        return ( path_len + fname_len ) < 4096 ? strcat( __path , __filename ) : __path;
    }

    char *__file_extention( char *ename , char *extention ) {
        int _ = strlen( ename ) , __ = strlen( extention );
        return _ > 0 && __ > 0 ? strncat( strdup( ename ) , extention , __ ) : emp;
    }
#endif

#ifndef _LBB_DELIMS
    #define _LBB_DELIMS
    #define _VAL_DELIM " : "
    #define _REF_DELIM " = "
    #define _ADDR_DELIM " := "
    #define _NDEF_DELIM " =: " 

    const char *__lvl_delim( unsigned __lvl ) {
        switch ( __lvl ) {
            case 0:
                return _VAL_DELIM;
            case 1:
                return _REF_DELIM;
            case 2:
                return _ADDR_DELIM;
            default:
                return _NDEF_DELIM;
        }
    }
#endif

#include <stdint.h>
#include <time.h>

void log_stat( struct stat sb ) {

    #if defined( minor ) && defined( major )
        printf("ID of containing device:  [%jx,%jx]\n",
        (uintmax_t) major(sb.st_dev),
        (uintmax_t) minor(sb.st_dev));
    #endif

    printf("File type:                ");

    switch (sb.st_mode & S_IFMT) {
        case S_IFBLK:  printf("block device\n");            break;
        case S_IFCHR:  printf("character device\n");        break;
        case S_IFDIR:  printf("directory\n");               break;
        case S_IFIFO:  printf("FIFO/pipe\n");               break;
        case S_IFLNK:  printf("symlink\n");                 break;
        case S_IFREG:  printf("regular file\n");            break;
        case S_IFSOCK: printf("socket\n");                  break;
        default:       printf("unknown?\n");                break;
    }

    printf("I-node number:            %ju\n", (uintmax_t) sb.st_ino);
    printf("I-node number:            %ju\n", (uintmax_t) sb.st_ino);

    printf("Mode:                     %jo (octal)\n",
           (uintmax_t) sb.st_mode);

    printf("Link count:               %ju\n", (uintmax_t) sb.st_nlink);
    printf("Ownership:                UID=%ju   GID=%ju\n",
           (uintmax_t) sb.st_uid, (uintmax_t) sb.st_gid);

    printf("Preferred I/O block size: %jd bytes\n",
           (intmax_t) sb.st_blksize);
    printf("File size:                %jd bytes\n",
           (intmax_t) sb.st_size);
    printf("Blocks allocated:         %jd\n",
           (intmax_t) sb.st_blocks);

    printf("Last status change:       %s", ctime(&sb.st_ctime));
    printf("Last file access:         %s", ctime(&sb.st_atime));
    printf("Last file modification:   %s", ctime(&sb.st_mtime));
}


=======
// MIN LIMITS
#define MIN_PN 3 // min chars for a pointname

=======
>>>>>>> 757e790 (shared library for point)
// STRING DEFS
#define OXATHER "0xather"
#define __F_LBB ".lbb"
#define SYMB__NN '@'

void log_stat( struct stat st );

/*************************************************************/


#ifndef _NO_DEFS
    #define _NO_DEFS
    #define emp ""
    int isempty( char *v ) {
        return strcmp( emp , v );
    }
    int iszero( int v ) {
        return v == 0;
    }
    int isnull( char *v ) {
        return v == NULL;
    }
#endif

#ifndef _UNI_PATHS
    #define _UNI_PATHS
    char *__path_unix( char *__path , char *__filename ) {
        int path_len = strlen( __path ) - 1 , fname_len = strlen( __filename ) - 1;
        if ( __path[path_len] != '/' && __filename[0] != '/' ) {
            strncat( __path , "/\0" , 2 );
        }
        return ( path_len + fname_len ) < 4096 ? strcat( __path , __filename ) : __path;
    }

    char *__file_extention( char *ename , char *extention ) {
        int _ = strlen( ename ) , __ = strlen( extention );
        return _ > 0 && __ > 0 ? strncat( strdup( ename ) , extention , __ ) : emp;
    }
#endif

#ifndef _LBB_DELIMS
    #define _LBB_DELIMS
    #define _VAL_DELIM " : "
    #define _REF_DELIM " = "
    #define _ADDR_DELIM " := "
    #define _NDEF_DELIM " =: " 

    const char *__lvl_delim( unsigned __lvl ) {
        switch ( __lvl ) {
            case 0:
                return _VAL_DELIM;
            case 1:
                return _REF_DELIM;
            case 2:
                return _ADDR_DELIM;
            default:
                return _NDEF_DELIM;
        }
    }
#endif

#include <stdint.h>
#include <time.h>

void log_stat( struct stat sb ) {

    #if defined( minor ) && defined( major )
        printf("ID of containing device:  [%jx,%jx]\n",
        (uintmax_t) major(sb.st_dev),
        (uintmax_t) minor(sb.st_dev));
    #endif

    printf("File type:                ");

    switch (sb.st_mode & S_IFMT) {
        case S_IFBLK:  printf("block device\n");            break;
        case S_IFCHR:  printf("character device\n");        break;
        case S_IFDIR:  printf("directory\n");               break;
        case S_IFIFO:  printf("FIFO/pipe\n");               break;
        case S_IFLNK:  printf("symlink\n");                 break;
        case S_IFREG:  printf("regular file\n");            break;
        case S_IFSOCK: printf("socket\n");                  break;
        default:       printf("unknown?\n");                break;
    }

    printf("I-node number:            %ju\n", (uintmax_t) sb.st_ino);
    printf("I-node number:            %ju\n", (uintmax_t) sb.st_ino);

    printf("Mode:                     %jo (octal)\n",
           (uintmax_t) sb.st_mode);

    printf("Link count:               %ju\n", (uintmax_t) sb.st_nlink);
    printf("Ownership:                UID=%ju   GID=%ju\n",
           (uintmax_t) sb.st_uid, (uintmax_t) sb.st_gid);

    printf("Preferred I/O block size: %jd bytes\n",
           (intmax_t) sb.st_blksize);
    printf("File size:                %jd bytes\n",
           (intmax_t) sb.st_size);
    printf("Blocks allocated:         %jd\n",
           (intmax_t) sb.st_blocks);

    printf("Last status change:       %s", ctime(&sb.st_ctime));
    printf("Last file access:         %s", ctime(&sb.st_atime));
    printf("Last file modification:   %s", ctime(&sb.st_mtime));
}


<<<<<<< HEAD
#ifndef __socket_entry
    #ifndef PORT_ACCEPT
        #define PORT_ACCEPT "9999"
    #endif
    #ifndef getaddrinfo
        #include <netdb.h>
    #endif
int __socket_entry( char *__ipaddr , int ipv  ) {
    int __listener , __rv , __g2g__ = 1;
    struct addrinfo as_hints , *as_info , *temp;
    memset( &as_hints , 0 , sizeof( as_hints ) );
    if ( ( __rv = getaddrinfo( __ipaddr , PORT_ACCEPT , &as_hints , &as_info ) ) != 0 ) {
        return 0;
    }
    for ( temp = as_info ; temp != NULL ; temp = temp -> ai_next ) {
        __listener = socket( temp -> ai_family , temp -> ai_socktype , temp -> ai_protocol );
        if ( __listener < 0 )
            continue;
        setsockopt( __listener , SOL_SOCKET , SO_REUSEADDR , &__g2g__ , sizeof( int ) );
        if ( bind( __listener , temp -> ai_addr , temp -> ai_addrlen ) < 0 )
            continue;
        break;
    }
    freeaddrinfo( as_info );
    return temp == NULL ? 0 : __listener;
}
>>>>>>> 4947f52 (v0.01-NS)
=======
>>>>>>> 757e790 (shared library for point)
=======
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

<<<<<<< HEAD
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
>>>>>>> a415938 (kurls)
#endif





























<<<<<<< HEAD
=======


























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
>>>>>>> a415938 (kurls)
=======
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

>>>>>>> cf46ec7 (athernet v0)