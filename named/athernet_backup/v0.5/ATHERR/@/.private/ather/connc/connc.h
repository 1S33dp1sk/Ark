#ifndef CONNC
    #define CONNC( __ather__ ) __CONNC( __ather__ )

// #include "types.h"
// #include "helpers.h"

#if !defined( dirnet )
    #include <dirent.h>
#endif

#if !defined( ATHER_PATH )
    #define ATHER_PATH "\033[38;2;66;5;240mAther\033[0;37m- %s\n"
#endif

#if !defined( ATHER_EXEC )
    #define ATHER_EXEC "\033[38;2;255;215;50mAther\033[0;37m> %s \033[38;2;115;115;115m//%x\n"
#endif

/**
 * 
 * Connc is a mixtix
 * between Call and Connect
 * C ( all ) && ( onnect )
 * C ( all ) && ( (on) (n) (ect) ) // ect as in *
 * 
 */
int __all( Path *path , Connc *connc );
int _check_entry( char *base_path , struct dirent *dir_entry , Connc *connc );


int __CONNC( Ather *_ ) {
    __all( _ -> _path , _ -> _connc );
    return 0;
}



int __all( Path *path , Connc *connc ) {
    DIR *d;
    struct dirent *dir;
    connc -> __dirs = malloc( MAX_STR * sizeof( char ) * 2 );
    connc -> filedata = malloc( sizeof( FileData * ) * 100 );
    char *temp = malloc( MAX_STR * sizeof( char ) );
    temp = strcpy( temp , path -> __main );
    if ( d = opendir( temp ) ) {
        // log__header( &(path -> __node)[1] );
        while ( ( dir = readdir( d ) ) != NULL ) {
           _check_entry( temp , dir , connc );
           connc -> __total += 1;
        }
        closedir( d );
    }
    free( temp );
}

int _check_entry( char *base_path , struct dirent *dir_entry , Connc *connc ) {
    char *__name = malloc( MAX_STR * sizeof( char ) );
    strcpy( __name , dir_entry -> d_name );
    // __name = dir_entry -> d_name;
    if ( __name[0] == '.' ) {
        // check if:`d_type`::dir_entry -> d_reclen*
        if ( dir_entry -> d_type == DT_DIR || dir_entry -> d_reclen == 24 ) {
            // printf( "@dir( %s/%s )\n" , base_path , __name );
            return 0;
        }
        else {
            if ( strcmp( __name , ATHER_FILE ) == 0 ) {
                // printf( "%s found.\n" , ATHER_FILE );
                return 0;
            }
            return 0;
        }
        return 0;
    }
    else {
        switch ( dir_entry -> d_type ) {
            case DT_REG:
                ( connc -> filedata )[connc->num__files] = malloc( sizeof( FileData ) );
                strcpy( (connc->filedata)[connc->num__files] -> __name , __name );
                file__process( (connc->filedata)[connc->num__files] );
                connc -> num__files += 1;
                // printf( "@file( %s/%s )\n" , base_path , __name );
                return 0;
            case DT_DIR:
                (connc -> __dirs)[connc->num__dirs] = malloc( MAX_STR * sizeof( char ) );
                strcpy( (connc -> __dirs)[connc->num__dirs] , __name );
                // printf( "@dir( %s/%s )\n" , base_path , *(connc -> __dirs) );
                connc -> num__dirs += 1;
                return 0;
            default:
                printf( "unknown :: %d : %s\n" , __name , dir_entry -> d_type );
                return 1;
        }
        return 0;        
    }
}
// int *__all( Ather *_ , Connc *connc );
// int *__on( Ather *_ , Connc *connc );
// int *__n( Ather *_ , Connc *connc );
// int *__ect( Ather *_ , Connc *connc );
























































// int ather__connc( Ather *ather );
// int aether_dir();
// int get_files( Path *a_path ,  Connc *connc );
// int _check_entry( char *base_path , struct dirent *dir_entry , Connc *connc );
// int _loop( char *dir_path , Connc *connc );

