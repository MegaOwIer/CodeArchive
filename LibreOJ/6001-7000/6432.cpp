#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MX=100005,mod=998244353;

int N,K,a[MX],b[MX],fac[MX],ifac[MX];

inline int read()
{
    int x=0,c=getchar();
    while(!isdigit(c))c=getchar();
    while(isdigit(c))x=x*10+c-'0',c=getchar();
    return x;
}
int getinv(int u){return u==1?1:LL(mod-mod/u)*getinv(mod%u)%mod;}
inline int C(int n,int m){return (LL)fac[n]*ifac[m]%mod*ifac[n-m]%mod;}
inline int solve(int val)
{
    if(!val)return C(N,K);
    int ans=0;
    int cnt=lower_bound(b+1,b+N+1,val*2)-lower_bound(b+1,b+N+1,val);
    if(cnt<=K)ans=C(N-cnt,K-cnt);
    cnt=lower_bound(b+1,b+N+1,val)-lower_bound(b+1,b+N+1,(val+1)/2);
    if(N-cnt-1>=K)ans=(ans+C(N-cnt-1,K))%mod;
    return ans;
}

int main()
{
    N=read(),K=read();
    fac[0]=1;
    for(int i=1;i<=N;i++)fac[i]=(LL)fac[i-1]*i%mod;
    ifac[N]=getinv(fac[N]);
    for(int i=N;i;i--)ifac[i-1]=(LL)ifac[i]*i%mod;
    for(int i=1;i<=N;i++)a[i]=b[i]=read();
    sort(b+1,b+N+1);
    for(int i=1;i<=N;i++)printf("%d\n",solve(a[i]));
    return 0;
}