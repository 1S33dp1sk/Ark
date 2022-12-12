#ifndef __yx__h
	#define __yx_types 1

	#define __up unsigned char *
	#define __sp char *

	#define __ui unsigned int
	#define __si int

	// unpack
	#ifndef __y__h
		__si y16i( __up __ ) { // signed 16-bit
			__ui ui = ( ( __ui )__[0]<<8 ) | __[1];
			if ( ui <= 0x7fffu ) { return ui; }
			return ( -1-( __ui )( 0xffffu - ui ) );
		}
		__ui y16u( __up __ ) { // unsigned 16-bit
			return ( ( __ui )__[0]<<8 ) | __[1];
		}
	#endif

	// pack
	#ifndef __x__h
		void x16i( __up __ , __ui i ) {
			*__++ = i>>8;	*__++ = i;
		}
	#endif

#endif

