#ifndef point
    #define point atherpoint


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


#define __AP_NAME "atherpoint"


struct apio {
    unsigned __fd;
    pid_t __pid;
};

typedef struct {
    struct apio t_ap;
    struct apio e_ap;
    struct stat ap_stat;
    unsigned lbb_fd;
#define ap_ok( __ ) ( (__.t_ap.__fd > 0) || (__.e_ap.__fd > 0) ? (1) : (0) )
} ap;

int atherpoint( char *p_path , unsigned p_level );
int process_entry( char *_e , int _e_len );
int app_engine( struct apio *engint );
int socket_execute( struct apio *sexec );
int applier( ap *apoint );



#endif


