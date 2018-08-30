#python3
import numpy as np
n=int(input())
s1=list(map(int,input().split()))
m=int(input())
s2=list(map(int,input().split()))
o=int(input())
s3=list(map(int,input().split()))
d = np.zeros((n+1,m+1,o+1),dtype=int)

for x in range(1,n+1):
	for y in range(1,m+1):
		for z in range(1,o+1):
			if(s1[x-1]==s2[y-1] and s2[y-1]==s3[z-1]):
				d[x,y,z]=d[x-1,y-1,z-1]+1
			else:
				d[x,y,z]=max(d[x-1,y,z],d[x,y-1,z],d[x,y,z-1])
print (d[n,m,o])