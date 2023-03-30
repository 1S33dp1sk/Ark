
#define __ATP_TESTS 1


#ifdef __KVS_TESTS
void *__kvptr__(kvptr *kptr) {

	return memset(kptr, 0, sizeof(kvptr));
};

	kvptr *kv_memit(char const *key, char const *val) {
		ulong keylen=str_rwings(key), vallen=str_rwings(val);
		kvptr *__=(kvptr*)malloc(size_kv);
		void *__key=malloc(len_strze(keylen));
		void *__val=malloc(len_strze(vallen));
		memmove(__key, key, keylen);
		memmove(__val, val, vallen);
		__ -> key=(char const *)__key;
		__ -> val=(char const *)__val;
		__ -> offseter='\0';
		return __;
	};

	int kv_offset(kvptr *kv, char const *data, ulong offset_at) {
		memset((void *)kv, 0, size_kvp);
		kv->key=str_b4offset(data, offset_at);
		kv->val=str_a4offset(++data, offset_at);
		kv->offseter=data[offset_at];
		return 0;
	};

	kvptr *kv_at(char const *data, char *delim) {
		ulong __offset=sep_offset(data, delim);
		if(!__offset){
			return NULL;
		};
		kvptr *res=(kvptr*)malloc(size_kvp);
		kv_offset(res, data, __offset);
		return res;
	};

	void log_kvp(kvptr *res){
		printf("kv :'rn\n");
		printf("dlm -> %c\n", res->offseter);
		printf("key -> %s\n", res->key);
		printf("val -> %s\n", res->val);
	};

void *__keyvals__(keyvals *kvs) {

	return memset(kvs, 0, sizeof(keyvals));
};
	void free_kv(keyvals *__) {
		ulong __count=__->count;
		printf("total count = %lu \n", __count);
		for(int i=0; i<__count;i++) {
			free((void *)__->keys[i]);
			free((void *)__->values[i]);
		};
	};

	void free_kvs(keyvals *__) {
		free((void *)__->seperator);
		free((void *)__->__line_ends);
		free((void *)__->keys);
		free((void *)__->values);
	};

	void __free_str(char const *__) {
		
		free((void *)__);
	};

	void log_kvs(keyvals *__) {
		printf("kvs :: \n");
		printf("seperator (%s)\n", __->seperator);
		printf("line endings -> %s\n", __->__line_ends);
		ulong count=0,__c=__->count;
		char const *_k,*_v;
		printf("total kvs = %lu\n", __c);
		do {
			_k=__->keys[count];
			_v=__->values[count];
			printf("%s,%s   =: %lu\n", _k,_v,count);
			count+=1;
		}while(count<__c);
	};
	
	void log_kv(keyvals *__) {
		ulong __count=__->count;
		printf("total count = %lu \n", __count);
		for(int i=0; i<__count;i++) {
			printf("k-> %s\n v-> %s\n",__->keys[i],__->values[i]);
		};
	};

	void *__kvs__(keyvals *__, char const *sep, char const *lds) {
		ulong seplen=str_rwings(sep), ldslen=str_rwings(lds);
		char *__sep=(char *)malloc(len_strze(seplen));
		char *__lends=(char *)malloc(len_strze(ldslen));
		memmove(__sep, sep, seplen);
		memmove(__lends, lds, ldslen);
		memset(__, 0, sizeof(keyvals));
		__->seperator=(char const *)__sep;
		__->__line_ends=(char const *)__lends;
		__->keys=malloc(mem_sz);
		__->values=malloc(mem_sz);
		__->keys[0]=NULL;
		__->values[0]=NULL;
		__->count=0;
		return __;
	};

	int __add_pair(keyvals *kvs, char const *key, char const *val) {

		log_kvs(kvs);

		return 0;
	};

	int kvs_pair(keyvals *kvs, char const *key, char const *val) {
		ulong keylen=str_rwings(key), vallen=str_rwings(val);
		char const *__key=(char const *)malloc(len_strze(keylen));
		char const *__val=(char const *)malloc(len_strze(vallen));
		memmove((void *)__key, key, keylen);
		memmove((void *)__val, val, vallen);
		#ifdef DEBUG
			printf("adding pair :: (%s,%s)\n",key, val);
		#endif
		return __add_pair(kvs, __key, __val);
	};

