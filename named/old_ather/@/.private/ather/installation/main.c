#include <unistd.h>
#include <pwd.h>
#include <string.h>
#include <sys/types.h>
#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h> 
#include <netdb.h>
#include<sys/stat.h>


#define WELCOME "\n\tWelcome to •xather—\n\t  The @ protocol\n\n"
#define __HDIR "/@" //home dir
#define MAX_STR 201


typedef struct {
	unsigned char __user[MAX_STR];
	unsigned char __home[MAX_STR];
	unsigned char __ip[INET6_ADDRSTRLEN];
} Instancified;

int __dirdata( char *__dirname ) {
    struct stat st;
    if ( stat( __dirname , &st ) == 0 ) {
    	printf( "@ directory found.\n" );
        return 0;    
    }
	printf( "No @ directory (i.e: folder) was found.\n » Would you like to initiate an ather dir ? \n" );	
	mkdir( __dirname , 0700 );
	return 0;
}

void __homedir( char *__ ) {
	struct passwd *pw = getpwuid( getuid() );
	memcpy( __ , pw -> pw_dir , strlen( pw -> pw_dir ) );
	__ += strlen( pw -> pw_dir );
	memcpy( __ , "/@\0" , 3 );
}


int main( void ) {
	Instancified __ = {0};
	
	printf( WELCOME );
	__homedir( __.__home );

	if ( __dirdata(__.__home) != 0 ) {
		return 1;
	}
	

	return 0;
}