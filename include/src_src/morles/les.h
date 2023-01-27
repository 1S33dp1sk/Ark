
#include <sys/select.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <string.h>
#include <arpa/inet.h>
#include<pthread.h> //for threading , link with lpthread


void *evaluate( void *);
int send_mor_aether( char *_aether , int len_aether , AETHER_FILE *_aether_file );



int les( int argc , char *argv[] ) {
	int _socket , _temp , _c , *_new;
	struct sockaddr_in client,server;
	char *message , __mor[1000];
	int num_threads = 1;


	_socket = socket( AF_INET , SOCK_STREAM , 0 );
	if ( _socket == -1 ) {
		printf( AETHER_ERROR , "les :: init" , "Socket cannot be created" );
		return 2;
	}

	server.sin_family = AF_INET;
	server.sin_addr.s_addr = INADDR_ANY;
	server.sin_port = htons( 9999 );


	if ( bind( _socket , ( struct sockaddr *) &server , sizeof( server ) ) < 0 ) {
		printf( AETHER_ERROR , "les :: init" , "Socket binding failed" );
		return 2;
	}

	listen( _socket , 3 );
	_c = sizeof( struct sockaddr_in );

	printf( AETHER_LES );

	int read_size;
	while ( ( _temp = accept( _socket , ( struct sockaddr *) &client , (socklen_t*) &_c ) ) ) {
		pthread_t sniffer_thread;
		_new = malloc(1);
		*_new = _temp;
		if( pthread_create( &sniffer_thread , NULL ,  evaluate , ( void *) _new) < 0) {
			printf( AETHER_ERROR , "les :: init" , "Thread cannot be created" );
			return 2;
		}
		num_threads += 1;
	}
	if ( _temp < 0 ) {
		printf( AETHER_ERROR , "les :: init" , "Listener could not accept connection" );
		return 2;
	}
	return 0;
}



void *evaluate( void *__socket ) {
	//Get the socket descriptor
	int _socket = *(int*)__socket;
	int _aether_size;
	char *message , __mor[AETHER_FILE_BUFFER];

	// message = "(P)ath , (C)onnc , C(all) , ENTRY{}\n";
	// send( _socket , message , strlen(message) , 0 );

	while ( _aether_size = recv( _socket , __mor , sizeof( __mor ) , 0 ) > 0 ) {
		int __mor_size = strlen( __mor );
		AETHER_FILE aether_file = {0};
		// if ( _get_attribs( &request_file ) == 0 ) {
		// 	printf( "\n%s\n" , request_file.A_PATH );
		// }

		if ( __mor_size > 10 ) {
			printf( AETHER_LISTEN , __mor_size , __mor  );
			if ( send_mor_aether( __mor , __mor_size , &aether_file ) == 0 ) {

				send( _socket , "request recieved\n\r\n\r" , 22 , 0 );
			}
			send( _socket , "request denied\n\r\n\r" , 20 , 0 );
		}
		else {
			printf( AETHER_ERROR , "les :: evaluate" , ".aether too short" );
			send( _socket , "request denied\n\r\n\r" , 20 , 0 );
		}
	}

	if ( _aether_size == -1 ) {
		printf( AETHER_ERROR , "les :: evaluate" , ".aether recv failed" );
	}
	else if ( _aether_size == 0 ) {
		printf( AETHER_LINE , "les -> mor disconnected" );
		fflush( stdout );
	}

	free( __socket );
	return 0;
}



int send_mor_aether( char *_aether , int len_aether , AETHER_FILE *_aether_file ) {
	a_file __file_raw = {0};

	_aether_file->A_FILE = &__file_raw;
	_aether_file->A_FILE->_contents = _aether;
	int _check = _get_attribs( _aether_file );

	printf( AETHER_SEND , _check  );

	// printf("\n\n\n check :: %d\n\n\n" , _check );

	return 0;
}

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

// v1
// #include <stdio.h>
// #include <sys/socket.h>
// #include <arpa/inet.h>
// #include <string.h>
// #include <unistd.h>
// #include <pthread.h> //for threading , link with lpthread
// #include <stdlib.h>
// #include <stddef.h>
// #include <errno.h>
// #include <sys/un.h>



// // by GNU.
// int make_named_socket( const char *filename );
// int _make_simple_socket( int socket_desc );
// int _listen( int socket_desc );
// int _make_raw_socket( int _socket_desc );
// void *connection_handler(void *);
// int _make_super_socket( int _external_socket , int _local_socket );



// int main( int argc , char const *argv[] ) {
// 	int __socket,socket__ = 0;
// 	int s__socket = _make_super_socket( _make_simple_socket( socket__ ) , _make_raw_socket( __socket ) );
// 	return 0;
// 	// return _make_and_listen();
// }


// int _make_raw_socket( int _socket_desc ) {
//   	struct sockaddr_un _les;
// 	//Prepare the sockaddr_in structure
// 	_les.sun_family = AF_LOCAL;
// 	strncpy( _les.sun_path , "x" , sizeof( _les.sun_path ) );
//  	int size = (offsetof (struct sockaddr_un, sun_path)
//           + strlen (_les.sun_path));

// 	( _socket_desc = socket(AF_LOCAL , SOCK_DGRAM , 0) ) == -1 ? 2 : _socket_desc;
// 	//Bind
// 	if( bind( _socket_desc , (struct sockaddr *)&_les , sizeof( _les ) ) < 0 ) {
// 		puts("bind failed : raw");
// 	}
// 	printf("%d\n\n\n", _socket_desc);
// 	return 	_socket_desc;
// }


