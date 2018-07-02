n=int(input())
a=[-1]+[int(x) for x in input().split()]+[-1]

ans=0
tmp=0
for i in range(1,n+2):
	if(a[i]<=a[i-1]):
		ans=max(ans,tmp)
		tmp=0;
	tmp+=1
print(ans)
