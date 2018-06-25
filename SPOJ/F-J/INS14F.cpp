#include<cstdio>
#include<cctype>
using namespace std;
typedef long long LL;
const int mod=1000000007,maxn=1000005;

int T,n,k;
LL fac[maxn],afac[maxn];
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
inline LL A(int n,int m)
{
    if(m>n)return 0;
    return fac[n]*afac[n-m]%mod;
}

int main()
{
    read(T),fac[0]=1;
    for(int i=1;i<=1000000;i++)fac[i]=fac[i-1]*i%mod;
    afac[1000000]=Pow(fac[1000000],mod-2);
    for(int i=1000000;i>=0;i--)afac[i-1]=afac[i]*i%mod;
    while(T--)
    {
        read(n),read(k);
        if(n<k*2)printf("%lld\n",A(n,k));
        else printf("%lld\n",A(n-1,k-1)*k%mod);
    }
    return 0;
}
