#include<bits/stdc++.h>
using namespace std;
const int MX=100005;

int T,N,Q,a[MX],b[MX];
unordered_map<int,int> Index;

inline int read()
{
    static int c,x;
    c=getchar(),x=0;
    while(!isdigit(c))c=getchar();
    while(isdigit(c))x=x*10+c-'0',c=getchar();
    return x;
}
inline int solve(int u)
{
    int index=Index[u],cg=0,cl=0,wg=0,wl=0;
    for(int L=1,R=N,mid;;)
    {
        mid=L+R>>1;
        if(mid==index)break;
        if(mid>index)cg++,wg+=(b[mid]<u),R=mid-1;
        else cl++,wl+=(b[mid]>u),L=mid+1;
    }
    int rk=lower_bound(a+1,a+N+1,u)-a;
    if(cl>=rk||(N-rk)<cg)return -1;
    return max(wg,wl);
}

int main()
{
    T=read();
    while(T--)
    {
        Index.clear();
        N=read(),Q=read();
        for(int i=1;i<=N;i++)Index[a[i]=b[i]=read()]=i;
        sort(a+1,a+N+1);
        while(Q--)printf("%d\n",solve(read()));
    }
    return 0;
}
