#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long LL;

LL n,k,ans,ret;

int main()
{
    scanf("%lld%lld",&n,&k);
    ans=n*k;
    LL mn=1,mx=n;
    while(mn!=mx)
    {
        LL mid=(mn+mx)>>1;
        if(k/mid!=k/n)  mn=mid+1;
        else  mx=mid;
    }
    ans-=k/n*(mn+n)*(n-mn+1)/2;
    for(int i=k/n+1;;i++)
    {
        LL cnt=k/i-k/(i+1);
        if(cnt<=1)  {ret=k/i;  break;}
        ans-=i*(k/i+k/(i+1)+1)*cnt/2;
    }
    for(;ret;ret--)  ans-=k/ret*ret;
    printf("%lld",ans);
    return 0;
}
