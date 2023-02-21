/// amv \\\
The Arch Machine {version}

#ifndef __Karch_512__
#include "2c/_h512.h"
#endif

// #ifndef __AMV__||__VMA__
#ifndef AMV
	#define AMV "ArchMachine v."
	struct __key {
		ulong v;
		ulong m;
		ulong a;
	};
#define __key_t(x,p) (ulong)(((ulong *)x)[p])

	#define __V(x) __key_t(x,0)
	#define __M(x) __key_t(x,1)
	#define __A(x) __key_t(x,2)




	#define _M_ __fifo(__epoch,alph_index)
	#define __fifo(x,y) __ap_att(1,x,y)
#endif

#define lock (__stres(lfiles[1]))


int lock_available(){
	#if defined(unlocked)
		return 1;
	#endif
	return -1;
};






int main(int argc, char **argv){
#define __ARGC__ argc
#define __ARGV__ *argv

__LBB_INIT
INDEX_AT("The book");

	printf("indexer :: %lu\n",IDXR);
	













INDEX_END("\n");


};




// 
// #ifndef __Karch_512__
// #include "2c/_h512.h"
// #endif
// #include "2c/net.h"
// ulong __get_action(char const *__arg){
// 	return elem_hash(__arg);
// }
// int main(int argc,char const *argv[]) {
// 	les();
// 	return 0;
// }
// 