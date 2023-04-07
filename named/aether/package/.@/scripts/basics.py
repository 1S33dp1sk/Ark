#!/usr/bin/python3
import os

gitdirs=[]

def __gitdirs(wdp):
	x=os.listdir(wdp)
	if('.git' in x):
		gitdirs.append(wdp)
	for _ in x:
		__="%s/%s"%(wdp, _)
		if(os.path.isdir(__)):
			__gitdirs(__)

if __name__ == '__main__':
	cwd = os.getcwd()
	__gitdirs(cwd)
	for i in gitdirs:
		print(i)