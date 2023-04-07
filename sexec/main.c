#include "sockets.h"



/**
 * SBLA
 * 
 * Socket 
 * Bind
 * Listen
 * Evaluate/Accept
 * 
 * 
 * SC
 * Socket
 * Connect
 * 
 */ 
int main( int argc , char **argv ) {

	int x = get_listener_socket() , __x;
	struct sockaddr_storage __addr;
	socklen_t sin_size;
	char ipstr[INET6_ADDRSTRLEN];

	if ( listen( x , 10 ) == -1 ) {
		printf("cannot listen\n");
		return -1;
	}

	printf( "socket :: %d\n" , x );

	while( 1 ) {
		sin_size = sizeof __addr;

		__x = accept( x , ( struct sockaddr * )&__addr , &sin_size );
		if ( __x == -1 ) {
			printf("unable to accept");
			return -2;
		}
        inet_ntop( __addr.ss_family , get_in_addr( ( struct sockaddr * )&__addr ) , ipstr , sizeof ipstr );
        printf("ipstr : %s\n" , ipstr);

        close( __x );
	}
}
