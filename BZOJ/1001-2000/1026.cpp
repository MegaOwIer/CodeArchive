#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int a,b,dp[12][12],digit[12];

inline LL sol(int u)
{
	if(!u)return 0;
	LL ans=0;
	int lth=0;
	for(int i=u;i;i/=10)digit[++lth]=i%10;
	for(int i=1;i<lth;i++)for(int j=1;j<=9;j++)ans+=dp[i][j];
	for(int i=1;i<digit[lth];i++)ans+=dp[lth][i];
	for(int i=lth-1;i;i--)
	{
		for(int j=0;j<digit[i];j++)if(abs(digit[1+i]-j)>1)ans+=dp[i][j];
		if(abs(digit[i+1]-digit[i])<2)break;
	}
	return ans;
}

int main()
{
	for(int i=0;i<=9;i++)dp[1][i]=1;
	for(int i=2;i<=10;i++)for(int j=0;j<=9;j++)for(int k=0;k<=9;k++)if(abs(j-k)>1)dp[i][j]+=dp[i-1][k];
	scanf("%d%d",&a,&b);
	printf("%lld",sol(b+1)-sol(a));
	return 0;
}
