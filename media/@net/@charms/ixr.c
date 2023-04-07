/// idxer \\\
ternary indexer (:

#ifndef __IDXER__H
    #define __IDXER__H 1
#include <unistd.h>
#ifndef __UTYPES__H
    #include "utypes.h"
#endif
#ifndef __HBAR__H
    #include "hbar.h"
#endif
#ifndef __ENK__H
    #include "enk.h"
#endif
#include <sys/stat.h>
    #define __idxer_name "indexer"
    #define __MA__F 0x00000000000000000008
    #define MachPtr 16
    #define __LO__F __MA__F<<3
    #define LockFile 64
    #define __GS__F __LO__F<<3
    #define GlobalSocketFile 512
    #define __UN__F __GS__F<<3
    #define UniversalFile 4096

#ifndef __Karch_512__
#define __Karch_512__

/**
NNE(X)
     * @returns :   true if x is not 0x0000
*/
    #define NNE(v) v==0x0000?0x01:0x00

    enum __ftypes {
/**
{a.k.a} FIFO **/
        __reader=1,
/**
{a.k.a} PIPE **/
        __socket=2,
/**
{a.k.a} FILE **/
        __field=3,
/**
{a.k.a} DIRECTORY **/
        __dir=4, 
/**
{a.k.a} BOOK **/
        lbb_1, //binary
        lbb_2, //
        lbb_3,
        lbb_4
    };
    #define ftype enum __ftypes

    enum __ftypes__size {
        __dir__size=4096,
        lbb_1__size=32768,
        lbb_2__size=262144,
        lbb_3__size=2097152,
        lbb_4__size=16777216,
        __reader__size=8,
        __socket__size=64,
        __field__size=512
    };
    #define ftype_s enum __ftypes__size


    uns __8sz(uns __);
    #define sz8(x) ((ulong)__8sz(x))

    ulong __fsize(char *fpath);
    #define fsze(x) ((ulong)__fsize(x))

    ulong __iosize(char *fpath);
    #define iosze(x) ((ulong)__iosize(x))

    uns __dmode(char *fpath);
    #define dmde(x) ((uns)__dmode(x))

    char *ccopy_to_path(char const *cc, char const *path);
    char *tochar(ulong inp_u);
    char *arch_gfile(char *cpath);
    ulong arch_cfile(ftype f_type);
    ftype_s arch_tfile(char *cpath);
    ulong arch_fpermissions(char *cpath);
    ulong arch_foffset(char *fpath,ulong f_field);
    ulong attsize(ulong __sz);
    ulong lbbatt(uns level, ulong szatt);
    ulong fsz8(ftype __);
    static ulong arch_fname(char *fpath,ulong fsize);
    int arch_mods(char const*c3path);
    int arch_env();

    static const uns ter_base[3]={0xFFFF7777,0x77771111,0x11110000};
    #define ter_t typeof(ter_base)
    // binary-ternary hybrid system 
    static ter_t b2ter_sys;

    #define arr_size(x) ((ulong)(sizeof(x)/sizeof(x[0])))
    /**
    NNE(X)
     * @returns :   true if x is not 0x0000
    */
    #define NNE(v) v==0x0000?0x01:0x00

    extern char **environ;

    static const uchar*charms[]={
        "att","bal","ccc","def","env","fmt",
        "git","hlv","inc","jab","kei","lbb",
        "mke","nop","ops","pub","que","rdl","sok",
        "trv","usr","vik","wln","xvl","ybn","z0x"
    };

    static const uchar*mods[]={
        "address","balance","charm","defined","enviroment","format",
        "git","hash","include","jaber","kei","lbb",
        "make","networks","osys","public","queue","riddle","shared",
        "traverse","user","vik","webpage","xolve","ybin","zen0x"
    };

    static const uns mods_count=arr_size(mods);
    static const uns __lbb_idx__=11;
    static uns env_hash_0,env_hash_1;

    ulong __env_hash(char **__var){
        uns __count=0;
        while(!NNE(__var[__count])){
            #ifdef DEBUG
                printf("%s\n",__var[__count]);
            #endif
            __count+=1;
        }
        env_hash_0=hash4(0,&__count,sizeof(uns));
        return (ulong)__count;
    }

    char const *__keys_hash(char **__var, uns __varc){
        uns _c=0;
        ulong hashes[__varc];
        void *__hptr=memset(&hashes,0,(sizeof(ulong)*__varc));
        while(_c<__varc){
            hashes[_c]=hash8(1,__var[_c],strlen(__var[_c]));
            #ifdef DEBUG
                printf("k-%08x:%u:=%s\n",hashes[_c],_c,__var[_c]);
            #endif
            _c+=1;
        }
        char const *env_hash_2=hashof(2,__hptr,sizeof(hashes));
        return env_hash_2;
    }

    ulong __arch_fsize(char *cpath){
        return fsze(cpath);     
    }

    ulong __fsize(char *fpath){
        struct stat __;
        memset(&__,0,sizeof(struct stat));
        if(stat(fpath,&__)!=0){return 0;}
        return __.st_size;
    }

    ulong __iosize(char *fpath){
        struct stat __;
        memset(&__,0,sizeof(struct stat));
        if(stat(fpath,&__)!=0){return 0;}
        return __.st_blksize;
    }

    uns __dmode(char *fpath){
        struct stat __;
        memset(&__,0,sizeof(struct stat));
        if(stat(fpath,&__)!=0){return 0;}
        return __.st_mode;
    }


    ulong __file_r(char*cpath){
        if (access(cpath,R_OK)==0){
            return 1;
        }
        return 0;
    }

    ulong __file_w(char*cpath){
        if (access(cpath,W_OK)==0){
            return 2; 
        }
        return 0;
    }

    ulong __file_x(char*cpath){
        if (access(cpath,X_OK)==0){
            return fsze(cpath);
        }
        return 0;
    }

    uns __8sz(uns _){
        uns __=1;while(_>0){__*=8;_--;}
        return __;
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
        sprintf(__,"%u\0",inp_u);
        return strdup(__);
    }

    char *arch_gfile(char *cpath){
        return tochar(fsze(cpath));
    }

    ulong attsize(ulong __size){
        int fd=open(".lbb",(O_RDWR|O_CREAT), S_IRWXU);
        if(fd==-1){
            printf("cannot create .lbb\n");
            return 0;
        }
        uchar buf[__size];
        memset(&buf,'#',(__size*sizeof(char)));
        uchar *buffer=buf;
        if(!NNE(buffer)){printf("not enough cache memory\n");return 0;}
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
        int fd=open(".lbb",(O_RDWR|O_CREAT), S_IRWXU);
        if(fd==-1){
            printf("cannot create .lbb\n");
            return 0;
        }
        ulong lbb_iosize=iosze(".lbb");
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

    ftype_s arch_tfile(char *cpath){
        ulong __fsize=__arch_fsize(cpath), res=0;
        while((__fsize>>3)!=8){
            res+=1;
        }
        switch(res){
        case 1:return __reader;
        case 2: return __socket;
        case 3: return __field;
        case 4: return __dir;
        case 5: return lbb_1;
        case 6: return lbb_2;
        case 7: return lbb_3;
        case 8: return lbb_4;
        default: return 0; 
        }
    }

    ulong arch_cfile(ftype _){
        switch(_){
            case __reader:return attsize(__8sz(1));
            case __socket:return attsize(__8sz(2));
            case __field:return attsize(__8sz(3));
            case __dir:return attsize(__8sz(4));
            case lbb_1:return lbbatt(1,__8sz(5));
            case lbb_2:return lbbatt(2,__8sz(6));
            case lbb_3:return lbbatt(3,__8sz(7));
            case lbb_4:return lbbatt(4,__8sz(8));
            default:return 0;
        }
    }



    ftype __size_switch(char *cpath) {
        ulong __fsize=__arch_fsize(cpath);
        switch(__fsize){
        case 8:return __reader;
        case 64: return __socket;
        case 512: return __field;
        case 4096: return __dir;
        case 32768: return lbb_1;
        case 262144: return lbb_2;
        case 2097152: return lbb_3;
        case 16777216: return lbb_4;
        default: return 0;
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
        if(!NNE(__)){return 0;}
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
            printf("%08x%08x",u[0],u[1]);
            printf("k+%llu\n",_ures);
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
    }

    int arch_env(void){
        char **__var=environ;
        uns envar_count=__env_hash(__var);
        char const *hvar=__keys_hash(__var,envar_count);
        printf("k+%x:%u:=ENVHASH=1\n",env_hash_0,envar_count); // ENVHASH :: ZENV
        return 0;
    }
#endif



// char __size8_ref(int i){
//     ulong __len=__8sz(i);
//     switch(__len){
//     case __MA__F: return 'k';
//     case __LO__F: return '@';
//     case __GS__F: return '/';
//     case __UN__F: return '#';
//     default: break;
//     }
//     return '_';
// }

#endif
    
/// mach file \\\
machine file ##by Karam Jaber.




#include <stdio.h>
#if _c

int main(int argc, char const*argv[]) {
    switch(argc){
    case 0:
        #define n0 (int)&'a'
    case 1:
        if(NNE(argv[1])){
#define DEBUG 1
            return arch_env();
        }
        // #define n1(x) ((ulong)x)
        break;
    case 2:
        #define n2 (int)&'0'
    default: break;
    }
#include "field.h"
    int __iter=0;
    #if _c
        #include <stdio.h>
        printf("here\n");
        for(__iter=_c;__iter!=0;__iter--){
            #include "field.h"
        }
        return 0;
    #endif 
}

#else
    int main() {
        printf("you like this?\n");
        return 0;
    }
#endif