# 
#####################################
#				shell				#
#####################################
__me:=$(shell whoami)
__host:=$(shell arch)
__cdir:=$(shell pwd)
__home:=@net
#####################################
#			@directories			#
#####################################
@SOURCE:=${__cdir}/@source
@__:=${__cdir}/@
__@:=${__cdir}/.@
__bin:=${__@}/bin
__lib:=${__@}/lib
__shd:=${__@}/shared
__tst:=${__@}/tests
shrd_fun:=${__shd}/funcs
shrd_pge:=${__shd}/pages
shrd_ipr:=${__shd}/intrpt
__src:=${__@}/source
@charms:=${__cdir}/@charms
lock@charms:=${@charms}/Lockfile #contains udef hdrs
#lbb_att
lbb@charms:=${@charms}/lbb #contains udef files
#headers_att
head@charms:=${@charms}/headers
#objects_att
obj@charms:=${@charms}/objects
#libraries_att
lib@charms:=${@charms}/libraries
#executables_att
exs@charms:=${@charms}/executables
#####################################
#			executables@			#
#####################################
@arch:=@${__host}
karch_512_build:=${@1c}/k512${@arch}
cloud_d_build:=${@1c}/d-cloud${@arch}
fields_build:=${@1c}/flds${@arch}
#####################################
#				Shorts				#
#####################################
__empty:=
all_objects:=${obj@charms}/*.o
ccstd_headers:=${__src}/karch_512/*.h
atherso:=libather.so
atherlib:=${lib@charms}/${atherso}
output:= -o ${@mymach} 
ac_out:=$(addprefix $(addsuffix $(addprefix ${__ac},${@charms}),${output}),${libather})
#####################################
#				Charms				#
#####################################

all: clean charms charms charms build_3c

#f gorgeous.
# @charms !exist ? __init__
# Lockfile exists ? __link__
# @charms exists BUT not initialzied? __att__
charms:
	@if [ -d ${@SOURCE} ]; \
		then mv ${@SOURCE} ${__@};\
	elif [ ! -d ${__@} ]; \
		then printf "Cannot create d-cloud without the source code. path :: ${__@}.\n"; \
	else \
		if [ ! -d ${@charms} ]; \
			then $_ __init__; \
		elif [ -f ${lock@charms} ]; \
			then $_ __link__; \
		else \
			$_ __att__; \
		fi;\
	fi;

clean: __clean_charms__
	if [ -f d-atp ]; then rm -rf d-atp; fi
	if [ -f d-cld ]; then rm -rf d-cld; fi
	if [ -f d-lbb ]; then rm -rf d-lbb; fi


rebuild: clean charms 

# must product a `@charms` directory
__init__: _check_charms_

__clean_charms__:
	if [ -d ${@charms} ]; then rm -rf ${@charms}; fi

# when rebuilding source clean
_check_source_: __clean_charms__
	@if [ -d ${__@} ]; \
		then if [ ! -d ${@charms} ]; then $_ _check_charms_;fi \
	else \
		
	fi

#################################
#			libather			#
#################################
lib_ather:= hbar lbb enk atp
__lib_ather__=$(addprefix __,$(addsuffix __,${lib_ather}))
clean_libather: clean_hbar clean_enk clean_lbb
	@printf "clean :(cc): libather\n"
	if [ -f ${o_hbar} ]; then rm ${o_hbar}; fi
	if [ -f ${xer_o} ]; then rm ${xer_o}; fi
	if [ -f ${o_enk} ]; then rm ${o_enk}; fi
	if [ -f ${o_lbb} ]; then rm ${o_lbb}; fi
	if [ -f ${atherlib} ]; then rm ${atherlib}; fi
	@printf "\n"

libather: ${__lib_ather__}
	cc -shared $(addprefix ${obj@charms}/,$(addsuffix .o,${lib_ather})) -o ${atherlib}

__charms_dirs__:
	if [ ! -d ${@charms} ]; then mkdir ${@charms}; fi;
	if [ ! -d ${@3c} ]; then mkdir ${@3c}; fi
	if [ ! -d ${lbb@charms} ]; then mkdir ${lbb@charms}; fi
	cp ${__tst}/index.ext ${lbb@charms}
###### REMOVE CP in production from `__charms__dirs__`

__ccc_dirs__:
	if [ ! -d ${head@charms} ]; then mkdir ${head@charms}; fi
	if [ ! -d ${obj@charms} ]; then mkdir ${obj@charms}; fi
	if [ ! -d ${@3c} ]; then mkdir ${@3c}; fi
	if [ ! -d ${lib@charms} ]; then mkdir ${lib@charms}; fi

__ccstd_headers__:
	cp ${ccstd_headers} ${head@charms}

__ccc_headers__:
	cat ${hbar_h} > ${_hbar}
	cat ${hbar_c} >> ${_hbar}
	cat ${enk_h} > ${_enk}
	cat ${enk_c} >> ${_enk}
	cat ${lbb_h} > ${_lbb}
	cat ${lbb_c} >> ${_lbb}
	cat ${atp_h} >> ${_atp}
	cat ${atp_c} >> ${_atp}


_check_charms_: \
	__charms_dirs__\
	__ccc_dirs__\
	__ccstd_headers__\
	__ccc_headers__\
	libather


# lbb to atp `midway link`
lbb_atp_ml:
	cat ${atp_h} >> ${_lbb}



#source
@3c:=${@charms}/3c
3c: 
	@printf "\n{{{ccc}}}\n"
	if [ ! -d ${@3c} ]; then mkdir ${@3c}; fi
	cp ${__src}/d_*.c ${@3c}

#compiled
@2c:=${@3c}/2c
2c:
	@printf "\n{{ cc }}\n"
	if [ ! -d ${@2c} ]; then mkdir ${@2c}; fi
	cp ${head@charms}/* ${@2c}


#programs
@1c:=${@2c}/c
1c:
	@printf "\n{  c  }\n"
	if [ ! -d ${@1c} ]; then mkdir ${@1c}; fi
	cc ${@3c}/d_atp.c -o ${@1c}/d-atp${@arch} ${atherlib}
	cc ${@3c}/d_cld.c -o ${@1c}/d-cld${@arch} ${atherlib}
	cc ${@3c}/d_lbb.c -o ${@1c}/d-lbb${@arch} ${atherlib}
#tests
3c_out:
	cp ${@1c}/d-atp${@arch} d-atp
	cp ${@1c}/d-cld${@arch} d-cld
	cp ${@1c}/d-lbb${@arch} d-lbb


build_3c: 3c 2c 1c 3c_out

test_karch:
	./k512 ${@charms}

test_cloud:
	./d-cloud

test_field:
	./runid ${__tst}/index.ext


#####################################
#				Base-26				#
#####################################
all:
__alphadef__ := a b c d e f g h i j k l m n o p q r s t u v w x y z
__bdef__ := a.tt b.al c.cc d.ef e.sx f.mt g.it h.lv i.ne j.ab k.ei l.bb m.ae n.et o.te p.ub q.ue r.dl t.rv u.sr v.ik w.lk x.vl y.bn z.ai
__fldsdef__ := .att .bal .ccc .def .exs .fmt .git .hlv .inc .jab .kei .lbb .mae .net .ote .pub .que .rdl .trv .usr .vik .xvl .ybn .zai
__clevels__ := c cc ccc 
__FLAMES__:=__Mach_001F_001A_abcdefghijklmnopqrstuvwxyz__0x
__FNAME_L_S__ = \n__Makefile_001F_001A_\n\tabcdefghijklmnopqrstuvwxyz\n__0x\n

package:
	if [ -d ${__cdir}/package ]; then rm -rf ${__cdir}/package; fi
	if [ -f ${__cdir}/package.zip ]; then rm -rf ${__cdir}/package.zip; fi
	mkdir -p ${__cdir}/package/@source
	cp -r ${__@}/* ${__cdir}/package/@source
	cp ${__cdir}/Makefile ${__cdir}/package
	zip -r package.zip package/*
	rm -rf package

#################################
#			Hash Bar			#
#################################
hbar:=hbar
hbar__:=${__src}/${hbar}
hbar_c:=${hbar__}/c
hbar_h:=${hbar__}/h
o_hbar:=${obj@charms}/${hbar}.o
c_hbar:=${head@charms}/${hbar}.c
_hbar:=${head@charms}/${hbar}.h
clean_hbar:
	if [ -f ${c_hbar} ]; then rm ${c_hbar}; fi
	@printf "\n"
__hbar:
	@printf "@3c 'Hash bar' {hbar}\n"
	cp ${_hbar} ${c_hbar}
	${ac} ${c_hbar} -o ${o_hbar}

#only creates the object files
__hbar__: __hbar clean_hbar
#################################
#		Little Black Book		#
#################################
lbb:=lbb
lbb__:=${__src}/${lbb}
lbb_c:=${lbb__}/c
lbb_h:=${lbb__}/h
o_lbb:=${obj@charms}/${lbb}.o
c_lbb:=${head@charms}/${lbb}.c
_lbb:=${head@charms}/${lbb}.h
clean_lbb:
	if [ -f ${c_lbb} ]; then rm ${c_lbb}; fi
	@printf "\n"
__lbb:
	@printf "@3c 'Little black book' {lbb}\n"
	cp ${_lbb} ${c_lbb}
	${ac} ${c_lbb} -o ${o_lbb}

__lbb__: __lbb clean_lbb
#################################
#			Enkoder				#
#################################
enk:=enk
enk__:=${__src}/${enk}
enk_c:=${enk__}/c
enk_h:=${enk__}/h
o_enk:=${obj@charms}/${enk}.o
c_enk:=${head@charms}/${enk}.c
_enk:=${head@charms}/${enk}.h
clean_enk:
	if [ -f ${c_enk} ]; then rm ${c_enk}; fi
	@printf "\n"
__enk:
	@printf "@3c 'Encoder' {enk}\n"
	cp ${_enk} ${c_enk}
	${ac} ${c_enk} -o ${o_enk}

__enk__: __enk clean_enk
#####################################
#				Indexer				#
#####################################
ixr:=ixr
ixr__:=${__src}/${ixr}
ixr_c:=${ixr__}/c
ixr_h:=${ixr__}/h
o_ixr:=${obj@charms}/${ixr}.o
c_ixr:=${head@charms}/${ixr}.c
_ixr:=${head@charms}/${ixr}.h
clean_ixr:
	if [ -f ${c_ixr} ]; then rm ${c_ixr}; fi
	@printf "\n"
__ixr: 
	@printf "@3c 'The Indexer' {ixr}\n"
	cp ${_ixr} ${c_ixr}
	${ac} ${c_ixr} -o ${o_ixr}

__ixr__:__ixr clean_ixr
#################################
#			  Transfer			#
#################################
atp:=atp
atp__:=${__src}/${atp}
atp_a:=${atp__}/anet.h
atp_m:=${atp__}/mor.h
atp_l:=${atp__}/les.h
atp_c:=${atp__}/c
atp_h:=${atp__}/h
o_atp:=${obj@charms}/${atp}.o
c_atp:=${head@charms}/${atp}.c
_atp:=${head@charms}/${atp}.h

# field for output
clean_atp:
	if [ -f ${c_atp} ]; then rm ${c_atp}; fi
	@printf "\n"
__atp:
	@printf "@3c 'Aether Transfer Protocol' {atp}\n"
	cp ${_atp} ${c_atp}
	${ac} ${c_atp} -o ${o_atp}

__atp__: __atp clean_atp
#################################
#			  NET				#
#################################
net:=net
net__:=${__src}/${net}
o_net:=${obj@charms}/${net}.o
ml_net:=${head@charms}/morles.c
_net:=${head@charms}/${net}.h

# field for output
clean_net:
	if [ -f ${ml_net} ]; then rm ${ml_net}; fi
	@printf "\n"
__net:
	@printf "@3c 'Atthernet' {net}\n"
	cp ${_net} ${ml_net}
	${ac} ${ml_net} -o ${o_net}

__net__: __net clean_net

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