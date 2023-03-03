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


struct __dpoint_indexes {
    ulong count;
    ulong filesize;
    dpoint **idxrs;
};

typedef struct __dpoint_indicies dices;


unsigned get_hlevel(char *href) {
    ulong c=str_rwings(href);
    unsigned res=((c)>>3);
    if (res>3){
        return 3;
    };
    return res;
};


dpoint *__stpoint(char const *st_name) {
    if(st_name==NULL){
        return NULL;
    };
    ulong __len=str_rwings(st_name);
    dpoint *d_stpoint=(dpoint *)malloc(sizeof(dpoint));
    void *tptr=(void *)&st_name;
    if(st_name[0]=='k'){
        memmove(((void *)d_stpoint->__ref), tptr, __len);
    }
    else {
        memmove(((void*)d_stpoint->__name), tptr, __len);
    };
    return d_stpoint;
};

#define __FLAG_START 0x1
#define __INTERPRETER_FS 0x2
#define __FLAG_IE_PS 0x3
#define __FLAG_ES 0x4
#define __FLAG__ 0x10
#define FLAG 0x100
#define __flag_interpret 16
#define __flag_payload 273

// read from till
int __read_ft(char *dbuffer, ulong dbuf_len) {
    int __direction=0;
    ulong __flags=0, c__=0, __c=dbuf_len;
    char const *arg=(char const *)dbuffer;
    ulong __alen=str_rwings(arg);
    pia_st pst; __pia__(pst);
    char *__ptrname, *__interpreter, *__args;
    do {
        c__+=1;__c--;
        if(!__flags) {
            #ifdef DEBUG
                printf("-----\n");
            #endif
            if(dbuffer[c__]=='@') {
                __direction+=1;
                __flags|=__FLAG__;
                #ifdef DEBUG
                    printf(">%c__", dbuffer[c__]);
                    printf("FLAG START #%lu#\n", __flags);
                #endif
            }
            else if(dbuffer[__c]=='}') {
                __direction-=1;
                __flags|=__FLAG_ES;
                #ifdef DEBUG
                    printf("__%c<", dbuffer[__c]);
                    printf("FLAG END #%lu#\n", __flags);
                #endif       
            }else {
            #ifdef DEBUG
                printf("direction unknown ::: \n");
            #endif
            };
           
        } else { 
        char *ptr_interchange; ulong temp;
           if((__flags==__flag_interpret)||(dbuffer[c__]=='@')) {
                __flags|=__FLAG_START;
                #ifdef DEBUG
                    printf("FLAG START #%lu#\n", __flags);
                #endif
                temp=sep_offset(arg, "<");
                // we increment the `arg` to get rid of the @ & then
                // seperate offset considers the `<` included in str_b4
                // so we decrement the count
                temp-=1;
                __ptrname=stn_b4offset(arg, temp);
                #ifdef DEBUG
                    printf("pointer name ::: %s\n", __ptrname);
                #endif
                memmove(__p_pointer(pst), __ptrname, __P_LEN);
                temp=_p_pointer_len(pst);
                if(temp>__P_LEN){
                    #ifdef LOG_ERR
                        printf("pointer names must be 8 bytes\n");
                    #endif
                    #ifdef DEBUG
                        printf("pointer contents iteration ::\n");
                        for(int i=0;i<temp; i++){
                            printf("%d(%c)\n", __ptrname[i],__ptrname[i]);
                        }
                    #endif
                    return 2;
                };
            }
            else if((__flags>__flag_interpret)&&(dbuffer[c__]=='<')) {
                __flags|=FLAG;
                #ifdef DEBUG
                    printf("INTERPRETER FLAG #%lu#\n", __flags);
                #endif
                // recenter the `arg` to be able to extract the correct offset
                ptr_interchange=str_a4offset(arg, temp);
                ptr_interchange+=(temp-1);
                temp=sep_offset(ptr_interchange, ">");
                #ifdef DEBUG
                        printf("offset is @ %lu\n", temp);
                #endif     
                __interpreter=stn_b4offset(ptr_interchange, temp);
                #ifdef DEBUG
                    printf("interpreter :: %s\n", __interpreter);
                #endif
                memmove(__p_interpreter(pst), __interpreter, __I_LEN);
                ulong temp=_p_interpreter_len(pst);
                if(temp>__I_LEN){
                    #ifdef LOG_ERR
                        printf("interpreters always have a maximum of 64 bytes for a reference call\n");
                    #endif
                    #ifdef DEBUG
                        printf("__interpreter :: %s : %lu\n", __interpreter,temp);
                    #endif
                    return 3;
                };
            }
            else if((__flags==__flag_payload)&&(dbuffer[c__]=='>')) {
                __flags|=__FLAG_IE_PS;
                #ifdef DEBUG
                    printf("FLAG PAYLOAD #%lu#\n", __flags);
                #endif
                // seperate the bracket insides by seperating the `{`
                // and making use of the fact that `}` should be at end of data inp (eodi)
                ptr_interchange=str_a4offset(ptr_interchange, temp);
                temp=sep_offset(ptr_interchange, "{");
                __args=str_a4offset(ptr_interchange, temp);
                temp=str_rwings((char const *)__args);
                if(__args[temp]!='}'){
                    #ifdef LOG_ERR
                        printf("err : malformat :: no closing arg sequence `}Z`\n");
                    #endif
                    return 1;
                };
            }
            else if((__flags>=__FLAG_IE_PS)&&(dbuffer[c__]=='{')) {
                #ifdef DEBUG
                    printf("FLAG PAYLOAD START #%lu#\n", __flags);
                #endif
                __flags|=__FLAG_ES;
                // get the actual args inside the brackets
                char *args=str_b4offset(__args, temp);
                memmove(__p_args(pst), args, __A_LEN);
                temp=_p_args_len(pst);
                if(temp>__A_LEN){
                    #ifdef LOG_ERR
                        printf("payloads are restricted to 512bytes max\n");
                    #endif
                    #ifdef DEBUG
                        printf("interchange :: %s\n", ptr_interchange);
                        printf("intra arguments :: %s\n", ptr_interchange);
                        printf("start args offset :: %lu\n", temp);
                        printf("main args :: %s\n", __args);
                    #endif
                    return 4;
                };
                #ifdef DEBUG
                    printf("pointer name := %s\n", p_pointer(pst));
                    printf("interpreter  := %s\n", p_interpreter(pst));
                    printf("arguments    := %s\n", p_args(pst));
                #endif
            };
        };

    }while(__c>0);

    return 0;
}
 


int main(int argc, char **argv) {
#define __ARGC__ argc
#define __ARGV__ *argv

    m_stat mst;memset(&mst, 0, sizeof(m_stat));
    get_mstat("api.d", &mst);
    log_mstat(&mst);

    char __dbuf[mst.m_size];memset(&__dbuf, 0, sizeof(__dbuf));
    __readin(__dbuf, mst.m_size, __dgetfd("api.d"));
    __read_ft(__dbuf, mst.m_size);










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








