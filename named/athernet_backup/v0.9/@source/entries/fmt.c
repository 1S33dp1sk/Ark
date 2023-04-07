#define ATHER_FILE_ENTRY "entry.ath"

#define ATH_BANG '#'
#define ATH_NEW '!'
#define ATH_START '{'
#define ATH_END '}'
#define ATH_POINT '@'
#define ATH_PATH '/'
#define ATH_IP '.'
#define ATH_IPV6 ':'


static char *__filename = "";
char *__env[] = {""};
int look_fmt( char *__ , unsigned int __tlen );
int __shebang( char *__ );
int __entry( char *__ );
int __json( char *__ );

#define ather_sbang __shebang
#define ather_entry __entry
// #define ather_json __json
#define ather_point __sys_entry
#define ather_path __path_entry
#define ather_ipv4 __socket_entry ( char *__ , 4 )
#define ather_ipv6 __socket_entry ( char *__ , 6 )

#include "../probe.h"



int main( int argc , char **argv ) {
	if ( argc != 2 ) { printf("usage :: @fmt filename"); return 1; }
	__filename = argv[1];

	int __fd = 0 , _fn_len = strlen( __filename );
	printf( "@fmt :\n entry :: %s\n" , __filename );

	if ( ( __fd = __path_entry( __filename ) ) != 0 ) {
		char temp[512];
		int r_bytes = read( __fd , temp , 512 );
		#ifdef DEBUG
		printf( "fdvalue is %d \n r_bytes :: %d\n\t:: %s\n" , __fd , r_bytes , temp );
		#endif
		close( __fd );
		return look_fmt( temp , r_bytes );
	}
	else {
		printf( "file :: %s cannot be accessed\n" , __filename );
	}
}

typedef struct {
} lbb_val;

typedef struct {
	uint8_t _k_hash;
	char *_k_raw;
	unsigned int _k_len;
	lbb_val *val;
} lbb_key;

typedef struct {
	char *_p_name;
	unsigned int _p_fd;
	int _p_len;
} ath_point;

typedef struct {
	char *_a_input;

} ath_entry;

typedef struct {
	ath_point point;
} ath;

/**
 * @params _ must be a file descriptor
 * 
 * @dev : usually the format is :
 * 	Key @ name {
 * }
 */ 
int ather_at( unsigned int __fd ) {

	char _;
	while ( read( __fd , &_ , 1 ) > 0 ) {
		switch ( _ ) {
			case ATH_POINT: // should be a valid atherpoint  
				break;
			case ATH_START: // should be the first char after name
				break;
			case ATH_END: // should be the last char before EOF
				break;
			default: // should be concatnated to yeild `Key`
				break;
		}
		break;
	}

}


// rename :: binary_fmt
int look_fmt( char *__ , unsigned int __total ) {
	unsigned int __len = 1;
	while ( __len != 0 ) {
		__len--;
		switch ( __[__len] ) {
			case ATH_BANG:
				execve( __filename , __env , __env );
			case ATH_NEW:
				return __entry( *(&__) );
			case ATH_POINT:
				return __sys_entry( *(&__) );
			case ATH_PATH:
				return __path_entry( *(&__) );
			case ATH_IP:
				return __socket_entry( *(&__+1) , 4 );
			case ATH_IPV6:
				return __socket_entry( *(&__+1) , 6 );
			default:
				continue;
		}
	}
}

int __shebang( char *__ ) {
	// #undef MAX_PATH
	// #define MAX_PATH 2048
	// char filepath[MAX_PATH];
	// memset( &filepath , 0 , sizeof( filepath ) );
	// if ( __[0] == '!' ) {
	// 	__ = *(&__)+1;
	// 	int __c = 0;
	// 	while ( __[__c] != '\n' && __c != MAX_PATH ) {
	// 		filepath[__c] = __[__c];
	// 		__c += 1;
	// 	}
	// 	#ifndef execve
	// 	#include <unistd.h>
	// 	#endif
	// 	__ = *(&__)+__c;
	// 	int __fd = __path_entry( ATHER_FILE_ENTRY );
	// 	if ( __fd == 0 ) {
	// 		__fd = __ather_entry( ATHER_FILE_ENTRY , __ );
	// 		close( __fd );
	// 	}
	// 	char *env[2] = { filepath , ATHER_FILE_ENTRY }; 
	// 	printf( "filepath :: %s\n filevars :: %s\n" , env[0] , env[1] );
	// 	#include "sexec.h"
	// 	sexec( env );
	// }
	return 0;
}

int __entry( char *__ ) {
	#define MAX_ANAME 256
	char filename[MAX_ANAME];
	memset( &filename , 0 , sizeof( filename ) );
	if ( __[0] == '!' ) {
		__ = *(&__)+1;
		int __c = 0;
		while ( __[__c] != '\n' && __c != MAX_ANAME ) {
			filename[__c] = __[__c];
			__c += 1;
		}
		if ( __ather_entry( filename , *(&__)+__c ) > 0 ) {
			printf( "ather entry :: %s\n" , filename );
			return 0;
		}
		return 1;
	}
}