#include "lbb.h"
<<<<<<< HEAD
<<<<<<< HEAD

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <regex.h>



const char *__read( __lbb *lbb_st );
const char *__line( char *key , char *val , char *delim );
int __regex_lbb( char const *lbb_contents );


void log_sota( struct sota *__sota ) {
	#ifdef VERBOSE_DEBUG
	printf( " ---sota---\n " );
	#endif
	printf( "string : \"%.*s\"" , __sota -> tal , __sota -> sptr );
	printf( " :: offset = %jd; len = %jd\n" , __sota -> offset , __sota -> tal );
}

int lbb_append( __lbb *lbb_st , char *key , char *val ) {
	#ifdef DEBUG
		printf( "lbb -> \n\tadding %s :: %s\n" , key , val );
	#endif

	const char *prev = __read( lbb_st );
	const char *curr = __line( key , val , ":" );
	char total[strlen( prev ) + strlen( curr )];
	strcpy( total , prev );
	strcpy( total , curr );
	int b_written = write( lbb_st -> lbb_fd , total , strlen( total ) );
	
	#ifdef DEBUG
		printf( "wrote %d bytes\n" , b_written );
	#endif

	return b_written;
}

int lbb_query( __lbb *lbb_st , char *key ) {

	char const *s = __read( lbb_st );
	printf( "lbb :: \n%s\n" , s );
}

int compile_lbb( char const *rlbb , struct seam **__lines ) {
=======
// #define DEBUG
=======
#define DEBUG
>>>>>>> cf46ec7 (athernet v0)


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

#ifndef __lbb_raw__
	#define __lbb_raw__ "KW"
	char *_raw_kei( kei __kei ) {
		if( ( __kei.k != NULL ) && ( __kei.i__size != 0 ) ) {
			char __raw[__kei.i__size];
			memset( &__raw , 0 , sizeof( __kei.i__size )*sizeof( char ) );
			memcpy( __raw , __kei.k , __kei.i__size );
			return strdup( __raw );
		}
		return NULL;
	}
	char *_raw_word( word __word ) {
		unsigned __len_v = __word.v.i__size, __len_a = __word.a.i__size;
		unsigned __len_total = __len_v + __len_a + 3; 
		char __raw[__len_total];
		__raw[__len_total] = '\0';
		memcpy( __raw , _raw_kei( __word.v ) , __word.v.i__size );
		memcpy( __raw , __word.l , 2 );
		memcpy( __raw , _raw_kei( __word.a ) , __word.a.i__size );
		return strdup( __raw );
	}
#endif

entry_t __word( char *key , char *val , char *delim ) {
	unsigned __len = strlen( key ) + strlen( val ) + strlen( delim ) + 1;
	char __line[__len]; memset( &__line , 0 , __len ); __line[__len] = '\0';

	strcpy( __line , key );
	strcat( __line , delim );
	strcat( __line , val );
	strcat( __line , "\n" );

	return strdup( __line );
}

entry_t __read( struct lbb_st *st ) {
	unsigned lbb_size = st -> lbb_stat.st_size;
	char temp[lbb_size+1]; temp[lbb_size+1] = '\0';
	memset( &temp , 0 , lbb_size );
	read( st -> lbb_fd , &temp , lbb_size );
	return strdup( temp );
}

char *__hallmark( hallmark *__ ) {
	char __hal[max_str];
	return strdup( __hal );
}

int lbb_append( struct lbb_si*__ , char *key , char *val ) {
	#ifdef DEBUG
		printf( "lbb -> \n\tadding %s :: %s\n" , key , val );
	#endif

	const char *prev = __read( &__ -> st );
	const char *curr = __word( key , val , ":" );
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

int compile_lbb( char const *rlbb , word **__words ) {
>>>>>>> a415938 (kurls)

	char const *__s = rlbb;
	regex_t     regex;
	regmatch_t  pmatch[3];
	regoff_t    k_off, v_off , k_len , v_len;

<<<<<<< HEAD
	if ( regcomp( &regex , __lbb_regex , REG_NEWLINE ) ) {
		return 1;
	}

	#ifdef DEBUG
		printf("lbb>compiling\n");
	#endif

	struct sota _k , _w;
=======
	#ifdef DEBUG
		printf("lbb>compiling\n");
	#endif
	if ( regcomp( &regex , __lbb_regex , REG_NEWLINE ) ) {
		return 1;
	}

	kei _k , _w;
>>>>>>> a415938 (kurls)
	int __iter = 0;

	for ( ; ; __iter++ ) {

		if ( regexec( &regex, __s , arr_size( pmatch ) , pmatch , 0 ) ) {
			break;
		}
		memset( &_k , 0 , sizeof( _k ) );
		memset( &_w , 0 , sizeof( _w ) );

<<<<<<< HEAD
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
=======
		_k.e__set = ( intmax_t ) ( pmatch[1].rm_so + ( __s - rlbb ) ); 
		_k.i__size = ( intmax_t ) ( pmatch[1].rm_eo - pmatch[1].rm_so );
		_k.k = ( char * ) __s + pmatch[1].rm_so;

		printf( "key -> \"%.*s\"\n", _k.i__size , _k.k + pmatch[1].rm_so );

		_w.e__set = ( intmax_t ) ( pmatch[2].rm_so + ( __s - rlbb ) );
		_w.i__size = ( intmax_t ) ( pmatch[2].rm_eo - pmatch[2].rm_so );
		_w.k = ( char * ) __s + pmatch[2].rm_so;

		#ifdef DEBUG
			printf( "-------->#%d:\n", __iter );
			printf( "k :: %s\n" , _k.k );
			printf( "w :: %s\n" , _w.k );
		#endif

<<<<<<< HEAD

		// ( *__words + __iter ) -> v = _k;
		// ( *__words + __iter ) -> a = _w;
>>>>>>> a415938 (kurls)
=======
		( *__words + __iter ) -> v = _k;
		( *__words + __iter ) -> a = _w;
>>>>>>> cf46ec7 (athernet v0)

		__s += pmatch[0].rm_eo;
	}

	regfree( &regex );
<<<<<<< HEAD
=======
	#ifdef DEBUG
		printf("lbb>compiled\n");
	#endif
>>>>>>> a415938 (kurls)

	return 0;
}

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

		__s += pmatch[0].rm_eo;
	}

	regfree( &regex );

	return 0;
}

