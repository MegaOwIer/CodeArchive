#include<bits/stdc++.h>
using namespace std;
const int mod=20100403,maxn=2000005;
typedef long long LL;
 
int n,m;
LL fac[maxn],afac[maxn];
char c;
 
inline void read(int& x)
{
    c=getchar(),x=0;
    while(c<'0'||c>'9')c=getchar();
    while(c<='9'&&c>='0')x=x*10+c-'0',c=getchar();
}
inline LL Pow(LL a,int b)
{
    LL ans=1,res=a;
    while(b)
    {
        if(b&1)ans=ans*res%mod;
        res=res*res%mod;
        b>>=1;
    }
    return ans;
}
inline LL C(int u,int v)
{
    return fac[u]*afac[v]%mod*afac[u-v]%mod;
}
 
int main()
{
    read(n),read(m);
    fac[0]=1;
    for(int i=1;i<=n+m;i++)fac[i]=fac[i-1]*i%mod;
    afac[n+m]=Pow(fac[n+m],mod-2);
    for(int i=n+m;i;i--)afac[i-1]=afac[i]*i%mod;
    printf("%lld",(C(n+m,n)-C(n+m,m-1)+mod)%mod);
    return 0;
}
