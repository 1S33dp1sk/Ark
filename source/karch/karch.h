#ifndef __Karch_512__
#include "_h512.h"
#include "lbb.h"
#include "ixr.h"
#define OUTPUT 1
#define LOG_ERR 1
#endif

/// next \\\

// #define array(x,...) char **temp=(char const **)#__VA_ARGS__;int y=0; str x[2]; ulong _=0; do {\
// 	_+=sep_offset(temp, ",");\
// 	x[y].__=str_b4eoffset(temp, _);\
// 	x[y].__len=str_rwings(x[y].__);\
// 	*temp++;\
// 	y+=1;\
// }while(y<2);


// #include "headers/tests.d"
void log_str(char const *__) {
	write(0,__,str_rwings(__));
};

struct __num_d {
	ulong __val;
	void const *__;
	struct __num_d* __next;
};
typedef struct __num_d num;

#define number(x,...) num x; x.__val=__tonum(#__VA_ARGS__); x.__=numtochar(__VA_ARGS__); x.__next=&x;

// this should be used as a default
// for all strings, initiated once 
// at start or compile time and loaded
// via a .o or .so 
// 
struct __str_d {
	ulong __len;
	char const *__;
	struct __str_d* __next;
};
typedef struct __str_d str;
	#define __NADA__ "0"
	#define str_len(x) (ulong)(x->__len)
	#define str_val(x) (char const *)(x->__)
	#define str_nxt(x) (str *)(x->__next)
	#define string(x,y) str x; x.__=y; x.__len=str_rwings(y); x.__next=&x;

void str_out(struct __str_d __) {
	write(0, __.__, __.__len);
};

#define out_fmt(x) log_str(_Generic((x), \
	num:(char const *)(x.__),\
	str:(char const *)(x.__),\
	default:__NADA__\
))

#define out(x) out_fmt(x);
