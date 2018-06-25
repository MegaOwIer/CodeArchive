#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=300005;

struct edge {int to,next;}e[maxn<<1];
int n,a[maxn],tot,head[maxn],dep[maxn],fa[maxn][22],siz[maxn];
bool vis[maxn];

void add(int u,int v)
{
	e[++tot]=(edge){v,head[u]},head[u]=tot;
	e[++tot]=(edge){u,head[v]},head[v]=tot;
}
void dfs1(int u)
{
	for(int i=head[u];i;i=e[i].next)  if(!vis[e[i].to])
	{
		vis[e[i].to]=1;  fa[e[i].to][0]=u;
		dep[e[i].to]=dep[u]+1;
		dfs1(e[i].to);
	}
}
void init()
{
	for(int j=1;j<=19;j++)  for(int i=1;i<=n;i++)
	{
		if((1<<j)>dep[i])  continue;
		fa[i][j]=fa[fa[i][j-1]][j-1];
	}
}
int lca(int u,int v)
{
	if(dep[u]<dep[v])  swap(u,v);
	for(int i=19;dep[u]!=dep[v];i--)  if((dep[u]-dep[v])>=(1<<i))  u=fa[u][i];
	if(u==v)  return u;
	for(int i=19;i>=0;i--)  if(fa[u][i]!=fa[v][i])  u=fa[u][i],v=fa[v][i];
	return fa[u][0];
}
void dfs2(int u)
{
	for(int i=head[u];i;i=e[i].next)  if(e[i].to!=fa[u][0])
	{
		dfs2(e[i].to);
		siz[u]+=siz[e[i].to];
	}
}

int main()
{
	scanf("%d",&n);  vis[1]=1;
	for(int i=1;i<=n;i++)  scanf("%d",a+i);
	for(int i=1,aa,b;i<n;i++)  {scanf("%d%d",&aa,&b);  add(aa,b);}
	dfs1(1);  init();
	for(int i=1;i<n;i++)
	{
		int u=a[i],v=a[i+1],f=lca(u,v),p=fa[f][0];
		siz[u]++,siz[v]++,siz[f]--,siz[p]--; 
	}
	dfs2(1);
	for(int i=1;i<=n;i++)  printf("%d\n",i==a[1]?siz[i]:siz[i]-1);
	return 0;
}
