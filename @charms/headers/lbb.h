#ifndef __LBB__H
	#include <string.h>
	#include <sys/types.h>
	#include <stdarg.h>
	#include "utypes.h"
	#define __lbb_cregex "\\(^[a-zA-Z0-9]*\\)[=:]\\{1,\\}\\([a-zA-Z0-9]*\\)$"
	#define __R_SEP '\n'
	#define __K_SEP '#'
	#define __V_SEP ':'
	#define __T_SEP '='
	#define __A_SEP '@'
	#define __LBB_KEY_SIZE 0x4<<0x6
	#define MAX_LBB_FIELD 512
	#define levels_supported 4

	struct shard__ {
		char __key[256];
		ulong __fd;
		ulong __size;
		ulong __iosz;
	};
typedef struct shard__ shard_st;
typedef shard_st* shard_p;

	#define stsize(x) (ulong)x.st_size
	#define stiosize(x) (ulong)x.st_blksize

	static shard_st LBB_SHARD;
	#define arc_shard (&LBB_SHARD)

	#define key_shard(x) (char *)x.__key
	#define fld_shard(x) (ulong)x.__fd
	#define sze_shard(x) (ulong)x.__size
	#define ioz_shard(x) (ulong)x.__iosz

	#define shd_fd fld_shard(LBB_SHARD)
	#define shd_key key_shard(LBB_SHARD)
	#define shd_sze sze_shard(LBB_SHARD)
	#define shd_io sze_shard(LBB_SHARD) 

	int lbb();

	#define __LBB__H 1
#endif






/// little black book \\\

#ifndef __LBB__H
#include "lbb.h"
#endif
#ifndef __lbb_name
	#define __lbb_name "linked binary book"
/**
 * the lbb is what is known as a 
 * `singular` || `singelton`
 * which is a single instance of this header
 * is to be defined at any time, generally
 * at the time of inception of the `Lockfile`
**/ 
	// must return 0
	int lbb_init(char *cnpath){
		if(cnpath==NULL){
			printf("initiating lbb at a NULL path have undefiend behavior\n");
			return 1;
		}
		// init lbb shard
		shard_st __shard=LBB_SHARD;
		memset(&__shard,0,sizeof(shard_st));
		// init lbb c-name-path
		ulong cn_len=strlen(cnpath);
		if(cn_len>__LBB_KEY_SIZE){
			printf("lbb-shard : key is not 256bytes\n");
			return 2;
		}
		memmove(__shard.__key,cnpath,cn_len);
		// get file descriptor
		int _fd=open(__shard.__key,O_RDWR);
		if(_fd==-1){
			printf("lbb-shard : `%s` cannot be opened\n",__shard.__key);
			return 3;
		}
		__shard.__fd=_fd;
		// get the file stats
		struct stat stat_st;
		memset(&stat_st,0,sizeof(struct stat));
		if(stat(__shard.__key,&stat_st)!=0){
			printf("lbb-shard : stat cannot be obtained\n");
			return 4;
		}
		__shard.__size=stsize(stat_st);
		__shard.__iosz=stiosize(stat_st);
		return 0;
	}

	ulong __writeb(uchar *content,uns c_size) {
		ulong __fd=shd_fd;
		if(__fd!=0){
			ulong _size = (ulong)write(__fd,content,c_size);
			printf( "resof write :: %lu\n",_size);
			return _size;
		}	
		return 0;
	}

	char *__readb(){
		ulong __res=0,__fsz=shd_sze,__fd=shd_fd;
		uchar lbb_content[__fsz+1];
		__res=read(__fd,lbb_content,__fsz);
		if(__res==-1){
			printf("cannot read lbb\n");
			return NULL;
		}
		lbb_content[__fsz+1]='\0';
		if((__res<__fsz)&&(__res>0)){
			// means that reading was interuptted
			// for some reason, like a pipe or sig
			// so we can read from where we left off
			__res=pread(__fd,(lbb_content+__res),(__fsz-__res),__res);
		}
		return strdup((char*)lbb_content);
	}

	void __closeb(){
		close(shd_fd);
		memset(&LBB_SHARD,0,sizeof(shard_st));
	}

	ulong __fillb(){ // create &-> fill the book
		ulong __res=__writeb(shd_key,__LBB_KEY_SIZE);
		__closeb();
		return __res;
	}

	int lbb(){
		int res=lbb_init("Lockfile");
		return res;
	}

#endif