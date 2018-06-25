#include<bits/stdc++.h>
using namespace std;
namespace FastIO
{
	static char c;
	template<typename T>
	inline void read(T& x)
	{
		x=0,c=getchar();
		while(!isdigit(c))c=getchar();
		while(isdigit(c))x=x*10+c-'0',c=getchar();
	}
}
using FastIO::read;
typedef long long LL;
const int maxn=100005;

struct edge{int to,next;}e[maxn<<1];
int n,A[maxn],tot,head[maxn],deg[maxn];

inline void add(int u,int v)
{
	deg[u]++,deg[v]++;
	e[++tot]=(edge){v,head[u]},head[u]=tot;
	e[++tot]=(edge){u,head[v]},head[v]=tot;
}
inline int dfs(int u,int fa)
{
	int sum=0,w;
	for(int i=head[u];i;i=e[i].next)if(fa!=e[i].to)
	{
		w=dfs(e[i].to,u),sum+=w;
		if(w>A[u])exit((puts("NO"),0));
	}
	if(deg[u]==1)return A[u]-sum;
	if(sum<A[u])exit((puts("NO"),0));
	A[u]<<=1;
	if(A[u]<sum)exit((puts("NO"),0));
	return A[u]-sum;
}

int main()
{
	read(n);
	for(int i=1;i<=n;i++)read(A[i]);
	for(int i=1,u,v;i<n;i++)read(u),read(v),add(u,v);
	if(dfs(1,-1)>0)return puts("NO"),0;
	return puts("YES"),0;
}
