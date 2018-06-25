#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+5;
typedef long long LL;

struct edge{int to,next,w;}e[maxn<<1];
int n,tot,head[maxn],siz[maxn],dis[maxn];
LL ans;
char c;

inline void read(int& x)
{
	x=0,c=getchar();
	while(!isdigit(c))c=getchar();
	while(isdigit(c))x=x*10+c-'0',c=getchar();
}
inline void add(int u,int v,int w)
{
	e[++tot]=(edge){v,head[u],w},head[u]=tot;
	e[++tot]=(edge){u,head[v],w},head[v]=tot;
}
inline void dfs(int u,int fa)
{
	siz[u]=1;
	for(int i=head[u];i;i=e[i].next)if(e[i].to!=fa)
		dis[e[i].to]=dis[u]+e[i].w,dfs(e[i].to,u),siz[u]+=siz[e[i].to];
	ans+=1LL*abs(2*siz[u]-n)*(dis[u]-dis[fa]);
}

int main()
{
	read(n);
	for(int i=1,u,v,w;i<n;i++)read(u),read(v),read(w),add(u,v,w);
	dfs(1,0);
	printf("%lld",ans);
	return 0;
}
