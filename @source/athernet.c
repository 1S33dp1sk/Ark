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

	a.	athernet (level|alias)
		e.g:: athernet
			: athernet 2
			: athernet chainnet
			: athernet unix
**/
int main( int argc , char **argv ) {

	little_black_book( "" , __lbb );
	lbb_append( &__lbb , "0ai" , "2" );
	
	
}