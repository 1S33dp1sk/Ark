#ifndef lbb


// #define DEBUG

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdint.h>
/*
***************************************************************************
	*******************************************************************
		***********************************************************
			***************************************************
				********************************************
					************************************
						****************************
							********************
								************
									lbb
								************
							********************
						****************************
					************************************
				********************************************
			***************************************************
		***********************************************************
	*******************************************************************
***************************************************************************
*/
#define MAX_STR 256
#define MAX_PATH 4096
#define __lbb_name ".lbb"
#define __lbb_regex "\\(^[a-zA-Z0-9]*\\)[=:]\\{1,\\}\\([a-zA-Z0-9]*$\\)"
#define arr_size( _ ) ( sizeof( _ ) ) / ( sizeof( ( _ )[0] ) )

struct __lbb {
	int lbb_fd; // main file descriptor
				// used as an int to describe any errors 
				// via negative correlations with the num
	struct stat lbb_stat;
				// checks for sizes, i-node numbers, devices etc
	char lbb_path[MAX_PATH];
				// the maximum build os-depenedent path for the file
};

struct sota {
	char *sptr; 
				// string ptr
	intmax_t offset; 
				// offset from file descriptor
	intmax_t tal; 
				// total array length
};

struct seam {
	struct sota key;
	struct sota wry;
};

//little black book
struct lbb__ {
	struct __lbb st; // universal description
	struct seam **lbb_addrs;
	unsigned addr_count;
};

typedef struct lbb__ lbb;

// checkmake 

#define lbb_check( __ ) __.st.lbb_fd > 0 ? \
	__.st.lbb_fd : access( __.st.lbb_path , (F_OK|R_OK) ) == 0 ? 0 : -1
#define lbb_make( __ ) \
	do { \
		__.st.lbb_fd = open( __.st.lbb_path , ( O_CREAT | O_RDWR ) , \
			( S_IRWXU | S_IRWXG | S_IRWXO ) ); \
	} while ( 0 )
// when we open an lbb, use O+RDONLY
// no need to write anything to it
// as it should be updated atomically within 
// *kurl that is referenced to/by it
#define lbb_open( __ ) \
	do { __.st.lbb_fd = open( __.st.lbb_path , O_RDONLY ); } while ( 0 )
#define lbb_status( __ ) \
	stat( __.st.lbb_path , ( &__.st.lbb_stat ) ) == 0 ? 1 : -1
#define lbb_size( __ ) \
	__.st.lbb_stat.st_size
#define lbb_iobytes( __ ) \
	__.st.lbb_stat.st_blksize
#define lbb_close( __ ) \
	close( __.st.lbb_fd )
#define lbb_descriptors( __ ) \
	__.st.lbb_fd > 0 ? 1 : -1





lbb little_black_book( char *lbb_name );
int lbb_append( lbb *__ , char *lbb_key , char *lbb_val );
int lbb_query( lbb *__ , char *lbb_key );
int compile_lbb( char const *lbb_contents , struct seam **lbb_lines );
void log_sota( struct sota *s );

#endif
