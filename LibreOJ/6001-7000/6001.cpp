#include<bits/stdc++.h>
using namespace std;
namespace FastIO
{
	static char c;
	template<typename T>
	inline bool read(T& x)
	{
		x=0,c=getchar();
		while(!isdigit(c))c=getchar();
		while(isdigit(c))x=x*10+c-'0',c=getchar();
		return c!='\n'&&c!='\r';
	}
}
using FastIO::read;

struct edge{int to,next,f;}e[5300];
int n,m,S,T,tot=1,head[105],dep[105],now,ans,ans1;
bool used[55];
queue<int> q; 

inline void add(int u,int v,int w)
{
	e[++tot]=(edge){v,head[u],w},head[u]=tot;
	e[++tot]=(edge){u,head[v],0},head[v]=tot;
}
inline bool bfs()
{
	memset(dep+1,-1,T<<2),dep[S]=0,q.push(S);
	while(!q.empty())
	{
		now=q.front(),q.pop();
		for(int i=head[now];i;i=e[i].next)if(e[i].f&&!~dep[e[i].to])
			dep[e[i].to]=dep[now]+1,q.push(e[i].to); 
	}
	return ~dep[T];
}
inline int dfs(int u,int f)
{
	if(u==T)return f;
	int w,use=0;
	for(int i=head[u];i;i=e[i].next)if(e[i].f&&dep[e[i].to]==dep[u]+1)
	{
		w=dfs(e[i].to,min(f-use,e[i].f));
		use+=w,e[i].f-=w,e[i^1].f+=w;
		if(use==f)return f;
	}
	if(!use)dep[u]=-1;
	return use;
}

int main()
{
	read(m),read(n),T=(S=n+m+1)+1;
	for(int i=1,f;i<=m;i++)
	{
		read(f),add(S,i,f),ans+=f;
		while(read(f))add(i,m+f,1e9);
		add(i,m+f,1e9);
	}
	for(int i=1,f;i<=n;i++)read(f),add(m+i,T,f);
	while(bfs())ans-=dfs(S,1e9);
	for(int i=1;i<=m;i++)if(~dep[i])
	{
		printf("%d ",i);
		for(int j=head[i];j;j=e[j].next)
			used[e[j].to-m]=1;
	}
	putchar('\n');
	for(int i=1;i<=n;i++)if(used[i])printf("%d ",i);
	printf("\n%d",ans); 
	return 0;
}
