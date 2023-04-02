#ifndef __KARCH__
	#define __KARCH__ 4096
/**
* nai =: native aether interface
* 
* The following are used as outputs
* DEBUG		#used to display most sub-processes happening.
* OUTPUT	#used to display any output.
* PROCESS	#used to display the names of the sub-processes being executed.
* LOG_ERR	#used to display the errors.
**/
	#define OUTPUT 1
	#define PROCESS 1
	#define DEBUG 1
	#define LOG_ERR 1
	#include "_512.h"
#endif

// #ifdef __MODS
// 	#ifndef __ATP__H
// 		#include "atp/h"
// 	#endif
// 	#ifndef __ENK__H
// 		#include "enk/h"
// 	#endif
// 	#ifndef __HBAR__H
// 		#include "hbar/h"
// 	#endif
// 	#ifndef __IXR__H
// 		#include "ixr/h"
// 	#endif
// 	#ifndef __LBB__H
// 		#include "lbb/h"
// 	#endif
// #else
// 	#ifndef __HBAR__H
// 		#include "arch512/hbar.h"
// 	#endif
// 	#ifndef __ENK__H
// 		#include "arch512/enk.h"
// 	#endif
// 	#ifndef __LBB__H
// 		#include "arch512/lbb.h"
// 	#endif
// 	#ifndef __IXR__H
// 		#include "arch512/ixr.h"
// 	#endif
// 	#ifndef __ATP__H
// 		#include "arch512/atp.h"
// 	#endif
// #endif
