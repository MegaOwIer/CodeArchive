#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn=100005;

struct edge{int to,next;}e[maxn*10];
int n,m,tot,head[maxn],dfn[maxn],low[maxn],cnt,siz[maxn];
LL ans[maxn];
char c;

inline void read(int& x)
{
	c=getchar(),x=0;
	while(!isdigit(c))c=getchar();
	while(isdigit(c))x=x*10+c-48,c=getchar();
}
inline void add(int u,int v)
{
	e[++tot]=(edge){v,head[u]},head[u]=tot;
	e[++tot]=(edge){u,head[v]},head[v]=tot;
}
inline void tarjan(int u)
{
	int tmp=0;
	siz[u]=1,dfn[u]=low[u]=++cnt;
	for(int i=head[u];i;i=e[i].next)
		if(dfn[e[i].to])low[u]=min(low[u],dfn[e[i].to]);
		else
		{
			tarjan(e[i].to),siz[u]+=siz[e[i].to];
			low[u]=min(low[u],low[e[i].to]);
			if(dfn[u]<=low[e[i].to])
			{
				ans[u]+=(LL)tmp*siz[e[i].to];
				tmp+=siz[e[i].to];
			}
		}
	ans[u]+=(LL)tmp*(n-tmp-1);
}

int main()
{
	read(n),read(m);
	for(int i=1,u,v;i<=m;i++)read(u),read(v),add(u,v);
	tarjan(1);
	for(int i=1;i<=n;i++)printf("%lld\n",ans[i]+n-1<<1);
	return 0;
}
