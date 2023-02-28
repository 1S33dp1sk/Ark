/// d-lbb \\\


#ifndef __Karch_512__
#include "2c/_h512.h"
#include "2c/lbb.h"
#include "2c/ixr.h"
#define OUTPUT 1
#define LOG_ERR 1
#endif

#ifdef OUTPUT
int main(int argc,char const*argv[]) {
#define __ARGC__ argc
#define __ARGV__ *argv
__LBB_START__
        if(argc!=2){
        #ifdef LOG_ERR
            __usage();
        #endif
        return 1;
    };
    char *temp=flds(argv[1]);
    INDEXER(temp);
INDEX_END("\n");
};
#endif






















