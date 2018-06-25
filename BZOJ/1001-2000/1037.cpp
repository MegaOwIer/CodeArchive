#include<bits/stdc++.h>
using namespace std;
const int mod=12345678;

int n,M,k,dp[305][155][21][21],ans;
char c;

int main()
{
	scanf("%d%d%d",&n,&M,&k),dp[0][0][0][0]=1;
	for(int i=0;i<M+n;i++)for(int j=0;j<=n;j++)
		for(int l=0;l<=k;l++)for(int m=0;m<=k;m++)if(dp[i][j][l][m])
	{
		if(l+1<=k&&j+1<=n)(dp[i+1][j+1][l+1][max(m-1,0)]+=dp[i][j][l][m])%=mod;
		if(m+1<=k&&i-j+1<=M)(dp[i+1][j][max(l-1,0)][m+1]+=dp[i][j][l][m])%=mod;
	}
	for(int i=0;i<=k;i++)for(int j=0;j<=k;j++)(ans+=dp[n+M][n][i][j])%=mod;
	printf("%d",ans);
	return 0;
}
