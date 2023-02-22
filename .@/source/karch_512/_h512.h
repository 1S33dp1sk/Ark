/// machine file \\\

#ifndef __Karch_512__
#ifndef __k_arch512__h
#include "standard.h"
#ifndef __UTYPES__H
    #include "utypes.h"
#endif
#ifndef __ATP__H
    #include "atp.h"
#endif
#ifndef __HBAR__H
    #include "hbar.h"
#endif
#ifndef __ENK__H
    #include "enk.h"
#endif
#ifndef __LBB__H
    #include "lbb.h"
#endif
#ifndef __IXR__H
    #include "ixr.h"
#endif
#define __k_arch512__h 1
#endif
#define __Karch_512__ 
#define __MA__F 0x100000000000000000000007
#define LONG_MAX_COMPUTED_N_DIGITS 21 //logb(x) = loga(x) / loga(b)
#define MachPtr 16
#define __GS__F __MA__F<<3
#define GSocketField 64
#define __LO__F __LO__F<<3
#define LockF 512
#define __UN__F __GS__F<<3
#define UFile 4096



#define arch_filename "@charms/Lockfile"


uns __get_fd(char *cpath,uns __flag);
uns __get_process_flags(char *cpath);
uns __check_lbb_file(char *cpath,lbb_t ftype);
char *ccopy_to_path(char const *cc, char const *path);
char *tochar(ulong inp_u);
char *arch_gfile(char *cpath);
ulong arch_cfile(lbb_t f_type);
lbb_sz arch_tfile(char *cpath);
ulong arch_fpermissions(char *cpath);
ulong arch_foffset(char *fpath,ulong f_field);
ulong attsize(ulong __sz);
ulong lbbatt(uns level, ulong szatt);
ulong fsz8(lbb_t __);

static ulong arch_fname(char *fpath,ulong fsize);
int arch_mods(char const*c3path);
int arch_cdesc(ulong lbbfd);
int arch_cenv();

int arch_cdesc(ulong lbbfd) {

    return 0;
}

uns __get_fd(char *cpath,uns __flag){
    ulong __fd,__fsz,__iosz;
    if(!__fd){
        if((__fd=open(cpath,__flag,S_IRWXU))==-1){return 0;}
        __fsz=fsze(cpath);
        __iosz=iosze(cpath);
    }
    return __fd;
}

uns __get_process_flags(char *cpath){
    return dmde(cpath);
}

uns __check_lbb_file(char *cpath,lbb_t ftype){
    if(fsze(cpath)<1){
        return 0;
    }
    return 1;
};




struct __arc_buffer {
    ulong level;
    uchar __[512];
};
typedef struct __arc_buffer ArcBuffer;

struct __ustr {
    ulong len;
    uchar *__;
};

typedef struct __ustr ustr;

void *arc_read(ArcBuffer *buffer, ulong ffd) {
    long res;
    switch(buffer->level){
    case 0:
        res=read(ffd,buffer->__,24);
        if(res!=-1){
            return buffer;
        }
    default:
        return NULL;
    }
}


struct __dynamic_arc {
    ulong level;
    uchar *__;
};
typedef struct __dynamic_arc cld_buffer;


#define arr_size(x) ((ulong)(sizeof(x)/sizeof(x[0])))
#define LBB_DIRECTORY lfiles[0]
#define LOCK_FIFO lfiles[1]
#define LES_FILE lfiles[2]


extern char **environ;

static const uchar charms[26][4]={
    "att\0","bal\0","ccc\0","def\0","env\0","fmt\0",
    "git\0","hlv\0","inc\0","jab\0","kei\0","lbb\0",
    "mke\0","nop\0","ops\0","pub\0","que\0","rdl\0","sok\0",
    "trv\0","usr\0","vik\0","wln\0","xvl\0","ybn\0","z0x\0"
};

