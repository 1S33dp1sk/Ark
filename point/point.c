#include "point.h"



#ifndef ap_entry
    #define _ap_entry __ap_entry
    #define ap_entry __ap_entry( ap_name , F_OK )
    int __ap_entry( char *_e_path , int _e_type ) {
        int __ap = 0 , __flags = ( F_OK | ( _e_type == 0 ? R_OK : _e_type ) );
        if ( access( _e_path , __flags ) == 0 ) {
            __ap = open( _e_path , __flags );
        }
        return __ap > 0 ? __ap : 0;
    }
    #ifndef _ap_r_entry
        #define _ap_r_entry() __ap_entry( ap_name , R_OK )
    #endif
    #ifndef _ap_w_entry
        #define _ap_w_entry() __ap_entry( ap_name , W_OK )
    #endif
    #ifndef _ap_l_entry    
        #define _ap_l_entry() __ap_entry( ap_name , ( R_OK | W_OK ) )
    #endif
#else
    #ifndef ap_r_entry
        #define ap_r_entry _ap_r_entry
        int _ap_r_entry() {
            int __apr , __flags = ( R_OK );
            if ( access( ap_name , __flags ) == 0 ) {
                __flags = O_RDONLY;
                __apr = open( ap_name , __flags );
            }
            return __apr > 0 ? __apr : 0;
        }
    #endif
    #ifndef ap_w_entry
        #define ap_w_entry _ap_w_entry
        int _ap_w_entry() {
            int __apr , __flags = ( W_OK );
            if ( access( ap_name , __flags ) == 0 ) {
                __flags = O_WRONLY;
                __apr = open( ap_name , __flags );
            }
            return __apr > 0 ? __apr : 0;   
        }
    #endif
#endif

#ifndef ap_check
    #define ap_check __ap_fifo
    int __ap_fifo( char *point_name , struct stat *pstat ) {
        /**
         * mutex
         * because after `stat()`
         * st_nlink is atleast >= 1
        **/
        if ( ( pstat -> st_nlink == 0 ) \
            && stat( point_name , pstat ) == 0 ) { return 1; }
        return 0;
    }
#endif

#ifndef ap_make
    #define ap_make __ap_make
    int __ap_make() {
        if ( !mkfifo( ap_name , ( S_IRWXU | S_IXGRP | S_IXOTH ) ) ) {
            return 1;
        }
        return 0;
    }
#endif






#ifndef atherpoint
    int atherpoint( char ap_ref[8] ) {
        memmove( ap_name , ap_ref , 8 );
        #ifdef DEBUG
            printf( "@point :: ref = %s\n" , ap_name );
        #endif
        memset( &ap , 0 , __size_p_si );
        #ifdef DEBUG
            printf( "@point :: checking for atherpoint\n" );
        #endif
        if ( !__ap_fifo( ap_name , &ap.st.p_stat ) ) {
            #ifdef DEBUG
                printf( "@point :: no atherpoint found, attempting to create one\n" );
            #endif
            if ( !__ap_make() ) {
                #ifdef DEBUG
                    printf( "@point :: unable to create atherpoint\n" );
                #endif
                return -2;
            }
        }
        return 0;
    }
#endif

#ifndef process_entry
int process_entry( char *p_entry , int pe_type ) {

    return _ap_entry( p_entry , pe_type );    
}
#endif

#ifndef app_engine
int app_engine( struct p_io *engint ) {
    int c = 0, r_bytes;
    char _ , __[4096];
    memset( &__ , 0 , sizeof( __ ) );

    #ifdef DEBUG
        printf( "engint : FIFO FD = %d\n" , engint -> io_pfd );
        printf( "engint :: reading from fifo\n" );
    #endif

    while ( ( r_bytes = read( engint -> io_pfd , &__ , 4096 ) ) > 0 ) {
        c += r_bytes;
        _ = __[c-1];
        if ( _ == 10 ) {
            #ifdef DEBUG
                printf( "engint :: processing entry\n" );
            #endif
            if ( !process_entry( __ , c ) ) {
                printf("entry processed\n");
                break;
            }
            memset( &__ , 0 , c * sizeof( char ) );
            c = 0 , r_bytes = 0;
            continue;
        }
        r_bytes = 0;
    }
    return 0x0;
}
#endif

#ifndef socket_execute
int socket_execute( struct p_io *sexec ) {

    int count = 0, r_bytes = 0;
    char _ , __[4096];
    memset( &__ , 0 , sizeof( __ ) );

    #ifdef DEBUG
        printf( "sexec : FIFO fd : %d \n" , sexec -> io_pfd );
        printf( "sexec :: reading from stdin\n" );
    #endif

    while ( ( r_bytes = read( 0 , &__ , 4096 ) ) > 0 ) {
        count += r_bytes;
        _ = __[count-1];

        printf( "\n\n\n _ = (%c) \n\n\n" , _ );
        #ifdef DEBUG
            printf( "sexec : bytes read = %d : total bytes = %d\n" , r_bytes , count );
        #endif
        if ( _ == 10 ) {
            #ifdef DEBUG
                printf( "sexec :: writing to FIFO : len = %d, buf = %s\n" , count , __ );
            #endif
            if ( write( sexec -> io_pfd , __ , 4096 ) > 0 ) {
                memset( &__ , 0 , count );
                count = 0 , r_bytes = 0;
                continue;
            }
            break;
        }
        else if ( _ == 27 ) {
            printf( "sexec :: exit\n" );
            return 0;
        }
        r_bytes = 0;
    }
    printf( "sexec :: execution ended\n" );
    return 0;
}
#endif

#ifndef p_reader
    #define p_reader __init_reader
    int __init_reader(){
        point_io __reader , __writer;
        memset( &__reader , 0 , __size_p_io );
        memset( &__writer , 0 , __size_p_io );
        ap.st.p_known = __reader;
        ap.st.p_annon = __writer;
        // get the current pid
        __reader.io_pid = getpid();
        // fork the process for the new pid
        if ( ( __writer.io_pid = fork() ) == -1 ) {
            printf( "cannot start the atherpoint :: fork\n" );
            return -2;
        }
        // check calling process
        if ( is_reader ) {
            printf( "current pid for reading :: %ld\n" , __reader.io_pid );
            // read
            if ( ( __reader.io_pfd = _ap_r_entry() ) == 0 ) {
                printf( "cannot open atherpoint for reading\n");
                return -3;
            }
            printf( "\n-#-#-# engine -#-#-#\n" );
            return app_engine( &__reader );
        }
        else {
            printf( "current pid for writing :: %ld\n" , __writer.io_pid );
            // write 
            if ( ( __writer.io_pfd = _ap_w_entry() ) == 0 ) {
                printf( "cannot open atherpoint for writing\n");
                return -3;
            }
            printf( "\n#-#-# socket executive #-#-#\n" );
            return socket_execute( &__writer );
        }
        return 0;
    }
#endif



