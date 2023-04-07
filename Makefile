<<<<<<< HEAD
<<<<<<< HEAD
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

=======
misc:
	cc @source/misc.c -o shared/programs/misc ./shared/libather.so
	./shared/programs/misc
	
nothing:

# `run()`ing compile will create a new version of whatever is getting \
compiled because.
running:
	$_ run_check

run_anet:
	./shared/programs/athernet

run_kurl:
	./shared/programs/kurl

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




kmachid: libathernet  
	__mhid

__av_cmds__: 
	@\@/ter env

ac:= cc -c -fpic 



__mhid: __av_cmds__ __av_netf__ __av_next
	__mach__ 

>>>>>>> x/machine




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
=======
>>>>>>> x/machine
#####################################
#				Morles				#
#####################################
server:
	@\@/server run
morles:
	cc dev/net/morles.c -o @/server
#####################################
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
#				Clear				#
#####################################
clear_bin:
	if [ -d ${__bindir} ]; then rm -rf ${__bindir}; fi

clear@:
	if [ -d ${_@} ]; then rm -rf ${_@}; fi

clear_att:
<<<<<<< HEAD
	if [ -d ${__src} ]; then rm -rf ${__src}; fi
=======
	if [ -d ${att} ]; then rm -rf ${att}; fi
>>>>>>> x/machine

cleared_remake:
	if [ ! -d ${__bindir} ]; then mkdir ${__bindir}; fi
	if [ ! -d ${_@} ]; then mkdir ${_@}; fi
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
lib_ather:= hbar enk ixr lbb fld
__lib_ather__=$(addprefix __,$(addsuffix __,${lib_ather}))
clean_libather: clean_hbar clean_enk clean_ixr clean_lbb
=======
lib_ather:= hbar enk idxer zenv lbb fld
__lib_ather__=$(addprefix __,$(addsuffix __,${lib_ather}))
clean_libather: clean_hbar clean_enk clean_ixr clean_zenv clean_lbb
>>>>>>> x/machine
	@printf "clean :(cc): libather\n"
	if [ -f ${o_hbar} ]; then rm ${o_hbar}; fi
	if [ -f ${xer_o} ]; then rm ${xer_o}; fi
	if [ -f ${o_enk} ]; then rm ${o_enk}; fi
<<<<<<< HEAD
=======
	if [ -f ${o_zenv} ]; then rm ${o_zenv}; fi
>>>>>>> x/machine
	if [ -f ${o_lbb} ]; then rm ${o_lbb}; fi
	if [ -f ${atherlib} ]; then rm ${atherlib}; fi
	@printf "\n"

libather: ${__lib_ather__}
<<<<<<< HEAD
	cc -shared $(addprefix ${__bin}/,$(addsuffix .o,${lib_ather})) -o ${atherlib}
=======
	cc -shared $(addprefix ${__bindir}/,$(addsuffix .o,${lib_ather})) -o ${atherlib}
>>>>>>> x/machine
#####################################
#		libather - Hash bar			#
#####################################
hbar:=hbar
# file output
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
clean_hbar:
	@printf "clean :: Hash bar\n"
	if [ -f ${@hbar}.c ]; then rm ${@hbar}.c; fi
	if [ -f ${@hbar}.h ]; then rm ${@hbar}.h; fi
	@printf "\n"

__hbar__:
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
#####################################
#				Indexer				#
#####################################
ir:=ixr
ixr:=idxer
idxer:=indexer
# file output
xer_o:=${__bindir}/${ixr}.o
# field for input
@idxer:=${__dev}/${ir}
cidxer:=${@idxer}/c
hidxer:=${@idxer}/h
# field for output
_idxer:=${att}/${ixr}
# for fields
idxer_:=${_idxer}/${idxer}
idxeroc:=${_idxer}.c
idxeroh:=${_idxer}.h
# idxer@:=${_@}/${idxer}
clean_ixr: clean_idxer clean_indexer
clean_idxer:
	@printf "clean : out : The ${idxer}\n"
	if [ -f ${idxer_}.c ]; then rm ${idxer_}.c; fi
	if [ -f ${idxer_}.h ]; then rm ${idxer_}.h; fi
	@printf "\n"
clean_indexer:
	@printf "clean : in : The ${idxer}\n"
	if [ -d ${_idxer} ]; then rm -rf ${_idxer}; fi
	if [ -f ${xer_o} ]; then rm ${xer_o}; fi
	@printf "\n"
__idxer__: 
# 	if [ ! -d ${_idxer} ]; then mkdir -p ${_idxer}; fi
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
#################################
#		Little Black Book		#
#################################
lbb:=lbb
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

clean_lbb:
	@printf "clean :: Little black book\n"
	if [ -f ${@lbb}.c ]; then rm ${@lbb}.c; fi
	if [ -f ${@lbb}.h ]; then rm ${@lbb}.h; fi
	@printf "\n"

__lbb__:
<<<<<<< HEAD
	cat ${lbb_h} > ${_lbb}
	cat ${lbb_c} > ${c_lbb}
	cc -c -fpic ${c_lbb} -o ${o_lbb}
=======
	cat ${lbb_h} > ${@lbb}.h
	cat ${lbb_c} > ${@lbb}.c
	cc -c -fpic $(addsuffix .c,${@lbb}) -o ${o_lbb}
>>>>>>> x/machine
#################################
#			Enkoder				#
#################################
enk:=enk
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
clean_enk:
	@printf "clean :: Enkoding\n"
	if [ -f ${@enk}.c ]; then rm ${@enk}.c; fi
	if [ -f ${@enk}.h ]; then rm ${@enk}.h; fi
	@printf "\n"

__enk__:
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
#################################
#		  libathernet.so		#
#################################
clean_libathernet: clean_netatt clean_fld clean_ter

clean_netatt:
	@printf "clean ::: @net\n"
	if [ -d ${netatt} ]; then rm -rf ${netatt}; fi
	@printf "\n"

netatt:
	if [ ! -d ${netatt} ]; then mkdir ${netatt}; fi
	cp ${attnet}/*.h ${netatt}


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
# field for output
fields: clean_fld __fld__
clean_fld:
	@printf "\nLinked Active Fields\n"
	if [ -f ${ter@} ]; then rm ${ter@}; fi
	if [ -f ${fld_o} ]; then rm ${fld_o}; fi
	if [ -f ${attfld}.c ]; then rm ${attfld}.c; fi
	@printf "\n"
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

__fld__:
	cat ${fld_h} > ${attfld}.h
	cat ${fld_c} > ${attfld}.c
	cc -c -fpic $(addsuffix .c,${attfld}) -o ${fld_o}
	cc $(addsuffix .c,${attfld}) -o ${@fld} 
#################################
#		 check &-> build		#
#################################







>>>>>>> x/machine




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



# \
mr. karam jaber.
>>>>>>> x/machine
