/// athernet \\\

#include "probe.h"
#include "hbar/hbar.h"
#include "point/point.h"
#include "lbb/lbb.h"
#include "nai/nai.h"





/**
components ::
	athernet proper init requires:: 
 		1. atherpoint ( ap )
 		2. little black book ( lbb )
**/
static ap __ap;
static lbb __lbb;
/**
usage ::

<<<<<<< HEAD
int main( int argc , char **argv ) {

	
	unsigned __c = 0;

	ap __atherpoint; 
	lbb __pointlbb;

	wdebug();
	genesis_kurl = __kurl()&lbb_exists() \
		== __net_kurl ? __kurl()&lbb_load( __pointlbb ) : __kurl()&lbb_make( __pointlbb );		
	wdebug();
=======
	a.	athernet (level|alias)
		e.g:: athernet
			: athernet 2
			: athernet chainnet
			: athernet unix
	
	aliaslist::
		0	|	unix	|	homenet
		1	|	local	|	intranet
		2	|	global	|	internet
		3	|	block	|	chainnet 
**/
int main( int argc , char **argv ) {
>>>>>>> c94b96b (started documentation with proper formatting as follows)
	
	// genesis_kurl = __kurl()&lbb_exists() \
	// 	== __net_kurl ? __kurl()&lbb_load( __lbb ) : __kurl()&lbb_make( __lbb );		
	
	// genesis_kurl = genesis_kurl <= __pmax_kurl ? 0 : 1 ;
}