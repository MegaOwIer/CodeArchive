#include<bits/stdc++.h>
using namespace std;
const int maxn=10005;
#define lb(x) x&(-x)

int n,k,a[maxn],tr[105],tr2[105],dp[maxn][105],mx,cnt,ans=1e8,ans0;

inline void add(int x,int y){for(;x<=k;x+=lb(x))tr[x]+=y;}
inline int sum(int x){int ans=0;for(;x;x-=lb(x))ans+=tr[x];return ans;}
inline void add2(int x,int y){for(;x<=k;x+=lb(x))tr2[x]+=y;}
inline int sum2(int x){int ans=0;for(;x;x-=lb(x))ans+=tr2[x];return ans;}

int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)scanf("%d",a+i);
	for(int i=n;i;i--)if(~a[i])add2(a[i],1),ans0+=sum2(a[i]-1);
	for(int i=1;i<=n;i++)dp[i][0]=100000000;
	for(int i=1;i<=n;i++)
	{
		if(~a[i])add(a[i],1),add2(a[i],-1);
		else
		{
			cnt++;
			for(int j=1;j<=k;j++)dp[cnt][j]=min(dp[cnt-1][j],dp[cnt][j-1]);
			for(int j=1;j<=k;j++)dp[cnt][j]+=sum(k)-sum(j)+sum2(j-1);
		}
	}
	for(int i=1;i<=k;i++)ans=min(ans,dp[cnt][i]);
	printf("%d",ans+ans0);
	return 0;
}
