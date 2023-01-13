// the zero kurl

extern kurl_t kurl;

#define kurl0 _kurl_0
#define __kurl_level 0

#include "../lbb/lbb.h"
#include "../point/point.h"

// access ( good || deny )
// 

void _kurl_0() {
	int res = 0;
	res = little_black_book( __lbb_name );
	printf( "lbb res :: %d\n" , res );
	printf( "( lbb fd :: %d)\n" , book.st.lbb_fd );
}

