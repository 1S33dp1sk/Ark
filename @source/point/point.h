<<<<<<< HEAD
<<<<<<< HEAD
#ifndef point
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
    #define point atherpoint
=======
    #define point
>>>>>>> 1635bec (started athernet)


/**
 * atherpoint is an `FIFO`
 * with a singular reader, that is the `lbb`
 * 
 * writers can connect to the atherpoint syncronously 
 * and query real time updates on the values , operations
 * that are used to create/modify these values.
 * 
 * that is done mainly by kurling the lbb between two or more
 * points. 
 * 
 */

#include <sys/stat.h>
#include <sys/types.h>


#define __ap_name "atherpoint"

=======

// #define DEBUG
=======
    #define point atherpoint
>>>>>>> 96d62a9 (created a dynamic shared library resulting in ./shared/* .o files)

#include <sys/stat.h>
#include <sys/types.h>


#define __AP_NAME "atherpoint"
<<<<<<< HEAD
static struct stat __lbb_stat;
>>>>>>> 4947f52 (v0.01-NS)
=======

>>>>>>> 757e790 (shared library for point)

struct apio {
    unsigned __fd;
    pid_t __pid;
};

<<<<<<< HEAD
<<<<<<< HEAD
=======

>>>>>>> 4947f52 (v0.01-NS)
=======
>>>>>>> 757e790 (shared library for point)
typedef struct {
    int __k__;
    unsigned lbb_fd;
    struct stat ap_stat;
    struct apio from;
    struct apio to_point;
} ap;

<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
int atherpoint( char *p_path , unsigned p_level );
=======
static ap __ap;

#define point_descriptors( __ ) \
    ( __.to_point.__fd > 0 ) || ( __.from.__fd > 0 ) ? 1 : 0 

#define point_exists() __file_exsits( __ap_name )
#define make_point( __ ) atherpoint( __ap_name , &__ )



int atherpoint( void *at_point , ap *__ );
>>>>>>> 1635bec (started athernet)
int process_entry( char *_e , int _e_len );
int app_engine( struct apio *engint );
int socket_execute( struct apio *sexec );
int applier( ap *apoint );

=======



=======
int atherpoint( char *p_path , unsigned p_level );
>>>>>>> 757e790 (shared library for point)
int process_entry( char *_e , int _e_len );
int app_engine( struct apio *engint );
int socket_execute( struct apio *sexec );
int applier( ap *apoint );

<<<<<<< HEAD
void log_stat( struct stat st );
int __ap_entry( char *_e_path , int _e_type );
int _ap_r_entry();
int _ap_w_entry();
int __ap_fifo();
int __ap_make();


int process_entry( char *entry , int e_len ) {

    printf( "entry = %d@app_engine :: \n\t%s\n" );

    return e_len > 10 ? 0 : 1;
}

int app_engine( struct apio *engint ) {
    int c = 0, r_bytes;
    char _ , __[4096];
    memset( &__ , 0 , sizeof( __ ) );

    #ifdef DEBUG
        printf( "engint : FIFO FD = %d\n" , engint -> __fd );
        printf( "engint :: reading from fifo\n" );
    #endif

    while ( ( r_bytes = read( engint -> __fd , &__ , 4096 ) ) > 0 ) {
        c += r_bytes;
        _ = __[c-1];
        if ( _ == 10 ) {
            #ifdef DEBUG
                printf( "engint :: processing entry\n" );
            #endif
            if ( !process_entry( __ , c ) ) {
                printf("entery processed\n");
                break;
            }
            memset( &__ , 0 , c * sizeof( char ) );
            c = 0 , r_bytes = 0;
            continue;
        }
        r_bytes = 0;
    }
}

int socket_execute( struct apio *sexec ) {

    int count = 0, r_bytes = 0;
    char _ , __[4096];
    memset( &__ , 0 , sizeof( __ ) );

    #ifdef DEBUG
        printf( "sexec : FIFO fd : %d \n" , sexec -> __fd );
        printf( "sexec :: reading from stdin\n" );
    #endif

    while ( ( r_bytes = read( 0 , &__ , 4096 ) ) > 0 ) {
        count += r_bytes;
        _ = __[count-1];

        printf( "\n\n\n _ = (%c) \n\n\n" , _ );
        #ifdef DEBUG
            printf( "sexec : bytes read = %d : total bytes = %d\n" , r_bytes , count );
        #endif
        if ( _ == 10 ) {
            #ifdef DEBUG
                printf( "sexec :: writing to FIFO : len = %d, buf = %s\n" , count , __ );
            #endif
            if ( write( sexec -> __fd , __ , 4096 ) > 0 ) {
                memset( &__ , 0 , count );
                count = 0 , r_bytes = 0;
                continue;
            }
            break;
        }
        else if ( _ == 27 ) {
            printf( "sexec :: exit\n" );
            return 0;
        }
        r_bytes = 0;
    }
    printf( "sexec :: execution ended\n" );
    return 0;
}

int applier( ap *point ){

    // get the current pid
    ( point -> e_ap ).__pid = getpid();
    // fork the process for the new pid
    if ( ( ( point -> t_ap ).__pid = fork() ) == -1 ) {
        printf( "cannot start the atherpoint :: fork\n" );
        return 2;
    }

    // check calling process
    if ( ( point -> t_ap ).__pid == 0 ) {
        printf( "current pid for reading :: %d\n" , ( point -> e_ap ).__pid );
        // read
        if ( ( ( point -> e_ap ).__fd = _ap_r_entry() ) == 0 ) {
            printf( "cannot open atherpoint for reading\n");
            return 3;
        }
        printf( "\n-#-#-# engine -#-#-#\n" );
        return app_engine( &(point -> e_ap) );
    }
    else {
        printf( "current pid for writing :: %d\n" , ( point -> t_ap ).__pid );
        // write
        if ( ( ( point -> t_ap ).__fd = _ap_w_entry() ) == 0 ) {
            printf( "cannot open atherpoint for writing\n");
            return 3;
        }
        printf( "\n#-#-# socket executive #-#-#\n" );
        return socket_execute( &(point -> t_ap) );
    }

    return 0;
}


/**
 * 
 * _e_path :: delim/os/path
 * 
 * _e_type :
 *  0 -> read
 *  1 -> write
 */
#ifndef __ap_entry
int __ap_entry( char *_e_path , int _e_type ) {
    int __ap = 0 , __flags = ( F_OK | ( _e_type == 0 ? R_OK : _e_type ) );
    char *e_path = strcat( strdup( _e_path ) , ".lbb" );
    if ( access( e_path , __flags ) == 0 ) {
        __flags = ( _e_type == 0 ? O_RDONLY : O_WRONLY );
        __ap = open( e_path , __flags );
    }
    return __ap > 0 ? __ap : 0;
}
#endif

#ifndef _ap_r_entry
int _ap_r_entry() {
    int __apr , __flags = ( R_OK );

    if ( access( __AP_NAME , __flags ) == 0 ) {
        __flags = O_RDONLY;
        __apr = open( __AP_NAME , __flags );
    }

    return __apr > 0 ? __apr : 0;
}
#endif

#ifndef _ap_w_entry
int _ap_w_entry() {
    int __apr , __flags = ( W_OK );

    if ( access( __AP_NAME , __flags ) == 0 ) {
        __flags = O_WRONLY;
        __apr = open( __AP_NAME , __flags );
    }

    return __apr > 0 ? __apr : 0;   
}
#endif

#ifndef __ap_fifo
int __ap_fifo( ap *__ ) {
    if ( ( ( __ -> ap_stat ).st_nlink == 0 ) 
        && 
        stat( __AP_NAME , &( __ -> ap_stat ) ) == 0 ) {
            log_stat( __ -> ap_stat );
        	return 1;
    }
    return 0;
}
#endif

#ifndef __ap_make
int __ap_make() {
    if ( !mkfifo( __AP_NAME , ( S_IRWXU | S_IXGRP | S_IXOTH ) ) ) {
        return 1;
    }
    return 0;
}
#endif


#include <stdint.h>
struct request{
    unsigned num_bytes;
    char *lbb_key;
    char *datin;
    uint8_t hash;
};

typedef struct {
    char __; // ptr
    unsigned __clen; // chars read
    unsigned __flag; /* 0 -> bytes  
                        1 -> key
                        2 -> datin
                        3 -> hash
                     */
    struct request __in;
#define r __in
} engine_r;


int e_read( unsigned _rfd , unsigned _wfd ) {
    engine_r reader;
    memset( &reader , 0 , sizeof( reader ) );
    int __readlen = 0;
    while( ( __readlen = read( _rfd , (&reader.__) , 1 ) ) > 0 ) {
        printf( ">>%c\n" , reader.__ );
        if ( reader.__ == '@' ) {
            printf("reader is @\n");
            reader.__flag = 1;
        }
        switch ( reader.__flag ) {
            case 1:
                return 0;
            default:
                reader.__clen += __readlen;
                write( _wfd , "ok\n" , 2 );
        }
    }
    write( _wfd , "live baby\n" , 10 ); 
    close( _rfd );
    close( _wfd );
    return 0;
}



#ifndef __loop
int __loop( unsigned int rd , unsigned int wd ) {
    char __;
    unsigned int __len = 1;
    while ( read( rd , &__ , 1 ) > 0 && __ != '\n' ) {
        while ( __len != 0 ) {
            __len--;
            write( wd , "live baby\n" , 10 );           
        }
    }
    if ( rd != 0 ) {
    	close( rd );
    }
    if ( wd != 0 ) {
    	close( wd );
    }
    return 0;
}
#endif

typedef enum {
    __ADDR_PATH = 1,
    __ADDR_IPv4,
    __ADDR_IPv6,
    __ADDR_BLOCKCHAIN
} p_type;

int check_ap( char *p_addr , p_type paddr_t ) {
    int __fd = 0;
    switch( paddr_t ) {
        case __ADDR_PATH:
            if ( access( p_addr , F_OK ) == 0 ) {
                printf("OK :: access path @%s\n" , p_addr);
                return 0;
            }
            return 1;
        case __ADDR_IPv4:
            __fd = socket( AF_INET , SOCK_STREAM , 0 );
            if ( __fd > 0 ) {
                printf("OK :: access socket @%s\n" , p_addr );
                close( __fd );
                return 0;
            }
            return 1;

        case __ADDR_IPv6:
            if ( ( __fd = socket( AF_INET6 , SOCK_STREAM , 0 ) ) > 0 ) {
                printf("OK :: access socket (v6) @%s\n" , p_addr );
                close( __fd );
                return 0;
            }
            return 1;
        case __ADDR_BLOCKCHAIN:
            printf("blockchain not yet implemented\n");
            return 1;
        default:
            printf("unkown addr type\n");
            return 1;
    }
}

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
>>>>>>> 4947f52 (v0.01-NS)
=======
>>>>>>> 757e790 (shared library for point)
=======
/// atherpoint \\\
=======
#ifndef point
    #define point
>>>>>>> c1e4320 (athernet V0.9)

// #define DEBUG

/**
 * atherpoint is an `FIFO`
 * with a singular reader, that is the `lbb`
 * 
 * writers can connect to the atherpoint syncronously 
 * and query real time updates on the values , operations
 * that are used to create/modify these values.
 * 
 * that is done mainly by kurling the lbb between two or more
 * points. 
 * 
 */

#include <sys/stat.h>
#include <sys/types.h>


#define __ap_name "atherpoint"

typedef enum __io_types {
    __reader = 1,
    __writers
};

struct pio {
    unsigned io_pfd;
    pid_t io_pid;
    __io_types io_type;
};

struct point_st {
    struct stat ap_stat;
    struct pio p_from;
    struct pio p_to;
};

struct point_si {
    struct point_st st;
    int level;
    void *lai;
};


#define point_descriptors( __ ) \
    ( __.to_point.__fd > 0 ) || ( __.from.__fd > 0 ) ? 1 : 0 

#define point_exists() __file_exsits( __ap_name )
#define make_point( __ ) atherpoint( __ap_name , &__ )



int atherpoint( void *at_point , apoint* ap );
int process_entry( char *_e , int _e_len );
int app_engine( struct apio *engint );
int socket_execute( struct apio *sexec );
int applier( apoint* ap );

>>>>>>> a415938 (kurls)


#endif


