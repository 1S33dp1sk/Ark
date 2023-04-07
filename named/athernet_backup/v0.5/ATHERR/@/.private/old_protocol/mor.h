#ifndef MOR

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT_ACCEPT "9999"
#define MAX_ATHER_SIZE 1000

#define SEP_PATH " » "
#define SEP_CALL " • "
#define SEP_CONNC " — "
#define SEP_NODEF " [\u2716] "

// void *get_in_addr( struct sockaddr *sa ) {
// 	if ( sa -> sa_family == AF_INET ) {
// 		return &( ( ( struct sockaddr_in * ) sa ) -> sin_addr );
// 	}
// 	return &( ( ( struct sockaddr_in6 * ) sa ) -> sin6_addr );
// }


int MOR( Ather *_ ) {

	int sockfd , numbytes;
	char buf[MAX_ATHER_SIZE];
	struct addrinfo hints , *les_info , *p;
	int rv;
	char s[INET6_ADDRSTRLEN];


	memset( &hints , 0 , sizeof hints );
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;

	if ( ( rv = getaddrinfo( "127.0.0.1" , PORT_ACCEPT , &hints , &les_info ) ) != 0 ) {
		fprintf( stderr , "mor » no ather [\u2716] —» %s\n" , gai_strerror( rv ) );
		return 1;
	}


	for ( p = les_info; p != NULL; p = p -> ai_next ) {
		if ( ( sockfd = socket( p -> ai_family , p -> ai_socktype , p -> ai_protocol ) ) == -1 ) {
			perror( "mor » mirror [\u2716] —» failed " );
			return 2;
		}

		if ( connect( sockfd , p -> ai_addr , p -> ai_addrlen ) == -1 ) {
			close( sockfd );
			perror( "mor » onconnect [\u2716] —» failed" );
			continue;
		}
		break;
	}

	if ( p == NULL ) {
		fprintf( stderr , "mor » reply [\u2716] —» failed activating les\n" );
		return 2;
	}

	inet_ntop( p -> ai_family , get_in_addr( ( struct sockaddr * ) p -> ai_addr ) , s , sizeof s );

	printf( "\n—» mor•les —»");
	freeaddrinfo( les_info );

	if ( ( numbytes = recv( sockfd , buf , MAX_ATHER_SIZE-1, 0 ) ) == -1 ) {
		perror( "morles » no .ather [\u2716] —» unable to verify .ather" );
		exit( 1 );
	}

	buf[numbytes] = '\0';

	printf( "»\n\t%s\n" , buf );
	close( sockfd );
	return 0;
}

#endif