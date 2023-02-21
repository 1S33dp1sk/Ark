/// unsigned types \\\


#ifndef __UTYPES__H
	#ifndef uns
		#define uns unsigned int
	#endif
	#ifndef uchar
		#define uchar unsigned char
	#endif
	#define __d8 unsigned long
	#define __t8 unsigned long long

typedef __d8 ulong;
typedef __t8 tlong;

// supported file types
	enum __ftypes {
	/**
	{a.k.a} FIFO **/
	    f_reader=1,
	/**
	{a.k.a} PIPE **/
	    f_socket=2,
	/**
	{a.k.a} FILE **/
	    f_field=3,
	/**
	{a.k.a} DIRECTORY **/
	    f_dir=4, 
	/**
	{a.k.a} BOOK **/
	    lbb_1, //binary
	    lbb_2, //
	    lbb_3,
	    lbb_4
	};
typedef enum __ftypes lbb_t;

// supported file sizes
	enum __ftypes__size {
	    __freader_sz=8,
	    __fsocket_sz=64,
	    __ffield_sz=512,
	    __fdir_sz=4096,
	    __lbb1_sz=32768,
	    __lbb2_sz=262144,
	    __lbb3_sz=2097152,
	    __lbb4_sz=16777216
	};
typedef enum __ftypes__size lbb_sz;

static const char *lfiles[]={"@charms/lbb/","@charms/lock","@charms/.lesfile"};

/**
 * 
 * can modify a call to 
 * `conifgure.ac` to iterate 
 * something like AC_DEFINE([__uX],[__u5],[defines a struct of 8**5])
 * and create a __uX where `X` is any number
 * for any base 8 num, obtaining the `__u64` defined by linux kernel etc.
 * 
**/

	static ulong __cindex;

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