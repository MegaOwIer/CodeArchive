#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn=200005,mod=10007;

struct edge{int to,next;}e[maxn<<1];
int n,tot,head[maxn],w[maxn],mx[maxn],smx[maxn],sum[maxn],ans1,ans2,sum2[maxn];
char c;

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
inline void dfs(int u,int fa)
{
	mx[u]=sum[u]=w[fa];
	sum2[u]=w[fa]*w[fa]%mod;
	for(int i=head[u];i;i=e[i].next)if(e[i].to!=fa)
	{
		dfs(e[i].to,u);
		sum[u]=(sum[u]+w[e[i].to])%mod;
		sum2[u]=(sum2[u]+w[e[i].to]*w[e[i].to])%mod;
		if(w[e[i].to]>=mx[u])smx[u]=mx[u],mx[u]=w[e[i].to];
		else if(w[e[i].to]>smx[u])smx[u]=w[e[i].to];
	}
	ans1=max(ans1,mx[u]*smx[u]);
	ans2=(ans2+sum[u]*sum[u]-sum2[u]+mod)%mod;
}

int main()
{
	read(n);
	for(int i=1,u,v;i<n;i++)read(u),read(v),add(u,v);
	for(int i=1;i<=n;i++)read(w[i]);
	dfs(1,0);
	printf("%d %d",ans1,ans2);
}
