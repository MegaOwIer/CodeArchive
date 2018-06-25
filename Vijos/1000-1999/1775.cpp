#include<bits/stdc++.h>
using namespace std;

int n,m,a[355],cnt[5],dp[45][45][45][45],pos,now;

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)scanf("%d",a+i);
	for(int i=1,b;i<=m;i++)scanf("%d",&b),cnt[b]++;
	dp[0][0][0][0]=a[0];
	for(int i=0;i<=cnt[1];i++)for(int j=0;j<=cnt[2];j++)
		for(int k=0;k<=cnt[3];k++)for(int l=0;l<=cnt[4];l++)
		{
			pos=i+j*2+k*3+l*4,now=dp[i][j][k][l];
			if(i<cnt[1])dp[i+1][j][k][l]=max(dp[i+1][j][k][l],now+a[pos+1]);
			if(j<cnt[2])dp[i][j+1][k][l]=max(dp[i][j+1][k][l],now+a[pos+2]);
			if(k<cnt[3])dp[i][j][k+1][l]=max(dp[i][j][k+1][l],now+a[pos+3]);
			if(l<cnt[4])dp[i][j][k][l+1]=max(dp[i][j][k][l+1],now+a[pos+4]);
		}
	printf("%d",dp[cnt[1]][cnt[2]][cnt[3]][cnt[4]]);
	return 0;
}