static const char mod_att[]="address\0";
static const char mod_bal[]="balance\0";
static const char mod_ccc[]="charm\0";
static const char mod_def[]="defined\0";
static const char mod_env[]="enviroment\0";
static const char mod_fmt[]="format\0";
static const char mod_git[]="git\0";
static const char mod_hlv[]="hash\0";
static const char mod_inc[]="include\0";
static const char mod_jab[]="jaber\0";
static const char mod_kei[]="kei\0";
static const char mod_lbb[]="lock\0";
static const char mod_mke[]="make\0";
static const char mod_net[]="networks\0";
static const char mod_oss[]="osys\0";
static const char mod_pub[]="public\0";
static const char mod_que[]="queue\0";
static const char mod_rdl[]="riddle\0";
static const char mod_shd[]="shared\0";
static const char mod_trv[]="traverse\0";
static const char mod_usr[]="user\0";
static const char mod_vik[]="vik\0";
static const char mod_wln[]="webpage\0";
static const char mod_xvl[]="xolve\0";
static const char mod_ybn[]="ybin\0";
static const char mod_zen[]="zen0x\0";


static const char *mods[26] ={
    mod_att,mod_bal,mod_ccc,mod_def,mod_env,mod_fmt,
    mod_git,mod_hlv,mod_inc,mod_jab,mod_kei,
    mod_lbb,mod_mke,mod_net,mod_oss,mod_pub,
    mod_que,mod_rdl,mod_shd,mod_trv,mod_usr,
    mod_vik,mod_wln,mod_xvl,mod_ybn,mod_zen
};
static const uns mods_count=arr_size(mods);

struct __ccc_item {
    struct __ccc_item* nxt;
    ulong __3chash;
    const uchar *__charm;
    const char *__mod;
};
typedef struct __ccc_item arc;

static arc kArcs[26];
#define elem_hash(x) hash8(0,x,strlen(x))

int __init_3ci(){
    int i_index=0;
    for(; i_index<25;i_index+=1){
        kArcs[i_index].__charm=charms[i_index];
        kArcs[i_index].__mod=mods[i_index];
        kArcs[i_index].__3chash=elem_hash(mods[i_index]);
        kArcs[i_index].nxt=&kArcs[i_index+1];
        printf("INDEXING ARC :%d: %s\n", i_index,mods[i_index]);
    }
    printf("INDEXING ARC :%d: %s\n", i_index,mods[i_index]);
    kArcs[i_index].__charm=charms[i_index];
    kArcs[i_index].__mod=mods[i_index];
    kArcs[i_index].__3chash=elem_hash(mods[i_index]);
    kArcs[i_index].nxt=NULL;
    return i_index;
};

int arch_3ci(){
return __init_3ci();
}

void log_arcs(){
    arc *karc=kArcs;
    while(karc!=NULL){
        printf("name :: %s\n",karc->__mod);
        printf("charm :: %s\n",karc->__charm);
        printf("hash :: %lu\n",karc->__3chash);
        karc=karc->nxt;
    }
}


#define LBB_0 1
static const uns __lbb_idx__=11;
static uns env_hash_0,env_hash_1;



ulong __env_hash(char **__var){
    uns __count=0;
    while(!(NNE(__var[__count]))){
        #ifdef DEBUG
            printf("%s\n",__var[__count]);
        #endif
        __count+=1;
    }
    env_hash_0=hash4(0,&__count,sizeof(uns));
    return (ulong)__count;
}


char const *__h_passcode(char *udef_pass){

    return hashof(2,udef_pass,strlen(udef_pass));
}

char const*__kgev(uchar *__udef_pnop){
    char **env_var=environ;
    char *udef_pnop=(char*)__udef_pnop;
    ulong vcount=0,__c=0, envar_count=__env_hash(env_var), evar_count=envar_count+1;
    ulong __hashes[evar_count];
    void *__hptr=memset(&__hashes,0,(sizeof(ulong)*evar_count));
    do {
        vcount=strlen(env_var[__c]);
        __hashes[__c]=hash8(1,env_var[__c],vcount);
        vcount=0;__c+=1;
    } while(__c<envar_count);
    if(__hashes[envar_count-1]==0){
        return NULL;
    }
    __hashes[envar_count]=hash8(1,udef_pnop,strlen(udef_pnop));
    return hashof(3,__hashes,sizeof(__hashes));
}


