/// ixr \\\
The indexer
#ifndef __IXR__H
	#include "utypes.h"
	#include "standard.h"

#define __FLAG_START 0x1
#define __INTERPRETER_FS 0x2
#define __FLAG_IE_PS 0x3
#define __FLAG_ES 0x4
#define __FLAG_IS 0x5
#define __FLAG__ 0x10
#define FLAG 0x100
#define __flag_interpret 16
#define __flag_indexer 228
#define __flag_handler 261
#define __flag_payload 273

	#define str_wsize(x) (str_rwings(x)*sizeof(char))
	#define ustr_wsize(x) (str_rwings(x)*sizeof(uchar))
    #define KV_FORMAT(...) __generic_fmt(__key_value, ##__VA_ARGS__) 

	static ulong __cindex=0;
	#define IDXR (const ulong) __cindex
	static ulong __ixr_fd=0x228;
	static ulong ___offset=0;

	char const *hashof(unsigned level, void const *tohash, ulong thsize);

	#define sz8(x) ((ulong)__8sz(x))
	#define fsze(x) ((ulong)__fsize(x))
	#define iosze(x) ((ulong)__iosize(x))
	#define dmde(x) ((uns)__dmode(x))
	#define inn(x) (ulong)__inodenum(x)
	#define status(x) __statusof(x)
	#define stres(x) __stres(x)

	#define INDEXER(x) x!=NULL?__indexer__(x):indexer_start()
	#define R_INDEXER(x,y) refer_index(x,y,#x)
	#define INDEX_AT (ulong)IDXR
	#define INDEX_END(x) return __set_next(x);

	#define LONG_SIZE ULONG_SIZE
	#define ULONG_SIZE ((ulong)(sizeof(ulong)))
	#define uc_size(x) ((ulong)(x*sizeof(uchar)))

	#define GET_FMT_STR(FSTR,NAR,...) do { \
		memset(&FSTR,0,(NAR*sizeof(char)));\
	}while(1!=1)

	#define __ASCII(x) OUT_ASCII(0,x)

	#define __TEXT(x) OUT_ASCII(0,#x);

	#define OUT_HEXA(fd,x) do { \
		char _[ATP_SPEC_SIZE];uchar __[ATP_BUFFER_SIZE];\
		memset(&_,0,sizeof _);memset(&__,0,sizeof __);\
		snprintf(_,sizeof _,"%s",FMT_HEXA_SPEC(x));\
		ulong pack_sz=pack(__,_,x);\
		if(pack_sz>0){write(fd,__,pack_sz);}\
	}while(1!=1)

	#define Display(...) printf("%s\n",##__VA_ARGS__);

	#define __ARGS(...) #__VA_ARGS__

	#ifndef __os_name
		#if HAVE_TARGET_CONDITIONALS_H
			#include <targetConditionals.h>
		#endif
		#if _WIN64
			#define __os_name "windows:64b\0"
		#elif _WIN32
			#define __os_name "windows\0"
		#elif defined(TARGET_OS_IPHONE)
			#define __os_name "apple:iphone\0"
		#elif defined(TARGET_OS_MAC)
			#define __os_name "apple:macos\0"
		#elif __APPLE__!=0
			#define __os_name "apple\0"
		#elif __linux__!=0
			#define __os_name "unix:linux\0"
		#elif __ANDROID__!=0
			#define __os_name "unix:android\0"
		#elif BSD
			#define __os_name "bsd\0"
		#elif __unix__
			#define __os_name "unix\0"
		#else
			#define __os_name "\0"
		#endif
	#endif

	void log_fmt_t(fmt_t __format);
	char const *__gdelim(fmt_t __gtype);
	char const *__generic_fmt(fmt_t _gtype, char const *__key, char const *__value);





	#define __IXR__H 1
#endif