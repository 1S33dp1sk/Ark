#ifndef lbb
<<<<<<< HEAD
	#define lbb little_black_book
=======
>>>>>>> in_vik/main

// #define DEBUG

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdint.h>
<<<<<<< HEAD
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
=======
#include <fcntl.h>

#define __lbb_name ".lbb"
/**
lbb strucuture
 * 
**/ 
struct lbb_st {
	int lbb_fd; // main file descriptor
				// used as an int to describe any errors 
				// via negative signed ints
	struct stat lbb_stat;
				// checks for sizes, i-node numbers, devices etc
	char lbb_path[max_path];
				// the maximum build os-depenedent path for the file
};

struct sota {
	char *sptr; 
				// string ptr
	intmax_t offset; 
				// offset from file descriptor
	intmax_t tal; 
				// total array length
>>>>>>> in_vik/main
};

struct seam {
	struct sota key;
<<<<<<< HEAD
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
=======
				// the key for the lbb
	struct sota wry;
				// the { value , address , reference } of the key
};

/**
lbb structure interface
 *
**/
struct lbb_si {
	struct lbb_st st; 
				// universal lbb descriptor via struct
	struct seam **lbb_addrs;
				// the compiled and loaded lbb adddress
	unsigned addr_count;
				// the count of the `seam **` addresses
};


#define __lbb_regex "\\(^[a-zA-Z0-9]*\\)[=:]\\{1,\\}\\([a-zA-Z0-9]*$\\)"

typedef const void * entry_t;
typedef const char * word_t;
typedef word_t* record_t;
static struct lbb_si book;

#define lbb_entry entry_t
#define lbb_word eword_t entry_t
#define lbb_record record_t

#define init_lbb() 0x0|lbb_check( __ ) == 0 ? \
	0x2&lbb_load( __ ) : 0x1&lbb_make( __ )

// checkmake 
#define lbb_check( __ ) \
	book.st.lbb_fd > 0 ? book.st.lbb_fd :\
		access( book.st.lbb_path , (F_OK|R_OK) ) == 0 ?	 0 : -1
#define lbb_make( __ )  \
	book.st.lbb_fd > 0 ?\
		book.st.lbb_fd :\
			memmove( book.st.lbb_path , __lbb_name , sizeof( __lbb_name ) ); \
			book.st.lbb_fd = open( book.st.lbb_path , ( O_CREAT | O_RDWR ) , ( S_IRWXU | S_IRWXG | S_IRWXO ) );\
			book.st.lbb_fd;

// generate ctx for main interface via load
#define lbb_load( __ ) little_black_book( __lbb_name )
/**
LBB <O_RDONLY> on open:
 * when we open an lbb, use O+RDONLY
 * no need to write anything to it
 * as it should be updated atomically within 
 * the point through *kurl; that is referenced to/by it
**/
#define lbb_open( __ ) \
	do { book.st.lbb_fd = open( book.st.lbb_path , O_RDONLY ); } while ( 0 )
#define lbb_status( __ ) stat( book.st.lbb_path , &(book.st.lbb_stat) ) 
#define lbb_size( __ ) \
	book.st.lbb_stat.st_size
#define lbb_siobytes( __ ) \
	book.st.lbb_stat.st_blksize
#define lbb_close( __ ) \
	close( book.st.lbb_fd )
#define lbb_descriptors( __ ) book.st.lbb_fd
#define lbb_exists( __ ) __file_exsits( __lbb_name )


int little_black_book( char *lbb_name );
int lbb_append( struct lbb_si *__ , char *lbb_key , char *lbb_val );
int lbb_query( struct lbb_si *__ , char *lbb_key );
>>>>>>> in_vik/main
int compile_lbb( char const *lbb_contents , struct seam **lbb_lines );
void log_sota( struct sota *s );

#endif
