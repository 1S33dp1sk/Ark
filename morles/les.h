
#include <sys/select.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <string.h>
#include <arpa/inet.h>

#define PORT_ACCEPT "9999"
#define MAX_STR 256

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

int ather_les( void ) {

	fd_set __main;
	fd_set __reader;
	uint32_t __listener;
	uint32_t group_max , new_fd , n_bytes , yes = 1 , i , k , rv;
	char __buffer[MAX_STR] , remote__ip[INET6_ADDRSTRLEN];
	struct sockaddr_storage __remote;
	struct addrinfo hints , *les_info , *p;

	FD_ZERO( &__main );
	FD_ZERO( &__reader );

	memset( &hints , 0 , sizeof( hints ) );
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_flags = AI_PASSIVE;


	if ( ( rv = getaddrinfo( NULL , PORT_ACCEPT , NULL , &les_info ) ) != 0 ) {
        fprintf( stderr , " getaddr info : %s\n" , gai_strerror( rv ) );
        return -1;
	}


    for ( p = les_info; p != NULL; p = p -> ai_next ) {
    	printf( "Remote IP :: %x\n" , __ip( remote__ip , p -> ai_addr ) );
    }



}