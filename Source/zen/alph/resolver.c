/// resolver \\\



#include "lbb.h"

ulong __ndefined(char c){
	int _c = (int)c;
	if(_c<(int)0100||_c>(int)0132){
		return 1;
	}
	return 0;
}


ulong resolver(uchar*kurl,size_t __size) {
	if(__size<=(size_t)6) {
		if(kurl[4]!='\0'||__ndefined(kurl[0])){
			#ifdef DEBUG
				printf("cannot resolve bytes<6 that are not shared across athernet\n");
			#endif
			_exit(0x0);
		}
		uchar ___name[4]; memcpy(__name,kurl,4); 
		return lbb_resolve(__name);// execvp()
	}
}



#define __level_c __sa__m

char const **read_descriptions(unsigned fd) {
	//if(fd<2){return {"reserved for standard in/out"};};
	char const **__descriptions;

	void *ptr=malloc(__level_c);
	ssize_t __rsize=read(fd,ptr,__level_c);
	// read lowest level and go up
	__descriptions[0]=(char const *)ptr;


	return __descriptions;
}
