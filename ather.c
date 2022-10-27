<<<<<<< HEAD
/***
 * Mr. Karam.J :
***/ 


#include "common.h"
#include "morles/protocol.h"
#define INTRO__A "\n\tWelcome to ather ( a.k.a @-Protocol )\n"
#define SYMB__NN '@'
#define ENTER__NN "enter( » )nodename :: @"
#define SCAN__NN "%s"
static char __udef_nodename[MAX_STR];
#include "iota.h"
#include "lbb/little_black_book.h"
#include <unistd.h>
#include <pwd.h>






// int main( int argc , char *argv[] ) {
// /**
//  * mrkj, 2022 Sept.27
//  * lbb full implementation with sha3, thanks to the 
//  * good people at crypto@brainhub.org for their work
//  * on the sha3 implementation that is used here.
//  */
// 	sx_lbb lbb;
// 	memset( &lbb , 0 , sizeof( lbb ) );
// 	unsigned int __ = __lbb__( &lbb );
// 	if ( __ > 0 ) {
// 		if ( argc > 1 && check_lbb( &lbb , argv[1] ) != 0 ) {
// 			if ( argc == 3 ) {
// 				if ( lbb_add( &lbb , argv[2] ) == 0 ) {
// 					//
// 				}
// 			}
// 			else if ( argc > 1 ) {
// 				lbb_query( &lbb );
// 			}
// 		}
// 		__cleanup( &lbb );
// 		return 0;
// 	}
// 	write( 0 , "cannot create •lbb\n" , 21 );
// 	return 1;
// }


void __intro( char *__nodename ) {
	int __ = 0;
	char __nn[MAX_STR] = {0};
	__nn[0] = SYMB__NN;
	write( 0 , INTRO__A , strlen( INTRO__A ) );
	write( 0 , ENTER__NN , strlen( ENTER__NN ) );
	__ = read( 0 , &__nn , MAX_STR - 1 );
	if ( __ > 0 ) {
		memcpy( __nodename , __nn , strlen( __nn ) - 1 );
		memcpy( __udef_nodename , __nn , strlen( __nn ) - 1 );
	}
}

void __0pid( _ia_p0 *p0 ) {
	p0 -> ia_pid = getpid();
}

void log_p0( _ia_p0 *p0 ) {
	printf( "PID :: %d\n" , p0 -> ia_pid );
	printf( "NODE :: %s\n" , p0 -> ia_name );
}

void log_p1( _ia_p1 *p1 ) {
	printf( "PATH :: %s\n" , p1 -> ia_path );
	printf( "SHELL :: %s\n" , p1 -> ia_shell );
}

int __1cwd( _ia_p1 *p1 ) {
#ifndef getcwd
#endif
	if ( getcwd( p1 -> ia_path , sizeof( p1 -> ia_path ) ) != NULL ) {
		return 0;
	}
	return 2;
}

int __1sh( _ia_p1 *p1 ) {
#ifndef getpwuid
#endif
	struct passwd *p = getpwuid( getuid() );
	memcpy( p1 -> ia_shell , p -> pw_shell , strlen( p -> pw_shell ) );
	return 0;
}

#define PATH__NAME "PATH"
#define CONNC__NAME "CONNC"
#define CALL__NAME "CALL"
#define ENTRY__NAME "ENTRY"
#define PUBK__NAME "ADDR"
#define CONF__NAME "CONF"


const static char ATTRIBUTES[6][10] = { 
	PATH__NAME , 
	CONNC__NAME , 
	CALL__NAME , 
	ENTRY__NAME , 
	PUBK__NAME , 
	CONF__NAME
};



// Basic aether execution 
#define _AETHER_ ".aether"
#define AETHER_HOME ".aether/"
#define AETHER__NAME "Aether"
#define STRING_BUFFER 100
#define AETHER_FILE_BUFFER 1000
#define AETHER_REPLY_MAX 2000
#define ATTIBUTE_BUFFER 10
#define NULL_PTR NULL
#define HASH_LEN 33


// LOGGING
#define AETHER_ENTRY "\t\t\t->\033[38;2;66;5;240m%s\n\n\tcontents\n"
#define AETHER_THREADS_NUM "\t\033[38;2;66;5;240m->\033[0;37m%d\n"
#define AETHER_SIG "\t\t\t\033[0;37mAether\n"
#define AETHER_PATH "\n\033[38;2;66;5;240mAether\e[0;37m- %s\n"
#define AETHER_F_EXEC "\n\033[38;2;255;215;50mAether\e[0;37m> %s \033[38;2;115;115;115m//%x\n"
#define AETHER_EXEC "\n\033[38;2;255;215;50mAether\e[0;37m> %s\n"
#define AETHER_LINE "\n\033[38;2;84;84;84mAether\e[0;37m :: %s\n"
#define AETHER_ERROR "\n\033[38;2;178;34;34mAETHER\e[0;37m : %s -> %s\n"
#define AETHER_LES "\n\033[38;2;84;84;84mAether\033[0;37m : L E S -> \n"
#define AETHER_LISTEN "\n\033[38;2;84;84;84mAether\e[0;37m :: listen : .aether : %d,-> \n%s\n"
#define AETHER_EVALUATE "\n\033[38;2;84;84;84mAether\e[0;37m :: evaluate :\n\n--->\n%s\n<---\n"
#define AETHER_SEND "\n\033[38;2;84;84;84mAether\e[0;37m :: send : %d\n"

int main( int argc , char **argv ) {
	// 0
	// the iota here is just the 
	// nodename && the current pid 
	_ia_p0 p0 = {0};
	memset( &p0 , 0 , sizeof( _ia_p0 ) );
	__intro( p0.ia_name );
	__0pid( &p0 );
	log_p0( &p0 );


	sx_lbb lbb;
	memset( &lbb , 0 , sizeof( lbb ) );
	if ( ( lbb.__lbb = __lbb__( &lbb ) ) > 0 ) {
		// printf("\n");
		ather_les( __udef_nodename );
	}else{
		printf("@");
	}

	// // 1
	// // the iota here is just the
	// // path && the shell
	// _ia_p1 p1 = {0};
	// memset( &p1 , 0 , sizeof( _ia_p1 ) );
	// if ( __1cwd( &p1 ) ) {
	// 	return 2;
	// }

	// if ( __1sh( &p1 ) ) {
	// 	return 2;
	// }

	// log_p1( &p1 );


	// 2
	// the iota here is just the
	// ip+socket && the request
	

	// int rv;
	// struct addrinfo hints , *les_info;
	// memset( &hints , 0 , sizeof( hints ) );
	// hints.ai_family = AF_UNSPEC;
	// hints.ai_socktype = SOCK_STREAM;


	// rv = getaddrinfo( "127.0.0.1" , "9999" , &hints , &les_info );

	// if ( rv == -1 ) {
	// 	printf( "Socket/Port is busy." );
	// 	return 2;
	// }

	// printf( "\nres of rv :: %d\n" , rv );

	// struct addrinfo *_iter;
	// for ( _iter = les_info ; _iter != NULL ; _iter = les_info -> ai_next ){
	// 	printf( " :: %d\n" , _iter -> ai_addrlen );
	// }

	// freeaddrinfo( les_info );


	// if ( argc == 3 ) {
	// 	#ifndef AtherX
	// 		#include "xather.h"
	// 	#endif
	// 	_xather__( argv[1] , &*(&argv[2]) );
	// }
	// else {
	// 	#ifndef AtherShell
	// 		#include "shell.h"
	// 	#endif
	// 	ather_shell();
	// }
}
=======
>>>>>>> 58c0c04 (a few changes here&there)


