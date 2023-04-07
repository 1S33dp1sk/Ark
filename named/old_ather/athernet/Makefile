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
@SOURCE:=${__cdir}/@source
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
	@if [ -d ${@SOURCE} ]; \
		then mv ${@SOURCE} ${__@}; fi
	if [ ! -d ${@charms} ]; \
		then $_ __init__; \
	else \
		if [ -f "Lockfile" ]; \
			then $_ __link__; \
		else \
			$_ __att__; \
		fi;\
	fi;

clean: __clean_charms__
	if [ -f arc ]; then rm -rf arc; fi
	if [ -f Lockfile ]; then rm -rf Lockfile; fi

rebuild: clean charms 

package:
	if [ -d ${__cdir}/package ]; then rm -rf ${__cdir}/package; fi
	if [ -f ${__cdir}/package.zip ]; then rm -rf ${__cdir}/package.zip; fi
	mkdir -p ${__cdir}/package/@source
	cp -r ${__@}/* ${__cdir}/package/@source
	cp ${__cdir}/Makefile ${__cdir}/package
	zip -r ${__cdir}/package.zip ${__cdir}/package/*
	rm -rf ${__cdir}/package




# .lbb exists ? __link__
# charm exsists ? __att__
# neither exsists? __init__

shell_att:$(shell ${@__})

__att__:
	./lbb start


__link__:
	cc ${__src}/net/morles.c -o anet
	./anet

__clean_charms__:
	if [ -d ${@charms} ]; then rm -rf ${@charms}; fi


# when rebuilding source clean
_check_source_: __clean_charms__
	@if [ -d ${__@} ]; \
		then if [ ! -d ${@charms} ]; then $_ _check_charms_;fi \
	else \
		printf "Cannot create @net without the source code. path :: ${__@}.\n"; return 1;\
	fi



# must produce a charm file
__init__: _check_charms_









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
lbb_att:=${@charms}/lbb
fun_headers:=${headers_att}/fun

__ccc_dirs__:
	if [ ! -d ${@charms} ]; then mkdir ${@charms}; fi;
	if [ ! -d ${headers_att} ]; then mkdir ${headers_att}; fi
	if [ ! -d ${fun_headers} ]; then mkdir ${fun_headers}; fi
	if [ ! -d ${lbb_att} ]; then mkdir ${lbb_att}; fi

__ccstd_headers__:
	cp ${__src}/_h512.h ${headers_att}
	cp ${__src}/standard.h ${headers_att}
	cp ${__src}/utypes.h ${headers_att}

__ccc_headers__:
	cat ${hbar_h} > ${_hbar}
	cat ${hbar_c} >> ${_hbar}
	cat ${enk_h} > ${_enk}
	cat ${enk_c} >> ${_enk}
	cat ${lbb_h} > ${_lbb}
	cat ${lbb_c} >> ${_lbb}

__Karch512__:
	cp ${__src}/karc.c ${fun_headers}
	cc ${fun_headers}/karc.c -o arc

_check_charms_: __ccc_dirs__ __ccstd_headers__ __ccc_headers__ __Karch512__

	



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
lib_ather:= hbar enk ixr lbb fld
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
	cc -shared $(addprefix ${__bin}/,$(addsuffix .o,${lib_ather})) -o ${atherlib}
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
_hbar:=${@charms}/headers/${hbar}.h

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

c_lbb:=${@charms}/${lbb}.c
_lbb:=${@charms}/headers/${lbb}.h

clean_lbb:
	@printf "clean :: Little black book\n"
	if [ -f ${@lbb}.c ]; then rm ${@lbb}.c; fi
	if [ -f ${@lbb}.h ]; then rm ${@lbb}.h; fi
	@printf "\n"

__lbb__:
	cat ${lbb_h} > ${_lbb}
	cat ${lbb_c} > ${c_lbb}
	cc -c -fpic ${c_lbb} -o ${o_lbb}
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
_enk:=${@charms}/headers/${enk}.h
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

# field for output
fields: clean_fld __fld__
clean_fld:
	@printf "\nLinked Active Fields\n"
	if [ -f ${ter@} ]; then rm ${ter@}; fi
	if [ -f ${fld_o} ]; then rm ${fld_o}; fi
	if [ -f ${attfld}.c ]; then rm ${attfld}.c; fi
	@printf "\n"

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




# \
mr. karam jaber.