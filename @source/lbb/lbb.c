#include "lbb.h"

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
	printf( "string : \"%.*s\"" , ( int ) __sota -> tal , __sota -> sptr );
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
		#ifdef DEBUG
			printf( "no lbb found, creating one\n" );
		#endif
		create( ud );
	}
	else {
		#ifdef DEBUG
		printf( "lbb found, initializing...\n");
		#endif
		init( ud );
	}

	if ( !status( ud ) ) {
		printf( "lbb status cannot be determined\n" );
		return -1;
	}
	#ifdef DEBUG
	printf( "lbb : size = %ld bytes\n" , size( ud ) );	
	#endif

	if ( ud.lbb_fd <= 0 ) {
		printf( "lbb file cannot be accessed\n" );
		return -2;
	}
	#ifdef DEBUG
	printf( "lbb : fd = %d\n" , ud.lbb_fd );
	#endif

	int compilation_res = compile_lbb( __read( &ud ) , &lines );
	#ifdef DEBUG
		printf( "compiled : %d\n" , compilation_res );
		printf( "\n lines = \n k :: %.*s\n v :: %.*s\n" , 
		(lines[0].key).tal , (lines[0].key).sptr , 
		(lines[0].wry).tal , (lines[0].wry).sptr );
	#endif

	cleanup( ud , lines );

	return compilation_res;
}

