/// \\\

#define DEBUG

// any header, function or defintion
// can be declared here such as \\
#include <string.h>

#ifndef __idx__h
	#define __idx_name "@idx"
	#define ccc_dir "@__ccc__d@"

	#ifndef __os_name
		#if HAVE_TARGET_CONDITIONALS_H
			#include <targetConditionals.h>
		#endif
		#if _WIN64
			#define __os_name "windows:64b\0"
		#elif _WIN32
			#define __os_name "windows\0"
		#elif TARGET_OS_IPHONE
			#define __os_name "apple:iphone\0"
		#elif TARGET_OS_MAC
			#define __os_name "apple:macos\0"
		#elif __APPLE__
			#define __os_name "apple\0"
		#elif __linux__
			#define __os_name "unix:linux\0"
		#elif __ANDROID__
			#define __os_name "unix:android\0"
		#elif BSD
			#define __os_name "bsd\0"
		#elif __unix__
			#define __os_name "unix\0"
		#else
			#define __os_name "\0"
		#endif
	#endif
	
	#include "probe.h"

		
	char *__current_dir() {
		char *actv_dir, __activity_dir[__sa__dsls];memset(&__activity_dir,0,__sa__dsls);
		actv_dir = getcwd(__activity_dir,__sa__dsls);
		return strdup(__activity_dir);
	}

	struct __i_name {
		char h_name[__sa__pi];
		char l_name[__sa__pi];
		char s_name[__sa__pi];
	};
	struct __i_name i_name() {
		struct __i_name __;
		if(gethostname(__.h_name,HOSTNAME_MAX)==-1){
			__.h_name[0]='\0';
		};
		if(getlogin_r(__.l_name,LOGNAME_MAX)!=0) {
			__.l_name[0]='\0';
		};
		memcpy(__.s_name,__os_name,strlen(__os_name));
		return __;
	}

	struct __i_info {
		ulong uid;
		ulong euid;
		ulong rgid;
		ulong egid;
		ulong mw_bytes;
	};
	struct __i_info i_info() {
		struct __i_info __ = {
			.uid=(ulong)getuid(),
			.euid=(ulong)geteuid(),
			.rgid=(ulong)getgid(),
			.egid=(ulong)getegid(),
			.mw_bytes=pathconf(__current_dir(),_PC_PIPE_BUF)
		};
		return __;
	}

	struct __i_index {
		struct __i_name names;
		struct __i_info info;
	};
	struct __i_index i_index() {
		struct __i_index __ = {
			.names=i_name(),
			.info=i_info()
		};
		return __;
	}

int main(){
	struct __i_index inst = i_index();
	#ifdef DEBUG
		#include <stdio.h>
		printf("real group id      :: %lu\n",inst.info.rgid);
		printf("effective group id :: %lu\n",inst.info.egid);
		printf("atomic max bytes   :: %lu\n",inst.info.mw_bytes);
		printf("hostname           :: %s\n",inst.names.h_name);
		printf("login name         :: %s\n",inst.names.l_name);
	#endif
	return 0;
}

#endif
