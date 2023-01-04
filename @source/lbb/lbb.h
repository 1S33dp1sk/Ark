<<<<<<< HEAD
<<<<<<< HEAD
#ifndef lbb
<<<<<<< HEAD
<<<<<<< HEAD
	#define lbb little_black_book
=======
>>>>>>> 4947f52 (v0.01-NS)
=======
	#define lbb little_black_book
>>>>>>> 96d62a9 (created a dynamic shared library resulting in ./shared/* .o files)

// #define DEBUG

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
<<<<<<< HEAD
<<<<<<< HEAD
#include <stdint.h>
=======
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <fcntl.h>
#include <regex.h>
>>>>>>> 4947f52 (v0.01-NS)
=======
#include <stdint.h>
>>>>>>> 96d62a9 (created a dynamic shared library resulting in ./shared/* .o files)
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

<<<<<<< HEAD
<<<<<<< HEAD
=======

>>>>>>> 4947f52 (v0.01-NS)
=======
>>>>>>> 96d62a9 (created a dynamic shared library resulting in ./shared/* .o files)
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
<<<<<<< HEAD
<<<<<<< HEAD
=======
	// union {
	// 	struct sota *value;
	// 	struct sota *hash;
	// 	struct sota *ref;
	// } wry;
>>>>>>> 4947f52 (v0.01-NS)
=======
>>>>>>> 96d62a9 (created a dynamic shared library resulting in ./shared/* .o files)
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

<<<<<<< HEAD
<<<<<<< HEAD

int little_black_book( char *lbb_name );
int lbb_append( __lbb *lil_blk_book , char *lbb_key , char *lbb_val );
int lbb_query( __lbb *lil_blk_book , char *lbb_key );
int compile_lbb( char const *lbb_contents , struct seam **lbb_lines );
void log_sota( struct sota *s );
=======
const char *__read( __lbb *lbb );
const char *__line( char *key , char *val , char *delim );
int __append( __lbb *lbb , char *key , char *val );


void log_sota( struct sota *__sota ) {
	#ifdef VERBOSE_DEBUG
	printf( " ---sota---\n " );
	#endif
	printf( "string : \"%.*s\"" , __sota -> tal , __sota -> sptr );
	printf( " :: offset = %jd; len = %jd\n" , __sota -> offset , __sota -> tal );
}

int lbb_append( __lbb *lbb , char *key , char *val ) {
	#ifdef DEBUG
		printf( "lbb -> \n\tadding %s :: %s\n" , key , val );
	#endif

	const char *prev = __read( lbb );
	const char *curr = __line( key , val , ":" );
	char total[strlen( prev ) + strlen( curr )];
	strcpy( total , prev );
	strcpy( total , curr );
	int b_written = write( lbb -> lbb_fd , total , strlen( total ) );
	
	#ifdef DEBUG
		printf( "wrote %d bytes\n" , b_written );
	#endif

	return b_written;
}

const char *__line( char *key , char *val , char *delim ) {
	unsigned __len = strlen( key ) + strlen( val ) + strlen( delim ) + 1;
	char __line[__len];
	memset( &__line , 0 , sizeof( __line ) );
	strcpy( __line , key );
	strcat( __line , delim );
	strcat( __line , val );
	strcat( __line , "\n" );

	return strdup( __line );
}

const char *__read( __lbb *lbb ) {
	unsigned lbb_size = lbb -> lbb_stat.st_size;
	char temp[lbb_size+1];
	memset( &temp , 0 , sizeof( temp ) );
	read( lbb -> lbb_fd , &temp , lbb_size );
	strcat( temp , "\n" );
	return strdup( temp );
}

void __query( __lbb *lbb , char *key ) {

	char const *s = __read( lbb );
	printf( "lbb :: \n%s\n" , s );
}

int compile_lbb( char const *rlbb , struct seam **__lines ) {

	char const *__s = rlbb;
	regex_t     regex;
	regmatch_t  pmatch[3];
	regoff_t    k_off, v_off , k_len , v_len;

	if ( regcomp( &regex , __lbb_regex , REG_NEWLINE ) ) {
		return 1;
	}

	#ifdef DEBUG
		printf("lbb>compiling\n");
	#endif

	struct sota _k , _w;
	int __iter = 0;

	for ( ; ; __iter++ ) {

		if ( regexec( &regex, __s , arr_size( pmatch ) , pmatch , 0 ) ) {
			break;
		}
		memset( &_k , 0 , sizeof( _k ) );
		memset( &_w , 0 , sizeof( _w ) );

		_k.offset = ( intmax_t ) ( pmatch[1].rm_so + ( __s - rlbb ) ); 
		_k.tal = ( intmax_t ) ( pmatch[1].rm_eo - pmatch[1].rm_so );
		_k.sptr = ( char * ) __s + pmatch[1].rm_so;

		_w.offset = ( intmax_t ) ( pmatch[2].rm_so + ( __s - rlbb ) );
		_w.tal = ( intmax_t ) ( pmatch[2].rm_eo - pmatch[2].rm_so );
		_w.sptr = ( char * ) __s + pmatch[2].rm_so;

		#ifdef DEBUG
			printf( "-------->#%d:\n", __iter );
			log_sota( &_k );
			log_sota( &_w );
		#endif

		( *__lines + __iter ) -> key = _k;
		( *__lines + __iter ) -> wry = _w;

		__s += pmatch[0].rm_eo;
	}

	regfree( &regex );

	return 0;
}


int __regex_lbb( char const *rlbb ) {

	char const *__s = rlbb;
	regex_t     regex;
	regmatch_t  pmatch[3];
	regoff_t    k_off, v_off , k_len , v_len;

	if ( regcomp( &regex , __lbb_regex , REG_NEWLINE ) ) {
		return 1;
	}

	#ifdef DEBUG
		printf("lbb : raw => \n------>\n%s<------\n", __s);
		printf("lbb : compiled =>\n");
	#endif

	int __iter = 0;

	for ( ; ; __iter++ ) {
		
		if ( regexec( &regex, __s , arr_size( pmatch ) , pmatch , 0 ) ) {
			break;
		}

		#ifdef DEBUG
			printf( "-------->#%d:\n", __iter );
		#endif

		k_off = pmatch[1].rm_so + (__s - rlbb);
		k_len = pmatch[1].rm_eo - pmatch[1].rm_so;

		#ifdef DEBUG
			printf( "key (offset) = %jd; key (length) = %jd\n", (intmax_t) k_off , (intmax_t) k_len);
			printf( "key -> \"%.*s\"\n", k_len , __s + pmatch[1].rm_so );
		#endif

		v_off = pmatch[2].rm_so + (__s - rlbb);
		v_len = pmatch[2].rm_eo - pmatch[2].rm_so;
		   
		#ifdef DEBUG
			printf( "va (offset) = %jd; va (length) = %jd\n" , (intmax_t) v_off , (intmax_t) v_len);
			printf( "va -> \"%.*s\"\n" , v_len , __s + pmatch[2].rm_so );
		#endif

		__s += pmatch[0].rm_eo;
	}

	regfree( &regex );

	return 0;
}
>>>>>>> 4947f52 (v0.01-NS)
=======

int little_black_book( char *lbb_name );
int lbb_append( __lbb *lil_blk_book , char *lbb_key , char *lbb_val );
int lbb_query( __lbb *lil_blk_book , char *lbb_key );
int compile_lbb( char const *lbb_contents , struct seam **lbb_lines );
void log_sota( struct sota *s );
>>>>>>> 96d62a9 (created a dynamic shared library resulting in ./shared/* .o files)

#endif
=======
/// the little black book \\\
=======
#ifndef lbb
>>>>>>> c1e4320 (athernet V0.9)

// #define DEBUG

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdint.h>
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


<<<<<<< HEAD
>>>>>>> a415938 (kurls)
=======
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
int compile_lbb( char const *lbb_contents , struct seam **lbb_lines );
void log_sota( struct sota *s );

#endif
>>>>>>> c1e4320 (athernet V0.9)
