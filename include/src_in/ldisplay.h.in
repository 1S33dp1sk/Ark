/** supposedly the window handler **/

typedef enum { __white , __black , __grey , __purple } Colors;
typedef enum { NO_DEF, /* not defined */ DEF, /* defined == default */ VAR /* defined && !default */ } v_def;

#ifndef AtherLog
    #define AtherLog "@log"

    #define S__EXEC " » "
    #define S__EP " — "
    #define S__POTHARD " • "
    #define S__POTLIGHT " · "
    #define S__X " [\u2716] "
    #define S__GTG " [\u2713] "

    #define DIR_FOUND "@ directory found.\n"
    #define DIR_NOT_FOUND "No @ directory (i.e: folder) was found.\n"

    #define DEF_DEF "\033[38;2;255;215;50m %s \033[0;37m» initiating @ %s \n"
    #define DEF_NO "\033[38;2;178;34;34m%s\033[0;37m :: [\u2716] -> %s\n"
    #define DEF_VAR "\033[38;2;66;5;240m( %s ) \033[0;37m —» %s•\n"


    #define NC "\033[0;37m"
    #define NCNL "\033[0;37m\n"

    #define vlog( vtype , ... ) void varlog( vtype , argname , __arg )
    void varlog( v_def vtype , char *argname , char *__arg ) {
        switch ( vtype ) {
            case NO_DEF:
                printf( NO_DEF , argname , __arg ); // argerr
                break;
            case DEF:
                printf( DEF_DEF , argname , __arg ); // argdef
                break;
            case VAR:
                printf( DEF_VAR , argname , __arg ); // argval
                break;
        }
    }


    #define str_color( c , s ) (char *) ( color__unix( c , s ) )
    char *color__unix( Colors __color , char *__str ) {
        char *color__str = malloc( 100 + strlen( __str ) * sizeof( char ) );
        strcat( color__str , NC );
        strcpy( color__str , "\033[38;2;240;240;240m" );
        switch ( __color ) {
        case __white:
            strcat( color__str , "\033[38;2;240;240;240m" );
            break;
        case __black:
            strcat( color__str , "\033[38;2;20;20;20m" );
            break;
        case __grey:
            strcat( color__str , "\033[38;2;115;115;115m" );
            break;
        case __purple:
            strcat( color__str , "\033[38;2;66;5;240m" );
            break;
        default:
            strcat( color__str , "\033[38;2;127;9;128m" );
            break;
        }
        strcat( color__str , __str );
        strcat( color__str , NC );
        return color__str;
    } 


    void log_path_debug( Path *path );
    void log_connc_debug( Connc *connc );
    void log_elements_debug( Elems *elements );
    void log_protocol_packet_debug( Protocol *p );
    void log_addrinfo_debug( struct addrinfo *__ );
    void log_typeproto_debug( typeproto *__ );
    void log_ifaddr_debug( struct ifaddrs *_lcon );
    void log_ip_debug( char *cur_ip );
    void log_file_data( FileData *filedata );


    void log_path_debug( Path *path ) {
        printf("\nAther :: PATH :: \n");
        printf(" __node -> %x\n" , path->__node );
        printf(" __main -> %s\n" , path->__main );
        printf(" __pub -> %s\n" , path->__pub );
        printf(" __name -> %s\n" , path->__name );
        printf(" __home -> %s\n" , path->__home );
        printf(" __wd -> %s\n" , path->__wd );
    }

    void log_connc_debug( Connc *connc ) {
        printf("\nAther :: CONNC :: \n");
        if ( connc -> num__dirs >= 1 ) {
            printf("\n Dirs :: \n");
            for( int _dir_iter=0; _dir_iter<connc->num__dirs; _dir_iter++ ) {
                printf( DEF_VAR , connc->__dirs[_dir_iter]  ); // 
            }
        }
        if ( connc -> num__files >= 1 ) {
            printf("\n Files :: \n");
            for( int _file_iter=0; _file_iter<connc->num__files; _file_iter++ ) {
                printf( DEF_VAR , connc->filedata[_file_iter]->__name , connc->filedata[_file_iter]->__hash );
            }
        }
    }

    void log_elements_debug( Elems *elements ) {
        printf( "Ather :: Elements :: \n" );
        printf( "\t__path -> %s\n" , elements -> __path );
        printf( "\t__call -> %s\n" , elements -> __call );
        printf( "\t__connc -> %s\n" , elements -> __connc );
        printf( "\t__entry -> %s\n" , elements -> __entry );
    }

    void log_protocol_packet_debug( Protocol *p ) {
        printf( " ATHER :PROTOCOL :: PACKET -> \n " );
        printf( "\tlen   :: %d\n" , p -> _len );
        printf( "\tname      :: %s\n" , p -> _name );
        printf( "\tsize      :: %d\n" , p -> _size );
        printf( "\tdiff      :: %c\n" , p -> _diff );
        printf( "\ttype      :: %s\n" , p -> _type );
        printf( "\tselector :: 0x%04lx\n" , p -> _selector );
        printf( "\tbin   :: %s\n" , p -> _bin );
    }

    void log_addrinfo_debug( struct addrinfo *__ ) {
        printf( " ATHER :: ADDRINFO :: \n" );
        printf( "flags :: %d\n" , __ -> ai_flags );
        printf( "family :: %d\n" , __ -> ai_family );
        printf( "c_name :: %s\n" , __ -> ai_canonname );
        printf( "protocol :: %d\n" , __ -> ai_protocol );
        printf( "socket : <type> : %d\n" , __ -> ai_socktype );
        printf( "socket : <len> : %d\n" , __ -> ai_addrlen );
        printf( "socket : <addr> : %d\n", __ -> ai_addr );
        printf( "\t>> %c\t\n\n" , __ -> ai_next == NULL ? '#' : '!' );  
    }

    void log_typeproto_debug( typeproto *__ ) {

        printf( " ATHER :: TYPEPROTO :: \n" );
        printf( "name_proto :: %d\n" , __ -> name__ );
        printf( "name_ip :: %s\n" , __ -> at__ );
        printf( "node_name :: %s\n" , __ -> node__ );
        printf( "node_service :: %s\n\n" , __ -> serv__ );
        log_addrinfo_debug( __ -> hints__ );
    }

    void log_ifaddr_debug( struct ifaddrs *_lcon ) {
        printf( "flags :: %x\n" , _lcon -> ifa_flags );
        printf( "interface :: %s\n" , _lcon -> ifa_name );
        printf( "data :: %p\n\n" , _lcon -> ifa_data ); 
    }

    void log_ip_debug( char *cur_ip ) {
        
        printf( "•%s\n" , cur_ip );
    }

    void log_file_data( FileData *filedata ) {
        printf( "Ather :: File ::\n" , filedata -> __name , filedata -> __size , strlen( filedata -> __contents ) > 100 ? "too long" : filedata -> __contents );
        printf( " __name : %s\n" , filedata -> __name );
        printf( " __registery : %x\n" , filedata -> __registery );
        printf( " __size : %d\n" , filedata -> __size );
        printf( " __hash : %x\n" , filedata -> __hash );
        printf( " __contents {\n\033[38;2;111;112;131m%s\033[0;37m\n}\n" , strlen( filedata -> __contents ) > 50 ? "call to display" : filedata -> __contents );
    }


#endif
