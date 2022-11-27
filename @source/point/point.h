#ifndef point
    #define point


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


struct apio {
    unsigned __fd;
    pid_t __pid;
};

typedef struct {
    int __k__;
    unsigned lbb_fd;
    struct stat ap_stat;
    struct apio from;
    struct apio to_point;
} ap;

static ap __ap;

#define point_descriptors( __ ) \
    ( __.to_point.__fd > 0 ) || ( __.from.__fd > 0 ) ? 1 : 0 

#define point_exists() __file_exsits( __ap_name )
#define make_point( __ ) atherpoint( __ap_name , &__ )



int atherpoint( void *at_point , ap *__ );
int process_entry( char *_e , int _e_len );
int app_engine( struct apio *engint );
int socket_execute( struct apio *sexec );
int applier( ap *apoint );



#endif


