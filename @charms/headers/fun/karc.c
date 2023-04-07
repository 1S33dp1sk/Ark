#ifndef __Karch_512__
#include "../_h512.h"
#endif

int main() {

	printf("\nWelcome to Arc, let's create an instance first\n");
	printf("checking env :: %d\n", arch_env());
	printf("instantiating lbb ::: %d\n",lbb());
	return 0;
}
