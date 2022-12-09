#include "lbb.h"
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD

<<<<<<< HEAD
=======
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
>>>>>>> 1b97cf4 (broke everything)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <regex.h>
/**
lbb : word ::
 * an lbb word consists of 3 main parts
 * 
*-1.	key	]	:	[ value				( stores the associated key with value )
		

*.0.	key ]	=	[ reference			( stores the associated key with a reference )

	____________________________
*+1.	key	]	:=	[ address 			( stores the associated key as an address )
 *
 * 
1.	key:value:=address 
 * 
2. 	key=value:=address
 * 
3.	key:=value:=address
 * 
*/


word_t __read( struct lbb_st *__st );
word_t __line( char *key , char *val , char *delim );


int lbb_append( struct lbb_si*__ , char *key , char *val ) {
	#ifdef DEBUG
		printf( "lbb -> \n\tadding %s :: %s\n" , key , val );
	#endif

<<<<<<< HEAD
	const char *prev = __read( &__ -> st );
	const char *curr = __line( key , val , ":" );
	char total[strlen( prev ) + strlen( curr )];
	strcpy( total , prev );
	strcpy( total , curr );
	int b_written = write( __ -> st.lbb_fd , total , strlen( total ) );
	
	#ifdef DEBUG
		printf( "wrote %d bytes\n" , b_written );
	#endif

	return b_written;
}

int lbb_query( struct lbb_si*__ , char *key ) {
=======
word_t __read( struct lbb_st *__st );
word_t __line( char *key , char *val , char *delim );
>>>>>>> d369e4b (alignments)
=======
#define DEBUG




>>>>>>> facbf6d (starting encoding&decoding for lbb words,records,hallmark, and book)

}

