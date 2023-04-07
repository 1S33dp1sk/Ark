#ifndef A__PATH
#define A__PATH

#ifndef STRING_BUFFER
#define STRING_BUFFER 100
#endif

#ifndef getcwd
#include "/usr/include/unistd.h"
#endif

#if !defined( strstr ) || !defined( strlen ) || !defined( strtok )
#include "/usr/include/string.h"
#endif

#ifndef malloc
#include "/usr/include/stdlib.h"
#endif

#ifndef _ather_
#define _ather_ ".ather"
#endif

#ifndef __ather__
#define __ather__ "ather"
#endif

#ifndef ATHER_LES_PUB
#define ATHER_LES_PUB "ather/public/" // ather
#endif

#ifndef ATHER_LES_PVT
#define ATHER_LES_PVT "ather/.private" // .ather
#endif

#ifndef ATHER_HOME
#define ATHER_HOME "/ather/"
#endif

#ifndef ATHER_ENTRY
#define ATHER_ENTRY "\t\t\t->\033[38;2;66;5;240m%s\n\tcontents\n"
#endif

#ifndef ATHER_ERROR
#define ATHER_ERROR "\033[38;2;178;34;34mATHER\033[0;37m :: %s [\u2716] -> %s\n"
#endif

#ifndef ATHER_POINTER
#define ATHER_POINTER "\033[38;2;115;115;115m%s\033[0;37m"
#endif


#ifndef CGREY
#define CGREY "\033[38;2;115;115;115m"
#endif


#ifndef ATHER_PEAK
#define ATHER_PEAK_PUBLIC "public·"
#define ATHER_PEAK "·"
#define ATHER_PEAK_IN "·%s"
#define ATHER_PEAK_PRIVATE "•private"
#define _ATHER_PEAK "•"
#define _ATHER_PEAK_IN "•%s"
#define ATHER_PEAK_MOR "·public@"
#define ATHER_PEAK_DIR "—» %s\n"
#define ATHER_PEAK_FILE "·» %s\n"
#define ATHER_PREAK_EXEC "» %s «\n"
#endif

typedef enum
{
    WHITE,
    GREY
} Colors;

#define ptr_log( ... ) fprintf( stdout , "pointer  //%s%s\n" , CGREY , ##__VA_ARGS__ );
#define ath_log( ... ) fprintf( stdout , "@th%s\n\n" ,  ##__VA_ARGS__ );






/**
 * in order to be able to get the full 
 * nav system and build paths correctly 
 * we will utilize the `PATH` structure.
*/

void log_path_debug_verbose( Path *path );
void log_path_debug( Path *path );
char *mixin_path( char *ptr , Path *path );
static int aether_path( Path *path , Type type );

int ather__path( Ather *ather );
int les_style( char *str , char *savestr );
int typed_les_style( Type _type , char *str , char *savestr );
Type __path( Path *path );
void ather_path_log( Ather *ather );
void _type_log( Type _type );



int ather__path( Ather *ather ) {
    Path path = {0};
    ather -> _path = &path;
    ( ather -> _path -> __name ) = malloc( 100 );
    ( ather -> _path -> __main ) = malloc( 100 );
    les_style( ather -> __name__ , ather -> _path -> __name );
    char buffer[STRING_BUFFER] , temp;
    int __ = -1;
    FileData filedata = {0};
    ather -> _wrap = &filedata;
    if ( ( ( ather -> _path -> __main ) = (char *)&buffer )!= NULL ) {
        ather -> _type = __path( &path );
        if ( access( _ather_ , F_OK ) == 0 ) {
            filedata.__name = _ather_;
            if ( __ = _file_contents( &filedata ) == 0 ) {
                if ( __ = _file_hash( &filedata ) != filedata.__name ) {
                    switch( ather -> _type ) {
                        case LES_PUB:
                            ath_log( ATHER_PEAK_PUBLIC );
                            break;
                        case LES_PVT:
                            ath_log( ATHER_PEAK_PRIVATE );
                            break;
                        case MOR:
                            ptr_log( ather -> __name__ );
                            break;
                        default:
                            printf( ATHER_ERROR , "type" , "unknown" );
                            return -1;                      
                    }
                    return 0;
                }
                else {
                    printf( ATHER_ERROR , "hash" , "no 0" );
                    return 1;
                }
            }
            else {
                printf( ATHER_ERROR , "contents" , "no permissions" );
                return 1;
            }
        }
        else {
            printf( ATHER_ERROR , "type" , "no wrapper" );
            return 1;
        }
    }
    else {
        printf( ATHER_ERROR , "path" , "no ctx" );
        return 1;
    }
}
        
