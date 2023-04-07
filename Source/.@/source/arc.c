#ifndef __Karch_512__
#include "2c/_h512.h"
#endif


ulong __get_action(char const *__arg){
	return elem_hash(__arg);
}

int main(int argc,char const *argv[]) {
	if(argc!=2){
		printf("usage : arc [`@charms` directory path]\n");
		return 2;
	}
	printf("\nWelcome to Arc.\n");
	printf("ARC : Lockfile size=4096 bytes\n\tEnv :: ");
	int lbb_i=lbb(argv[1],arch_cfile(f_dir));
	printf("checking karch_512 build => %s\n", (arch_cenv()==0?"Systems check":"Cannot obtain enviroment"));
	printf("linking book :%d to arcs#%d\n",lbb_i,arch_3ci());
	lbb_close();
	return 0;
}
