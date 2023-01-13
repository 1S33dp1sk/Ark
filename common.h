/*
    -----------------------------------------------------------------------------------------------------
    |Ather  ::                                                                                          |
<<<<<<< HEAD
    |                                              @                                                    |
    |                                                                                                   |
    | the `at` is common character defined in UTF-8 under the sequence position of 64.                  |
    | it is utilized by ather as the main indicator that there's ather or not.                          |
=======
    |                                                                                                   |
    |                                              @                                                    |
    |                                                                                                   |
    |                                                                                                   |
    | the `at` is common character defined in UTF-8 under the sequence of 64. it is utilized by ather   |
    | as the main indicator that there's ather or not.                                                  |
>>>>>>> 52885d5 (c.*ather*)
    |                                                                                                   |
    -----------------------------------------------------------------------------------------------------
*/
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <pwd.h>
#include <netdb.h>
#include <string.h>
#include <fcntl.h>
#include <dirent.h>
#include <ctype.h>
#include <ifaddrs.h>
#include <stdarg.h>

<<<<<<< HEAD
#define X_NODEF &"\0"
=======

>>>>>>> 52885d5 (c.*ather*)
#define PORT_ACCEPT "9999"
#define AtherDot ".ather"
#define AtherHelpers "@helpers"
#define AtherPath "@path"
#define __DELIMS = ":="
#define ENTRY__START "{"
#define ENTRY__END "}"
#define PATH_LENGTH 201
#define MAX_LEN 4096
#define MAX_FILE 10000
#define MAX_PROTO 1024
#define HASH_SIZE 8
#define MAX_NAME 100
#define MAX_PATH 4096
#define MAX_STR 256

typedef struct {    
    char _name[MAX_NAME-1];
    char af_path[MAX_PATH-1];
    char *prefered_coms;
    union {
        char *__ip; // support both ipv4 && ipv6
        char *__str; // whatever the name is
        struct sockaddr_storage *__soc;
    } a_type;
#define a_ip a_type.__ip
#define a_str a_type.__str
#define a_socket a_type.__soc;
    char *cur_coms;
    unsigned char con_status; // e(xists) n(o_def)
    unsigned char *__defcall;
} a_info;

typedef struct {
    uint32_t __hash;
    int __size;
    char __name[MAX_LEN];
    char __registery[HASH_SIZE];
    char __contents[MAX_FILE];
} FileData;

/**
 * in order to be able to get the full 
 * nav system and build paths correctly 
 * we will utilize the `PATH` structure.
*/
typedef struct {
    char __node[MAX_STR]; // connc reference
    char __name[MAX_STR]; // entry
    char __main[MAX_LEN]; // private current path (unix)
    char __home[MAX_LEN]; // public current path (mor)
    char __wd[MAX_STR]; // the name of the current dir
    char __pub[MAX_LEN]; // the full path for the public `@`
} Path;

typedef struct {
    int __depth;
    int __res;
    char *__exec;
    char __ctx[150];
} Entry;

typedef struct {
    char __path[MAX_STR];
    char __call[MAX_LEN];
    char __connc[MAX_STR];
    char __entry[MAX_FILE];
} Elems;

typedef struct {
    FileData **filedata;
    char **__dirs;
    int num__files;
    int num__dirs;
    int __total;
    uint32_t _hashd; // _hash(disposable) || reusable || masterhash || etx...
} Connc;


typedef struct {
    unsigned char _diff; // 1 byte
    unsigned int _len , _size , _select; // 2bytes each
    unsigned char *_name , *_bin , *_type; // string
    unsigned long long int _selector; // 8 bytes
} Protocol;

typedef struct {
    char *__path;
    Path *_path;
    FileData *_wrap;
    char *__call;
    // Call *_call;
    char *__connc;
    Connc *_connc;
    char *__entry;
    Entry *_entry;
    // Type _type;
    // Vecf *_vecf;
    char *__name__;
    char **__args__;
    uint32_t __ref__;
} Ather;


// 
// linux - #man getaddrinfo
// GNU LICENSE
// getaddrinfo( node , serv , hints , res )
// struct addrinfo {
//    int              ai_flags;
//    int              ai_family;
//    int              ai_socktype;
//    int              ai_protocol;
//    socklen_t        ai_addrlen;
//    struct sockaddr *ai_addr;
//    char            *ai_canonname;
//    struct addrinfo *ai_next;
// };
// is used here.

typedef enum {
    A_MOR, 
    A_ANY = AF_UNSPEC,
    A_INET6 = AF_INET6,
    A_INET = AF_INET,
    A_LES
} nameproto;

typedef struct {
    nameproto name__;
    char at__[INET6_ADDRSTRLEN];
    char *node__;
    char *serv__;
    struct addrinfo *hints__;
    struct addrinfo *res__;
} typeproto;