// int _make_simple_socket( int _socket_desc ) {
// 	struct sockaddr_in _listener;
// 	//Prepare the sockaddr_in structure
// 	_listener.sin_family = AF_INET;
// 	_listener.sin_addr.s_addr = INADDR_ANY;
// 	_listener.sin_port = htons( 9999 );

// 	( _socket_desc = socket ( AF_INET , SOCK_STREAM , 0 ) ) == -1 ? 2 : _socket_desc;
// 	//Bind
// 	if( bind( _socket_desc ,(struct sockaddr *)&_listener , sizeof( _listener )) < 0) {
// 		puts("bind failed : simple");
// 	}
// 	printf("%d\n\n\n", _socket_desc);
// 	return 	_socket_desc;
// }


// int _make_super_socket( int _external_socket , int _local_socket ) {
// 	int new_socket , c , *new_sock;
// 	char e_send[2000];
// 	char *_eval = "\0";
// 	char __send[100] = "recieved\n\n .aether";
// 	struct sockaddr_in client;

// 	listen( _external_socket , 3 );
// 	listen( _local_socket , 4 );
	
// 	//Accept and incoming connection
// 	printf("\n\033[38;2;84;84;84mAether\e[0;37m :: %s" , "(L)es :\n");
// 	c = sizeof( struct sockaddr_in );

// 	while ( 1 ) {
// 		if ( ( new_socket = recv( _local_socket , e_send , 1999 , 0 ) ) > 0 ) {
// 		printf( ".aether :: %ld,-> \n%s\n" , strlen( e_send ) , e_send );

// 		}
// 		if ( ( new_socket = connect( _external_socket , (struct sockaddr *)&client, sizeof( c ) ) ) > 0 ) {
// 			printf( "new con -> " );
// 			write( new_socket , "new" , 4 );
// 		}
// 	}

// 	// while ( ( new_socket = recv( _local_socket , e_send , 1999 , 0 ) ) > 0 ) {
// 	// 	printf( ".aether :: %ld,-> \n%s\n" , strlen( e_send ) , e_send );
// 	// }


// 	printf("\n recv donz \n");

// 	if ( new_socket < 0 ) {
// 		perror( "accept failed" );
// 		return 1;
// 	}
// 	// printf("Closing");
// 	// close( socket_desc );

// 	close( _external_socket );
// 	close( _local_socket );

// 	return 0;


// }




// int _listen( int socket_desc ) {
// 	int new_socket , c , *new_sock;
// 	char e_send[2000];
// 	char *_eval;

// 	listen(socket_desc , 3);
	
// 	//Accept and incoming connection
// 	printf("\n\033[38;2;84;84;84mAether\e[0;37m :: %s" , "(L)es :\n");
// 	c = sizeof( struct sockaddr_in );

// 	while ( ( new_socket = recv( socket_desc , e_send , 1999 , 0 ) ) > 0 ) {
// 		printf( ".aether :: %ld,-> \n%s\n" , strlen( e_send ) , e_send );
// 	}


// 	printf("\n recv donz \n");

// 	if ( new_socket < 0 ) {
// 		perror( "accept failed" );
// 		return 1;
// 	}
// 	// printf("Closing");
// 	// close( socket_desc );

// 	close( socket_desc );

// 	return 0;
// }

// void *connection_handler(void *socket_desc) {
// 	//Get the socket descriptor
// 	int sock = *(int*)socket_desc;
// 	int read_size;
// 	char *message , client_message[2000];
	
// 	//Send some messages to the client
// 	message = "Greetings! I am your connection handler\n";
// 	write(sock , message , strlen(message));
	
// 	message = "Now type something and i shall repeat what you type \n";
// 	write(sock , message , strlen(message));
	
// 	//Receive a message from client
// 	while( (read_size = recv(sock , client_message , 2000 , 0)) > 0 ) {
// 		//Send the message back to client
// 		write(sock , client_message , strlen(client_message));
// 	}
	
// 	if(read_size == 0) {
// 		puts("Client disconnected");
// 		fflush(stdout);
// 	}
// 	else if(read_size == -1) {
// 		perror("recv failed");
// 	}

// 	printf("%s" , "Handler Freed @");	
// 	//Free the socket pointer
// 	free(socket_desc);
	
// 	return 0;
// }



// int make_named_socket (const char *filename) {
//   struct sockaddr_un name;
//   int sock;
//   size_t size;

//   /* Create the socket. */
//   sock = socket (PF_LOCAL, SOCK_DGRAM, 0);
//   if (sock < 0) {
//       perror ("socket");
//       exit (EXIT_FAILURE);
//     }

//   /* Bind a name to the socket. */
//   name.sun_family = AF_LOCAL;
//   strncpy (name.sun_path, filename, sizeof (name.sun_path));
//   printf("\nSocket :: @ : %s\n", name.sun_path );
//   name.sun_path[sizeof (name.sun_path) - 1] = '\0';

//   /* The size of the address is
//      the offset of the start of the filename,
//      plus its length (not including the terminating null byte).
//      Alternatively you can just do:
//      size = SUN_LEN (&name);
//  */
//   size = (offsetof (struct sockaddr_un, sun_path)
//           + strlen (name.sun_path));

//   if (bind (sock, (struct sockaddr *) &name, size) < 0) {
//       perror ("bind");
//       exit (EXIT_FAILURE);
//     }


//   return _listen( sock );
// }
