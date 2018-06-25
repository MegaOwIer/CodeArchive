#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int T,maxp,W,h,t,q[2005],dp[2005][2005],ap,bp,as,bs,ans=1<<31;
char c;

int main()
{
	scanf("%d%d%d",&T,&maxp,&W);
	memset(dp,-0x3f,sizeof(dp));
	for(int i=1;i<=W+1;i++)
	{
		scanf("%d%d%d%d",&ap,&bp,&as,&bs);
		for(int j=0;j<=as;j++)dp[i][j]=-ap*j;
		for(int j=0;j<=maxp;j++)dp[i][j]=max(dp[i][j],dp[i-1][j]);
		ans=max(ans,dp[i][0]);
	}
	for(int i=W+2;i<=T;i++)
	{
		scanf("%d%d%d%d",&ap,&bp,&as,&bs),h=1,t=0;
		for(int j=0;j<=as;j++)dp[i][j]=-ap*j;
		for(int j=0;j<=maxp;j++)dp[i][j]=max(dp[i][j],dp[i-1][j]);
		for(int j=0;j<=maxp;j++)
		{
			while(q[h]<j-as&&h<=t)h++;
			while(dp[i-W-1][q[t]]+ap*q[t]<=dp[i-W-1][j]+ap*j&&h<=t)t--;
			q[++t]=j;
			if(h<=t)dp[i][j]=max(dp[i][j],dp[i-W-1][q[h]]+ap*(q[h]-j));
		}
		h=1,t=0;
		for(int j=maxp;~j;j--)
		{
			while(q[h]>j+bs&&h<=t)h++;
			while(dp[i-W-1][q[t]]+bp*q[t]<=dp[i-W-1][j]+bp*j&&h<=t)t--;
			q[++t]=j;
			if(h<=t)dp[i][j]=max(dp[i][j],dp[i-W-1][q[h]]+bp*(q[h]-j));
		}
		ans=max(ans,dp[i][0]);
	}
	printf("%d",ans);
	return 0;
}
