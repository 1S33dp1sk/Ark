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


#ifndef __ATT__
	#define __ATT__ 2
	#include <stdio.h>
	int main(int argc,char const*argv[]) {
		printf("Terrnet compiler\n");
		printf("num of args :: %d\n", argc);
		for(int i=0; i<argc;i++)
			printf("args :%d: %s\n",i, argv[i]);
	}
#endif
