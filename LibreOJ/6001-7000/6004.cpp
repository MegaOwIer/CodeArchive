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

struct edge{int to,next,f;}e[82000];
int n,m,S,T,head[425],cur[425],tot=1,ans,dep[425],now;
queue<int> q;

inline void add(int u,int v,int f)
{
	e[++tot]=(edge){v,head[u],f},head[u]=tot;
	e[++tot]=(edge){u,head[v],0},head[v]=tot;
}
inline bool bfs()
{
	memset(dep+1,-1,T<<2),dep[S]=0,q.push(S);
	while(!q.empty())
	{
		now=q.front(),q.pop();
		for(int i=head[now];i;i=e[i].next)if(!~dep[e[i].to]&&e[i].f)
			dep[e[i].to]=dep[now]+1,q.push(e[i].to);
	}
	return ~dep[T];
}
inline int dfs(int u,int f)
{
	if(u==T)return f;
	int w,used=0;
	for(int &i=cur[u];i;i=e[i].next)if(dep[e[i].to]==dep[u]+1&&e[i].f)
	{
		w=dfs(e[i].to,min(e[i].f,f-used));
		used+=w,e[i].f-=w,e[i^1].f+=w;
		if(f==used)return f;
	}
	return used;
}

int main()
{
	read(m),read(n),T=1+(S=n+m+1);
	for(int i=1,f;i<=m;i++)read(f),add(S,i,f),ans+=f;
	for(int i=1,f;i<=n;i++)read(f),add(i+m,T,f);
	for(int i=1;i<=m;i++)for(int j=1;j<=n;j++)add(i,j+m,1);
	while(bfs())memcpy(cur+1,head+1,T<<2),ans-=dfs(S,1e9);
	if(ans)return puts("0"),0;
	puts("1");
	for(int i=1;i<=m;i++)
	{
		for(int j=head[i];j;j=e[j].next)if(!e[j].f&&e[j].to!=S)
			printf("%d ",e[j].to-m);
		putchar('\n');
	}
	return 0;
}
