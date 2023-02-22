/// The d-cloud \\\
The D-cloud is a Layer-3 network

#include "2c/_h512.h"
#include "2c/ixr.h"


/**
 * morles :: 
 *  off :: les <-> server
 *  on  :: mor --> les
 */

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

#define LOG_LEVEL 2


// 1 or more if lock exists
ulong check_lock() {
    ulong res=__stres(__lbb_locking);
    if(!res){
        #if LOG_LEVEL >= 2
            printf("%lu : lbb :: no lock found\n",c_pid);
        #endif
        _exit(1);
    }
    return res;
};


// __TEXT(Hello World); //valid in ATP
#ifdef __AT_PROTOCOL__
int main(int argc, char **argv) {
	spec var;
	spec_set_type(&var, KV);
	OUT_ASCII(0,var.g_delim);
	return 0;
}
#else

struct __arc {
    ulong __pid;
    ulong __lock;
};


int main(int argc, char const*argv[]) {

    p_pid=(ulong)getpid();
    c_pid=(ulong)fork();

    if(CALL_NSUC(c_pid)){
        printf("fork-error :: cannot instantiate the d-cloud\n");
        return 1;
    };

    struct __arc arc;
    memset(&arc, 0, sizeof(struct __arc));
    arc.__pid=p_pid;
    arc.__lock=check_lock();

    if(CALL_SUCC(c_pid)){ 
    // forked process {a.k.a} child process
        arc.__pid=(ulong)getpid(); 
        __LBB__L;
    }
    else {
    // main process {a.k.a} parent process
         __LBB__R;
    };



 magic_shard();
};

#endif



