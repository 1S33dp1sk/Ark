// #include "common.h"
#ifndef DEBUG
// #define DEBUG
#endif

#ifndef lbb
	#define lbb little_black_book
	#define Sexec "@sexec"
	#include <unistd.h>
	#include <sys/types.h>
	#include <sys/stat.h>
	#include <ifaddrs.h>
	#include <fcntl.h>
	#include "../sha3.h"


typedef enum {
	LBB_NODENAME,
	LBB_ADDRESS
} lbb_lookup;

/**
 * Flags::
 * 
 * create sx
 * read sx
 * execute sx
 */
typedef enum {
	fd_reg,
	fd_net,
	fd_sx
} fd_types;

typedef enum {
	CREATE_SX = 00,
	READ_SX = 01,
	EXECUTE_SX = 11
} sx_flags;
typedef struct {
#ifndef MAX_FILE
#define MAX_FILE 8192
#endif
#ifndef MAX_STR
#define MAX_STR 256
#endif
	char __contents[MAX_FILE];
	char __name[MAX_STR];
	uint32_t __hash;
} sx_reg;



typedef struct {
#ifndef MAX_STR
#define MAX_STR 100
#endif
	#if defined( TRAIL )
	#define __sock struct addrinfo __addr
	#endif
	char __ipstr[INET6_ADDRSTRLEN];
	char __servstr[MAX_STR];
	uint32_t __reg;
	uint32_t hash;
} sx_net;



typedef struct {
#ifndef MAX_PATH
#define MAX_PATH 2048
#endif
	char sx_path[MAX_PATH];
	#if defined( TRAIL )
	#define sx_verify uint32_t __verify
	#else
	char *kvs;
	#endif
	sx_reg __reg;
	sx_net net;
	uint32_t hash__;
} sx_main;

// typedef struct sha3_context_ {
//     uint64_t saved;             /* the portion of the input message that we
//                                  * didn't consume yet */
//     union {                     /* Keccak's state */
//         uint64_t s[SHA3_KECCAK_SPONGE_WORDS];
//         uint8_t sb[SHA3_KECCAK_SPONGE_WORDS * 8];
//     } u;
//     unsigned byteIndex;         /* 0..7--the next byte after the set one
//                                  * (starts from 0; 0--none are buffered) */
//     unsigned wordIndex;         /* 0..24--the next word to integrate input
//                                  * (starts from 0) */
//     unsigned capacityWords;     /* the double size of the hash output in
//                                  * words (e.g. 16 for Keccak 512) */
// } sha3_context;

typedef struct {
	lbb_lookup __lookup;
	unsigned char *__k;
	uint32_t __klen;
	unsigned char *__v;
	uint32_t __vlen;
	uint32_t __kvc;
	unsigned int __lbb;
	char __cache[MAX_STR];
	char result[1024];
	uint8_t *__hash;
	sha3_context __sha3c;
} sx_lbb;


typedef struct {
	fd_types sx_type;
	unsigned int sx__;
	char *sx_name; // ptr to the start of the array
	unsigned int sx_namelen; // @eqv. strlen( sx_namelen )
	char *sx_lbbv; // values
	unsigned int sx_lbbe; //entries
	union {
		sx_reg reg__;
		sx_net net__;
		sx_main sx__;
	} __;
#define sx_areg __.reg__
#define sx_anet __.net__
#define sx_amain __.sx__;
} sx_ctx;



// initializes the book
unsigned int __lbb__( sx_lbb *lbb );
// check if the call is valid
int check_lbb( sx_lbb *lbb, char *arg );
// queries the book returns *NULL on `NE`||`no_def`
void *lbb_query( sx_lbb *lbb );
// add an address to the book
int lbb_add( sx_lbb *lbb , char *value );
// initializes a *les* instance
// with `__aname`
int ather_les( char *__aname );
// good, fundemental, memory-friendly func
void _lbb_cleanup( sx_lbb *lbb );
void _ctx_cleanup( sx_ctx *ctx );
// attaches the signature to the regular sx
void __hash( sx_reg *reg );
// checks the first letter in the `__contents`
int check__( sx_reg *reg );
// step :: { 1 }
// for correct propagation for the ctx
// struct must be initalized
int __reg( sx_ctx *_ctx , sx_reg *_reg );
// initializes `ipstr` to the address of 
// the socket using `inet_ntop`
// handle both :: < IPV4 , IPV6 >
void *__ip( char *ipstr , struct sockaddr *_ );
// logs the ipstr
void log_ip( char *ipstr );
// attaches the ips to memory
void _ctxnet_ips( sx_ctx *_ctx , sx_net *_net );
// s-execute
// (sign)(&|)execute
void sexec( char const *filepath , unsigned int flags );
// convert the bytes to hexadecimal
static void byte_to_hex( uint8_t b , char s[23] );
// log the sha3 hash (32bytes)
void log_hash( uint8_t *hash );

