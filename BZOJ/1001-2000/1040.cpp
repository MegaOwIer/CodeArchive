#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn=1000005;

struct edge{int to,next;bool used;}e[maxn<<1];
int n,tot=1,head[maxn],l,r,w[maxn];
LL ans,mx,dp[maxn][2];
bool vis[maxn];
char c;

inline void read(int& x)
{
	x=0,c=getchar();
	while(!isdigit(c))c=getchar();
	while(isdigit(c))x=x*10+c-'0',c=getchar();
}
inline void add(int u,int v)
{
	e[++tot]=(edge){v,head[u]},head[u]=tot;
	e[++tot]=(edge){u,head[v]},head[v]=tot;
}
inline void dfs(int u,int fa)
{
	vis[u]=1;
	for(int i=head[u];i;i=e[i].next)if(e[i].to!=fa)
	{
		if(vis[e[i].to]){l=u,r=e[i].to,e[i].used=e[i^1].used=1;return;}
		dfs(e[i].to,u);
	}
}
inline void Tree_dp(int u,int fa,int cant)
{
	vis[u]=1;
	dp[u][1]=(u==cant?0:w[u]),dp[u][0]=0;
	for(int i=head[u];i;i=e[i].next)if(e[i].to!=fa&&!e[i].used)
	{
		Tree_dp(e[i].to,u,cant);
		dp[u][1]+=dp[e[i].to][0];
		dp[u][0]+=max(dp[e[i].to][0],dp[e[i].to][1]);
	}
}

int main()
{
	read(n);
	for(int i=1,u;i<=n;i++)read(w[i]),read(u),add(i,u);
	for(int i=1;i<=n;i++)if(!vis[i])
	{
		mx=0,l=r=0,dfs(i,-1);
		if(l)
		{
			Tree_dp(l,-1,r),mx=max(dp[l][0],dp[l][1]);
			Tree_dp(r,-1,l),mx=max(mx,max(dp[r][0],dp[r][1]));
		}
		else Tree_dp(i,-1,0),mx=max(dp[i][0],dp[i][1]);
		ans+=mx;
	}
	printf("%lld",ans);
	return 0;
}
