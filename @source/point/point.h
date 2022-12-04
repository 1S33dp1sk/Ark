#ifndef point
    #define point

// #define DEBUG

/**
 * atherpoint is an `FIFO`
 * with a singular reader, that is the `lbb`
 * 
 * writers can connect to the atherpoint syncronously 
 * and query real time updates on the values , operations
 * that are used to create/modify these values.
 * 
 * that is done mainly by kurling the lbb between two or more
 * points. 
 * 
 */

#include <sys/stat.h>
#include <sys/types.h>


#define __ap_name "atherpoint"

typedef enum __io_types {
    __reader = 1,
    __writers
};

struct pio {
    unsigned io_pfd;
    pid_t io_pid;
    __io_types io_type;
};

struct point_st {
    struct stat ap_stat;
    struct pio p_from;
    struct pio p_to;
};

struct point_si {
    struct point_st st;
    int level;
    void *lai;
};


#define point_descriptors( __ ) \
    ( __.to_point.__fd > 0 ) || ( __.from.__fd > 0 ) ? 1 : 0 

#define point_exists() __file_exsits( __ap_name )
#define make_point( __ ) atherpoint( __ap_name , &__ )



int atherpoint( void *at_point , apoint* ap );
int process_entry( char *_e , int _e_len );
int app_engine( struct apio *engint );
int socket_execute( struct apio *sexec );
int applier( apoint* ap );



#endif


