#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <netdb.h>

#define PORT_ACCEPT "9999"

typedef enum {
	ATOMIC ,
	LOCAL,
	GLOBAL,
	UNIVERSAL
} as_type;



int nit_ather_socket( as_type _as_type ) {

	int __listener;
	int __rv;

	int G2G = 1;

	struct addrinfo as_hints , *as_info , *temp;
	memset( &as_hints , 0 , sizeof ( as_hints ) );

	// check if socket already exsits

	switch ( _as_type ) {
		default:
			as_hints.ai_family = AF_UNSPEC;
			as_hints.ai_socktype = SOCK_STREAM;
			as_hints.ai_flags = AI_PASSIVE;
			break;
	}

	if ( ( __rv = getaddrinfo( NULL , PORT_ACCEPT , &as_hints , &as_info ) ) != 0 ) {
		printf("ERROR :: %s : (%s)\n", "getaddrinfo" , gai_strerror( __rv ) );
		return -1;
	}

	for ( temp = as_info ; temp != NULL ; temp = temp -> ai_next ) {
		__listener = socket( temp -> ai_family , temp -> ai_socktype , temp -> ai_protocol );
		if ( __listener < 0 )
			continue;
		setsockopt( __listener , SOL_SOCKET , SO_REUSEADDR , &G2G , sizeof( int ) );
		if ( bind( __listener , temp -> ai_addr , temp -> ai_addrlen ) < 0 )
			continue;
		break;
	}

	freeaddrinfo( as_info );
	return temp == NULL ? -2 : __listener;
}



int main( int argc , char **argv ) {
	if ( argc == 2 ){
		return nit_ather_socket( 0 );
	}

	printf("Usage :: @sockets [0|1|2|3]\n");
	return 1;
}