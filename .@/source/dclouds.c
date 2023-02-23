/// The d-cloud \\\
The D-cloud is a Layer-3 network

#include "2c/_h512.h"
#include "2c/lbb.h"
#include "2c/ixr.h"

#define __D_CLOUD__ 1


struct __st_points {
    ulong __index;
    char *__ref;
    char *__name;
};
typedef struct __st_points dpoint;


struct __arc_t {
    ulong __pid;
    int __fork;
    ulong __next;
    dpoint **__points;
};
typedef struct __arc_t arc_t;

static arc_t __arc;

void __arcpid(){
    __arc.__pid=(ulong)getpid();
};

void __arcfork(){
    __arc.__fork=fork();
};

static struct __sok_t __sok;

void __arcsok(){
    __sok=__arcsocket();
};

static ulong step_c=0;

enum step_size {
    step_point=8,
    step_addr=16,
    step_sok=128
};


void *__arcstp(enum step_size stsize){
    void *stp;
    if(stsize<=step_point) {
        __arcpid();
        step_c+=1;
        stp=malloc(__MA__F);
    }
    else if (stsize<=step_addr) {
        __arcfork();
        return __arcstp(6);
    }
    else if(stsize==step_sok) {
        __arcsok();
        return __arcstp(6);
    }
    return stp;
};

const arc_t* arc=&__arc;

ulong lenify(char const*__){
    ulong _c=0;
    while(*__++!=0){
        _c+=1;
    }
    return _c;
};

static ulong points_c=0;

void free_arcs() {
    void *d2ptr, *dptr=arc->__points;
    for(ulong i=0;i<points_c;i++){
        d2ptr=(dpoint *)dptr;
        free((d2ptr+i));
    };
};

void free_args() {
    _socket_free_fd(&__sok);
    free_arcs();
};

void *__arc_stpoints(ulong __stindex, char const *__stname) {
    dpoint *__point=__arcstp(__MA__F);
    memset(__point,0,sizeof(ulong));
    __point->__index=__stindex;
    
    ulong length=lenify(__stname);
    char *stname=(char *)malloc(length);
    memset(stname,0,length);
    memmove(stname,__stname,length);
    __point->__name=stname;


    char const *__stref=hashof(1, __stname, length);
    ulong ref_length=lenify(__stref);
    char *stref=(char *)malloc(ref_length);
    memset(stref,0,ref_length);
    memmove(stref,__stref,ref_length);
    __point->__ref=stref;


    points_c+=1;
    return (dpoint *)__point;
}

#define __TEST_128 1 


#ifdef __D_CLOUD__
#define STORAGE_SIZE(x) (ulong)((1<<(2*x)))
int main(int argc, char const*argv[]) {

    #ifdef __TEST_8
        void *temp=__arcstp(8);
        printf("temp <%p>",temp);
    #elif __TEST_16
        void *temp=__arcstp(16);
        printf("temp <%p>",temp);
    #elif __TEST_128
        void *temp=__arcstp(128);
        log_socket(&__sok);
    #endif


   free_args();
};
#endif



// #mr. karam jaber.