int __dirdata( char *__dirname );
int __fdata( char *__filepath );
int _file_contents( FileData *filedata );
char *_dir_hash( char *__dirname );
char *_path_hash( Path *path );
int _file_hash( FileData *filedata );
void _log_file_data( FileData *filedata );
int file__process( FileData *filedata );


#include "log.h"


<<<<<<< HEAD
=======

>>>>>>> 52885d5 (c.*ather*)
// typedef enum {
//     A__DIR,
//     A__DIR_FILE,
//     A__FILE,
// } Found;

// typedef enum {
//     LES_PUB,
//     LES_PVT,
//     MOR_PUB,
//     NO_SPEC
// } Type;

// typedef enum {
//     CMD__PATH = 0x97e82973,
//     CMD__CALL = 0x47622221,
//     CMD__CONNC = 0xa7155072,
//     CMD__ENTRY = 0xd3e74f0f,
//     CMD__LES = 0x350647ed,
//     CMD__MOR = 0x9eefc5c9,
//     CMD__ADDR = 0x7ce4b62e,
//     CMD__CONF = 0x5cdac004
// } Commands;

// // typedef enum {
// //     PATH = 0x14e02e2c,
// //     CALL = 0xb6f92096,
// //     CONNC = 0x6e5dc94a,
// //     ENTRY = 0x11216bb,
// //     ADDR,
// //     CONF
// // } Elements;


// typedef struct {
//     char __display[MAX_FILE];
//     int __at;
//     uint32_t __v;
// } Call;

// typedef struct {
//     int found__; // path
//     int c__; // called or connected
//     int executed__; // entry
//     int verified__; // @
//     int flagged; // EXIT
// } Vecf; // #


// typedef struct {
//  int len , size , select;
//  char *name , *bin , diff , *type;
//  long long int selector;
// } _Protocol;



// typedef struct {
//     int len_entries;
    
// } dot_a;

// typedef enum {
//     NODE_NODEF,
//     NODE_BUSY,
//     NODE_ABLE,
//     NODE_ATHER
// } n_status;


// typedef struct {
//     uint32_t hash_name;
//     uint32_t hash_contents;
// } a_call;

// typedef struct {
//     union {
//         char *__name;
//         char *__ipstr;
//     } resolved_name;
// #define apr_name resolved_name.__name
// #define apr_ipstr resolved_name.__ipstr;
// } a_path;

// typedef struct {

// } a_entry;

// typedef struct {

// } a_connc;



// typedef struct {
//     a_call def__;
//     a_path node__; 
//     a_entry sexec__;
//     a_connc protos__;
// } __a;



// binary interface 
// invoke , ABI , pack , etx..
// adaptive based on the system 
#define i16( __ , _ ) __I( __ , _ , 0 ) // 16-bit comms
#define i32( __ , _ ) __I( __ , _ , 2 ) // 32-bit comms
#define i64( __ , _ ) __I( __ , _ , 6 ) // 64-bit comms
// binary mirror
// reply , ABM , unpack , etx..
#define r16( __ , _ ) __R( __ , _ , 0 ) // 16-bit comms
#define r32( __ , _ ) __R( __ , _ , 2 ) // 32-bit comms
#define r64( __ , _ ) __R( __ , _ , 6 ) // 64-bit comms


