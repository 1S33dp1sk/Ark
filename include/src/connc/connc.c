#include "connc.h"


int main(/*int argc, char const *argv[]*/) {
	int F_HASH;
    char * _mystr = "Hello World";
    F_HASH = SuperFastHash( _mystr , strlen( _mystr ) );
    printf("HASH :: %s -> %x" , _mystr ,  F_HASH );
	return 0;
}