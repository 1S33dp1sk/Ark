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
@__:=${__cdir}/@
__@:=${__cdir}/.@
__bin:=${__@}/bin
__lbb:=${__@}/lbb
__lib:=${__@}/lib
__shd:=${__@}/shared
__src:=${__@}/source
@charms:=${__cdir}/@charms
@mymach:=${__cdir}/@mach
charms:$(shell cat ${@charms}/index.lbb)
#####################################
#				Shorts				#
#####################################
__empty:=
__binobjs:=${__bin}/*.o
__devheaders:=${__dev}/*.h
atherso:=libather.so
athernetso__:=libathernet.so
atherlib:=${__lib}/${atherso}
anetlib:=${__lib}/${athernetso__}

# build charms as a list and then run another
# make command to compile and then execute

__ac:=$(cc -c -fpic)
output:= -o ${@mymach} 
ac:=$(addprefix $(addsuffix $(addprefix ${__ac},${@charms}),${output}),${libather})


mk_att_dirs:
	@if [ -d ${__source} ]; \
		then __build__; if [ ! -d ${__@} ]; then mkdir ${__@}; \
		fi; if [ ! -d ${@charms_} ]; then mkdir ${@charms_};fi \
	else \
		printf "Cannot create @net without the ${__source}.\n"; return 1;\
	fi



__build__: libather
	@printf "Building charm indexer\n ${lib_ather}\n"
	cc ${@charms}/idxer.c ${output} .@/lib/atherlib.so



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
#####################################
#				Morles				#
#####################################
server:
	@\@/server run
morles:
	cc dev/net/morles.c -o @/server
#####################################
#				Clear				#
#####################################
clear_bin:
	if [ -d ${__bindir} ]; then rm -rf ${__bindir}; fi

clear@:
	if [ -d ${_@} ]; then rm -rf ${_@}; fi

clear_att:
	if [ -d ${__src} ]; then rm -rf ${__src}; fi

cleared_remake:
	if [ ! -d ${__bindir} ]; then mkdir ${__bindir}; fi
	if [ ! -d ${_@} ]; then mkdir ${_@}; fi
	if [ ! -d ${__src} ]; then mkdir  ${__src}; fi
clear_common:
	# maybe should iterate over them delete &-> copy
	cp ${__devheaders} ${__src}
clean_bindir:
	if [ -d ${__bindir} ]; then rm -rf ${__bindir}; fi

clean_exits: clean_bindir
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
lib_ather:= hbar enk idxer lbb fld
__lib_ather__=$(addprefix __,$(addsuffix __,${lib_ather}))
clean_libather: clean_hbar clean_enk clean_ixr clean_lbb
	@printf "clean :(cc): libather\n"
	if [ -f ${o_hbar} ]; then rm ${o_hbar}; fi
	if [ -f ${xer_o} ]; then rm ${xer_o}; fi
	if [ -f ${o_enk} ]; then rm ${o_enk}; fi
	if [ -f ${o_lbb} ]; then rm ${o_lbb}; fi
	if [ -f ${atherlib} ]; then rm ${atherlib}; fi
	@printf "\n"

libather: ${__lib_ather__}
	cc -shared $(addprefix ${__bindir}/,$(addsuffix .o,${lib_ather})) -o ${atherlib}
#####################################
#		libather - Hash bar			#
#####################################
hbar:=hbar
# file output
@hbar:=${__src}/${hbar}
__hbar:=${__src}/${hbar}
hbar__:=${__hbar}/${hbar}
hbar_c:=${__hbar}/c
hbar_h:=${__hbar}/h
o_hbar:=${__bin}/hbar.o

c_hbar:=${@charms}/${hbar}.c
_hbar:=${@charms}/${hbar}.h

clean_hbar:
	@printf "clean :: Hash bar\n"
	if [ -f ${@hbar}.c ]; then rm ${@hbar}.c; fi
	if [ -f ${@hbar}.h ]; then rm ${@hbar}.h; fi
	@printf "\n"

__hbar__:
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
o_ixr:=${__bin}/${ixr}.o

c_ixr:=${@charms}/${ixr}.c
_ixr:=${_idxer}.h
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
	cat ${ixr_c} > ${c_ixr}
	cc -c -fpic ${c_ixr} -o ${o_ixr}
#################################
#		Little Black Book		#
#################################
lbb:=lbb
@lbb:=${__src}/${lbb}
__lbb:=${__src}/${lbb}
lbb__:=${__lbb}/${lbb}
lbb_c:=${__lbb}/c
lbb_h:=${__lbb}/h
o_lbb:=${__bin}/lbb.o

c_ixr:=${@charms}/${lbb}.c
_ixr:=${@charms}/${lbb}.h

clean_lbb:
	@printf "clean :: Little black book\n"
	if [ -f ${@lbb}.c ]; then rm ${@lbb}.c; fi
	if [ -f ${@lbb}.h ]; then rm ${@lbb}.h; fi
	@printf "\n"

__lbb__:
	cat ${lbb_h} > ${_ixr}
	cat ${lbb_c} > ${c_ixr}
	cc -c -fpic ${c_ixr} -o ${o_lbb}
#################################
#			Enkoder				#
#################################
enk:=enk
@enk:=${__src}/${enk}
__enk:=${__src}/${enk}
enk__:=${__enk}/${enk}
enk_c:=${__enk}/c
enk_h:=${__enk}/h
o_enk:=${__bin}/enk.o

c_enk:=${@charms}/${enk}.c
_enk:=${@charms}/${enk}.h
clean_enk:
	@printf "clean :: Enkoding\n"
	if [ -f ${@enk}.c ]; then rm ${@enk}.c; fi
	if [ -f ${@enk}.h ]; then rm ${@enk}.h; fi
	@printf "\n"

__enk__:
	cat ${enk_h} > ${_enk}
	cat ${enk_c} > ${c_enk}
	cc -c -fpic ${c_enk} -o ${o_enk}
#################################
#			Y-ternary			#
#################################


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
	cp ${__dev}/net/*.h ${net}


libathernet: netatt fields ter_cm 
#################################
#			Ternary				#
#################################
t2:=ter
ter:=3c
ccc:=ternary
# output file
ter@:=${__@}/${t2}
#####################
#implement header file#
#####################
ter_o:=${_@}/3c.o
# field for input 
ter__:=${__dev}/${t2}
ter_c:=${ter__}/c
ter_h:=${ter__}/h
# field for output
ater:=${__src}/${ccc}
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
#################################
fld:=fld
@fld:=${__src}/${fld}
__fld:=${__src}/${fld}
fld__:=${__enk}/${fld}
fld_c:=${__enk}/c
fld_h:=${__enk}/h
o_fld:=${__bin}/fld.o

c_enk:=${@charms}/${fld}.c
_enk:=${@charms}/${fld}.h

# field for output
fields: clean_fld __fld__
clean_fld:
	@printf "\nLinked Active Fields\n"
	if [ -f ${ter@} ]; then rm ${ter@}; fi
	if [ -f ${fld_o} ]; then rm ${fld_o}; fi
	if [ -f ${attfld}.c ]; then rm ${attfld}.c; fi
	@printf "\n"

__fld__:
	cat ${fld_h} > ${c_enk}
	cat ${fld_c} > ${_enk}
	cc -c -fpic ${c_enk} -o ${o_fld}
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




# \
mr. karam jaber.