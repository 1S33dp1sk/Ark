#ifndef ather
	#define ather( argc , argv ) main( argc , argv )
	#include "helpers.h"

int _lestyle( Type _type , char *str , char *savestr );
int __connc( Ather *_ );
int __call( Ather *_ );
int __find( Ather *_ );
int __file( Ather *_ );
int __path( Ather *_ );
int __hdir( Ather *_ );
int __FCEV( Ather *_ );
int ather_exec( Ather *_ , FileData node_file );


int __connc( Ather *_ ) {

	return CONNC( _ );
}

int __call( Ather *_ ) {


	return 0;
}

int __find( Ather *_ ) {
	/**
	 * this is a Tri/ternary state operator
	 * and it has a Tru state.
	 * 
	 * `PATH()` will only be the same as `_flag`
	 * if the full first while loop passes
	 * 
	 * the idea of a Tru state is hidden in the 
	 * 
	 * optional return as a `1 : 1` will only run it ONCE
	 * optional return as a `1 : 0` will run RECURSIVE
	 * 
	 * NOTE :: utilizing this technique is critical when thinking ternary
	 * due to the fact that wrapping context is just as important as 
	 * unwrapping. in ather this is morles.
	 * 
	 * 
	 * MUST @params `_flag = 0?`
	 * 
	 * `PATH( _ ) == _flag ? 0 : 0` <-- worth playing around with 
	 * 
	 *  
	 */
	return PATH( _ ) == _ -> _vecf -> flagged ? 1 : 1; 
}

int __FCEV( Ather *_ ) {
	if ( _ -> _vecf != 0 ) {
		printf("no fcev");
		return 1;
	}

	Path path = {0};
	_ -> _path = &path;
	__PATH( _ );
	// log_path_debug( _ -> _path );

	Connc connc = {0};
	_ -> _connc = &connc;
	__CONNC( _ );
	// log_connc_debug( _ -> _connc );

	Call call = {0};
	_ -> _call = &call;

	Entry entry = {0};
	_ -> _entry = &entry;

	Vecf vecf = {0};
	_ -> _vecf = &vecf;
	return 0;
}

int __file( Ather *_ ) {
	int __ = 0;
	FileData filedata = {0};
	_ -> _wrap = &filedata;
	strcpy( filedata.__name , __HFILE );
	if ( !__fdata( __HFILE ) ) {
		if ( !_file_contents( &filedata ) ) {
			if ( __ = _file_hash( &filedata ) == 0 ) {
				_log_file_data( &filedata );
				_ -> _vecf -> found__ = 1;
				return 0;
			}
		}
		printf( ".ather" , "malformed contents\n" );
		return 2;
	}
	return __hdir( _ );
}

int __hdir( Ather *_ ) {
	printf(". :: no ather file found.\n");
	return 2;
}

void __FCEV__ATHER__( Ather *_ ) {

	__FCEV( _ );
}

int ___( Ather *_ ) {
	// Tru ::: Tri
	Vecf *__ = _ -> _vecf;
	while ( __find( _ ) && !__ -> found__ ) {
		while ( __connc( _ ) || __call( _ ) ) {
			break;
		}
		break;
	}
	return 0;
}

int Tri( Ather *_ ) {
	printf("%x ::  \n" , _ -> __ref__ );
	// printf("main:%s\n", _ -> _path -> __main );
	// printf("name:%s\n", _ -> _path -> __name );
	// printf("home:%s\n", _ -> _path -> __home );
}

int _path_exists( Path *path , uint32_t __ref_hash__ ) {
	Connc connc = {0};
	strcat( path -> __pub , (&_pubHDIR[1]));
	__all( path -> __pub , &connc );
	for ( int i=0; i<connc.num__dirs; i++ ) {
		char *dir_name = malloc( MAX_STR * sizeof( char ) );
		strcpy( dir_name , NODE__BASE );
		strncat( dir_name , connc.__dirs[i] , 200 );
		if ( super_fast_hash( dir_name , strlen( dir_name ) ) == __ref_hash__ ) {
			strcpy( path -> __node , connc.__dirs[i] );
			return 0;
		}
	}
	return 1;
}

int ather_path( Ather *_ , char *node ) {
	char at = ( char )( node[0]);
	if ( at != '@' ) {
		printf( NO_DEF , "ather path" , "must start with @" );
		return 0;
	}
	if ( ( _ -> _path -> __pub )[0] == '\0' ) {
		printf( NO_DEF , "ather pub" , "no pub found" );
		return 0;
	}
	if ( _path_exists( _ -> _path , _ -> __ref__ ) != 0 ){
		printf( NO_DEF , "ather path" , "node does not exist" );
		return 0;
	}

	printf("%s :: %x :: \n" , node , _ -> __ref__ );
	return 1;
}




int ather_connc( Ather *_ , char *node ) {
	if ( ather_path( _ , node ) != 1 ) {
		printf( NO_DEF , "ather path" , "cannot determine path" );
		return 2;
	}
	char *full_path = malloc( MAX_LEN * sizeof( char ) );
	strcpy( full_path , _ -> _path -> __pub );
	strcat( full_path , _ -> _path -> __node );
	strcat( full_path , __HFILE_PATH );

	FileData filedata = {0};
	int file_main = _file_exists( full_path , &filedata );
	if ( file_main != 0 ) {
		printf( NO_DEF , "connc file" , "no contents found" );
		return 2;
	}

	return ather_exec( _ , filedata );
}




/**
 * sfh( elems.__path ) MUST equal sfh( _ -> __node__ )
 */

int ather_exec( Ather *_ , FileData node_file ) {
	Elems elems = {0};
	_get_elements( &elems , node_file.__contents );
	log_elements_debug( &elems );
}




int __CMD__ATHER__( Ather *_ ) {
	char *__cmd = _ -> __args__[0];
	switch ( super_fast_hash( __cmd , strlen( __cmd ) ) ) {
		case CMD__LES:
			return LES( _ );
		case CMD__MOR:
			return MOR( _ );
		case CMD__CALL:
			// __file( _ );
			__cmd = _ -> __args__[1];
			_ -> __ref__ = super_fast_hash( __cmd , strlen( __cmd ) ); 
			ather_connc( _ , __cmd );
			break;
		case CMD__CONNC:
			printf("todo :: ");
			break;
		case CMD__ENTRY:
			printf("todo :: ");
			break;
		case CMD__PATH:
		default:
			_ -> __ref__ = super_fast_hash( __cmd , strlen( __cmd ) ); 
			ather_path( _ , __cmd );
			return 0;
	}
	return 0;
}



int main( int argc , char const *argv[] )  {
	// Ather ather = {0};
	// ather.__name__ = ( char * ) argv[0];
	// __FCEV( &ather );
	// if ( argc > 1 ) { 
	// 	ather.__args__ = ( char ** ) ( argv + 1 ); 
	// 	return __CMD__ATHER__( &ather );
	// }
	
	printf("\n\n\n%d\n\n\n" , INET6_ADDRSTRLEN );
	

	// // __FCEV__ATHER__( &ather );
	return 0;
}

#endif
