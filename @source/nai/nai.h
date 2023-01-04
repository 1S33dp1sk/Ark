#ifndef nai

// #define DEBUG


/**
 * since `__nai` is a union we will use a concept called 
 * 	common initial sequence ( cis ) for the structs a_i*
 * 
 * any struct element is prepended with `__` if the element
 * accessed is a *cis*
 */

#define __nai_name "nativeainterface"

struct a_inmp {
	long inn; // node number
	char imp[mpath_max]; // mount path
};

struct a_isok {
	long __inn; // cis
	char __imp[mpath_max]; //cis

	unsigned isv; // socket value
	struct sockaddr_storage isa;
	int isp; // socket port
};

struct a_idns {
	long __inn; // cis
	char __imp[mpath_max]; // cis

	unsigned __isv; // cis
	struct sockaddr_storage isa; // cis
	int __isp; // cis

	char ids[dstr_max]; // sub domain
	char idn[dstr_max]; // domain name
	char idt[dstr_max]; // top level domain
};

struct a_ibna {
	long __inn; // cis
	char __imp[mpath_max]; // cis

	unsigned __isv; // cis
	struct sockaddr_storage isa; // cis
	int __isp; // cis

	char __ids[dstr_max]; // cis
	char __idn[dstr_max]; // cis
	char __idt[dstr_max]; // cis

	char ibi[bid_max]; // blockchain identifier
	char iba[baddr_max]; // blockchain address ( public key )
};

typedef union __nai {
	struct a_inmp n_uni; // universal ( unix )
	struct a_isok n_loc; // local
	struct a_idns n_glo; // global
	struct a_ibna n_blo; // blockchain
} nai;


int uni_interface( struct a_inmp *n_uni );
int loc_interface( struct a_isok *n_loc );
int glo_interface( struct a_idns *n_glo );
int blo_interface( struct a_ibna *n_blo );

nai native_interface( int level );
char *native_address( int level );


#endif


