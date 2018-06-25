#include<bits/stdc++.h>
using namespace std;
const int maxn=300000;
#define REF(i,u) for(int i=head[u];i;i=e[i].next)if(e[i].to!=fa[u][0])
#define RVC(i,a) for(i=a.begin();i!=a.end();++i)

struct edge{int to,next;}e[maxn<<1];
int n,m,tot,head[maxn],w[maxn],fa[maxn][20],dep[maxn],maxd;
int s[maxn],t[maxn],Lca[maxn],lth[maxn];
int val[maxn],tong[maxn],ans[maxn],num[maxn];
char c;
vector<int> cnt[maxn],cnt2[maxn],cnt3[maxn];
vector<int>::iterator it;

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
inline void dfs(int u)
{
	for(int i=1;(1<<i)<=dep[u];i++)fa[u][i]=fa[fa[u][i-1]][i-1];
	REF(i,u)fa[e[i].to][0]=u,dep[e[i].to]=dep[u]+1,dfs(e[i].to);
}
inline int lca(int u,int v)
{
	if(dep[u]<dep[v])swap(u,v);
	for(int i=18;dep[u]-dep[v];i--)if((1<<i)<=dep[u]-dep[v])u=fa[u][i];
	if(u==v)return u;
	for(int i=18;~i;i--)if(fa[u][i]!=fa[v][i])u=fa[u][i],v=fa[v][i];
	return fa[u][0];
}
inline void dfs1(int u)
{
	int now=dep[u]+w[u],tmp;
	if(now<=maxd)tmp=tong[now];
	REF(i,u)dfs1(e[i].to);
	tong[dep[u]]+=val[u];
	if(now<=maxd)ans[u]=tong[now]-tmp;
	RVC(it,cnt[u])tong[dep[*it]]--;
}
inline void dfs2(int u)
{
	int now=dep[u]-w[u]+maxn,tmp;
	tmp=num[now];
	REF(i,u)dfs2(e[i].to);
	RVC(it,cnt2[u])num[maxn+*it]++;
	ans[u]+=num[now]-tmp;
	RVC(it,cnt3[u])num[maxn+*it]--;
}

int main()
{
	read(n),read(m);
	for(int i=1,u,v;i<n;i++)read(u),read(v),add(u,v);
	dfs(1);for(int i=1;i<=n;i++)maxd=max(maxd,dep[i]);
	for(int i=1;i<=n;i++)read(w[i]);
	for(int i=1;i<=m;i++)
	{
		read(s[i]),read(t[i]),Lca[i]=lca(s[i],t[i]);
		val[s[i]]++,lth[i]=dep[s[i]]+dep[t[i]]-2*dep[Lca[i]];
		cnt[Lca[i]].push_back(s[i]);
	}
	dfs1(1);
	for(int i=1;i<=m;i++)
	{
		cnt2[t[i]].push_back(dep[t[i]]-lth[i]);
		cnt3[Lca[i]].push_back(dep[t[i]]-lth[i]);
	}
	dfs2(1);
	for(int i=1;i<=m;i++)if(dep[s[i]]-dep[Lca[i]]==w[Lca[i]])ans[Lca[i]]--;
	for(int i=1;i<=n;i++)printf("%d ",ans[i]);
	return 0;
}
