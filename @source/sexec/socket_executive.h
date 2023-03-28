#include "common.h"


#ifndef AtherShell
#define AtherShell "@shell"


int ather_shell() {
	char _atherdir[MAX_PATH];

	a_info current_info;


	__homedir( _atherdir );
	__entries( _atherdir , &current_info );

	printf( current_info.af_path );

	printf("\n\n%c\n\n", current_info.con_status );

	return 0;
}

#endif