void display_a_info( a_info *__ ) {
    printf( "Ather :: info : \n" );
    printf( "\tnodename :: %s\n" , __ -> _name );
    printf( "\tpref. coms :: %s\n", __ -> prefered_coms );
    printf( "\taf_path : %s\n", __ -> af_path );

    printf( "\ta_ip : %s\n", __ -> a_ip );
    printf( "\ta_str : %s\n" , __ -> a_str );
}
<<<<<<< HEAD
int __I( unsigned char *__ , unsigned long long int _ , unsigned int b ) {
    while ( b > 0 ) {
        *__++ = _>>(b+1)*8;
        b--;
    }
    *__++ = _>>8; *__++ = _;
    return 0;
}
    // `_` flag for signed/unsigned. `_` = 0 == unsigned
    unsigned long long int __R( unsigned char *__ , unsigned int _ , unsigned int b ) {
        unsigned int b__ = b;
        if ( !b ) {
            #if defined( xType )
                #undef xType
            #endif
            #define xType unsigned int
            #if defined( cType )
                #undef cType
            #endif
            #define cType ( unsigned int )
            #if defined( mVal )
                #undef mVal
            #endif
            #define mVal 0x7fffu
            #if defined( fVal )
                #undef fVal
            #endif
            #define fVal 0xffffu
            #if defined( sType )
                #undef sType
            #endif
            #define sType int
            #if defined( sCType )
                #undef sCType
            #endif
            #define sCType ( int )
            #if defined( DEBUG )
                printf( "16-bit :: %04lx :: %04lx\n" , mVal , fVal );
            #endif
        }
        else if ( b == 2 ) {
            #if defined( xType )
                #undef xType
            #endif
            #define xType unsigned long int 
            #if defined( cType )
                #undef cType
            #endif
            #define cType ( unsigned long int  )
            #if defined( mVal )
                #undef mVal
            #endif
            #define mVal 0x7fffffffu
            #if defined( fVal )
                #undef fVal
            #endif
            #define fVal 0xffffffffu
            #if defined( sType )
                #undef sType
            #endif
            #define sType long int 
            #if defined( sCType )
                #undef sCType
            #endif
            #define sCType ( long int  )
            #if defined( DEBUG )
               printf( "32-bit :: %08lx :: %08lx\n" , mVal , fVal );
            #endif
        }
        else if ( b == 6 ) {
            #if defined( xType )
                #undef xType
            #endif
            #define xType unsigned long long int 
            #if defined( cType )
                #undef cType
            #endif
            #define cType ( unsigned long long int  )
            #if defined( mVal )
                #undef mVal
            #endif
            #define mVal 0x7fffffffffffffffu
            #if defined( fVal )
                #undef fVal
            #endif
            #define fVal 0xffffffffffffffffu
            #if defined( sType )
                #undef sType
            #endif
            #define sType long long int 
            #if defined( sCType )
                #undef sCType
            #endif
            #define sCType ( long long int  )
            #if defined( DEBUG )
                printf( "64-bit :: %016lx :: %016lx \n" , mVal , fVal );
            #endif
        }

        xType temp = ( xType ) __[0]<<( b + 1 )* 8 , last = ( xType ) __[( b + 1 )];
        if ( b == 0 ) {
            return temp | last;
        }
        while ( b > 0 ) {
            b--;
            temp |= ( ( xType )__[ b__ - b ] <<( b + 1 )* 8 );
        }
        temp |= last;
        if ( !_ ) {
            return temp; 
        }

        sType final;
        if ( temp <= mVal ) {
            final = temp;
        } 
        else {
            final = - 1 - sCType ( fVal - temp );;
        }
        return final;
    }
=======

>>>>>>> 52885d5 (c.*ather*)
#undef get16bits
#if ( defined( __GNUC__ ) && defined( __i386__ )) || defined( __WATCOMC__ ) \
  || defined( _MSC_VER ) || defined ( __BORLANDC__ ) || defined ( __TURBOC__ )
    #define get16bits( d ) ( * ( ( const uint16_t * ) ( d ) ) )
#endif

#if !defined ( get16bits )
    #define get16bits( d ) ( ( ( ( uint32_t ) ( ( ( const uint8_t * )( d ) )[1] ) ) << 8 )\
                       +( uint32_t ) ( ( ( const uint8_t * ) ( d ) )[0] ) )
#endif
uint32_t super_fast_hash (char *data , int len) {
    uint32_t hash = len, tmp;
    int rem;
    if (len <= 0 || data == NULL) { return 0; }
    rem = len & 3;
    len >>= 2;

    /* Main loop */
    for (;len > 0; len--) {
        hash  += get16bits (data);
        tmp    = (get16bits (data+2) << 11) ^ hash;
        hash   = (hash << 16) ^ tmp;
        data  += 2*sizeof (uint16_t);
        hash  += hash >> 11;
    }

    /* Handle end cases */
    switch (rem) {
        case 3: hash += get16bits (data);
                hash ^= hash << 16;
                hash ^= ((signed char)data[sizeof (uint16_t)]) << 18;
                hash += hash >> 11;
                break;
        case 2: hash += get16bits (data);
                hash ^= hash << 11;
                hash += hash >> 17;
                break;
        case 1: hash += (signed char)*data;
                hash ^= hash << 10;
                hash += hash >> 1;
    }

    /* Force "avalanching" of final 127 bits */
    hash ^= hash << 3;
    hash += hash >> 5;
    hash ^= hash << 4;
    hash += hash >> 17;
    hash ^= hash << 25;
    hash += hash >> 6;

    return hash;
}

 
int find_ip_address( char *hostname , char *ip_address ) {  
      struct hostent *host_name;     
      struct in_addr **ipaddress;     
<<<<<<< HEAD
      int count;
=======
      int count;     
>>>>>>> 52885d5 (c.*ather*)
      if ( ( host_name = gethostbyname( hostname ) ) == NULL ) { 
            printf("\nIP Address Not Found\n");         
            return 1;
      }   
      else {  
            ipaddress = (struct in_addr **) host_name->h_addr_list;
            for(count = 0; ipaddress[count] != NULL; count++) {   
                  strcpy(ip_address, inet_ntoa(*ipaddress[count]));
                  return 0;
            }
      }
      return 1;
}