void k1_addr(ulong _h8res,ulong _count,char *_kval) {
    ulong __len=11+16+strlen(_kval);
    char __kaddr[__len];
    memset(&__kaddr,0,__len);
    sprintf(__kaddr,"k-%08lx:%lu:=%s\n",_h8res,__cindex,_kval);
    __cindex+=1;
    ulong psize=lbb_print(__kaddr);
};

char const *__keys_hash(char **__var, uns __varc){
    uns _c=0;
    ulong hashes[__varc];
    void *__hptr=memset(&hashes,0,(sizeof(ulong)*__varc));
    while(_c<__varc){
        ulong vclen=strlen(__var[_c]);
        hashes[_c]=hash8(1,__var[_c],vclen);
        #ifdef LBB_0
            k1_addr(hashes[_c],_c,__var[_c]);
        #endif
        _c+=1;
    }
    char const *env_hash_2=hashof(2,__hptr,sizeof(hashes));
    return env_hash_2;
}

ulong __arch_fsize(char *cpath){
    return fsze(cpath);     
}


lbb_sz lbb_type2sz(lbb_t type){
    switch(type){
    case f_reader: return __freader_sz;
    case f_socket: return __fsocket_sz;
    case f_field: return __ffield_sz;
    case f_dir: return __fdir_sz;
    case lbb_1: return __lbb1_sz;
    case lbb_2: return __lbb2_sz;
    case lbb_3: return __lbb3_sz;
    case lbb_4: return __lbb4_sz;
    default: return 0;
    }
}

lbb_t __size_switch(char *cpath) {
    ulong __fsize=__arch_fsize(cpath);
    switch(__fsize){
        case 8:return f_reader;
        case 64: return f_socket;
        case 512: return f_field;
        case 4096: return f_dir;
        case 32768: return lbb_1;
        case 262144: return lbb_2;
        case 2097152: return lbb_3;
        case 16777216: return lbb_4;
        default: return 0;
    }
}

// free after
char *ccopy_to_path(char const *cc, char const *path){
    char __ccc[256];
    memset(&__ccc,0,sizeof(__ccc));
    uns __pathlen=strlen(path),__len=__pathlen+4; //including the '\0' byte
    strcpy(__ccc,path);
    strcpy((__ccc+__pathlen),cc);
    if(__ccc[__len]!='\0'){
        __ccc[__len]='\0';
    }
    return strdup(__ccc);
}
// free after 
char *tochar(ulong inp_u){
    char __[9];
    memset(&__,0,sizeof(__));
    sprintf(__,"%lu",inp_u);
    return strdup(__);
}

char *arch_gfile(char *cpath){
    return tochar(fsze(cpath));
}

ulong attsize(ulong __size){
    int fd=open(arch_filename,(O_RDWR|O_CREAT), S_IRWXU);
    if(fd==-1){
        printf("cannot create .lbb\n");
        return 0;
    }
    uchar buf[__size];
    memset(&buf,'#',(__size*sizeof(char)));
    uchar *buffer=buf;
    ulong __set=0;
    long int temp=0;
    while(__set<__size){
        temp=pwrite(fd,buf,__size,__set);
        if(temp==-1){
            printf("error pwriting\n");return 0;
        }
        __set+=temp;temp=0;
    }
    return fd;
}

