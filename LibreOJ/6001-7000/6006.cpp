#include<bits/stdc++.h>
using namespace std;
namespace FastIO
{
	static char c;
	static int top,buf[22];
	template<typename T>
	inline void read(T& x)
	{
		x=0,c=getchar();
		while(!isdigit(c))c=getchar();
		while(isdigit(c))x=x*10+c-'0',c=getchar();
	}
	template<typename T>
	inline void write(T x,int f=0)
	{
		top=0;
		do buf[top++]=x%10,x/=10;while(x);
		for(int i=top-1;~i;i--)putchar(buf[i]+48);
		if(f)putchar(f&1?' ':':');
	}
}
using FastIO::read;
using FastIO::write;

struct edge{int to,next,f;}e[42045];
int k,n,S,T,m,head[1025],tot=1,cur[1025],dep[1025],now,ans;
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
		for(int i=head[now];i;i=e[i].next)if(e[i].f&&!~dep[e[i].to])
			dep[e[i].to]=dep[now]+1,q.push(e[i].to);
	}
	return ~dep[T];
}
inline int dfs(int u,int f)
{
	if(u==T||!f)return f;
	int used=0,w;
	for(int i=head[u];i;i=e[i].next)if(dep[u]+1==dep[e[i].to])
	{
		w=dfs(e[i].to,min(e[i].f,f-used));
		used+=w,e[i].f-=w,e[i^1].f+=w;
		if(used==f)return f;
	}
	if(!used)dep[u]=-1;
	return used;
}

int main()
{
	read(k),read(n),T=1+(S=k+n+1);
	for(int i=1,f;i<=k;i++)read(f),add(S,i,f),m+=f;
	for(int i=1,t,r;i<=n;i++)
	{
		read(t),add(k+i,T,1);
		for(int j=1;j<=t;j++)read(r),add(r,k+i,1);
	}
	while(bfs())memcpy(cur+1,head+1,T<<2),ans+=dfs(S,1e9);
	if(ans!=m)return puts("No Solution!"),0;
	for(int i=1;i<=k;i++)
	{
		write(i,2),putchar(' ');
		for(int j=head[i];j;j=e[j].next)if(!e[j].f&&e[j].to!=S)
			write(e[j].to-k,1);
		putchar('\n');
	}
	return 0;
}
