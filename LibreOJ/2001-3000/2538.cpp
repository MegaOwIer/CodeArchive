#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MX=3005,mod=998244353,MN=1505;

int C[MX][MX],N,M,K,a[MN],tmp[MX],f[MX][MX],g[MX][MX];

inline int read()
{
    int x=0,c;
    while(!isdigit(c=getchar()));
    while(x=x*10+c-'0',isdigit(c=getchar()));
    return x;
}
inline int F(int x,int y)
{
    int ans=0;
    for(int i=y;i<=N;i++)
        ans=(ans+(LL)C[N-i][x-y]*f[i][y])%mod;
    return ans;
}
inline int G(int x,int y)
{
    int ans=0;
    for(int i=y;i<=N;i++)
        ans=(ans+(LL)C[N-i][x-y]*g[i][y])%mod;
    return ans;
}

int main()
{
    for(int i=0;i<=3000;i++)C[i][0]=1;
    for(int i=1;i<=3000;i++)for(int j=1;j<=i;j++)
        C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
    for(int T=read();T--;)
    {
        N=read(),M=read(),K=read();
        for(int i=1;i<=N;i++)a[i]=read();
        sort(a+1,a+N+1,greater<int>());
        memset(tmp+1,0,sizeof(int)*N<<1);
        g[0][0]=tmp[0]=1;
        for(int i=1;i<=N;i++)for(int j=i;j;j--)
        {
            g[i][j]=(LL)tmp[j-1]*a[i]%mod;
            tmp[j]=(tmp[j]+g[i][j])%mod;
        }
        for(int i=1;i<=N;i++)a[i]=read();
        sort(a+1,a+N+1,greater<int>());
        memset(tmp,0,sizeof(int)*(N+1));
        for(int i=1;i<=N;i++)for(int j=i;j;j--)
        {
            f[i][j]=(tmp[j-1]+(LL)C[i-1][j-1]*a[i])%mod;
            tmp[j]=(tmp[j]+f[i][j])%mod;
        }
        int ans=0;
        for(int i=0;i<M;i++)
            if(i>=K)ans=(ans+(LL)F(M-i,1)*G(i,K-1))%mod;
            else ans=(ans+(LL)F(M-i,K-i)*G(i,i))%mod;
        printf("%d\n",ans);
    }
    return 0;
}
