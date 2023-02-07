#ifndef __TER__H
	#include <unistd.h>
	#include <sys/stat.h>
	#include <fcntl.h>
	#include <stdio.h>
	#include <string.h>
	#include <stdlib.h>
	#include "utypes.h"
	#include "idxer.h"
	#include "zenv.h"
#define TERNARY_LEVELS 3



	static size_t *__field__(char const *filename,ulong filelines,ulong datasize);
	static uchar *__header(uchar *__,char const *filename,ulong filelines,ulong datasize);
	static const ulong __hlen=256;
	static const ulong __hsize=256*sizeof(uchar);
	static const char *__fmt_header="__s_L_L__s\0";
	static ulong __rf=0;
	static ulong __eout=0;
	static ulong __fdlo=0;

	enum _ud {
		u__='u',
		__d='d',
	};

	#define updown(x) ((ulong)((enum _ud)(x)))
	// static updown __ud(uchar __);
	static ulong tests();
	char *__dofl(ulong __);
	// ulong __fw_att(char const *__f,ulong __w__,ulong offset);

	ulong const blazing_hash(void *);

	// hash string
	struct __vsr {
	    ulong __len;
	    ulong __hash;
	    uchar*__str;
	};


	#define vstr struct __vsr



	#define sarg(x) ((uns)(x->__str))
	#define larg(x) ((uns)(x->__len))
	#define harg(x) ((uns)(x->__len=strlen(x->__str)))


	ulong const blazing_hash(void *_){


	    return (ulong)0x3;
	}






	#define __TER__H TERNARY_LEVELS
#endif