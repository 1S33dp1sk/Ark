<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> x/master
# 
#####################################
#			Shell/@net				#
#####################################
__me:=$(shell whoami)
__host:=$(shell arch)
__cdir:=$(shell pwd)
__home:=@net
#####################################
#			C/Directories			#
#####################################
attixr:=./@
@__:=${__cdir}/@
__@:=${__cdir}/.@
__bin:=${__@}/bin
__lib:=${__@}/lib
__shd:=${__@}/shared
shrd_fun:=${__shd}/funcs
shrd_pge:=${__shd}/pages
shrd_ipr:=${__shd}/intrpt
__src:=${__@}/source
@charms:=${__cdir}/@charms
@mymach:=${__cdir}/@mach


#f gorgeous.
charms:
	if [ -f ".lbb" ]; \
		then $_ __link__; \
	else \
		if [ ! -f "charm" ]; \
			then $_ __init__;\
		else \
			$_ __att__; \
		fi;\
	fi;
<<<<<<< HEAD

<<<<<<< HEAD
=======

>>>>>>> temp/source
#ather processor := _u_charm 
a:=att#address
b:=bal#balance
c:=ccc#charm
d:=dig#digital
e:=exs#execs
f:=fmn#formation
g:=gab#gability
h:=hlv#hlevel
i:=ine#include
j:=jie#jiter
k:=kur#kursor
l:=lar#laddr
m:=mae#manage
n:=nop#nope
o:=ops#operations
p:=pub#public
q:=que#query
r:=rdd#read
s:=spc#space
t:=trv#traverse
u:=usr#user
v:=vik#vik
w:=wlk#wellkommen
x:=xlv#xolve
y:=ybs#ybase
z:=zai#zai

<<<<<<< HEAD
=======
misc:
	cc @source/misc.c -o shared/programs/misc ./shared/libather.so
	./shared/programs/misc
=======
	#replace with encoding next ;
#ather processor := _u_charm 
#/** 			@	   #\
 address 		: att =uchar*		:=lbb{ [fd,inn] , path }\
 balance 		: bal =ulong			:=query( att )\
 charm 		: chm =char const*	:=charm\
 digital 		: dig =ulong			:=#def\
 execs		: exs =sizeof		:=void *\
 formation	: fmn =ulong		:=#usedef\
 gvailability	: gvy =args_t[2]	:=l_args,args_r\
 hevel		: hvl =ulong	:=1|hashlvl\
 include		: ine =uchar*[]		:=files||strings\
 jcall		: jck =ulong[]		:=call_(j)\
 katt			: ktt =struct _u_,ulong*,void *:=__id,charms,__kargs(seed__,...)\
 laddr		: lar =union __nai*				:=native_ather_interface\
 mcall		: mca =addr_t,callre_t*,void *	:=kmem,ket,krgs\
 nope			: nop =sizeof			:=entry_t\
 operatingsys	: sys =sizeof			:=sys_call()\
 pdetails		: pds =sizeof			:=point_t\
 qlbb			: qlt =sizeof			:=lbb_query(type_t)\
 rlbb 		: rlb =struct __lbb		:=book\
 sandbox		: sbp =char *[]			:=playground\
 traverse		: tra =number			:={ de , en }code(base)\
 user			: usr =sizeof			:=home\
 vik			: vik =struct vik_t** 	:=viks\
 welkommen	: wln =ulong			:=connect(loc)\
 xolve		: xol =sizeof			:=request\
 ybins		: ybi =char *[]			:=bins\
 z 			: log =int&struct __privacy	:=_yes,_no,_maybe,def\
#**/


// the number of tabs control the access level allowed
# 0 -> nodef
const static char __control = '\t';
# 2 -> command ( default_args || supplied_args )
const static char _ignored[6] = { '@' , '#' , ':' , '=' , '\s' }; // "\s" for formatting freaks in code beauty
# 3 -> define
unsigned long count_tabs( void *__ , unsigned char _ ) {
	unsigned char *__c = (unsigned char *) __;
	unsigned long _r = 0;
	while ( __c != '\t' ) {
		if ( _ == 'l' ) {
			__c-=2;
		}
		_r+=1;
		__c+=1;
	}
	return _r;
}
# 4 -> kmem_alloc( base_ , _size )
void *kmem_alloc( unsigned long _b , unsigned long _s ) {
	struct __kmem = {
		.__base = _b;
		.__size = _s;
		.__start = katt( struct __kmem )
		.lock = retrieve()
	}
	unsigned long total = 0;
	while ( _s > 0 ) {
		total += _b * _s;
		_s-=1;
	}
}

static long __lbb__error__ = 0;

__lbb_errors[] = { 
	"not enough storage\n", //_0xf=
}

void const *lbb_error() {
	return *__lbb_errors[__lbb__error__];
}

void const *katt( unsigned long _size ) {
	if ((lbb_reserve(_size)) < 0 ) {
		return lbb_error();
	}
	return lbb_point();
}

static unsigned long f_reserve = 0; // wrong to have f_reserves should be automated as in sequencial


// long to indicate error on -ve returns
long lbb_reserve(unsigned long _size) {
	unsigned long _reserve = __reserve(_size);
	if ( _reserve == 0 ) {
		__lbb__error__ = -1;
		return __lbb__error__;
	}
	return _reserve >= _size ? _reserve : f_reserve ; 
}

void const *lbb_point() { 
>>>>>>> v9/athernet
	
} 

