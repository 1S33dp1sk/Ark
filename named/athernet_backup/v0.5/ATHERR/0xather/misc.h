#define DEBUG
// printf
#include <stdio.h>
// getwd
#include <unistd.h>
// malloc
#include <stdlib.h>
// PATH_MAX
#include <limits.h>



// mkfifo
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
// sha3 context + hash
#include "@source/sha3.h"

// strncat
#include <string.h>

#define no_ather NULL

#define ather_0 "atomic"
#define ath_0 "@"

#define ather_1 "local"
#define ath_1 "."

#define ather_2 "global"
#define ath_2 "/"

#define ather_3 "truis"
#define ath_3 "x"

char *lbb_t_name( int a_type , char *a_typename ) {
	switch ( a_type ) {
		case 0 : if ( a_typename != NULL ) { strcat( a_typename , ather_0 ); } return ather_0;
		case 1 : if ( a_typename != NULL ) { strcat( a_typename , ather_1 ); } return ather_1;
		case 2 : if ( a_typename != NULL ) { strcat( a_typename , ather_2 ); } return ather_2;
		case 3 : if ( a_typename != NULL ) { strcat( a_typename , ather_3 ); } return ather_3;
		default : return no_ather;
	}
}

void lbb_t_signature( int e_count , int a_type , char *a_name , char *a_args , char *lbb_hash , char *a_signature ) {
	sprintf( a_signature , "%s :: %d@%s" , a_name , e_count , lbb_t_name( a_type , NULL ) );
	strcat( a_signature , "\n( " );
	strcat( a_signature , a_args );
	strcat( a_signature , " )\n{ #");
	strcat( a_signature , lbb_hash );
	strcat( a_signature , " }\n");
	printf( "\n ---> \n%s\n <---\n" , a_signature );
}

int isnegative( int v ) {
	return v < 0;
}

int ispostive( int v ) {
	return v > 0 ? v : 0;
}

int iszero( int v ) {
	return v == 0;
}

int isnull( char *v ) {
	return v == NULL;
}

int getpath( char *path ) {
	return isnull( getcwd( path , PATH_MAX ) );
}

int ispathempty( char *path , struct stat *estat ) {
	return isnegative( stat( path , estat ) );
}

int ispathfull( char *path , struct stat *estat ) {
	return ispostive( stat( path , estat ) );
}

int eopen( char *path , uint pdescriptor ) {
	return ispostive( ( pdescriptor = open( path , O_RDWR ) ) );
}

void pathcat( char *path , char *ename ) {
	int idx = 0 , path_len = strlen( path ) , ename_len = strlen( ename );
	if ( path[path_len-1] != '/' ) {
		strncat( &(path[path_len])  , "/\0" , 2 );
	}
	strncat( path , ename , ename_len );
}

void addextention( char *ename , char *extention ) {
	int _ = strlen( ename ) , __ = strlen( extention );
	if ( _ > 0 && __ > 0 ) {
		strncat( ename , extention , __ );
	}
}