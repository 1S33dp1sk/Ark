#include "point.h"


<<<<<<< HEAD
<<<<<<< HEAD
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

<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
=======

>>>>>>> 757e790 (shared library for point)
=======
>>>>>>> 96d62a9 (created a dynamic shared library resulting in ./shared/* .o files)
=======
#ifndef process_entry
>>>>>>> 46ba237 (broke everything pt.2)
int process_entry( char *entry , int e_len ) {

    printf( "entry = %d@app_engine :: \n\t%s\n" , e_len , entry );

    return e_len > 10 ? 0 : 1;
}
#endif

<<<<<<< HEAD
int app_engine( struct apio *engint ) {
=======
=======
#include <unistd.h>
>>>>>>> c1e4320 (athernet V0.9)

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


int atherpoint( void *point_name , apoint *__ ) {

    memset( __ , 0 , sizeof( apoint ) );
    #ifdef DEBUG
        printf( "@point :: checking for atherpoint\n" );
    #endif

    if ( !__ap_fifo( &__ ) ) {

        #ifdef DEBUG
            printf( "@point :: no atherpoint found, attempting to create one\n" );
        #endif

        if ( !__ap_make() ) {
            printf( "@point :: unable to create atherpoint\n" );
            return -2;
        }
    }

    __ -> lbb_fd = __ap_entry( ( char * ) point_name , __ -> __k__ );


    return __ -> lbb_fd;
}

int process_entry( char *entry , int e_len ) {

    printf( "entry = %d@app_engine :: \n\t%s\n" , e_len , entry );

    return e_len > 10 ? 0 : 1;
}

<<<<<<< HEAD
#ifndef app_engine
int app_engine( struct p_io *engint ) {
>>>>>>> a415938 (kurls)
=======
int app_engine( struct apio *engint ) {
>>>>>>> c1e4320 (athernet V0.9)
=======
#ifndef app_engine
int app_engine( struct p_io *engint ) {
>>>>>>> 46ba237 (broke everything pt.2)
    int c = 0, r_bytes;
    char _ , __[4096];
    memset( &__ , 0 , sizeof( __ ) );

    #ifdef DEBUG
        printf( "engint : FIFO FD = %d\n" , engint -> __fd );
        printf( "engint :: reading from fifo\n" );
    #endif

<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
    while ( ( r_bytes = read( engint -> __fd , &__ , 4096 ) ) > 0 ) {
=======
    while ( ( r_bytes = read( engint -> io_pfd , &__ , 4096 ) ) > 0 ) {
>>>>>>> a415938 (kurls)
=======
    while ( ( r_bytes = read( engint -> __fd , &__ , 4096 ) ) > 0 ) {
>>>>>>> c1e4320 (athernet V0.9)
=======
    while ( ( r_bytes = read( engint -> io_pfd , &__ , 4096 ) ) > 0 ) {
>>>>>>> 46ba237 (broke everything pt.2)
        c += r_bytes;
        _ = __[c-1];
        if ( _ == 10 ) {
            #ifdef DEBUG
                printf( "engint :: processing entry\n" );
            #endif
            if ( !process_entry( __ , c ) ) {
<<<<<<< HEAD
<<<<<<< HEAD
                printf("entery processed\n");
=======
                printf("entry processed\n");
>>>>>>> a415938 (kurls)
=======
                printf("entery processed\n");
>>>>>>> cf46ec7 (athernet v0)
                break;
            }
            memset( &__ , 0 , c * sizeof( char ) );
            c = 0 , r_bytes = 0;
            continue;
        }
        r_bytes = 0;
    }
}
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD

int socket_execute( struct apio *sexec ) {
=======
#endif

#ifndef socket_execute
int socket_execute( struct p_io *sexec ) {
>>>>>>> a415938 (kurls)
=======

int socket_execute( struct apio *sexec ) {
>>>>>>> c1e4320 (athernet V0.9)
=======
#endif

#ifndef socket_execute
int socket_execute( struct p_io *sexec ) {
>>>>>>> 46ba237 (broke everything pt.2)

    int count = 0, r_bytes = 0;
    char _ , __[4096];
    memset( &__ , 0 , sizeof( __ ) );

    #ifdef DEBUG
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
        printf( "sexec : FIFO fd : %d \n" , sexec -> __fd );
=======
        printf( "sexec : FIFO fd : %d \n" , sexec -> io_pfd );
>>>>>>> a415938 (kurls)
=======
        printf( "sexec : FIFO fd : %d \n" , sexec -> __fd );
>>>>>>> c1e4320 (athernet V0.9)
=======
        printf( "sexec : FIFO fd : %d \n" , sexec -> io_pfd );
>>>>>>> 46ba237 (broke everything pt.2)
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
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
            if ( write( sexec -> __fd , __ , 4096 ) > 0 ) {
=======
            if ( write( sexec -> io_pfd , __ , 4096 ) > 0 ) {
>>>>>>> a415938 (kurls)
=======
            if ( write( sexec -> __fd , __ , 4096 ) > 0 ) {
>>>>>>> c1e4320 (athernet V0.9)
=======
            if ( write( sexec -> io_pfd , __ , 4096 ) > 0 ) {
>>>>>>> 46ba237 (broke everything pt.2)
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
<<<<<<< HEAD
<<<<<<< HEAD

<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
int applier( ap *a_point ){
=======
int applier( apoint *a_point ){
>>>>>>> 1b97cf4 (broke everything)

    // get the current pid
    ( a_point -> e_ap ).__pid = getpid();
    // fork the process for the new pid
    if ( ( ( a_point -> t_ap ).__pid = fork() ) == -1 ) {
=======
int applier( ap *point ){
=======
int applier( ap *a_point ){
>>>>>>> 96d62a9 (created a dynamic shared library resulting in ./shared/* .o files)

    // get the current pid
    ( a_point -> from ).__pid = getpid();
    // fork the process for the new pid
<<<<<<< HEAD
<<<<<<< HEAD
    if ( ( ( point -> t_ap ).__pid = fork() ) == -1 ) {
>>>>>>> 757e790 (shared library for point)
=======
    if ( ( ( a_point -> t_ap ).__pid = fork() ) == -1 ) {
>>>>>>> 96d62a9 (created a dynamic shared library resulting in ./shared/* .o files)
=======
#endif

#ifndef applier
int applier( point *ap ){
=======
>>>>>>> c1e4320 (athernet V0.9)
=======
#endif
>>>>>>> 46ba237 (broke everything pt.2)

#ifndef applier
int applier( point *ap ){

    struct p_io lbb_reader = ( ap -> apst ).p_lbb;
    struct p_io point_writer = ( ap -> apst ).p_annon;

    // get the current pid
    lbb_reader.io_pid = getpid();
    // fork the process for the new pid
<<<<<<< HEAD
<<<<<<< HEAD
    if ( ( point_writer.io_pid = fork() ) == -1 ) {
>>>>>>> a415938 (kurls)
=======
    if ( ( ( a_point -> to_point ).__pid = fork() ) == -1 ) {
>>>>>>> c1e4320 (athernet V0.9)
=======
    if ( ( ( a_point -> to_point ).__pid = fork() ) == -1 ) {
>>>>>>> 1635bec (started athernet)
=======
    if ( ( point_writer.io_pid = fork() ) == -1 ) {
>>>>>>> 46ba237 (broke everything pt.2)
        printf( "cannot start the atherpoint :: fork\n" );
        return 2;
    }

    // check calling process
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
    if ( ( a_point -> t_ap ).__pid == 0 ) {
        printf( "current pid for reading :: %d\n" , ( a_point -> e_ap ).__pid );
        // read
        if ( ( ( a_point -> e_ap ).__fd = _ap_r_entry() ) == 0 ) {
=======
    if ( ( point -> t_ap ).__pid == 0 ) {
        printf( "current pid for reading :: %d\n" , ( point -> e_ap ).__pid );
        // read
        if ( ( ( point -> e_ap ).__fd = _ap_r_entry() ) == 0 ) {
>>>>>>> 757e790 (shared library for point)
=======
    if ( ( a_point -> t_ap ).__pid == 0 ) {
        printf( "current pid for reading :: %d\n" , ( a_point -> e_ap ).__pid );
        // read
        if ( ( ( a_point -> e_ap ).__fd = _ap_r_entry() ) == 0 ) {
>>>>>>> 96d62a9 (created a dynamic shared library resulting in ./shared/* .o files)
=======
    if ( point_writer.io_pid == 0 ) {
        printf( "current pid for reading :: %ld\n" , lbb_reader.io_pid );
        // read
        if ( ( lbb_reader.io_pid = _ap_r_entry() ) == 0 ) {
>>>>>>> a415938 (kurls)
=======
    if ( ( a_point -> to_point ).__pid == 0 ) {
        printf( "current pid for reading :: %d\n" , ( a_point -> from ).__pid );
        // read
        if ( ( ( a_point -> from ).__fd = _ap_r_entry() ) == 0 ) {
>>>>>>> c1e4320 (athernet V0.9)
=======
    if ( ( a_point -> to_point ).__pid == 0 ) {
        printf( "current pid for reading :: %d\n" , ( a_point -> from ).__pid );
        // read
        if ( ( ( a_point -> from ).__fd = _ap_r_entry() ) == 0 ) {
>>>>>>> 1635bec (started athernet)
=======
    if ( point_writer.io_pid == 0 ) {
        printf( "current pid for reading :: %d\n" , lbb_reader.io_pid );
        // read
        if ( ( lbb_reader.io_pid = _ap_r_entry() ) == 0 ) {
>>>>>>> 46ba237 (broke everything pt.2)
            printf( "cannot open atherpoint for reading\n");
            return 3;
        }
        printf( "\n-#-#-# engine -#-#-#\n" );
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
        return app_engine( &(a_point -> e_ap) );
    }
    else {
        printf( "current pid for writing :: %d\n" , ( a_point -> t_ap ).__pid );
        // write
        if ( ( ( a_point -> t_ap ).__fd = _ap_w_entry() ) == 0 ) {
=======
        return app_engine( &(point -> e_ap) );
=======
        return app_engine( &(a_point -> e_ap) );
>>>>>>> 96d62a9 (created a dynamic shared library resulting in ./shared/* .o files)
=======
        return app_engine( &(a_point -> from ) );
>>>>>>> 1635bec (started athernet)
    }
    else {
        printf( "current pid for writing :: %d\n" , ( a_point -> to_point ).__pid );
        // write
<<<<<<< HEAD
<<<<<<< HEAD
        if ( ( ( point -> t_ap ).__fd = _ap_w_entry() ) == 0 ) {
>>>>>>> 757e790 (shared library for point)
=======
        if ( ( ( a_point -> t_ap ).__fd = _ap_w_entry() ) == 0 ) {
>>>>>>> 96d62a9 (created a dynamic shared library resulting in ./shared/* .o files)
=======
        return app_engine( &lbb_reader );
=======
        return app_engine( &(a_point -> from ) );
>>>>>>> c1e4320 (athernet V0.9)
=======
        return app_engine( &lbb_reader );
>>>>>>> 46ba237 (broke everything pt.2)
    }
    else {
        printf( "current pid for writing :: %d\n" , point_writer.io_pid );
        // write
<<<<<<< HEAD
<<<<<<< HEAD
        if ( ( point_writer.io_pfd = _ap_w_entry() ) == 0 ) {
>>>>>>> a415938 (kurls)
=======
        if ( ( ( a_point -> to_point ).__fd = _ap_w_entry() ) == 0 ) {
>>>>>>> c1e4320 (athernet V0.9)
=======
        if ( ( ( a_point -> to_point ).__fd = _ap_w_entry() ) == 0 ) {
>>>>>>> 1635bec (started athernet)
=======
        if ( ( point_writer.io_pfd = _ap_w_entry() ) == 0 ) {
>>>>>>> 46ba237 (broke everything pt.2)
            printf( "cannot open atherpoint for writing\n");
            return 3;
        }
        printf( "\n#-#-# socket executive #-#-#\n" );
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
        return socket_execute( &(a_point -> t_ap) );
=======
        return socket_execute( &(point -> t_ap) );
>>>>>>> 757e790 (shared library for point)
=======
        return socket_execute( &(a_point -> t_ap) );
>>>>>>> 96d62a9 (created a dynamic shared library resulting in ./shared/* .o files)
=======
        return socket_execute( &point_writer );
>>>>>>> a415938 (kurls)
=======
        return socket_execute( &(a_point -> to_point) );
>>>>>>> c1e4320 (athernet V0.9)
=======
        return socket_execute( &(a_point -> to_point) );
>>>>>>> 1635bec (started athernet)
=======
        return socket_execute( &point_writer );
>>>>>>> 46ba237 (broke everything pt.2)
    }

    return 0;
}
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD


<<<<<<< HEAD
<<<<<<< HEAD

=======
/**
 * 
 * _e_path :: delim/os/path
 * 
 * _e_type :
 *  0 -> read
 *  1 -> write
 */
>>>>>>> 757e790 (shared library for point)
=======

>>>>>>> 96d62a9 (created a dynamic shared library resulting in ./shared/* .o files)
=======



>>>>>>> c1e4320 (athernet V0.9)
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
<<<<<<< HEAD
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
    // kindof a mutex because after `stat`
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
=======
=======
>>>>>>> c1e4320 (athernet V0.9)
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

<<<<<<< HEAD
>>>>>>> a415938 (kurls)
=======
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
    // kindof a mutex because after `stat`
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
>>>>>>> c1e4320 (athernet V0.9)
=======
#endif


>>>>>>> 46ba237 (broke everything pt.2)

