/// d-cld \\\

#ifndef __Karch_512__
#include "2c/_h512.h"
#include "2c/lbb.h"
#include "2c/ixr.h"
#define OUTPUT 1
#define LOG_ERR 1
#endif

#ifdef RUNNING_BITS
#undef __RUN_C
#else
#define __RUN_C 256
#endif

int main(int argc, char **argv) {
    __LBB_START__
    m_stat mst;memset(&mst, 0, sizeof(m_stat));
    get_mstat("api.d", &mst);
    log_mstat(&mst);

    char __dbuf[mst.m_size];memset(&__dbuf, 0, sizeof(__dbuf));
    __readin(__dbuf, mst.m_size, __dgetfd("api.d"));
    __read_ft(__dbuf, mst.m_size);

    return 0;
};











// __LBB_START__ 
// __arcstp(__RUN_C);
// char const *__rcf=__FILE__;
// ulong __rcflen=str_rwings(__rcf);
// printf("rc constant =: %s\n", __rcf);
// char const *__rc_constant=hashof(1, __rcf, __rcflen);
// if(argv[1]!=NULL){
//     char const *__rc_arg=hashof(1, argv[1], str_rwings(argv[1]));
//     void *lptr=__generate_lock(argv[1], str_rwings(argv[1]));
//     if(lptr!=NULL){
//         printf("@%p ::: { rc constant :: %s } \n", lptr, __rc_constant);
//         printf("-> %s \n", __rc_arg);
//     }
// };
// INDEX_END("\n");








