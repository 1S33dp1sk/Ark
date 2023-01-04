#include "nai.h"

/**
errors 
 * 
 * -1 :: cannot get current working dir
 * -2 :: os path too long
 * -3 :: lbb cannot be `access`ed()
 * -4 :: no atherpoint found
 * -5 :: cannot get host details `gethostbyname` failed
 * -6 :: cannot initiate communication socket
 * -7 :: could not bind to network address
 * -8 :: could not listen on socket
**/

#define sp_network htons( 9999 )
#define sa_global_port "3490"  // the global conf port
#define sa_global_queue 10   // queue size for connections
#define sa_size sizeof( struct in_addr )
#define sa6_size sizeof( struct in6_addr )

char *__path_unix( char *__path , char *__filename ) {
	int path_len = strlen( __path ) - 1 , fname_len = strlen( __filename ) - 1;
	if ( __path[path_len] != '/' && __filename[0] != '/' ) {
		strncat( __path , "/\0" , 2 );
	}
	return ( path_len + fname_len ) < max_path ? strcat( __path , __filename ) : NULL;
}

#ifdef __signals
	#include <errno.h>
	#include <sys/wait.h>
	void sigchld_handler( int s ) {
		// save errorno & restore
	    // as `waitpid` might overwrite
	    int saved_errno = errno;

	    while( waitpid( -1 , NULL , WNOHANG ) > 0 );

	    errno = saved_errno;
	}
#endif

// get sockaddr, IPv4 or IPv6:
void *get_in_addr( struct sockaddr *sa ) {
	if ( sa->sa_family == AF_INET ) {
		return &( ( ( struct sockaddr_in* ) sa )-> sin_addr );
	}
	return &( ( ( struct sockaddr_in6* ) sa )-> sin6_addr );
}

/***
 * interface calls only check and return the
 * native structure for the interface
 * i.e :: only ATOMIC && GET but no SET is allowed here.
 */

