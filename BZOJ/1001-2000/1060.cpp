#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=500000+5;

struct edge {int to,next,w;}e[maxn<<1];
int n,s,head[maxn],tot,dis[maxn];
long long final;
bool vis[maxn];

void add(int u,int v,int w)
{
	e[++tot]=(edge){v,head[u],w},head[u]=tot;
	e[++tot]=(edge){u,head[v],w},head[v]=tot;
}
void dfs(int u)
{
	int mx=0,sum=0,siz=0;
	for(int i=head[u];i;i=e[i].next)  if(!vis[e[i].to])
	{
		vis[e[i].to]=1;  siz++;
		dfs(e[i].to);
		mx=max(mx,e[i].w+dis[e[i].to]);
		sum+=e[i].w+dis[e[i].to];
	}
	dis[u]=mx;
	final+=siz*mx-sum;
}

int main()
{
	scanf("%d%d",&n,&s);  vis[s]=1;
	for(int i=1,a,b,c;i<n;i++)
	{
		scanf("%d%d%d",&a,&b,&c);
		add(a,b,c);
	}
	dfs(s);
	printf("%lld",final);
	return 0;
}
