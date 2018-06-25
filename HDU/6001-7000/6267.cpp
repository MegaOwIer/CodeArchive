#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MX=100005,mod=998244353;

int T,N,inv[MX],fac[MX],tmp,ans;

inline int read()
{
    int x=0,c=getchar();
    while(!isdigit(c))c=getchar(),x=0;
    while(isdigit(c))x=x*10+c-'0',c=getchar();
    return x;
}
int getinv(int u){return u==1?1:LL(mod-mod/u)*getinv(mod%u)%mod;}

int main()
{
    inv[0]=inv[1]=fac[0]=1;
    for(int i=2;i<=100000;i++)inv[i]=LL(mod-mod/i)*inv[mod%i]%mod;
    for(int i=1;i<=100000;i++)fac[i]=(LL)fac[i-1]*i%mod;
    for(T=read();T--;)
    {
        N=read(),tmp=(LL)fac[N-1]*getinv(fac[N])%mod,ans=0;
        for(int i=0,val=0;i<N;i++)
            val=(val+inv[i])%mod,ans=(ans+(LL)val*tmp%mod*read())%mod;
        printf("%d\n",ans);
    }
    return 0;
}
