#include<cstdio>
using namespace std;

int n,k,d[10005];
bool dp[10005][105];

int main()
{
    scanf("%d%d",&n,&k);
    for(int i=1,a;i<=n;i++)
    {
        scanf("%d",&a);
        a=(a%k+k)%k;
        d[i]=a;
    }
    dp[1][d[1]]=dp[1][k-d[1]]=1;
    for(int i=2;i<=n;i++)  for(int j=0;j<k;j++)  dp[i][j]=dp[i-1][(j+d[i])%k]|dp[i-1][((j-d[i])%k+k)%k];
    puts(dp[n][0]?"Divisible":"Not divisible");
    return 0;
}
