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
// #include "point.h"


// VERBOSE LOGGING
#define DEBUG
// #define HASH_DEBUG

// MAX LIMITS
#define MAX_STR 256
#define MAX_PATH 4096

// MIN LIMITS
#define MIN_PN 3 // min chars for a pointname

// STRING DEFS
#define emp ""
#define OXATHER "0xather"
#define __ATDIR_DEF "@source"
#define __LBBF_DEF ".lbb"
#define clear_chars "\n\n\n\n\n\n\n\n\n\n\n\n"
#define INTRO__A "\n\t\tWelcome to ather ( a.k.a @-Protocol )\n"
#define ENTER__NN "enter( » )pointname :: @"
#define INVALID_PN "invalid pointname\n"
#define SYMB__NN '@'


void sha3_init256( void *priv );
void sha3_init384( void *priv );
void sha3_init512( void *priv );

int __sys_entry( char *__ );
int __path_entry( char *__ );
int __socket_entry( char *__ , int __v );
int __ather_entry( char *__ , char *_ );
int __fd_entry( char *__ );
int __at_dir( char *__ );


static char __udef_pointname[MAX_STR];
static unsigned int __udef_pointname_len; 



void __clear() {

    write( 0 , clear_chars , 12 );
}


int __intro() {
    #include <string.h>
    int __ = 0;
    char __nn[MAX_STR] = {0};
    __nn[0] = SYMB__NN;
    write( 0 , INTRO__A , strlen( INTRO__A ) );
    __clear();
    write( 0 , ENTER__NN , strlen( ENTER__NN ) );
    __ = read( 0 , &__nn , MAX_STR - 1 );
    if ( __ > 0 ) {
        strcpy( __udef_pointname , __nn );
        if ( ( __udef_pointname_len = strlen( __udef_pointname ) > MIN_PN ) && __nn[0] != '\n' ){
            return __udef_pointname_len;
        }
        else {
            write( 0 , INVALID_PN , strlen( INVALID_PN ) );
            return 0;
        }
    }  
}

#if defined( yes )
    #undef yes
#ifndef yes
    #define yes 1
#endif

#ifndef iszero
int iszero( int v ) {

    return v == 0;
}
#endif

#ifndef isnull
int isnull( char *v ) {

    return v == NULL;
}
#endif


#ifndef __path_unix
char *__path_unix( char *__path , char *__filename ) {
    int path_len = strlen( __path ) - 1 , fname_len = strlen( __filename ) - 1;
    if ( __path[path_len] != '/' && __filename[0] != '/' ) {
        strncat( __path , "/\0" , 2 );
    }
    return ( path_len + fname_len ) < 4096 ? strcat( __path , __filename ) : __path;
}
#endif

#ifndef __file_extention
char *__file_extention( char *ename , char *extention ) {
    int _ = strlen( ename ) , __ = strlen( extention );
    return _ > 0 && __ > 0 ? strncat( strdup( ename ) , extention , __ ) : emp;
}
#endif


/*************************************************************/
typedef struct {
    char ap_name[MAX_STR];
    char ap_path[MAX_PATH];
    unsigned int __lbb;
#define ap_historic ap_lbb
    unsigned int __r;
#define ap_read __r
    unsigned int __w;
#define ap_write __w
} atherpoint;


typedef enum {
    __LBB_VALUE , 
    __LBB_REFERENCE , 
    __LBB_EXECUTE
} lbb_lvl;




int _ather_dir( atherpoint *ap ) {
    // get the current dir
    if ( __at_dir( ap -> ap_path ) ) {
        char *atdir = strdup( ap -> ap_path );
        __path_unix( atdir , __ATDIR_DEF );
        if ( __path_entry( atdir ) ) {
            // atdir avaliable
            return 1;
        }
        // no /@/dir 
        return 0;
    }
    // cannot getcwd
    return 0;
}
#define check_ap_dir _ather_dir


void ather_check( atherpoint *ap ) {
    if ( _ather_dir( ap ) ) { 
    }
}




char *__lvl_delim( lbb_lvl __lvl ) {
    switch ( __lvl ) {
        case __LBB_VALUE:
            return " : ";
        case __LBB_REFERENCE:
            return " = ";
        case __LBB_EXECUTE:
            return " := ";
        default:
            return " -> ";
    }
}


