#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/un.h>





int mirror( int _socket , char *_aether , Les _les );


int mor( int argc , char const *argv[] ) {


}




int mirror( int _socket , char *_aether , Les *_les ) {

	int __temp;
	char __reply[AETHER_REPLY_MAX];

	_socket = socket( AF_INET , SOCK_STREAM , 0 );
	if ( _socket < 0 ) {
		printf( AETHER_ERROR , "Socket" , "init failed" );
		return 2;
	}

	_les->sin_addr->s_addr = inet_addr("127.0.0.1"); //16777343;
	_les->sin_family = AF_INET;
	_les->sin_port = htons( 999 );

	if ( connect( _socket , ( struct sockaddr *) &_les , sizeof( _les ) ) < 0 ) {
		printf( AETHER_ERROR , "Socket" , "connection failed" );
		return 2;
	}

	printf( AETHER_SIG );

	char message[AETHER_FILE_BUFFER] = _aether;

	while ( __temp = recv( _socket , __reply , AETHER_REPLY_MAX , 0 ) > 0 ) {
		if ( message != NULL ) {
			if ( send( _socket , message , strlen( message ) , 0 ) >= 0 ) {
				printf( AETHER_EXEC , __reply );
			}
		}
		scanf( AETHER_PATH , message );
	}
	close( _socket );
	return 0;
}

















// v2
// int main( int argc, char const *argv[] ) {
// 	if ( argc > 1 ) {
// 		return _client_local( argc , argv );
// 	}
// 	return _client( argv[1] );
// }


// int _client_local( int argc, char const *argv[] ) {

// 	int socket_desc;
// 	struct sockaddr_in _listener;
// 	char *_les, mor_[2000];

// 	socket_desc = socket( AF_INET , SOCK_STREAM , 0 );
// 	if ( socket_desc == -1 ) {
// 		printf( AETHER_ERROR , "CONNC" , "Socket Cannot be created" );
// 		return 2;
// 	}

// 	_listener.sin_family = AF_INET;
// 	_listener.sin_addr.s_addr = inet_addr( "127.0.0.1" );
// 	_listener.sin_port = htons( 9999 );

// 	if ( connect( socket_desc , (struct sockaddr *)&_listener , sizeof( _listener ) ) < 0 ) {
// 		puts( "connect error" );
// 		return 0;
// 	}

// 	puts( "connected" );


// 	//Send some data
// 	_les = "GET / HTTP/1.1\r\n\r\n";
// 	if( send( socket_desc , _les , strlen( _les ) , 0 ) < 0 ) {
// 		puts( "Send failed" );
// 		return 1;
// 	}
// 	puts( "data sent\n" );


// 	//Receive a reply from the server
// 	if( recv( socket_desc, mor_ , 2000 , 0 ) < 0 ) {
// 		puts( "recv failed" );
// 	}
// 	puts( "Reply received\n" );
// 	puts( mor_ );

// 	close( socket_desc );
	
// 	return 0;
// }

// int _client( char const *argv ) {
// 	int socket_desc;
// 	// struct sockaddr_in _les;
//   	struct sockaddr_un _les;
// 	char evaluate_[AETHER_FILE_BUFFER], mor_[2000];


// 	socket_desc = socket( AF_LOCAL , SOCK_DGRAM , 0 );
// 	if ( socket_desc < 0 ) {
// 		perror( "Cannot create socket" );
// 		return 2;

// 	}

// 	_les.sun_family = AF_LOCAL;
// 	strncpy( _les.sun_path , "x" , sizeof( _les.sun_path ) );


//   	if (connect ( socket_desc, (struct sockaddr *) &_les, sizeof( _les )) < 0) {
//       perror ("connect");
//       exit (EXIT_FAILURE);
//     }

// 	//Send some data
// 	sprintf( evaluate_ , "PATH:=Aether\nCONNC:=\nCALL:=entry\nENTRY{ ##python3 }\n\r" );
// 	if( send( socket_desc , evaluate_ , strlen( evaluate_ ) , 0 ) < 0 ) {
// 		puts( "Send failed" );
// 		return 1;
// 	}
// 	puts( "data sent\n" );


// 	close( socket_desc );
// 	return 0;
// }









// v1
// int _client() {
// 	int socket_desc;
// 	struct sockaddr_in _listener;
// 	char *_les, mor_[2000];

// 	socket_desc = socket( AF_INET , SOCK_STREAM , 0 );
// 	if ( socket_desc == -1 ) {
// 		printf( AETHER_ERROR , "CONNC" , "Socket Cannot be created" );
// 		return 2;
// 	}

// 	_listener.sin_addr.s_addr = inet_addr( "127.0.0.1" );
// 	_listener.sin_family = AF_INET;
// 	_listener.sin_port = htons( 8888 );

// 	if ( connect( socket_desc , (struct sockaddr *)&_listener , sizeof( _listener ) ) < 0 ) {
// 		puts( "connect error" );
// 		return 0;
// 	}

// 	puts( "connected" );


// 	//Send some data
// 	_les = "GET / HTTP/1.1\r\n\r\n";
// 	if( send( socket_desc , _les , strlen( _les ) , 0 ) < 0 ) {
// 		puts( "Send failed" );
// 		return 1;
// 	}
// 	puts( "data send\n" );


// 	//Receive a reply from the server
// 	if( recv( socket_desc, mor_ , 2000 , 0 ) < 0 ) {
// 		puts( "recv failed" );
// 	}
// 	puts( "Reply received\n" );
// 	puts( mor_ );

// 	close( socket_desc );
// }

// int main( int argc, char const *argv[] ) {

// 	int socket_desc;
// 	struct sockaddr_in _listener;
// 	char *_les, mor_[2000];

// 	socket_desc = socket( AF_INET , SOCK_STREAM , 0 );
// 	if ( socket_desc == -1 ) {
// 		printf( AETHER_ERROR , "CONNC" , "Socket Cannot be created" );
// 		return 2;
// 	}

// 	_listener.sin_addr.s_addr = inet_addr( "127.0.0.1" );
// 	_listener.sin_family = AF_INET;
// 	_listener.sin_port = htons( 8888 );

// 	if ( connect( socket_desc , (struct sockaddr *)&_listener , sizeof( _listener ) ) < 0 ) {
// 		puts( "connect error" );
// 		return 0;
// 	}

// 	puts( "connected" );


// 	//Send some data
// 	_les = "GET / HTTP/1.1\r\n\r\n";
// 	if( send( socket_desc , _les , strlen( _les ) , 0 ) < 0 ) {
// 		puts( "Send failed" );
// 		return 1;
// 	}
// 	puts( "data send\n" );


// 	//Receive a reply from the server
// 	if( recv( socket_desc, mor_ , 2000 , 0 ) < 0 ) {
// 		puts( "recv failed" );
// 	}
// 	puts( "Reply received\n" );
// 	puts( mor_ );

// 	close( socket_desc );
	
// 	return 0;
// }