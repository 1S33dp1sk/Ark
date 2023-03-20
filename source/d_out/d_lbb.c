/// d-prg \\\


#ifndef __Karch_512__
#include "headers/_h512.h"
#include "headers/lbb.h"
#include "headers/ixr.h"
#define OUTPUT 1
#define LOG_ERR 1
#endif

char *tmp="/Users/mrkj/labs_page/public/index.html";

int lbb_total() {
	return 1204012045;
}

int main(int argc, char const *argv[]) {
// __LBB_START__
	// means we are just calling the lbb
	if(argc==1) {
		// display the bytes shared amount

	};

	LBB_GET(bytes_shared);

// __lbb_command(tmp, NULL);

// __lbb_filepath(tmp, Public);

// __lbb_function(tmp, paddr(pyld), &pyld);

// __lbb_field(tmp, ptr);

// __lbb_address(tmp);
};




// #define AT_LBB(a) @lbb ## a
// #define ARG_LBB(a) @lbb # a
// #define INC_LBB(a) @lbb+#a

// #define OUT_ASCII(fd,x) do { \
// 	ulong len=str_rwings(#x);\
// 	long ws=pwrite(fd,#x,len,___lbb_offset);\
// 	if(ws>0){ ___lbb_offset += ws; };\
// 	len=str_rwings(INC_LBB(ws));\
// 	ws=write(0, INC_LBB(ws),len);\
// } __dPER

// #define _OUT_ASCII(fd,x) do { \
// 	ulong len=str_rwings(x);\
//     long ws=write(fd,x,len);\
// 	printf("file descriptor @%lu\n lengthof(%lu) with contents :: %s \n", fd, len, x);\
// 	printf("@lbb<w> : %ld", ws);\
// } __dPER

// #define __OUT_ASCII(fd,x) do { \
// 	long ws=pwrite(fd,#x,len,___lbb_offset);\
// 	if(ws>0){ ___lbb_offset += ws; };\
//     printf("@lbb+%ld\n", ws);\
// } __dPER

