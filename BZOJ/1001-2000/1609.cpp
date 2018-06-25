#include<bits/stdc++.h>
using namespace std;
const int maxn=30005;

int n,a[maxn],dp[maxn][4],ans;
char c;

inline void read(int& x)
{
	c=getchar(),x=0;
	while(!isdigit(c))c=getchar();
	while(isdigit(c))x=x*10+c-48,c=getchar();
}

int main()
{
	read(n);
	for(int i=1;i<=n;i++)read(a[i]);
	for(int i=1;i<=n;i++)
	{
		dp[i][1]=dp[i-1][1]+(a[i]!=1);
		dp[i][2]=min(dp[i-1][1],dp[i-1][2])+(a[i]!=2);
		dp[i][3]=min(min(dp[i-1][1],dp[i-1][2]),dp[i-1][3])+(a[i]!=3);
	}
	ans=min(dp[n][1],min(dp[n][2],dp[n][3]));
	for(int i=1;i<=n;i++)
	{
		dp[i][3]=dp[i-1][3]+(a[i]!=3);
		dp[i][2]=min(dp[i-1][3],dp[i-1][2])+(a[i]!=2);
		dp[i][1]=min(min(dp[i-1][3],dp[i-1][2]),dp[i-1][1])+(a[i]!=1);
	}
	ans=min(min(ans,dp[n][1]),min(dp[n][2],dp[n][3]));
	printf("%d",ans);
	return 0;
}
