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
	int refer_index(void *__ptr, void *__ref, char *__prname);

	static ulong __cindex=0;
	#define IDXR (const ulong) __cindex
	static ulong __ixr_fd=0x228;
	static ulong ___offset=0;

	#define d512_read(d,o) (char const *)__readb(512,fd,fo*512)
	#define sz8(x) ((ulong)__8sz(x))
	#define fsze(x) ((ulong)__fsize(x))
	#define iosze(x) ((ulong)__iosize(x))
	#define dmde(x) ((uns)__dmode(x))
	#define inn(x) (ulong)__inodenum(x)
	#define status(x) __statusof(x)
	#define stres(x) __stres(x)

	#define INDEXER(x) x!=NULL?__indexer__(x):indexer_start()
	#define INDEX_AT (ulong)IDXR
	#define INDEX_END(x) return __set_next(x);

	#define LONG_SIZE ULONG_SIZE
	#define ULONG_SIZE ((ulong)(sizeof(ulong)))
	#define uc_size(x) ((ulong)(x*sizeof(uchar)))


	void log_fmt_t(fmt_t __format);
	char const *__gdelim(fmt_t __gtype);
	char const *__generic_fmt(fmt_t _gtype, char const *__key, char const *__value);
	#define __IXR__H 1
#endif