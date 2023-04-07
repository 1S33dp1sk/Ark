#include <stdio.h>
#include "connc.h"

int main(int argc, char const *argv[]) {
    Ather ather = {0};
    ather.__name__ = (char *)argv[0];
    CONNC( &ather );
    return 0;
}