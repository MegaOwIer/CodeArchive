#include<bits/stdc++.h>
using namespace std;
const int maxn=10005;

int n,m,d[maxn],dp[maxn][505];
char c;

inline void read(int& x)
{
	c=getchar(),x=0;
	while(!isdigit(c))c=getchar();
	while(isdigit(c))x=x*10+c-48,c=getchar();
}

int main()
{
	read(n),read(m);
	for(int i=1;i<=n;i++)read(d[i]);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)dp[i][j]=dp[i-1][j-1]+d[i];
		dp[i][0]=dp[i-1][0];
		for(int j=1;j<=m&&j<i;j++)dp[i][0]=max(dp[i][0],dp[i-j][j]);
	}
	printf("%d",dp[n][0]);
	return 0;
}
