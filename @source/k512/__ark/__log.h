


/************************ h-logging ************************/

#ifndef _D_LOG
	#define _D_LOG 1
	void log_str(char const *__) {
		write(0,__,str_rwings(__));
		write(0,"\n",1);
	};

	void log_dpoint(d_point *dst_point) {
		printf("dst point :: \n");
		printf("@%lu\n", dst_point->c_index);
		printf("name :%s\n",dst_point->c_name);
		printf("ref  :%s\n",dst_point->c_ref);
	};

	void log_sstat(s_stat *sfile){
		printf("dcloud : ATP :: dist ::: shared\n");
		printf("path	= %s\n", sfile->s_path);
		printf("iploc	= %s\n", sfile->s_ipv);
		printf("port	= %s\n", __s_port);
		printf("addr	= %s\n", sfile->s_addr);
		printf("term	= %s\n", sfile->s_term==0?"PUBLIC":"PRIVATE");
	};

	void log_mstat(m_stat *mfile){
		printf("dcloud : ATP :: dist ::: mounted\n");
		printf("path	= %s\n", mfile->m_path);
		printf("nodenum	= %lu\n", mfile->m_inn);
		printf("size	= %lu\n",mfile->m_size);
		printf("mode	= %lu\n",mfile->m_mode);
		printf("blkio	= %lu\n",mfile->m_blksz);
	};

	void log_esptr(ulong *esptr) {
		printf("dcloud : K :: esptr\n");
		ulong c=0;
		do {
			printf(":%lu=%lu\n",c,esptr[c]);c+=1;
		}
		while(*esptr++);
	};

	void log_process_ids(ulong p_pid, ulong c_pid) {
	   printf("process ids ::\n");
	   printf("p.pid    =%lu\n",p_pid);
	   printf("c.pid    =%lu\n",c_pid);
	};

	void log_process_schema(ulong p_pid, ulong c_pid) {
	    printf("p_pid :: %lu",p_pid);
	    printf("\nc_pid :: %lu",c_pid);
	    printf("\nsuccess=%d\tnsucess=%d\n",CALL_SUCC(c_pid),CALL_NSUC(c_pid));
	    printf("call next ? %lu\n",CALL_NEXT(c_pid));
	};

	void log_at_protoname(atp_t __atpname) {
		switch(__atpname) {
		case __at_p: 		printf("ATP : @				::\b"); break;
		case __at_4: 		printf("ATP : @Ipv4			::\b"); break;
		case __at_6: 		printf("ATP : @Ipv6			::\b"); break;
		case __at_e:		printf("ATP : @ETHEREUM		::\b"); break;
		case __at__:		printf("ATP : @-Protocol	::\b"); break;
		default:			printf("ATP <dcloud> 		:::\n"); break;
		};
	};
	
	void log_ixrh(ixr_h *ixrh) {
		// log indexer prototype
		printf("\nindexer head ::\n");
		printf("\tfldsze=%lu", ixrh->__size);
		printf("\tdcount=%lu", ixrh->d_count);
		printf("\tchksum=%lu", ixrh->checksum);
		printf("\n");
	};

	void log_socket(aip_sock *sock) {

		printf("socket @%s\n",aip_sockname(sock));
	};

	// misc
	char const *__atp_names(int __at) {
		switch(__at) {
		case __lbb_none__:		return "#%d	NoEntry";
		case __lbb_charms__:	return "#%d	@charms/";
		case __lbb_yeild__:		return "#%d	@lbb";
		case __lbb_info__:		return "#%d	:IXR:";
		case __lbb_variable__:	return "#%d	var";
		case aip_base:			return "#%d	K-lbb";
		case aip_get:			return "#%d	K-@ATP<get>";
		case aip_set:			return "#%d	K-@ATP<set>(varname){value}";
		case aip_return: 		return "#%d	K-atp_fetch";
		case aip_retain: 		return "#%d	K-atp_save";
		case aip_retreive: 		return "#%d	K-atp_call";
		case aip_dcloud: 		return "#%d	K-dcloud_connect";
		case aip_next: 			return "#%d	K-&ATP->";
		default: 				return "#%d	K-default";
		};
	};

	void log_atp_names() {
		printf("\natp names :\n");
		printf("%s\n", __atp_names(__lbb_none__));
		printf("%s\n", __atp_names(__lbb_charms__));
		printf("%s\n", __atp_names(__lbb_yeild__));
		printf("%s\n", __atp_names(__lbb_info__));
		printf("%s\n", __atp_names(__lbb_variable__));
		printf("%s\n", __atp_names(aip_base));
		printf("%s\n", __atp_names(aip_get));
		printf("%s\n", __atp_names(aip_set));
		printf("%s\n", __atp_names(aip_return));
		printf("%s\n", __atp_names(aip_retain));
		printf("%s\n", __atp_names(aip_retreive));
		printf("%s\n", __atp_names(aip_dcloud));
		printf("%s\n", __atp_names(aip_next));
	};

	void log_content(content_st *content) {
		printf("content :: \n");
		printf("type    : %u\n",http_ctype(content));
		printf("data    : %s\n",(char *)http_cdata(content));
		printf("size    : %lu\n",http_clen(content));
	};


	void log_into(d_into *into_st) {
		printf("into : \n");
		printf("request <%u> \n", in_switch(into_st));
		printf("caller  : %s\n", in_caller(into_st));
		printf("arg    :: %s\n", in_argument(into_st));
	};
	
	// log the key value as strings
	void log_keyvalue(char *key, char *value) {
		__ASCII(key);
		__ASCII(value);
	};
	// print the corrent way of using the `d-lbb` command
	void lbb_usage(){
		__TEXT(Use lbb as :: `d-lbb /path/to/file`);
	};

	void log_ixr_point(void *__) {
		printf("point index 	: %lu\n",ist_index(__));
		printf("point reference : %s\n", ist_ref(__));
		printf("point name  	: %s\n", ist_name(__));
	};


	#define __H512__L 1
#endif
