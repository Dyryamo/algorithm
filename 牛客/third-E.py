import os;
import sys;
def solve(a):
	i=1;
	s=1;
	while i<=a:
		s=i*s;
		i+=1;
	return s;
for line in sys.stdin:
	print(solve(int(line)));