#define LBB_EXTENTION ".lbb\0"
#define LBB_EXTENTION__LEN 5

unsigned int __lbb__( sx_lbb *lbb ) {
	char lbb_filename[MAX_STR];
	strncpy( lbb_filename, __udef_nodename, strlen( __udef_nodename ) );
	strncat( lbb_filename , LBB_EXTENTION , LBB_EXTENTION__LEN ); 
	int __ = 0;
	if ( (  __ = open( lbb_filename , O_RDWR ) ) > 0 ) {
		write( 0 , "exs•lbb\nsx»lbb\n" , 19 );
		#ifdef DEBUG
		#endif
	}
	else if ( ( __ = open( lbb_filename , O_CREAT|O_WRONLY|O_TRUNC ) ) > 0 ) {
		char b;
		write( 0 , "crt•lbb?(y/n)\n" , 17 );
		read( 0 , &b , 1 );
		if ( b != 'y' ) {
			close( __ );
			remove( lbb_filename );
			return 0;
		}
		#ifdef DEBUG
		write( 0 , "crt•lbb\nsx»rdwr @\n" , 22 );
		#endif
	}

	if ( __ > 0 ) {
		// char buf[1024];
		// uint32_t __res = the_t( __ , buf );
		// printf( "res•lbb :t: %d\n" , *(&__res) );
		// uint32_t __resr = the_r( __ , buf );
		// printf( "res•lbb :r: %d\n" , *(&__resr) );
		return __;
	}
	return 0;
}

int check_lbb( sx_lbb *lbb , char *arg ) {
	if ( ( lbb -> __klen = strlen( arg ) ) < 2 ) {
		return 0;
	}
	if ( arg[0] == '0' && arg[1] == 'x' ) {
		#ifdef DEBUG
		write( 0 , "its an address!\n" , 16 );
		#endif
		lbb -> __lookup = LBB_ADDRESS;
		lbb -> __v = arg;
		return 2;
	}
	else if ( arg[0] == '@' || ( arg[0] == 'a' && arg[1] == 't' ) ) {
		lbb -> __lookup = LBB_NODENAME;
		lbb -> __k = ( char * ) arg;
		sha3_context *__ctx = &( lbb -> __sha3c );
		char *__k = (lbb -> __k);
		uint8_t *__hash = lbb -> __hash;
		sha3_init256( __ctx );
		sha3_set_flags( __ctx , 1 );
		sha3_update( __ctx , __k , lbb -> __klen );
		__hash = ( uint8_t *) sha3_finalize( __ctx );
		#ifdef DEBUG
		printf( "»%s ::\n\t:: sha3 ::" , arg );
		log_hash( ( uint8_t * ) ( __hash ) );
		#endif
		return 1;
	}
	else {
		write( 0 , "only\n `0x` && `@` \n" , 19 );
		return 0;
	}
}

void *lbb_query( sx_lbb *lbb ) {

}

int lbb_add( sx_lbb *lbb , char *value ) {
	if ( lbb -> __k == NULL ) {
		printf("ERR :: key is null." );
		return 1;
	}

	sha3_context *__ctx = &( lbb -> __sha3c );
	uint8_t *__hash = lbb -> __hash;
	sha3_init256( __ctx );
	sha3_set_flags( __ctx , 1 );
	sha3_update( __ctx , value , strlen( value ) );
	__hash = ( uint8_t *) sha3_finalize( __ctx );
	#ifdef DEBUG
	printf( "»»%s ::\n\t:: sha3 ::" , value );
	log_hash( ( uint8_t * ) ( __hash ) );
	#endif
	printf( "%s:=%s\n" , lbb -> __k , value );
	return 0;
}


