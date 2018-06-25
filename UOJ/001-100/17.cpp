#include<bits/stdc++.h>
using namespace std;
const int maxn=10005;

int n,m,k,x[maxn],y[maxn],dp[2][1005],l[maxn],h[maxn],I,cnt,ans=1e9;
char c;
bool fail;

inline void read(int& x)
{
	x=0,c=getchar();
	while(!isdigit(c))c=getchar();
	while(isdigit(c))x=x*10+c-'0',c=getchar();
}

int main()
{
	read(n),read(m),read(k);
	for(int i=0;i<n;i++)read(x[i]),read(y[i]);
	fill(h,h+n+1,m+1),fill(l,l+n+1,0);
	for(int i=1,p;i<=k;i++)read(p),read(l[p]),read(h[p]);
	for(int i=0;i<n;i++)
	{
		I=i&1,fail=1;
		if(h[i+1]!=m+1)cnt++;
		fill(dp[I^1]+1,dp[I^1]+m+1,1e9);
		for(int j=l[i+1]+y[i]+1;j<h[i];j++)
		{
			if(j-y[i]>=h[i+1])break;
			dp[I^1][j-y[i]]=min(dp[I^1][j-y[i]],dp[I][j]);
		}
		for(int j=1,nj=1+x[i];j<=m;j++)
		{
			dp[I][nj]=min(dp[I][nj],dp[I][j]+1);
			if(nj<m)nj++;
		}
		for(int j=max(1,l[i+1]-x[i]+1),nj=j+x[i];j<=m;j++)
		{
			if(nj>=h[i+1])break;
			dp[I^1][nj]=min(dp[I^1][nj],dp[I][j]+1);
			if(nj<m)nj++;
		}
		for(int j=l[i+1]+1;j<h[i+1];j++)if(dp[I^1][j]<1e9){fail=0;break;}
		if(fail)printf("0\n%d",cnt-1),exit(0);
	}
	for(int i=1;i<=m;i++)ans=min(ans,dp[n&1][i]);
	printf("1\n%d",ans);
	return 0;
}
