#include<bits/stdc++.h>
using namespace std;
const int maxn=15005;

struct edge{int u,v,w;}e[maxn<<1];
struct Tree_edge{int to,next,w;}E[maxn<<1];
int n,m,k,head[maxn],tot,ffa[maxn],res,dis[maxn][16],dep[maxn],fa[maxn][16];
char c;

inline void read(int& x)
{
	x=0,c=getchar();
	while(!isdigit(c))c=getchar();
	while(isdigit(c))x=x*10+c-'0',c=getchar();
}
inline bool operator < (edge a,edge b){return a.w<b.w;}
inline int find(int x){return x==ffa[x]?x:ffa[x]=find(ffa[x]);}
inline void add(int u,int v,int w)
{
	E[++tot]=(Tree_edge){v,head[u],w},head[u]=tot;
	E[++tot]=(Tree_edge){u,head[v],w},head[v]=tot;
}
inline void dfs(int u,int fffa)
{
	for(int i=1;(1<<i)<=dep[u];i++)
		fa[u][i]=fa[fa[u][i-1]][i-1],dis[u][i]=max(dis[u][i-1],dis[fa[u][i-1]][i-1]);
	for(int i=head[u];i;i=E[i].next)if(E[i].to!=fffa)
		dep[E[i].to]=dep[u]+1,fa[E[i].to][0]=u,dis[E[i].to][0]=E[i].w,dfs(E[i].to,u);
}
inline int lca(int u,int v)
{
	if(dep[u]<dep[v])swap(u,v);
	for(int i=14;dep[u]-dep[v];i--)if((1<<i)<=dep[u]-dep[v])u=fa[u][i];
	if(u==v)return u;
	for(int i=14;~i;i--)if(fa[u][i]!=fa[v][i])u=fa[u][i],v=fa[v][i];
	return fa[u][0];
}
inline int ask(int u,int v)
{
	int ans=0;
	for(int i=14;dep[u]-dep[v];i--)if((1<<i)<=dep[u]-dep[v])
		ans=max(ans,dis[u][i]),u=fa[u][i];
	return ans;
}

int main()
{
	read(n),read(m),read(k);
	for(int i=1;i<=n;i++)ffa[i]=i;
	for(int i=1;i<=m;i++)read(e[i].u),read(e[i].v),read(e[i].w);
	sort(e+1,e+m+1);
	for(int i=1;i<=m&&res<n-1;i++)
	{
		int f1=find(e[i].u),f2=find(e[i].v);
		if(f1==f2)continue;
		ffa[f1]=f2,add(e[i].u,e[i].v,e[i].w),res++;
	}
	dfs(1,-1);
	for(int i=1,u,v;i<=k;i++)
	{
		read(u),read(v);
		int f=lca(u,v);
		printf("%d\n",max(ask(u,f),ask(v,f)));
	}
	return 0;
}
