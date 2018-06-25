#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int mod=998244353,MX=1<<21|1;

int n,m,p,w[22],sum[MX],g[22],ppct[1<<8|1],f0[22][MX],f[22][MX],isum[MX];

template<typename T>inline void read(T& x)
{
    static char c;
    x=0,c=getchar();
    while(!isdigit(c))c=getchar();
    while(isdigit(c))x=x*10+c-'0',c=getchar();
}
inline void add(int u,int v){g[u]|=1<<v,g[v]|=1<<u;}
inline int popcnt(int u){return ppct[u&255]+ppct[u>>8&255]+ppct[u>>16&255];}
inline int Pow(int a,int b)
{
    if(!a)return 0;
    int ans=1;
    for(;b;b>>=1,a=(LL)a*a%mod)if(b&1)ans=(LL)ans*a%mod;
    return ans;
}
inline bool check(int S)
{
    static int zt[22];
    for(int i=0;i<n;i++)if(S&(1<<i))
        sum[S]+=w[i],zt[i]=g[i]&S;
    isum[S]=Pow(sum[S],mod-p-1);
    sum[S]=Pow(sum[S],p);
    for(int i=0;i<n;i++)if(S&(1<<i))
        if(popcnt(zt[i])&1)return 1;
    for(int i=0;i<n;i++)if(S&(1<<i))zt[i]|=1<<i;
    for(int i=0;i<n;i++)if(S&(1<<i))
        for(int j=0;j<n;j++)if(zt[j]&(1<<i))zt[j]|=zt[i];
    for(int i=0;i<n;i++)if(S&(1<<i))return zt[i]!=S;
}
inline void FMT(int* A)
{
    for(int t=1;t<(1<<n);t<<=1)for(int s=0;s<(1<<n);s++)
        if(s&t)A[s]=(A[s]+A[s^t])%mod;
}
inline void IFMT(int* A)
{
    for(int t=1;t<(1<<n);t<<=1)for(int s=0;s<(1<<n);s++)
        if(s&t)A[s]=(A[s]-A[s^t]+mod)%mod;
}

int main()
{
    read(n),read(m),read(p);
    for(int i=1;i<256;i++)ppct[i]=ppct[i>>1]+(i&1);
    for(int i=1,u,v;i<=m;i++)read(u),read(v),add(u-1,v-1);
    for(int i=0;i<n;i++)read(w[i]);
    for(int i=(1<<n)-1;i;i--)if(check(i))f0[popcnt(i)][i]=sum[i];
    for(int i=1;i<=n;i++)FMT(f0[i]);
    f[0][0]=1,FMT(f[0]);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)for(int s=0;s<(1<<n);s++)
            f[i][s]=(f[i][s]+(LL)f[i-j][s]*f0[j][s])%mod;
        IFMT(f[i]);
        for(int s=0;s<(1<<n);s++)f[i][s]=(LL)f[i][s]*isum[s]%mod;
        FMT(f[i]);
    }
    IFMT(f[n]),printf("%d",f[n][(1<<n)-1]);
    return 0;
}
