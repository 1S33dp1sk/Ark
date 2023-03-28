#ifndef lbb
	#define lbb little_black_book

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
#define __LBB_NAME ".lbb"
#define __lbb_regex "\\(^[a-zA-Z0-9]*\\)[=:]\\{1,\\}\\([a-zA-Z0-9]*$\\)"

typedef struct {
	int lbb_fd;
	struct stat lbb_stat;
	char lbb_path[MAX_PATH];
} __lbb;

struct sota {
	char *sptr; // string ptr
	intmax_t offset; // offset from file descriptor
	intmax_t tal; // total array length
};

struct seam {
	struct sota key;
	struct sota wry;
};

//little black book
typedef struct {
	__lbb lbb_ud; // universal description
	struct seam **lbb_addrs;
	unsigned total_addrs;
} ath_lbb;


#define arr_size( _ ) ( sizeof( _ ) ) / ( sizeof( ( _ )[0] ) )
#define exists( _ ) _.lbb_fd > 0 ? \
	_.lbb_fd : access( _.lbb_path , (F_OK|R_OK|W_OK) ) == 0 ? 0 : -1
#define init( _ ) \
	do { _.lbb_fd = open( _.lbb_path , O_RDWR ); } while ( 0 )
#define cleanup( _ , __ ) \
	do { close( _.lbb_fd ); } while ( 0 )
#define create( _ ) \
	do { _.lbb_fd = open( _.lbb_path , ( O_CREAT | O_RDWR ) , ( S_IRWXU | S_IRWXG | S_IRWXO ) ); } while ( 0 )
#define status( _ ) stat( _.lbb_path , ( &_.lbb_stat ) ) == 0 ? 1 : 0
#define size( _ ) _.lbb_stat.st_size


int little_black_book( char *lbb_name );
int lbb_append( __lbb *lil_blk_book , char *lbb_key , char *lbb_val );
int lbb_query( __lbb *lil_blk_book , char *lbb_key );
int compile_lbb( char const *lbb_contents , struct seam **lbb_lines );
void log_sota( struct sota *s );

#endif
