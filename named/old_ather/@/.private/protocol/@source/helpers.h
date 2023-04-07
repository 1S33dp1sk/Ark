
#ifndef AtherHelpers
    #define AtherHelpers "@helpers"

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <ctype.h>
#include <ifaddrs.h>
#include <netdb.h>
#include <stdarg.h>




#define MAX_LEN 4096
#define MAX_FILE 10000
#define MAX_STR 256
#define MAX_PROTO 1024
#define HASH_SIZE 8




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
#include "dot.h"
#include "protocol.h"
#include "verify.h"


/*
    -----------------------------------------------------------------------------------------------------
    |Ather  ::                                                                                          |
    |                                                                                                   |
    |                                              @                                                    |
    |                                                                                                   |
    |                                                                                                   |
    | the `at` is common character defined in UTF-8 under the sequence of 64. it is utilized by ather   |
    | as the main indicator that there's ather or not.                                                  |
    |                                                                                                   |
    -----------------------------------------------------------------------------------------------------
*/
// #include <stdint.h>
// #include <string.h>



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















#endif