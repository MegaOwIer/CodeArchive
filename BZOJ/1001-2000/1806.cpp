#include<bits/stdc++.h>
using namespace std;

int n,dp[2][4][4][4][4],k,tmp,ans;
char c;

inline int getk()
{
	do c=getchar();while(!isalpha(c));
	if(c=='M')return 1;
	if(c=='F')return 2;
	return 3;
}
inline int wk(int a,int b,int c)
{
	int tmp=1;
	if(a&&a!=b&&a!=c)tmp++;
	if(b&&b!=c)tmp++;
	return tmp;
}

int main()
{
	scanf("%d",&n),memset(dp,-1,sizeof(dp));
	dp[0][0][0][0][0]=0;
	for(int i=1;i<=n;i++)
	{
		k=getk();
		for(int a1=0;a1<4;a1++)for(int a2=0;a2<4;a2++)for(int b1=0;b1<4;b1++)for(int b2=0;b2<4;b2++)
		{
			if(!~dp[i&1^1][a1][a2][b1][b2])continue;
			tmp=wk(a1,a2,k);
			dp[i&1][a2][k][b1][b2]=max(dp[i&1][a2][k][b1][b2],tmp+dp[i&1^1][a1][a2][b1][b2]);
			tmp=wk(b1,b2,k);
			dp[i&1][a1][a2][b2][k]=max(dp[i&1][a1][a2][b2][k],tmp+dp[i&1^1][a1][a2][b1][b2]);
		}
	}
	for(int a1=0;a1<4;a1++)for(int a2=0;a2<4;a2++)
		for(int b1=0;b1<4;b1++)for(int b2=0;b2<4;b2++)
			ans=max(ans,dp[n&1][a1][a2][b1][b2]);
	printf("%d",ans);
	return 0;
}
