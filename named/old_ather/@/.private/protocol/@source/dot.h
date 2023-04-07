
#ifndef AtherDot

    #include <pwd.h>
    #include <dirent.h>
    #include <sys/stat.h>
    #include <fcntl.h>

    #define AtherDot ".ather"
    #define AtherPath "@path"
    #define __DELIMS = ":="
    #define ENTRY__START "{"
    #define ENTRY__END "}"
    #define PATH_LENGTH 201

    const char __delims[2] = { ':' , '=' };
    const int ascii_entry[] = { 69, 78, 84, 82, 89, 123, 32 };
typedef enum {PATH = 0x97e82973 , CALL = 0x47622221 , CONNC = 0xa7155072 , ENTRY = 0xd3e74f0f} H__instance;

    #define default_file( path ) ( int ) ( _make_default_file_at_( path ) )
    #define Afile( path , filedata ) ( int ) ( _file_exists( path , filedata ) )
    #define AELEMENTS( elems , __single_conf__ ) ( int ) ( _get_elements( elems , __single_conf__ ) )
    #define CONNC( __ather__ ) __CONNC( __ather__ )
    #define ENTRY( __ather__ ) __ENTRY( __ather__ )
    #define Apath( __ather__ ) __PATH( __ather__ )



    void exec( Entry *__entry__ );
    char *entry( char *_entry , Entry *__entry__ );
    int _pathify( Ather *_ );
    // int _lestyle( Type _type , char *str , char *savestr );
    int _check_entry( char *base_path , struct dirent *dir_entry , Connc *connc );
    int _make_entry_ctx( char *_entry , Entry *__entry__ );
    int __activedir( char *__fullpath );
    int __all( Path *path , Connc *connc );
    void __homedir( char *__ );
    int __check__entry( char *entry_name );
    char *__ENTRY__( char *_entry , Entry *__entry__ );


    /**
     * @needed for executing the entry -- incoming
     */
    int __check__entry( char *entry_name ) {
        for ( int _i=0; _i<6; _i++ ) {
            if ( entry_name[_i] != ascii_entry[_i] ) {
                return 10;
            }
        }
        return 20;
    }
    int _make_entry_ctx( char *_entry , Entry *__entry__ ) {
        int _iterlen = strlen( _entry );
        int _idx = 0;
        for( ; _idx < _iterlen ; _idx++ ) {
            if ( _entry[_idx] == '#' ) {
                break;
            }
        }
        char *__ref = &(_entry[_idx+1]);
        strncpy( __entry__ -> __ctx , __ref , _iterlen - _idx );
        return 0;
    }
    char *__ENTRY__( char *_entry , Entry *__entry__ ) {
        char *_e__name = malloc( MAX_STR * sizeof( char ) );
        _e__name = strtok_r( _entry , ENTRY__END , &_entry );
        int __;
        if ( ( __ = __check__entry( _e__name ) ) == 10 ) {
            _entry = strtok( NULL , ENTRY__END );
            _make_entry_ctx( _entry , __entry__ );
        }
        return _entry;
    }
    char *entry( char *_entry , Entry *__entry__ ) {
        return __ENTRY__( _entry , __entry__ );
        // exec( __entry__ );
    }
    void exec( Entry *__entry__ ) {
        if ( strlen( __entry__ -> __ctx ) > 2 ) {
            __entry__ -> __depth += 1;
            __entry__ -> __res = system( __entry__ -> __ctx );
        }
    }
    int __ENTRY( Ather *_ ) {
    }
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
                if ( strcmp( __name , AtherDot ) == 0 ) {
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
                    // file__process( (connc->filedata)[connc->num__files] );
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
    unsigned int __pack( unsigned char *__ , char *__fmt , Protocol *p );
    int _make_default_file_at_( char *file_path ) {
        unsigned int __default_file__;
        char __buf[1024];
        __default_file__ = open( file_path , O_RDWR|O_CREAT , S_IRWXU );
        Protocol p = {0};
        p._bin = malloc( 100 * sizeof( char ) );
        p._bin = "Mypathisbecause";
        unsigned int _size = __pack( __buf , "E\0" , &p );
        write( __default_file__ , __buf , _size );
        close( __default_file__ );
        return 0;
    }
    void unpack__( unsigned char *__ , char *__fmt , Protocol *p );
    int _read_default_file( char *file_path ) {
        unsigned int __default_file__;
        char __buf[1024];
        __default_file__ = open( file_path , O_RDWR );
        // printf("reading..\n");
        Protocol p = {0};
        p._bin = malloc( 100 * sizeof( char ) );
        unpack__( __buf , "E\n" , &p );
        return 0;
    }
    int _file_exists( char *file_path , FileData *filedata ) { 
        if ( strlen( file_path ) < strlen( AtherDot ) + 1 ) {
            return 2;
        }
        strcpy( filedata -> __name , file_path );
        if ( file_path[strlen( file_path ) - 1] != 'r' ) {
            strcat( filedata -> __name , "/@" );
        }
        int __ = 0;
        if ( !__fdata( filedata -> __name ) ) {
            if ( _file_contents( filedata ) == 0 ) {
                if ( __ = _file_hash( filedata ) == 0 ) {
                    // _log_file_data( filedata );
                    return 0;
                }
                printf( NO_DEF , ".ather" , "cannot verify" );
                return 1;
            }
            printf( NO_DEF , ".ather" , "malformed contents" );
            return 1;
        }
        printf( NO_DEF , ".ather" , "no configurations found" );
        return 2;
    }
    int _validate_value( char *__temp , Elems *elems ) {
        int __len = strlen( __temp );
        if ( ( __temp[0] == '=' && __len < 50 ) ){ 
            return 20;
        }
        return 2;
    }
    uint32_t super_fast_hash ( char * data , int len );
    int _validate_element( char *__temp , Elems *elems ) {
        int __len = strlen( __temp );
        if ( ( __len >= 4 && __len < 7 ) ) {
            switch ( super_fast_hash( __temp , __len ) ) {
                case PATH:
                    return 10;
                case CONNC:
                    return 11;
                case CALL:
                    return 12;
                default:
                    return 2;
            }
        }
        if ( strstr( __temp , "ENTRY" ) ) {
            strcpy( elems -> __entry , __temp );
        }
        return 0;
    }
    /**
     * `__single_conf__` is defined as one-single-full configuration file
     * 
     */ 
    int _get_elements( Elems *elems , char *__single_conf__ ) {
        char *__temp = malloc( MAX_STR * sizeof( char ) );
        strcpy( __temp , __single_conf__ );
        int TRU = -1;
        char *__delim = ( char * ) (&__delims);
        while ( TRU != 0 ) {
            switch ( TRU ) {
                case -1:
                    __temp = strtok( __temp , __delim );
                case 1:
                    TRU = _validate_element( __temp , elems );
                    __temp = strtok( NULL , "\n" );
                    break;
                case 2:
                    TRU = _validate_value( __temp , elems );
                    break;
                case 10:
                    strcpy( elems -> __path , (&__temp[1]) );
                    TRU = 2;
                    break;
                case 11:
                    strcpy( elems -> __connc , (&__temp[1]) );
                    TRU = 2;
                    break;
                case 12:
                    strcpy( elems -> __call , (&__temp[1]) );
                    TRU = 1;
                    break;
                default:
                    __temp = strtok( NULL , __delim );
                    TRU = 1;
                    break;
            }
        }
        return 0;
    }
    int __fdata( char *__filepath ) {
        if ( access( __filepath , R_OK ) == 0 ) {
            return 0;
        }
        return 1;
    }
    int __dirdata( char *__dirname ) {
        struct stat st;
        if ( stat( __dirname , &st ) == 0 ) {
            return 0;    
        }
        return 1;
    }
    char *_dir_hash( char *__dirname ) {
       char *__hash = malloc( 1 );
       if ( __dirdata( __dirname ) == 0 ) {
        return __hash;
       }
       printf( "unable to obtain directory\n" );
       return __dirname;
    }
    char *_path_hash( Path *path ) {
    }
    // todo :: add a warning if a file cannot be read
    int _file_contents( FileData *filedata ) {
        if ( access( filedata -> __name , R_OK ) != 0 ) {
            printf( NO_DEF , "op" , "no access." );
            return 2;
        }
        FILE *f__ = fopen( filedata -> __name , "r" );
        fread( filedata -> __contents , sizeof( filedata -> __contents ) , 1 , f__ );
        filedata -> __size = ftell( f__ );
        fclose( f__ );
        return 0;
    }
    // void __homedir( char *__ ) {
    //     struct passwd *pw = getpwuid( getuid() );
    //     memcpy( __ , pw -> pw_dir , strlen( pw -> pw_dir ) );
    //     __ += strlen( pw -> pw_dir );
    //     memcpy( __ , "/@\0" , 3 );
    // }
    int __activedir( char *__fullpath ) {
        struct stat __st;
        if ( stat( __fullpath , &__st ) == 0 ) {
            printf( DIR_FOUND );
            return 0;    
        }
        printf( DEF_DEF , __fullpath , "Y" );   
        mkdir( __fullpath , 0700 );
        return 0;
    }
    // int __PATH( Ather *_ ) {
    //     int __ = 0;
    //     Path *path = _ -> _path;
    //     if ( getcwd( path -> __main , sizeof( path -> __main ) ) != NULL ) {
    //         _ -> _type = NO_SPEC;
    //         if ( strstr( path -> __main , __HDIR ) != NULL ) {
    //             _ -> _type = MOR_PUB;
    //             strcpy( path -> __home , __HDIR );
    //             if ( strstr( path -> __main , _pvtHDIR ) != NULL ) {
    //                 _ -> _type = LES_PVT;
    //                 strcpy( path -> __home , _pvtHDIR );
    //             }
    //             else if ( strstr( path -> __main , _pubHDIR ) != NULL ) {
    //                 _ -> _type = LES_PUB; 
    //                 strcpy( path -> __home , _pubHDIR );
    //             }
    //             return _pathify( _ );
    //         }
    //         else {
    //             printf( NO_DEF , __HFILE , path -> __main );
    //             _ -> _vecf -> flagged = 1;
    //             return 1;
    //         }
    //     }
    //     return 2; 
    // }
    int _pathify( Ather *_ ) {
        char *temp , *_ptr = ( _ -> _path -> __main );
        int _length = strlen( _ptr );
        int __len = 0, __FLAG = 0;
        while ( _length > 0 ) {
            temp = ( char * )( &_ptr[_length] );
            if ( strstr( temp , _ -> _path -> __home ) != NULL && __FLAG == 0 ) {
                __len = strlen( temp );
                // _lestyle( _ -> _type , temp , _ -> _path -> __name );
                __FLAG = 1;
            }
            if ( __FLAG == 1 ) {
                strcpy( _ -> _path -> __wd , (&_ptr[strlen( _ptr )-_length]) );
                __FLAG = 2;
            }
            if ( strstr( temp , "@/" ) == NULL && __FLAG == 2 ){
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
        return 0;
    }
    // int _lestyle( Type _type , char *str , char *savestr ) {
    //     int _iter = strlen( str );
    //     int _ = 1 , __ = 0;
    //     while ( _ < _iter  ) {
    //         if ( str[_] == '/' ) {
    //             if ( __ >= 0 && savestr[__ - 1] != '.' ){
    //                 savestr[__] = '.';
    //                 // strcat( savestr , "#" );
    //                 __++;
    //             }
    //         }
    //         else if ( str[_] != '.' ) {
    //             savestr[__] = str[_];
    //             __++;
    //         }
    //         _++;
    //     }
    //     return 0;
    // }
#endif