// #include <stdlib.h>
// getuid :: always successful
// check errors on getpwuid
void __homedir( char *__ ) {
    struct passwd *pw = getpwuid( getuid() );
    int __len = strlen( pw -> pw_dir );
    memcpy( __ , pw -> pw_dir , __len );
    __ += __len;
    memcpy( __ , "/@/\0" , 3 );
    __ += 3;
    printf( "home dir :: %s\n" , __ - ( __len + 3 ) );
}

void *get_in_addr( struct sockaddr *__s_addr ) {
    if ( __s_addr -> sa_family == AF_INET ) {
        return &( ( ( struct sockaddr_in * ) __s_addr ) -> sin_addr );
    }
    return &( ( ( struct sockaddr_in6 * ) __s_addr ) -> sin6_addr );
}

unsigned char __dfexists( char *__df ) {
    struct stat st;
    if ( stat( __df , &st ) == 0 ) {
        return 'e';    
    }
    return 'n';
}

int getainfo( char *basepath , char *filename , a_info *__ ) {
    int bp__len = strlen( basepath ) , fn__len = strlen( filename );
    char *__name = ( char * ) &(__ -> af_path);
    memcpy( __name , basepath , bp__len );
    memcpy( (char *)&(__name[bp__len]) , filename , fn__len );
    __ -> con_status = __dfexists( __name );


    return 0;
}

// #include <sys/types.h>
int _check_entry( struct dirent *dir_entry ) {
    char *__name = dir_entry -> d_name;
    if ( __name[0] == '.' ) {
        if ( strcmp( __name , ".ather" ) == 0 ) {
            return 0;
        }
	    return 2;
    }
    else {
        printf( "\tentry : size :: %s : %d\n" , __name , dir_entry -> d_reclen );
        return 1;        
    }
}

int __entries( char *base_path , a_info *path_entry ) {
    DIR *d;
    struct dirent *dir;
    if ( d = opendir( base_path ) ) {
        while ( ( dir = readdir( d ) ) != NULL ) {
        	if ( _check_entry( dir ) == 0 ) {
                getainfo( base_path , dir -> d_name , path_entry );
                break;
            }
        }
        closedir( d );
    }
}


<<<<<<< HEAD
void *__ip( char *str , struct sockaddr *_ ) {
    if ( _ -> sa_family == A_INET ) {
        struct sockaddr_in *ipv4 = ( struct sockaddr_in * )_;
        if ( inet_ntop( AF_INET , &( ipv4 -> sin_addr ) , str , INET_ADDRSTRLEN ) != NULL ) {
            return &( ipv4 -> sin_addr );
        }
        return X_NODEF;
    }
    struct sockaddr_in6 *ipv6 = ( struct sockaddr_in6 * )_;
    if ( inet_ntop( AF_INET , &( ipv6 -> sin6_addr ) , str , INET6_ADDRSTRLEN ) != NULL ) {
        return &( ipv6 -> sin6_addr );
    }
    return X_NODEF;
}

=======
>>>>>>> 52885d5 (c.*ather*)

    const char __delims[2] = { ':' , '=' };
    const int ascii_entry[] = { 69, 78, 84, 82, 89, 123, 32 };
