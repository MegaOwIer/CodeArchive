#include<bits/stdc++.h>
using namespace std;
namespace FastIO
{
	static char c;
	static int buf[22],top;
	template<typename T>inline void read(T& x)
	{
		x=0,c=getchar();
		while(!isdigit(c))c=getchar();
		while(isdigit(c))x=x*10+c-'0',c=getchar();
	}
	template<typename T>inline void write(T x,int f=0)
	{
		top=0;
		do buf[top++]=x%10,x/=10;while(x);
		while(top)putchar(48+buf[--top]);
		putchar(f?'\n':' ');
	}
}
using FastIO::read;
using FastIO::write;
typedef long long LL;
const int maxn=2e5+5;
#define st first
#define nd second

int n,dep[maxn],S,T,fa[maxn],cnt;
bool fl[maxn];
LL ans;
vector<int> g[maxn];
pair<int,int> q[maxn];

#define pb push_back
inline void add(int u,int v){g[u].pb(v),g[v].pb(u);}
#undef pb
inline void dfs(int u,int f){for(auto i:g[u])if(i!=f)fa[i]=u,dep[i]=dep[u]+1,dfs(i,u);}
inline void dfs2(int u,int lca)
{
	int tmp=0;
	for(auto i:g[u])if(i!=fa[u])fl[i]?tmp=i:(dfs2(i,lca),0);
	if(tmp)dfs2(tmp,tmp);
	int dis1=dep[u],dis2=dep[u]+dep[T]-2*dep[lca];
	if(dis1>dis2||fl[u])q[++cnt]=make_pair(S,u),ans+=dis1;
	else q[++cnt]=make_pair(T,u),ans+=dis2;
}

int main()
{
	read(n);
	for(int i=1,u,v;i<n;i++)read(u),read(v),add(u,v);
	dfs(1,-1);
	for(int i=1;i<=n;i++)if(dep[i]>dep[S])S=i;
	memset(dep+1,0,n<<2),memset(fa+1,0,n<<2);
	dfs(S,-1),fl[S]=1;
	for(int i=1;i<=n;i++)if(dep[i]>dep[T])T=i;
	for(int i=T;i!=S;i=fa[i])fl[i]=1;
	dfs2(S,S);
	write(ans,1);
	for(int i=1;i<n;i++)write(q[i].st),write(q[i].nd),write(q[i].nd,1);
	return 0;
}
