#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;

int n,dp[2][5005],now,ans;
char c;
bool lsf;

int main()
{
	scanf("%d",&n),dp[0][0]=1;
	for(int i=1;i<=n;i++)
	{
		do c=getchar();while(!isalpha(c));
		now=i&1;
		memset(dp[now],0,n<<2);
		if(lsf)for(int j=1;j<n;j++)dp[now][j]=dp[now^1][j-1];
		else
		{
			dp[now][n-1]=dp[now^1][n-1];
			for(int j=n-2;~j;j--)dp[now][j]=(dp[now][j+1]+dp[now^1][j])%mod;
		}
		lsf=(c=='f');
	}
	for(int i=0;i<n;i++)ans=(ans+dp[n&1][i])%mod;
	printf("%d",ans);
	return 0;
}
