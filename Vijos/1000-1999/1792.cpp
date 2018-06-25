#include<bits/stdc++.h>
using namespace std;
const int mod=1000007;

int n,m,a,dp[105];

int main()
{
	scanf("%d%d",&n,&m),dp[0]=1;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a);
		for(int j=m;j;j--)for(int k=1;k<=a&&k<=j;k++)
			(dp[j]+=dp[j-k])%=mod;
	}
	printf("%d",dp[m]);
	return 0;
}
