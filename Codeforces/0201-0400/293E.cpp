#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn=100005;
#define lowbit(x) x&(-x)

struct path{int dep,lth;}r[maxn];
struct edge{int to,next,w;}e[maxn<<1];
int n,l,w,tot,head[maxn],siz[maxn],mxsz[maxn],G,c,c0,it,tr[maxn];
bool vis[maxn];
char ch;

inline bool operator < (path a,path b){return a.lth<b.lth;}
inline void read(int& x)
{
	x=0,ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch<='9'&&ch>='0')x=x*10+ch-'0',ch=getchar();
}
inline void add(int u,int v,int w)
{
	e[++tot]=(edge){v,head[u],w},head[u]=tot;
	e[++tot]=(edge){u,head[v],w},head[v]=tot;
}
inline void dfs1(int u,int fa)
{
	siz[u]=1,mxsz[u]=0;
	for(int i=head[u];i;i=e[i].next)if(!vis[e[i].to]&&e[i].to!=fa)
	{
		dfs1(e[i].to,u);
		siz[u]+=siz[e[i].to];
		if(siz[e[i].to]>mxsz[u])mxsz[u]=siz[e[i].to];
	}
}
inline void dfs2(int u,int fa,int tot)
{
	mxsz[u]=max(mxsz[u],tot-siz[u]);
	if(mxsz[u]<=tot/2)G=u;
	for(int i=head[u];i;i=e[i].next)if(e[i].to!=fa&&!vis[e[i].to])dfs2(e[i].to,u,tot);
}
inline int getO(int u)
{
	dfs1(u,-1),dfs2(u,-1,siz[u]);
	return G;
}
inline void dfs3(int u,int fa,int dep,int lth)
{
	if(dep>l||lth>w)return;
	r[++c]=(path){dep,lth};
	for(int i=head[u];i;i=e[i].next)if(e[i].to!=fa&&!vis[e[i].to])dfs3(e[i].to,u,dep+1,lth+e[i].w);
}
inline void add(int x,int val){for(;x<=l;x+=lowbit(x))tr[x]+=val;}
inline int sum(int x){int ans=0;for(;x;x-=lowbit(x))ans+=tr[x];return ans;}
inline LL solve(int u)
{
	u=getO(u),c=0;
	LL ans=0;
	for(int i=head[u];i;i=e[i].next)if(!vis[e[i].to])
	{
		c0=c;
		dfs3(e[i].to,u,1,e[i].w),sort(r+c0+1,r+c+1),it=c;
		for(int j=c0+1;j<=c;j++)add(r[j].dep,1);
		for(int j=c0+1;j<=c;j++)
		{
			while(r[j].lth+r[it].lth>w&&it>c0)add(r[it].dep,-1),it--;
			ans-=sum(l-r[j].dep);
		}
		while(it>c0)add(r[it].dep,-1),it--;
	}
	sort(r+1,r+c+1),it=c;
	for(int j=1;j<=c;j++)add(r[j].dep,1);
	for(int j=1;j<=c;j++)
	{
		while(r[j].lth+r[it].lth>w&&it)add(r[it].dep,-1),it--;
		if(r[j].lth<=w&&r[j].dep<=l)ans+=2;
		ans+=sum(l-r[j].dep);
	}
	vis[u]=1;
	for(int i=head[u];i;i=e[i].next)if(!vis[e[i].to])ans+=solve(e[i].to);
	return ans;
}

int main()
{
	read(n),read(l),read(w);
	for(int i=2,p,w;i<=n;i++)read(p),read(w),add(p,i,w);
	printf("%lld",solve(1)>>1);
	return 0;
}
