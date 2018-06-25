x,n=input().split(' ')
x=int(x);n=int(n)
ans=n//7*1250
n%=7
for i in range(1,n+1):
	if(x<6):
		ans+=250
	x=x+1;
	if(x==8):
		x=1
print(ans)
