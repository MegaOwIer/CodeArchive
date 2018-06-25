#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
#define mp make_pair
#define st first
#define nd second

int n,m,f[maxn],g[maxn],pre[maxn];
char s[maxn];
pair<int,int> dp[maxn];

int main()
{
	scanf("%d%s%d",&n,s+1,&m);
	for(int i=n;i;i--)
	{
		if(s[i]=='a')f[i]=1+g[i+1],g[i]=0;
		else if(s[i]=='b')g[i]=1+f[i+1],f[i]=0;
		else f[i]=1+g[i+1],g[i]=1+f[i+1];
	}
	for(int i=1;i<=n;i++)dp[i]=mp(-1e9,1e9);
	for(int i=1;i<=n;i++)pre[i]=pre[i-1]+(s[i]=='?');
	for(int i=0,xx,yy;i<n;i++)
	{
		if(dp[i].st>dp[i+1].st||(dp[i].st==dp[i+1].st&&dp[i].nd<dp[i+1].nd))dp[i+1]=dp[i];
		if(f[i+1]>=m)
		{
			xx=dp[i].st+1;
			yy=dp[i].nd+pre[i+m]-pre[i];
			if(xx>dp[i+m].st||(xx==dp[i+m].st&&yy<dp[i+m].nd))dp[i+m]=mp(xx,yy);
		}
	}
	printf("%d",dp[n].nd);
	return 0;
}
