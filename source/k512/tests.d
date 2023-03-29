
#define __ATP_TESTS 1


#ifdef __FILE_MULTI_IO
	// creates a file of a particular increment size
	ulong attsize(ulong __size){
		int fd=open(arch_filename,(O_RDWR|O_CREAT), S_IRWXU);
		if(fd==-1){
			printf("cannot create .lbb\n");
			return 0;
		};
		uchar buf[__size];
		memset(&buf,'#',(__size*sizeof(char)));
		uchar *buffer=buf;
		ulong __set=0;
		long int temp=0;
		while(__set<__size){
			temp=pwrite(fd,buf,__size,__set);
			if(temp==-1){
				printf("error pwriting\n");return 0;
			};
			__set+=temp;temp=0;
		};
		return fd;
	};
	// fills up the file created 
	ulong fldatt(uns level,ulong sizeatt){
		int fd=open(arch_filename,(O_RDWR|O_CREAT), S_IRWXU);
		if(fd==-1){
			printf("cannot create .lbb\n");
			return 0;
		};
		ulong lbb_iosize=iosze(arch_filename);
		uns cptr=0,blk=0,chk_blocks=sizeatt&lbb_iosize,nblocks=sizeatt/lbb_iosize;
		if(chk_blocks||!nblocks){
			printf("wrong size.\noctal system handler \n");
			return 0;
		};
		ulong total=0;long int temp=0;
		uchar buf[512];
		memset(&buf,'@',(512*sizeof(uchar)));
		for(;blk<nblocks;){
			temp=pwrite(fd,buf,512,total);
			if(temp==-1){printf("error writing\n"); return 0;}
			total+=temp;temp=0;blk++;
		};
		return fd;
	};
#endif


#ifdef __BASE_26_TESTS
	/********* base26 *********/
	static const uchar charms[26][4]={
		"att\0","bal\0","ccc\0","def\0","env\0","fmt\0",
		"git\0","hlv\0","inc\0","jab\0","kei\0","lbb\0",
		"mke\0","nop\0","ops\0","pub\0","que\0","rdl\0","sok\0",
		"trv\0","usr\0","vik\0","wln\0","xvl\0","ybn\0","z0x\0"
	};

	static const ulong __enu_size=512;
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
	typedef struct __ccc_item ccc;

	static ccc kCCC[26];

	int __init_3ci(){
		int i_index=0;
		for(; i_index<25;i_index+=1){
			kCCC[i_index].__charm=charms[i_index];
			kCCC[i_index].__mod=mods[i_index];
			kCCC[i_index].__3chash=elem_hash(mods[i_index]);
			kCCC[i_index].nxt=&kCCC[i_index+1];
			printf("INDEXING ARC :%d: %s\n", i_index,mods[i_index]);
		}
		printf("INDEXING ARC :%d: %s\n", i_index,mods[i_index]);
		kCCC[i_index].__charm=charms[i_index];
		kCCC[i_index].__mod=mods[i_index];
		kCCC[i_index].__3chash=elem_hash(mods[i_index]);
		kCCC[i_index].nxt=NULL;
		return i_index;
	};

	int arch_3ci(){
		return __init_3ci();
	};

	void log_arcs(){
		ccc *kccc=kCCC;
		while(kccc!=NULL){
			printf("name :: %s\n",kccc->__mod);
			printf("charm :: %s\n",kccc->__charm);
			printf("hash :: %lu\n",kccc->__3chash);
			kccc=kccc->nxt;
		};
	};


#endif

