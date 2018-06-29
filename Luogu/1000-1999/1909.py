import math

n=int(input())
ans=2147483647
for i in range(1,4):
	a,b=input().split(' ')
	a=int(a);b=int(b)
	tmp=int(math.ceil(n/a)*b)
	ans=min(ans,tmp)
print(ans)
