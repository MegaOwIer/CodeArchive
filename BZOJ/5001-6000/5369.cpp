#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MX=1<<20|1,mod=998244353;

int N,a[21],f[MX],g[MX],S,sum[MX],ans;

inline int read()
{
    int x=0,c=getchar(),f=1;
    while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
    while(isdigit(c))x=x*10+c-'0',c=getchar();
    return x*f;
}

int main()
{
    N=read(),S=(1<<N)-1;
    for(int i=0;i<N;i++)a[i]=read();
    for(int i=1;i<=S;i++)for(int j=0;j<N;j++)
        if((i>>j)&1)sum[i]+=a[j];
    for(int i=1;i<=S;i++)
    {
        if(__builtin_popcount(i)==1)f[i]=1;
        else for(int j=0;j<N;j++)
            if(((i>>j)&1)&&sum[i]>a[j])
                f[i]=(f[i]+f[i^(1<<j)])%mod;
    }
    g[0]=1;
    for(int i=1;i<=S;i++)
        if(sum[i]>0)g[i]=0;
        else if(__builtin_popcount(i)==1)g[i]=1;
        else for(int j=0;j<N;j++)if((i>>j)&1)
            g[i]=(g[i]+g[i^(1<<j)])%mod;
    for(int i=1;i<=S;i++)
        ans=(ans+(LL)sum[i]*f[i]%mod*g[i^S])%mod;
    printf("%d\n",(ans+mod)%mod);
    return 0;
}
