/// idxer \\\
ternary (:

#include "utypes.h"
#include "hbar.h"
#include "enk.h"
#include <sys/stat.h>

#define arr_size(x) ((ulong)(sizeof(x)/sizeof(x[0])))

/**
 * ternary base is what determines
 * the main permissions in the system.
 * 
 * Permissions are divided into 2 main parts:
 * 1.	File type
 * a simple 2 bit/1 byte solution to determine the 
 * known type of the file. i.e: FIFO,Socket,Storage...
 &-> 
 * 2.	Access
 * With `Access` that's where the ternary actually 
 * shines. As it is divided into 3 main parts
 * a.	Root `file created-on`
 * b.	User `file use-by`
 * c.	Public `file accessible-to` 
 * 
 * the three different numbers determine the actual
 * R-W-X assignable values.
 * 
 * Keep in mind that all of the following code is based
 * on the current machines and their operations. Thus,
 * we are simulating a ternary system on a binary machine.
 * 
**/ 
static const uns ter_base[3]={0xFFFF7777,0x77771111,0x11110000};
#define ter_t typeof(ter_base)
// ternary system 
// but i would rather call it
// system ternary or `sys`&`ter`->`syster`
static ter_t syster;


uns __8rsz(uns _){
	uns __=1;while(_>0){__*=8;_--;}
	return __;
}
#define rsze(x) ((ulong)__8rsz(x))

ulong __fsize(char *fpath){
	struct stat __;
	memset(&__,0,sizeof(struct stat));
	if(stat(fpath,&__)!=0){return 0;}
	return __.st_size;
}
#define fsze(x) ((ulong)__fsize(x))

ulong __iosize(char *fpath){
	struct stat __;
	memset(&__,0,sizeof(struct stat));
	if(stat(fpath,&__)!=0){return 0;}
	return __.st_blksize;
}
#define iosze(x) ((ulong)__iosize(x))

uns __dmode(char *fpath){
	struct stat __;
	memset(&__,0,sizeof(struct stat));
	if(stat(fpath,&__)!=0){return 0;}
	return __.st_mode;
}
#define dmde(x) ((uns)__dmode(x))


// name must be 3 chars here
static ullng field_name(char *name,ulong csize){
    ullng __res=0;
    ulong _ures=0,__size=9; //(sizeof(ulong))+(5*sizeof(char))\\;
    uchar *__=malloc(__size);
    if(__==NULL){return 0;}
    memset(__,0,sizeof(__size));
    size_t step=__size/3;
    memmove(__,name,step);
    char *__idx=(char*)__+step;
    // printf("__ : %p\n__idx : %p\n",__,__idx);
    // printf("%s\n",__idx-3);
    memmove(__idx,":",1);
    uchar *__xer=(uchar *)&__idx+1;
    ulong __packed=0;
    if((__packed=pack(__xer,"L",csize))!=4){
        printf("error packing L in xer\n"); 
        return 0;
    }
    unpack(__xer,"L",&_ures);
    
    if(__[__size]=='\0'){
        printf("%s",__);
        printf("%08x%08x",u[0],u[1]);
        printf("k+%llu\n",_ures);
        *u=hash16(3,__,8);
    }
    return __res;
}
















