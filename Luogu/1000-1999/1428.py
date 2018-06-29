n=int(input())
a=input().split()
for i in range(0,n):
	cnt=0
	for j in range(0,i):
		if(int(a[j])<int(a[i])):
			cnt+=1
	print(cnt,end=' ')