Type __path( Path *path ) {
    
    char *temp , *__ptr = ( path -> __main );
    int _iter = 0 , _length = strlen( __ptr );
    path -> __home = malloc( _length );
    Type _type = NO_SPEC;
    // deconstruct working dir
    int TRU = -2;
    while ( TRU != 0 ) {
        switch( TRU ) {
            case -1:
                TRU = strstr( temp , ATHER_HOME ) != NULL ? 1 : -2;
                break;
            case 1:
                _type = LES_PUB;
                if ( strstr( temp , ATHER_LES_PUB ) != NULL ) { path -> __home = ATHER_LES_PUB; TRU = 0; break; }
            case 2:
                _type = LES_PVT;
                if ( strstr( temp , ATHER_LES_PVT ) != NULL ) { path -> __home = ATHER_LES_PVT; TRU = 0; break; }
            case 3:
               _type = MOR;
                path -> __home = ATHER_PEAK_MOR;
                TRU = 0;
                break;
            default:
                temp = (char *)(&__ptr[_iter]);
                _iter++;
                TRU = _iter < _length ? ( TRU > 0 ? 1 : -1 ) : 3;
                break;
        }
    }
    // rebuild path
    while ( _length != 0 ) {
        temp = (char *)(&__ptr[_length]);
        if ( strstr( temp , path -> __home ) != NULL ) {
            int __len = strlen( temp );
            path -> __node = malloc( __len * sizeof( char ) );
            typed_les_style( _type , temp , path -> __node );
            break;
        }
        _length--;
    }
    return _type;  
}


int typed_les_style( Type _type , char *str , char *savestr ) {

    char tls__delim[3] = ATHER_PEAK;

    int _iter = strlen( str );
    int _ = 0 , __ = 0;
    while ( _ < _iter ) {
        if ( str[_] == '/' ) {
            if ( __ >= 0 && savestr[__ - 1] != '.' ){
                savestr[__] = tls__delim[0];
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


int les_style( char *str , char *savestr ) {
    int _iter = strlen( str );
    int _ = 0 , __ = 0;
    while ( _ < _iter ) {
        if ( str[_] == '/' ) {
            if ( __ >= 0 && savestr[__ - 1] != '.' ){
                savestr[__] = '.';
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

void ather_path_log( Ather *ather ) {
    _type_log( ather -> _type );
    log_path_debug_verbose( ather -> _path );   
}

void _type_log( Type _type ) {
    printf( " Ather :: Type ::\n " );
    switch ( _type ) {
        case LES_PUB:
            printf( "%d > Public\n" , LES_PUB );
            break;
        case LES_PVT:
            printf( "%d > Private\n" , LES_PVT );
            break;
        case MOR:
            printf( "%d > MOR <\n" , MOR );
            break;
        default:
            break;
    }
}

char *mixin_path( char *ptr , Path *path ) {
   int _idx = 0, rloc = 2;
   int f_len = strlen( ptr );
   path->__main = malloc( f_len );
   path->__node = malloc( f_len );
   char * em_ptr = malloc( f_len );

   for( int i=0; i<f_len; i++ ) {
        (path->__main)[i] = ptr[i];
        int __dif = f_len - strlen( path->__main );
        if ( ! strstr( path->__main , ATHER_HOME ) ) {
            if ( rloc == 2 ) {
                path->__home = malloc( __dif );
                rloc = 0;
            }
            (path->__home)[i] = ptr[i];
        }
        else {
            (path->__node)[_idx] = ptr[i];
            em_ptr[_idx] = ptr[i];
            _idx++;
        }
    }
    path->__name = malloc( f_len );
    char * token = strtok(em_ptr, "/");
    while( token != NULL ) {
      char * temp = token;
      token = strtok( NULL , " " );
      if ( token == NULL ) {
        path->__name = temp;
        break;
      }
    }
    log_path_debug_verbose( path );
    return ptr;
}

void log_path_debug( Path *path ) {

    printf( ATHER_ENTRY , path->__node );
}

void log_path_debug_verbose( Path *path ) {
    printf(" Ather :: PATH :: \n");
    printf(" __main -> %s\n" , path->__main );
    printf(" __home -> %s\n" , path->__home );
    printf(" __node -> %s\n" , path->__node );
    printf(" __name -> %s\n" , path->__name );
}


#endif