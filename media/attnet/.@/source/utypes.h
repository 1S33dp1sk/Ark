/// unsigned types \\\


#ifndef __UTYPES__H
	#ifndef uns
		#define uns unsigned int
	#endif
	#ifndef uchar
		#define uchar unsigned char
	#endif
	#define __d8 unsigned long

typedef __d8 ulong;
	// #define ulong unsigned long long int
	/**
	 * 
	 * can modify a call to 
	 * `conifgure.ac` to iterate 
	 * something like AC_DEFINE([__uX],[__u5],[defines a struct of 8**5])
	 * and create a __uX where `X` is any number
	 * for any base 8 num, obtaining the `__u64` defined by linux kernel etc.
	 * 
	**/
	struct _u2st {
		unsigned long _1;
		unsigned long _2;
	};
	static const struct _u2st __u0={._1=0,._2=0};
	#define _u2s struct __u2
	#define ret_su struct __u2 *
	#define retSU(ret__) struct __u2 __={._1=ret__[0];._2=ret__[1]}
	static unsigned long u[2];

	
	#define __UTYPES__H 1
#endif