#ifndef __IDXER__H
#include "idxer.h"
#endif
#ifndef __idxer_name
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



#endif
