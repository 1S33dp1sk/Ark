/// The d-cloud \\\
The D-cloud is a Layer-3 network

#include "2c/_h512.h"
#include "2c/ixr.h"


/**
 * morles :: 
 *  off :: les <-> server
 *  on  :: mor --> les
 */

struct __key {
	ulong a;
	ulong m;
	ulong v;
};

struct __spec {
	gfmt g_ev;
	char const *g_delim;
};

typedef struct __spec spec;


int spec_set_type(spec *sp, gfmt g) {
	sp->g_ev=g;
	sp->g_delim=DELIM(g);
	return 0;
};

static ulong p_pid;
static ulong c_pid;
#define CALL_SUCC(x) x==(ulong)0?1:0
#define CALL_INST(x) x==(ulong)1?1:0
#define CALL_NSUC(x) x==(ulong)-1?1:0
#define CALL_NEXT(x) x<(ulong)-1?x>(ulong)1?1:x:0


// __TEXT(Hello World); //valid in ATP
#ifdef __AT_PROTOCOL__
int main(int argc, char **argv) {
	spec var;
	spec_set_type(&var, KV);
	OUT_ASCII(0,var.g_delim);
	return 0;
}
#else
int main(int argc, char const*argv[]) {

    p_pid=(ulong)getpid();
    c_pid=(ulong)fork();
    if(CALL_NSUC(c_pid)){
        printf("fork-error :: cannot instantiate the d-cloud\n");
        return 1;
    }
    else if(CALL_SUCC(c_pid)){
        // forked process {a.k.a} child process
        p_pid=(ulong)getpid();
        #if LOG_LEVEL == 3
            printf("child process with pid=%lu\n\t&&c_pid :: %lu\n",p_pid,c_pid);
        #endif
        return 0;
    }
    // main process {a.k.a} parent process
    #if LOG_LEVEL == 3
        printf("parent process with pid=%lu\n\t&&c_pid :: %lu\n",p_pid,c_pid);
    #endif
    if(fsze((char *)lfiles[1])==0){
        #if LOG_LEVEL == 3
            printf("no lock found, instantiating\n");
        #endif
        prg dcloud;
        int res = init_generic(dcloud);
    }
    #if LOG_LEVEL == 3
        printf("p_pid :: %lu",p_pid);
        printf("\nc_pid :: %lu",c_pid);
        printf("\nsuccess=%d\tnsucess=%d\n",CALL_SUCC(c_pid),CALL_NSUC(c_pid));
        printf("call next ? %d\n",CALL_NEXT(c_pid));
    #endif
}
#endif

