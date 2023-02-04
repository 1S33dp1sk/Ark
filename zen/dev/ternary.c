#include <unistd.h>
#include <stddef.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include "string.h"
#include <stdlib.h>
#include "idxer.h"

static size_t *__field__(char const *filename,ulong filelines,ulong datasize);
static uchar *__header(uchar *__,char const *filename,ulong filelines,ulong datasize);

static const ulong __hlen=256;
static size_t *__field__(char const *filename,ulong filelines,ulong datasize) {
	// free the tracker
	size_t *tracker=malloc((3*sizeof(size_t)));
	static uchar header[256];
	uchar *_header=__header(header,filename,filelines,datasize);

	return tracker;
}
static const size_t __hsize=__hlen*sizeof(uchar);
static const char *__fmt_header="__s_L_L__s\0";
static uchar *__header(uchar *__,char const *filename,ulong filelines,ulong datasize) {
#define fmt_header __fmt_header
	memset(&__,0,__hsize);
	size_t __fname=strlen(filename);if(__fname>=256){printf("names<256b!\n");_exit(1);}
	pack(__,fmt_header,filename,filelines,datasize,".out\n\0");
	return __;
}
static uns __rf=0;
static uns __file_d(char const *filepath){
	uns res=0;
	int __=0;
	__=open(filepath,O_RDONLY);
	if(__!=-1){
		res=(uns)__;
		__rf=res;
	}
	return res;
}






static uns __fdlo=0;
char *__f_lbb_out(){
	int __=open("lbb.out",(O_RDWR|O_CREAT),S_IROTH);
	__fdlo=__==-1?0:__;
	return "LO";
}

char *__f_out_lbb(){
	int __=open("out.lbb",(O_RDWR|O_CREAT),(S_IRWXU|S_IRGRP|S_IXGRP));
	__fdlo=__==-1?0:__;
	return "OL";
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


int main(int argc, char const*argv[]) {

	// size_t res = fsz8(dir);
	// printf("result :: %lu\n",res);

	for(int i=1;i<10;i++){
		printf("i=%d::%lu\n",i,sz8(i));
	}

}

