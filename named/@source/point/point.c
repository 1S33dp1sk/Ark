#include "point.h"


#include <unistd.h>

#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/socket.h>
#include <sys/sysmacros.h>

#include <stdio.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>
#include <fcntl.h>


int __ap_entry( char *_e_path , int _e_type );
int _ap_r_entry();
int _ap_w_entry();
int __ap_fifo();
int __ap_make();


<<<<<<< HEAD

int atherpoint( char *p_path , unsigned p_level ) {

    // char *__path = argc >= 2 ? ( ( char * )argv[1] ) : "";
    // int __level = argc == 3 ? argv[2][0] - '0' : 0;

    ap __;
    memset( &__ , 0 , sizeof( __ ) );

    #ifdef DEBUG
        printf( "@point :: checking FIFO for atherpoint\n" );
=======
int atherpoint( void *point_name , apoint *__ ) {

    memset( __ , 0 , sizeof( apoint ) );
    #ifdef DEBUG
        printf( "@point :: checking for atherpoint\n" );
>>>>>>> in_vik/main
    #endif

    if ( !__ap_fifo( &__ ) ) {

        #ifdef DEBUG
            printf( "@point :: no atherpoint found, attempting to create one\n" );
        #endif

        if ( !__ap_make() ) {
            printf( "@point :: unable to create atherpoint\n" );
<<<<<<< HEAD
            return 2;
        }
    }

    __.lbb_fd = __ap_entry( p_path , p_level );


    return applier( &__ );
=======
            return -2;
        }
    }

    __ -> lbb_fd = __ap_entry( ( char * ) point_name , __ -> __k__ );


    return __ -> lbb_fd;
>>>>>>> in_vik/main
}

int process_entry( char *entry , int e_len ) {

<<<<<<< HEAD
    printf( "entry = %d@app_engine :: \n\t%s\n" );
=======
    printf( "entry = %d@app_engine :: \n\t%s\n" , e_len , entry );
>>>>>>> in_vik/main

    return e_len > 10 ? 0 : 1;
}

int app_engine( struct apio *engint ) {
    int c = 0, r_bytes;
    char _ , __[4096];
    memset( &__ , 0 , sizeof( __ ) );

    #ifdef DEBUG
        printf( "engint : FIFO FD = %d\n" , engint -> __fd );
        printf( "engint :: reading from fifo\n" );
    #endif

    while ( ( r_bytes = read( engint -> __fd , &__ , 4096 ) ) > 0 ) {
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

int socket_execute( struct apio *sexec ) {

    int count = 0, r_bytes = 0;
    char _ , __[4096];
    memset( &__ , 0 , sizeof( __ ) );

    #ifdef DEBUG
        printf( "sexec : FIFO fd : %d \n" , sexec -> __fd );
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
            if ( write( sexec -> __fd , __ , 4096 ) > 0 ) {
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

<<<<<<< HEAD
int applier( ap *a_point ){

    // get the current pid
    ( a_point -> e_ap ).__pid = getpid();
    // fork the process for the new pid
    if ( ( ( a_point -> t_ap ).__pid = fork() ) == -1 ) {
=======
int applier( apoint *a_point ){

    // get the current pid
    ( a_point -> from ).__pid = getpid();
    // fork the process for the new pid
    if ( ( ( a_point -> to_point ).__pid = fork() ) == -1 ) {
>>>>>>> in_vik/main
        printf( "cannot start the atherpoint :: fork\n" );
        return 2;
    }

    // check calling process
<<<<<<< HEAD
    if ( ( a_point -> t_ap ).__pid == 0 ) {
        printf( "current pid for reading :: %d\n" , ( a_point -> e_ap ).__pid );
        // read
        if ( ( ( a_point -> e_ap ).__fd = _ap_r_entry() ) == 0 ) {
=======
    if ( ( a_point -> to_point ).__pid == 0 ) {
        printf( "current pid for reading :: %d\n" , ( a_point -> from ).__pid );
        // read
        if ( ( ( a_point -> from ).__fd = _ap_r_entry() ) == 0 ) {
>>>>>>> in_vik/main
            printf( "cannot open atherpoint for reading\n");
            return 3;
        }
        printf( "\n-#-#-# engine -#-#-#\n" );
<<<<<<< HEAD
        return app_engine( &(a_point -> e_ap) );
    }
    else {
        printf( "current pid for writing :: %d\n" , ( a_point -> t_ap ).__pid );
        // write
        if ( ( ( a_point -> t_ap ).__fd = _ap_w_entry() ) == 0 ) {
=======
        return app_engine( &(a_point -> from ) );
    }
    else {
        printf( "current pid for writing :: %d\n" , ( a_point -> to_point ).__pid );
        // write
        if ( ( ( a_point -> to_point ).__fd = _ap_w_entry() ) == 0 ) {
>>>>>>> in_vik/main
            printf( "cannot open atherpoint for writing\n");
            return 3;
        }
        printf( "\n#-#-# socket executive #-#-#\n" );
<<<<<<< HEAD
        return socket_execute( &(a_point -> t_ap) );
=======
        return socket_execute( &(a_point -> to_point) );
>>>>>>> in_vik/main
    }

    return 0;
}



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

<<<<<<< HEAD
    if ( access( __AP_NAME , __flags ) == 0 ) {
        __flags = O_RDONLY;
        __apr = open( __AP_NAME , __flags );
=======
    if ( access( __ap_name , __flags ) == 0 ) {
        __flags = O_RDONLY;
        __apr = open( __ap_name , __flags );
>>>>>>> in_vik/main
    }

    return __apr > 0 ? __apr : 0;
}
#endif

#ifndef _ap_w_entry
int _ap_w_entry() {
    int __apr , __flags = ( W_OK );

<<<<<<< HEAD
    if ( access( __AP_NAME , __flags ) == 0 ) {
        __flags = O_WRONLY;
        __apr = open( __AP_NAME , __flags );
=======
    if ( access( __ap_name , __flags ) == 0 ) {
        __flags = O_WRONLY;
        __apr = open( __ap_name , __flags );
>>>>>>> in_vik/main
    }

    return __apr > 0 ? __apr : 0;   
}
#endif

#ifndef __ap_fifo
<<<<<<< HEAD
int __ap_fifo( ap *__ ) {
    if ( ( ( __ -> ap_stat ).st_nlink == 0 ) 
        && 
        stat( __AP_NAME , &( __ -> ap_stat ) ) == 0 ) {
        #ifdef log_stat
            log_stat( __ -> ap_stat );
        #endif
            return 1;
    }
=======
int __ap_fifo( char *point_name , struct stat *point_st ) {
    // kindof a mutex because after `stat`
    // st_nlink is atleast >= 1
    if ( ( point_st -> st_nlink == 0 ) \
        && stat( point_name , point_st ) == 0 ) { return 1; }
>>>>>>> in_vik/main
    return 0;
}
#endif

#ifndef __ap_make
int __ap_make() {
<<<<<<< HEAD
    if ( !mkfifo( __AP_NAME , ( S_IRWXU | S_IXGRP | S_IXOTH ) ) ) {
=======
    if ( !mkfifo( __ap_name , ( S_IRWXU | S_IXGRP | S_IXOTH ) ) ) {
>>>>>>> in_vik/main
        return 1;
    }
    return 0;
}
#endif