void *__sline__(s_line *sline) {

	return memset(sline, 0, sizeof(s_line));
};
	s_line*kvs_liner(char const *__key, char const *__val, char const *__dlm, char const *__lds) {
		ulong keylen=str_rwings(__key), vallen=str_rwings(__val), dlmlen=str_rwings(__dlm), ldslen=str_rwings(__lds);
		ulong __size=keylen+vallen+dlmlen+ldslen;
		void *__=malloc(len_strze(__size));
		memmove(__, __key, keylen);
		memmove((__+keylen), __dlm, dlmlen);
		memmove((__+keylen+dlmlen), __val, vallen);
		memmove((__+keylen+dlmlen+vallen), __lds, ldslen);
		s_line *_=(s_line *)malloc(size_sline);
		_->__size=__size;
		_->__cptr=__;
		return _;
	};

	void free_kv_sline(s_line *kvs_sl) {
		free((void *)kvs_sl->__cptr);
		free(kvs_sl);
	};

	char const *kvs_traverse(keyvals *kvs) {
		ulong __size=0, c=0, count=kvs->count;
		do {
			#ifdef DEBUG
				printf("kvs->key : %lu :: %s\n", c, kvs_key(kvs,c));
				printf("kvs->val : %lu :: %s\n", c, kvs_val(kvs,c));
			#endif
			__size+=str_rwings(kvs->keys[c]);
			__size+=str_rwings(kvs->values[c]);
			c+=1;
		} while(c<count);
		ulong __len=len_strze(__size);
		#ifdef DEBUG
			printf("size : %lu\n", __size);
		#endif
		char *__=(char *)malloc(__len);
		memset(__, '\0', sizeof(__len));
		c=1;__size=0;
		while(c<count){
			s_line *temp=kvs_liner kvs_id(kvs,c);
			memmove((__+__size), (void *)temp->__cptr, temp->__size);
			__size+=(temp->__size);
			free_kv_sline(temp);
			c+=1;
		};

		return strdup(__);
	};



#endif


