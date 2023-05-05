


/************************ h-logging ************************/

#ifndef _D_LOG
	#define _D_LOG 1

	void log_str(int __fd,char const *__) {
		write(__fd,__,str_rwings(__));
	};

	void arange_var(char const v[4]) {
		// printf("%s", v);
		printf("\n");
	};

	char const *__arange_vars(char *__v, ulong __vlen) {
		char __[20]; memset(&__, 0, sizeof(__));
		for(int i=0; i<__vlen;i+=4) {
			if(i%4==0) {
				sprintf(__, "%s", &__v[i]);
				printf("char : %d : %s\n", i, __);
			}
		};
		printf("str : %s\n", (char *)&__);
		return strdup((char const *)__);
	};

	char const *csv_int(int *ptr, ulong ptr_count) {
		ulong c=0, _magic=ptr_count*21;
		char __[_magic];memset(&__, 0, _magic);
		for (int i=0; i<ptr_count; i++) {
			char const *__num = num2char(ptr[i]);
			ulong __len = str_rwings(__num);
			memmove(&__[c], __num, __len);
			c+=__len;
			__[c]=',';
			c+=1;
			#ifdef DEBUG
				printf("%d : %s\n", i, __[i]);
			#endif
		};
		__[c-1]='\0';
		return strdup((char const *)__);
	};

	char const *csv_str(char const **ptr, ulong ptr_count) {
		ulong c=0, clen=0;
		while(c<ptr_count) {
			if(ptr[c]){
				clen+=str_rwings(ptr[c]);
			};
			c+=1;
		};
		ulong _magic = clen+ptr_count; // foreach => ptr_count+1 -> `,` 
		#ifdef DEBUG
			printf("combined string arr size :: %s\n", num2char(clen));
		#endif
		char __[_magic]; memset(&__, 0, _magic);
		c=0;
		for (int i=0; i<ptr_count; i+=1) {
			ulong __len = str_rwings(ptr[i]);
			memmove(&__[c], ptr[i], __len);
			c+=__len;
			__[c]=',';
			c+=1;
			#ifdef DEBUG
				printf("%d : %s\n", i, &__[i]);
			#endif
		};
		__[c-1]='\0';

		return strdup((char const *)__);
	};

	#define _U_CODE(x) x[0]!=0||x[1]!=0||x[2]!=0||x[3]!=0?1:0

	char const *csv_uni(char const _ucode[][4], ulong uc_count) {
		ulong c=0, clen=0;
		while(c<uc_count) {
			if(_U_CODE(_ucode[c])){
				clen+=4;
			};
			c+=1;
		};
		ulong _magic = clen+uc_count; // foreach => uc_count+1 -> `,` 
		#ifdef DEBUG
			printf("combined string arr size :: %s\n", num2char(clen));
		#endif
		char __[_magic], *p=(char *)&__; memset(&__, 0, _magic);
		c=0;
		char **temp;
		for (int i=0; i<uc_count; i+=1) {
			snprintf(p, 4, "%s", &_ucode[i][0]);
			temp[i]=p;
			p+=4;
		};
		for(int j=0; j<3; j++) {
			printf("p : %s\n", temp[j]);
		}
		return strdup((char const *)__);
	};

	char const *unicode_str(char const __address[][4], ulong __len) {
		printf("unicode chars : %lu\n", __len);
		ulong c=0, _magic = (4*__len)+__len; // consider 4 bytes for char + foreach `,`
		char __[_magic]; memset(&__, 0, _magic);
		for (int i=0; i<__len; i+=1) {
			memmove(&__[c], &__address[i], 4); c+=4;
			arange_var(__);
		};
		__[_magic]='\0';
		return __arange_vars(__, _magic);
	};


/**
 * dPRG(
	ulong num=6, len=3;
	int temp[3] = {11,22,33};
	storage_log(num, temp, len)
)
**/
	void storage_log(ulong __idx, int *__vu_args, ulong __len) {
		char const *__name_idx = num2char(__idx);
		char const *__count = num2char(__len);
		char const *__csv = csv_int(__vu_args, __len);
		#ifdef DEBUG
			printf("index @%s\n", __name_idx);
			printf("$VA_ARGS %s\n", __count);
			printf("VU_ARGS '%s'", __csv);
		#endif
		#ifdef OUTPUT
			printf("%s:%s\t'%s'", __name_idx, __count, __csv);
		#endif
	};

