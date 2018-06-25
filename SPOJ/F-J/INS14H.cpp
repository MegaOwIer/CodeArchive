#include<cstdio>
#include<cctype>
using namespace std;
typedef long long LL;
const int mod=1000000007;

int Q,N,T;
LL ans[105][105],fac[205],afac[205];
char c;

inline void read(int& x)
{
    c=getchar(),x=0;
    while(!isdigit(c))c=getchar();
    while(isdigit(c))x=x*10+c-'0',c=getchar();
}
inline LL Pow(LL a,int b)
{
    LL ans=1;
    while(b)
    {
        if(b&1)ans=ans*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return ans;
}
inline LL C(int n,int m)
{
    if(m>n)return 0;
    return fac[n]*afac[n-m]%mod*afac[m]%mod;
}

int main()
{
    read(Q),fac[0]=1;
    for(int i=1;i<=200;i++)fac[i]=fac[i-1]*i%mod;
    afac[200]=Pow(fac[200],mod-2);
    for(int i=200;i>=0;i--)afac[i-1]=afac[i]*i%mod;
    for(int i=0;i<=100;i++)ans[1][i]=C(i*2,i);
    for(int i=1;i<=100;i++)ans[i][0]=1;
    for(int i=2;i<=100;i++)for(int j=1;j<=100;j++)for(int k=0;k<=j;k++)
    {
        ans[i][j]=(ans[i][j]+ans[i-1][j-k]*C(k*2,k)%mod*C(2*j,2*k)%mod)%mod;
    }
    while(Q--)
    {
        read(N),read(T);
        if(T&1)puts("0");
        else printf("%lld\n",ans[N][T/2]);
    }
    return 0;
}
