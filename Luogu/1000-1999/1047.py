L,M=input().split(' ')
L=int(L);M=int(M)
a=[True for i in range(0,L+1)]
for i in range(0,M):
	l,r=input().split(' ')
	l=int(l);r=int(r)
	for j in range(l,r+1):
		a[j]=False
cnt=0
for i in range(0,L+1):
	if(a[i]==True):
		cnt+=1
print(cnt)
