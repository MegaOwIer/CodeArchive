n=int(input())
a=input().split()
flag=[False for i in range(0,20000)]
for i in range(0,n):
	for j in range(0,i):
		flag[int(a[i])+int(a[j])]=True
cnt=0
for i in range(0,n):
	if(flag[int(a[i])]==True):
		cnt+=1
print(cnt)
