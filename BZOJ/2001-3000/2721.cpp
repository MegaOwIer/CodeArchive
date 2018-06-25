#include<cstdio>
#include<algorithm>
using namespace std;
const long long mod=1000000000+7;

int n,p[78500],cnt;
bool fl[1000001];
long long ans=1LL,ans1;

int main()
{
    scanf("%d",&n);  p[++cnt]=2;
    for(int i=3;i<=n;i+=2)  if(!fl[i])
    {
        p[++cnt]=i;
        for(int j=i+i;j<=n;j+=i)  fl[j]=1;
    }
    for(int i=1;i<=cnt;i++)
    {
        ans1=0LL;
        for(int j=n/p[i];j;j/=p[i])  ans1=(ans1+j)%mod;
        ans=ans*(2*ans1+1)%mod;
    }
    printf("%lld",ans);
    return 0;
}
