#include<cstdio>
typedef long long LL;

LL a,ans;

int main()
{
    scanf("%lld",&a);
    for(int i=1;i<=a;i++)  ans+=a/i;
    printf("%lld",ans);
    return 0;
}
