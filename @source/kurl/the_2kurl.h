// the two kurl



#define kurl2 _kurl_2
#if defined( __kurl_level )
#undef __kurl_level
#define __kurl_level 2
#endif


void _kurl_2() {
	printf( "from kurl2\n ptrsize :: %d\n" , __size_ptr( __kurl_level ) );
}

