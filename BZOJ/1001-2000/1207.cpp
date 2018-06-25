#include<bits/stdc++.h>
using namespace std;

int n,m,t[10005],x[10005],y[10005],dp[10005],ans;

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)scanf("%d%d%d",t+i,x+i,y+i);
	fill(dp+1,dp+m+1,1);
	for(int i=2;i<=m;i++)for(int j=1;j<i;j++)
		if(abs(x[i]-x[j])+abs(y[i]-y[j])<=t[i]-t[j])dp[i]=max(dp[i],dp[j]+1);
	for(int i=1;i<=m;i++)ans=max(ans,dp[i]);
	printf("%d",ans);
	return 0;
}
