#ifndef __ANETSTD__H
/**
 * 
 * tests should be done here per header, and checked against to result
 * in a pre defined manner to ensure consistant execution across devices and 
 * systems
**/
#define __ANET_IDX 2

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
#define __ANETSTD__H __ANET_IDX
#endif