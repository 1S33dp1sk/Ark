#ifndef __hat__
	#define hat void *
	#define __hat__ ( hat _ )
	#define type_h unsigned long
	#define cast_h( _ ) ( ( unsigned long ) ( _ )  ) 
	#define ksig__ 0x0
	#define ksig_p1 ( unsigned long ) 0x11111111
	#define ksig_n( _ ) ksig

extern type_h ksig __hat__{
	unsigned long c = ( type_h ) _;
	return cast_h( c^ksig_p1 );
}

#endif
