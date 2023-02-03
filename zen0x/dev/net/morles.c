/// morles \\\
the morles server

/**
 * 
 * a new hash is always welcomed so 
 * 
**/

struct __k_args {
	uns hcount,
	ulong const *hashes[]
};

struct __c_args {
	int argc,
	char const *argv[]
};

struct _k_args {
	uns hcount,
	ulong const *hashes[],
	struct __c_args c_args
};

struct _c_args {
	int argc,
	char const *argv[],
	struct __k_args k_args
};


union kc_args {
	struct _k_args kargs;
	struct _c_args cargs;
};

#define kc_args args 

int main(int argc, char const *argv) {



	args _args = {
		.cargs.argc=argc,
		.cargs.argv=argv
	};





}