/**
 * 
dPRG(
	char const *temp[] = {"address", "balance", "ccc"};
	misc_log("9", temp, 3);
)
**/
	void misc_log(char const *__iden, char const **__vs_args, ulong __len) {
		char const *__count = num2char(__len);
		char const *__csv = csv_str(__vs_args, __len);
		#ifdef DEBUG
			printf("index @%s\n", __iden);
			printf("count=%s\n", __count);
			printf("VS_ARGS \"%s\"", __csv);
		#endif
		#ifdef OUTPUT
			printf("%s:%s\t\"%s\"", __iden, __count, __csv);
		#endif
	};

// temporary
/**
 * dPRG(
	char const temp[][4] = {"\U000021AF", "\U000031CF", "\U000091EF"};
	unicode_log("1S33dp1sk", temp, 3);
)
**/
	void unicode_log(char const *__name, char const __address[][4], ulong __len) {
		char const *__count = num2char(__len);
		char const *__csv = unicode_str(__address, __len);
		#ifdef DEBUG
			printf("index @%s\n", __name);
			printf("count=%s\n", __count);
			printf("unicode args  `%s`", __csv);
		#endif
		#ifdef OUTPUT
			printf("%s:%s\t`%s`", __name, __count, __csv);
		#endif
	};



	void log_ixr(ixr_h ixr) {
		return log_ixrh(&ixr);
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

	#define __ixr_shared(x) "shared_size":(x)

	#define ixr_shared(x) __ixr_shared(#x)

	void log_ixrh(ixr_h *ixrh) {
		// log indexer prototype
		_log(0,ixrh);
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


	void log_into(d_into into_st) {
		printf("into : \n");
		printf("request <%u> \n", in_switch(into_st));
		printf("caller  : %s\n", in_caller(into_st));
		printf("arg    :: %s\n", in_argument(into_st));
	};
	
	// log the key value as strings
	void log_keyvalue(char *key, char *value) {
		__ASCII(0,key);
		__ASCII(0,value);
	};
	// print the corrent way of using the `d-lbb` command
	void lbb_usage(){
		__TEXT(0, Use lbb as :: `d-lbb /path/to/file`);
	};

	// void log_ixr_point(void *__) {
	// 	printf("point index 	: %lu\n",ist_index(__));
	// 	printf("point reference : %s\n", ist_ref(__));
	// 	printf("point name  	: %s\n", ist_name(__));
	// };

	void log_program(d_prg *prg) {
		printf("call : %s", prg->__);
		const char *arg = prg->prg_args;
		ulong c=0;
		do {
			printf(" :: %s\n", arg);
			c+=1; arg = prg->prg_args;
			arg=prg->prg_args+=1;
		}while(arg!=NULL);
		//printf("!%s\n", prg->prg_handler);
	};

	void log_read_err(int __errno) {
    	switch(__errno) {
         case EAGAIN:    printf("The file was marked for non-blocking I/O, and no data were ready to be read.");
         case EBADF:     printf("fildes is not a valid file or socket descriptor open for reading.");
         case EFAULT:    printf("Buf points outside the allocated address space.");
         case EINTR:     printf("A read from a slow device was interrupted before any data arrived by the delivery of a signal.");
         case EINVAL:    printf("The pointer associated with fildes was negative.");
         case EIO:       printf("An I/O error occurred while reading from the file system.");
         case EISDIR:    printf("An attempt is made to read a directory.");
         case ENOBUFS:   printf("An attempt to allocate a memory buffer fails.");
         case ENOMEM:    printf("Insufficient memory is available.");
         case ENXIO:  	 printf("An action is requested of a device that does not exist.");
         case ESTALE:    printf("An attempt to read a remote file through NFS that has already been deleted in the server.");
         case ETIMEDOUT: printf("The connection timed out while reading a remote file from a soft mounted NFS volume.");
         case EDEADLK:   printf("The file is a “dataless” file that requires materialization and the I/O policy of the current");
         case ESPIPE:    printf("The file descriptor is associated with a pipe, socket, or FIFO.");
         case ECONNRESET:printf("The connection is closed by the peer during a read attempt on a socket");
         case ENOTCONN:  printf("A read is attempted on an unconnected socket.");
         default:        printf("read err : unknown\n");
    }
	}


	#define __H512__L 1
#endif