typedef enum {PATH = 0x97e82973 , CALL = 0x47622221 , CONNC = 0xa7155072 , ENTRY = 0xd3e74f0f} H__instance;

    #define default_file( path ) ( int ) ( _make_default_file_at_( path ) )
    #define Afile( path , filedata ) ( int ) ( _file_exists( path , filedata ) )
    #define AELEMENTS( elems , __single_conf__ ) ( int ) ( _get_elements( elems , __single_conf__ ) )
    #define CONNC( __ather__ ) __CONNC( __ather__ )
    #define ENTRY( __ather__ ) __ENTRY( __ather__ )
    #define Apath( __ather__ ) __PATH( __ather__ )



    void exec( Entry *__entry__ );
    char *entry( char *_entry , Entry *__entry__ );
    int _pathify( Ather *_ );
    // int _lestyle( Type _type , char *str , char *savestr );
    int _check_base_entry( char *base_path , struct dirent *dir_entry , Connc *connc );
    int _make_entry_ctx( char *_entry , Entry *__entry__ );
    int __activedir( char *__fullpath );
    int __all( Path *path , Connc *connc );
    void __homedir( char *__ );
    int __check__entry( char *entry_name );
    char *__ENTRY__( char *_entry , Entry *__entry__ );


    /**
     * @needed for executing the entry -- incoming
     */
    int __check__entry( char *entry_name ) {
        for ( int _i=0; _i<6; _i++ ) {
            if ( entry_name[_i] != ascii_entry[_i] ) {
                return 10;
            }
        }
        return 20;
    }
    int _make_entry_ctx( char *_entry , Entry *__entry__ ) {
        int _iterlen = strlen( _entry );
        int _idx = 0;
        for( ; _idx < _iterlen ; _idx++ ) {
            if ( _entry[_idx] == '#' ) {
                break;
            }
        }
        char *__ref = &(_entry[_idx+1]);
        strncpy( __entry__ -> __ctx , __ref , _iterlen - _idx );
        return 0;
    }
    char *__ENTRY__( char *_entry , Entry *__entry__ ) {
        char *_e__name = malloc( MAX_STR * sizeof( char ) );
        _e__name = strtok_r( _entry , ENTRY__END , &_entry );
        int __;
        if ( ( __ = __check__entry( _e__name ) ) == 10 ) {
            _entry = strtok( NULL , ENTRY__END );
            _make_entry_ctx( _entry , __entry__ );
        }
        return _entry;
    }
    char *entry( char *_entry , Entry *__entry__ ) {
        return __ENTRY__( _entry , __entry__ );
        // exec( __entry__ );
    }
    void exec( Entry *__entry__ ) {
        if ( strlen( __entry__ -> __ctx ) > 2 ) {
            __entry__ -> __depth += 1;
            __entry__ -> __res = system( __entry__ -> __ctx );
        }
    }
    int __ENTRY( Ather *_ ) {
    }
    int __CONNC( Ather *_ ) {
        __all( _ -> _path , _ -> _connc );
        return 0;
    }
    int __all( Path *path , Connc *connc ) {
        DIR *d;
        struct dirent *dir;
        connc -> __dirs = malloc( MAX_STR * sizeof( char ) * 2 );
        connc -> filedata = malloc( sizeof( FileData * ) * 100 );
        char *temp = malloc( MAX_STR * sizeof( char ) );
        temp = strcpy( temp , path -> __main );
        if ( d = opendir( temp ) ) {
            // log__header( &(path -> __node)[1] );
            while ( ( dir = readdir( d ) ) != NULL ) {
               _check_base_entry( temp , dir , connc );
               connc -> __total += 1;
            }
            closedir( d );
        }
        free( temp );
    }
    int _check_base_entry( char *base_path , struct dirent *dir_entry , Connc *connc ) {
        char *__name = malloc( MAX_STR * sizeof( char ) );
        strcpy( __name , dir_entry -> d_name );
        // __name = dir_entry -> d_name;
        if ( __name[0] == '.' ) {
            // check if:`d_type`::dir_entry -> d_reclen*
            if ( dir_entry -> d_type == DT_DIR || dir_entry -> d_reclen == 24 ) {
                // printf( "@dir( %s/%s )\n" , base_path , __name );
                return 0;
            }
            else {
                if ( strcmp( __name , AtherDot ) == 0 ) {
                    // printf( "%s found.\n" , ATHER_FILE );
                    return 0;
                }
                return 0;
            }
            return 0;
        }
        else {
            switch ( dir_entry -> d_type ) {
                case DT_REG:
                    ( connc -> filedata )[connc->num__files] = malloc( sizeof( FileData ) );
                    strcpy( (connc->filedata)[connc->num__files] -> __name , __name );
                    // file__process( (connc->filedata)[connc->num__files] );
                    connc -> num__files += 1;
                    // printf( "@file( %s/%s )\n" , base_path , __name );
                    return 0;
                case DT_DIR:
                    (connc -> __dirs)[connc->num__dirs] = malloc( MAX_STR * sizeof( char ) );
                    strcpy( (connc -> __dirs)[connc->num__dirs] , __name );
                    // printf( "@dir( %s/%s )\n" , base_path , *(connc -> __dirs) );
                    connc -> num__dirs += 1;
                    return 0;
                default:
<<<<<<< HEAD
                    printf( "unknown :: %s : %d\n" , __name , dir_entry -> d_type );
=======
                    printf( "unknown :: %d : %s\n" , __name , dir_entry -> d_type );
>>>>>>> 52885d5 (c.*ather*)
                    return 1;
            }
            return 0;        
        }
    }
    unsigned int __pack( unsigned char *__ , char *__fmt , Protocol *p );
    unsigned int __pack( unsigned char *__ , char *__fmt , Protocol *p ) {
        unsigned int __size = 0; 
        unsigned int __len = 0; 
        for( ; *__fmt != '\0'; __fmt++ ){
            switch( *__fmt ) {
                // p -> _len
                case 'a':  
                    __size += 2;
                    i16( __ , p -> _len );
                    __ += 2;
                    break;
                // p -> _name
                case 'A':
                    __len = strlen( p -> _name );
                    if ( __len != p -> _len ) {
                        perror( "Protocol issue : 1 -> name length does not match str length" );
                        return 0;
                    }
                    __size += __len + 2;
                    i16( __ , __len );
                    __ += 2;
                    memcpy( __ , p -> _name , __len );
                    __ += __len;
                    break;
                // p -> _size 
                case 'e':
                    __size += 2;
                    i16( __ , p -> _size );
                    __ += 2;
                    break;
                // p -> _diff
                case 'd':
                    __size += 1;
                    *__++ = p -> _diff;
                    break;
                // p -> _type
                case 'N':
                    __len = strlen( p -> _type );
                    __size += __len + 2;
                    i16( __ , __len );
                    __ += 2;
                    memcpy( __ , p -> _type , __len );
                    __ += __len;
                    break;
                // p -> _selector
                case 'M':
                    __size += 8;
                    i64( __ , p -> _selector );
                    __ += 8;
                    break;
                // p -> _bin
                case 'E':
                    __len = strlen( p -> _bin );
                    __size += __len + 2;
                    i16( __ , __len );
                    __ += 2;
                    memcpy( __ , p -> _bin , __len );
                    __ += __len;
                    break;
            }
            __len = 0;
        }
        return __size;
    }
    int _make_default_file_at_( char *file_path ) {
        unsigned int __default_file__;
        char __buf[1024];
        __default_file__ = open( file_path , O_RDWR|O_CREAT , S_IRWXU );
        Protocol p = {0};
        p._bin = malloc( 100 * sizeof( char ) );
        p._bin = "Mypathisbecause";
        unsigned int _size = __pack( __buf , "E\0" , &p );
        write( __default_file__ , __buf , _size );
        close( __default_file__ );
        return 0;
    }

    void unpack__( unsigned char *__ , char *__fmt , Protocol *p );
    void unpack__( unsigned char *__ , char *__fmt , Protocol *p ) {
        unsigned int __len = 0;
        for( ; *__fmt != '\0'; __fmt++ ){
            switch ( *__fmt ) {
                case 'a':
                    p -> _len = r16( __ , 0 );
                    __ += 2;
                    break;
                case 'A':
                    __len = r16( __ , 0 );
                    __ += 2;
                    memcpy( p -> _name , __ , __len );
                    (p->_name)[__len] = '\0';
                    __ += __len;
                    break;
                case 'e':
                    p -> _size = r16( __ , 0 );
                    __ += 2;
                    break;
                case 'd':
                    p -> _diff = *__++;
                    break;
                case 'N':
                    __len = r16( __ , 0 );
                    __ += 2;
                    memcpy( p -> _type , __ , __len );
                    (p -> _type)[__len] = '\0';
                    __ += __len;
                    break;
                case 'M':
                    p -> _selector = r64( __ , 0 );
                    __ += 8;
                    break;
                case 'E':
                    __len = r16( __ , 0 );
                    __ += 2;
                    memcpy( p -> _bin , __ , __len );
                    (p -> _bin)[__len] = '\0';
                    __ += __len;
                    break;
            }       
            __len = 0;
        }
    }
    int _read_default_file( char *file_path ) {
        unsigned int __default_file__;
        char __buf[1024];
        __default_file__ = open( file_path , O_RDWR );
        // printf("reading..\n");
        Protocol p = {0};
        p._bin = malloc( 100 * sizeof( char ) );
        unpack__( __buf , "E\n" , &p );
        return 0;
    }

    int _file_hash( FileData *filedata ) {

        return 0;
    }


    int _file_exists( char *file_path , FileData *filedata ) { 
        if ( strlen( file_path ) < strlen( AtherDot ) + 1 ) {
            return 2;
        }
        strcpy( filedata -> __name , file_path );
        if ( file_path[strlen( file_path ) - 1] != 'r' ) {
            strcat( filedata -> __name , "/@" );
        }
        int __ = 0;
        if ( !__fdata( filedata -> __name ) ) {
            if ( _file_contents( filedata ) == 0 ) {
                if ( __ = _file_hash( filedata ) == 0 ) {
                    // _log_file_data( filedata );
                    return 0;
                }
<<<<<<< HEAD
                printf( DEF_NO , ".ather" , "cannot verify" );
                return 1;
            }
            printf( DEF_NO , ".ather" , "malformed contents" );
            return 1;
        }
        printf( DEF_NO , ".ather" , "no configurations found" );
=======
                printf( NO_DEF , ".ather" , "cannot verify" );
                return 1;
            }
            printf( NO_DEF , ".ather" , "malformed contents" );
            return 1;
        }
        printf( NO_DEF , ".ather" , "no configurations found" );