// void _connc_and_hash( Connc *connc );
// void _index_and_total( Connc *connc );

// int ather__connc( Ather *ather ) {
//     int __ = 0;
//     FileData __filedata = {0};
//     __filedata.__name = ".ather";
//     if ( __ = _file_contents( &__filedata ) == 0 ) {
//         if ( __ = _file_hash( &__filedata ) != __filedata.__name ) {
//             _log_file_data( &__filedata );
//             return 0;
//         }
//         printf( NO_DEF , "connc" , "unable to connect" );
//         return 1;
//     }
//     printf( NO_DEF , "connc" , "unable to op" );
//     return 1;
// }


// int _loop( char *_path , Connc *connc ) {
//     DIR *d;
//     struct dirent *dir;
//     char *temp = malloc( 256 * sizeof( char ) );
//     temp = strcat( temp , _path );
//     if ( d = opendir( _path ) ) {
//         while ( ( dir = readdir( d ) ) != NULL ) {
//             // printf( "%s :: %d \n" , dir -> d_name , dir -> d_type );
//            _check_entry( temp , dir , connc );
//         }
//         closedir( d );
//     }
//     free( temp );
// }

// void _index_and_total( Connc *connc ) {
//     // remove extra increment
//     // for index to start from 0
//     connc->num__dirs -= 1;
//     connc->num__files -= 1;
//     // combine for hashing
//     connc->__total = connc->num__dirs + connc->num__files;
// }

// int _check_entry( char *base_path , struct dirent *dir_entry , Connc *connc ) {
//     char *__name = dir_entry -> d_name;
//     if ( __name[0] == '.' ) {
//         // check if:`d_type`::dir_entry -> d_reclen*
//         if ( dir_entry -> d_type == DT_DIR || dir_entry -> d_reclen == 24 ) {
//             printf( "@dir : %s%s \n" , base_path , dir_entry -> d_name );
//             return 0;
//         }
//         else {
//             if ( strcmp( dir_entry -> d_name , ATHER_FILE ) == 0 ) {
//                 printf( "%s found.\n" , ATHER_FILE );
//             }
//             return 0;
//         }
//         return 0;
//     }
//     else {
//         switch ( dir_entry -> d_type ) {
//             case DT_REG:
//                 printf( "@file : %s%s\n" , base_path , dir_entry -> d_name );
//                 return 0;
//             default:
//                 printf( "unknown :: %d : %s\n" , dir_entry -> d_name , dir_entry -> d_type );
//                 return 1;
//         }
//         return 0;        
//     }


//     // if( dir_entry -> d_type == DT_DIR && strcmp( dir_entry->d_name , "." ) && strcmp( dir_entry->d_name , ".." ) ) {
//     //     *(connc->__dirs) = (char *)(&dir_entry->d_name);
//     //     connc->num__dirs = connc->num__dirs + 1;
//     // }
//     // else if ( dir_entry -> d_type == DT_REG ) {
//     //     *(connc->__files) = (char *)(&dir_entry->d_name);
//     //     connc->num__files = connc->num__files + 1;
//     // }
// }

// int get_files( Path *path , Connc *connc ) {
//     if ( ( path -> __main ) == NULL && strlen( path -> __main ) < 5 ) {
//         return 2;
//     }
//     connc->__dirs = malloc( 100 * sizeof( char ) );
//     connc->__files = malloc( 100 * sizeof( char ) );
//     _loop( path -> __main , connc );
//     return 0;
// }

// void _connc_and_hash( Connc *connc ) {
//     int __total = connc->__total , _iter = 0;
//     for( ; _iter <= connc->num__files; _iter++ ) {
//         FileData __filedata = {0};
//         connc -> filedata[_iter] = &__filedata;
//         // _file_hash( &__filedata );    
//         // __filedata = connc -> filedata[_iter];
//         // _file_contents( &__filedata );
//         // __safehash = super_fast_hash( __filedata.__contents , strlen( __filedata.__contents ) );
//         // connc-> filedata[_iter] = __safehash;
//     }
// }
#endif
