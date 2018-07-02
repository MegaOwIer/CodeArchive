n,x=input().split(' ')
n=int(n)
ans=0
for i in range(1,n+1):
	tmp=str(i)
	ans+=tmp.count(x)
print(ans)
