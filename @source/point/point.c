#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include "point.h"



#ifndef __ap_entry
int __ap_entry( char *_e_path , int _e_type ) {
    int __ap = 0 , __flags = ( F_OK | ( _e_type == 0 ? R_OK : _e_type ) );
    char *e_path = strcat( strdup( _e_path ) , ".lbb" );
    if ( access( e_path , __flags ) == 0 ) {
        __flags = ( _e_type == 0 ? O_RDONLY : O_WRONLY );
        __ap = open( e_path , __flags );
    }
    return __ap > 0 ? __ap : 0;
}
#endif

#ifndef _ap_r_entry
int _ap_r_entry() {
    int __apr , __flags = ( R_OK );

    if ( access( __ap_name , __flags ) == 0 ) {
        __flags = O_RDONLY;
        __apr = open( __ap_name , __flags );
    }

    return __apr > 0 ? __apr : 0;
}
#endif

#ifndef _ap_w_entry
int _ap_w_entry() {
    int __apr , __flags = ( W_OK );

    if ( access( __ap_name , __flags ) == 0 ) {
        __flags = O_WRONLY;
        __apr = open( __ap_name , __flags );
    }

    return __apr > 0 ? __apr : 0;   
}
#endif

#ifndef __ap_fifo
int __ap_fifo( char *point_name , struct stat *point_st ) {
    // a mutex because after `stat`
    // st_nlink is atleast >= 1
    if ( ( point_st -> st_nlink == 0 ) \
        && stat( point_name , point_st ) == 0 ) { return 1; }
    return 0;
}
#endif

#ifndef __ap_make
int __ap_make() {
    if ( !mkfifo( __ap_name , ( S_IRWXU | S_IXGRP | S_IXOTH ) ) ) {
        return 1;
    }
    return 0;
}
#endif

#ifndef atherpoint
int atherpoint( void *point_name , point *__ ) {

    memset( __ , 0 , __size_p_si );

    #ifdef DEBUG
        printf( "@point :: checking for atherpoint\n" );
    #endif

    if ( !__ap_fifo( __ap_name , &( __ -> apst.p_stat ) ) ) {

        #ifdef DEBUG
            printf( "@point :: no atherpoint found, attempting to create one\n" );
        #endif

        if ( !__ap_make() ) {
            printf( "@point :: unable to create atherpoint\n" );
            return -2;
        }
    }

    __ -> apst.p_lbb.io_pfd = __ap_entry( ( char * ) __ap_name , W_OK );

    return 1;
}
#endif

#ifndef process_entry
int process_entry( char *entry , int e_len ) {

    printf( "entry = %d@app_engine :: \n\t%s\n" , e_len , entry );

    return e_len > 10 ? 0 : 1;
}
#endif

#ifndef app_engine
int app_engine( struct p_io *engint ) {
    int c = 0, r_bytes;
    char _ , __[4096];
    memset( &__ , 0 , sizeof( __ ) );

    #ifdef DEBUG
        printf( "engint : FIFO FD = %d\n" , engint -> __fd );
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
                printf("entery processed\n");
                break;
            }
            memset( &__ , 0 , c * sizeof( char ) );
            c = 0 , r_bytes = 0;
            continue;
        }
        r_bytes = 0;
    }
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

#ifndef applier
int applier( point *ap ){

    struct p_io lbb_reader = ( ap -> apst ).p_lbb;
    struct p_io point_writer = ( ap -> apst ).p_annon;

    // get the current pid
    lbb_reader.io_pid = getpid();
    // fork the process for the new pid
    if ( ( point_writer.io_pid = fork() ) == -1 ) {
        printf( "cannot start the atherpoint :: fork\n" );
        return 2;
    }

    // check calling process
    if ( point_writer.io_pid == 0 ) {
        printf( "current pid for reading :: %ld\n" , lbb_reader.io_pid );
        // read
        if ( ( lbb_reader.io_pid = _ap_r_entry() ) == 0 ) {
            printf( "cannot open atherpoint for reading\n");
            return 3;
        }
        printf( "\n-#-#-# engine -#-#-#\n" );
        return app_engine( &lbb_reader );
    }
    else {
        printf( "current pid for writing :: %ld\n" , point_writer.io_pid );
        // write
        if ( ( point_writer.io_pfd = _ap_w_entry() ) == 0 ) {
            printf( "cannot open atherpoint for writing\n");
            return 3;
        }
        printf( "\n#-#-# socket executive #-#-#\n" );
        return socket_execute( &point_writer );
    }

    return 0;
}
#endif



