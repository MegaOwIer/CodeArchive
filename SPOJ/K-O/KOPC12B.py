mod=1000000007
a=[1 for i in range(2000005)]
for i in range(1,2000001):
    a[i]=a[i-1]*i%mod
T=int(input())
for i in range(T):
    n=int(input())
    ans=a[2*n]*pow(a[n],mod-3,mod)*n*500000004
    print(ans%mod)
