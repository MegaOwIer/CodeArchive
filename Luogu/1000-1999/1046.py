a=input().split(' ')
x=int(input())+30
ans=0;
for i in a:
	if(x>=int(i)):
		ans+=1
print(ans)