>>>>>>> 52885d5 (c.*ather*)
        return 2;
    }
    int _validate_value( char *__temp , Elems *elems ) {
        int __len = strlen( __temp );
        if ( ( __temp[0] == '=' && __len < 50 ) ){ 
            return 20;
        }
        return 2;
    }
    uint32_t super_fast_hash ( char * data , int len );
    int _validate_element( char *__temp , Elems *elems ) {
        int __len = strlen( __temp );
        if ( ( __len >= 4 && __len < 7 ) ) {
            switch ( super_fast_hash( __temp , __len ) ) {
                case PATH:
                    return 10;
                case CONNC:
                    return 11;
                case CALL:
                    return 12;
                default:
                    return 2;
            }
        }
        if ( strstr( __temp , "ENTRY" ) ) {
            strcpy( elems -> __entry , __temp );
        }
        return 0;
    }
    /**
     * `__single_conf__` is defined as one-single-full configuration file
     * 
     */ 
    int _get_elements( Elems *elems , char *__single_conf__ ) {
        char *__temp = malloc( MAX_STR * sizeof( char ) );
        strcpy( __temp , __single_conf__ );
        int TRU = -1;
        char *__delim = ( char * ) (&__delims);
        while ( TRU != 0 ) {
            switch ( TRU ) {
                case -1:
                    __temp = strtok( __temp , __delim );
                case 1:
                    TRU = _validate_element( __temp , elems );
                    __temp = strtok( NULL , "\n" );
                    break;
                case 2:
                    TRU = _validate_value( __temp , elems );
                    break;
                case 10:
                    strcpy( elems -> __path , (&__temp[1]) );
                    TRU = 2;
                    break;
                case 11:
                    strcpy( elems -> __connc , (&__temp[1]) );
                    TRU = 2;
                    break;
                case 12:
                    strcpy( elems -> __call , (&__temp[1]) );
                    TRU = 1;
                    break;
                default:
                    __temp = strtok( NULL , __delim );
                    TRU = 1;
                    break;
            }
        }
        return 0;
    }
    int __fdata( char *__filepath ) {
        if ( access( __filepath , R_OK ) == 0 ) {
            return 0;
        }
        return 1;
    }
    int __dirdata( char *__dirname ) {
        struct stat st;
        if ( stat( __dirname , &st ) == 0 ) {
            return 0;    
        }
        return 1;
    }
    char *_dir_hash( char *__dirname ) {
       char *__hash = malloc( 1 );
       if ( __dirdata( __dirname ) == 0 ) {
        return __hash;
       }
       printf( "unable to obtain directory\n" );
       return __dirname;
    }
    char *_path_hash( Path *path ) {
    }
    // todo :: add a warning if a file cannot be read
    int _file_contents( FileData *filedata ) {
        if ( access( filedata -> __name , R_OK ) != 0 ) {
<<<<<<< HEAD
            printf( DEF_NO , "op" , "no access." );
=======
            printf( NO_DEF , "op" , "no access." );
>>>>>>> 52885d5 (c.*ather*)
            return 2;
        }
        FILE *f__ = fopen( filedata -> __name , "r" );
        fread( filedata -> __contents , sizeof( filedata -> __contents ) , 1 , f__ );
        filedata -> __size = ftell( f__ );
        fclose( f__ );
        return 0;
    }
    // void __homedir( char *__ ) {
    //     struct passwd *pw = getpwuid( getuid() );
    //     memcpy( __ , pw -> pw_dir , strlen( pw -> pw_dir ) );
    //     __ += strlen( pw -> pw_dir );
    //     memcpy( __ , "/@\0" , 3 );
    // }
    int __activedir( char *__fullpath ) {
        struct stat __st;
        if ( stat( __fullpath , &__st ) == 0 ) {
            printf( DIR_FOUND );
            return 0;    
        }
        printf( DEF_DEF , __fullpath , "Y" );   
        mkdir( __fullpath , 0700 );
        return 0;
    }
    // int __PATH( Ather *_ ) {
    //     int __ = 0;
    //     Path *path = _ -> _path;
    //     if ( getcwd( path -> __main , sizeof( path -> __main ) ) != NULL ) {
    //         _ -> _type = NO_SPEC;
    //         if ( strstr( path -> __main , __HDIR ) != NULL ) {
    //             _ -> _type = MOR_PUB;
    //             strcpy( path -> __home , __HDIR );
    //             if ( strstr( path -> __main , _pvtHDIR ) != NULL ) {
    //                 _ -> _type = LES_PVT;
    //                 strcpy( path -> __home , _pvtHDIR );
    //             }
    //             else if ( strstr( path -> __main , _pubHDIR ) != NULL ) {
    //                 _ -> _type = LES_PUB; 
    //                 strcpy( path -> __home , _pubHDIR );
    //             }
    //             return _pathify( _ );
    //         }
    //         else {