struct __lbb_loc {
	unsigned long offset,
	unsigned long subsize,
	void const* __start;
};

struct __kmem {
	unsigned long __base;
	unsigned long __size;
	void const* __start;
	struct __lbb_loc lock;
};

struct __lbb_loc retrieve() {

	struct __lbb_loc = {
		.offset = __lbb_cur_offset,
		.subsize = __lbb_cur_size,
		.__start = __lbb_att
	};

	return &__lbb_loc
}

union __lbb__ {
	struct _fd_inn {
		unsigned long fd;
		unsigned long inn;
	} _fdinn;
	struct _path {
		unsigned char const* p;
		unsigned long l;
	} _path;
}



# ather processors always have 2 or more point{s,ers} a tracker of the type 
# and a tracker for the referenced execution params, notice here that execution
# params include binaries, ternaries, and any new numbering system&|encoding 
# including two or more step executions such as compile, link & run using a combination of 
# `cc`, `[ar,nm, cc -fpic]` , `./` 
#in general the following:
	# `./shared/programs/[interpreter:python3,node,sh,...] args..` 

# a 2nd level ather processor can be fully connected on a full grid, with max bit change being the 
# correct amount of balance between latency and complete change.
# the type of, defined for this, is ternary which is 3. it's VERY important to note that 3 means,
# 3 different `ent`|entities in the ather processor and not the same ather processor into more than 1,
# it's also very important to note that the ather processor is always changing but 1 change at a time
# and that's the charm.

# a 3rd level ather processor can relay latency and change to other ather processors connected on the
# athernet.
#	the athernet uses blockchain for historical data, the internet to connect, ternary for lockation, binary to execute \
by mr.kj 

# an athernet processor is able to define itself or mimic any other type of athernet processor, nonetheless
# a processor is not limited, except by it's balance. Unlike in the traditional sense the hardware is the limitation, 
# no sir, 
# a device running athernet can execute commands comming from processors that it's not running on, as a vik, 
# and each vic contributes xol to get the { cpu , gpu } execution to the output device, delivered and executed.
# the amount,lockation,latency of the combined laddr processors that run any charm determines a part of that charm.
# 
# 




address:
	@if [ ! -d @charms ]; then printf "no charms\n run \`charm\`\n"; \
		else printf "att;" > @charms/.address; fi

balance:
	@if [ ! -f @charms/.balance ]; then printf "no balance found\n"; \
		else printf "0" > @charms/.balance; fi

charms_:
	att=$( address )
	bal=$( balance )
	chm=$( charm )

charm__:
	$_ _charms
	$_ __charms
	$_ charms_

_charms:
	rm -rf @charms

__charms:
	if [ ! -d "@charms" ]; then mkdir @charms; fi
	touch @charms/.address
	touch @charms/.balance
	touch @charms/.charm

charm:
	$_ charm__
	@printf "\n@charm:0xkaram#\n" > @charms/.charm

^digital:
	@cat @charms/.charm

digital:
	#modules
# 	so_athernet=
#fifo coms

execs:
	exs
#execute c on socket




formation:
#hash( "left" , "right" )
	$( c__ )shared/programs/kurl
pre:
	c=@
	c__=./
	c_bash=/bin/bash
	cc=/usr/bin/cc
	ch=#

runs:
	_anet=$( c__ )shared/programs/athernet
	_kurl=$( c__ )shared/programs/kurl







executables:
	@cc @source/athernet.c -o shared/programs/athernet ./shared/libather.so
	@cc @source/kurl/kurl.c -o shared/programs/kurl ./shared/libather.so

run_check:
	#checking
	@if [ ! -d shared ]; then $_ run_compile; fi
	@if [ ! -f .lbb ]; then $_ run_kurl; fi

run_clean:
	@if [ -d shared ]; then rm -rf shared; fi
	@if [ -f .lbb ]; then rm -rf .lbb; fi
	@if [ -f athernet ]; then rm -rf athernet; fi
	@if [ -f kurl ]; then rm -rf kurl; fi

