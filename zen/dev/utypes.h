#ifndef __UTYPES__H
	#ifndef uns
		#define uns unsigned int
	#endif
	#ifndef uchar
		#define uchar unsigned char
	#endif
// //can modify a call to 
// // `conifgure.ac` to iterate 
// // something like AC_DEFINE([__uX],[__u5],[defines a struct of 8**5])
// // and create a __uX where `X` is any number
// // for any base 8 num
// struct _u2st {
// 	unsigned long _1;
// 	unsigned long _2;
// };
// static const struct _u2st __u0={._1=0,._2=0};
// #define _u2s struct __u2
// #define ret_su struct __u2 *
// #define retSU(ret__) struct __u2 __={._1=ret__[0];._2=ret__[1]}

// static unsigned long u[2];
// #define u2_t typeof(u)
	#ifndef ulong
		#define ulong long 
	#endif
	#ifndef ullng
		#define ullng unsigned long long
	#endif
#define __UTYPES__H 1
#endif