#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn=100005;

struct edge{int u,v,w;}e[300005];
struct Tree_edge{int to,next,w;}E[maxn<<1];
int n,m,tot,head[maxn],cnt,fa[maxn],dep[maxn],pa[maxn][20],d1[maxn][20],d2[maxn][20],mn=1e9;
LL ans;
bool used[300005];
char c;

inline void read(int& x)
{
	c=getchar(),x=0;
	while(!isdigit(c))c=getchar();
	while(isdigit(c))x=x*10+c-48,c=getchar();
}
inline bool operator < (edge a,edge b){return a.w<b.w;}
inline int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
inline void dfs(int u)
{
	for(int i=1;(1<<i)<=dep[u];i++)
	{
		pa[u][i]=pa[pa[u][i-1]][i-1];
		d1[u][i]=max(d1[u][i-1],d1[pa[u][i-1]][i-1]);
		if(d1[u][i-1]==d1[pa[u][i-1]][i-1])
			d2[u][i]=max(d2[u][i-1],d2[pa[u][i-1]][i-1]);
		else
		{
			d2[u][i]=min(d1[u][i-1],d1[pa[u][i-1]][i-1]);
			d2[u][i]=max(d2[u][i],d2[u][i-1]);
			d2[u][i]=max(d2[u][i],d2[pa[u][i-1]][i-1]);
		}
	}
	for(int i=head[u];i;i=E[i].next)if(E[i].to!=pa[u][0])
	{
		pa[E[i].to][0]=u,d1[E[i].to][0]=E[i].w;
		dep[E[i].to]=dep[u]+1,dfs(E[i].to);
	}
}
inline void add(int u,int v,int w)
{
	E[++tot]=(Tree_edge){v,head[u],w},head[u]=tot;
	E[++tot]=(Tree_edge){u,head[v],w},head[v]=tot;
}
inline int lca(int u,int v)
{
	if(dep[v]>dep[u])swap(u,v);
	for(int i=16;dep[u]-dep[v];i--)if((1<<i)<=dep[u]-dep[v])u=pa[u][i];
	if(u!=v)
	{
		for(int i=16;~i;i--)if(pa[u][i]!=pa[v][i])u=pa[u][i],v=pa[v][i];
		u=pa[u][0];
	}
	return u;
}
inline void wk(int u,int v,int w)
{
	int mx1=0,mx2=0;
	for(int i=16;dep[u]-dep[v];i--)if((1<<i)<=dep[u]-dep[v])
	{
		if(d1[u][i]>mx1)mx2=mx1,mx1=d1[u][i];
		mx2=max(mx2,d2[u][i]),u=pa[u][i];
	}
	if(mx1!=w)mn=min(mn,w-mx1);
	else mn=min(mn,w-mx2);
}

int main()
{
	read(n),read(m);
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=m;i++)read(e[i].u),read(e[i].v),read(e[i].w);
	sort(e+1,e+m+1);
	for(int i=1;cnt<n;i++)
	{
		int f1=find(e[i].u),f2=find(e[i].v);
		if(f1==f2)continue;
		fa[f1]=f2,ans+=e[i].w,cnt++,used[i]=1;
		add(e[i].u,e[i].v,e[i].w);
	}
	dfs(1);
	for(int i=1;i<=m;i++)if(!used[i])
	{
		int LCA=lca(e[i].u,e[i].v);
		wk(e[i].u,LCA,e[i].w),wk(e[i].v,LCA,e[i].w);
	}
	printf("%lld",ans+mn);
	return 0;
}
