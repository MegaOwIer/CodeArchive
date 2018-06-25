#include<bits/stdc++.h>
using namespace std;
typedef vector<int>::iterator vit;
typedef long long LL;
const int MXN=1505,MXM=5005,mod=1e9+7;
#define pb push_back

namespace FastIO
{
	char c;
	int bf[22],top;
	template<typename T>inline void read(T& x)
	{
		x=0,c=getchar();
		while(!isdigit(c))c=getchar();
		while(isdigit(c))x=x*10+c-'0',c=getchar();
	}
	template<typename T>inline void write(T x)
	{
		top=0;
		do bf[++top]=x%10,x/=10;while(x);
		while(top)putchar(48+bf[top--]);
		putchar('\n');
	}
}
using FastIO::read;
using FastIO::write;

int n,m,head[MXN],dis[MXN],deg[MXN],u[MXM],v[MXM],w[MXM],a[MXN],b[MXN],ans[MXM];
vector<int> g[MXN];
queue<int> q;
char vis[MXN],onw[MXM];

inline void SPFA(int S)
{
	int now;
	vit i;
	memset(vis+1,0,sizeof(char)*n);
	memset(dis+1,0x3f,sizeof(int)*n);
	dis[S]=0,q.push(S);
	while(!q.empty())
	{
		now=q.front(),q.pop(),vis[now]=0;
		for(i=g[now].begin();i!=g[now].end();++i)
			if(dis[v[*i]]>dis[now]+w[*i])
			{
				dis[v[*i]]=dis[now]+w[*i];
				if(!vis[v[*i]])q.push(v[*i]),vis[v[*i]]=1;
			}
	}
}
inline void dfs1(int u)
{
	if(vis[u])return;
	vis[u]=1;
	for(vit i=g[u].begin();i!=g[u].end();++i)
		if(dis[v[*i]]==dis[u]+w[*i])deg[v[*i]]++,dfs1(v[*i]);
}
inline void dfs2(int u)
{
	for(vit i=g[u].begin();i!=g[u].end();++i)
		if(dis[v[*i]]==dis[u]+w[*i])
		{
			onw[*i]=1;
			a[v[*i]]=(a[v[*i]]+a[u])%mod;
			if(!--deg[v[*i]])dfs2(v[*i]);
		}
}
inline void dfs3(int u)
{
	b[u]=1;
	for(vit i=g[u].begin();i!=g[u].end();++i)
		if(dis[v[*i]]==dis[u]+w[*i])
		{
			if(b[v[*i]]==0)dfs3(v[*i]);
			b[u]=(b[u]+b[v[*i]])%mod;
		}
}

int main()
{
	read(n),read(m);
	for(int i=1;i<=m;i++)
		read(u[i]),read(v[i]),read(w[i]),g[u[i]].pb(i);
	for(int i=1,j;i<=n;i++)
	{
		SPFA(i);
		memset(vis+1,0,sizeof(char)*n),dfs1(i);
		memset(onw+1,0,sizeof(char)*m);
		memset(a+1,0,sizeof(int)*n);
		memset(b+1,0,sizeof(int)*n);
		a[i]=1,dfs2(i),dfs3(i);
		for(j=1;j<=m;j++)if(onw[j])ans[j]=(ans[j]+(LL)a[u[j]]*b[v[j]])%mod;
	}
	for(int i=1;i<=m;i++)write(ans[i]);
	return 0;
}
