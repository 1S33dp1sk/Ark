/// runid_flds \\\
i run field ids


#include "2c/_h512.h"
#include "2c/net.h"
#define MORLES 1
/**
 * morles :: 
 *  off :: les <-> server
 *  on  :: mor --> les
 */

void __usage(){
    printf("%s\n", "dcloud [on/off]\n");
}

static ulong p_pid;
static ulong c_pid;

#define CALL_SUCC(x) x==(ulong)0?1:0
#define CALL_INST(x) x==(ulong)1?1:0
#define CALL_NSUC(x) x==(ulong)-1?1:0
#define CALL_NEXT(x) x<(ulong)-1?x>(ulong)1?1:x:0


#define DEBUG 1


struct __pr_generic {
    char const *path;
    struct stat st;
    ulong inn;
};
typedef struct __pr_generic prg;

int init_generic(struct __pr_generic prg_dcloud){
    memset(&prg_dcloud,0,sizeof(prg_dcloud));
    prg_dcloud.path=((char const*)(lfiles[1]));
    if(!ap_make(prg_dcloud.path)){
        printf("error :: cannot make fifo\n");
        return 1;
    }
    void *res=status(prg_dcloud.path);
    if(res==NULL){
        printf("error :: cannot obtain status ::: status()returned null\n");
        return 1;
    }
    printf("path :: %s\n",prg_dcloud.path);
    printf("inum :: %lu\n",inodenum);
    printf("____\n");
    return 0;
}



static const char *__lbb__d="@charms/lbb/";
static const char *__lock__f="@charms/Lockfile";
static const ulong __enu_size=512;


// #define DEBUG 1
#define LBB_0 1
#define LBB_1 1

ulong __enu_count(ulong __size){
    ulong __c=0;
    while(__size>__enu_size){
        __c+=1;__size-=__enu_size;
    };
    return __c+=1;
}



char const *__hfilename(char *cpath){

    return hashof(1,cpath,strlen(cpath));
}


char *__fld_hash(char *cpath,ulong fsize, ulong max_enumer){
    int x=-12;
    long xx=129541;
    __ASCII(xx);



    // ulong size_path=strlen(cpath)*sizeof(char);
    // ulong size_long=sizeof(ulong);
    // ulong fld_size=(size_path)+(size_long*2);
    // void *__fld=malloc(fld_size),*rfld=__fld;
    // #ifdef DEBUG
    //     printf("fld @%x\n",__fld);
    // #endif
    // void *__fld_cpath=((void *)(cpath));
    // memmove(__fld,__fld_cpath,size_path);
    // #ifdef DEBUG
    //     printf("moved cpath ->fld @%x\n",(__fld+size_path));
    // #endif
    // void *__fld_fsize=((void *)(__fld+size_path));
    // memmove(__fld_fsize,fsize,size_long);
    // // #ifdef DEBUG
    // //     printf("moved size ->fld @%x\n",(__fld+size_path+size_long));
    // // #endif
    // // void *__fld_maxenu=((void *)(max_enumer));
    // // memmove((__fld+size_path+size_long),__fld_maxenu,size_long);
    // // #ifdef DEBUG
    // //     printf("moved max_enumer ->fld @%x\n",(__fld+size_path+(2*size_long)));
    // // #endif
}

char *__fld_packed_hash(char *cpath,ulong fsize, ulong max_enumer){
    ulong size_path=strlen(cpath)*sizeof(char);
    ulong size_long=sizeof(ulong);
    ulong _size__=(size_path)+(size_long*2);
    uchar __fld[_size__];
    memset(&__fld,0,_size__);
    pack(__fld,"sQQ",cpath,fsize,max_enumer);
}

int main(int argc, char const*argv[]) {
    if(argc!=2){
        printf("usage :: d-cloud [path-like-to]\n");
        return 0;
    }

    char *__dlink=(char *)argv[1];
    char *fp_hash=(char *)__hfilename(__dlink);
    ulong dl_size=fsze(__dlink);
    ulong enu_count=__enu_count(dl_size);
    char *fn_sz_mn=__fld_hash(__dlink,dl_size,enu_count);
    #ifdef DEBUG
        printf("size of file to be linked :: %lu\n", dl_size);
        printf("enumeration count :: %lu\n", enu_count);
        printf("hash of path :: %s\n", fp_hash);
    #endif
    #ifdef LBB_1
        // while(enu_count>=0){
        //     printf("%s=%lu+%s\n",__dlink,enu_count,fp_hash);
        //     enu_count--;
        // }
    #endif
        
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


/****
 * usage ::
 * 
 * d-cloud [user-defined-name] [[file_1 file_2] OR [path/to/files/\*]]
 * if no user-defined-name is specified then an hbar computed address
 * will be automatically assigned to the files and returned in stdout.
 */





/**
 * simply any L0,L1,L2 can connect to it && L3 can access it ::
 * 
 * L(3) => any device that can store `Lockfile` and then serve an `lbb` instance.
 * L(2) => any controlling terminal that can execute the `arc` specified for an OS-independent common-socket parameters.
 * L(1) => any operating system that can run the `Makefile` to create & compile the `@charms` directory.
 * L(0) => any processor that can read and process the `_h512.h` to check the necessary modules to run L(3).
 * L(n) are defined as a pseudo reference to the type of information handling and processing that can be applied to the reference.
 * 
**/












