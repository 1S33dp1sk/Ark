/// fields \\\
#key:value=type@address
#ifndef __LBB__H
	#include <string.h>
	#include <fcntl.h>
	#include <sys/stat.h>
	#include "utypes.h"
	#include "idxer.h"
	#include <sys/types.h>
	#include <unistd.h>
	#include <stdarg.h>
	#define __lbb_cregex "\\(^[a-zA-Z0-9]*\\)[=:]\\{1,\\}\\([a-zA-Z0-9]*\\)$"
	#define __lbb_ext ".lbb"
	#define CAN_COMPILE 0

	#define __R_SEP '\n'
	#define __K_SEP '#'
	#define __V_SEP ':'
	#define __T_SEP '='
	#define __A_SEP '@'
	#define __LBB_KEY_SIZE ((uns)256)
	#define __LBB_ATT "../.lbb"

	static uchar __key[256];
	static uns __fd=0;
	static ulong __fsz=0;
	static ulong __iosz=0;



	int append_field();
	int change_field();
	int remove_recrod();
	int count_fields();
	int init_field(uns lvl,char const*key,char const*ftypes,...);

	uns islvl(uchar c);
	uchar *lbb_key(uchar const *__);

	#define get_lbb __get_lbb

	int __get_lbb(){
		struct stat __;
		memset(&__,0,sizeof(struct stat));
		if(stat(__LBB_ATT,&__)!=0){return -1;}
		__fd=open(__LBB_ATT,O_RDWR);
		__fsz=__.st_size;
		__iosz=__.st_blksize;
		return __fd;
	}

	uns __get_fd(uns __flag){
		if(!__fd){
			if((__fd=open(__LBB_ATT,__flag,S_IRWXU))==-1){return 0;}
			__fsz=fsze(__LBB_ATT);
			__iosz=iosze(__LBB_ATT);
		}
		return __fd;
	}

	size_t __writeb(uchar *content,uns c_size) {
		if(__fd!=0){
			size_t _size = write(__fd,content,c_size);
			printf( "resof write :: %zd\n",_size);
			return _size;
		}	
		return 0;
	}

	// call `__get_lbb()` before
	// must be already initialized
	uchar *__readb(){
		size_t __res=0;
		uchar lbb_content[__fsz+1];
		__res=read(__fd,lbb_content,__fsz);
		if(__res==-1){return "";}
		lbb_content[__fsz+1]='\0';
		if((__res<__fsz)&&(__res>0)){
			// means that reading was interuptted
			// for some reason, like a pipe or sig
			// so we can read from where we left off
			__res=pread(__fd,(lbb_content+__res),(__fsz-__res),__res);
		}
		return strdup(lbb_content);
	}

	void __closeb(){
		close(__fd);
	}

	uns get_fd(){
		#ifdef DEBUG
		printf("creating lbb file :: ");
		#endif
		uns __res=0;
		if(!(__res=__get_fd(O_CREAT|O_RDWR|O_EXCL))){
			#ifdef DEBUG
			printf("failed.\n checking read/write :: ");
			#endif
			if(!(__res=__get_fd(O_RDWR))){
				#ifdef DEBUG
				printf("failed.\n checking read :: ");
				#endif
				__res= __get_fd(O_RDONLY);
				#ifdef DEBUG
				printf(__res==0?"failed.\n":"success.\n");
				#endif
				return __res;
			}
			else{
				#ifdef DEBUG
				printf("success.\n");
				#endif
				return __res;
			}
		}
		else{
			#ifdef DEBUG
			printf("success.\n");
			#endif
			return __res;
		}
		return __res;
	}

	uns __fillb(){ // create &-> fill the book
		uns __res=0;
		__res=get_fd();
		if(__res)
			__res=__writeb(__key,__LBB_KEY_SIZE);
		__closeb();
		return __res;
	}

	uns __makefill(){ // fill file with 256*`K`
		memset(&__key,'K',__LBB_KEY_SIZE);
		uns __res=__fillb();
		return __res;
	}

	uns __get_process_flags(){
		return dmde(__LBB_ATT);
	}

	uns __check_lbb_file(){
		if(fsze(__LBB_ATT)<__LBB_KEY_SIZE){
			return 0;
		}
		return 1;
	}

	uns __make_lbb_file(){
		return __makefill();
	}
	#define __LBB__H 1
#endif






