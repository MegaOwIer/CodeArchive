#include<bits/stdc++.h>
using namespace std;

using LL=long long;
using Point=pair<int,int>;
const int MX=4005,mod=1000000007;
#define st first
#define nd second

int N,ans,fac[MX<<1],inv[MX<<1];
int Pool[MX][MX],*f[MX],**dp;
Point P[200005];

inline int read()
{
    int x=0,c=getchar();
    while(!isdigit(c))c=getchar();
    while(isdigit(c))x=x*10+c-'0',c=getchar();
    return x;
}
inline void update(int& a,int b){((a+=b)>=mod)&&(a-=mod);}
int Inv(int u){return u==1?1:LL(mod-mod/u)*Inv(mod%u)%mod;}
inline int C(int n,int m){return (LL)fac[n]*inv[m]%mod*inv[n-m]%mod;}

int main()
{
    N=read();
    for(int i=0;i<MX;i++)f[i]=Pool[i]+2002;
    dp=f+2002;
    fac[0]=1;
    for(int i=1;i<=8000;i++)fac[i]=(LL)fac[i-1]*i%mod;
    inv[8000]=Inv(fac[8000]);
    for(int i=8000;i;i--)inv[i-1]=(LL)inv[i]*i%mod;
    for(int i=1,x,y;i<=N;i++)
        x=read(),y=read(),dp[-x][-y]+=1,P[i]=make_pair(x,y);
    for(int i=-1999;i<=2000;i++)update(dp[-2000][i],dp[-2000][i-1]);
    for(int i=-1999;i<=2000;i++)update(dp[i][-2000],dp[i-1][-2000]);
    for(int i=-1999;i<=2000;i++)for(int j=-1999;j<=2000;j++)
        update(dp[i][j],dp[i-1][j]),update(dp[i][j],dp[i][j-1]);
    for(int i=1;i<=N;i++)update(ans,dp[P[i].st][P[i].nd]);
    for(int i=1;i<=N;i++)update(ans,mod-C((P[i].st+P[i].nd)*2,P[i].st*2));
    printf("%lld\n",(LL)ans*Inv(2)%mod);
    return 0;
}
