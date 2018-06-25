#include<bits/stdc++.h>
using namespace std;
namespace FastIO
{
	static char c;
	static int f,top,buf[22];
	template<typename T>inline void rd(T& x)
	{
		x=0,c=getchar(),f=1;
		while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
		while(isdigit(c))x=x*10+c-'0',c=getchar();x*=f;
	}
	template<typename T>inline void wt(T x)
	{
		top=0;
		do buf[++top]=x%10,x/=10;while(x);
		while(top)putchar(buf[top--]+48);
		putchar('\n');
	}
}
using FastIO::rd;
using FastIO::wt;
typedef long long LL;
typedef pair<LL,LL> pLL;
typedef pair<LL,pLL> pLLL;
const int maxn=100005;
#define pb push_back
#define st first
#define nd second
#define mp make_pair

struct edge{int to,next,w;}e[maxn<<1];
int n,Q,tot,head[maxn],dep[maxn],root,mxs[maxn],siz[maxn],RT,x,y;
LL cnt[maxn],sum[maxn];
bool vis[maxn];
vector<LL> sumdist[maxn];
vector<pLL> pre[maxn];
vector<pLLL> ch[maxn],record;

inline void add(int u,int v,int w)
{
	e[++tot]=(edge){v,head[u],w},head[u]=tot;
	e[++tot]=(edge){u,head[v],w},head[v]=tot;
}
inline void dfs(int u,int pre,int SIZE)
{
	siz[u]=1,mxs[u]=0;
	for(int i=head[u];i;i=e[i].next)if(e[i].to!=pre&&!vis[e[i].to])
		dfs(e[i].to,u,SIZE),siz[u]+=siz[e[i].to],mxs[u]=max(mxs[u],siz[e[i].to]);
	mxs[u]=max(mxs[u],SIZE-siz[u]);
	if(mxs[u]<mxs[root])root=u;
}
inline void getdis(int u,int fa,int tar,int dist)
{
	pre[u].pb(mp(tar,dist)),siz[u]=1;
	for(int i=head[u];i;i=e[i].next)if(!vis[e[i].to]&&e[i].to!=fa)
		getdis(e[i].to,u,tar,dist+e[i].w),siz[u]+=siz[e[i].to];
}
inline void work(int u)
{
	vis[u]=1;
	pre[u].pb(mp(u,0));
	for(int i=head[u];i;i=e[i].next)if(!vis[e[i].to])
	{
		getdis(e[i].to,-1,u,e[i].w);
		dfs(e[i].to,root=0,mxs[0]=siz[e[i].to]);
		ch[u].pb(mp(root,mp(e[i].to,e[i].w)));
		work(root);
	}
}
inline void upd(int x,int y,LL z)
{
	int u;
	for(int i=0;i<pre[x].size();i++)
	{
		u=pre[x][i].st,cnt[u]+=y,sum[u]+=z+pre[x][i].nd*y;
		if(i+1!=pre[x].size())for(int j=0;j<ch[u].size();j++)
			if(ch[u][j].st==pre[x][i+1].st)
				sumdist[u][j]+=pre[x][i].nd*y+z;
	}
}
inline LL query()
{
	int x=RT,mx;
	record.clear();
	while(x)
	{
		mx=0;
		for(int i=1;i<ch[x].size();i++)
			if(cnt[ch[x][mx].st]<cnt[ch[x][i].st])mx=i;
		if(ch[x].empty()||cnt[ch[x][mx].st]*2<=cnt[x])
		{
			LL ans=sum[x];
			for(int i=0;i<record.size();i++)
				upd(record[i].st,record[i].nd.st,record[i].nd.nd);
			return ans;
		}
		int v=ch[x][mx].st;
		record.pb(mp(ch[x][mx].nd.st,mp(cnt[v]-cnt[x],sumdist[x][mx]-sum[x]-ch[x][mx].nd.nd*(cnt[x]-cnt[v]))));
		upd(ch[x][mx].nd.st,cnt[x]-cnt[v],sum[x]-sumdist[x][mx]+ch[x][mx].nd.nd*(cnt[x]-cnt[v]));
		x=v;
	}
}

int main()
{
	rd(n),rd(Q);
	for(int i=1,u,v,w;i<n;i++)rd(u),rd(v),rd(w),add(u,v,w);
	dfs(1,root,mxs[0]=n),work(RT=root);
	for(int i=1;i<=n;i++)sumdist[i]=vector<LL>(ch[i].size(),0);
	while(Q--)rd(x),rd(y),upd(x,y,0),wt(query());
	return 0;
}
