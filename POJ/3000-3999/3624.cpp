#include<cstdio>
#include<algorithm>
using namespace std;

int m,n,w[3500],d[3500],dp[13000];

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)  scanf("%d%d",&w[i],&d[i]);
	for(int i=1;i<=n;i++)  for(int j=m;j;j--)  if(j>=w[i])  dp[j]=max(dp[j],dp[j-w[i]]+d[i]);
	printf("%d",dp[m]);
	return 0;
}
