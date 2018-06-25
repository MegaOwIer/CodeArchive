#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
#define clr(a,s) memset(a+1,0,s)
const int maxn=10005;

struct edge {int to,next,w;}e[maxn<<1];
int n,k,tot,head[maxn],mx[maxn],siz[maxn],G,dis[maxn],c;
bool vis[maxn];

inline int read()
{
	int ans=0;  char ch=getchar();
	while(ch<'0'||ch>'9')  ch=getchar();
	while(ch>='0'&&ch<='9')  ans=ans*10+ch-'0',ch=getchar();
	return ans;
}
inline void add(int u,int v,int w)
{
	e[++tot].to=v,e[tot].next=head[u],e[tot].w=w,head[u]=tot;
	e[++tot].to=u,e[tot].next=head[v],e[tot].w=w,head[v]=tot;
}
inline void init(){tot=0,clr(head,n<<2),clr(vis,n);}
inline void dfsg(int u,int fa)
{
	siz[u]=1;  mx[u]=0;
	for(int i=head[u];i;i=e[i].next)  if(!vis[e[i].to]&&e[i].to!=fa)
	{
		dfsg(e[i].to,u);
		siz[u]+=siz[e[i].to];
		if(siz[e[i].to]>mx[u])  mx[u]=siz[e[i].to];
	}
}
inline void dfsg2(int u,int fa,int tot)
{
	mx[u]=max(mx[u],tot-siz[u]);
	if(mx[u]<=tot/2)  G=u;
	for(int i=head[u];i;i=e[i].next)  if(!vis[e[i].to]&&e[i].to!=fa)  dfsg2(e[i].to,u,tot);
}
inline int getg(int u)
{
	dfsg(u,-1);
	dfsg2(u,-1,siz[u]);
	return G;
}
inline void dfs(int u,int fa,int lth)
{
	dis[++c]=lth;
	for(int i=head[u];i;i=e[i].next)  if(!vis[e[i].to]&&e[i].to!=fa)  dfs(e[i].to,u,lth+e[i].w);
}
inline int solve(int u)
{
	u=getg(u);
	int ans=-1;  dis[c=1]=0;
	for(int i=head[u];i;i=e[i].next)  if(!vis[e[i].to])
	{
		int c0=c;
		dfs(e[i].to,u,e[i].w);
		sort(dis+c0+1,dis+c+1);
		int it=c;
		for(int j=c0+1;j<=c;j++)
		{
			while(dis[it]+dis[j]>k&&it>c0)  --it;
			ans-=it-c0;
		}
	}
	sort(dis+1,dis+c+1);
	int it=c;
	for(int j=1;j<=c;j++)
	{
		while(dis[it]+dis[j]>k&&it)  --it;
		ans+=it;
	}
	vis[u]=1;
	for(int i=head[u];i;i=e[i].next)  if(!vis[e[i].to])  ans+=solve(e[i].to);
	return ans;
}

int main()
{
	while(scanf("%d%d",&n,&k)==2&&n&&k)
	{
		init();
		for(int i=1,u,v,w;i<n;i++)  u=read(),v=read(),w=read(),add(u,v,w);
		printf("%d\n",solve(1)>>1);
	}
	return 0;
}
