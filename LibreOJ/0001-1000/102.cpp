#include<bits/stdc++.h>
using namespace std;
namespace FastIO
{
	static char c;
	template<typename T>
	inline void read(T& x)
	{
		c=getchar(),x=0;
		while(!isdigit(c))c=getchar();
		while(isdigit(c))x=x*10+c-'0',c=getchar();
	}
}
using FastIO::read;
const int maxn=15005;

struct edge
{
	int to,c,w;
	edge* r;
	edge(){}
	edge(int to,int c,int w,edge* r):to(to),c(c),w(w),r(r){}
}*G[405],*pre[405],pool[maxn<<1];
int n,m,s[maxn],t[maxn],c[maxn],w[maxn],deg[405],dis[405],ans1,ans2,f;
bool inq[405],vis[405];
queue<int> q;

inline bool spfa()
{
	q.push(1),fill(dis+2,dis+n+1,2147483647);
	memset(vis+1,0,n);
	while(!q.empty())
	{
		int now=q.front();q.pop(),inq[now]=0,vis[now]=1;
		for(edge* i=G[now];i!=G[now+1];i++)if(i->c&&dis[now]+i->w<dis[i->to])
		{
			dis[i->to]=dis[now]+i->w,pre[i->to]=i;
			if(!inq[i->to])q.push(i->to),inq[i->to]=1;
		}
	}
	return vis[n];
}

int main()
{
	read(n),read(m),G[1]=pool;
	for(int i=1;i<=m;i++)
		read(s[i]),read(t[i]),read(c[i]),read(w[i]),deg[s[i]]++,deg[t[i]]++;
	for(int i=1;i<=n;i++)G[i+1]=G[i]+deg[i];
	for(int i=1;i<=m;i++)
	{
		--deg[s[i]],--deg[t[i]];
		G[s[i]][deg[s[i]]]=edge(t[i],c[i],w[i],G[t[i]]+deg[t[i]]);
		G[t[i]][deg[t[i]]]=edge(s[i],0,-w[i],G[s[i]]+deg[s[i]]);
	}
	while(spfa())
	{
		f=2147483647;
		for(int i=n;i!=1;i=pre[i]->r->to)f=min(f,pre[i]->c);
		for(int i=n;i!=1;i=pre[i]->r->to)
		{
			pre[i]->c-=f,pre[i]->r->c+=f;
			ans2+=f*pre[i]->w;
		}
		ans1+=f;
	}
	printf("%d %d",ans1,ans2);
	return 0;
}
