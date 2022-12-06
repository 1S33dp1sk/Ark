/// the little black book \\\

// #define DEBUG



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
#ifndef lbb
	#define __lbb_name "little_black_book"
	#define __lbb_regex "\\(^[a-zA-Z0-9]*\\)[=:]\\{1,\\}\\([a-zA-Z0-9]*$\\)"
	#define __lbb_ext ".lbb"

	typedef const void * entry_t;
	typedef const char * word_t;
	typedef word_t* record_t;

	#define lbb_entry entry_t
	#define lbb_word word_t entry_t
	#define lbb_record record_t

	static struct lbb_si book;
	#define lbb &book
	#include "../anet.h"

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
		#define __size_lbb_st sizeof( struct lbb_st )
	/**
	lbb entry structure
	 * 
	**/
		struct sota {
			char *sptr; 
						// string ptr
			intmax_t offset; 
						// offset from file descriptor
			intmax_t tal; 
						// total array length
		};
		#define __size_sota sizeof( struct sota )
	/**
	lbb line structure
	 * 
	**/  
		struct seam {
			struct sota key;
						// the key for the lbb
			struct sota wry;
						// the { value , address , reference } of the key
		};
		#define __size_seam sizeof( struct seam )
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
				book.st.lbb_fd > 0 ? 0x0 : access( book.st.lbb_path , (F_OK|R_OK|W_OK) ) == 0 ? 0x0 : 0xF 
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
	#define lbb_exists() \
		__file_exsits( __lbb_ext )



	int little_black_book( char *lbb_name );
		int lbb_append( struct lbb_si *__ , char *lbb_key , char *lbb_val );
		int lbb_query( struct lbb_si *__ , char *lbb_key );
	int compile_lbb( char const *lbb_contents , struct seam **lbb_lines );
		void log_sota( struct sota *s );

#endif

