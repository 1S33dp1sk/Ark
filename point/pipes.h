// pipefd[0] -> read
// pipefd[1] -> write
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdint.h>

int e_out( char *e_message , int e_return , ... ) {
	printf( "E -> %s\n" , e_message );
	return e_return;
}

typedef struct {
	unsigned int __rfd;
	unsigned int __wfd;
	uint8_t __hfd;
} _rwd; // file descriptors

typedef struct {
	pid_t __ppd;
	pid_t __cpd;
} _psd; // process descriptors

typedef struct {
	_psd pr;
#define p_pid pr.__ppd;
#define c_pid pr.__cpd;
	_rwd io;
#define rfd io.__rfd;
#define wfd io.__wfd;
#define hash io.__hfd;
} descriptor;





int pipes( int argc , char **argv ) {
	int __pfd[2];
	pid_t __cpid;
	char __buf;


	if ( argc != 2 ) {
		return e_out( "usage :: (@ call)", -1 );
	}

	if ( pipe( __pfd ) == -1 ) {
		return e_out( "pipe cannot be created", -2 );
	}

	if ( ( __cpid = fork() ) == -1 ) {
		return e_out( "cannot fork process" , -3 );
	}

	if ( __cpid == 0 ) {
		close( __pfd[1] ); // close the write end of pipe
		while( read( __pfd[0] , &__buf , 1 ) > 0 ) {
			write( STDOUT_FILENO , &__buf , 1 );
		}
		write( STDOUT_FILENO , "\n" , 1 );
		close( __pfd[0] );
		return 0;
	}
	else {
		close( __pfd[0] ); // close the read end of the pipe
		write( __pfd[1] , argv[1] , strlen( argv[1] ) );
		close( __pfd[1] ); // reader will see EOF
		wait( NULL );
		return 0;
	}
}