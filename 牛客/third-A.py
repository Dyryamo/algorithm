import sys;
import math;
pi=3.1415926535;
e=2.718281828459;
T=int(input())
for line in range(0,T):
	a=int(input());
	print("%d"%(math.floor((0.5*math.log(2*pi*a,8)+a*math.log(a/e,8)))+1));



