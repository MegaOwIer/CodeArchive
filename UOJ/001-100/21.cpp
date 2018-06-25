#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MX=1000005;

int N,a[MX],X;
LL ans,tmp,del;

int main()
{
    scanf("%d",&N);
    for(int i=1,x;i<=N;i++)
        scanf("%d",&x),a[x]++,ans+=x,X=max(X,x);
    for(int i=1;i<=X;i++)a[i]+=a[i-1];
    for(int i=1,mx;i<=X;i++)
    {
        tmp=0;
        for(int j=i-1,k=1;j<=X;j+=i,k++)
            tmp+=(a[min(X,j+i)]-a[j])*k;
        del=max(del,tmp*(i-1));
    }
    printf("%lld\n",ans-del);
    return 0;
}
