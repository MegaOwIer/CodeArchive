#include<cstdio>
#include<algorithm>
using namespace std;

int n,b,m[25],dp[40000001],sum,i=1;

int main()
{
	scanf("%d%d",&n,&b);
	for(int i=1;i<=n;i++)  {scanf("%d",&m[i]);  sum+=m[i];}
	for(int i=1;i<=n;i++)  for(int j=sum;j>=m[i];j--)  dp[j]=max(dp[j],dp[j-m[i]]+m[i]);
	for(;dp[i]<b;i++);
	printf("%d",dp[i]-b);
	return 0;
}