#ifdef __FILE_MULTI_IO_TESTS
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
	ulong fldatt(ulong level,ulong sizeatt){
		int fd=open(arch_filename,(O_RDWR|O_CREAT), S_IRWXU);
		if(fd==-1){
			printf("cannot create .lbb\n");
			return 0;
		};
		ulong lbb_iosize=iosze(arch_filename);
		ulong cptr=0,blk=0,chk_blocks=sizeatt&lbb_iosize,nblocks=sizeatt/lbb_iosize;
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

	static const ulong mods_count=arr_size(mods);

	// get this architicture modificiations {{ CERTIFICATE }}
	int arch_mods(char const *__3curl){
		ulong fieldname=0, ccc__offset=0;
		char const *__mod,*__crm,*__3c;
		ulong __len=0, __offset=0;
		int c=0; // count
		for(;c<mods_count;c++){
			__mod=(char*)mods[c];
			__crm=(char*)charms[c];
			__3c=ccopy_to_path(__crm,__3curl);
			__len=arch_tfile(__3c);
			__offset+=arch_fpermissions(__3c);
			ccc__offset+=arch_foffset(__3c,__offset);
			fieldname=arch_fname(__crm,ccc__offset);
		}
		return 0;
	}


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
	#ifndef k_stat
		// K structure
		struct __ptrdx {
			ulong pidx;
			ulong tri;
		};
		union __exs_ptr {
			ulong *esptr;
			struct __ptrdx ptrdx;
		};
		struct __k_stat {
			char u_name[8];
			union __exs_ptr exsp;
			char i_addr[512];
		};
		typedef struct __k_stat k_stat;
		static const ulong size_kstat=sizeof(k_stat);
	#endif

	struct __ptrdx __iptridx(char const *__ptr_index) {
		char *_ptr_idx=(char *)__ptr_index;

		ulong plen=str_rwings(_ptr_idx);
		ulong lcount=0;

		ulong off_at=sep_offset(_ptr_idx,"ae");

		char *_pidx=str_b4offset(_ptr_idx,off_at);
		ulong pidx,_pxlen=str_rwings(_pidx);
		uchar *pidx_=(uchar *)_pidx;
		unpack(pidx_,"L",pidx);


		char *_tri=str_a4offset(_ptr_idx,off_at);
		ulong tri,_tilen=str_rwings(_tri);
		uchar *tri_=(uchar *)_tri;
		unpack(tri_,"L",tri);

		struct __ptrdx ipd;
		memset(&ipd,0,sizeof(struct __ptrdx));
		ipd.pidx=pidx;
		ipd.tri=tri;

		return ipd;
	};

	void *___exsptr(char const *__ptr_index) {
		ulong lcount=0, lcpy=0, plen=str_rwings(__ptr_index), comb_len=plen;
		char *_ptr_idx=(char *)__ptr_index;
		uchar *__pind=(uchar *)_ptr_idx;

		while(comb_len>8){
			lcount+=1;comb_len-=8;
		};

		// ulong esize=lcount*(sizeof(ulong));
		// void *_es_ptrs=malloc(esize);
		// _es_ptrs=memset(_es_ptrs,0,esize);

		// ulong *es_ptr=(ulong *)_es_ptrs;

		// es_ptr[0]=1281;
		// es_ptr[1]=28589105;

		// // while(lcpy<(lcount-1)){
		// // 	unpack(__pind,"L",es_ptrs[lcpy]);
		// // 	lcpy+=1;
		// // };
		// // es_ptrs[lcount]='\0';

		// // // log_esptr()
		// // return es_ptrs;


		return (void *)__ptr_index;
	};

	spstr sepstr_offset(char *string, char *seperator) {
		int x=0,y=0,len_count=0,offset_at=-1;
		while(string[x]!='\0'){
			if(string[x]==seperator[y]){
				while(seperator[y]==string[y+x]){
					y+=1;
				};
				if(seperator[y]=='\0'){
					offset_at=x;
				}
				else{
					y=0;
				};
			};
			x+=1;
		};
		spstr res = {
			.str=string,
			.str_length=x,
			.sep=seperator,
			.sep_offs=offset_at,
		};
		return res;
	};

	/**
	 * extract the string at offset
	**/
	strld extract_atoff(char *str, ulong atoff){
		strld res;
		res.data=str+atoff;
		char *s=str+atoff;
		int c=0;
		while(*s++){
			c+=1;
		};
		res.len=c;
		return res;
	};


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


	/*******************************************************************/


	void test_spaces_and_tabs() {
		int spta_count=spaces_and_tabs(" aksd foa	sf");
		printf("spaces+tabs count :: %d\n",spta_count);
	};

	void test_init_sepstr(char const*fullstr, char const*sep) {
		spstr res;
		if(fullstr==NULL||sep==NULL){
			res=sepstr_offset("mykey:has a very niceth=ce value of ", "=c");
		}
		else {
			res=sepstr_offset((char *)fullstr,(char *)sep);
		};

		log_sepstr(res);
	};


	int main_atoff(){
		strld sep=extract_atoff("hello world\n",6);
		log_strld(sep);
		return 0;
	};

	 int get_kstat(char const *__path, k_stat *kfile) {
	 	memset(kfile,0,sizeof(struct __k_stat));
	 	char *_path=(char *)__path;
	 	ulong off_at=sep_offset(_path,"@");


	 	char *uname=str_b4offset(_path,off_at);
	 	ulong unlen=str_rwings(uname);

	 	char *ixes=str_a4offset(_path,off_at);
	 	ulong ixlen=str_rwings(ixes);

	 	memmove((&kfile->u_name),uname,unlen);
	 	memmove((&kfile->i_addr),ixes,ixlen);

	 	(kfile->exsp).ptrdx=__iptridx(__path);
	 	log_ptrdx(&((kfile->exsp).ptrdx));

	 	 (kfile->exsp).esptr=___exsptr(__path);
	 	 log_esptr((kfile->exsp).esptr);
	 	return 0;
	 };

	 int main_sepstr(int argc, char const *argv[]){
		if(argc==3){
			test_init_sepstr(argv[1],argv[2]);
		}
		else{
			test_init_sepstr(NULL,NULL);
		}
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