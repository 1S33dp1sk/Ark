
/************************ d-hash ************************/

#ifndef _D_HASH
	#define _D_HASH 1

		#define __size_u64 sizeof(uint64_t)
        #define __sha3_k_sponge_w (((1600)/8)/__size_u64) //bits to byte
	    struct __sha3_context {
	        uint64_t saved;             
	                // remainder of input string that we didn't consume yet
	        union {                     
	            uint64_t s[__sha3_k_sponge_w];
	            uint8_t sb[__sha3_k_sponge_w*8];
	        } u;                        
	                // keccak's state 
	        unsigned byte_idx;         
	                // 0..7--the next byte after the set one (starts from 0; 0--none are buffered) 
	        unsigned word_idx;         
	                // 0..24--the next word to integrate input (starts from 0)
	        unsigned cap_words;
	                // the double size of the hash output in words (e.g. 16 for Keccak 512)
	    };
    typedef struct __sha3_context sha3_context;
	        #define __sha3_rot_l_64(x, y) (((x)<<(y))|((x)>>((__size_u64*8)-(y))))
	    static sha3_context __sha3;
    

	void __hex_bytes(uint8_t __c, char __s[3]) {
		uint32_t i=1;
		__s[0] = __s[1] = '0';
		__s[2] = '\0';
		while(__c) {
			uint32_t t = __c&0x0f;
			if(t<10) {
				__s[i] = '0'+t;
			} 
			else {
				__s[i] = 'a'+t-10;
			};
			i--;
			__c>>=4;
		}
	};

	void __sha3_str(char *buffer, uint8_t *__hash, unsigned __len) {
		char __[3];
		for (int i=0;i<__len;i+=1) {
			__hex_bytes(__hash[i], __);
			strncat(buffer, (char *)__, 3);
			// memmove(buffer+i, (char *)__, 3);
		};
	};


	void htostr(char *__str, uint8_t *__hash) {
		__sha3_str(__str, __hash, 32);
	};
	/**
	 * @dev used to hash the input from
	 * @param key       : `argv[1]`
	 * 
	 * and copy the result to a pre-allocated buffer
	 * @param hashkey   : ( char[256] )
	 */
	char *__s_hash(char *__key, char *__hash) {
		ulong __keylen=str_rwings(__key);
		#ifdef DEBUG
			printf("-----BEGIN HASH DEBUG-----\n");
			printf("key : %s :: %lu\n",__key, __keylen);
		#endif
		sha3_init256(&__sha3);
		sha3_set_flags(&__sha3,1);
		sha3_update(&__sha3,__key,__keylen);
		uchar *__uhash=(uchar *)sha3_finalize(&__sha3);
		htostr(__hash,__uhash);
		#ifdef DEBUG
			printf( "hash : %s\n" , __hash);
			printf( "-----END HASH DEBUG-----\n" );
		#endif
		return __hash;
	}
	/**
	blaz_hash : used in function signatures
	 *
	**/  
   	ulong blaz_hash(char const *__data) {
		ulong len=str_rwings(__data), hash=len, tmp, dsize=(sizeof(uchar)*2), ucsize=dsize*2;
		slong rem;
		if (len<=0||__data==NULL) { 
			return 0; 
		};
		rem=len&3;
		len>>=2;
		/* main */
		for (;len>0; len--) {
			hash  += get16bits (__data);
			tmp    = (get16bits(__data+2)<<11)^hash;
			hash   = (hash<<16)^tmp;
			__data+= ucsize;
			hash  += hash>>11;
		};
		/* handler */
		switch (rem) {
			case 3: hash+=get16bits(__data);
					hash^=hash<<16;
					hash^=((schar)__data[dsize]) << 18;
					hash+=hash>>11;
					break;
			case 2: hash+=get16bits (__data);
					hash^=hash<<11;
					hash+=hash>>17;
					break;
			case 1: hash+=(schar)*__data;
					hash^=hash<<10;
					hash+=hash>>1;
		};
		/* force out 127 bits*/
		hash^=hash<<3;
		hash+=hash>>5;
		hash^=hash<<4;
		hash+=hash>>17;
		hash^=hash<<25;
		hash+=hash>>6;

		return hash;
	};
	/**
	[initiate | reset] the sha3 context
	**/
	sha3_r sha3_init(void *priv, ulong bit_size) {
		sha3_context *ctx = (sha3_context *) priv;
		if( bit_size != 256 && bit_size != 384 && bit_size != 512 ) {
			return __sha3_u_n;
		};
		memset(ctx ,0 , __size_sha3_context);
		#ifdef H_DEBUG
			printf("ctx -> cap_words : %lu\n", (2*bit_size/(8*__size_u64)));
		#endif
		ctx->cap_words=(2*bit_size/(8*__size_u64));
		return __sha3_u_ok;
	};
	/**
	[set | unset] keccak flag
	 *
	**/
	sha3_f sha3_set_flags(void *priv, sha3_f flags) {
		sha3_context *ctx=(sha3_context *)priv;
		flags&=__sha3_flag_keccak__;
		ctx->cap_words|=(flags==__sha3_flag_none__?__sha3_flag_keccak__:0);
		return flags;
	};
	/**
	XOR into state for keccak
	 * generally called after `__sha3_k_sponge_w - ctx` -> cap_words words 
	 * are `XOR()` into the state `s` 
	**/
	static void keccakf(uint64_t s[25]) {
		int i, j, round;
		uint64_t t, bc[5];
	#define __sha3_keccak_rounds 24
		for(round=0; round<__sha3_keccak_rounds; round++) {
			/* Theta */
			for(i=0; i<5; i++)
				bc[i]=s[i]^s[i+5]^s[i+10]^s[i+15]^s[i+20];

			for(i=0; i<5; i++) {
				t = bc[(i+4)%5]^__sha3_rot_l_64(bc[(i+1)%5], 1);
				for(j=0; j<25; j+=5)
					s[j+i]^=t;
			};
			/* Rho Pi */
			t = s[1];
			for(i=0; i<24; i++) {
				j=keccakf_piln[i];
				bc[0]=s[j];
				s[j]=__sha3_rot_l_64(t, keccakf_rotc[i]);
				t=bc[0];
			};
			/* Chi */
			for(j=0; j<25; j+=5) {
				for(i=0; i<5; i++)
					bc[i]=s[j+i];
				for(i=0; i<5; i++)
					s[j+i]^=(~bc[(i+1)%5])&bc[(i+2)%5];
			};
			/* Iota */
			s[0] ^= keccakf_rndc[round];
		}
	};
	/**
	hash the buffer in ctx
	 *
	**/
	void sha3_update(void *priv, void const *buf_inp, ulong len) {
		sha3_context *ctx=(sha3_context *)priv;
				// cast to context from voidptr
		unsigned tail, old_tail=(8-ctx->byte_idx)&7; // reminder for word 0...7 
		size_t words, i;
		const uint8_t *buf=buf_inp;
		__sha3_trace_buf("called to update with:", buf, len);
		__sha3_assert(ctx->byte_idx<8);
		__sha3_assert(ctx->word_idx<sizeof(ctx-> u.s)/sizeof(ctx->u.s[0]));
		if(len<old_tail) {        
			// have no complete word or haven't started the word yet 
			__sha3_trace("because %d<%d, store it and return", (unsigned)len, (unsigned)old_tail);
			// endian-independent
			while (len--)
				ctx->saved|=(uint64_t)(*(buf++))<<((ctx->byte_idx++)*8);
			__sha3_assert(ctx->byte_idx<8);
			return;
		};
		if(old_tail) {
			// process a single word
			__sha3_trace("completing one word with %d bytes", (uns)old_tail);
			// endian-independent
			len-=old_tail;
			while(old_tail--)
				ctx->saved|=(uint64_t)(*(buf++))<<((ctx->byte_idx++)*8);
			/* now ready to add saved to the sponge */
			ctx->u.s[ctx->word_idx]^=ctx->saved;
			__sha3_assert(ctx->byte_idx==8);
			ctx->byte_idx=0;
			ctx->saved=0;
			if(++ctx->word_idx==(__sha3_k_sponge_w-__sha3_cw(ctx->cap_words))) {
				keccakf(ctx->u.s);
				ctx->word_idx = 0;
			};
		};
		/* now work in full words directly from input */
		__sha3_assert(ctx->byte_idx==0);
		words=len/__size_u64;
		tail=len-words*__size_u64;
		__sha3_trace("have %d full words to process", (uns)words );
		for(i=0; i<words; i++, buf+=__size_u64) {
			const uint64_t t = (uint64_t) (buf[0]) |
					((uint64_t) (buf[1]) << 8 * 1) |
					((uint64_t) (buf[2]) << 8 * 2) |
					((uint64_t) (buf[3]) << 8 * 3) |
					((uint64_t) (buf[4]) << 8 * 4) |
					((uint64_t) (buf[5]) << 8 * 5) |
					((uint64_t) (buf[6]) << 8 * 6) |
					((uint64_t) (buf[7]) << 8 * 7);
	#if defined(__x86_64__) || defined(__i386__)
			__sha3_assert(memcmp(&t,buf,8)==0);
	#endif
			ctx->u.s[ctx->word_idx]^=t;
			if(++ctx->word_idx==(__sha3_k_sponge_w-__sha3_cw(ctx->cap_words))){
				keccakf(ctx->u.s);
				ctx->word_idx=0;
			};
		};
		__sha3_trace("have %d bytes left to process, save them", (unsigned)tail );
		/* finally, save the partial word */
		__sha3_assert(ctx->byte_idx==0&&tail<8);
		while (tail--) {
			__sha3_trace("Store byte %02x '%c'", *buf, *buf);
			ctx->saved|=(uint64_t)(*(buf++))<<((ctx->byte_idx++)*8);
		}
		__sha3_assert(ctx->byte_idx<8);
		__sha3_trace( "Have saved=0x%016" PRIx64 " at the end", ctx->saved );
	};
	/**
	simply the `update()` with the padding.
	 * The padding block is 0x01 || 0x00* || 0x80. First 0x01 and last 0x80 
	 * bytes are always present, but they can be the same byte.
	**/
	void const *sha3_finalize(void *priv) {
		sha3_context *ctx=(sha3_context*)priv;
		__sha3_trace("called with %d bytes in the buffer", ctx->byte_idx);
		/* Append 2-bit suffix 01, per SHA-3 spec. Instead of 1 for padding we
		 * use 1<<2 below. The 0x02 below corresponds to the suffix 01.
		 * Overall, we feed 0, then 1, and finally 1 to start padding. Without
		 * M || 01, we would simply use 1 to start padding. */
		uint64_t t;
		if( ctx->cap_words & __sha3_k_use_flag ) {
			/* Keccak version */
			t = (uint64_t)(((uint64_t)1)<<(ctx->byte_idx*8));
		}
		else {
			/* SHA3 version */
			t = (uint64_t)(((uint64_t)(0x02|(1<<2)))<<((ctx->byte_idx)*8));
		};
		ctx->u.s[ctx->word_idx]^=ctx->saved^t;
		ctx->u.s[__sha3_k_sponge_w-__sha3_cw(ctx->cap_words)-1]^=__sha3_const(0x8000000000000000UL);
		keccakf(ctx->u.s);
		/* Return first bytes of the ctx->s. This conversion is not needed for
		 * little-endian platforms e.g. wrap with #if !defined(__BYTE_ORDER__)
		 * || !defined(__ORDER_LITTLE_ENDIAN__) || __BYTE_ORDER__!=__ORDER_LITTLE_ENDIAN__ 
		 *    ... the conversion below ...
		 * #endif */
		{
			unsigned __i;
			for(__i=0; __i<__sha3_k_sponge_w; __i++) {
				const unsigned t1 = (uint32_t) ctx->u.s[__i];
				const unsigned t2 = (uint32_t) ((ctx->u.s[__i]>>16)>>16);
				ctx->u.sb[__i*8+0]=(uint8_t)(t1); 
				ctx->u.sb[__i*8+1]=(uint8_t)(t1>>8);
				ctx->u.sb[__i*8+2]=(uint8_t)(t1>>16);
				ctx->u.sb[__i*8+3]=(uint8_t)(t1>>24);
				ctx->u.sb[__i*8+4]=(uint8_t)(t2); 
				ctx->u.sb[__i*8+5]=(uint8_t)(t2>>8);
				ctx->u.sb[__i*8+6]=(uint8_t)(t2>>16);
				ctx->u.sb[__i*8+7]=(uint8_t)(t2>>24);
			}
		}
		__sha3_trace_buf("hash: (first 32 bytes)", ctx->u.sb, 256/8);
		return (ctx->u.sb);
	};
	/**
	atomic hashing 
	 *
	**/
	sha3_r sha3_hash_buffer( ulong bit_size, sha3_f flags, const void *in, ulong in_bytes, void *out, ulong out_bytes ) {
		
		sha3_r err;
		sha3_context c;

		err = sha3_init( &c , bit_size );
		
		if( err != __sha3_u_ok ) {
			return err;
		}
		
		if( sha3_set_flags(&c, flags) != flags ) {
			return __sha3_u_n;
		}
		
		sha3_update( &c , in , in_bytes );
		const void *h = sha3_finalize( &c );

		if( out_bytes > bit_size/8 ){
			out_bytes = bit_size/8;
		}
		memcpy( out , h , out_bytes );

		return __sha3_u_ok;
	}
	/**
	 * hbar family
	 * hash,fhash       @returns uchar const *
	 * hashof,fhashof   @returns char const *
	 * hasht,fhasht     @returns typeof(numbytes) : 4=ulong , 8=ulong , etc..
	 * 
	 * zero_address          @returns zero address
	**/ 
	char const *zero_address(ulong level){
		switch(level){
		case 0: return "0x00000000";
		case 1: return "0x0000000000000000";
		case 2: return "0x00000000000000000000000000000000";
		case 3: return "0x0000000000000000000000000000000000000000000000000000000000000000";
		default: return "0";
		}
	};
	/**
	hashof str based on level
	 * extreme care for the values must be taken when using this function
	 * specially `thsize` {a.k.a to_hash_size} 
	 *  ONLY send size values that are `sizeof(tohash)<=` otherwise the hash
	 * will be random and there will be no way to retrieve it or guarantee 
	 * any kind of consistency.
	 * 
	 * this is by design, as we can generate randomness from this. 
	 ***AFNAB**
	**/ 
	char const *hashof(ulong level, void const *tohash, ulong thsize) {
		ulong hash_size=0,k_flag=0,hashstr_len=4;
		switch (level) {
			case 0:
				hash_size=256;
				break;
			case 1:
				hash_size=384;
				hashstr_len=8;
				break;
			case 2:
				hash_size=512;
				hashstr_len=16;
				break;
			case 3:
				k_flag=1;
				hash_size=256;
				hashstr_len=32;
				break;
			default:
				return NULL;        
		};
		char hsize_str[hash_size];
		memset(&hsize_str, 0, sizeof(hsize_str));
		sha3_init(&__sha3, hash_size);
		sha3_set_flags(&__sha3, k_flag);
		sha3_update(&__sha3, tohash, thsize);
		uint8_t *__hptr = (uchar *)sha3_finalize(&__sha3);
		__sha3_str(hsize_str, __hptr, hashstr_len);
		return strdup(hsize_str);
	};

	void *__generate_lock(char const *__hash, ulong __hlen) {
		if(__hlen<8||__hlen%8!=0||__hlen%4!=0) {
			printf("not safe, not recomended, will not do it\n");
			return NULL;
		};
		ulong __atplsize=(__hlen>>3);
		char atp_lock[__atplsize];
		memset(&atp_lock, 0, __atplsize);

		ulong __lsize=(__hlen<<2);
		char __lock[__lsize];
		memset(&__lock, 0, __lsize);

		char const *__hh=hashof(2, __hash, __hlen);
		#ifdef DEBUG
			printf("generating lock ....\n");
			printf("lock(%s) : %lu :: %lu ::: %s\n",__hash,__atplsize, __lsize, __hh);
		#endif

		memmove(&__lock, __hh, __lsize);

		return malloc(8);
	};
	// raw 
	uchar const *hash( ulong level , void const *tohash , ulong thsize ) {
		#ifdef DEBUG
			char const *_strhash=(char const *)tohash;
			printf("hash : string to hash :: %s\n",_strhash);
		#endif
			ulong hash_size = 0 , k_flag = 0 , hashstr_len = 4;
			switch ( level ) {
				case 0:
					hash_size = 256;
					break;
				case 1:
					hash_size = 384;
					hashstr_len = 8;
					break;
				case 2:
					hash_size = 512;
					hashstr_len = 16;
					break;
				case 3:
					k_flag = 1;
					hash_size = 256;
					hashstr_len = 32;
					break;
				default:
					return NULL;        
			}
			char __hsized[hash_size];
			memset(&__hsized, 0, hash_size);
			uchar *__hptr;
			sha3_init( &__sha3 , hash_size );
			sha3_set_flags( &__sha3 , k_flag );
			sha3_update( &__sha3 , tohash , thsize );
			return ( uchar * ) sha3_finalize( &__sha3 );
	}
	/**
	hashof-8
	 * 
	**/
	ulong hash8(ulong __vl, void const *__v, ulong __vsize) {
		uchar const *__ = hash((ulong)__vl,__v,__vsize);
		ulong c=0,res=0;
		for(;c<8;c+=1){
			res|=(ulong)__[c]<<(c*8);
		};
		return res;
	};
	/**
	hash24=3x(hashof-8)
	 *
	**/
	ullong hash24(ulong __vl, void const *__v, ulong __vsize){
		uchar const *__ = hash(__vl,__v,__vsize);
		ullong res=0;
		ulong __c0=0,__c1=0;
		for(;__c0<2;__c0+=1) {
			res=0;
			for(;__c1<8;__c1+=1) {
				res|=(ullong)__[__c0]<<(__c1*8);
			};
			u[__c0]=res;
		};
		return res;
	};
	/**
	file hash
	 *
	**/
	char const *fhashof( ulong level , char const *filepath ) {
			struct stat __st;
			int __fd = open( filepath , O_RDONLY );

			#ifdef DEBUG
				printf( "attempting to open file :: %s :" , filepath );
				printf( "fd: %d\n" , __fd );
			#endif

			if ( fstat( __fd , &__st ) == -1 ) {
				printf( "cannot obtain file info\n" );
				return NULL;
			}
			ulong __size=__st.st_size;
			char fl_hash[__size];
			memset(&fl_hash,0,__size);
			ulong b_read=read(__fd,fl_hash,__size);
			close(__fd);

			#ifdef DEBUG
				printf( "file size :: %lu\n" , __size );
				printf( "bytes read :: %lu\n" , b_read );    
			#endif

			return hashof(level,fl_hash,b_read);
	};

	char const *fdhashof(ulong level, ulong fd, ulong filesize) {
			char fd_hash[filesize];
			memset(&fd_hash,0,filesize);
			int b_read=read(fd,fd_hash,filesize);
			if(b_read==-1) {
				#ifdef LOG_ERR
					printf("err : read :: %d", errno);
				#endif
				return NULL;
			}
			else if ((ulong)b_read==filesize) {
				return hashof(level, fd_hash, b_read);
			}
			else if (b_read==0) {
				#ifdef LOG_ERR
					printf("file has no contents to hash\n");
				#endif
				return zero_address(level);
			}
			else {
				ulong temp=0;
				if(b_read<filesize) {
					temp+=(ulong)b_read;
					while(temp<filesize) {
						b_read=pread(fd, (fd_hash+b_read), filesize-temp, temp);
						if(b_read==-1){
							#ifdef LOG_ERR
								printf("cannot read the full file\n");
							#endif
							break;
						};
					};
					#ifdef DEBUG
						printf( "file size :: %lu\n" , filesize );
						printf( "bytes read :: %d\n" , b_read );    
					#endif
			}
				return hashof(level, fd_hash, temp);
			};
	}
	/**
	file-hash raw
	 *
	**/
	uchar const *fhash(ulong level,char const*filepath) {
		struct stat __st;
		int __fd = open( filepath , O_RDONLY );

		#ifdef DEBUG
			printf( "attempting to open file :: %s :" , filepath );
			printf( "fd: %d\n" , __fd );
		#endif

		if ( fstat( __fd , &__st ) == -1 ) {
			#ifdef DEBUG
				printf( "cannot obtain file info\n" );
			#endif
			return NULL;
		}

		ulong __size=__st.st_size;
		char fl_hash[__size];
		memset(&fl_hash,0,__size);
		ulong b_read=read(__fd,fl_hash,__size);

		#ifdef DEBUG
			printf( "file size :: %lu\n" , __size );
			printf( "bytes read :: %lu\n" , b_read );    
		#endif

		return hash(level,fl_hash,b_read);
	}   
	/**
	file-hash4
	 * 
	**/
	ulong fhash4(ulong level,char const *filepath) {
		uchar const *__ = fhash(level,filepath);
		if(__==NULL){return 0;}
		ulong res=0;
		for(int i=0;i<4;i++){
			res|=(ulong)__[i]<<(i*8);
		}
		return res;
	}
	/**
	file-hash8
	 * 
	**/
	ulong fhash8(ulong level,char const*filepath) {
		uchar const *__ = fhash(level,filepath);
		if(__==NULL){return 0;}
		ulong res=0;
		for(int i=0;i<8;i++){
			res|=(ulong)__[i]<<(i*8);
		};
		return res;
	};
	/**
	file-hash16
	 *
	 * 
	 * 
	**/
	ulong fhash16(ulong level, char const*filepath){
		uchar const *__=fhash(level,filepath);
		if(__==NULL){return 0;}
		ulong res=0;
		for(int i=0;i<16;i++){
			res|=(ulong)__[i]<<(i*8);
		};
		return res;
	};

	char const *arch_namehash(char const *__name) {

		return hashof(1, __name, str_rwings(__name));
	};

	ulong env_hash(char **__var){
		ulong __count=0;
		while(!(NNE(__var[__count]))){
			#ifdef DEBUG
				printf("%s\n",__var[__count]);
			#endif
			__count+=1;
		}
		env_hash_0=(ulong)hash8(0,&__count,sizeof(ulong));
		return (ulong)__count;
	};

	char const *envarr_hash(uchar *__udef_pnop){
		char const **env_var=(char const **)environ;
		char *udef_pnop=(char*)__udef_pnop;
		ulong vcount=0,__c=0, envar_count=content_count(env_var), evar_count=envar_count+1;
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
	};

	char const *varll_hash(void const **__vars, ulong __vcount){
		// variable-linked-list hash
		ulong c=0, hashes[__vcount], h_vsize=ulong_wsize(__vcount);
		void *__hptr=memset(&hashes,0,h_vsize);
		if(!__vcount) {
			#ifdef DEBUG
				printf("vcount cannot be 0\n");
			#endif
			return zero_address(2);
		}
		else {
			while((__vars[c])&&(c<__vcount)){
				hashes[c]=hash8(1,__vars[c],str_rwings(__vars[c]));
				c+=1;
			};
			char const *__hash=hashof(2,__hptr,h_vsize);
			return __hash;
		};
	};

	char const *arch_hash(void const *__){

		return hashof(3,__,__rwings(__));
	};

	char const *arch_checksum(char const **__content) {
		ulong llcount=content_count(__content);

		return varll_hash(vcontent(__content), llcount);
	};

	char const *arch_cenv(){
		char const **__var=(char const **)environ;
		ulong var_count=content_count(__var);
		return varll_hash(vcontent(__var), var_count);
	};

	ulong arch_address(char const *__fpath, ulong __fld){
		// returns the 8b hash if not fld is not zero
		if(__fld!=0) {
			if(stres(__fpath)) {
				return fhash8(2, __fpath);
			}
			else {
				return hash8(1, __fpath, str_rwings(__fpath));
			};
		}else {
			return (ulong)0;
		};
	};

#endif