int compile_lbb( char const *rlbb , struct seam **__lines ) {
=======
// #define DEBUG
=======
#define DEBUG
>>>>>>> cf46ec7 (athernet v0)


=======
>>>>>>> c1e4320 (athernet V0.9)
=======


>>>>>>> 4317814 (started anet.h)
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
								  *******
									lbb
								  *******
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

char *__record( 
	int __rlevel , // record level
	char *__raddr , // record address
	char *__rencorh , // record encryption|hash
	unsigned __rcount ) { // record lines count 
	return NULL;
}

int __write_record() {

	return 0;
}

word_t __line( char *key , char *val , char *delim ) {
	unsigned __len = strlen( key ) + strlen( val ) + strlen( delim ) + 1;
	char __line[__len]; memset( &__line , 0 , __len ); __line[__len] = '\0';

	strcpy( __line , key );
	strcat( __line , delim );
	strcat( __line , val );
	strcat( __line , "\n" );

	return strdup( __line );
}

word_t __read( struct lbb_st *st ) {
	unsigned lbb_size = st -> lbb_stat.st_size;
	char temp[lbb_size+1]; temp[lbb_size+1] = '\0';
	memset( &temp , 0 , lbb_size );
	read( st -> lbb_fd , &temp , lbb_size );
	return strdup( temp );
}

int __lbb_record( entry_t *ent ) {	
}

char *__hallmark( hallmark *__ ) {
	char __hal[max_str];
	int __ = 0;
	memset( &__hal , 0 , max_str*sizeof( char ) );
	__hal[__] = __ -> __l;
	__+=1;
	__hal[__] = ':';
	__+=1;
	unsigned int *__hal[__] = __->__n;
	__+=sizeof( unsigned int );
	__hal[__] = __kurl_version; 
	__+=1;
	unsigned int *__hal[__] = strlen( __ -> __n );
	__+=sizeof( unsigned int );
	__hal[__] = '@';
	__+=1;
	unsigned _a_addr = strlen( __ -> __a ); 
	memcpy( *__hal[__] , __ -> __a , _a_addr*sizeof( char ) );
	__+=_a_addr;
	__hal[__] = __kurl_version;
	__+=1;
	unsigned long *__hal[__] = __ -> __k;
	__+=sizeof( unsigned long );
	__hal[__] = 0xa;
	__+=1;
	printf( "%c:%d\t@%s\t=%lx\n" , \
	__ -> __l ,\
	__ -> __n ,\
	__ -> __a ,\
	__ -> __k );
	return strdup( __hal );
}

int lbb_append( struct lbb_si*__ , char *key , char *val ) {
	#ifdef DEBUG
		printf( "lbb -> \n\tadding %s :: %s\n" , key , val );
	#endif

	const char *prev = __read( &__ -> st );
	const char *curr = __line( key , val , ":" );
	char total[strlen( prev ) + strlen( curr )];
	strcpy( total , prev );
	strcpy( total , curr );
	int b_written = write( __ -> st.lbb_fd , total , strlen( total ) );
	
	#ifdef DEBUG
		printf( "wrote %d bytes\n" , b_written );
	#endif

	return b_written;
}

int lbb_query( struct lbb_si*__ , char *key ) {
}

<<<<<<< HEAD
int compile_lbb( char const *rlbb , word **__words ) {
>>>>>>> a415938 (kurls)
=======
int compile_lbb( char const *rlbb , struct seam **__lines ) {
>>>>>>> c1e4320 (athernet V0.9)

	char const *__s = rlbb;
	regex_t     regex;
	regmatch_t  pmatch[3];
	regoff_t    k_off, v_off , k_len , v_len;

<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
=======
	#ifdef DEBUG
		printf("lbb>compiling\n");
	#endif
>>>>>>> facbf6d (starting encoding&decoding for lbb words,records,hallmark, and book)
	if ( regcomp( &regex , __lbb_regex , REG_NEWLINE ) ) {
		return 1;
	}

	#ifdef DEBUG
		printf("lbb>compiled\n");
	#endif

	struct sota _k , _w;
=======
	#ifdef DEBUG
		printf("lbb>compiling\n");
	#endif
=======
>>>>>>> c1e4320 (athernet V0.9)
	if ( regcomp( &regex , __lbb_regex , REG_NEWLINE ) ) {
		return 1;
	}

<<<<<<< HEAD
	kei _k , _w;
>>>>>>> a415938 (kurls)
=======
	#ifdef DEBUG
		printf("lbb>compiling\n");
	#endif

	struct sota _k , _w;
>>>>>>> c1e4320 (athernet V0.9)
	int __iter = 0;

	for ( ; ; __iter++ ) {

		if ( regexec( &regex, __s , arr_size( pmatch ) , pmatch , 0 ) ) {
			break;
		}
		memset( &_k , 0 , sizeof( _k ) );
		memset( &_w , 0 , sizeof( _w ) );

<<<<<<< HEAD
<<<<<<< HEAD
		_k.offset = ( intmax_t ) ( pmatch[1].rm_so + ( __s - rlbb ) ); 
		_k.tal = ( intmax_t ) ( pmatch[1].rm_eo - pmatch[1].rm_so );
		_k.sptr = ( char * ) __s + pmatch[1].rm_so;

		_w.offset = ( intmax_t ) ( pmatch[2].rm_so + ( __s - rlbb ) );
		_w.tal = ( intmax_t ) ( pmatch[2].rm_eo - pmatch[2].rm_so );
		_w.sptr = ( char * ) __s + pmatch[2].rm_so;

		#ifdef DEBUG
			printf( "-------->#%d:\n", __iter );
			printf( "k :: %s\n" , _k.sptr );
			printf( "w :: %s\n" , _w.sptr );
		#endif

<<<<<<< HEAD
		( *__lines + __iter ) -> key = _k;
		( *__lines + __iter ) -> wry = _w;
=======
		_k.e__set = ( intmax_t ) ( pmatch[1].rm_so + ( __s - rlbb ) ); 
		_k.i__size = ( intmax_t ) ( pmatch[1].rm_eo - pmatch[1].rm_so );
		_k.k = ( char * ) __s + pmatch[1].rm_so;

		printf( "key -> \"%.*s\"\n", _k.i__size , _k.k + pmatch[1].rm_so );
=======
		_k.offset = ( intmax_t ) ( pmatch[1].rm_so + ( __s - rlbb ) ); 
		_k.tal = ( intmax_t ) ( pmatch[1].rm_eo - pmatch[1].rm_so );
		_k.sptr = ( char * ) __s + pmatch[1].rm_so;
>>>>>>> c1e4320 (athernet V0.9)

		_w.offset = ( intmax_t ) ( pmatch[2].rm_so + ( __s - rlbb ) );
		_w.tal = ( intmax_t ) ( pmatch[2].rm_eo - pmatch[2].rm_so );
		_w.sptr = ( char * ) __s + pmatch[2].rm_so;

		#ifdef DEBUG
			printf( "-------->#%d:\n", __iter );
			log_sota( &_k );
			log_sota( &_w );
		#endif

<<<<<<< HEAD
<<<<<<< HEAD

		// ( *__words + __iter ) -> v = _k;
		// ( *__words + __iter ) -> a = _w;
>>>>>>> a415938 (kurls)
=======
		( *__words + __iter ) -> v = _k;
		( *__words + __iter ) -> a = _w;
>>>>>>> cf46ec7 (athernet v0)
=======
		( *__lines + __iter ) -> key = _k;
		( *__lines + __iter ) -> wry = _w;
>>>>>>> c1e4320 (athernet V0.9)

		__s += pmatch[0].rm_eo;
	}

	regfree( &regex );
<<<<<<< HEAD
<<<<<<< HEAD
=======
	#ifdef DEBUG
		printf("lbb>compiled\n");
	#endif
>>>>>>> a415938 (kurls)
=======
>>>>>>> c1e4320 (athernet V0.9)

	return 0;
}

<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
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
=======
		// ( *__lines + __iter ) -> key = _k;
		// ( *__lines + __iter ) -> wry = _w;
>>>>>>> facbf6d (starting encoding&decoding for lbb words,records,hallmark, and book)

		__s += pmatch[0].rm_eo;
	}

	regfree( &regex );

	return 0;
}

