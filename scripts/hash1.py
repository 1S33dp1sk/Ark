#!/usr/bin/python3
import base64
import hashlib
import sys

def __hash(arg):
	h=hashlib.sha1(bytes(arg, 'ascii'))
	hd=h.hexdigest()
	hash_str=base64.b64encode(bytes.fromhex(hd)).decode()
	print("hash is %s"%hash_str)
	with open('temp.sha1','w+') as fout:
		fout.write(hash_str)


if __name__=='__main__':
	if(len(sys.argv)==1):
		print("usage : hash1 argument to hash")
	else:
		__hash(sys.argv[1])
