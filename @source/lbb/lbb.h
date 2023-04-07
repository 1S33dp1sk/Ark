<<<<<<< HEAD
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

=======
/// lbb \\\

/**
lbb { a.k.a a little black book }
 * each consists of 3 words & they are categorized 
 * into 3 main genres with the possibility to add 
 * more of the ternary truth table
 * 
 * 
fordax*-1.	key	 :  value	
 *
 *	key:value:=address	( stores the associated key with value )
 * 
dercis*.0.	key  =  reference
 *
 *	key=value:=address	( stores the associated key with a reference )
 * 
attadr*+1.	key	:=  address 
 *
 *	key:=value:=address	( stores the associated key as an address )
 * 
*/
#ifndef __lbb__h
	/**
	header file name&properties
	 *
	**/
	#define __lbb_name "little_black_book"
	#include "../probe.h"
	// #define __lbb__h kurl > 0x7000 ? kurl&=0x0100 : kurl|=0x1111 
	#define __lbb_regex "\\(^[a-zA-Z0-9]*\\)[=:]\\{1,\\}\\([a-zA-Z0-9]*\\)$"
	#define __lbb_ext ".lbb"
	/**
	lbb entry results 
	 *
	**/
		enum lbb_e_res {
			_r_ref,
			_r_val,
			_r_liy
		};
		#define laddr enum lbb_e_res
	/**
	lbb hallmark structure
	 *
	**/
		struct lbb_hallmark {
			unsigned char __level;
			unsigned long __num_records;
			char *__address;
			char *__keyhash;
		};
		#define hallmark struct lbb_hallmark
		#define __size_lbb_hallmark sizeof( struct lbb_hallmark )
	/**
	lbb entry structure
	 * 
	**/
		struct lbb_kei {
			char *k; 
						// ptr
			unsigned long e__set; 
						// data offset from descriptor
			unsigned long i__size;
						// iter_size total array length
		};
		#define kei struct lbb_kei
		#define __size_kei sizeof( struct lbb_kei )
	/**
	lbb line structure
	 * 
	**/  
		struct lbb_word { // word
			kei v;
						// the key for the lbb
			kei a;
						// the { value , address , reference } of the key
			char l[2];
						// delimiter
		};
		#define word struct lbb_word
		#define __size_word sizeof( struct lbb_word )
	/**
	lbb line structure
	 *
	**/
		struct lbb_line {
			word a;
						// identification word
			kei b;
						// unique key
			char c[2];
						// delimiter
		};
		#define line struct lbb_line
		#define __size_line sizeof( struct lbb_line )
	/**
	lbb paragraph structure
	 *
	**/
		struct lbb_record {
			hallmark al;
			word *words;
		};
		#define record struct lbb_record
		#define __size_record sizeof( struct lbb_record )
	/**
	lbb main strucutre
	 * 
	**/
		struct lbb_st {
			unsigned lbb_level;
						// the k-level identifier  
			int lbb_fd; 
						// main file descriptor
						// used as an int to describe any errors 
						// via negative signed ints
			struct stat lbb_stat;
						// checks for sizes, i-node numbers, devices etc
			char lbb_path[max_path];
						// the maximum build os-depenedent path for the fifo
		};
		#define lbb_structure struct lbb_st
		#define __size_lbb_st sizeof( struct lbb_st )
	/**
	lbb interface structure
	 *
	**/
		struct lbb_si {
			struct lbb_st st; 
						// universal lbb descriptor via struct
			word **lbb_addrs;
						// the compiled and loaded lbb adddress
			unsigned addr_count;
						// the count of the `seam **` addresses
		};
		#define lbb_interface struct lbb_si
		#define __size_lbb_si sizeof( struct lbb_si )
	/**
	initialize book
	 *
	**/
	extern unsigned long level;
	static struct lbb_si book;
	static void *book_ref = &book;
	#define lbb &book
	#define create_lbb little_black_book
	ulong little_black_book();
		int compile_lbb( char const *lbb_contents , word **words );
	char *book_reference();
	char *book_key();
	char *book_point();
	/**
	ops on book
	 * 
	**/
	extern laddr lbb_entry (const void *_);
	extern const char *__hallmark( hallmark __ );
	extern const char *__word( char *k , char *v , char *d );
	extern const char *__read();
	extern int __write( char const *__ );
	extern int lbb_prompt();
	/**
	checkmake for lbb
	 * 
	**/  
		#define lbb_checkmake() 0x0^lbb_check() == 0x0 ? 0x0002&lbb_load() : 0x0001|lbb_make()
			#define lbb_check() \
				book.st.lbb_fd > 0 ? 0x0 : access( __lbb_ext , F_OK ) == 0 ? 0x1 : 0x2 
			#define lbb_make() 0x2; \
				do { \
					memmove( book.st.lbb_path , __lbb_ext , sizeof( __lbb_ext ) ); \
					book.st.lbb_fd = open( book.st.lbb_path , ( O_CREAT | O_RDWR ) , ( S_IRWXU | S_IRWXG | S_IRWXO ) ); \
				} while( 0 )
					// copy the named path and create an lbb file
					// check for access on the file path for lbb
			#define lbb_load() little_black_book()
					// generate ctx for main interface via load
			/**
			LBB <O_RDONLY> on open:
			 * when we open an lbb, use O+RDONLY
			 * no need to write anything to it
			 * as it should be updated atomically within 
			 * the point through *kurl; that is referenced to/by it
			**/
			#define lbb_open() \
				do { book.st.lbb_fd = open( book.st.lbb_path , O_RDONLY ); } while ( 0 )
			#define lbb_status() \
				stat( book.st.lbb_path , &(book.st.lbb_stat) ) 
			#define lbb_size() \
				book.st.lbb_stat.st_size
			#define lbb_siobytes() \
				book.st.lbb_stat.st_blksize
			#define lbb_close() \
				close( book.st.lbb_fd )
			#define lbb_descriptors() \
				book.st.lbb_fd
			#define lbb_inodenum() \
				book.st.lbb_stat.st_ino
#endif
>>>>>>> anet_V9/athernet



<<<<<<< HEAD
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
=======
>>>>>>> anet_V9/athernet

