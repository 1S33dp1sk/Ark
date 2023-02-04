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


uns __8sz(uns _){
	uns __=1;while(_>0){__*=8;_--;}
	return __;
}
#define sz8(x) ((ulong)__8sz(x))

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

enum __ftypes {
    que=1, //queue_idx
    sok=2, //socket_addr
    fid=3, //field
    dir=4, //directory
    lbb_1, //binary
    lbb_2, //
    lbb_3,
    lbb_4
};
#define ftype enum __ftypes

size_t att(ulong __size){
    int fd=open(".lbb",(O_RDWR|O_CREAT), S_IRWXU);
    if(fd==-1){
        printf("cannot create .lbb\n");
        return 0;
    }
    uchar buf[__size];
    memset(&buf,'#',(__size*sizeof(char)));
    uchar *buffer=buf;
    if(buffer==NULL){printf("not enough cache memory\n");return 0;}
    ulong __set=0;
    ssize_t temp=0;
    while(__set<__size){
        temp=pwrite(fd,buf,__size,__set);
        if(temp==-1){
            printf("error pwriting\n");return 0;
        }
        __set+=temp;temp=0;
    }
    return __set;
}

#define fatt att
#define satt att
#define fitt att
#define datt att

size_t lbb(uns level,ulong __size){
    int fd=open(".lbb",(O_RDWR|O_CREAT), S_IRWXU);
    if(fd==-1){
        printf("cannot create .lbb\n");
        return 0;
    }
    ulong lbb_iosize=iosze(".lbb");
    uns cptr=0,blk=0,chk_blocks=__size&lbb_iosize,nblocks=__size/lbb_iosize;
    if(chk_blocks||!nblocks){
        printf("wrong size.\noctal system handler \n");
        return 0;
    }
    size_t total=0;ssize_t temp=0;
    uchar buf[512];
    memset(&buf,'@',(512*sizeof(uchar)));
    for(;blk<nblocks;){
        temp=pwrite(fd,buf,512,total);
        if(temp==-1){printf("error writing\n"); return 0;}
        total+=temp;temp=0;blk++;
    }
    return total;
}


size_t fsz8(ftype _){
    switch(_){
        case que:return att(__8sz(1));
        case sok:return satt(__8sz(2));
        case fid:return fitt(__8sz(3));
        case dir:return datt(__8sz(4));
        case lbb_1:return lbb(1,__8sz(5));
        case lbb_2:return lbb(2,__8sz(6));
        case lbb_3:return lbb(3,__8sz(7));
        case lbb_4:return lbb(4,__8sz(8));
        default:return 0;
    }
}