// node number : point
// mount path : lbb
int uni_interface( struct a_inmp *inmp ) {

	struct stat __st;
	char *path = inmp -> imp;
	// zero the initial path
	char __path[max_path];
	memset( __path , 0 , max_path );
	// get the current working dir
	if ( getcwd( __path , max_path ) == NULL ) {
		#ifdef DEBUG
		printf( "cannot get working dir\n" );
		#endif
		return -1;
	}
	// re-zero the `mp`
	memset( path , 0 , max_path );
	// copy the path to struct element
	memcpy( path , __path , strlen( __path ) );
	// add the `.lbb` name to the path
	if ( __path_unix( path , ".lbb" ) == NULL ) {
		printf( "cannot construct lbb path\n" );
		return -2;
	}
	// check calling process permissions
	// for constructed path to lbb
	if ( access( path , F_OK|R_OK ) != 0 ) {
		#ifdef DEBUG
		printf( "lbb cannot be accessed\n" );
		#endif
		return -3;
	}
	// attach `atherpoint` to the directory path
	if ( __path_unix( __path , "atherpoint" ) == NULL ) {
		printf( "cannot construct point path\n" );
		return -2;
	}
	// call the FIFO `stat` to retreive `inn`
	if ( stat( __path , &__st ) == -1 ) {
		printf("cannot initiate unix interface\n");
		return -4;				
	}
	// get the inodenum from the struct `stat`
	// and add the value to `inmp`
	return 0;
}
// S B L A
int loc_interface( struct a_isok *isok ) {
	
	// check ipv4 socket first
	int _sok = socket( AF_INET , SOCK_STREAM , 0 ) , _ip6flag = 0;
	#ifdef DEBUG
		printf( "creating socket IPV4 :: " );
	#endif
	if ( _sok < 0 ) {
		_ip6flag = 1;
		#ifdef DEBUG
			printf( "failed.\ncreating socket IPV6 :: " );
		#endif
		if ( ( _sok = socket( AF_INET6 , SOCK_STREAM , 0 ) ) < 0 ) {
			#ifdef DEBUG
				printf( "failed.\n exiting.\n" );
			#endif
			printf( "cannot initiate communication socket\n" );
			return -6;
		}
	}
	#ifdef DEBUG
		printf( "success\n" );
	#endif

	printf( "socket result :: %d\n" , _sok );


	struct sockaddr_in _iaddr4;
	struct sockaddr_in6 _iaddr6;


	void *_iaddr;
	int res, _iasize = sizeof( struct sockaddr_in ) , _ia6size = sizeof( struct sockaddr_in6 );


	if ( _ip6flag ) {
		_iaddr6.sin6_family = AF_INET6;
		_iaddr6.sin6_port = sp_network;
		res = inet_pton( AF_INET6 , s_local2v6 , &_iaddr6.sin6_addr );
		res = bind( _sok , (struct sockaddr*)&_iaddr6 , _ia6size );
	}else{
		_iaddr4.sin_family = AF_INET;
		_iaddr4.sin_port = sp_network;
		res = inet_pton( AF_INET , s_local , &_iaddr4.sin_addr );
		res = bind( _sok , (struct sockaddr*)&_iaddr4 , _iasize );
	}

	if ( res != 0 ) {
		printf( "could not bind to local network address.\n" );
		return -7;
	}
	

	printf( "binding result :: %d\n" , res );

	struct sockaddr_storage their_addr; // connector's address information
	int _newfd;
	socklen_t sin_size;
	char s[INET6_ADDRSTRLEN];

	if ( listen( _sok , 10 ) == -1 ) {
		printf("cannot listen on socket.\n");
		return -8;
	}

	printf("server: waiting for connections...\n");

	while(1) { 
		sin_size = sizeof( their_addr );
		_newfd = accept(_sok, (struct sockaddr *)&their_addr, &sin_size);
		if ( _newfd == -1 ) {
			// cannot accept
			continue;
		}

		inet_ntop(their_addr.ss_family,
		get_in_addr((struct sockaddr *)&their_addr),
		s, sizeof s);
		printf("server: got connection from %s\n", s);

		if (!fork()) { // this is the child process
			close( _sok ); // child doesn't need the listener
			if ( send( _newfd , "ather :: nai : 1\n" , 17 , 0 ) == -1 ) {
				printf( "could not send back data\n" );
			}
			close( _newfd );
			exit( 0 );
		}

		close( _newfd );  // parent doesn't need this
	}
}
// global socket && sbla
int glo_interface( struct a_idns *idns ) {
	int sockfd, new_fd;  // listen on sock_fd, new connection on new_fd
	struct addrinfo hints, *servinfo, *p;
	struct sockaddr_storage their_addr; // connector's address information
	socklen_t sin_size;
	// struct sigaction sa;
	int yes=1;
	char s[INET6_ADDRSTRLEN];
	int rv;

	memset(&hints, 0, sizeof hints);
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_flags = AI_PASSIVE; // use my IP

	if ((rv = getaddrinfo(NULL, sa_global_port, &hints, &servinfo)) != 0) {
		fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
		return 1;
	}

	// loop through all the results and bind to the first we can
	for(p = servinfo; p != NULL; p = p->ai_next) {
		if ((sockfd = socket(p->ai_family, p->ai_socktype,
				p->ai_protocol)) == -1) {
			perror("server: socket");
			continue;
		}

		if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &yes,
				sizeof(int)) == -1) {
			perror("setsockopt");
			exit(1);
		}
		
		if (bind(sockfd, p->ai_addr, p->ai_addrlen) == -1) {
			close(sockfd);
			perror("server: bind");
			continue;
		}
		inet_ntop(p->ai_family,
			get_in_addr((struct sockaddr *)&p->ai_addr),
			s, sizeof s);
		printf("server: running on socket :: %s\n", s);

		break;
	}

	freeaddrinfo(servinfo); // all done with this structure

	if (p == NULL)  {
		fprintf(stderr, "server: failed to bind\n");
		exit(1);
	}

	if (listen(sockfd, sa_global_queue) == -1) {
		perror("listen");
		exit(1);
	}

	// sa.sa_handler = sigchld_handler; // reap all dead processes
	// sigemptyset(&sa.sa_mask);
	// sa.sa_flags = SA_RESTART;
	// if (sigaction(SIGCHLD, &sa, NULL) == -1) {
	// 	perror("sigaction");
	// 	exit(1);
	// }

	printf("server: waiting for connections...\n");

	while(1) {  // main accept() loop
		sin_size = sizeof their_addr;
		new_fd = accept(sockfd, (struct sockaddr *)&their_addr, &sin_size);
		if (new_fd == -1) {
			perror("accept");
			continue;
		}

		inet_ntop(their_addr.ss_family,
			get_in_addr((struct sockaddr *)&their_addr),
			s, sizeof s);
		printf("server: got connection from %s\n", s);

		if (!fork()) { // this is the child process
			close(sockfd); // child doesn't need the listener
			if (send(new_fd, "Hello, world!", 13, 0) == -1)
				perror("send");
			close(new_fd);
			exit(0);
		}
		close(new_fd);  // parent doesn't need this
	}

	return 0;
}
// blockchain socket + network name + netaddr
int blo_interface( struct a_ibna *ibna ) {
	char *__argvs[3] = { "/home/kj/go/bin/geth" , "attach" , NULL };

	execve( "/home/kj/go/bin/geth" , __argvs , NULL );
}


// delegate
nai native_interface( int level ) {

	nai __;
	memset( &__ , 0 , sizeof( __ ) );

	int _res = -1;

	switch ( level ) {
		case 0: _res = uni_interface( &__.n_uni ); break;
		case 1: _res = loc_interface( &__.n_loc ); break;
		case 2: _res = glo_interface( &__.n_glo ); break;
		case 3: _res = blo_interface( &__.n_blo ); break;
		default: break; 
	}
	return __;
}


#ifndef native_address
#include "../hbar/hbar.h"
char const *native_address( int level ) {
	int res = -1;
	nai __;
	memset( &__ , 0 , sizeof( __ ) );
	switch ( level ) {
		case 0: 
			res = uni_interface( &__.n_uni );
			if ( res >= 0 ) {
				return hbar( level , &__.n_uni , sizeof( struct a_inmp ) );
			}
			break;
		case 1: 
			res = loc_interface( &__.n_loc ); 
			if ( res >= 0 ) {
				return hbar( level , &__.n_loc , sizeof( struct a_isok ) );
			}
			break;
		case 2: 
			res = glo_interface( &__.n_glo );
			if ( res >= 0 ) {
				return hbar( level , &__.n_glo , sizeof( struct a_idns ) );
			}
			break;
		case 3: 
			res = blo_interface( &__.n_blo ); 
			if ( res >= 0 ) {
				return hbar( level , &__.n_blo , sizeof( struct a_ibna ) );
			}
			break;
		default: 
			break; 
	}
	return NULL;
}
#endif