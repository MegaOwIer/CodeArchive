#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=100005;

int n;
double p[maxn],x[maxn],x2[maxn],dp[maxn];

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)  scanf("%lf",p+i);
    for(int i=1;i<=n;i++)
    {
        x[i]=(x[i-1]+1)*p[i];
        x2[i]=(x2[i-1]+2*x[i-1]+1)*p[i];
        dp[i]=dp[i-1]+(3*x[i-1]+3*x2[i-1]+1)*p[i];
    }
    printf("%.1lf",dp[n]);
    return 0;
}