run_compile:
	@mkdir -p shared/{compiled,programs} && printf "compling..\n";
	# ather 
	# a
	@printf "att point [:=] address\n"
	@cc -c -fpic @source/point/point.c -o shared/compiled/point.o
	# t
	@printf "tkurl (  )\n"
	@cc -c -fpic @source/kurl/kurl.c -o shared/compiled/kurl.o
	# h
	@printf "hbar ( hash whatever )\n"
	@cc -c -fpic @source/hbar/hbar.c -o shared/compiled/hbar.o
	# e
	@printf "eai ( electronic ather interface )\n"
	@cc -c -fpic @source/nai/nai.c -o shared/compiled/nai.o
	# r
	@printf "read( little black book )\n"
	@cc -c -fpic @source/lbb/lbb.c -o shared/compiled/lbb.o
	@cc -shared shared/compiled/*.o -o shared/libather.so
	$_ executables



run_asyemtric:
	$_ run_check










run_symetric:










kurl_test:
	@if [ -f athernet ]; then rm athernet; fi
	@if [ ! -d shared ]; then mkdir shared; fi
	@if [ -f .lbb ]; then rm .lbb; fi
	@cc -c -fpic @source/hbar/hbar.c -o shared/hbar.o
	@cc -c -fpic @source/nai/nai.c -o shared/nai.o
	@cc -c -fpic @source/point/point.c -o shared/point.o
	@cc -c -fpic @source/lbb/lbb.c -o shared/lbb.o
	@cc -shared shared/*.o -o shared/libather.so
	@cc @source/athernet.c -o athernet ./shared/libather.so
	@cc @source/kurl/kurl.c -o kurl ./shared/libather.so
	./kurl
>>>>>>> anet_V9/athernet

ca:
	@if [ -f athernet ]; then rm athernet; fi
	@if [ -f kurl ]; then rm kurl; fi
	@if [ ! -d shared ]; then mkdir shared; fi
	#@cc -c -fpic @source/point/point.c -o shared/point.o
	@cc -c -fpic @source/lbb/lbb.c -o shared/lbb.o
	#@cc -c -fpic @source/hbar/hbar.c -o shared/hbar.o
	#@cc -c -fpic @source/nai/nai.c -o shared/nai.o
	@cc -shared shared/*.o -o shared/libather.so
	@cc @source/athernet.c -o athernet ./shared/libather.so
	#@cc @source/kurl/kurl.c -o kurl ./shared/libather.so

rca:
	if [ -d shared ]; then rm -rf shared; fi
<<<<<<< HEAD
	if [ -f ather ]; then rm ather; fi

=======
ca:
	@if [ -f athernet ]; then rm athernet; fi
	@if [ -f kurl ]; then rm kurl; fi
	@if [ ! -d shared ]; then mkdir shared; fi
	@cc -c -fpic @source/point/point.c -o shared/point.o
	@cc -c -fpic @source/lbb/lbb.c -o shared/lbb.o
	@cc -c -fpic @source/hbar/hbar.c -o shared/hbar.o
	@cc -c -fpic @source/nai/nai.c -o shared/nai.o
	@cc -shared shared/*.o -o shared/libather.so
	@cc @source/athernet.c -o athernet ./shared/libather.so
	@cc @source/kurl.c -o kurl ./shared/libather.so

rca:
	if [ -d shared ]; then rm -rf shared; fi
=======
>>>>>>> anet_V9/athernet
	if [ -f .lbb ]; then rm .lbb; fi
	if [ -f athernet ]; then rm athernet; fi
	if [ -f kurl ]; then rm kurl; fi
	rm atherpoint
<<<<<<< HEAD
>>>>>>> in_vik/main
=======
>>>>>>> anet_V9/athernet

old:
	cc @source/lbb/main.c -o @lbb
	cc @source/hbar/main.c -o @hbar
	cc @source/point/main.c -o @point
	cc @source/entry/main.c -o @entry

<<<<<<< HEAD
<<<<<<< HEAD


=======
>>>>>>> in_vik/main
=======
>>>>>>> anet_V9/athernet
rall:
	rm @lbb
	rm @hbar
	rm @point
	rm @entry
	rm .lbb
	rm atherpoint

clean:
	rm @lbb
	rm @hbar
	rm @point
	rm @entry
=======

indexer_list:
	#first is the basic unistd





# .lbb exists ? __link__
# charm exsists ? __att__
# neither exsists? __init__

shell_att:$(shell ${@__})

__att__: __@__ shell_att

__link__:
	./lbb start

__clean_charms__:
	rm -rf ${@charms}


# when rebuilding source clean
_check_source_: __clean_charms__
	@if [ -d ${__@} ]; \
		then if [ ! -d ${@charms} ]; then $_ _check_charms_;fi \
	else \
		printf "Cannot create @net without the source code. path :: ${__@}.\n"; return 1;\
	fi



# must produce a charm file
__init__: _check_source_
	./arc ${@charms} lbb k-addr









#####################################
#				Shorts				#
#####################################
__empty:=
__binobjs:=${__bin}/*.o
__devheaders:=${__dev}/*.h
_snet:=${__src}/net
_cnet:=${@charms}/net
atherso:=libather.so
athernetso:=libathernet.so
atherlib:=${__lib}/${atherso}
anetlib:=${__lib}/${athernetso__}

# build charms as a list and then run another
# make command to compile and then execute

__ac:=$(cc -c -fpic)
output:= -o ${@mymach} 
ac:=$(addprefix $(addsuffix $(addprefix ${__ac},${@charms}),${output}),${libather})





__build__: libathernet
	@printf "Building charm indexer\n ${lib_ather}\n"
	cc ${@charms}/fld.c -o lbb ${atherlib}

# __shrd:= / funcs pages intpr
# shrd_charms:=$(addprefix ${@charms},${__shrd})

headers_att:=${@charms}/headers
funcs_att:=${headers_att}/fun

__ccc_dirs__:
	if [ ! -d ${@charms} ]; then mkdir ${@charms}; fi;
	if [ ! -d ${@charms}/headers ]; then mkdir ${@charms}/headers; fi
	if [ ! -d ${@charms}/lbb ]; then mkdir ${@charms}/lbb; fi

_check_charms_: __ccc_dirs__
	if [ ! -d ${@charms} ]; then mkdir ${@charms}; fi;
	if [ ! -d ${@charms}/headers ]; then mkdir ${@charms}/headers; fi
	cp ${__src}/_h512.h ${headers_att}
	cp ${__src}/standard.h ${headers_att}
	cp ${__src}/utypes.h ${headers_att}
	cat ${hbar_h} > ${_hbar}
	cat ${hbar_c} >> ${_hbar}
	cat ${enk_h} > ${_enk}
	cat ${enk_c} >> ${_enk}
	cat ${lbb_h} > ${_lbb}
	cat ${lbb_c} >> ${_lbb}
	if [ ! -d ${funcs_att} ]; then mkdir ${funcs_att}; fi
	cp ${__src}/karc.c ${funcs_att}
	cc ${funcs_att}/karc.c -o arc
# 	if [ ! -d ${@charms}/pages ]; then mkdir ${@charms}/pages; fi
# 	if [ ! -d ${@charms}/intrpt ]; then mkdir ${@charms}/intrpt; fi


__@__:
	if [ -f ${@__} ]; \
		then rm -rf ${@__}; \
	fi
	cc ${__src}/att.c -o @;

__shared__: __autogen_charms__
	printf "shared"
=======
=======
>>>>>>> x/master


indexer_list:
	#first is the basic unistd





# .lbb exists ? __link__
# charm exsists ? __att__
# neither exsists? __init__

shell_att:$(shell ${@__})

__att__: __@__ shell_att

__link__:
	./lbb start

__clean_charms__:
	rm -rf ${@charms}


# when rebuilding source clean
_check_source_: __clean_charms__
	@if [ -d ${__@} ]; \
		then if [ ! -d ${@charms} ]; then $_ _check_charms_;fi \
	else \
		printf "Cannot create @net without the source code. path :: ${__@}.\n"; return 1;\
	fi



# must produce a charm file
__init__: _check_source_
	./arc ${@charms} lbb k-addr


>>>>>>> x/machine







#####################################
#				Shorts				#
#####################################
__empty:=
__binobjs:=${__bin}/*.o
__devheaders:=${__dev}/*.h
_snet:=${__src}/net
_cnet:=${@charms}/net
atherso:=libather.so
athernetso:=libathernet.so
atherlib:=${__lib}/${atherso}
anetlib:=${__lib}/${athernetso__}

# build charms as a list and then run another
# make command to compile and then execute

__ac:=$(cc -c -fpic)
output:= -o ${@mymach} 
ac:=$(addprefix $(addsuffix $(addprefix ${__ac},${@charms}),${output}),${libather})





__build__: libathernet
	@printf "Building charm indexer\n ${lib_ather}\n"
	cc ${@charms}/fld.c -o lbb ${atherlib}

# __shrd:= / funcs pages intpr
# shrd_charms:=$(addprefix ${@charms},${__shrd})

headers_att:=${@charms}/headers
funcs_att:=${headers_att}/fun

__ccc_dirs__:
	if [ ! -d ${@charms} ]; then mkdir ${@charms}; fi;
	if [ ! -d ${@charms}/headers ]; then mkdir ${@charms}/headers; fi
	if [ ! -d ${@charms}/lbb ]; then mkdir ${@charms}/lbb; fi

_check_charms_: __ccc_dirs__
	if [ ! -d ${@charms} ]; then mkdir ${@charms}; fi;
	if [ ! -d ${@charms}/headers ]; then mkdir ${@charms}/headers; fi
	cp ${__src}/_h512.h ${headers_att}
	cp ${__src}/standard.h ${headers_att}
	cp ${__src}/utypes.h ${headers_att}
	cat ${hbar_h} > ${_hbar}
	cat ${hbar_c} >> ${_hbar}
	cat ${enk_h} > ${_enk}
	cat ${enk_c} >> ${_enk}
	cat ${lbb_h} > ${_lbb}
	cat ${lbb_c} >> ${_lbb}
	if [ ! -d ${funcs_att} ]; then mkdir ${funcs_att}; fi
	cp ${__src}/karc.c ${funcs_att}
	cc ${funcs_att}/karc.c -o arc
# 	if [ ! -d ${@charms}/pages ]; then mkdir ${@charms}/pages; fi
# 	if [ ! -d ${@charms}/intrpt ]; then mkdir ${@charms}/intrpt; fi


__@__:
	if [ -f ${@__} ]; \
		then rm -rf ${@__}; \
	fi
	cc ${__src}/att.c -o @;

__shared__: __autogen_charms__
	printf "shared"




#####################################
#				Base-26				#
#####################################
all:
__alphadef__ := a b c d e f g h i j k l m n o p q r s t u v w x y z
__bdef__ := a.tt b.al c.cc d.ef e.sx f.mt g.it h.lv i.ne j.ab k.ei l.bb m.ae n.et o.te p.ub q.ue r.dl t.rv u.sr v.ik w.lk x.vl y.bn z.ai
__fieldsdef__ := .att .bal .ccc .def .exs .fmt .git .hlv .inc .jab .kei .lbb .mae .net .ote .pub .que .rdl .trv .usr .vik .xvl .ybn .zai
__clevels__ := c cc ccc 
__FLAMES__:=__Mach_001F_001A_abcdefghijklmnopqrstuvwxyz__0x
__FNAME_L_S__ = \n__Makefile_001F_001A_\n\tabcdefghijklmnopqrstuvwxyz\n__0x\n
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> x/master

#####################################
#			Extended @				#
#####################################
__dev:=${__charms}/dev

__network:=${__cdir}/network
__bindir:=${__@}/.bin
__libsdir:=${__bindir}/libs
att:=${__network}/@source
net:=${__src}/net
__0xadir:=${__charms}/0xa
<<<<<<< HEAD
=======
>>>>>>> x/machine
=======
>>>>>>> x/master
#####################################
#				Morles				#
#####################################
server:
	@\@/server run
morles:
	cc dev/net/morles.c -o @/server
#####################################
<<<<<<< HEAD
<<<<<<< HEAD
=======
#				Shell				#
#####################################
__me:=$(shell whoami)
__host:=$(shell arch)
__cdir:=$(shell pwd)
__home:=athernet
#####################################
#			C/Directories			#
#####################################
_@:=${__cdir}/@
__dev:=${__cdir}/dev
__0xadir:=${__cdir}/0xa
__bindir:=${__cdir}/bin
__share:=${__cdir}/shared
__libsdir:=${__cdir}/libs
__charms:=${__cdir}/charms
attnet:=${__dev}/net
att:=${__share}/@source
netatt:=${att}/net
@fld:=${_@}/fld
#####################################
#				Shorts				#
#####################################
__empty:=
__binobjs:=${__bindir}/*.o
__devheaders:=${__dev}/*.h
atherlib__:=libather.so
anetlib__:=libathernet.so
atherlib:=${__libsdir}/${atherlib__}
anetlib:=${__libsdir}/${anetlib__}
#####################################
>>>>>>> x/machine
=======
>>>>>>> x/master
#				Clear				#
#####################################
clear_bin:
	if [ -d ${__bindir} ]; then rm -rf ${__bindir}; fi

clear@:
	if [ -d ${_@} ]; then rm -rf ${_@}; fi

clear_att:
<<<<<<< HEAD
<<<<<<< HEAD
	if [ -d ${__src} ]; then rm -rf ${__src}; fi
=======
	if [ -d ${att} ]; then rm -rf ${att}; fi
>>>>>>> x/machine
=======
	if [ -d ${__src} ]; then rm -rf ${__src}; fi
>>>>>>> x/master

cleared_remake:
	if [ ! -d ${__bindir} ]; then mkdir ${__bindir}; fi
	if [ ! -d ${_@} ]; then mkdir ${_@}; fi
<<<<<<< HEAD
<<<<<<< HEAD
	if [ ! -d ${__src} ]; then mkdir  ${__src}; fi
clear_common:
	# maybe should iterate over them delete &-> copy
	cp ${__devheaders} ${__src}
clean_bindir:
	if [ -d ${__bindir} ]; then rm -rf ${__bindir}; fi

clean_exits: clean_bindir
=======
	if [ ! -d ${att} ]; then mkdir  ${att}; fi
clear_common:
	# maybe should iterate over them delete &-> copy
	cp ${__devheaders} ${att}
>>>>>>> x/machine
=======
	if [ ! -d ${__src} ]; then mkdir  ${__src}; fi
clear_common:
	# maybe should iterate over them delete &-> copy
	cp ${__devheaders} ${__src}
clean_bindir:
	if [ -d ${__bindir} ]; then rm -rf ${__bindir}; fi

clean_exits: clean_bindir
>>>>>>> x/master
clear_d: clear_bin clear@ clear_att cleared_remake clear_common 
#####################################
#				@Source				#
#####################################
ternary_start: clear_d ather_start athernet_start
ather_start:  clean_libather libather
athernet_start: clean_libathernet libathernet
#####################################
#				libather			#
#####################################
<<<<<<< HEAD
<<<<<<< HEAD
lib_ather:= hbar enk ixr lbb fld
__lib_ather__=$(addprefix __,$(addsuffix __,${lib_ather}))
clean_libather: clean_hbar clean_enk clean_ixr clean_lbb
=======
lib_ather:= hbar enk idxer zenv lbb fld
__lib_ather__=$(addprefix __,$(addsuffix __,${lib_ather}))
clean_libather: clean_hbar clean_enk clean_ixr clean_zenv clean_lbb
>>>>>>> x/machine
=======
lib_ather:= hbar enk ixr lbb fld
__lib_ather__=$(addprefix __,$(addsuffix __,${lib_ather}))
clean_libather: clean_hbar clean_enk clean_ixr clean_lbb
>>>>>>> x/master
	@printf "clean :(cc): libather\n"
	if [ -f ${o_hbar} ]; then rm ${o_hbar}; fi
	if [ -f ${xer_o} ]; then rm ${xer_o}; fi
	if [ -f ${o_enk} ]; then rm ${o_enk}; fi
<<<<<<< HEAD
<<<<<<< HEAD
=======
	if [ -f ${o_zenv} ]; then rm ${o_zenv}; fi
>>>>>>> x/machine
=======
>>>>>>> x/master
	if [ -f ${o_lbb} ]; then rm ${o_lbb}; fi
	if [ -f ${atherlib} ]; then rm ${atherlib}; fi
	@printf "\n"

libather: ${__lib_ather__}
<<<<<<< HEAD
<<<<<<< HEAD
	cc -shared $(addprefix ${__bin}/,$(addsuffix .o,${lib_ather})) -o ${atherlib}
=======
	cc -shared $(addprefix ${__bindir}/,$(addsuffix .o,${lib_ather})) -o ${atherlib}
>>>>>>> x/machine
=======
	cc -shared $(addprefix ${__bin}/,$(addsuffix .o,${lib_ather})) -o ${atherlib}
>>>>>>> x/master
#####################################
#		libather - Hash bar			#
#####################################
hbar:=hbar
# file output
<<<<<<< HEAD
<<<<<<< HEAD
@hbar:=${__src}/${hbar}
__hbar:=${__src}/${hbar}
hbar__:=${__hbar}/${hbar}
hbar_c:=${__hbar}/c
hbar_h:=${__hbar}/h
o_hbar:=${__bin}/hbar.o

c_hbar:=${@charms}/${hbar}.c
_hbar:=${@charms}/headers/${hbar}.h

=======
@hbar:=${att}/${hbar}
__hbar:=${__dev}/${hbar}
hbar__:=${__hbar}/${hbar}
hbar_c:=${__hbar}/c
hbar_h:=${__hbar}/h
o_hbar:=${__bindir}/hbar.o
>>>>>>> x/machine
=======
@hbar:=${__src}/${hbar}
__hbar:=${__src}/${hbar}
hbar__:=${__hbar}/${hbar}
hbar_c:=${__hbar}/c
hbar_h:=${__hbar}/h
o_hbar:=${__bin}/hbar.o

c_hbar:=${@charms}/${hbar}.c
_hbar:=${@charms}/headers/${hbar}.h

>>>>>>> x/master
clean_hbar:
	@printf "clean :: Hash bar\n"
	if [ -f ${@hbar}.c ]; then rm ${@hbar}.c; fi
	if [ -f ${@hbar}.h ]; then rm ${@hbar}.h; fi
	@printf "\n"

__hbar__:
<<<<<<< HEAD
<<<<<<< HEAD
	cat ${hbar_h} > ${_hbar}
	cat ${hbar_c} > ${c_hbar}
	cc -c -fpic ${c_hbar} -o ${o_hbar}
#####################################
#				Indexer				#
#####################################
ixr:=ixr
# file output
# field for input
@ixr:=${__src}/${ixr}
__ixr:=${__src}/${ixr}
ixr__:=${__ixr}/${ixr}
# for fields
ixr_c:=${__ixr}/c
ixr_h:=${__ixr}/h
o_ixr:=${__bin}/${ixr}.o

c_ixr:=${@charms}/${ixr}.c
_ixr:=${@charms}/${ixr}.h
# idxer@:=${_@}/${idxer}
clean_ixr:
	@printf "clean : in/out : The ${idxer}\n"
	if [ -f ${idxer_}.c ]; then rm ${idxer_}.c; fi
	if [ -f ${idxer_}.h ]; then rm ${idxer_}.h; fi
	@printf "\n"
	if [ -d ${_idxer} ]; then rm -rf ${_idxer}; fi
	if [ -f ${xer_o} ]; then rm ${xer_o}; fi
	@printf "\n"
__ixr__: 
# 	if [ ! -d ${_idxer} ]; then mkdir -p ${_idxer}; fi
	cat ${ixr_c} > ${c_ixr}
	cat ${ixr_h} > ${_ixr}
	cc -c -fpic ${c_ixr} -o ${o_ixr}
=======
	cat ${hbar_h} > ${@hbar}.h
	cat ${hbar_c} > ${@hbar}.c
	cc -c -fpic $(addsuffix .c,${@hbar}) -o ${o_hbar}
=======
	cat ${hbar_h} > ${_hbar}
	cat ${hbar_c} > ${c_hbar}
	cc -c -fpic ${c_hbar} -o ${o_hbar}
>>>>>>> x/master
#####################################
#				Indexer				#
#####################################
ixr:=ixr
# file output
# field for input
@ixr:=${__src}/${ixr}
__ixr:=${__src}/${ixr}
ixr__:=${__ixr}/${ixr}
# for fields
ixr_c:=${__ixr}/c
ixr_h:=${__ixr}/h
o_ixr:=${__bin}/${ixr}.o

c_ixr:=${@charms}/${ixr}.c
_ixr:=${@charms}/${ixr}.h
# idxer@:=${_@}/${idxer}
clean_ixr:
	@printf "clean : in/out : The ${idxer}\n"
	if [ -f ${idxer_}.c ]; then rm ${idxer_}.c; fi
	if [ -f ${idxer_}.h ]; then rm ${idxer_}.h; fi
	@printf "\n"
	if [ -d ${_idxer} ]; then rm -rf ${_idxer}; fi
	if [ -f ${xer_o} ]; then rm ${xer_o}; fi
	@printf "\n"
__ixr__: 
# 	if [ ! -d ${_idxer} ]; then mkdir -p ${_idxer}; fi
<<<<<<< HEAD
	cat ${hidxer} > ${idxeroh}
	cat ${cidxer} > ${idxeroc}
	cc -c -fpic ${idxeroc} -o ${xer_o}
#################################
#			Zenviroment			#
#################################
zenv:=zenv
@zenv:=${att}/${zenv}
__zenv:=${__dev}/${zenv}
zenv__:=${__zenv}/${zenv}
zenv_c:=${__zenv}/c
zenv_h:=${__zenv}/h
o_zenv:=${__bindir}/zenv.o

clean_zenv:
	@printf "clean :: Z enviroment\n"
	if [ -f ${@zenv}.c ]; then rm ${@zenv}.c; fi
	if [ -f ${@zenv}.h ]; then rm ${@zenv}.h; fi
	@printf "\n"

__zenv__:
	cat ${zenv_h} > ${@zenv}.h
	cat ${zenv_c} > ${@zenv}.c
	cc -c -fpic $(addsuffix .c,${@zenv}) -o ${o_zenv}
>>>>>>> x/machine
=======
	cat ${ixr_c} > ${c_ixr}
	cat ${ixr_h} > ${_ixr}
	cc -c -fpic ${c_ixr} -o ${o_ixr}
>>>>>>> x/master
#################################
#		Little Black Book		#
#################################
lbb:=lbb
<<<<<<< HEAD
<<<<<<< HEAD
@lbb:=${__src}/${lbb}
__lbb:=${__src}/${lbb}
lbb__:=${__lbb}/${lbb}
lbb_c:=${__lbb}/c
lbb_h:=${__lbb}/h
o_lbb:=${__bin}/lbb.o

c_lbb:=${@charms}/${lbb}.c
_lbb:=${@charms}/headers/${lbb}.h
=======
@lbb:=${att}/${lbb}
__lbb:=${__dev}/${lbb}
lbb__:=${__lbb}/${lbb}
lbb_c:=${__lbb}/c
lbb_h:=${__lbb}/h
o_lbb:=${__bindir}/lbb.o
>>>>>>> x/machine
=======
@lbb:=${__src}/${lbb}
__lbb:=${__src}/${lbb}
lbb__:=${__lbb}/${lbb}
lbb_c:=${__lbb}/c
lbb_h:=${__lbb}/h
o_lbb:=${__bin}/lbb.o

c_lbb:=${@charms}/${lbb}.c
_lbb:=${@charms}/headers/${lbb}.h
>>>>>>> x/master

clean_lbb:
	@printf "clean :: Little black book\n"
	if [ -f ${@lbb}.c ]; then rm ${@lbb}.c; fi
	if [ -f ${@lbb}.h ]; then rm ${@lbb}.h; fi
	@printf "\n"

__lbb__:
<<<<<<< HEAD
<<<<<<< HEAD
	cat ${lbb_h} > ${_lbb}
	cat ${lbb_c} > ${c_lbb}
	cc -c -fpic ${c_lbb} -o ${o_lbb}
=======
	cat ${lbb_h} > ${@lbb}.h
	cat ${lbb_c} > ${@lbb}.c
	cc -c -fpic $(addsuffix .c,${@lbb}) -o ${o_lbb}
>>>>>>> x/machine
=======
	cat ${lbb_h} > ${_lbb}
	cat ${lbb_c} > ${c_lbb}
	cc -c -fpic ${c_lbb} -o ${o_lbb}
>>>>>>> x/master
#################################
#			Enkoder				#
#################################
enk:=enk
<<<<<<< HEAD
<<<<<<< HEAD
@enk:=${__src}/${enk}
__enk:=${__src}/${enk}
enk__:=${__enk}/${enk}
enk_c:=${__enk}/c
enk_h:=${__enk}/h
o_enk:=${__bin}/enk.o

c_enk:=${@charms}/${enk}.c
_enk:=${@charms}/headers/${enk}.h
=======
@enk:=${att}/${enk}
__enk:=${__dev}/${enk}
enk__:=${__enk}/${enk}
enk_c:=${__enk}/c
enk_h:=${__enk}/h
o_enk:=${__bindir}/enk.o
>>>>>>> x/machine
=======
@enk:=${__src}/${enk}
__enk:=${__src}/${enk}
enk__:=${__enk}/${enk}
enk_c:=${__enk}/c
enk_h:=${__enk}/h
o_enk:=${__bin}/enk.o

c_enk:=${@charms}/${enk}.c
_enk:=${@charms}/headers/${enk}.h
>>>>>>> x/master
clean_enk:
	@printf "clean :: Enkoding\n"
	if [ -f ${@enk}.c ]; then rm ${@enk}.c; fi
	if [ -f ${@enk}.h ]; then rm ${@enk}.h; fi
	@printf "\n"

__enk__:
<<<<<<< HEAD
<<<<<<< HEAD
	cat ${enk_h} > ${_enk}
	cat ${enk_c} > ${c_enk}
	cc -c -fpic ${c_enk} -o ${o_enk}
#################################
#			  Fields			#
#################################
fld:=fld
@fld:=${__src}/${fld}
__fld:=${__src}/${fld}
fld__:=${__fld}/${fld}
fld_c:=${__fld}/c
fld_h:=${__fld}/h
o_fld:=${__bin}/fld.o

c_fld:=${@charms}/${fld}.c
_fld:=${@charms}/${fld}.h

=======
	cat ${enk_h} > ${@enk}.h
	cat ${enk_c} > ${@enk}.c
	cc -c -fpic $(addsuffix .c,${@enk}) -o ${o_enk}
#################################
#			Y-binary			#
#################################
MAKE:=${MAKE} host-type=${__host}
__ybin:=${__dev}/ybin
3c_temp:=${att}/temp.c
ybinary: clean_ylink ybin_hash8 ybin_zcharms

clean_ylink:
	if [ -f ${3c_temp} ]; then rm -rf ${3c_temp}; fi

ybin_hash8: clean_ylink
	link ${__ybin}/hash8.c ${3c_temp}
	cc ${3c_temp} -o ${@dir}/hash_it ${atherlib}
	unlink ${3c_temp}

ybin_zcharms: clean_ylink
	link ${__ybin}/charms.c ${3c_temp}
	cc ${3c_temp} -o ${@dir}/zcharms ${atherlib}
	unlink ${3c_temp}
=======
	cat ${enk_h} > ${_enk}
	cat ${enk_c} > ${c_enk}
	cc -c -fpic ${c_enk} -o ${o_enk}
>>>>>>> x/master
#################################
#			  Fields			#
#################################
fld:=fld
@fld:=${__src}/${fld}
__fld:=${__src}/${fld}
fld__:=${__fld}/${fld}
fld_c:=${__fld}/c
fld_h:=${__fld}/h
o_fld:=${__bin}/fld.o

c_fld:=${@charms}/${fld}.c
_fld:=${@charms}/${fld}.h

<<<<<<< HEAD
libathernet: netatt fields ter_cm 
#################################
#			Ternary				#
#################################
t2:=ter
ter:=3c
ccc:=ternary
# output file
ter@:=${_@}/${t2}
#####################
#implement header file#
#####################
ter_o:=${_@}/3c.o
# field for input 
ter__:=${__dev}/${t2}
ter_c:=${ter__}/c
ter_h:=${ter__}/h
# field for output
ater:=${att}/${ccc}
ter_cm: clean_ter @ter_  
ternary:=${ter@} checkmake
clean_ter:
	@printf "Ternary UD\n"
	if [ -f ${ter@} ]; then rm ${ter@}; fi
	if [ -f ${ter_o} ]; then rm ${ter_o}; fi
	if [ -f ${ater}.c ]; then rm ${ater}.c; fi
	if [ -f ${ater}.h ]; then rm ${ater}.h; fi
	@printf "\n"

__ter__:
	cat ${ter_h} > ${ater}.h
	cat ${ter_c} > ${ater}.c
	if [ -f ${idxeroh} ]; then \
	cc ${ater}.c -o ${ter@} ${atherlib};fi

@ter_: 
	if [ -f ${ter@} ] && [ -f ${ter_o} ];\
		then \
			$(ternary); \
		else \
			$_ __ter__; \
	fi
#################################
#			  Fields			#
#################################
f3:=fld
fld:=field
field:=linked
# output files
attfld:=${att}/${fld}
#####################
#implement header file#
#####################
fld_o:=${__bindir}/${f3}.o
# field for input 
fld__:=${__dev}/${f3}
fld_c:=${fld__}/c
fld_h:=${fld__}/h
>>>>>>> x/machine
=======
>>>>>>> x/master
# field for output
fields: clean_fld __fld__
clean_fld:
	@printf "\nLinked Active Fields\n"
	if [ -f ${ter@} ]; then rm ${ter@}; fi
	if [ -f ${fld_o} ]; then rm ${fld_o}; fi
	if [ -f ${attfld}.c ]; then rm ${attfld}.c; fi
	@printf "\n"
<<<<<<< HEAD
<<<<<<< HEAD

__fld__:
	cat ${fld_h} > ${_fld}
	cat ${fld_c} > ${c_fld}
	cc -c -fpic ${c_fld} -o ${o_fld}
#################################
#		  libathernet.so		#
#################################

mach_shell:
	cc ${@charms}/fld.c -o ${shrd_fun}/mach ${atherlib}
	

libathernet: libather mach_shell
	cp ${_snet}/* ${@charms}
	cc ${@charms}/morles.c -o ${shrd_fun}/morles ${atherlib}
	${shrd_fun}/mach shell

#################################
#		 check &-> build		#
#################################
ac:= cc -c -fpic 
__mach__: clean_libather libather clean_libathernet libathernet
	
__av__: __av_cmds__ __av_net__ __av_next

__hostinfo:=$(shell uname -s) $(shell uname -n) $(shell uname -m)

ternnet_check:
	@if [ ! -d ${__dev} ]; then printf "No development directory found\n"; fi
	$_ _check_dirs

_check_dirs:
	if [ ! -d ${__charms} ]; then mkdir ${__charms}; fi 
	if [ ! -d ${_@} ]; then mkdir ${_@}; fi 
	if [ ! -d ${__network} ]; then mkdir ${__network}; fi
	$_ _check_compile

_check_compile:
	cc ${__dev}/att.c -o att
	${__cdir}/att ${__hostinfo}
=======
# 	if [ -f ${attfld}.h ]; then rm ${attfld}.h; fi
=======
>>>>>>> x/master

__fld__:
	cat ${fld_h} > ${_fld}
	cat ${fld_c} > ${c_fld}
	cc -c -fpic ${c_fld} -o ${o_fld}
#################################
#		  libathernet.so		#
#################################

mach_shell:
	cc ${@charms}/fld.c -o ${shrd_fun}/mach ${atherlib}
	

libathernet: libather mach_shell
	cp ${_snet}/* ${@charms}
	cc ${@charms}/morles.c -o ${shrd_fun}/morles ${atherlib}
	${shrd_fun}/mach shell

#################################
#		 check &-> build		#
#################################
ac:= cc -c -fpic 
__mach__: clean_libather libather clean_libathernet libathernet
	
__av__: __av_cmds__ __av_net__ __av_next

__hostinfo:=$(shell uname -s) $(shell uname -n) $(shell uname -m)

ternnet_check:
	@if [ ! -d ${__dev} ]; then printf "No development directory found\n"; fi
	$_ _check_dirs

_check_dirs:
	if [ ! -d ${__charms} ]; then mkdir ${__charms}; fi 
	if [ ! -d ${_@} ]; then mkdir ${_@}; fi 
	if [ ! -d ${__network} ]; then mkdir ${__network}; fi
	$_ _check_compile

<<<<<<< HEAD
>>>>>>> x/machine
=======
_check_compile:
	cc ${__dev}/att.c -o att
	${__cdir}/att ${__hostinfo}
>>>>>>> x/master




<<<<<<< HEAD
<<<<<<< HEAD
# \
mr. karam jaber.
>>>>>>> old_att/machine
=======




































#################################
#		 top level clean		#
#################################
clean_exits: clean_bindir

clean_bindir:
	if [ -d ${__bindir} ]; then rm -rf ${__bindir}; fi



=======
>>>>>>> x/master
# \
mr. karam jaber.
>>>>>>> x/machine
=======
>>>>>>> temp/source
