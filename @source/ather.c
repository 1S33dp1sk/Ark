<<<<<<< HEAD
#include "probe.h"
#include "point/point.h"
<<<<<<< HEAD
<<<<<<< HEAD
#include "lbb/lbb.h"
#include "hbar/hbar.h"
#include "nai/nai.h"
=======

>>>>>>> 757e790 (shared library for point)
=======
#include "lbb/lbb.h"
#include "hbar/hbar.h"
#include "nai/nai.h"
>>>>>>> 96d62a9 (created a dynamic shared library resulting in ./shared/* .o files)


int main( int argc , char **argv ) {

<<<<<<< HEAD
<<<<<<< HEAD
	union __nai __;

	int res = nai( argv[1][0] - '0' , __ );
=======
	unsigned lvl = 0;

	atherpoint( emp , lvl );



>>>>>>> 757e790 (shared library for point)
=======
	union __nai __;

<<<<<<< HEAD
	int res = nai( 0 , __ );
>>>>>>> 96d62a9 (created a dynamic shared library resulting in ./shared/* .o files)
=======
	int res = nai( argv[1][0] - '0' , __ );
>>>>>>> bb7010d (added sockets for nai=1,2 && added execve for nai=3)

}
=======
/***
 * Mr. Karam.J :
 * 		However, as for ather, when talking about the interfacing provided
 * it is quite simple in a sense.
 * 0 -> ather
 * 1 -> operating sys(linux,macOS,Win{32,64},POSIX-complaint) or any other
 * 2 -> Apache or any other
 * 3 -> ethereum or any other
 * Any peer on 0xather is always aware and in total control of everything that is happening
 * to the system as a whole, however the ather is i-defined; user-defined.
 * Thus, @home is different:
 *  for each 
 * 	1.	person(unique phone,ethereum address,... for example)/ 
 * 	2.	each group of people(unique LAN)/ 
 * 	3.	each collection of groups(unique sub_net)
 * 	4.  each (global ip) 
 * 	5.  each protocol type  
 * @ protocol includes the different machine processes that are
 * being run, including a fantastic signature creating mechanism.
 * that combines any or all the above to form uniqueness which is coupled by a `c struct`
 * enable the protocol to call sockets, open/close files, interrupt processes, process scripts, run shells, etc...
 * 
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
	#include <unistd.h>
#endif
	if ( getcwd( p1 -> ia_path , sizeof( p1 -> ia_path ) ) != NULL ) {
		return 0;
	}
	return 2;
}

int __1sh( _ia_p1 *p1 ) {
#ifndef getpwuid
	#include <pwd.h>
#endif
	struct passwd *p = getpwuid( getuid() );
	memcpy( p1 -> ia_shell , p -> pw_shell , strlen( p -> pw_shell ) );
	return 0;
}

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


>>>>>>> eb99d6a (0xather)
