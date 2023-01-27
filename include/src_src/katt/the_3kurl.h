// the three kurl



#define kurl3 _kurl_3
#if defined( __kurl_level )
#undef __kurl_level
#define __kurl_level 3
#endif


void _kurl_3() {
	printf( "from kurl3\n ptrsize :: %d\n" , __size_ptr( __kurl_level ) );
}