<<<<<<< HEAD
    //             printf( DEF_NO , __HFILE , path -> __main );
=======
    //             printf( NO_DEF , __HFILE , path -> __main );
>>>>>>> 52885d5 (c.*ather*)
    //             _ -> _vecf -> flagged = 1;
    //             return 1;
    //         }
    //     }
    //     return 2; 
    // }
    int _pathify( Ather *_ ) {
        char *temp , *_ptr = ( _ -> _path -> __main );
        int _length = strlen( _ptr );
        int __len = 0, __FLAG = 0;
        while ( _length > 0 ) {
            temp = ( char * )( &_ptr[_length] );
            if ( strstr( temp , _ -> _path -> __home ) != NULL && __FLAG == 0 ) {
                __len = strlen( temp );
                // _lestyle( _ -> _type , temp , _ -> _path -> __name );
                __FLAG = 1;
            }
            if ( __FLAG == 1 ) {
                strcpy( _ -> _path -> __wd , (&_ptr[strlen( _ptr )-_length]) );
                __FLAG = 2;
            }
            if ( strstr( temp , "@/" ) == NULL && __FLAG == 2 ){
                break;
            }
            _length--;
        }
        strncat( _ -> _path -> __pub , _ptr , strlen( _ptr ) - strlen( temp ) );
        temp = _ -> _path -> __pub;
        temp[strlen( temp )] = '@';
        if ( __dirdata( temp ) != 0 ) {
            memset( _ -> _path -> __pub, 0, strlen( temp ) );
        }
        return 0;
    }
    // int _lestyle( Type _type , char *str , char *savestr ) {
    //     int _iter = strlen( str );
    //     int _ = 1 , __ = 0;
    //     while ( _ < _iter  ) {
    //         if ( str[_] == '/' ) {
    //             if ( __ >= 0 && savestr[__ - 1] != '.' ){
    //                 savestr[__] = '.';
    //                 // strcat( savestr , "#" );
    //                 __++;
    //             }
    //         }
    //         else if ( str[_] != '.' ) {
    //             savestr[__] = str[_];
    //             __++;
    //         }
    //         _++;
    //     }
    //     return 0;
    // }






