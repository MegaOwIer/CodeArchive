#include<bits/stdc++.h>
using namespace std;
const int maxn=10005;

struct edge{int to,next;}e[50005],d[50005];
int n,m,head[maxn],tot,low[maxn],dfn[maxn],cnt,scc,bl[maxn],siz[maxn],h[maxn],ans;
char c;
bool vis[maxn],ins[maxn];
stack<int> s;

inline void read(int& x)
{
	x=0,c=getchar();
	while(!isdigit(c))c=getchar();
	while(isdigit(c))x=x*10+c-48,c=getchar();
}
inline void dfs(int u)
{
	int now=-1;
	vis[u]=ins[u]=1,low[u]=dfn[u]=++cnt,s.push(u);
	for(int i=head[u];i;i=e[i].next)
	{
		if(!vis[e[i].to])
		{
			dfs(e[i].to);
			low[u]=min(low[u],low[e[i].to]);
		}
		else if(ins[e[i].to])low[u]=min(low[u],dfn[e[i].to]);
	}
	if(low[u]==dfn[u])
	{
		scc++;
		while(now!=u)now=s.top(),s.pop(),ins[now]=0,bl[now]=scc,++siz[scc];
	}
}

int main()
{
	read(n),read(m);
	for(int i=1,u,v;i<=m;i++)read(u),read(v),e[i]=(edge){v,head[u]},head[u]=i;
	for(int i=1;i<=n;i++)if(!vis[i])dfs(i);
	for(int i=1;i<=n;i++)for(int j=head[i];j;j=e[j].next)if(bl[i]!=bl[e[j].to])
		d[++tot]=(edge){bl[e[j].to],h[bl[i]]},h[bl[i]]=tot;
	for(int i=1;i<=scc;i++)if(!h[i])if(ans)exit((puts("0"),0));else ans=siz[i];
	return printf("%d",ans),0;
	
}
