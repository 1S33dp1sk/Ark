/// runid_flds \\\
i run field ids

#include "2c/_h512.h"
#include "2c/lbb.h"
#include "2c/ixr.h"

void __usage(){
    printf("%s\n", "dcloud [on/off]\n");
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

#define DEBUG 1
#define LBB_0 1
#define LBB_1 1

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

#define OUTPUT 1
#ifdef OUTPUT
int main(int argc, char **argv){

    if(argc!=2){
        __TEXT(Use fields as :: `Fields /path/to/file`);
        return 1;
    };
    char *__fld_name=(char *)argv[1];
    ulong __fld_n_size=strlen(__fld_name);

    m_stat cm_st;
    memset(&cm_st,0,sizeof(m_stat));
    int res=get_mstat(__fld_name,&cm_st);
    if(res==-1){
        __TEXT(Field not found);
        return 2;
    };
    #ifdef DEBUG
        log_mstat(&cm_st);
    #endif


    char *cflds_head=conv_fields(&cm_st);
    if(cflds_head==NULL){
        return 3;
    };
    #ifdef OUTPUT
        printf("'%s'\n",cflds_head);
    #endif

    return 0;
};
#elif LIBRARY
int flds(int argc, char **argv) {
    if(argc!=2){
        __TEXT(Use fields as :: `Fields /path/to/file`);
        return 1;
    };
    char *__fld_name=(char *)argv[1];
    ulong __fld_n_size=strlen(__fld_name);

    m_stat cm_st;
    memset(&cm_st,0,sizeof(m_stat));
    int res=get_mstat(__fld_name,&cm_st);
    if(res==-1){
        __TEXT(Field not found);
        return 2;
    };
    #ifdef DEBUG
        log_mstat(&cm_st);
    #endif


    char *cflds_head=conv_fields(&cm_st);
    if(cflds_head==NULL){
        return 3;
    };
    #ifdef OUTPUT
        printf("'%s'\n",cflds_head);
    #endif

    return 0;
}
#endif






















