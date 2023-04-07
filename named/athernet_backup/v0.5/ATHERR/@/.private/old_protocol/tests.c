#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <unistd.h>

// #ifndef ln_pack
// #define pack_ln_16( xather_ ) ( pack_ln( (xather_) , 16 ) );
// #define pack_ln_16( xather_ ) ( pack_ln( (xather_) , 16 ) );

// #define pack_ln_32( xather_ ) ( pack_ln( (xather_), 32) );
// #define unpack_ln_32( xather_ ) ( unpack_ln( (xather_), 32) );

// #define pack_ln_64( xather_ ) ( pack_ln( (xather_), 64) );
// #define unpack_ln_64( xather_ ) ( unpack_ln( (xather_), 64) );
// void pack_ln( Ather *_ , int _to ) {
// }
// #endif


#define PROTOCOL_STYLE "axA-E@N#A{E}"
#define len_IPV6 46
#define p_sep() print_seperator()
#define MAX_A_LEN 0xffff;
#define SELECTOR_BYTES 8
#define LOCAL_A "127.0.0.1"
// binary interface 
// invoke , ABI , pack , etx..
#define i16( __ , _ ) __I( __ , _ , 0 )
#define i32( __ , _ ) __I( __ , _ , 2 )
#define i64( __ , _ ) __I( __ , _ , 6 )
// binary mirror
// reply , ABM , unpack , etx..
#define r16( __ , _ ) __R( __ , _ , 0 )
#define r32( __ , _ ) __R( __ , _ , 2 )
#define r64( __ , _ ) __R( __ , _ , 6 )

typedef enum {
	_NOSPEC,
	_IPv4,
	_IPv6,
	_EVM,
	_ATHER
} nType;


void pr_unsigned_int( unsigned int x );
void print_seperator();
char *_xather_( unsigned int __len , char *__name , char *savestr );
nType node_type( unsigned char __selector );


void print_seperator() {

	printf("\n");
}
void pr_unsigned_int( unsigned int x ) {
 	printf( "\n x :: sizeof , val , @\n :: %016lu : %d : %016x\n" , sizeof( x ) , x , &x );
 	p_sep();
}
char *_xather_( unsigned int __len , char *__name , char *savestr ) {
	sprintf( savestr , "%dxather-%s\\" , __len , __name );
	return savestr;
}
nType node_type( unsigned char __selector ) {
	switch ( __selector ) {
		case '4':
			return _IPv4;
		case '6':
			return _IPv6;
		case '1':
			return _EVM;
		case '0':
			return _ATHER;
		default:
			return _NOSPEC;
	}
}



// __ buffer
// b base 

// `_` is a value of the unsigned char appended 
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

int __T( unsigned char *__ , unsigned long long int _ , unsigned int b ) {

}



/* 	@-PROTOCOL 	*/ 
// len , name , entry length , node , mor , entry
static const char example[49] = "3xather-pub*\\1@4k#default\\{#}";
// #define PRODUCTION
// #ifndef PRODUCTION
// #endif

// typedef struct {
// 	int len , size , select;
// 	char *name , *bin , diff , type[len_IPV6];
// 	long long int selector;
// } _Protocol;

typedef struct {
	unsigned char _diff; // 1 byte
	unsigned int _len , _size , _select; // 2bytes
	unsigned char *_name , *_bin , *_type; // string
	unsigned long long int _selector; // 8 bytes
} Protocol;
#define PROTOCOL_LINE "aAedNME\0"

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


void print_protocol_packet_debug( Protocol *p ) {
	printf( " ATHER :PROTOCOL :: PACKET -> \n " );
	printf( "\tlen 	 :: %d\n" , p -> _len );
	printf( "\tname 	 :: %s\n" , p -> _name );
	printf( "\tsize 	 :: %d\n" , p -> _size );
	printf( "\tdiff 	 :: %c\n" , p -> _diff );
	printf( "\ttype 	 :: %s\n" , p -> _type );
	printf( "\tselector :: 0x%04lx\n" , p -> _selector );
	printf( "\tbin 	 :: %s\n" , p -> _bin );
}

#define DEBUG
#ifdef DEBUG
#include <limits.h>
#include <float.h>
#include <assert.h>
#include <stdlib.h>
#endif

int main( void ) {
#ifndef DEBUG
	unsigned char __buffer[1024];
#else
	unsigned char __buf[1024];
	unsigned int __packet_size;
	// use the Protocol structure
	// to fill the data used for any call.

	char *_p_fmt = "aAedNME\0";
	Protocol __p = {0};

	__p._len = 3; // 2bytes
	__p._name = "pub"; // nbytes ( n = 3 )
	__p._size = 1; // 2bytes
	__p._diff = 'a'; //1byte
	__p._type = "127.0.0.1\0"; // nbytes ( n = 9 )
	__p._selector = 0x97e82973; // 8bytes
	__p._bin = "#"; // nbytes ( n = 1 )

	__packet_size = __pack( __buf , _p_fmt , &__p );
	printf( "Sending packet for :: \n" );
	print_protocol_packet_debug( &__p );
	printf( "total size for packet : %d bytes \n" , __packet_size );

	

	printf("\n\n recieving packet :: \n" );
	Protocol p__ = {0};
	p__._name = malloc( 100 * sizeof( unsigned char ) );
	p__._bin = malloc( 100 * sizeof( unsigned char ) );
	p__._type = malloc( 100 * sizeof( unsigned char ) );
	unpack__( __buf , _p_fmt , &p__ );
	print_protocol_packet_debug( &p__ );


#endif
 	return 0;
 }




