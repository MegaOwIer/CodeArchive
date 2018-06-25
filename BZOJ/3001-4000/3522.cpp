#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn=5005;

struct edge{int to,next;}e[maxn<<1];
int n,tot,head[maxn],d[maxn],d1[maxn],d2[maxn],dep[maxn];
LL ans;
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
	d[dep[u]]++;
	for(int i=head[u];i;i=e[i].next)if(e[i].to!=fa)dep[e[i].to]=dep[u]+1,dfs(e[i].to,u);
}

int main()
{
	read(n);
	for(int i=1,u,v;i<n;i++)read(u),read(v),add(u,v);
	for(int i=1;i<=n;i++)
	{
		memset(d1+1,0,n<<2),memset(d2+1,0,n<<2);
		for(int j=head[i];j;j=e[j].next)
		{
			memset(d+1,0,n<<2),dep[e[j].to]=1,dfs(e[j].to,i);
			for(int k=1;k<=n;k++)ans+=d2[k]*d[k],d2[k]+=d[k]*d1[k],d1[k]+=d[k];
		}
	}
	printf("%lld",ans);
	return 0;
}
