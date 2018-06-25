#include<bits/stdc++.h>
using namespace std;
namespace FastIO
{
	static char c;
	static int buf[22],top;
	template<typename T>inline void read(T& x)
	{
		x=0,c=getchar();
		while(!isdigit(c))c=getchar();
		while(isdigit(c))x=x*10+c-'0',c=getchar();
	}
	template<typename T>inline void write(T x)
	{
		top=0;
		do buf[top++]=x%10,x/=10;while(x);
		while(top)putchar(48+buf[--top]);
		putchar('\n');
	}
}
using FastIO::read;
using FastIO::write;
const int maxn=10250;

struct edge
{
	int to,f,c;
	edge* r;
	edge(){}
	edge(int to,int f,int c,edge* r):to(to),f(f),c(c),r(r){}
}pool[maxn<<1],*G[205],*pre[205];
int S,T,n,m,u[maxn],v[maxn],f[maxn],c[maxn],deg[205],tot,dis[205],now,flow,cost,cnt;
int a[105],b[105],C[105][105];
queue<int> q;
bool inq[205],vis[205];

inline void add(int U,int V,int F,int C)
{
	deg[U]++,deg[V]++;
	++tot,u[tot]=U,v[tot]=V,f[tot]=F,c[tot]=C;
}
inline bool bfs()
{
	memset(vis+1,0,T),memset(dis+1,0,T<<2),q.push(S),vis[S]=1;
	while(!q.empty())
	{
		now=q.front(),q.pop(),inq[now]=0;
		for(edge* i=G[now];i!=G[now+1];i++)if(i->f)
			if(!vis[i->to]||dis[i->to]>dis[now]+i->c)
			{
				dis[i->to]=dis[now]+i->c,pre[i->to]=i;
				if(!inq[i->to])q.push(i->to),inq[i->to]=1,vis[i->to]=1;
			}
	}
	return vis[T];
}

int main()
{
	read(m),read(n),T=1+(S=n+m+1);
	for(int i=1;i<=m;i++)read(a[i]),add(S,i,a[i],0);
	for(int i=1;i<=n;i++)read(b[i]),add(m+i,T,b[i],0);
	for(int i=1;i<=m;i++)for(int j=1;j<=n;j++)read(C[i][j]),add(i,j+m,2147483647,C[i][j]);
	G[1]=pool;for(int i=1;i<=T;i++)G[i+1]=G[i]+deg[i];
	for(int i=1;i<=tot;i++)
	{
		deg[u[i]]--,deg[v[i]]--;
		G[u[i]][deg[u[i]]]=edge(v[i],f[i],c[i],G[v[i]]+deg[v[i]]);
		G[v[i]][deg[v[i]]]=edge(u[i],0,-c[i],G[u[i]]+deg[u[i]]);
	}
	while(bfs())
	{
		flow=1e9;
		for(int i=T;i!=S;i=pre[i]->r->to)flow=min(flow,pre[i]->f);
		cost+=flow*dis[T];
		for(int i=T;i!=S;i=pre[i]->r->to)pre[i]->f-=flow,pre[i]->r->f+=flow;
	}
	write(cost),cost=0;
	for(int i=1;i<=T;i++)deg[i]=G[i+1]-G[i];
	for(int i=1;i<=tot;i++)
	{
		deg[u[i]]--,deg[v[i]]--;
		G[u[i]][deg[u[i]]]=edge(v[i],f[i],-c[i],G[v[i]]+deg[v[i]]);
		G[v[i]][deg[v[i]]]=edge(u[i],0,c[i],G[u[i]]+deg[u[i]]);
	}
	while(bfs())
	{
		flow=1e9;
		for(int i=T;i!=S;i=pre[i]->r->to)flow=min(flow,pre[i]->f);
		cost+=flow*dis[T];
		for(int i=T;i!=S;i=pre[i]->r->to)pre[i]->f-=flow,pre[i]->r->f+=flow;
	}
	write(-cost);
	return 0;
}
