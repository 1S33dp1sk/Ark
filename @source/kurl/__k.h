#ifndef klevels
	#define klevels 7

	#define __ki 4
	#define __kii 8
	#define __kiii 16
	#define __kiv 32
	#define __kv 64
	#define __kvi 128
	#define __kvii 256
#endif

#if defined( ik ) && !defined( __ik )
	#define __ik ik
	#ifndef kurl_at
		#define kurl_at __kurl_at
		int __kurl_at() {
			printf( "kurl @ %d\n" , __ik );
			return __ik;
		}
	#endif

#if ( __ik <= 4 )
	#ifdef att
		#undef att
	#endif
	#define att ( ( int ) ( atherpoint() ) )
#endif




	
#elif ( __ik <= 8 )
	#ifdef att
		#undef att
	#endif
	#define att ( ( int ) (  ) )

#endif




























































#endif