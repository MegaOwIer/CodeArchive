#include<bits/stdc++.h>
using namespace std;
const int maxn=1000005;

int n,a[maxn];
long long ans;

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",a+i);
    for(int i=1;i<n;i++)ans+=max(a[i],a[i+1]);
    printf("%lld",ans);
    return 0;
}
