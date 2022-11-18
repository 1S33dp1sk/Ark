#include "nai.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdint.h>
#include <sys/socket.h>
#include <string.h>

/**
 * ERRORS 
 * 
 * 1 :: cannot get current working dir
 * 2 :: os path too long
 * 3 :: lbb cannot be `access`ed()
 * 4 :: no atherpoint found
 */

char *__path_unix( char *__path , char *__filename ) {
    int path_len = strlen( __path ) - 1 , fname_len = strlen( __filename ) - 1;
    if ( __path[path_len] != '/' && __filename[0] != '/' ) {
        strncat( __path , "/\0" , 2 );
    }
    return ( path_len + fname_len ) < mpath_max ? strcat( __path , __filename ) : NULL;
}

// node number : point
// mount path : lbb
int uni_interface( struct a_inmp *inmp ) {

	struct stat __st;
	char *path = inmp -> imp;
	// zero the initial path
	char __path[mpath_max];
	memset( __path , 0 , mpath_max );
	// get the current working dir
	if ( getcwd( __path , mpath_max ) == NULL ) {
		printf( "cannot get working dir\n" );
		return 1;
	}
	// re-zero the `mp`
	memset( path , 0 , mpath_max );
	// copy the path to struct element
	memcpy( path , __path , strlen( __path ) );
	// add the `.lbb` name to the path
	if ( __path_unix( path , ".lbb" ) == NULL ) {
		printf( "path too long\n" );
		return 2;
	}
	// check calling process permissions
	// for constructed path to lbb
	if ( access( path , F_OK|R_OK ) != 0 ) {
		printf( "lbb cannot be accessed\n" );
		return 3;
	}
	// attach `atherpoint` to the directory path
	if ( __path_unix( __path , "atherpoint" ) == NULL ) {
		printf( "path too long\n" );
		return 2;
	}
	// call the FIFO `stat` to retreive `inn`
	if ( stat( __path , &__st ) == -1 ) {
		printf( "atherpoint cannot be accessed\n" );
		return 4;
	}
	// get the inodenum from the struct `stat`
	// and add the value to `inmp`
	inmp -> inn = __st.st_ino;

	return 0;
}

void log_uni( struct a_inmp n_uni ) {
	printf( "native ather interface\n" );
	printf( "	universal	\n" );
	printf( "inode num::		%ju\n" , ( uintmax_t ) n_uni.inn );
	printf( "mount path::		%s\n" , n_uni.imp );
}

int atherinterface( int level , ani __ ) {

	int res = uni_interface( &__.n_uni );

	log_uni( __.n_uni );


	return 0;
}