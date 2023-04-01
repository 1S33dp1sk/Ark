#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>
#include "utypes.h"
#include "hbar.h"


ulong __hid(char const *x,ulong sz,ulong lvl){
	return hash8(lvl,x,sz);
}

int uprint(ulong u){
	if(!u){
		printf("usage :: hash8 [name] [(size) (level)]\n MUST BE >4 characters.\
			Output 8 bytes hbar on stdout.\n");
		return 1;
	}
	printf("%lu\n",u);
	return 0;
}

int main(int argc, char const*argv[]) {
	ulong __;
	switch(argc){
	default:__=0;break;
	case 2:__=__hid(argv[1],((ulong)strlen(argv[1])),3);break;
	case 3:__=__hid(argv[1],((ulong)atoi(argv[2])),3);break;
	case 4:__=__hid(argv[1],((ulong)atoi(argv[2])),((ulong)atoi(argv[3])));break;
	}
	uprint(__);
	return 0;
}