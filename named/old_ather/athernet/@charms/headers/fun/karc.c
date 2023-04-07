#ifndef __Karch_512__
#include "../_h512.h"
#endif


ulong __get_action(char const *__arg){
	return elem_hash(__arg);
}

int main(int argc,char const *argv[]) {
// __init_3ci();
	printf("\nWelcome to Arc, let's create an instance first\n");
	printf("checking env :: %d\n", arch_env());
	// log_arcs();
	printf("arc : creating Lockfile :: %lu\n",arch_cfile(f_dir));
	// int lbb_instance=lbb(argv[1]);
	// printf("instantiating lbb result :: %d\n",lbb_instance);
	return 0;
}
