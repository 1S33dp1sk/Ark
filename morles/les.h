


typedef struct
{
    struct sockaddr_in *s_in;
    struct sockaddr_un *s_un;
    char socket_path[STRING_BUFFER];
} Les;





int les( int argc , char *argv[] ) {
	Les _les = {0};
	int _socket , _temp , _c , *_new;
	struct sockaddr_in client;
	char *message;

	_socket = socket( AF_INET , SOCK_STREAM , 0 );
	if ( _socket == -1 ) {
		printf( AETHER_ERROR , "les :: Socket" , "Cannot create socket" );
		return 2;
	}

	_les->s_in->sin_family = AF_INET;
	_les->s_in->sin_addr.s_addr = INADDR_ANY;
	_les->s_in->sin_port = htons( 8888 );


	if ( bind( _socket , ( struct sockaddr *) &(_les->s_in) , sizeof( _les->s_in ) ) < 0 ) {
		printf( AETHER_ERROR , "les :: Socket" , "Binding to the socket failed" );
		return 2;
	}

	listen( _socket , 3 );
	_c = sizeof( struct sockaddr_in );


	int read_size;
	char _mor[2000];
	while ( ( _new = accept( _socket , ( struct sockaddr *) &client , (socklen_t*) &_c ) ) ) {
		while( ( read_size = recv( sock , _mor , 2000 , 0 ) ) > 0 ) {
			//Send the message back to client
			printf( "\n\t\tmor:%s\n" , _mor );
			write( sock , "request recieved" , strlen( 20 ) );
		}
	}
	return 0;
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