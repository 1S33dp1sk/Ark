#ifndef probe
    #define probe 
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

// VERBOSE LOGGING
#define DEBUG

// MAX LIMITS
#define MAX_STR 256
#define MAX_PATH 4096

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


#endif





























