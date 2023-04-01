/**
 * Ternnet 
 * Download client
 * Install => `Make` for devs
 * Check sys
 * 		files
 * Compile @source
 * 		networks
 * Connect Host
 */


/**
 * 
 * errors::
 *			1: index file permissions are not suitable
 *			2: index file cannot be opened
 *			3: index file format is not supported {a.k.a} stat cannot be called 
**/


#ifndef __ATT__
	#define __ATT__ 2
	#include "utypes.h"
	#include <stdio.h>
	#include <unistd.h>
	#include <fcntl.h>
	#include <sys/types.h>
	#include <sys/stat.h>
	static ulong idxer_fd;
	static struct stat idxer_st;
    ulong __fsize(char *fpath){
        // memset(&__,0,sizeof(struct stat));
        if(stat(fpath,&idxer_st)!=0){return 3;}
	#define __index_stat (&idxer_st) 
        return __index_stat->st_size;
    }

	ulong __get_idx(){
		int __fd;
	#define __index_file "charm"
		if(access(__index_file,F_OK|R_OK|W_OK)!=0){
			return 1;
		}
		__fd=open(__index_file,O_RDWR);
		if(__fd==-1){return 2;}
	#define __index_fd idxer_fd
		idxer_fd=__fd;
		return __fsize(__index_file); 
	}



	int main(int argc,char const*argv[]) {
		ulong idx_fd=__get_idx();
		printf("called\n");
		if(argc==1){
			printf("__shared__\n");
		}
		close(idx_fd);
		return 0;
	}

#endif
