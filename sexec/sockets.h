/*  
    @-PROTOCOL  
     #Morles
                */ 
#ifndef AtherProtocol
    #define AtherProtocol "@protocol"
    #define AtherMor "@mor"
    #define AtherLes "@les"
    #define PORT_ACCEPT "9999"
    #define BACKLOG 10
    #define MAX_STR 256
    #define MAX_A_LEN 0xffff;
    #define SELECTOR_BYTES 8   
    #define PROTOCOL_STYLE "axA-E@N#A{E}"
    #define PROTOCOL_LINE "aAedNME\0"
    #define ATHER_SERVICE "0xather"
    #include <sys/types.h>
    #include <sys/socket.h>
    #include <string.h>
    #include <stdarg.h>
    #include <stdlib.h>
    #include <sys/wait.h>
    #include <signal.h>
    #include <netdb.h>
    #include <arpa/inet.h> 
    #include <netinet/in.h>
    #include <errno.h>
    #include <poll.h>
	#include<pthread.h> //for threading , link with lpthread

    #define MOR( __ather__ ) __MOR( __ather__ )
    #define LES( __ather__ ) __LES( __ather__ )

    #define pathify( node , serv , __typeproto , __override , ... ) \
        __pathify( node , serv , ( ( typeproto * ) __typeproto  ) , __override , ##__VA_ARGS__ )

    static const char protocol_example[49] = "3xather-pub*\\1@4k#default\\{#}";

	int les( int argc , char **argv );
	int mirror( char *_aether );
	int get_listener_socket( void );
    int __I( unsigned char *__ , unsigned long long int _ , unsigned int b );
    unsigned long long int __R( unsigned char *__ , unsigned int _ ,unsigned int b);
	void *evaluate( void *);


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

    int get_listener_socket( void ) {
        int _listener;
        int yes=1;
        int rv;
        struct addrinfo hints, *les_info, *p;
        memset( &hints , 0 , sizeof hints );
        hints.ai_family = AF_UNSPEC;
        hints.ai_socktype = SOCK_STREAM;
        hints.ai_flags = AI_PASSIVE;

        if ( ( rv = getaddrinfo( NULL , PORT_ACCEPT , &hints , &les_info ) ) != 0 ) {
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

    void add_to_pfds( struct pollfd *pfds[] , int newfd , int *fd_count , int *fd_size ) {
        // check for memory allocation
        if ( *fd_count == *fd_size ) {
            *fd_size += 2;
            *pfds = realloc( *pfds , sizeof( **pfds ) * ( *fd_size ) );
        }
        (*pfds)[*fd_count].fd = newfd;
        (*pfds)[*fd_count].events = POLLIN;
        (*fd_count)++;
    }

    void del_from_pfds( struct pollfd pfds[] , int i , int *fd_count ) {
        pfds[i] = pfds[*fd_count-1];
        (*fd_count)--;
    }

    int LES__( void ) {
        int listener;
        int newfd;
        struct sockaddr_storage remoteaddr;
        socklen_t addrlen;
        char buf[MAX_STR];
        char remoteIP[INET6_ADDRSTRLEN];

        int fd_count = 0;
        int fd_size = 5;
        struct pollfd *pfds = malloc( sizeof *pfds * fd_size );

        listener = get_listener_socket();
        if ( listener == -1 ) {
            fprintf( stderr , "error , ather cannot les.\n" );
            return 2;
        }

        pfds[0].fd = listener;
        pfds[0].events = POLLIN;

        for(;;) {
            int poll_count = poll( pfds , fd_count , -1 );
            if ( poll_count == -1 ) {
                perror("poll");
                return 2;
            }
        }

        for ( int __ = 0; __ < fd_count; __++ ){
            if ( pfds[__].revents & POLLIN ) {

                if ( pfds[__].fd == listener ) {
                    addrlen = sizeof remoteaddr;
                    newfd = accept( listener , ( struct sockaddr *)&remoteaddr , &addrlen );
                    if ( newfd == -1 ){
                        perror("accept");
                    }
                    else {
                        add_to_pfds( &pfds , newfd , &fd_count , &fd_size );
                        printf( "Evaluate:: new connection from %s on #%d\n" , 
                            inet_ntop( remoteaddr.ss_family 
                            , get_in_addr( (struct sockaddr*)&remoteaddr), remoteIP , INET6_ADDRSTRLEN )
                            , newfd );
                    }
                }
                else {
                    int nBytes = recv( pfds[__].fd , buf , sizeof buf , 0 );
                    int sender_fd = pfds[__].fd;

                    if ( nBytes <= 0 ) {
                        if ( nBytes == 0 ){ 
                            printf( "Termination on #%d" , sender_fd );
                        }
                        else {
                            perror("recv");
                        }

                        close( pfds[__].fd );
                        del_from_pfds( pfds , __ , &fd_count );
                    }
                    else {
                        for ( int k = 0; k < fd_count; k++ ) {
                            int dest_fd = pfds[k].fd;
                            if ( dest_fd != listener && dest_fd != sender_fd ) {
                                if ( send( dest_fd , buf , nBytes , 0 ) == -1 ) {
                                    perror( "send" );
                                }
                            }
                        }
                    }
                }
            }
        }
        return 0;
    }

    void sig_chld_handler( int __signal ) {
        int saved_errno = errno;

        while ( waitpid( -1 , NULL , WNOHANG ) > 0 );

        errno = saved_errno;
    }
	
	int get_listener_socket( void ) {
	    int _listener;
	    int yes=1;
	    int rv;
	    struct addrinfo hints, *les_info, *p;
	    memset( &hints , 0 , sizeof hints );
	    hints.ai_family = AF_UNSPEC;
	    hints.ai_socktype = SOCK_STREAM;
	    hints.ai_flags = AI_PASSIVE;

	    if ( ( rv = getaddrinfo( NULL , PORT_ACCEPT , &hints , &les_info ) ) != 0 ) {
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

	int mirror( char *_aether ) {
		int _socket;
		struct sockaddr_in server;
		int __temp;
		char __reply[AETHER_REPLY_MAX];
		// char *message = "\nPATH:=\nCONNC:=\nCALL:=\nENTRY{ }\n\r\0";

		_socket = socket( AF_INET , SOCK_STREAM , 0 );
		if ( _socket < 0 ) {
			printf( AETHER_ERROR , "mor :: mirror" , "Socket init failed" );
			return 2;
		}

		server.sin_family = AF_INET;
		server.sin_addr.s_addr = inet_addr("127.0.0.1"); //16777343;
		server.sin_port = htons( 9999 );

		if ( connect( _socket , ( struct sockaddr *) &server , sizeof( server ) ) < 0 ) {
			printf( AETHER_ERROR , "mor :: mirror" , "Socket connection failed" );
			return 2;
		}

		printf( AETHER_SIG );

		if ( send( _socket , _aether , strlen( _aether ) , 0 ) > 0 ) {
			if ( __temp = recv( _socket , __reply , AETHER_REPLY_MAX , 0 ) > 0 ) {
				printf( AETHER_EXEC , __reply );
			}
		}
		printf( AETHER_SIG );
		close( _socket );
		return 0;
	}

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

    int __LES( Ather *_ ) {

        int sockfd , new_fd;
        struct addrinfo hints, *les_info, *p;
        struct sockaddr_storage mor_addr;
        socklen_t sin_size;
        struct sigaction sa;
        int yes = 1;
        char s[INET6_ADDRSTRLEN];
        int rv;

        memset( &hints , 0 , sizeof hints );

        hints.ai_family = AF_UNSPEC;
        hints.ai_socktype = SOCK_STREAM;
        hints.ai_flags = AI_PASSIVE;


        if ( ( rv = getaddrinfo( NULL , PORT_ACCEPT , &hints , &les_info ) ) != 0 ) {
            fprintf( stderr , " getaddr info : %s\n" , gai_strerror( rv ) );
            return 1;
        }


        for ( p = les_info; p != NULL; p = p -> ai_next ) {
            if ( ( sockfd = socket( p -> ai_family , p -> ai_socktype , p -> ai_protocol ) ) == -1 ) {
                perror( "les •socket [\u2716]" );
                continue;
            }

            if ( setsockopt( sockfd , SOL_SOCKET , SO_REUSEADDR , &yes , sizeof( int ) ) == -1 ) {
                perror( "les •setsockopt [\u2716]" );
                exit( 1 );
            }

            if ( bind( sockfd , p -> ai_addr , p -> ai_addrlen ) == -1 ) {
                close( sockfd );
                perror( "les •active dir [\u2716]" );
                continue;
            }

            break;
        }


        freeaddrinfo( les_info );

        if ( p == NULL ) {
            fprintf( stderr , "les • [\u2716] —» failed initiating activity\n" );
            exit( 1 );
        }


        if ( listen( sockfd , BACKLOG ) == -1 ) {
            perror( "les •listen [\u2716] —» unable to obtain lingustics" );
            exit( 1 );
        }


        sa.sa_handler = sig_chld_handler;
        sigemptyset( &sa.sa_mask );
        sa.sa_flags = SA_RESTART;

        if ( sigaction( SIGCHLD , &sa , NULL ) == -1 ) {
            perror( "les •sigaction [\u2716]" );
            exit( 1 );
        }


        printf(" les •listening —» \n" );

        while ( 1 ) {
            sin_size = sizeof mor_addr;
            new_fd = accept( sockfd , ( struct sockaddr * )&mor_addr , &sin_size );
            if ( new_fd == -1 ) {
                perror( "les •evaluate [\u2716] —» unable to decipher." );
                return 2;
            }

            inet_ntop( mor_addr.ss_family , get_in_addr( ( struct sockaddr * )&mor_addr ) , s , sizeof s );
            printf( "\n—» les•mor —»\n\t%s\n" , s );

            if ( !fork() ) {
                close( sockfd );
                if ( send( new_fd , "Hello World!" , 13 , 0 ) == -1 ) 
                    perror( "les •sending [\u2716] —» unable to transfer .ather" );             
                close( new_fd );
                exit( 0 );  
            }
            close( new_fd );
        }

        return 0;
    }
    
    int AtherLES( void ) {
        fd_set master;
        fd_set read_fds;
        int fdmax;

        int listener;
        int newfd;
        struct sockaddr_storage remoteaddr;
        socklen_t addrlen;
        char buf[MAX_STR];
        int nBytes;
        char remoteIP[INET6_ADDRSTRLEN];
        int yes=1;
        int i,k,rv;
        struct addrinfo hints, *les_info, *p;

        FD_ZERO( &master );
        FD_ZERO( &read_fds );

        memset( &hints , 0 , sizeof hints );
        hints.ai_family = AF_UNSPEC;
        hints.ai_socktype = SOCK_STREAM;
        hints.ai_flags = AI_PASSIVE;

        if ( ( rv = getaddrinfo( NULL , PORT_ACCEPT , &hints , &les_info ) ) != 0 ) {
            fprintf( stderr , " getaddr info : %s\n" , gai_strerror( rv ) );
            return 1;
        }

        for ( p = les_info; p != NULL; p = p -> ai_next ) {
            listener = socket( p -> ai_family , p -> ai_socktype , p -> ai_protocol );
            if ( listener < 0 ) {
                continue;
            }


            setsockopt( listener , SOL_SOCKET , SO_REUSEADDR , &yes , sizeof( int ) );
            if ( bind( listener , p -> ai_addr , p -> ai_addrlen ) < 0 ) {
                close( listener );
                continue;
            }
            break;
        }

        if ( p == NULL ) {
            fprintf( stderr , "Atherles failed\n" );
            return 2;
        }

        freeaddrinfo( les_info );
        if ( listen( listener , 10 ) == -1 ) {
            perror( "listening failed\n" );
            return 2;
        }

        FD_SET( listener , &master );
        fdmax = listener;

        for ( ;; ) {
            read_fds = master;
            if ( select( fdmax + 1 , &read_fds , NULL , NULL , NULL ) == -1 ) {
                perror("select");
                return 2;
            }

            for ( i = 0; i<=fdmax; i++ ) {
                if ( FD_ISSET( i , &read_fds ) ) {
                    if ( i == listener ) {
                        addrlen = sizeof remoteaddr;
                        newfd = accept( listener , ( struct sockaddr *)&remoteaddr , &addrlen );
                        if ( newfd == -1 ) {
                            perror("accept");
                            continue;
                        }
                        else {
                            FD_SET( newfd , &master );
                            if ( newfd > fdmax ) {
                                fdmax = newfd;
                            }
                            printf("AtherLes :: selected new connection from %s on %d\n\n" 
                                , inet_ntop( remoteaddr.ss_family , get_in_addr((struct sockaddr *)&remoteaddr)
                                    , remoteIP , INET6_ADDRSTRLEN),
                                        newfd);
                        }
                    }
                    else {
                        if ( ( nBytes = recv( i , buf , sizeof buf , 0 ) ) <= 0 ) {
                            if ( nBytes == 0 ) {
                                printf( "Atherles :: %d is out\n" , i );
                            }
                            else {
                                perror("recv");
                            }
                            close(i);
                            FD_CLR( i , &master );
                        }
                        else {
                            for ( k = 0; k <= fdmax; k++ ) {
                                if ( FD_ISSET( k , &master ) ) {
                                    if ( k != listener && k != i ) {
                                        if ( send( k , buf , nBytes , 0 ) == -1 ) {
                                            perror( "send" );
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }

        return 0;
    } 

    int __MOR( Ather *_ ) {

        int sockfd , numbytes;
        char buf[MAX_FILE];
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

        if ( ( numbytes = recv( sockfd , buf , MAX_PROTO - 1 , 0 ) ) == -1 ) {
            perror( "morles » no .ather [\u2716] —» unable to verify .ather" );
            exit( 1 );
        }

        buf[numbytes] = '\0';

        printf( "»\n\t%s\n" , buf );
        close( sockfd );
        return 0;
    }

    int ather_mor( void ) {
        int sockfd , numbytes;
        char buf[1024];
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

        // inet_ntop( p -> ai_family , get_in_addr( ( struct sockaddr * ) p -> ai_addr ) , s , sizeof s );


        printf( "\n—» mor•les —»");
        freeaddrinfo( les_info );
        int tempp =  write( sockfd , "Hello you" , 10 );

        printf("Write :: %d\n\n",  tempp );

        if ( ( numbytes = recv( sockfd , buf , 1024 - 1 , 0 ) ) == -1 ) {
            perror( "morles » no .ather [\u2716] —» unable to verify .ather" );
            exit( 1 );
        }

        buf[numbytes] = '\0';

        printf( "\n\t»%s\n" , buf );
        close( sockfd );
        return 0;
    }   

    int sendall( int s , char *buf , int *len ) {
        int total = 0;        // how many bytes we've sent
        int bytesleft = *len; // how many we have left to send
        int n;
        while( total < *len ) {
            n = send( s , buf+total , bytesleft , 0 );
            if ( n == -1 ) { break; }
            total += n;
            bytesleft -= n;
        }
        *len = total; // return number actually sent here
        return n==-1?-1:0; // return -1 on failure, 0 on success
    }

    unsigned int __write( unsigned int *__fd , char *__fmt , Protocol *p ) {
        unsigned int __size = 0; 
        unsigned int __len = 0;
        unsigned char *__ = calloc( MAX_STR , sizeof( unsigned char ) ); 
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

    int __pathify( char *node__name , char *node__serv , typeproto *__ , int __override , ... ) {

        int __status = 2;
        va_list __vars;

        if ( node__name != NULL || node__serv != NULL ) {

            __ -> node__ = node__name;
            __ -> serv__ = node__serv;


            if ( !__override ) {
                // only accept socket streams
                // no more dgram bs
                __ -> hints__ -> ai_socktype = SOCK_STREAM;
                // adaptive to ip addr len
                __ -> hints__ -> ai_family = A_ANY;
                // check to see if `les` then socket :: <bind,accept>
                if ( __ -> name__ == A_MOR || node__name[0] == '@' || 
                    strcmp( node__serv , ATHER_SERVICE ) == 0 ) {
                    __ -> hints__ -> ai_flags = AI_PASSIVE;
                }
                if ( __ -> name__ == A_LES ) {
                    __ -> hints__ -> ai_flags = 0;
                }
            }
            else {
                va_start( __vars , __override );
                while ( __override > 0 ) {
                    __ -> hints__ = va_arg( __vars , struct addrinfo * );           
                    __override--;
                }
                va_end( __vars );
            }


            if (( __status = getaddrinfo( node__name , node__serv , __ -> hints__ , &(__ -> res__) )) == 0 ){
                __status = 0;
                struct addrinfo *_;
                for ( _ = __ -> res__; _ != NULL; _ = _ -> ai_next ) {
                    void *addr;
                    if ( ( addr = ( __ -> at__ , _ -> ai_addr ) ) != X_NODEF ) {
                        __status = 0;
                    }
                }
                free( __ -> res__ );
            }
            else {
                printf( "__pathify :: %s\n" , gai_strerror( __status ) );
            }
        }

        return __status;
    }

#endif

//refs\\

// 
// linux - #man getaddrinfo
// GNU LICENSE
// getaddrinfo( node , serv , hints , res )
// struct addrinfo {
//    int              ai_flags;
//    int              ai_family;
//    int              ai_socktype;
//    int              ai_protocol;
//    socklen_t        ai_addrlen;
//    struct sockaddr *ai_addr;
//    char            *ai_canonname;
//    struct addrinfo *ai_next;
// };
