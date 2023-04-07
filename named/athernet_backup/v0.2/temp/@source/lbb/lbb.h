/// the little black book \\\

// #define DEBUG
	

// #define the_lbb "__lbb" 
// possiblities : { al , a- , @ , # , ... }

/**
lbb { a.k.a little black book }
 * each consists of 3 words & they are categorized 
 * into 3 main genres with the possibility to add 
 * more of the ternary truth table
 * 
 * 
*-1.	key	: value	
 *
 *	key:value:=address	( stores the associated key with value )
 * 
*.0.	key = reference
 *
 *	key=value:=address	( stores the associated key with a reference )
 * 
*+1.	key	:= address 
 *
 *	key:=value:=address	( stores the associated key as an address )
 * 
*/


#ifndef __lbb__h
	#define __lbb_name "little_black_book"
	#include "../probe.h"
	// #define __lbb__h kurl > 0x7000 ? kurl&=0x0100 : kurl|=0x1111 
	#define __lbb_regex "\\(^[a-zA-Z0-9]*\\)[=:]\\{1,\\}\\([a-zA-Z0-9]*\\)$"
	#define __lbb_ext ".lbb"

	#define entry_t const void *
	#define t_entry ( entry_t _ )

	extern unsigned long level;
	static struct lbb_si book;

	#define lbb &book
	/**
	lbb entry results 
	 *
	**/
		enum lbb_e_res {
			__ref,
			__val,
			__liy
		};
		#define laddr enum lbb_e_res
	/**
	lbb hallmark structure
	 *
	**/
		struct lbb_hallmark {
			unsigned char __k; 
						// ( character )
			unsigned long __a; 
						// ( seperator )
			unsigned char _y_;  
						// ( count )
			unsigned char*_a; 
						// ( @string )
			unsigned int  n; 
						// ( # == # )
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
			intmax_t e__set; 
						// file offset from descriptor
			intmax_t i__size;
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
			int lbb_fd; // main file descriptor
						// used as an int to describe any errors 
						// via negative signed ints
			struct stat lbb_stat;
						// checks for sizes, i-node numbers, devices etc
			char lbb_path[max_path];
						// the maximum build os-depenedent path for the fifo
		};
		#define __st struct lbb_st
		#define __size_lbb_st sizeof( struct lbb_st )
	/**
	lbb interface structure
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
		#define __interface struct lbb_si
		#define __size_lbb_si sizeof( struct lbb_si )
	/**
	checkmake for lbb
	 * 
	**/  
		#define lbb_checkmake() 0x0^lbb_check() == 0x0 ? 0x0002&lbb_load() : 0x0001|lbb_make()
			#define lbb_make() 0x2; \
				do { \
					memmove( book.st.lbb_path , __lbb_ext , sizeof( __lbb_ext ) ); \
					book.st.lbb_fd = open( book.st.lbb_path , ( O_CREAT | O_RDWR ) , ( S_IRWXU | S_IRWXG | S_IRWXO ) ); \
				} while( 0 )
					// copy the named path and create an lbb file
			#define lbb_check() \
				book.st.lbb_fd > 0 ? 0x0 : access( book.st.lbb_path , (F_OK|R_OK|W_OK) ) == 0 ? 0x1 : 0x2 
					// check for access on the file path for lbb
			#define lbb_load() little_black_book( __lbb_ext )
					// generate ctx for main interface via load
			/**
			LBB <O_RDONLY> on open:
			 * when we open an lbb, use O+RDONLY
			 * no need to write anything to it
			 * as it should be updated atomically within 
			 * the point through *kurl; that is referenced to/by it
			**/
			#define lbb_open() \
				do { book.st.lbb_fd = open( book.st.lbb_path , O_RDWR ); } while ( 0 )
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
	/**
	initialize book
	 *
	**/
	int little_black_book();
		int compile_lbb( char const *lbb_contents , word **words );

	/**
	ops on book
	 * 
	**/
	extern laddr lbb_entry t_entry;
		int lbb_append( struct lbb_si *__ , char *lbb_key , char *lbb_val );
		int lbb_query( struct lbb_si *__ , char *lbb_key );
#endif


