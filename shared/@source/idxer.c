
#ifndef __IDXER__H
    #ifndef __HBAR__H
    #include "hbar.h"
    #endif
    #ifndef __ENK__H
    #include "enk.h"
    #endif
    #include <sys/stat.h>

/**
NNE(X)
     * @returns :   true if x is not 0x0000
*/
    #define NNE(v) v==0x0000?0x01:0x00

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

    uns __8sz(uns __);
    #define sz8(x) ((ulong)__8sz(x))

    ulong __fsize(char *fpath);
    #define fsze(x) ((ulong)__fsize(x))

    ulong __iosize(char *fpath);
    #define iosze(x) ((ulong)__iosize(x))

    uns __dmode(char *fpath);
    #define dmde(x) ((uns)__dmode(x))

    ulong attsize(ulong __sz);
    ulong lbbatt(uns level, ulong szatt);
    ulong fsz8(ftype __);

    static const uns ter_base[3]={0xFFFF7777,0x77771111,0x11110000};
    #define ter_t typeof(ter_base)
    // ternary system 
    // but i would rather call it
    // system ternary or `sys`&`ter`->`syster`
    static ter_t syster;

    #define __IDXER__H 1
	#define __idxer_name "indexer" 
	static uns __index_att(){
		return 0;
	}

    uns __8sz(uns _){
    	uns __=1;while(_>0){__*=8;_--;}
    	return __;
    }

    ulong __fsize(char *fpath){
    	struct stat __;
    	memset(&__,0,sizeof(struct stat));
    	if(stat(fpath,&__)!=0){return 0;}
    	return __.st_size;
    }

    ulong __iosize(char *fpath){
    	struct stat __;
    	memset(&__,0,sizeof(struct stat));
    	if(stat(fpath,&__)!=0){return 0;}
    	return __.st_blksize;
    }

    uns __dmode(char *fpath){
    	struct stat __;
    	memset(&__,0,sizeof(struct stat));
    	if(stat(fpath,&__)!=0){return 0;}
    	return __.st_mode;
    }

    #define __LO__F __MA__F<<3
    #define LockFile 64
    #define __GS__F __LO__F<<3
    #define GlobalSocketFile 512
    #define __UN__F __GS__F<<3
    #define UniversalFile 4096
    // char __size8_ref(int i){
    //     ulong __len=__8sz(i);
    //     switch(__len){
    //     case __MA__F: return 'k';
    //     case __LO__F: return '@';
    //     case __GS__F: return '/';
    //     case __UN__F: return '#';
    //     default: break;
    //     }
    //     return '_';
    // }


    ulong attsize(ulong __size){
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
        long int temp=0;
        while(__set<__size){
            temp=pwrite(fd,buf,__size,__set);
            if(temp==-1){
                printf("error pwriting\n");return 0;
            }
            __set+=temp;temp=0;
        }
        return fd;
    }


    ulong lbbatt(uns level,ulong sizeatt){
        int fd=open(".lbb",(O_RDWR|O_CREAT), S_IRWXU);
        if(fd==-1){
            printf("cannot create .lbb\n");
            return 0;
        }
        ulong lbb_iosize=iosze(".lbb");
        uns cptr=0,blk=0,chk_blocks=sizeatt&lbb_iosize,nblocks=sizeatt/lbb_iosize;
        if(chk_blocks||!nblocks){
            printf("wrong size.\noctal system handler \n");
            return 0;
        }
        ulong total=0;long int temp=0;
        uchar buf[512];
        memset(&buf,'@',(512*sizeof(uchar)));
        for(;blk<nblocks;){
            temp=pwrite(fd,buf,512,total);
            if(temp==-1){printf("error writing\n"); return 0;}
            total+=temp;temp=0;blk++;
        }
        return fd;
    }


    ulong fsz8(ftype _){
        switch(_){
            case que:return attsize(__8sz(1));
            case sok:return attsize(__8sz(2));
            case fid:return attsize(__8sz(3));
            case dir:return attsize(__8sz(4));
            case lbb_1:return lbbatt(1,__8sz(5));
            case lbb_2:return lbbatt(2,__8sz(6));
            case lbb_3:return lbbatt(3,__8sz(7));
            case lbb_4:return lbbatt(4,__8sz(8));
            default:return 0;
        }
    }



#endif
