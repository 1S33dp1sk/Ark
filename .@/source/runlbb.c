#include "2c/_h512.h"
#include "2c/lbb.h"
#include "2c/ixr.h"


#define __D_CLOUD__ 1

#ifdef __D_CLOUD__
	#define __TEST_8 1
	#include "d-512.h/cloud"
	#undef __TEST_8
	#define __TEST_16 1
#endif
#if __TEST_16
	#include "d-512.h/cloud"
	#undef __TEST_16
	#define __TEST_256 2
#endif
#if __TEST_256
	#include "d-512.h/cloud"
	#undef __TEST_256
	#define __TEST_512 3
#else
	#define __TEST_512 1
#endif





