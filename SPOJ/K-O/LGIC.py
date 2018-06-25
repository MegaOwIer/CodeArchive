a=[0,1]
ans=1
n=int(input())
for i in range(1,n):
    tmp=a[i]*2+i-1
    a.append(tmp)
    ans=ans*(i+1)
print(ans+a[n])
