__str = """a:=address
b:=balance
c:=charm
d:=digital
e:=execs
f:=formation
g:=gvailability
h:=hlevel
i:=include
j:=jaber
k:=katt
l:=laddr
m:=mcall
n:=nope
o:=operatingsys
p:=pointdetails
q:=queryargs
r:=readbook
s:=sandbox
t:=traverse
u:=user
v:=vik
w:=welkommen
x:=xolve,solve&resolve
y:=ybase
z:=z"""

def __write_file(__path):
	with open(__path,'w') as fout:
		fout.write("#autogen")

def __read_make(__cwd,_list):
	assert len( _list ) == 26 #alphadef
	if (__cwd.endswith("/charms")):
		print("in charms\n")
		for i in _list:
			__name="%s/.%s"%(_cwd,i[1])
			if (os.path.isfile(__name)):
				continue
			else:
				__write_file(__name)

import os
if __name__ == '__main__':
	list_ = [ i for i in __str.split("\n")]
	_list = [ i.split(":=") for i in list_ ]
	_cwd = os.getcwd()
	__read_make(_cwd,_list)

















#python3 decode_make.py

