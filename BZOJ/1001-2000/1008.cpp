#include<cstdio>
using namespace std;
typedef long long LL;
const LL mod=100003LL;

LL m,n,ans,ans1;

LL Pow(LL a,LL b)
{
    if(!a)  return 0LL;
    LL ans=1,ans1=a;
    while(b)
    {
        if(b&1)  ans=ans*ans1%mod;
        ans1=ans1*ans1%mod;
        b>>=1;
    }
    return ans;
}

int main()
{
    scanf("%lld%lld",&m,&n);
    ans=Pow(m%mod,n%(mod-
    1));
    ans1=(m%mod)*Pow((m-1)%mod,(n-1)%(mod-1))%mod;
    printf("%lld",(ans-ans1+mod)%mod);
    return 0;
}
