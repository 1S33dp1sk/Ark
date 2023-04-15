#
#####################################
#			  Base-26				#
#####################################
all:
__alphdef__:=a b c d e f g h i j k l m n o p q r s t u v w x y z
__bindef__:=a.tt b.al c.cc d.ef e.sx f.mt g.it h.lv i.ne j.ab k.ei l.bb m.ae n.et o.te p.ub q.ue r.dl t.rv u.sr v.ik w.lk x.vl y.bn z.ai
__terdef__:=.att .bal .ccc .def .exs .fmt .git .hlv .inc .jab .kei .lbb .mae .net .ote .pub .que .rdl .trv .usr .vik .xvl .ybn .zai
__clevels__:=c cc ccc 
__FLAMES__:=__Mach_001A_abcdefghijklmnopqrstuvwxyz__0x
__FNAME_L_S__=\n__Makefile__
#####################################
#			   Shell				#
#####################################
__me:=$(shell whoami)
__host:=$(shell arch)
__cdir:=$(shell pwd)
#####################################
#		  	Base-source				#
#####################################
@Ark:=${__cdir}
@SOURCE:=${__cdir}/@source
@mods:=${__cdir}/mods
@__:=${__cdir}/@
__@:=${__cdir}/.@
@k512:=${__@}/k512
__mods:=${__@}/mods
__viks:=${__@}/viks
__arcd:=${__@}/arc.d
#####################################
#			Charms@d.*  			#
#####################################
@charms:=${@__}charms
#lbb_att
lbb@charms:=${@charms}/d.lbb 
#headers_att
out@charms:=${@charms}/d.out
#source_att
src@charms:=${@charms}/d.src
#objects_att
# obj@charms:=${@charms}/d.obj
#libraries_att
# lib@charms:=${@charms}/d.lib
#executables_att
run@charms:=${@charms}/d.run
#contracts_att
# sol@charms:=${@charms}/d.sol
#variables_att
var@charms:=${@charms}/d.var
#misc_att
exs@charms:=${@charms}/executables
#header files : .h
# headers@d:=${src@charms}/headers
#compile files : .c
compile@d:=${src@charms}/compile
#####################################
#			Shortcuts				#
#####################################
__empty:=
source_nop:=227
all_objects:=${out@charms}/*.o
ccstd_headers:=${__src}/k512/
lock@charms:=${lbb@charms}/.lbb
aetherso:=libaether.so
ac:=cc -c -fpic
aetherlib:=${out@charms}/${aetherso}
output:= -o ${@mymach} 
ac_out:=$(addprefix $(addsuffix $(addprefix ${__ac},${@charms}),${output}),${libaether})
all: clean charms
karch: build_3c
rebuild: clean charms 
clean: __clean_charms__
#####################################
#			Executables@			#
#####################################
ark_o:=${out@charms}/ARK.o
ark@k512:=${@k512}/ARK
src_ark:=${src@charms}/ark.c
k512_d:=${@k512}/ark
arc_k512:=${@k512}/__ark
h512@src:=${src@charms}/h512
d@h512:=${h512@src}/d
ark@src:=${src@charms}/ark
headers@src:=${src@charms}/headers
k512_utypes:=${src@charms}/utypes.h
k512_standard:=${src@charms}/standard.h
k512_header:=${src@charms}/k_arch512.h
@arch:=@${__host}
karch_build:=${@1c}/k512${@arch}
cloud_d_build:=${@1c}/d-cloud${@arch}
fields_build:=${@1c}/flds${@arch}
#####################################
#			 Objectify				#
#####################################
types_o:=${out@charms}/types.o
standards_o:=${out@charms}/standards.o
k512arch_o:=${out@charms}/karc_512h.o
#####################################
#			 Charms 				#
#####################################
__base_at:=k512 mods
base_at:=$(addprefix ${__base_at}, ${__cdir})
mv_basis:=$(foreach __, ${__base_at}, mv ${__} ${__@})
basic:= $(__atdir) $(mv_basis)
__atdir:
	if [ ! -d ${__@} ];\
		then mkdir ${__@};\
			fi;
#f gorgeous.
# @charms !exist ? init
# Lockfile exists ? link
# @charms exists BUT not initialzied? att
charms:
	if [ -d ${@SOURCE} ]; \
		then mv ${@SOURCE} ${__@}; \
	elif [[ -d ${@k512} && -d ${@mods} ]]; \
		then ${basic};\
	elif [ ! -d ${__@} ]; \
		then printf "\nCannot create d-cloud without the source code. path :: ${__@}.\n"; return ${source_nop};\
	else \
		if [ ! -d ${@charms} ]; \
			then $_ _check_charms_; \
		elif [ -f ${lock@charms} ]; \
			then $_ __link__; \
		else \
			$_ __lock__; \
		fi;\
	fi;
#################################
#			  ARK   			#
#################################
ark_prgs:=ark cloud points program platform
install:
	if [ -d ${out@charms} ]; then if [ -f ${out@charms}/ARK ]; then \
	sudo cp ${out@charms}/ARK /usr/bin/@; fi; fi;
# 	if [ -d ${@charms} ]; then sudo cp -r ../Ark/@charms ///Ark; fi;

#source
_ark_in:
	echo "#include \"k_arch512.h"\" > ${c_lbb}
	cc ${src@charms}/ark.c -o ${out@charms}/ark.o ${aetherlib}

_ark_out:
	cc ${src@charms}/ark.c -o @ ${aetherlib}

ark_intro:
	@printf "\n{{{{{{{{{ARK}}}}}}}}}\n"

__ark__:  
	cc -c -fpic ${src@charms}/ark.c -o ${out@charms}/ark.o

ARK: ark_intro _ark_in _ark_out
# 	./ARK ${ark@src}/points
#	points
#################################
#			libaether			#
#################################
_aether_:=ark lbb ixr atp
__aether__:=$(addprefix __,$(addsuffix __,${_aether_}))

clean_libather: clean_lbb clean_ixr clean_atp
	@printf "clean :(cc): libather\n"
	if [ -f ${o_lbb} ]; then rm ${o_lbb}; fi
	if [ -f ${o_ixr} ]; then rm ${o_ixr}; fi
	if [ -f ${o_atp} ]; then rm ${o_atp}; fi
	if [ -f ${aetherlib} ]; then rm ${aetherlib}; fi
	@printf "\n"
_lib_:=karc_512h types standards
__lib_aether__: $(__aether__)
	cc -shared $(addprefix ${out@charms}/,$(addsuffix .o,${_aether_})) -o ${aetherlib}
la_intro:
	@printf "\n{AETHER}\n"

libaether: la_intro __k512_objects __lib_aether__ __ld_out 
#################################
#		Linked Binary Book		#
#################################
lbb:=lbb
lbb__:=${@k512}/${lbb}
lbb_c:=${lbb__}/${lbb}.c
lbb_h:=${lbb__}/${lbb}.h
o_lbb:=${out@charms}/${lbb}.o
c_lbb:=${src@charms}/${lbb}.c
_lbb:=${headers@src}/${lbb}.h
__lbb:=${src@charms}/${lbb}
clean_lbb:
	if [ -f ${c_lbb} ]; then rm ${c_lbb}; fi
	@printf "\n"
__lbb__:
	@printf "d.out@ 'Linked Binary Book' {lbb}\n"
	echo "#include \"k_arch512.h"\" > ${c_lbb}
	cat ${lbb_c} >> ${c_lbb}
	${ac} ${c_lbb} -o ${o_lbb}

in_lbb: __lbb__ clean_lbb
#####################################
#				Indexer				#
#####################################
ixr:=ixr
ixr__:=${@k512}/${ixr}
ixr_c:=${ixr__}/${ixr}.c
ixr_h:=${ixr__}/${ixr}.h
o_ixr:=${out@charms}/${ixr}.o
c_ixr:=${src@charms}/${ixr}.c
_ixr:=${headers@src}/${ixr}.h
__ixr:=${src@charms}/${ixr}
clean_ixr:
	if [ -f ${c_ixr} ]; then rm ${c_ixr}; fi
	@printf "\n"
__ixr__: 
	@printf "d.out@ 'The Indexer' {ixr}\n"
	echo "#include \"k_arch512.h"\" > ${c_ixr}
	cat ${ixr_c} >> ${c_ixr}
	${ac} ${c_ixr} -o ${o_ixr}

in_ixr:__ixr__ clean_ixr
#####################################
#	 		 @-Protocol 			#
#####################################
atp:=atp
atp__:=${@k512}/${atp}
atp_a:=${atp__}/anet.h
atp_m:=${atp__}/mor.h
atp_l:=${atp__}/les.h
atp_c:=${atp__}/${atp}.c
atp_h:=${atp__}/${atp}.h
o_atp:=${out@charms}/${atp}.o
c_atp:=${src@charms}/${atp}.c
_atp:=${headers@src}/${atp}.h
__atp:=${src@charms}/${atp}
clean_atp:
	if [ -f ${c_atp} ]; then rm ${c_atp}; fi
	@printf "\n"
__atp__:
	@printf "d.out@ 'Aether Transfer (@-Protocol)' {atp}\n"
	echo "#include \"k_arch512.h"\" > ${c_atp}
	cat ${atp_c} >> ${c_atp}
	${ac} ${c_atp} -o ${o_atp}

in_atp: __atp__ clean_atp
#################################
#			   MODS   			#
#################################
# aeth_version=2
#chmod u-x ${__aeth}//*;
#chmod u-x ${__alph}//*;
#chmod u-x ${__alph}//*;
# $(foreach mod, $(addprefix mod_, ${mod}), $(mod))

_mods_:=aeth alph intr
__mods__:=$(addprefix mod_, ${_mods_})

alph:=alias
__alph:=${__mods}/${alph}
alph__:=${run@charms}/${alph}
alph_lbb:=${alph__}/_v1/lbb
_alph_:=${alph__}/__alph__


aeth:=aether
__aeth:=${__mods}/${aeth}
aeth__:=${run@charms}/${aeth}
aeth_py:=${aeth__}/_v1/py
aeth_js:=${aeth__}/_v1/js
aeth_sh:=${aeth__}/_v1/sh
_aeth_:=${aeth__}/__aeth__


intr:=interpreter
__intr:=${__mods}/${intr}
intr__:=${run@charms}/${intr}
_intr_:=${intr__}/__intr__

mod_intr:
	@if [ ! -d ${__intr} ]; then printf "err: !intr.d\n"&return 2;fi;
	@if [ -d ${intr__} ]; then printf "err: ${intr}&->!0\n"; fi;
	mkdir ${intr__}; cp -r ${__intr}/* ${intr__};
	chmod u+x ${intr__}//*;

mod_alph:
	@if [ ! -d ${__alph} ]; then printf "err: !alph.d\n"&return 2;fi;
	@if [ -d ${alph__} ]; then printf "err: ${alph}&->!0\n"; fi;
	mkdir ${alph__}; cp -r ${__alph}/* ${alph__};
	chmod u+x ${alph__}//*;

mod_aeth:
	@if [ ! -d ${__aeth} ]; then printf "err: !aeth.d\n"&return 2; fi;
	@if [ -d ${aeth__} ]; then printf "err: ${aeth}&->!0"; fi;
	mkdir ${aeth__}; cp -r ${__aeth}/* ${aeth__};
	chmod u+rwx ${aeth__}//*;

mods_intro:
	@printf "\n{MODS}\n"

_mods:
	cp -r ${__mods}//* ${@charms}/d.run
	chmod u+x ${run@charms}//*
# $(__mods__)
mods_init: mods_intro _mods
#################################
#		  Packaging(3C)		    #
#################################
__h512_headers=$(addprefix ${@k512}/, *.h)
h512_headers:=standard utypes _h512
__d__arc=$(addprefix $(addprefix ${arc_k512}/, $(addsuffix *, __)), .h)
d_files:=file lang log main string hash koder
_lbb_ld_h:=${__lbb}${@arch}.h
lbb_ld:=${out@charms}/lbb${@arch}.ld
_ixr_ld_h:=${__ixr}${@arch}.h
ixr_ld:=${out@charms}/ixr${@arch}.ld
_atp_ld_h:=${__atp}${@arch}.h
atp_ld:=${out@charms}/atp${@arch}.ld



__ccc_dirs__:
	if [ ! -d ${@charms} ]; then mkdir ${@charms}; fi;
	if [ ! -d ${lbb@charms} ]; then mkdir ${lbb@charms}; fi
	if [ ! -d ${src@charms} ]; then mkdir ${src@charms}; fi
	if [ ! -d ${out@charms} ]; then mkdir ${out@charms}; fi
	if [ ! -d ${run@charms} ]; then mkdir ${run@charms}; fi
	if [ ! -d ${sol@charms} ]; then mkdir ${sol@charms}; fi

__clean_charms__:
	if [ -d ${@charms} ]; then rm -rf ${@charms}; fi
	if [ -f temp ]; then rm -rf temp; fi
	if [ -f temp.* ]; then rm -rf temp.*; fi
	if [ -f draft ]; then rm -rf draft; fi


__k512_objects:
	cc ${k512_utypes} -o ${types_o}
	cc ${k512_standard} -o ${standards_o}
	cc ${k512_header} -o ${k512arch_o}


__ld_out:
	echo "#include \"k_arch512.h"\" > ${_lbb_ld_h}
	cat ${_lbb} >> ${_lbb_ld_h}
	cc ${_lbb_ld_h} -o ${lbb_ld}
	rm ${_lbb_ld_h}
	echo "#include \"k_arch512.h"\" > ${_ixr_ld_h}
	cat ${_ixr} >> ${_ixr_ld_h}
	cc ${_ixr_ld_h} -o ${ixr_ld}
	rm ${_ixr_ld_h}
	echo "#include \"k_arch512.h"\" > ${_atp_ld_h}
	cat ${_atp} >> ${_atp_ld_h}
	cc ${_atp_ld_h} -o ${atp_ld}
	rm ${_atp_ld_h}


# when rebuilding source clean
_check_source_: __clean_charms__
	@if [ -d ${__@} ]; then if [ ! -d ${@charms} ]; then $_ _check_charms_;fi; fi


_3c_check:
	if [ ! -d ${@charms} ]; then return 2; fi

_check_charms_: \
	build_3c\
	mods_init\
	libaether\
	ARK\
	outro

outro:
	@printf "\nWelcome to (d-☁️.io)\n"


build_3c: __ccc_dirs__
	if [ ! -d ${headers@src} ]; then mkdir ${headers@src}; fi
	cp ${__h512_headers} ${src@charms}
	cp ${ark@k512} ${src_ark}
	cat ${lbb_h} > ${_lbb}
	cat ${ixr_h} > ${_ixr}
	cat ${atp_h} > ${_atp}
	if [ ! -d ${ark@src} ]; then mkdir ${ark@src}; fi
	cp ${__d__arc} ${ark@src}
	cp ${@k512}/__karch__  ${src@charms}/k_arch512.h


package:
	if [ -d ${__cdir}/package ]; then rm -rf ${__cdir}/package; fi
	if [ -f ${__cdir}/package.zip ]; then rm -rf ${__cdir}/package.zip; fi
	mkdir -p ${__cdir}/package/@source
	cp -r ${__@}/* ${__cdir}/package/@source
	cp ${__cdir}/Makefile ${__cdir}/package
	zip -r package.zip package/*
	rm -rf package 
# #################################
# #			Hash Bar			#
# #################################
# hbar:=hbar
# hbar__:=${__k512}/${hbar}
# hbar_c:=${hbar__}/c
# hbar_h:=${hbar__}/h
# o_hbar:=${out@charms}/${hbar}.o
# c_hbar:=${src@charms}/${hbar}.c
# _hbar:=${headers@src}/${hbar}.h
# clean_hbar:
# 	if [ -f ${c_hbar} ]; then rm ${c_hbar}; fi
# 	@printf "\n"
# __hbar__:
# 	@printf "d.out@ 'Hash bar' {hbar}\n"
# 	echo "#include \"k_arch512.h"\" > ${c_hbar}
# 	cat ${_hbar} >> ${c_hbar}
# 	cat ${hbar_c} >> ${c_hbar}
# 	${ac} ${c_hbar} -o ${o_hbar} 

# #only creates the object files
# __hbar: __hbar__ clean_hbar


# #################################
# #			Enkoder				#
# #################################
# enk:=enk
# enk__:=${__k512}/${enk}
# enk_c:=${enk__}/c
# enk_h:=${enk__}/h
# o_enk:=${out@charms}/${enk}.o
# c_enk:=${src@charms}/${enk}.c
# _enk:=${headers@src}/${enk}.h
# clean_enk:
# 	if [ -f ${c_enk} ]; then rm ${c_enk}; fi
# 	@printf "\n"
# __enk__:
# 	@printf "d.out@ 'Encoder' {enk}\n"
# 	echo "#include \"k_arch512.h"\" > ${c_enk}
# 	cat ${_enk} >> ${c_enk}
# 	cat ${enk_c} >> ${c_enk}
# 	${ac} ${c_enk} -o ${o_enk}

# __enk: __enk__ clean_enk







#################################
#			  NET				#
#################################
net:=net
net__:=${__src}/${net}
o_net:=${obj@charms}/${net}.o
ml_net:=${headers@d}/morles.c
_net:=${headers@d}/${net}.h

# field for output
clean_net:
	if [ -f ${ml_net} ]; then rm ${ml_net}; fi
	@printf "\n"
__net__:
	@printf "d.out@ 'Aethernet' {net}\n"
	cp ${_net} ${ml_net}
	${ac} ${ml_net} -o ${o_net}

__net: __net clean_net

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

clean_dexec: __clean_charms__
	if [ -f d-atp ]; then rm -rf d-atp; fi
	if [ -f d-cld ]; then rm -rf d-cld; fi
	if [ -f d-lbb ]; then rm -rf d-lbb; fi
	if [ -f d-pts ]; then rm -rf d-pts; fi
	if [ -f d-prg ]; then rm -rf d-prg; fi

clean_exits: clean_bindir
clear_d: clear_bin clear@ clear_att cleared_remake clear_common 
#####################################
#				@Source				#
#####################################
ternary_start: clear_d ather_start athernet_start
ather_start:  clean_libather libather
athernet_start: clean_libathernet libathernet

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


#tests
3c_test:
	cc ${src@charms}/atp.2c.ark -o ${out@charms}/d-atp${@arch} ${atherlib}
	cp ${out@charms}/d-atp${@arch} cc@d-atp
	cc ${src@charms}/cld.2c.ark -o ${out@charms}/d-cld${@arch} ${atherlib}
	cp ${out@charms}/d-cld${@arch} cc@d-cld
	cc ${src@charms}/lbb.2c.ark -o ${out@charms}/d-lbb${@arch} ${atherlib}
	cp ${out@charms}/d-lbb${@arch} cc@d-lbb
	cc ${src@charms}/pts.2c.ark -o ${out@charms}/d-pts${@arch} ${atherlib}
	cp ${out@charms}/d-pts${@arch} cc@d-pts
	cc ${src@charms}/prg.2c.ark -o ${out@charms}/d-prg${@arch} ${atherlib}
	cp ${out@charms}/d-prg${@arch} cc@d-prg




























































# \
mr. karam jaber.