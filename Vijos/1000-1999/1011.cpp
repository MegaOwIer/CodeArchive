#include<bits/stdc++.h>
using namespace std;

int r,c,a[505][505],dp[505][505],ans;
char ch;

inline void read(int& x)
{
	x=0,ch=getchar();
	while(!isdigit(ch))ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
}
inline int Dp(int u,int v)
{
	if(dp[u][v])return dp[u][v];
	dp[u][v]=1;
	if(u>1&&a[u-1][v]<a[u][v])dp[u][v]=max(Dp(u-1,v)+1,dp[u][v]);
	if(v>1&&a[u][v-1]<a[u][v])dp[u][v]=max(Dp(u,v-1)+1,dp[u][v]);
	if(u<r&&a[u+1][v]<a[u][v])dp[u][v]=max(Dp(u+1,v)+1,dp[u][v]);
	if(v<c&&a[u][v+1]<a[u][v])dp[u][v]=max(Dp(u,v+1)+1,dp[u][v]);
	return dp[u][v];
}

int main()
{
	read(r),read(c);
	for(int i=1;i<=r;i++)for(int j=1;j<=c;j++)read(a[i][j]);
	for(int i=1;i<=r;i++)for(int j=1;j<=c;j++)
		ans=max(ans,Dp(i,j));
	printf("%d",ans);
	return 0;
}
