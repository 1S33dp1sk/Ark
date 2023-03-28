// the one kurl



#define kurl1 _kurl_1
#if defined( __kurl_level )
#undef __kurl_level
#define __kurl_level 1
#endif


void _kurl_1() {
	printf( "from kurl1\n ptrsize :: %d\n" , __size_ptr( __kurl_level ) );
}

