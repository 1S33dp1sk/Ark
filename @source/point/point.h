/// atherpoint \\\

#define DEBUG


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
#if point
	#ifndef __ap_name
		#define __ap_name "atherpoint"
	#endif

	#include "../probe.h"

	enum __io_types {
		__io_r = 1,
		__io_ws
	};

	struct p_io {
		unsigned io_pfd;
				// a paticular file descriptor
		signed long io_pid;
				// the initating process id
		enum __io_types io_type;
				// the IO type, mainly will be writers
	};
	#define __size_p_io sizeof( struct p_io )
	#define point_io struct p_io

	struct p_st {
		struct stat p_stat;
				// the FIFO stat in the filesystem
		struct p_io p_known;
				// the point reader&executor
		struct p_io p_annon;
				  // annonymus point request
	};
	#define __size_p_st sizeof( struct point_st )
	#define point_st struct p_st

	struct p_si {
		struct p_st st;
				// the ather point structure
		int level;
				// the level associated with the structure
		void *lai;
				// can && should be casted to a { nai } reference
	};
	#define __size_p_si sizeof( struct p_si )
	#define __size_p __size_p_si
	#define point_si struct p_si

	extern unsigned long level;
	static char ap_name[8];
	static point_si ap; 

	#define point_descriptors() \
		( ap.st.p_lbb.io_pfd > 0 ) || ( ap.st.p_annon.io_pfd > 0 ) ? 1 : 0 

	#define point_exists() __file_exsits( __ap_name )
	#define make_point atherpoint

	#define is_reader ap.st.p_annon.io_pid == 0
	#define is_writer ap.st.p_known.io_pid == 0
	
	#define p_writer() int _w_res = 0;\
		do { ap.st.p_annon.io_pfd = _ap_w_entry(); _w_res = ( ap.st.p_annon.io_pfd != 0 )  } while( 0 )

	#define p_reader() int _r_res = 0;\
		do { ap.st.p_known.io_pfd = _ap_r_entry(); _r_res = ( ap.st.p_known.io_pfd != 0 ) } while( 0 )

	extern int atherpoint( char ap_ref[8] );
	int process_entry( char *_e , int _e_len );
	int app_engine( point_io *engint );
	int socket_execute( point_io *sexec );
	extern int applier();
#endif


