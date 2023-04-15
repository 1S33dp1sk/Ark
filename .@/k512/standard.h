#ifndef __ANETSTD__H
    #define __ANET_IDX 4
    #define __ANETSTD__H __ANET_IDX
/**
 * 
 * tests should be done here per header, and checked against to result
 * in a pre defined manner to ensure consistant execution across devices and 
 * systems
**/

#ifndef __anet_unistd
#include <unistd.h>
#define __anet_unistd __ANET_IDX
#endif

#ifndef __anet_stdlib
#include <stdlib.h>
#define __anet_stdlib __ANET_IDX
#endif

#ifndef __anet_stddef
#include <stddef.h>
#define __anet_stddef __ANET_IDX
#endif

#ifndef __anet_stdint
#include <stdint.h>
#define __anet_stdint __ANET_IDX
#endif

#ifndef __anet_stdio
#include <stdio.h>
#define __anet_stdio __ANET_IDX
#endif

#ifndef __anet_string
#include <string.h>
#define __anet_string __ANET_IDX
#endif

#ifndef __anet_fcntl
#include <fcntl.h>
#define __anet_fcntl __ANET_IDX
#endif

#ifndef __anet_sys_types
#include <sys/types.h>
#define __anet_sys_types __ANET_IDX
#endif

#ifndef __anet_sys_stat
#include <sys/stat.h>
#define __anet_sys_stat __ANET_IDX
#endif

#ifndef __anet_sys_socket
#include <sys/socket.h>
#define __anet_sys_socket __ANET_IDX
#endif

#ifndef __anet_sys_wait
#include <sys/wait.h>
#define __anet_sys_wait __ANET_IDX
#endif

#ifndef __anet_errno
#include <errno.h>
#define __anet_errno __ANET_IDX
#endif

#ifndef __anet_netdb
#include <netdb.h>
#define __anet_netdb __ANET_IDX
#endif

#ifndef __anet_netinet_in
#include <netinet/in.h>
#define __anet_netinet_in __ANET_IDX
#endif

#ifndef __anet_arpa_inet
#include <arpa/inet.h>
#define __anet_arpa_inet __ANET_IDX
#endif

#ifndef __os_name
#define __os_delim_offset 3
#define __os_delim "/\0"
    #if HAVE_TARGET_CONDITIONALS_H
        #include <targetConditionals.h>
    #endif
    #if defined(_WIN64)
        #define __os_name "windows:64b\0"
        #undef __os_delim
        #define __os_delim "\\\0"
    #elif defined(_WIN32)
        #define __os_name "windows\0"
        #undef __os_delim
        #define __os_delim "\\\0"
    #elif defined(TARGET_OS_IPHONE)
        #define __os_name "apple:iphone\0"
    #elif defined(TARGET_OS_MAC)
        #define __os_name "apple:macos\0"
    #elif defined(__APPLE__)
        #define __os_name "apple\0"
    #elif defined(__linux__)
        #define __os_name "unix:linux\0"
    #elif defined(__ANDROID__)
        #define __os_name "unix:android\0"
    #elif defined(BSD)
        #define __os_name "bsd\0"
    #elif defined(__unix__)
        #define __os_name "unix\0"
    #else
        #define __os_name "\0"
    #endif
#endif

#endif
