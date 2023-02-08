#define att 1
#if att
/***\
Ternary
 * ternary base is what determines
 * the main permissions in the system.
 * 
 * Permissions are divided into 2 main parts:
 * 1.   File type
 * a simple 2 bit/1 byte solution to determine the 
 * known type of the file. i.e: FIFO,Socket,Storage...
&-> 
 * 2.   Contribution
 * With `access()` that's where the ternary actually 
 * shines. As it is divided into 3 main parts
 * a.   Host 		att		`file current location`
 * b.   Published 	by		`file data&permissions are set`
 * c.   Charm 		connect	`file address on athernet` 
 * 
 * the three different numbers {a.k.a addresses} determine 
 * a pseudo conversion between operating system permissions
 * as it acts in its own shell and index it's own files,
 * acts as a listener && as a server. 
 *
 * Keep in mind that all of the following code is based
 * on the current machines and their operations. Therefore,
 * this is not true ternary as we are simulating a ternary
 * system on a binary machine. 

 #mrkj
 * 
\***/
#include "idxer.h"
// mach \\
	machine 
#if __mach__ // n**8 bytes
	#ifndef __MACH_FILE__
		#error "att: MachFile cannot be included.\n"
	#else
		#if __mach__i //*^8
			
		#elif __lo_n //64bytes!
			
		#elif __ter512 //ternary* 
				static const ulong *__ter_base={0xFFFF7777,0x77771111,0x11110000};
				#define terins (ulong *)__ter_base
			
		#endif
	#endif
#endif
// atp \\
	ather transfer protocol
#if __ATP__
	#ifndef ATP
		#include "atp/MachFile"
		#endif
	#else
		#include "net/mor.h"
	#endif
	#if __SOKPOINT__
	#if Descriptions
		#define dname Descriptions.__file__
	#if Socket.point
		#define sok_t Socket.type()


	#elif __LBB__
		#if TER_LBB
			#define lbb "c@lbb#n"
			#define __c_ternary__ "ccc"
			#define __res__ 999
		#endif

		#if __TERC
			#ifndef TER_C
				extern const ulong __hlen;
				extern const ulong __hsize;
				extern const char *__fmt_header;
				extern ulong __rf;
				extern ulong __eout;
				extern ulong __fdlo;
				extern char **environ;
				#define TER_C 1
				#endif
			#undef __TERC
		#endif

		#if __TERH
			#ifndef __TER__H
				#include <unistd.h>
				#include <sys/stat.h>
				#include <fcntl.h>
				#include <stdio.h>
				#include <string.h>
				#include <stdlib.h>
				#define __TER__H 1
				#endif
			#undef __TERH
		#endif

		#if _0_TER
			static size_t *__field__(char const *filename,ulong filelines,ulong datasize);
			static uchar *__header(uchar *__,char const *filename,ulong filelines,ulong datasize);
			static ulong const blazing_hash(void *);

			static const ulong __hlen=256;
			static const ulong __hsize=256*sizeof(uchar);
			static const char *__fmt_header="__s_L_L__s\0";
			static ulong __rf=0;
			static ulong __eout=0;
			static ulong __fdlo=0;
			#undef 0_TER
		#endif

		#if _1_TER
			static size_t *__field__(char const *filename,ulong filelines,ulong datasize) {
				// free the tracker
				size_t *tracker=malloc((3*sizeof(size_t)));
				static uchar header[256];
				uchar *_header=__header(header,filename,filelines,datasize);
				return tracker;
			}
			static uchar *__header(uchar *__,char const *filename,ulong filelines,ulong datasize) {
			#define fmt_header __fmt_header
				memset(&__,0,__hsize);
				size_t __fname=strlen(filename);if(__fname>=256){printf("names<256b!\n");_exit(1);}
				pack(__,fmt_header,filename,filelines,datasize,".out\n\0");
				return __;
			}
			ulong const blazing_hash(void *_){
			    return (ulong)0x3;
			}
			#undef 1_TER
			#define TER_1(x) blazing_hash(x)
		#endif

		#if b1_TER
			static ulong __file_d(char const *filepath){
				ulong res=0;
				int __=0;
				__=open(filepath,O_RDONLY);
				if(__!=-1){
					res=__;
					__rf=res;
				}
				return res;
			}
			ulong __fw_att(char const *__f,ulong __w__,ulong offset) {
				long res=0;
				ulong __flen=strlen(__f),__res=__flen+offset;
				// maybe remove if intermideiate write is not sucessful
				res=pwrite(__w__,__dofl(offset),offset,0);
				// maybe remove if final write is not sucessful
				res=pwrite(__w__,__f,__flen,offset);
				return res!=__res?0:__res;
			}
			/**
			secretive ::
			 * `fsz8(dir)` && `fsz8(lbb_1)` 
			 * 		returns the same size for the field. Both are 4096 bytes.
			 * 
			 * 	Nonetheless,
			 *  when dir is created we fill file with `#`. 
			 *  when lbb is created we fill file with `@`.
			**/
			char *__dofl(ulong __){
				char fl[__];
				memset(&fl,'\n',__);
				return strdup(fl);
			}
			char *__f_lbb_out(){
				int __=open("lbb.out",(O_RDWR|O_CREAT),S_IROTH);
				__fdlo=__==-1?0:(ulong)__;
				return "LO";
			}
			char *__f_out_lbb(){
				int __=open("out.lbb",(O_RDWR|O_CREAT),(S_IRWXU|S_IRGRP|S_IXGRP));
				__fdlo=__==-1?0:(ulong)__;
				return "OL";
			}
			#undef 21_TER
			// 		#if TER_1
			// 			#if defined(TER_1(lbb))
		#endif

		#if b1_TEL
			#define __ma_file "machine"
			#define __lo_file "local"
			#define __so_file "socket"
			#define __te_read "/path/to/.lbb"
			#define __ter_file ".lbb"
			#define __zero_att ((ulong)0x0000000000000000)
			#define __mlf__kei ((ulong)0x000000002e6c6262)
			#define input 0x6262
			static const uchar *__=(uchar *)input;
			int fields();
		#endif

		#if t1_TER
			#define TERNARY_LEVELS 3
			enum _ud {
				u__='u',
				__d='d',
			};
			struct __vsr { // hash string
			    ulong __len;
			    ulong __hash;
			    uchar*__str;
			};
			#define vstr struct __vsr
			#define sarg(x) ((uns)(x->__str))
			#define larg(x) ((uns)(x->__len))
			#define harg(x) ((uns)(x->__len=strlen(x->__str)))
			#undef 31_TER
		#endif
	#else
	    #ifndef __UTYPES__H
	    	#include "utypes.h"
	    #endif
	    #ifndef __IDXER__H
			#include "idxer.h"
		#endif
		#ifndef __ZENV__H
			#include "zenv.h"
		#endif
	#endif
	#ifndef __TER__H
		#define __TER__H 1
	#endif
#endif	
#endif
			#endif