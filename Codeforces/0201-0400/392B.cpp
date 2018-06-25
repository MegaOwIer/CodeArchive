#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int t[4][4],n;
LL dp[42][4][4][4];

LL Dp(int n,int a1,int a2,int a3)
{
	if(!n)return 0;
	if(dp[n][a1][a2][a3])return dp[n][a1][a2][a3];
	LL b1=Dp(n-1,a1,a3,a2)+t[a1][a3]+Dp(n-1,a2,a1,a3);
	LL b2=Dp(n-1,a1,a2,a3)+t[a1][a2]+Dp(n-1,a3,a2,a1)+t[a2][a3]+Dp(n-1,a1,a2,a3);
	return dp[n][a1][a2][a3]=min(b1,b2);
}

int main()
{
	for(int i=1;i<4;i++)for(int j=1;j<4;j++)scanf("%d",&t[i][j]);
	scanf("%d",&n);
	printf("%lld",Dp(n,1,2,3));
	return 0;
}