#ifdef __MISC_TESTS
	#ifndef __strld
	/*** string manipulation ***/
		struct __strld {
			int len;
			char *data;
		};
		typedef struct __strld strld;
	#endif
	#ifndef __sepstr
		struct __sepstr {
			char *str;
			int str_length;
			char *sep;
			int sep_offs;	
		};
		typedef struct __sepstr spstr;
	#endif
	void log_strld(strld __strld);
	void log_sepstr(spstr __spstr);
	void log_ptrdx(struct __ptrdx *ptrdx);
	void log_strld(strld __){
		printf("string\n");
		printf("length=%d\n",__.len);
		printf("data:=%s\n",__.data);
	};

	void log_sepstr(spstr ss){
		printf("string=%s\nlength=%d\nseperator=%s\noffset=%d\n",ss.str,ss.str_length,ss.sep,ss.sep_offs);
	};

	void log_ptrdx(struct __ptrdx *ptrdx) {
		printf("dcloud : K :: ptrdx\n");
		printf("pidx :%lu\n",ptrdx->pidx);
		printf("tri  :%lu\n",ptrdx->tri);
	};

	void log_kstat(k_stat *kfile) {
		printf("dcloud : K\n");
		printf("uname	= %s\n", kfile->u_name);
		printf("iaddr	= %s\n", kfile->i_addr);
	};

	//int __get_fd(char const *__path, int __flag){

	//	return open(__path, __flag);
	//};

	//int __get_process_flags(char const *__path){

	//	return dmde(__cpath);
	//};

int main_atoff(){
	strld sep=extract_atoff("hello world\n",6);
	log_strld(sep);
	return 0;
};
#endif

#ifdef __HTTP_TESTS
	int main(){
		char const *request=form_http_request(__http_get, "/index.html");
		printf("request : %s\n", request);

		char const *response=form_http_response(200, "OK");
		printf("response : %s\n", response);
		return 0;
	};
#endif

#ifdef __DPRG_TESTS
	char *tmp="/Users/mrkj/Custom/web-socket-app/public/index.html";

	#define addr_size(x) ((ulong)sizeof((x->address)))
	#define paddr(x) &(x.address)
	/**
		lbb command @/Users/mrkj/Custom/web-socket-app/public/index.html<(null)>
		lbb filepath :/Users/mrkj/Custom/web-socket-app/public/index.html+0
		lbb function ::/Users/mrkj/Custom/web-socket-app/public/index.html(lbb call)=unknown args
		lbb field </Users/mrkj/Custom/web-socket-app/public/index.html> ::: 0x60000055c030 
		lbb address @0x10038393f
	 **/
	int main(int argc, char const *argv[]) {
		payld_st pyld;
		void *ptr=malloc(8);

	__lbb_command(tmp, NULL);

	__lbb_filepath(tmp, __pub);

	__lbb_function(tmp, paddr(pyld), &pyld);

	__lbb_field(tmp, ptr);

	__lbb_address(tmp);
	};
#endif

#ifdef __ATP_TESTS

	struct __test_arg_t {
		char const *arg;
		const char **extras;
	} test_arg[] = {
		{.arg="@charms/fieldname", .extras=(const char **)("get_fld")},
		{.arg="@lbb1address", .extras=((const char **)(&"read"))},
		{.arg="@GET", .extras=(const char **)(NULL)},
		{.arg="@9398f19a9b2", .extras=(const char **)("type")},
		{.arg="@special_var", .extras=(const char **)("special_val")},
		{.arg="random_var", .extras=(const char **)(&"get")},
		{.arg="RandomVar", .extras=(const char **)("set""val")},
		{.arg="12eRandom", .extras=(const char **)(NULL)},
	};

	int __atp_main(int argc, char const *argv[]) {
		into_st into;
		into_st *__p=__into__(&into);
		into_caller(into, argv[0]);
		into_args(into, &argv[1]);
		into_type(into, get_atp_type(argv[1]));
		__protocol__(into.req_at);
	}

	int __test_arg(char const *arg, char const **args) {
		args[1] = arg;
		args[2]=NULL;
		printf("\n\ntest :: \n");
		int res=__atp_main(2, args);
		printf("d-atp <%s, %s>(%d)\n\n", args[0], args[1], res);
		return res;
	};

	int __test__(struct __test_arg_t __, char const *args[]) {
		args[1] = __.arg;
		args[2]=__.extras;
		printf("\ntest :: %s\n", args[1]);
		int res=__atp_main(2, args);
		printf("<%s, %s>(%d)\n", args[0], args[1], res);
		return res;
	};

	dPRG(
		printf("TESTING ATP ::\n\t");
			ARR_SEP(test_arg, ',');
		printf("\n");
		for(int i=0; i<arr_size(test_arg); i++){
			__test__(test_arg[i], argv);
		};
	)

	
#endif