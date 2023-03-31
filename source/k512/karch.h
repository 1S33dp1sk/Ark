/// machine file \\\
K512-architecture 

#ifndef __KARCH__H
	#define __KARCH__H 1
/**
* nai =: native aether interface
* 
* The following are used as outputs
* DEBUG		#used to display most sub-processes happening on nai
* OUTPUT	#used to display any output on nai
* PROCESS	#used to display the names of the sub-processes being executed on nai
* LOG_ERR	#used to display the errors on nai
**/
	#define OUTPUT 1
	#define PROCESS 1
	#define DEBUG 1
	#define LOG_ERR 1
	#ifndef __UTYPES__H
		#include "utypes.h"
	#endif
	#ifndef __ANETSTD__H
		#include "standard.h"
	#endif
	#ifndef __HBAR__H
		#include "hbar.h"
	#endif
	#ifndef __ENK__H
		#include "enk.h"
	#endif
	#ifndef __LBB__H
		#include "lbb.h"
	#endif
	#ifndef __IXR__H
		#include "ixr.h"
	#endif
	#ifndef __ATP__H
		#include "atp.h"
	#endif
#endif


#ifndef __KARCH_D512__
	#include "_512.h"



	#define __KARCH_D512__ 4096
#endif