<<<<<<< HEAD

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

const char *__read( __lbb *lbb_st ) {
	unsigned lbb_size = lbb_st -> lbb_stat.st_size;
	char temp[lbb_size+1];
	memset( &temp , 0 , sizeof( temp ) );
	read( lbb_st -> lbb_fd , &temp , lbb_size );
	strcat( temp , "\n" );
	return strdup( temp );
}


int little_black_book( char *p_name ) {

	struct seam *lines;

	__lbb ud;
	memset( &ud , 0 , sizeof( ud ) );
	strcpy( ud.lbb_path , __LBB_NAME );

	if ( exists( ud ) == -1 ) {
		printf( "no lbb found, creating one\n" );
		create( ud );
	}
	else {
		printf( "lbb found, initializing...\n");
		init( ud );
	}

	if ( !status( ud ) ) {
		printf( "lbb status cannot be determined\n" );
		return 1;
	}
	printf( "lbb : size = %d bytes\n" , size( ud ) );	

	if ( ud.lbb_fd <= 0 ) {
		printf( "lbb file cannot be accessed\n" );
		return 2;
	}
	printf( "lbb : fd = %d\n" , ud.lbb_fd );


	int compilation_res = compile_lbb( __read( &ud ) , &lines );
	
	printf( "compiled : %d\n" , compilation_res );

	#ifdef DEBUG
		printf( "\n lines = \n k :: %.*s\n v :: %.*s\n" , 
		(lines[0].key).tal , (lines[0].key).sptr , 
		(lines[0].wry).tal , (lines[0].wry).sptr );
	#endif

	cleanup( ud , lines );

	return compilation_res;
}
=======
ulong little_black_book() {
=======
int little_black_book() {
>>>>>>> cf46ec7 (athernet v0)
	printf( "current level is :: %ld\n" , level );
	memset( &book , 0 , sizeof( struct lbb_si ) );

	word *words;
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


	int compilation_res = compile_lbb( __data , &words );
	// #ifdef DEBUG
	// 	printf( "compiled : %d\n" , compilation_res );
	// 	printf( "\n words = \n k :: %.*s\n v :: %.*s\n" , 
	// 	(int)(words[0].v).i__size , (words[0].v).k , 
	// 	(int)(words[0].a).i__size , (words[0].a).k );
	// #endif

	lbb_close();
	return 0;
}

laddr lbb_entry t_entry {

	int tmp = little_black_book();
	printf( "res lbb :: %d\n" , tmp );

	char const *argv0 = ( char * ) _;

	return __val;
}

int lbb_add_line( entry_t _l ) {
	int x = -1;
	if ( book.st.lbb_fd > 0 ) {
		int x = write( book.st.lbb_fd , _l , strlen( _l )*sizeof( char ) );
		printf( "fd : %d : wrote x :: %d bytes\n" , book.st.lbb_fd , x );
	}
	return x;
}

int lbb_add_hallmark(){
	unsigned char *at_name = "@karam";
	hallmark hm = {
		.__k = '@',
		.__a = ':',
		._y_ = '0',
		._a = at_name,
		.n = 0,
	};
	printf( "\n%c%c%c%s%d\n" , \
		hm.__k,
		hm.__a,
		hm._y_,
		hm._a,
		hm.n
	);
	// memset( &hm , 0 , sizeof( hallmark ) );
}

>>>>>>> a415938 (kurls)

