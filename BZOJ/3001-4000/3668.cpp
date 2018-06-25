#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;

int bit[maxn][35],op[maxn],dp[35][2],ans,n,m,sum;
char c,ch;

inline void read(int& x)
{
	x=0,ch=getchar();
	while(!isdigit(ch))ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
}
inline void getalpha(){do c=getchar();while(!isalpha(c));}

int main()
{
	read(n),read(m);
	for(int i=1,x;i<=n;i++)
	{
		getalpha(),read(x);
		if(c=='A')op[i]=1;
		else if(c=='O')op[i]=2;
		else op[i]=3;
		for(int j=0;x;j++)bit[i][j]=x&1,x>>=1;
	}
	for(int i=30;~i;i--)
	{
		dp[i][1]=1;
		for(int j=1;j<=n;j++)
			if(op[j]==1)dp[i][0]&=bit[j][i],dp[i][1]&=bit[j][i];
			else if(op[j]==2)dp[i][0]|=bit[j][i],dp[i][1]|=bit[j][i];
			else dp[i][0]^=bit[j][i],dp[i][1]^=bit[j][i];
		dp[i][0]<<=i,dp[i][1]<<=i;
	}
	for(int i=30;~i;i--)
	{
		if(dp[i][0])ans+=dp[i][0];
		else if(dp[i][1]&&sum+(1<<i)<=m)ans+=dp[i][1]; 
	}
	printf("%d",ans);
	return 0;
}

