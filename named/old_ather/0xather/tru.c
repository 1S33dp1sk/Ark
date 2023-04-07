#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <string.h>
#include <netdb.h>
#include <arpa/inet.h>



int get_listener_socket( void ) {
    int _listener;
    int yes=1;
    int rv;
    struct addrinfo hints, *les_info, *p;
    memset( &hints , 0 , sizeof hints );
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;

    if ( ( rv = getaddrinfo( NULL , "9999" , &hints , &les_info ) ) != 0 ) {
        fprintf( stderr , " getaddr info : %s\n" , gai_strerror( rv ) );
        return 1;
    }
    for( p = les_info; p != NULL; p = p -> ai_next ) {
        _listener = socket( p -> ai_family , p -> ai_socktype , p -> ai_protocol );
        if ( _listener < 0 ) {
            continue;
        }
        // remove "addr in use" bs
        setsockopt( _listener , SOL_SOCKET , SO_REUSEADDR , &yes , sizeof( int ) );
        if ( bind( _listener , p -> ai_addr , p -> ai_addrlen ) < 0 ) {
            continue;
        }
        break;
    }

    freeaddrinfo( les_info );
    if ( p == NULL ) {
        return -1;
    }

    return _listener;
}

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
