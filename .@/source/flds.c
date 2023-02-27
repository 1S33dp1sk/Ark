/// runid_flds \\\
i run field ids

#include "2c/_h512.h"
#include "2c/lbb.h"
#include "2c/ixr.h"

#define OUTPUT 1
#define DEBUG 1


void __usage(){
    __TEXT(Use fields as :: `Fields /path/to/file`);
};

char *__pre_apple="/Users/mrkj/package/";
char *__pre_unix="/home/mrkj/package";
char *__pre_wind="C:\\package\\mrkj";
char *__pre_="///mrkj\\\\";

char const *mount_at="@charms/lbb/index.ext";
char const *_socket_="22ef791c@0.0.0.0";
char const *_forward_addr="@mrkj";
char const *_backward_addr="25258931ae931139141";
char const *k_addr="mrkj@25258931ae9311739141";

static const ulong __enu_size=512;


int get_allstats(){
    m_stat mstat;
    int res=get_mstat(mount_at,&mstat);
    printf("get mstat res=%d\n",res);
    log_mstat(&mstat);

    s_stat sstat;
    res=get_sstat(_socket_,&sstat);
    printf("get sstat res=%d\n",res);
    log_sstat(&sstat);

    k_stat kstat;
    res=get_kstat(k_addr,&kstat);
    printf("get kstat res=%d\n",res);
    log_kstat(&kstat);

    return res;
};

ulong __enu_count(ulong __size){
    ulong __c=0;
    while(__size>__enu_size){
        __c+=1;__size-=__enu_size;
    };
    return __c+=1;
};

char const *__hfilename(char *cpath){

    return hashof(1,cpath,strlen(cpath));
};

char *__fld_packed_hash(char *cpath,ulong fsize, ulong max_enumer){
    ulong size_path=strlen(cpath)*sizeof(char);
    ulong size_long=sizeof(ulong);
    ulong _size__=(size_path)+(size_long*2);
    uchar __fld[_size__];
    memset(&__fld,0,_size__);
    pack(__fld,"sQQ",cpath,fsize,max_enumer);
    return cpath;
};


char *flds(char const *__fldname) {
    if(__fldname==NULL){
        #ifdef LOG_ERR
            __TEXT(API : flds :: fld is null);
        #endif
        return NULL;
    };
    ulong __fld_n_size=strlen(__fldname);

    m_stat cm_st;
    m_stat *__cm_st=__mstat__(cm_st);
    int res=get_mstat(__fldname,__cm_st);
    if(res==-1){
        #ifdef LOG_ERR
            __TEXT(Field not found);
        #endif
        return NULL;
    };
    #ifdef DEBUG
        log_mstat(&cm_st);
    #endif


    char *cflds_head=conv_fields(__cm_st);
    if(cflds_head==NULL){
        #ifdef LOG_ERR
            printf("cflds header is null\n");
        #endif
        return NULL;
    };
    // needs to index here
    #ifdef DEBUG
        printf("'%s'\n",cflds_head);
    #endif

    return strdup(cflds_head);
};

#ifdef OUTPUT
int main(int argc, char **argv){

    if(argc!=2){
        #ifdef LOG_ERR
            __usage();
        #endif
        return 1;
    };
    char *__fld_name=(char *)argv[1];
    ulong __fld_n_size=strlen(__fld_name);

    m_stat cm_st;
    memset(&cm_st,0,sizeof(m_stat));

    int res=get_mstat(__fld_name,&cm_st);
    if(res==-1){
        #ifdef LOG_ERR
            __TEXT(Field not found);
        #endif
        return 2;
    };
    
    #ifdef DEBUG
        log_mstat(&cm_st);
    #endif

    char *cflds_head=conv_fields(&cm_st);
    if(cflds_head==NULL){
        #ifdef LOG_ERR
            printf("cflds header is null\n");
        #endif
        return 3;
    };

    #ifdef OUTPUT
        printf("'%s'\n",cflds_head);
    #endif

    return 0;
};

#endif






















