#ifndef Karch512
	#ifndef ARK
		#define ARK __ARK__
	#else
		#include "standard.h" 
		#include "utypes.h"
		/************************ Defintions ************************/

		#ifndef __H512__D
			#define LONG_MAX_COMPUTED_N_DIGITS 21 //logb(x) = loga(x) / loga(b)
			#define __MA__S 0x000000000000000000000008
			#define __GS__S __MA__S<<3
			#define __LO__F __GS__S<<3
			#define __UN__F __LO__S<<3
			#define __dPER while(1!=1);
			#define shard_flags (O_RDWR|O_APPEND|O_CREAT|O_EXCL|O_NOFOLLOW)
			#define shard_share (S_IRWXU|S_IWGRP|S_IXGRP|S_IWOTH|S_IXOTH)
			#define shard_nolock (O_RDWR)
			#define shard_lock_reader (O_RDONLY)
			#define shard_lock_writer (O_WRONLY)
			#define __vile ((void const *)(__FILE__))
			#define __caller_namelen (ulong)str_rwings(__FILE__)
			#define ARR_DELIM ",\0"
			#ifndef __USIZES
			    #define _LONG_MID 0x7fffffffu
			    #define _LONG_MAX 0xffffffffu
			    #define _LLONG_MID 0x7fffffffffffffffu
			    #define _LLONG_MAX 0xffffffffffffffffu
				#define __USIZES 1
			#endif

			#ifndef __FL_BYTES
		        #define F_BYTE(__) __&0x0f
		        #define L_BYTE(__) __&0xf0
				#define __FL_BYTES 1
		    #endif

		    #ifndef __CHAR_VARS
		        #define __CHAR_ZERO '0'
		        #define __CHAR_NULL '\0'
		        #define __CHAR_ALPH_A 'a'
				#define __CHAR_VARS 1
		    #endif

			#ifndef k512
				#define k512(x) _Generic((x),\
				uchar: uchar*,\
				schar: schar*,\
				slong: slong*,\
				ulong: ulong*,\
				ullong: ullong*,\
				sllong: sllong*,\
				default: NULL)

				#define __k512(x ...)  _Generic((x),\
				uchar: 0x01,\
				ulong: 0x02,\
				ullong: 0x03,\
				schar: 0x10,\
				slong: 0x12,\
				sllong: 0x13,\
				char const *: 0xa0,\
				char const **: 0xa1,\
				void const *: 0xb0,\
				void const **: 0xb1,\
				default: 0xff)
					
			#endif

			//FMT_ASCII_SPEC
			#define __C_FMT_SPEC(x) _Generic((x), \
				char: "%c",\
				unsigned char: "%d",\
				int: "%d",\
				unsigned int:"%u",\
				long: "%ld",\
				unsigned long: "%lu",\
				char *: "%s",\
				char [4]: "%s",\
				unsigned char *: "%s",\
				long long: "%lld",\
				unsigned long long: "%llu",\
				default: "%x")

			//FMT_HEXA_SPEC
		    #define __ENK_FMT_SPEC(__) \
		        _Generic((__), \
		            char: "c",\
		            unsigned char: "C",\
		            short: "h",\
		            int: "h",\
		            uns: "H",\
		            long: "l",\
		            ulong: "L",\
		            long long: "q",\
		            ullong: "Q",\
		            char *: "s",\
		            default: "_")

			#define _C_TYPES(x) \
			    _Generic((x), \
			        signed char: "char", \
			        unsigned char:"uchar", \
			        int:"int", \
			        unsigned int:"uns", \
			        long int:"ulong", \
			        unsigned long int:"ulong", \
			        long long int:"ullong", \
			        unsigned long long int:"ullong", \
			        char *:"string",\
			        void *:"pointer",\
			        default:"NULL")

		    #define NOFB_TYPE(x) \
		        _Generic((x), \
		            signed char: (char)x, \
		            unsigned char:(uchar)x, \
		            int:(int)x, \
		            unsigned int:(uns)x, \
		            long int:(ulong)x, \
		            unsigned long int:(ulong)x, \
		            long long int:(ullong)x, \
		            unsigned long long int:(ullong)x, \
		            default:NULL)
		    
		    #define LBB_OUT_FMT(__) \
		        _Generic((__), \
		            void * : void *,\
		            char * : char *,\
		            const char *: const char *,\
		            default: ulong*)

		    #define IXR_FMT(__) _Generic((__), \
				char 		: "c",\
				char*		: "s",\
				char const*	: "s",\
				int*		: "h",\
				uns*		: "H",\
				long*		: "l",\
				ulong*		: "L",\
				ullong*		: "Q",\
				default 	: "_")

		    #define IXR_ARG(__) _Generic((__), \
				char*					: (char*)x,\
				char const *			: (char const *)x,\
				unsigned char*			: (uchar*)x,\
				int*					: (int*)x,\
				unsigned int*			: (uns*)x,\
				long int*				: (ulong*)x,\
				unsigned long int*		: (ulong*)x,\
				long long int*			: (ullong*)x, \
				unsigned long long int*	: (ullong*)x, \
				default					: NULL)

			#define __lbb_call_generic(__) \
				_Generic((__),\
					atp_pointer:"lbb command",\
					atp_charm: "lbb interpreter",\
					atp_pyfld: "lbb payload field",\
					atp_h: "lbb data",\
				default:"lbb call")

			#define __lbb_resp_generic(__) \
				_Generic((__),\
					atp_pointer*:"command response",\
					atp_charm*: "interpreter reply",\
					atp_pyfld*: "payload retrieve",\
					atp_h*: "field return",\
				default:"unknown args")

			#define __lbb_generic(__) \
				_Generic((__),\
					char[8]:(atp_pointer *) &__,\
					char[64]:(atp_charm *) &__,\
					char[512]:(atp_pyfld *) &__,\
					char[4096]:(atp_h *) &__,\
					default:"unknown")

			#define __lbb_typd(__) \
				_Generic((__),\
					atp_pointer * : char[8],\
					atp_charm * : char[64],\
					atp_pyfld * : char[512],\
					atp_h * : char[4096],\
					default:"unknown")

			#define fmt_out(x) log_str(0,_Generic((x), \
				d_num:(char const *)(x.__),\
				d_str:(char const *)(x.__),\
				d_arr:(char const *)(x.__),\
				d_prg:(char const *)(x.__),\
				default:__NADA__\
			));

			/**
			 * while out formatting, display any of the 
			 * structure elements by defining them here.
			**/
			#define out_fmt(x) _Generic((x), \
				d_num:x.__,\
				d_str:x.__,\
				d_sha3:(char const *)x.__,\
				d_arr:(char const *)x.__,\
				d_prg:(char const *)x.__,\
				default:"@dPRG");

			#define __entry_sep "\n"
			#define __line_endings log_str(0, __entry_sep);
			#define __page_endings log_str(0, __entry_sep);
			#define __arr_sep ", "
			#define __key_sep " : "
			#define keyis(x,y) {log_str(0,x); log_str(0,__key_sep); out_fmt(y); __line_endings; }
			#define str_keyis(x,y) { log_str(0,#x); log_str(0,__key_sep); log_str(0,y.__); __line_endings; }
			#define arr_keyis(x,y) { log_str(0,#x); log_str(0,__key_sep); log_str(0,y.__); log_str(0,__arr_sep); __line_endings; }

			/** 
			 * The keyword is `is` here so a 
			 * key => keyis
			 * word => wordis
			 * page => pageis
			 * ... => ...is
			**/
			#define out_kv(x,y) arr_keyis(x,y)
			#define out(x) str_keyis(#x,x);

			#define OUT(x) _Generic((x), \
				laddr: 2,\
				d_arr: 2,\
				default: 1)


		    #define OUT_ENK_H(fd,x) do { \
		        char _[ATP_SPEC_SIZE];uchar __[ATP_BUFFER_SIZE];\
		        memset(&_,0,sizeof _);memset(&__,0,sizeof __);\
		        snprintf(_,sizeof _,"%s",__ENK_FMT_SPEC(x));\
		        ulong pack_sz=pack(__,_,x);\
		        if(pack_sz>0){write(fd,__,pack_sz);}\
		    } __dPER

		    #define OUT_ENK_A(fd,x) do { \
		        char __[4096];\
		        memset(&__,0,sizeof __);\
		        snprintf(__,sizeof __,"%s\n", __C_FMT_SPEC(x));\
		        dprintf(fd,__,(x));\
		    } __dPER

			#define TEXT_ARG(k,...)  OUT_ENK_A(0, #__VA_ARGS__)

		    #define dout(fn, x) {\
		    ulong temp=str_rwings(#x);\
		    write(!__exact_match(fn, "host")\
		    	?!__exact_match(fn, "local")\
		    	?!__exact_match(fn, "domain")\
		    	?!__exact_match(fn, "network")?4:3:2:0:1,#x,temp);\
			}

			#define __ark_next(x) (x->__next)

		    #define __ARK_FMT(x) _Generic((x), \
		    	char *: (char const *)x,\
				char const *: x,\
				ixr_h*: __ark_next(x),\
				d_point*: __ark_next(x),\
			    default: "#NE")

		    #define _log(x, ...) { \
		    	void const *__=__ARK_FMT(__VA_ARGS__);\
		    	write(x, __, str_rwings(__));\
		    };



			#define _ENK_A(x,y) x##y
			#define __ENK(x,y) __STRING(x##y)
			#define __ERR(x) OUT_ENK_A(0,__ENK(Err, x));
			#define __TEXT(n,x) OUT_ENK_A(n,#x);
			// #define TEXT(x) OUT_ENK_A(0,#x);
			#define __ASCII(n,x) OUT_ENK_A(n,x);
			// #define ASCII(x) OUT_ENK_A(0,x)
			#define __ARK(...) #__VA_ARGS__
			#define __HASH(x) write(0, hashof(3, x, str_rwings(x)), 32);
			/**
			** NNE : x :: true if x is not 0x0000
			**/
			#define NNE(v) v==0x0000?0x01:0x00
			// call result sucessful 
			#define CALL_SUCC(x) x==(ulong)0?1:0
			// call result instantiate
			#define CALL_INST(x) x==(ulong)1?1:0
			// call result not sucessful
			#define CALL_NSUC(x) x==(ulong)-1?1:0
			// call result jump
			#define CALL_NEXT(x) ((ulong)(x<(ulong)-1?x>1?1:x:0))
			#define arr_size(x) ((ulong)(sizeof(x)/sizeof(x[0])))
			#define elem_hash(x) hash8(0,x,strlen(x))
			#define wsize(x,y) (sizeof(x)*y)
			#define wulong(x) (ulong *) ulong x[x];
			#define ulong_wsize(x) wsize(ulong, x)
			#define str_wsize(x) wsize(char, x)
			#define ustr_wsize(x) wsize(uchar, x)
			#define vcontent(x) ((void const **)x)
			#define __typed_lbbfile_name(x) arch_tfile_lbb(x)
			#define typed_lbbfilename(x) __STRING(arch_tfile_lbb(x))
			#define s_lbbfile(x1,x2) x1##x2
			#define _C_ZERO(x) x-'0'

			#define LBB_READER(x)		x^0010000
			#define LBB_DIRECTORY(x)	x^0040000
			#define LBB_FIELD(x)		x^0100000
			#define LBB_SOCKET(x)		x^0140000
			#define ARCH_MADE(x)		x^0000700
			#define ARCH_SAVE(x)		x^0000007

			#define ARC_GENERIC(x) (ulong)((1<<(x*3)))
			#define __tempok "some args"
			#define arg_content(...) ((const char *[]){#__VA_ARGS__,ne})
			#define __NE ",\0"
			#define __argc(...) ((char * const *)#__VA_ARGS__)

			/**
		     * Thanks for the all the contributions and good work from 
		     * the keccak team http://keccak.noekeon.org/
		     * and brainhub team crypto@brainhub.org 
		     * for their combined efforts on the implementation of the `sha-3` hash.
		     *
		    **/
		    #ifndef __keccak_constants
		        #define byte_to_hex __hex_bytes
		        #define hash_to_strl __sha3_str 
		        #define hash_to_string __htostr
		        #define hbar_str __s_hash
		        #define __size_sha3_context ((ulong)sizeof(sha3_context))
		        #define __sha3_k_use_flag 0x80000000 // flag for PURE keccak
		        #define __sha3_cw(x) ((x)&(~__sha3_k_use_flag))
		        #define __sha3_assert(rcond)
		        #define __sha3_trace(fmt,...)
		        #define __sha3_trace_buf(format,buf,l)
		        #define sha3_init256(p) sha3_init(p,256)
		        #define sha3_init384(p) sha3_init(p,384)
		        #define sha3_init512(p) sha3_init(p,512)
		        #if defined(_MSC_VER)
		            #define __sha3_const(x) x
		        #else
		            #define __sha3_const(x) x##L
		        #endif
		    #endif

		    #undef get16bits
		        #if (defined(__GNUC__) && defined(__i386__)) || defined(__WATCOMC__) \
		        || defined(_MSC_VER) || defined (__BORLANDC__) || defined (__TURBOC__)
		            #define get16bits(d) (*((const ulong *)(d)))
		    #endif

		    #if !defined (get16bits)
		        #define get16bits(d) ((((ulong) (((const uchar *)(d))[1]))<<8)+(ulong) (((const uchar *) (d))[0]))
		    #endif

			#define __H512__D 1
		#endif

		/************************ Constants ************************/

		#ifndef __H512__C
			/********* types *********/
			static __ul u;
			static ell_st __ell;
			static aip_sock __sok;
			static arc_st __arc;
			/********** books *********/
			static ulong ___lbb_offset=0;
			static c_shard ___shard;
			static c_shard *l_shard=&___shard;
			static m_stat *lbb_mstat=&(___shard.c_stat);
			static lbb_h ___book;
			static d_into ixr_view;
			static const d_mod required_mods[2] = {{.__name="constants"},{.__name="tests"}};
			/********* unistd *********/
			extern char **environ;
			/********* http *********/
			static atp_h ___buffer;
			static uchar *dbuf = (uchar *)&___buffer.data;
			static char *__http_get="GET";
			static char *__http_post="POST";
			static char *wss_key_h="Sec-WebSocket-Key: ";
			static char *wss_acc_h="Sec-WebSocket-Accept: ";		
			static char *__reph="HTTP/1.1 200 OK\r\nContent-Type: text;\r\nContent-Length: 10\r\n\r\nHello Raed\r\n";
			static char *__upgrade="HTTP/1.1 101 Switching Protocols\r\nUpgrade: websocket\r\nConnection: Upgrade\r\nCache-Control: no-cache\r\nSec-WebSocket-Protocol: @-Protocol\r\n";
			static char *__cwss="258EAFA5-E914-47DA-95CA-C5AB0DC85B11\0";
			static const char *__http_protocol_version="HTTP/1.1";
			static const char *__http_base="P S R\r\n";
			static const char *__http_request_base="M P V\r\n";
			static const char *__http_response_base="B S R\r\n";
			/********* formats *********/
			static const char *__header_fmt="_Q_Q_Q_\n";
			static const char *__value_fmt="_Q:s:s_\n";
			static const char *__file_fmt="_Q:s:s#Q_\n";
			static const char *__dprg_fmt="_Q:s>s<s$s_\n";
			static const char *__fld_fmt="_Q:s@s=s+h_\n";
			/********* constants *********/
			static ulong __uptr[64];
			static int __dlvl=0;
			static ulong __cindex=0;
			static const ulong __ne__ =(ulong)00000000U;
			static const char ne__='\0';
			static void *__ne=(void *)'\0';
			static const void *ne=(char const *)(void *)'\0';
			static const void **NE=(void const **)&ne;
			static ulong __ixr_fd=0x228;
			static ulong ___offset=0;
			static ixr_h ___header;
			static ulong env_hash_0;
		  	static const uint64_t __keccakf_rndc[24] = {
		            __sha3_const( 0x0000000000000001UL ), __sha3_const( 0x0000000000008082UL ),
		            __sha3_const( 0x800000000000808aUL ), __sha3_const( 0x8000000080008000UL ),
		            __sha3_const( 0x000000000000808bUL ), __sha3_const( 0x0000000080000001UL ),
		            __sha3_const( 0x8000000080008081UL ), __sha3_const( 0x8000000000008009UL ),
		            __sha3_const( 0x000000000000008aUL ), __sha3_const( 0x0000000000000088UL ),
		            __sha3_const( 0x0000000080008009UL ), __sha3_const( 0x000000008000000aUL ),
		            __sha3_const( 0x000000008000808bUL ), __sha3_const( 0x800000000000008bUL ),
		            __sha3_const( 0x8000000000008089UL ), __sha3_const( 0x8000000000008003UL ),
		            __sha3_const( 0x8000000000008002UL ), __sha3_const( 0x8000000000000080UL ),
		            __sha3_const( 0x000000000000800aUL ), __sha3_const( 0x800000008000000aUL ),
		            __sha3_const( 0x8000000080008081UL ), __sha3_const( 0x8000000000008080UL ),
		            __sha3_const( 0x0000000080000001UL ), __sha3_const( 0x8000000080008008UL )
		        };
		    static const unsigned __keccakf_rotc[24] = {
		            1, 3, 6, 10, 15, 21, 28, 36, 45, 55, 2, 14, 27, 41, 56, 8, 25, 43, 62,
		            18, 39, 61, 20, 44
		        };
		    static const unsigned __keccakf_piln[24] = {
		            10, 7, 11, 17, 18, 3, 5, 16, 8, 21, 24, 4, 15, 23, 19, 13, 12, 2, 20,
		            14, 22, 9, 6, 1
		        };
			#define __H512__C 1
		#endif

		/************************ Naming ************************/
		#ifndef __H512__N
		    #ifndef _D_HASH_H
				#define _D_HASH_H 1
				// sha3
				void *_sockaddr(struct sockaddr *socket_address);
			    void htostr(char *__str, uchar *hash);
			    char *sha3_hash(char *__);
			    char *__s_hash(char *__key, char *__hashkey);
			    ulong blaz_hash(char const *__data);
			    static void keccakf(uint64_t s[25]);
			    // sha3_r __sha3_init(void *p,unsigned bit_size);
			    // sha3_f __sha3_set_flags(void *p,sha3_f flags);
			    void sha3_update(void *p,void const *buf_in,ulong len);
			    void const *sha3_finalize(void *ctx_p);
			    sha3_r sha3_hash_buffer(ulong bit_size,sha3_f cfg,const void *in,ulong in_bytes,void *out,ulong out_bytes);
			    const char *zero_address(ulong level);
			    void *__generate_lock(char const *__hash, ulong __hlen);
			    char const *hashof (ulong level, void const*to_hash, ulong the_hash_size);
			    uchar const *hash (ulong level, void const *to_hash, ulong the_hash_size);
			    ulong hash8 (ulong level, void const *to_hash, ulong the_hash_size);
			    ullong  hash24 (ulong level, void const *to_hash, ulong the_hash_size);
			    char const *fhashof(ulong level, char const *to_hash);
			    char const *fdhashof(ulong level, ulong fd, ulong filesize);
			    uchar const *fhash(ulong level, char const *to_hash);
			    ulong fhash4 (ulong level, char const *to_hash);
			    ulong fhash8 (ulong level, char const *to_hash);
			    ulong fhash16 (ulong level, char const *to_hash);
			    char const *arch_namehash(char const *__name);
			    ulong env_hash(char **__var);
			    char const *varll_hash(void const **__vars, ulong __vcount);
			    char const *arch_hash(void const *__);
			    ulong arch_address(char const *__fpath, ulong __fld);
			    char const *arch_checksum(char const **__content);
			    char const *arch_cenv();
		    #endif
			#ifndef _D_KODER_H
			    #define _D_KODER_H 1
			    // enkoding
			    void enc_u(uchar *__buffer, uchar __);
			    void enc_s(uchar *__buffer, schar __);
			    void enc_u8(uchar *__buffer, ulong __);
			    void enc_u64(uchar *__buffer, ullong __);
			    void enc_u512(uchar *__buffer, ullong __[3]);
			    void enc_unum(ulong __base, uchar *__buffer, ulong __num);
			    void enc_punum(ulong __base, ulong __roof, uchar *__buffer, ulong *__nums);
			    void enc_i(uchar *__buffer, char __);
			    char dnc_i(uchar *__buffer);
			    schar dnc_s(uchar *__buffer);
			    uchar dnc_u(uchar *__buffer);
			    slong dnc_i8(uchar *__buffer);
			    ulong dnc_u8(uchar *__buffer);
			    sllong dnc_i64(uchar *__buffer);
			    ullong dnc_u64(uchar *__buffer);
			    sllong* dnc_i512(uchar *__buffer);
			    ullong* dnc_u512(uchar *__buffer);
			    ulong pack(uchar *__buffer, char const *__format , ...);
			    void unpack(uchar *__buffer, char const *__format , ... );
			#endif
			#ifndef _D_FILE_H
				#define _D_FILE_H 1
				// file
				uchar const *__dbook(char const *__cpath, ulong __size);
				uchar const *__readb(ulong __fsize, ulong __fd, ulong __ro);
		    	void *__statusof(char const *__path);
				int __stres(char const *__path);
				ulong __writeb(uchar *content,ulong c_size, ulong __fd);
				ulong __fsize(char const *__path);
				ulong __iosize(char const *__path);
				ulong __inodenum(char const *__path);
				ulong __dmode(char const *__path);
				ulong __file_r(char const *__path);
				ulong __file_w(char const *__path);
				ulong __file_x(char const *__path);
				int __dgetfd(char const *__path);
			#endif
			#ifndef _D_STRING_H
				#define _D_STRING_H 1
				// strings
				int __nullchar(char c);
				int __numchar(char c);
				int __smchar(char c);
				int __capchar(char c);
				int __atchar(char c);
				int __sepchar(char c);
				int __delimchar(char c);
				ulong __rwings(void const *__);
				ulong str_rwings(char const *__str);
				int spaces_and_tabs(char *__str);
				int tabs_and_spaces(char const *__str);
				ulong __tonum(char const *__path);
				ulong tonum(int i);
				char const *num2char(ulong num_in);
				char const *s_num2char(long snum_in);
				char *__stn(char const *__str, ulong __len);
				void *__arg__(char const *file_args);
				int __exact_match(char const *__str_a, char const *__str_b);
				int __sep_atoff(char const *__str, char const *__sep);
				char *str_b4eoffset(char const *__str, ulong __offset);
				char *str_b4offset(char const *__str, ulong __offset);
				char *stn_b4offset(char const *__str, ulong __offset);
				char *str_a4woffset(char const *__str, ulong __offset);
				char const *str_a4offset(char const *__str, ulong __offset);
				char const *expand_atoffset(char const *__str, char const *__expantion, ulong __offset);
				char const *__expand(char const *__string, char const *__expantion, ulong __offset);
				char const *expand(char const *string, char const *exp);
				char const *__expand_str(char const *__str, char const *__expantion);
				char const *__combine_str(char const *__str_1, char const *__str_2);
				ulong str_cdelims(char const *__str, char const *__delim);
				ulong arr_cdelims(char const *__str);
				ulong sep_offset(char const *__str, char const *__seperator);
			#endif
			#ifndef _D_LOG_H
				#define _D_LOG_H 1
				// log
				void log_str(int file_descriptor, char const *string);
				void log_dpoint(d_point *dst_point);
				void log_sstat(s_stat *sfile);
				void log_mstat(m_stat *mfile);
				void log_esptr(ulong *ptr);
				void log_process_ids(ulong p_pid, ulong c_pid);
				void log_process_schema(ulong p_pid, ulong c_pid);
				void log_at_protoname(atp_t atp_name);
				void log_ixrh(ixr_h *ixrh);
				void log_socket(aip_sock *sock);
				char const *__atp_names(int __at);
				void log_atp_names();
				void log_content(content_st *content);
				void log_into(d_into into_st);
				void log_keyvalue(char *key, char *value);
				void lbb_usage();
				void log_ixr_point(void *__);
			#endif
			#ifndef _D_ARCH_H
				#define _D_ARCH_H 1
				// arch
				int __is_module(char const *__);
				int __is_file(char const *__);		
				int __is_ref(char const *__);
				char const *__address(int __level, char const *__filename);
				ulong *__indices(char const *__temp);
				char const *__uname(const char *__filename);
				char const *__get_atnmae(char const *__naming);
				char const *__getcaller();
				char const *caller();
				char const *charm_call(char const *entry, char const *name);
				int __entry_valid(char const *__);
				int __entry_nvalid(char const *__);
				ulong vcontent_count(void const **__vc);
				ulong content_count(char const **__content);
				ulong lexical_args(void **__vars);
				ulong __size8(int _);
				ulong lbb_type2size(lbb_t lbb_type);
				int __check_fld(char const *__path, lbb_t __path_type);
				char const *__charm_call(char const *entryhash, char const *__cname);
				char const *__mod_call(char const *__mname);
				char const *__fcall(char const *__filename);
				char const *__dcall(char const *__dirname);
				char const *__ecall(char const *__mod, char const *__name);
				int __check_ectx(char const *__mod, char const *__name);
				int __check_entry(char const *entry);
				ulong arch_ufile(char const *__cpath);
				lbb_t arch_tfile_lbb(char const *__cpath);
				char const *arch_szfile(char const *__cpath);
				int get_mstat(char const *__path, m_stat *mfile);
				int indexer_start();
				int __indexer__(char const *idr);
				int arch_att(char const *__path, ulong __perm, ulong __fldsize);
				char const *arch_dfile(char const *__name, ulong arch_perm, ulong tfile_size);
				int arch_cfile(char const *cf_name, lbb_t lbb_ftype);
				int arch_fperm(char const *__cpath, aip_sterm __sterm);
				void *__mstat__(m_stat *st);
				void const **variable_args(ulong __var_count, char const *__str, char const *__delim);
			#endif
			#define __H512__N 1
		#endif
	#endif

	#define Karch512 "K-arch512d"
#endif