int ather_les( char *__nodename ) {
// listen
#define _L__LES "@%s :: •L·e·s \n"
// evaluate
#define _E__LES "@%s :: ·L•e·s \n"
// send
#define _S__LES "@%s :: ·L·e•s \n"
	printf( _L__LES , __nodename );
	fd_set master;
	fd_set read_fds;
	int fdmax;

	int listener;
	int newfd;
	struct sockaddr_storage remoteaddr;
	socklen_t addrlen;
	char buf[MAX_STR];
	int nBytes;
	char remoteIP[INET6_ADDRSTRLEN];
	int yes=1;
	int i,k,rv;
	struct addrinfo hints, *les_info, *p;

	FD_ZERO( &master );
	FD_ZERO( &read_fds );

	memset( &hints , 0 , sizeof hints );
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_flags = AI_PASSIVE;

	if ( ( rv = getaddrinfo( NULL , PORT_ACCEPT , &hints , &les_info ) ) != 0 ) {
	    fprintf( stderr , " getaddr info : %s\n" , gai_strerror( rv ) );
	    return 1;
	}

	for ( p = les_info; p != NULL; p = p -> ai_next ) {
	    listener = socket( p -> ai_family , p -> ai_socktype , p -> ai_protocol );
	    if ( listener < 0 ) {
	        continue;
	    }


	    setsockopt( listener , SOL_SOCKET , SO_REUSEADDR , &yes , sizeof( int ) );
	    if ( bind( listener , p -> ai_addr , p -> ai_addrlen ) < 0 ) {
	        close( listener );
	        continue;
	    }
	    break;
	}

	if ( p == NULL ) {
	    fprintf( stderr , "Atherles failed\n" );
	    return 2;
	}

	freeaddrinfo( les_info );
	if ( listen( listener , 10 ) == -1 ) {
	    perror( "listening failed\n" );
	    return 2;
	}

	FD_SET( listener , &master );
	fdmax = listener;

	for ( ;; ) {
	    read_fds = master;
	    if ( select( fdmax + 1 , &read_fds , NULL , NULL , NULL ) == -1 ) {
	        perror("select");
	        return 2;
	    }

	    for ( i = 0; i<=fdmax; i++ ) {
	        if ( FD_ISSET( i , &read_fds ) ) {
	            if ( i == listener ) {
	                addrlen = sizeof remoteaddr;
	                newfd = accept( listener , ( struct sockaddr *)&remoteaddr , &addrlen );
	                if ( newfd == -1 ) {
	                    perror("accept");
	                    continue;
	                }
	                else {
	                    FD_SET( newfd , &master );
	                    if ( newfd > fdmax ) {
	                        fdmax = newfd;
	                    }
	                    printf("AtherLes :: selected new connection from %s on %d\n\n" 
<<<<<<< HEAD
	                        , inet_ntop( remoteaddr.ss_family , 
	                        	((struct sockaddr *)&remoteaddr)
=======
	                        , inet_ntop( remoteaddr.ss_family , get_in_addr((struct sockaddr *)&remoteaddr)
>>>>>>> 52885d5 (c.*ather*)
	                            , remoteIP , INET6_ADDRSTRLEN),
	                                newfd);
	                }
	            }
	            else {
	                if ( ( nBytes = recv( i , buf , sizeof buf , 0 ) ) <= 0 ) {
	                    if ( nBytes == 0 ) {
	                        printf( "Atherles :: %d is out\n" , i );
	                    }
	                    else {
	                        perror("recv");
	                    }
	                    close(i);
	                    FD_CLR( i , &master );
	                }
	                else {
	                    for ( k = 0; k <= fdmax; k++ ) {
	                        if ( FD_ISSET( k , &master ) ) {
	                            if ( k != listener && k != i ) {
	                                if ( send( k , buf , nBytes , 0 ) == -1 ) {
	                                    perror( "send" );
	                                }
	                                printf( "sent message :: %s\n", buf);
	                            }
	                        }
	                    }
	                }
	            }
	        }
	    }
	}
	return 0;
}

void _lbb_cleanup( sx_lbb *lbb ) {
	if ( lbb -> __lbb > 0 )
		close( lbb -> __lbb );
	write( 0 , "•lbb\n" , 7 );
}

void _ctx_cleanup( sx_ctx *ctx ) {

	close( ctx -> sx__ );
}

void __hash( sx_reg *reg ) {

	reg -> __hash = super_fast_hash( reg -> __contents , strlen( reg -> __contents ) );
}

int check__( sx_reg *reg ) {
	char *_ = ( char * )reg -> __contents;
	if ( _[0] != '@' ) {
		write( 0 , "malformed\n" , 10 );
		return -1;
	}
	// should add binary here
	// for protocol comms
	#ifdef DEBUG
	printf("check :: %c\n", _[0] );
	#endif
	return 0;
}

int __reg( sx_ctx *_ctx , sx_reg *_reg ) {
	int __  = open( _reg -> __name , O_RDONLY );
	if ( __ > 0 ) {
		_ctx -> sx_areg = *_reg;
		_ctx -> sx__ = __;
		// could possibly create subsequential calls here
		// read in 10-100-1000 bytes per && can ensure integ. 
		// of packet transfer with send_all		
		if ( __ = read( _ctx -> sx__ , _reg -> __contents , MAX_STR - 2 ) > 0 ) {
			_reg -> __contents[MAX_STR] = '\0';
			__hash( _reg );
			#ifdef DEBUG
			printf("ather wrap -> \n");
			printf( "::\n%s\n::\n" , _reg -> __contents );
			printf(":: hash :: %x\n", _reg -> __hash );
			#endif
			if ( check__( _reg ) == 0 ) {
				_ctx -> sx_areg.__hash = _reg -> __hash;
				return 0;
			}
		}
		return -2;
	}
	return -3;
}

<<<<<<< HEAD
// void *__ip( char *str , struct sockaddr *_ ) {
//     if ( _ -> sa_family == AF_INET ) {
//         struct sockaddr_in *ipv4 = ( struct sockaddr_in * )_;
//         if ( inet_ntop( AF_INET , &( ipv4 -> sin_addr ) , str , INET_ADDRSTRLEN ) != NULL ) {
//             return &( ipv4 -> sin_addr );
//         }
//     }
//     struct sockaddr_in6 *ipv6 = ( struct sockaddr_in6 * )_;
//     if ( inet_ntop( AF_INET , &( ipv6 -> sin6_addr ) , str , INET6_ADDRSTRLEN ) != NULL ) {
//         return &( ipv6 -> sin6_addr );
//     }
// }
=======
void *__ip( char *str , struct sockaddr *_ ) {
    if ( _ -> sa_family == AF_INET ) {
        struct sockaddr_in *ipv4 = ( struct sockaddr_in * )_;
        if ( inet_ntop( AF_INET , &( ipv4 -> sin_addr ) , str , INET_ADDRSTRLEN ) != NULL ) {
            return &( ipv4 -> sin_addr );
        }
    }
    struct sockaddr_in6 *ipv6 = ( struct sockaddr_in6 * )_;
    if ( inet_ntop( AF_INET , &( ipv6 -> sin6_addr ) , str , INET6_ADDRSTRLEN ) != NULL ) {
        return &( ipv6 -> sin6_addr );
    }
}
>>>>>>> 52885d5 (c.*ather*)

void log_ip( char *cur_ip ) {
    
    printf( "•%s\n" , cur_ip );
}

void _ctxnet_ips( sx_ctx *_ctx , sx_net *_net ) {
	#ifdef DEBUG
	printf( "\n\nips hash starting @ :: %x\n\n" ,  _ctx -> sx_areg.__hash  );
	#endif
	struct ifaddrs *_lcon, *_lconns;
	char cur_ip[INET6_ADDRSTRLEN] = {0};
	int __ = getifaddrs( &_lconns );
	for ( _lcon = _lconns; _lcon != NULL ; _lcon = _lcon -> ifa_next ) {
		__ip( cur_ip , _lcon -> ifa_addr );
		#ifdef DEBUG
		log_ip( cur_ip );
		#endif
	}
	freeifaddrs( _lconns );
}

void sexec( char const *__filepath , unsigned int __flag ) {
	unsigned int __ = 0;
	sx_ctx ctx;
	sx_reg initial;
	sx_net net;
	sx_main sx;

	memset( &ctx , 0 , sizeof( sx_ctx ) );
	memset( &initial , 0 , sizeof( sx_reg ) );
	memset( &net , 0 , sizeof( sx_net ) );
	memset( &sx , 0 , sizeof( sx_main ) );


	strncpy( initial.__name , __filepath , MAX_FILE );
	if ( __reg( &ctx , &initial ) == 0 ) {
		_ctxnet_ips( &ctx , &net );
		switch ( __flag ) {
			case CREATE_SX:
				break;
			case READ_SX:
				break;
			case EXECUTE_SX:
				break;
		}
	} 


	// printf( "sx__ :: %d\ttype :: %d\n" , __ctx.sx__ , __ctx.sx_type );
	// int x = read( __ctx.sx__ , buf , MAX_STR - 1 );
	// printf( "read %d bytes @sx__::\n%s\n" , x , buf );


	_ctx_cleanup( &ctx );
}

static void byte_to_hex(uint8_t b, char s[23]) {
    unsigned i=1;
    s[0] = s[1] = '0';
    s[2] = '\0';
    while(b) {
        unsigned t = b & 0x0f;
        if( t < 10 ) {
            s[i] = '0' + t;
        } else {
            s[i] = 'a' + t - 10;
        }
        i--;
        b >>= 4;
    }
}

void log_hash( uint8_t *hash ) {
	printf("\n\t\t");
	for ( int _ = 0 ; _ < 32 ; _ ++ ) {
		char __[3];
		byte_to_hex( hash[_] , __ );
		printf("%s", __ );
	}
	printf("\n");
}


#endif