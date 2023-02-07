#ifndef __TER__H
#include "ternary.h"
#endif

#ifndef __c_ternary__

extern const ulong __hlen;
extern const ulong __hsize;
extern const char *__fmt_header;
extern ulong __rf;
extern ulong __eout;
extern ulong __fdlo;
extern char **environ;


static size_t *__field__(char const *filename,ulong filelines,ulong datasize) {
	// free the tracker
	size_t *tracker=malloc((3*sizeof(size_t)));
	static uchar header[256];
	uchar *_header=__header(header,filename,filelines,datasize);

	return tracker;
}
static uchar *__header(uchar *__,char const *filename,ulong filelines,ulong datasize) {
#define fmt_header __fmt_header
	memset(&__,0,__hsize);
	size_t __fname=strlen(filename);if(__fname>=256){printf("names<256b!\n");_exit(1);}
	pack(__,fmt_header,filename,filelines,datasize,".out\n\0");
	return __;
}
static ulong __file_d(char const *filepath){
	ulong res=0;
	int __=0;
	__=open(filepath,O_RDONLY);
	if(__!=-1){
		res=__;
		__rf=res;
	}
	return res;
}

// static updown __ud(uchar __){
// 	return __!=011?__==013:__u:__d;
// }

ulong __fw_att(char const *__f,ulong __w__,ulong offset) {
	long res=0;
	ulong __flen=strlen(__f),__res=__flen+offset;
	// maybe remove if intermideiate write is not sucessful
	res=pwrite(__w__,__dofl(offset),offset,0);
	// maybe remove if final write is not sucessful
	res=pwrite(__w__,__f,__flen,offset);
	return res!=__res?0:__res;
}

/**
secretive ::
 * `fsz8(dir)` && `fsz8(lbb_1)` 
 * 		returns the same size for the field. Both are 4096 bytes.
 * 
 * 	Nonetheless,
 *  when dir is created we fill file with `#`. 
 *  when lbb is created we fill file with `@`.
**/

char *__dofl(ulong __){
	char fl[__];
	memset(&fl,'\n',__);
	return strdup(fl);
}
	
char *__f_lbb_out(){
	int __=open("lbb.out",(O_RDWR|O_CREAT),S_IROTH);
	__fdlo=__==-1?0:(ulong)__;
	return "LO";
}

char *__f_out_lbb(){
	int __=open("out.lbb",(O_RDWR|O_CREAT),(S_IRWXU|S_IRGRP|S_IXGRP));
	__fdlo=__==-1?0:(ulong)__;
	return "OL";
}

#define __res__ 999
int main(int argc, char const*argv[]) {
	switch(argc){
	case 0:
		#define n0 (int)&'a'
	case 1:
		if(argv[1]!=NULL)
			#define n1(x) ((ulong)x)
			break;
	case 2:
		#define n2 (int)&'0'
	default: break;
	}

	#include "field.h"
	int __iter=0;
	#if _c
		#include <stdio.h>
		__env_hash(environ);
		for(int i=1;i<10;i++){
			printf("i=%d::%lu\n",i,sz8(i));
		}
		for(__iter=_c;__iter!=0;__iter--){
			#include "field.h"
		}
		return 0;
	#endif 
}


	#define __c_ternary__ "ccc"
#endif
