#include<bits/stdc++.h>
using namespace std;
const int maxn=300005;
#define REF(i,u) for(int i=head[u];i;i=e[i].next)if(e[i].to!=pre)

struct edge{int to,next,w;}e[maxn<<1];
int n,m,tot,head[maxn],fa[maxn][20],dep[maxn],dis[maxn],s[maxn],t[maxn],f[maxn];
int ans,mx,mn,mid,tag[maxn],need,cnt,mxd,mxdd,lth[maxn];
char c;

inline void read(int& x)
{
	x=0,c=getchar();
	while(!isdigit(c))c=getchar();
	while(isdigit(c))x=x*10+c-48,c=getchar();
}
inline void add(int u,int v,int w)
{
	e[++tot]=(edge){v,head[u],w},head[u]=tot;
	e[++tot]=(edge){u,head[v],w},head[v]=tot;
}
inline void dfs(int u,int pre)
{
	for(int i=1;(1<<i)<=dep[u];i++)fa[u][i]=fa[fa[u][i-1]][i-1];
	REF(i,u)
	{
		fa[e[i].to][0]=u,dep[e[i].to]=dep[u]+1,dis[e[i].to]=dis[u]+e[i].w;
		dfs(e[i].to,u);
	}
	mxd=max(mxd,dep[u]);
}
inline int lca(int u,int v)
{
	if(dep[u]<dep[v])swap(u,v);
	for(int i=mxdd;dep[u]-dep[v];i--)if((1<<i)<=dep[u]-dep[v])u=fa[u][i];
	if(u==v)return u;
	for(int i=mxdd;~i;i--)if(fa[u][i]!=fa[v][i])u=fa[u][i],v=fa[v][i];
	return fa[u][0];
}
inline bool dfs2(int u,int pre)
{
	REF(i,u)
	{
		if(dfs2(e[i].to,u))return 1;
		tag[u]+=tag[e[i].to];
	}
	return tag[u]==cnt&&dis[u]-dis[pre]>=need;
}
inline bool check(int val)
{
	memset(tag+1,0,n<<2);
	need=cnt=0;
	for(int i=1;i<=m;i++)if(lth[i]>val)
	{
		cnt++;
		need=max(need,lth[i]-val);
		tag[s[i]]++,tag[t[i]]++;
		tag[f[i]]-=2;
	}
	return dfs2(1,0);
}

int main()
{
	freopen("transport20.in","r",stdin);
	read(n),read(m);
	for(int i=1,u,v,w;i<n;i++)read(u),read(v),read(w),add(u,v,w);
	dfs(1,0);
	while(mxd)mxdd++,mxd>>=1;
	for(int i=1;i<=m;i++)
	{
		read(s[i]),read(t[i]),f[i]=lca(s[i],t[i]);
		lth[i]=dis[s[i]]+dis[t[i]]-2*dis[f[i]];
		mx=max(mx,lth[i]);
	}
	while(mn<=mx)
	{
		mid=(mx+mn)>>1;
		if(check(mid))ans=mid,mx=mid-1;
		else mn=mid+1;
	}
	printf("%d",ans);
	return 0;
}
