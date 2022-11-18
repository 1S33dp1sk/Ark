#ifndef nai
	#define nai atherinterface // native ather interface
	
// supported natives < 0 , 1 , 2 , 3 >
#define nai_max 3
// mount path must be less than 512 bytes
#define mpath_max 512
// socket address max is ipv6 which is 16 bytes
#define saddr_max 16
// {sub,named,toplevel} domain must be less than 128 bytes each
#define dstr_max 128
// blockchain address is 256 bytes max
#define baddr_max 256
// blockchain identitfer must be 3 characters
#define bid_max 3

/**
 * since `__nai` is a union we will use a concept called 
 * 	common initial sequence ( cis ) for the structs a_i*
 * 
 * any struct element is prepended with `__` if the element
 * accessed is a *cis*
 */

struct a_inmp {
	long inn; // node number
	char imp[mpath_max]; // mount path
};

struct a_isok {
	long __inn; // cis
	char __imp[mpath_max]; //cis

	unsigned isv; // socket version
	char isa[saddr_max]; // socket address
	int isp; // socket port
};

struct a_idns {
	long __inn; // cis
	char __imp[mpath_max]; // cis

	unsigned __isv; // cis
	char __isa[saddr_max]; // cis
	int __isp; // cis

	char ids[dstr_max]; // sub domain
	char idn[dstr_max]; // domain name
	char idt[dstr_max]; // top level domain
};

struct a_ibna {
	long __inn; // cis
	char __imp[mpath_max]; // cis

	unsigned __isv; // cis
	char __isa[saddr_max]; // cis
	int __isp; // cis

	char __ids[dstr_max]; // cis
	char __idn[dstr_max]; // cis
	char __idt[dstr_max]; // cis

	char ibi[bid_max]; // blockchain identifier
	char iba[baddr_max]; // blockchain address ( public key )
};


union __nai {
	struct a_inmp n_uni; // universal ( unix )
	struct a_isok n_loc; // local
	struct a_idns n_glo; // global
	struct a_ibna n_blo; // blockchain
};

#define ani union __nai



int atherinterface( int level , ani __ );


#endif