ulong lbbatt(uns level,ulong sizeatt){
    int fd=open(arch_filename,(O_RDWR|O_CREAT), S_IRWXU);
    if(fd==-1){
        printf("cannot create .lbb\n");
        return 0;
    }
    ulong lbb_iosize=iosze(arch_filename);
    uns cptr=0,blk=0,chk_blocks=sizeatt&lbb_iosize,nblocks=sizeatt/lbb_iosize;
    if(chk_blocks||!nblocks){
        printf("wrong size.\noctal system handler \n");
        return 0;
    }
    ulong total=0;long int temp=0;
    uchar buf[512];
    memset(&buf,'@',(512*sizeof(uchar)));
    for(;blk<nblocks;){
        temp=pwrite(fd,buf,512,total);
        if(temp==-1){printf("error writing\n"); return 0;}
        total+=temp;temp=0;blk++;
    }
    return fd;
}

lbb_sz arch_tfile(char *cpath){
    ulong __fsize=__arch_fsize(cpath), res=0;
    while((__fsize>>3)>8){
        res+=1;
    }
    switch(res){
        case 1:return __freader_sz;
        case 2: return __fsocket_sz;
        case 3: return __ffield_sz;
        case 4: return __fdir_sz;
        case 5: return __lbb1_sz;
        case 6: return __lbb2_sz;
        case 7: return __lbb3_sz;
        case 8: return __lbb4_sz;
        default: return 0; 
    }
}

ulong arch_cfile(lbb_t _){
    switch(_){
        case f_reader:return attsize(__8sz(1));
        case f_socket:return attsize(__8sz(2));
        case f_field:return attsize(__8sz(3));
        case f_dir:return attsize(__8sz(4));
        case lbb_1:return lbbatt(1,__8sz(5));
        case lbb_2:return lbbatt(2,__8sz(6));
        case lbb_3:return lbbatt(3,__8sz(7));
        case lbb_4:return lbbatt(4,__8sz(8));
        default:return 0;
    }
}

ulong arch_fpermissions(char *cpath){
    ulong __=__file_x(cpath);
    return __<2?__+__file_w(cpath)+__file_r(cpath):__;
}

ulong arch_foffset(char *fpath,ulong f_field){
    return f_field!=0?(ulong)fhash8(2,fpath):(ulong)f_field;
}

static ulong arch_fname(char *name,ulong csize){
    ulong __res=0;
    ulong _ures=0,__size=9; //(sizeof(ulong))+(5*sizeof(char))\\;
    uchar *__=malloc(__size);
    if(!(NNE(__))){return 0;}
    memset(__,0,sizeof(__size));
    size_t step=__size/3;
    memmove(__,name,step);
    char *__idx=(char*)__+step;
    // printf("__ : %p\n__idx : %p\n",__,__idx);
    // printf("%s\n",__idx-3);
    memmove(__idx,":",1);
    uchar *__xer=(uchar *)&__idx+1;
    ulong __packed=0;
    if((__packed=pack(__xer,"L",csize))!=4){
        printf("error packing L in xer\n"); 
        return 0;
    }
    unpack(__xer,"L",&_ures);
    if(__[__size]=='\0'){
        printf("%s",__);
        printf("%08lx%08lx",u[0],u[1]);
        printf("k+%lu\n",_ures);
        // *u=hash16(3,__,8);
    }
    return __res;
}

int arch_mods(char const*_3curl){
    ulong fieldname=0, ccc__offset=0;
    char *__mod,*__crm,*__3c;
    ulong __len=0, __offset=0;
    int c=0; // count
    for(;c<mods_count;c++){
        __mod=(char*)mods[c];
        __crm=(char*)charms[c];
        __3c=ccopy_to_path(__crm,_3curl);
        __len=arch_tfile(__3c);
        __offset+=arch_fpermissions(__3c);
        ccc__offset+=arch_foffset(__3c,__offset);
        fieldname=arch_fname(__crm,ccc__offset);
    }
    return 0;
}

int arch_cenv(){
    char **__var=environ;
    uns envar_count=__env_hash(__var);
    char const *hvar=__keys_hash(__var,envar_count);
    printf("k+%x:%u:=ENVHASH=1\n",env_hash_0,envar_count); // ENVHASH :: ZENV
    return 0;
}


#endif



