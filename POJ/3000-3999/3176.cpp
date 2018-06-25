#include<cstdio>
#include<algorithm>
using namespace std;

int n,dp[400][400];

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)  for(int j=1;j<=i;j++)  scanf("%d",&dp[i][j]);
	for(int i=n-1;i;i--)  for(int j=1;j<=i;j++)  dp[i][j]+=max(dp[i+1][j],dp[i+1][j+1]);
	printf("%d",dp[1][1]);
	return 0;
}