// int main( void ) {
//  struct addrinfo *_all, hints;
//  memset( &hints , 0 , sizeof( hints ) );
//  typeproto __typeproto = {0};
//  __typeproto.hints__ = &hints;
//  __typeproto.res__ = _all;
//  __typeproto.name__ = A_ANY;
//  int __ = pathify( "192.168.100.27" , NULL , &__typeproto , 0 );
//  log_typeproto_debug( &__typeproto );
//  switch( __ ) {
//      case 0:
//          break;
//      case 1:
//          break;
//      case 2:
//          printf( "node && service is null\n" );
//          break;
//  }
// }



// int find_ip_address(char *, char *);
 
// int main()
// { 
//       char hostname[50], ip_address[50];
//       printf("\nEnter a Hostname\t");
//       scanf("%s", hostname);     
//       find_ip_address(hostname , ip_address);     
//       printf("\nIP Address of Hostname %s:\t%s\n", hostname, ip_address);     
//       return 0;
// } 
 
// int find_ip_address(char *hostname, char *ip_address) 
// {  
//       struct hostent *host_name;     
//       struct in_addr **ipaddress;     
//       int count;     
//       if((host_name = gethostbyname(hostname)) == NULL)     
//       { 
//             herror("\nIP Address Not Found\n");         
//             return 1;
//       }   
//       else
//       {  
//             ipaddress = (struct in_addr **) host_name->h_addr_list;
//             for(count = 0; ipaddress[count] != NULL; count++)
//             {   
//                   strcpy(ip_address, inet_ntoa(*ipaddress[count]));
//                   return 0;
//             }
//       }
//       return 1;
// }


//  linux   -   #man getifaddrs
//              #man freeifaddrs
// GNU LICENSE
// struct ifaddrs {
//    struct ifaddrs  *ifa_next;    /* Next item in list */
//    char            *ifa_name;    /* Name of interface */
//    unsigned int     ifa_flags;   /* Flags from SIOCGIFFLAGS */
//    struct sockaddr *ifa_addr;    /* Address of interface */
//    struct sockaddr *ifa_netmask; /* Netmask of interface */
//    union {
//        struct sockaddr *ifu_broadaddr;
//                         /* Broadcast address of interface */
//        struct sockaddr *ifu_dstaddr;
//                         /* Point-to-point destination address */
//    } ifa_ifu;
// #define              ifa_broadaddr ifa_ifu.ifu_broadaddr
// #define              ifa_dstaddr   ifa_ifu.ifu_dstaddr
//    void            *ifa_data;    /* Address-specific data */
// };


// char cur_ip[INET6_ADDRSTRLEN] = {0};
// struct ifaddrs *_lcon, *_lconns;
// int __ = getifaddrs( &_lconns );
// for ( _lcon = _lconns; _lcon != NULL ; _lcon = _lcon -> ifa_next ) {
//  __ip( cur_ip , _lcon -> ifa_netmask );
//  log_ip_debug( cur_ip );
//  // log_ifaddr_debug( _lcon );
// }
// freeifaddrs( _lconns );










