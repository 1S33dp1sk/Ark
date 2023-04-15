#!/usr/bin/python3

def str_seperator(x):
	if ':=' in x:
		return 0x21
	elif '=' in x:
		return 0x20
	elif '=:' in x:
		return 0x10
	elif ':' in x:
		return 0x01

def seperator(x):
	return { 0x21:':=',0x20:'=',0x10:'=:',0x01:':' }.get(x,lambda:"\0")

class alphabet:
	def __init__(self):
		self.alpha=[]
		self.base = """a:=address\nb:=balance\nc:=charm\nd:=digital\ne:=execs\nf:=formation\ng:=gvailability\nh:=hlevel\ni:=include\nj:=jaber\nk:=katt\nl:=laddr\nm:=mcall\nn:=nope\no:=operatingsys\np:=pointdetails\nq:=queryargs\nr:=readbook\ns:=sandbox\nt:=traverse\nu:=user\nv:=vik\nw:=welkommen\nx:=xolve,solve&resolve\ny:=ybase\nz:=z"""
		for i,__ in enumerate(self.base.split('\n')):
			_a = __[0]
			_abet= seperator(str_seperator(__))
			self.alpha.append({
				"ucid":"%s"%_a,
				"name":"%s%s"%(_a,__),
				"sep":"%s"%(_abet),
				"next":"%d"%(i+1),
			})

	def write_file(self, __path):
		with open(__path,'w') as fout:
			fout.write("#autogen")
			fout.write(str(self.alpha))

	def read_make(self, __cwd,_list):
		assert len( _list ) == 26 #alphadef
		if (__cwd.endswith("/charms")):
			print("in charms\n")
			for i in _list:
				__name="%s/.%s"%(_cwd,i[1])
				if (os.path.isfile(__name)):
					continue
				else:
					__write_file(__name)





if __name__ == '__main__':
	__base=alphabet()
	__base.write_file("alphabet")
	print(__base.alpha)











































