#!/usr/bin/python3

import os
import subprocess
import sys
import numpy

RHIGH = int(sys.argv[1]) if len(sys.argv)>1 else 100
RLOW = 0
RSIZE = int(sys.argv[1]) if len(sys.argv)>1 else 100
ALGO = ['MERGESORT','QUICKSORT']
DEBUG = int(sys.argv[2]) if len(sys.argv)>2 else 0

def exec(algo,vec):
	p1 = subprocess.run(["g++","-c","main-1.cc"], capture_output=True,text=True)
	p2 = subprocess.run(["g++","-c","sort.cc"], capture_output=True,text=True)
	p3 = subprocess.run(["g++","main-1.o","sort.o"], capture_output=True,text=True)
	p4 = subprocess.run(["./a.out","-a MERGESORT","-v", vec], capture_output=True,text=True)
	if(DEBUG): print(p4.stdout)
	print("Executing for %s:"%(algo),end=' ')
	print("Return Codes: p1=%d,p2=%d,p3=%d,p4=%d"%(p1.returncode,p2.returncode,p3.returncode,p4.returncode))

def main():
	random_list = list(numpy.random.randint(low = RLOW,high = RHIGH,size = RSIZE))
	vec = ','.join(str(v) for v in random_list)
	for item in ALGO:
		exec(item,vec)


if __name__=='__main__':
	main()