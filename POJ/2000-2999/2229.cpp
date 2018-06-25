#include<cstdio>
#include<cmath>
using namespace std;

const int mod=1000000000;
int n,dp[1000005];

int main()
{
	scanf("%d",&n);
	dp[0]=1;
	for(int i=1;i<=n;i++)
	{
		if(i%2)  dp[i]=dp[i-1];
		else  dp[i]=dp[i-1]+dp[i>>1];
		dp[i]%=mod;
	}
	printf("%d",dp[n]);
	return 0;
}