// int unpack( unsigned char *__ , char *__fmt , ... ) {

// 	va_list _vars;

// 	_Protocol protocol_ = {0};

// 	char *name__ , type__[len_IPV6] , *bin__;
// 	unsigned int *len__ , *size__ , *hash_selector;
// 	unsigned char *diff__ , *selector;

// 	va_start( _vars , __fmt );

// 	for ( ; *__fmt != '\0'; __fmt++ ) {
// 		switch ( *__fmt ) {
// 			case 'a':
// 				protocol_.__len = va_arg( _vars , unsigned int  );
// 				*len__ = r16( __ , 0 );
// 				__ += 2;
// 				break;
// 			case 'A':
// 				name__ = va_arg( _vars , char * );
// 				unsigned int __len = r16( __ , 0 );
// 				__ += 2;
// 				memcpy( name__ , __ , __len );
// 				name__[__len] = '\0';
// 				__ += __len;
// 				break;
// 			case 'e':
// 				// size__ = va_arg( _vars , unsigned int *);
// 				// *size__ = r16( __ , 0 );
// 				// __ +=2;
// 				break;
// 			case 'd':
// 				// diff__ = va_arg( _vars , unsigned char *);
// 				// *diff__ = *__++;
// 				break;
// 			case 'D':
// 				break;
// 			case 's':
// 				break;
// 			case 'S':
// 				break;
// 			case 'E':
// 				break;
// 			default:
// 				break;			
// 		}
// 	}
// }

// unsigned int __protocolify( unsigned char *__ , char *__fmt , ... ) {

// 	va_list _vars;
// 	Protocol protocol_ = {0};
// 	va_start( _vars , __fmt );
// 	unsigned char *_selector;
// 	unsigned int __total = 0;

// 	for( ; *__fmt != '\0'; __fmt++ ) {
// 		switch ( *__fmt ) {
// 			case 'a':
// 				__total += 1;
// 				protocol_.__len = ( unsigned int ) va_arg( _vars , unsigned int );
// 				i16( __ , protocol_.__len );
// 				__ += 1;
// 				break;
// 			case 'A':
// 				protocol_.__name = ( char * ) va_arg( _vars , char * );
// 				for ( unsigned int temp = protocol_.__len; temp > 0; temp-- )  {
// 					__total += 1;
// 					i16( __ , protocol_.__name[temp] );
// 					__ += 1;
// 				}
// 				break;
// 			case 'e':
// 				protocol_.__size = ( unsigned int ) va_arg( _vars , unsigned int );
// 				if ( protocol_.__size >= 100 ) {
// 					perror( "entry is max. 100" );
// 					return 2;
// 				}
// 				__total += 1;
// 				i16( __ , protocol_.__size );
// 				__ += 1;
// 				break;
// 			case 'd':
// 				protocol_.__diff = ( unsigned char ) va_arg( _vars , int );
// 				__total += 1;
// 				i16( __ , protocol_.__diff );
// 				__ += 1;
// 				break;
// 			case 'D':
// 				if ( protocol_.__diff != 0 ) {
// 					if ( ( char * ) va_arg( _vars , char * ) && protocol_.__diff == '4' ){
// 						unsigned int __length = strlen( LOCAL_A );
// 						__total += __length;
// 						memcpy( __ , LOCAL_A , __length );
// 						memcpy( protocol_.__type , LOCAL_A , __length );
// 						__ += __length;
// 					}
// 				}
// 				else {
// 					perror( "diff cannot be 0. request d before D.\n" );
// 					return 2;
// 				}
// 			case 's':
// 				protocol_.hash_selector = ( unsigned int ) va_arg( _vars , unsigned int );
// 				__total += 2;
// 				i32( __ , protocol_.hash_selector );
// 				__ += 2;
// 				break;
// 			case 'S':
// 				_selector = ( unsigned char *)&protocol_.selector;
// 				_selector = ( unsigned char* ) va_arg( _vars , unsigned char* );
// 				__total += 8;
// 				for ( int i = 0; i < 8; i++ ) {
// 					i16( __ , _selector[i] );
// 				}
// 				__ += 8;
// 				break;
// 			case 'E':
// 				protocol_.__bin = ( char * ) va_arg( _vars , char * );
// 				// if ( strlen( protocol_.__bin ) != protocol_.__size ) {
// 				// 	perror( "entry does not match entry type" );
// 				// 	return 2;
// 				// }
// 				__total += protocol_.__size;
// 				for ( int i = 0; i < protocol_.__size; i++ ) {
// 					i16( __ , protocol_.__bin[i] );
// 				}
// 				__ += protocol_.__size;
// 				break;
// 			default:
// 				break;
// 		}
// 	}

// 	va_end( _vars );

// 	return __total;
// }
