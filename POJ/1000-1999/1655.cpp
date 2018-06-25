#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define clear(a) memset(a,0,sizeof(a))
const int maxn=20005;

struct edge {int t,n;}e[maxn<<1];
int T,n,tot,head[maxn],fa[maxn],siz[maxn],mx[maxn],id;
bool vis[maxn];

inline int read()
{
	int ans=0;  char ch=getchar();
	while(ch<'0'||ch>'9')  ch=getchar();
	while(ch>='0'&&ch<='9')  ans=ans*10+ch-'0',ch=getchar();
	return ans;
}
inline void init()
{
	tot=0;  clear(head);  clear(siz);  clear(mx);
	clear(vis);  vis[1]=1;  id=1;
}
inline void add(int u,int v)
{
	e[++tot].t=v,e[tot].n=head[u],head[u]=tot;
	e[++tot].t=u,e[tot].n=head[v],head[v]=tot;
}
inline void dfs(int u)
{
	for(int i=head[u];i;i=e[i].n)  if(!vis[e[i].t])
	{
		vis[e[i].t]=1;  fa[e[i].t]=u;
		dfs(e[i].t);
		siz[u]+=siz[e[i].t];
		if(siz[e[i].t]>mx[u])  mx[u]=siz[e[i].t];
	}
	++siz[u];
}

int main()
{
	T=read();
	while(T--)
	{
		init();
		n=read();
		for(int i=1,a,b;i<n;i++)  a=read(),b=read(),add(a,b);
		dfs(1);
		for(int i=1;i<=n;i++)  if(n-siz[i]>mx[i])  mx[i]=n-siz[i];
		for(int i=2;i<=n;i++)  if(mx[i]<mx[id])  id=i;
		printf("%d %d\n",id,mx[id]);
	}
	return 0;
}
