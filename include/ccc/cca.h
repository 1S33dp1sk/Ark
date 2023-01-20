// connected charm address
// CCA

#ifdef HAVE_UNISTD_H
	#include <unistd.h>
	#include <fcntl.h>
	#include <sys/types.h>
	#include <sys/stat.h>
	#ifdef __lbb_location
		#ifndef ulong
			#define ulong unsigned long
		#endif
		#ifndef uchar
			#define uchar unsigned char
		#endif
		ulong kmem_resv( ulong m_size , uchar i_val ) {
			int _ = open( __lbb_location , ( O_CREAT | O_RDWR ) , ( S_IRWXU | S_IRWXG | S_IRWXO ) );
			ulong b_written = 0;
			if ( _ != -1 ) {
				uchar buf[m_size];
				memset( &buf , i_val , m_size );
				b_written = write( _ , buf , m_size );
			}
			return b_written;
		}
	#endif
#endif

#ifdef kmem_resv
	ulong kmem_resv( ulong m_size , uchar i_val );

	int main( int argc , char const *argv ) {

	if( argc <= 1 ) {
		return argc;
	}

	const char __switcher = argv[1][0];

	switch( __switcher ) {
		case 'm':
			return kmem_resv( __sa__pi , 'k' ) == 0;
		default:
			return 1; 
	}

	return -1;
}
#endif