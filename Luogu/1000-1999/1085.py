now=8;ans=0
for i in range(1,8):
	a,b=input().split(' ')
	a=int(a);b=int(b);
	if(a+b>now):
		ans=i;now=a+b
print(ans)