char *lbb_gress( char *key , char *val , lbb_lvl lvl ) {
    char *klv = strdup( val );
    char *lvl_delim = __lvl_delim( lvl );
    strcat( klv , lvl_delim );
    strcat( klv , key );
    printf( "%s\n" , klv );
    return klv;
}




#ifndef __lbb_dir
int __lbb_dir() {
    char __wd[MAX_PATH];
    memset( &__wd , 0 , sizeof( __wd ) );
    if ( !isnull( getcwd( *(&__wd) , sizeof( __wd ) ) ) ) {
        __path_unix( __wd , ".lbb/" );
    }
}
#endif


#ifndef __at_dir
int __at_dir( char *__ap_path ) {
    #if !defined( getcwd )
        #include <unistd.h>
        char __wd[MAX_PATH];
        memset( &__wd , 0 , sizeof( __wd ) );
        if ( !isnull( getcwd( *(&__wd) , sizeof( __wd ) ) ) ) {
            #if defined(DEBUG)
            printf("@check [\u2713]\n");
            #endif
            strcpy( __ap_path , __wd );
            return 1;
        }
        #if defined( DEBUG )
            printf( "@check [\u2715]\n" );
        #endif
        return 0;
    #endif
}
#endif

#ifndef __ather_entry
int __ather_entry( char *__filename , char *__filedata ) {
    char __wd[MAX_PATH];
    int __fd = 0 , __flags = ( O_CREAT | O_RDWR ) , __mode = ( S_IRWXU | S_IRWXG | S_IRWXO );
    memset( &__wd , 0 , sizeof( __wd ) );
    #ifndef getcwd
        #include <unistd.h>
    #endif
    if ( getcwd( *(&__wd) , sizeof( __wd ) ) != NULL ) {
        strcat( __wd , __filename );
        if ( !strcmp( __filedata , emp ) && __path_entry( __wd ) ) {
            __flags = O_RDONLY;
            __fd = open( __wd , __flags );
        }
        else {
            __fd = open( __wd , __flags , __mode );
            if ( write( __fd , __filedata , strlen( __filedata ) ) <= 0 ) {
                return 0;
            }
        }
    }
    return __fd > 0 ? __fd : 0; 
}
#endif

#ifndef __sys_entry
static struct stat fifo_stat;
int __sys_entry( char *__filename ) {
    #ifdef DEBUG
    printf( "@(sys entry)\n" );
    printf( "\tentry :: %s\n" , __filename );
    #endif
    #ifndef stat
        #include <sys/stat.h>
    if ( stat( __filename , &fifo_stat ) == 0 ) {
        return  __path_entry( __filename );
    }
    return 0;
    #endif
}
#endif

#ifndef __path_entry
int __path_entry( char *__pathname ) {
    int __flags = ( R_OK | W_OK | X_OK );
    #ifdef DEBUG
    printf( "@path entry\n" );
    #endif
    #ifndef access // included in <unistd.h>
    if ( access( __pathname , __flags ) == 0 ) {
        #ifdef DEBUG
            printf( "{ entry :: %s }\n" , __pathname );
        #endif
        return 1;
    }
    #ifdef DEBUG
        printf("{ access is revoked }\n");
    #endif
    return 0;
    #endif
}
#endif

#ifndef __fd_entry
int __fd_entry( char *__pathname ) {
    int __fd = 0 , __flags = ( R_OK | W_OK | X_OK );
    #ifdef DEBUG
    printf( "@point name\n" );
    printf( " path :: %s\n" , __pathname );
    #endif
    #ifndef access // included in <unistd.h>
    if ( access( __pathname , __flags ) == 0 ) {
        __flags = O_RDONLY;
        __fd = open( __pathname , __flags );
    }
    #ifdef DEBUG
    if ( __fd ) {
        printf( "{ point :: %d }\n" , __fd );
    }
    else {
        printf( "{ access is revoked }\n" , __fd );
    }
    #endif
    return __fd > 0 ? __fd : 0; 
    #endif
}
#endif


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
#endif





























