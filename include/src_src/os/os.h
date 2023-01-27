
#ifdef __macOS_get_sys_vars
	#ifndef __macOS_x_byteorder
		#define __macOS_x_byteorder "hw.byteorder"
		#define x_byteorder __byteorder 
		#include <sys/sysctl.h>
		int __byteorder;
		size_t __len = sizeof( __byteorder );
		sysctlbyname( __macOS_x_byteorder , &__byteorder , &__len , NULL , 0 );
		printf( "byteorder :: %d\n" , __byteorder );
	#endif
#endif
