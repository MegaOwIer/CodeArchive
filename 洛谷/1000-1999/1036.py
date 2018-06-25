def check(u):
    i=2
    while i*i<=u:
        if u%i==0:
            return
        i=i+1
    global ans
    ans=ans+1


def dfs(now,chn,tot):
    global n,k,a
    if chn==k:
        check(tot)
        return
    if now>n:
        return
    dfs(now+1,chn+1,tot+a[now])
    dfs(now+1,chn,tot)


def main():
    global ans,n,k,a
    ans=0
    n,k=input().split()
    n=int(n)
    k=int(k)
    a=[0]+[int(x) for x in input().split()]
    dfs(1,0,0)
    print(ans)


main()