<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD

=======
>>>>>>> 4f65147 (initial athernet structure including kurling , probing & builder for simple first stage rollout)
const char *__line( char *key , char *val , char *delim ) {
=======
__lbb__ __line( char *key , char *val , char *delim ) {
>>>>>>> c8122db (better structures & easier #inc_trace for hbar mainly in secondary and front-end modules)
	unsigned __len = strlen( key ) + strlen( val ) + strlen( delim ) + 1;
	char __line[__len];
	memset( &__line , 0 , sizeof( __line ) );
=======
word_t __line( char *key , char *val , char *delim ) {
	unsigned __len = strlen( key ) + strlen( val ) + strlen( delim ) + 1;
	char __line[__len]; memset( &__line , 0 , __len ); __line[__len] = '\0';

>>>>>>> c1e4320 (athernet V0.9)
=======
word_t __line( char *key , char *val , char *delim ) {
	unsigned __len = strlen( key ) + strlen( val ) + strlen( delim ) + 1;
	char __line[__len]; memset( &__line , 0 , __len ); __line[__len] = '\0';

>>>>>>> 1b97cf4 (broke everything)
	strcpy( __line , key );
	strcat( __line , delim );
	strcat( __line , val );
	strcat( __line , "\n" );

	return strdup( __line );
}

<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
const char *__read( __lbb *lbb_st ) {
	unsigned lbb_size = lbb_st -> lbb_stat.st_size;
	char temp[lbb_size+1];
	memset( &temp , 0 , sizeof( temp ) );
	read( lbb_st -> lbb_fd , &temp , lbb_size );
	strcat( temp , "\n" );
=======
__lbb__ __read( struct __lbb *st ) {
=======
__lbb__ __read( struct lbb_st *st ) {
>>>>>>> 1635bec (started athernet)
=======
word_t __read( struct lbb_st *st ) {
>>>>>>> 1b97cf4 (broke everything)

	unsigned lbb_size = st -> lbb_stat.st_size;
	char temp[lbb_size+1]; temp[lbb_size+1] = '\0';
	memset( &temp , 0 , lbb_size );
	read( st -> lbb_fd , &temp , lbb_size );
>>>>>>> c8122db (better structures & easier #inc_trace for hbar mainly in secondary and front-end modules)
	return strdup( temp );
}

int little_black_book( char *lbb_name ) {
=======
int little_black_book() {
	printf( "current level is :: %ld\n" , level );
>>>>>>> d369e4b (alignments)

	struct seam *lines;
	memset( &book , 0 , sizeof( struct lbb_si ) );

	unsigned _name_len = strlen( __lbb_ext );
	char const *__name = *&__lbb_ext;
	memmove( book.st.lbb_path , __name , _name_len );


	printf( "struct path :: %s\n" , book.st.lbb_path );
	switch ( lbb_check() ) {
		case 0x2:	
			#ifdef DEBUG
				printf( "-2) no lbb found, making one.\n" );
			#endif
			lbb_make();
			___next();
			break;
		case 0x1:
			#ifdef DEBUG
				printf( "-2) lbb found, loading.\n" );
			#endif
			lbb_open();
			___next();
			break;
		default:
			break;
	}

	#ifdef DEBUG
		printf( "current level is :: %ld\n" , level );
		printf( "-1) initializing lbb\n");
	#endif

	if ( lbb_status() != 0 ) {
		#ifdef DEBUG
			printf( "not zero on a zero kurl\n" );
		#endif
			printf( "lbb status cannot be determined\n" );
		return -1;
	}

	if ( lbb_descriptors() <= 0 ) {
		printf( "lbb file cannot be accessed\n" );
		return 0;
	}

	size_t t_size = lbb_size(); // total size
	#ifdef DEBUG
		printf( "lbb : size = %ld bytes\n" , t_size );	
		printf( "lbb : fd = %d\n" , book.st.lbb_fd );
	#endif

	const char *__data = __read( &book.st );
	unsigned long __len = strlen( __data );
	printf( "read :: %ld bytes\n" , __len );
	___next();


	int compilation_res = compile_lbb( __data , &lines );
	// #ifdef DEBUG
	// 	printf( "compiled : %d\n" , compilation_res );
	// 	printf( "\n lines = \n k :: %.*s\n v :: %.*s\n" , 
	// 	(int)(lines[0].key).tal , (lines[0].key).sptr , 
	// 	(int)(lines[0].wry).tal , (lines[0].wry).sptr );
	// #endif

	lbb_close();
	return 0;
}
=======
ulong little_black_book() {
=======
int little_black_book() {
>>>>>>> cf46ec7 (athernet v0)
	printf( "current level is :: %ld\n" , level );
=======
word_t __read( struct lbb_st *st ) {

	unsigned lbb_size = st -> lbb_stat.st_size;
	char temp[lbb_size+1]; temp[lbb_size+1] = '\0';
	memset( &temp , 0 , lbb_size );
	read( st -> lbb_fd , &temp , lbb_size );
	return strdup( temp );
}

int little_black_book( char *lbb_name ) {

	struct seam *lines;
>>>>>>> c1e4320 (athernet V0.9)
	memset( &book , 0 , sizeof( struct lbb_si ) );

	unsigned _name_len = strlen( lbb_name );
	char *__name = _name_len <= 3 \
		? __lbb_name : lbb_name;
	memmove( book.st.lbb_path , __name , _name_len );

	printf( "struct path :: %s\n" , book.st.lbb_path );
	if ( lbb_check( book ) == -1 ) {
		#ifdef DEBUG
			printf( "no lbb found, creating one\n" );
		#endif
		lbb_make( book );
	}
	#ifdef DEBUG
	printf( "initializing lbb\n");
	#endif
	lbb_open( book );

	if ( lbb_status( book ) != 0 ) {
		printf( "lbb status cannot be determined\n" );
		return -1;
	}

	#ifdef DEBUG
	printf( "lbb : size = %ld bytes\n" , lbb_size( book ) );	
	#endif

	if ( lbb_descriptors( book ) <= 0 ) {
		printf( "lbb file cannot be accessed\n" );
		return -2;
	}
	#ifdef DEBUG
	printf( "lbb : fd = %d\n" , book.st.lbb_fd );
	#endif

	word_t _word_all = __read(  &(book.st) );
	long _word_alen = strlen( _word_all );

	printf( "read :: %ld\n" , _word_alen );

	int compilation_res = compile_lbb( _word_all , &lines );
	if ( _word_alen < 4 ) {
		return compilation_res;
	}
	#ifdef DEBUG
		printf( "compiled : %d\n" , compilation_res );
		printf( "\n lines = \n k :: %.*s\n v :: %.*s\n" , 
		(int)(lines[0].key).tal , (lines[0].key).sptr , 
		(int)(lines[0].wry).tal , (lines[0].wry).sptr );
	#endif

	return 0;
}

<<<<<<< HEAD
>>>>>>> a415938 (kurls)

<<<<<<< HEAD
=======
>>>>>>> c1e4320 (athernet V0.9)
=======
laddr lbb_entry t_entry {

	int tmp = little_black_book();
	printf( "res lbb :: %d\n" , tmp );

	char const *argv0 = ( char * ) _;

	hallmark hm = {
		.__l = 'k',
		.__n = 2491,
		.__a = "athernet\0",
		.__k = 0x4ea585c0
	};

	__hallmark( &hm );

	return __val;
}


>>>>>>> d369e4b (alignments)
