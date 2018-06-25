#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const double r=0.5772156649;

LL n,m;
double ans;

int main()
{
    scanf("%lld%lld",&n,&m);
    if(n<=5000)for(int i=1;i<=n;i++)ans+=0.5/i;
    else ans=log(n+1.0)+r,ans/=2.0;
    printf("%lld\n",(LL)(ans*m-1e-10));
    return 0;
}
