/// what is my kurl ? \\\

/**
usage ::

	a.	kurl [path] (level) 
		e.g:: kurl /home/kj/athernet 2

	b.	@[point_name] 
		e.g:: athernet@KARAM

	c.	[u_reference] || #reference 
		e.g:: 2x194102491959120
			note:: since most shells needs an escape char for `#` i.e :: `\#`
				kurls support direct level calls :: `0x` , `1x` , `2x` , ... 
**/
#include "kurl.h"

void lbb_test() {

	printf( "book ref :: %p\n" , lbb );
}



int kurl( void *__ ) {
    if ( sizeof __ == 1 ) {
        #define ik__len 8
    }
    #include "__k.h"
    ulong lbb_inn = p0; // 8-long-lbb-inn
    printf( "lbb inodenum :: %ld\n" , lbb_inn );
    char *lbb_ref = att;
    printf( "lbb current ref :: %s\n" , lbb_ref );
    char *lbb_key = hat;
    printf( "lbb current key :: %s\n" , lbb_key );
    char *lbb_des = pat;
    printf( "lbb current point :: %s\n" , lbb_des );
    int ap_lbb = p1;
    printf( "ather point reader :: %d\n" , ap_lbb );
}

int main( void *args ) {

    return kurl( args );
}


















