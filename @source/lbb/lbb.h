/// the little black book \\\

// #define DEBUG

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdint.h>
#include <fcntl.h>
#include <string.h>

#include "../probe.h"
/**
lbb : word ::
 * an lbb word consists of 3 main parts
 * 
*-1.	key	: value	
 *
 *	key:value:=address	( stores the associated key with value )
 * 
 * 
*.0.	key = reference
 *
 *	key=value:=address	( stores the associated key with a reference )
 * 
 * 
*+1.	key	:= address 
 *
 *	key:=value:=address	( stores the associated key as an address )
 * 
 * 
*/
#ifndef lbb
	#define __lbb_name "little_black_book"
	#define __lbb_regex "\\(^[a-zA-Z0-9]*\\)[=:]\\{1,\\}\\([a-zA-Z0-9]*$\\)"
	#define __lbb_ext ".lbb"
	typedef const void * entry_t;
	typedef const char * word_t;
	typedef word_t* record_t;
	static struct lbb_si book;
	#define lbb_entry entry_t
	#define lbb_word eword_t entry_t
	#define lbb_record record_t
	/**
	 * 
	 */
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
	};

	struct seam {
		struct sota key;
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


	#define lbb ( &book ) lbb_load;

	#define init_lbb() 0x0|lbb_check( __ ) == 0 ? \
		0x2&lbb_load( __ ) : 0x1&lbb_make()
	// checkmake 
	#define lbb_check( __ ) \
		book.st.lbb_fd > 0 ? book.st.lbb_fd :\
			access( book.st.lbb_path , (F_OK|R_OK) ) == 0 ?	 0 : -1
	#define lbb_make __lbb_make
	// generate ctx for main interface via load
	#define lbb_load little_black_book( __lbb_ext )
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
	#define lbb_exists( __ ) __file_exsits( __lbb_ext )

	int __lbb_make() {
		if ( book.st.lbb_fd <= 0 ) {
			memmove( book.st.lbb_path , __lbb_ext , sizeof( __lbb_ext ) );
			book.st.lbb_fd = open( book.st.lbb_path , ( O_CREAT | O_RDWR ) , ( S_IRWXU | S_IRWXG | S_IRWXO ) );
		}
		return book.st.lbb_fd;
	}

	int little_black_book( char *lbb_name );
		int lbb_append( struct lbb_si *__ , char *lbb_key , char *lbb_val );
		int lbb_query( struct lbb_si *__ , char *lbb_key );
	int compile_lbb( char const *lbb_contents , struct seam **lbb_lines );
		void log_sota( struct sota *s );
#endif

