#include<bits/stdc++.h>
using namespace std;

int n,m,t,a[55],dp[55][55],tmp,ans[55][2505],res;
char c;

inline int getdigit(){do c=getchar();while(!isdigit(c));return c==49;}

int main()
{
	scanf("%d%d%d",&n,&m,&t);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)a[j]=a[j-1]+getdigit();
		for(int j=1;j<=m;j++)for(int k=1;k<=m;k++)
		{
			dp[k][j]=0;
			for(int l=0;l<k;l++)
			{
				tmp=a[k]-a[l];
				dp[k][j]=max(dp[k][j],dp[l][j-1]+max(tmp,k-l-tmp));
			}
		}
		for(int j=1;j<=t;j++)for(int k=1;k<=m&&k<=j;k++)
			ans[i][j]=max(ans[i][j],ans[i-1][j-k]+dp[m][k]);
	}
	for(int i=1;i<=t;i++)res=max(res,ans[n][i]);
	printf("%d",res);
	return 0;
}
