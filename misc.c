#include <stdio.h>
#include <regex.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <stdint.h>
#define arr_size( _ ) ( sizeof( _ ) ) / ( sizeof( ( _ )[0] ) )


// #define __lbb_regex "\\(^[a-zA-Z0-9]*\\)[=:]\\{1,\\}\\([a-zA-Z0-9]*$\\)"
#define __lbb_regex "\\(^[a-zA-Z0-9]*\\)[:=]\\{1,\\}\\([a-zA-Z0-9]*$\\)"


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


int __regex_lbb( char const *rlbb ) {

	char const *__s = rlbb;
	regex_t     regex;
	regmatch_t  pmatch[3];
	regoff_t    k_off, v_off , k_len , v_len;

	printf("lbb : raw => \n------>\n%s<------\n", __s);

	if ( regcomp( &regex , __lbb_regex , REG_NEWLINE ) ) {
		return 1;
	}

	printf( "regex compiled\n" );

	int __iter = 0;

	kei _at , _addr;


	for ( ; ; __iter++ ) {
		
		if ( regexec( &regex, __s , arr_size( pmatch ) , pmatch , 0 ) ) {
			break;
		}

		memset( &_at , 0 , sizeof( kei ) );
		memset( &_addr , 0 , sizeof( kei ) );


		printf( "match (%d) >\n", __iter );

		k_off = pmatch[1].rm_so + (__s - rlbb);
		k_len = pmatch[1].rm_eo - pmatch[1].rm_so;

		printf( "\tkey (offset) = %jd; key (length) = %jd\n", (intmax_t) k_off , (intmax_t) k_len);
		printf( "\tkey -> \"%.*s\"\n", k_len , __s + pmatch[1].rm_so );


		v_off = pmatch[2].rm_so + ( __s - rlbb );
		v_len = pmatch[2].rm_so - pmatch[2].rm_so;


		printf( "\tkey (offset) = %jd; key (length) = %jd\n", (intmax_t) v_off , (intmax_t) v_len);
		printf( "\tkey -> \"%.*s\"\n", v_len , __s + pmatch[2].rm_so );


		__s += pmatch[0].rm_eo;
	}
	regfree( &regex );

	if ( !__iter ) {
		printf( "no matches found.\n" );
	}

	return __iter;
}

int main() {

	char _f[1024];
	memset( &_f , 0 , 1024*sizeof(char) );

	int fd = open( ".lbb" , O_RDONLY );
	printf("fd :: %d\n" , fd );
	
	int b_read = read( fd , &_f , 1024 );
	printf( "bytes read :: %d\n" , b_read );

	__regex_lbb( _f );

	close( fd );
}