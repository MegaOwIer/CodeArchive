#include<bits/stdc++.h>
using namespace std;
const int maxn=50005;

int n,l,a,dp[maxn],pre[1000005],k,ans;
char c;

inline void read(int& x)
{
	x=0,c=getchar();
	while(!isdigit(c))c=getchar();
	while(isdigit(c))x=x*10+c-48,c=getchar();
}

int main()
{
	read(n),read(l);
	for(int i=1;i<=n;i++)
	{
		read(a);
		for(int j=1;j<=sqrt(a);j++)if(a%j==0)
		{
			if(j>=l)dp[i]=max(dp[i],dp[pre[j]]+1),pre[j]=i;
			k=a/j;
			if(k>=l&&k!=j)dp[i]=max(dp[i],dp[pre[k]]+1),pre[k]=i;
		}
		ans=max(ans,dp[i]);
	}
	printf("%d",ans);
	return 0;
}
