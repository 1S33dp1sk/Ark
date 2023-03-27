/// d-prg \\\
d-program

#ifndef karch
#include "headers/karch.h"
#endif


int __resolve(int _fd, char const *__dpath) {

	printf("__dpath : %s\n", __dpath);
	return 0;
}

#define d(fd,...) __resolve(fd, #__VA_ARGS__)


dPRG(
	d(0, @scripts/basics.py)
)































