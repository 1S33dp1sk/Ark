#ifndef PATH
	#define PATH( __ather__ ) __PATH( __ather__ )
    #define PATH_LENGTH 201
    #define LES__DELIM "•"
    #define MOR__DELIM "·"
	#define NODE__BASE "@pub."
    #define _pubHDIR "@/pub/"
    #define _pvtHDIR "@/.private/"
    #define __HDIR "/@" //home dir
	#define __ATHDIR "/@"
    #define __HFILE ".ather" //hidden file
	#define __HFILE_PATH "/.ather"


int _pathify( Ather *_ );
int _lestyle( Type _type , char *str , char *savestr );

int __PATH( Ather *_ ) {
	int __ = 0;
	Path *path = _ -> _path;
    if ( getcwd( path -> __main , sizeof( path -> __main ) ) != NULL ) {
    	_ -> _type = NO_SPEC;
        if ( strstr( path -> __main , __HDIR ) != NULL ) {
			_ -> _type = MOR_PUB;
			strcpy( path -> __home , __HDIR );
        	if ( strstr( path -> __main , _pvtHDIR ) != NULL ) {
				_ -> _type = LES_PVT;
				strcpy( path -> __home , _pvtHDIR );
			}
			else if ( strstr( path -> __main , _pubHDIR ) != NULL ) {
        		_ -> _type = LES_PUB; 
        		strcpy( path -> __home , _pubHDIR );
			}
			return _pathify( _ );
        }
        else {
            printf( NO_DEF , __HFILE , path -> __main );
            _ -> _vecf -> flagged = 1;
            return 1;
        }
    }
    return 2; 
}

int __dirdata( char *__dirname );

int _pathify( Ather *_ ) {
	char *temp , *_ptr = ( _ -> _path -> __main );
	int _length = strlen( _ptr );
	int __len = 0, __FLAG = 0;
	while ( _length > 0 ) {
		temp = ( char * )( &_ptr[_length] );
		if ( strstr( temp , _ -> _path -> __home ) != NULL && __FLAG == 0 ) {
			__len = strlen( temp );
			_lestyle( _ -> _type , temp , _ -> _path -> __name );
			__FLAG = 1;
		}
		if ( __FLAG == 1 ) {
			strcpy( _ -> _path -> __wd , (&_ptr[strlen( _ptr )-_length]) );
			__FLAG = 2;
		}
		if ( strstr( temp , __HDIR ) == NULL && __FLAG == 2 ){
			break;
		}
		_length--;
	}
	strncat( _ -> _path -> __pub , _ptr , strlen( _ptr ) - strlen( temp ) );
	temp = _ -> _path -> __pub;
	temp[strlen( temp )] = '@';
	if ( __dirdata( temp ) != 0 ) {
		memset( _ -> _path -> __pub, 0, strlen( temp ) );
	}
	return 1;
}

int _lestyle( Type _type , char *str , char *savestr ) {
    int _iter = strlen( str );
    int _ = 1 , __ = 0;
    while ( _ < _iter  ) {
        if ( str[_] == '/' ) {
            if ( __ >= 0 && savestr[__ - 1] != '.' ){
            	savestr[__] = '.';
            	// strcat( savestr , "#" );
                __++;
            }
        }
        else if ( str[_] != '.' ) {
            savestr[__] = str[_];
            __++;
        }
        _++;
    }
    return 0;
}





#endif