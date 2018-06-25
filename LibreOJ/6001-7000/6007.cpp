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
		if(f)putchar(f&1?' ':'\n');
	}
}
using FastIO::read;
using FastIO::write;

struct edge{int to,next,f;}e[5300];
int n,m,head[905],S,T,ans,tot=1,now,dep[905],cur[905];
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
	if(!f||u==T)return f;
	int w,used=0;
	for(int &i=cur[u];i;i=e[i].next)if(dep[e[i].to]==dep[u]+1)
	{
		w=dfs(e[i].to,min(e[i].f,f-used));
		used+=w,e[i].f-=w,e[i^1].f+=w;
		if(f==used)return f;
	}
	if(!used)dep[u]=-1;
	return used;
}

int main()
{
	read(m),read(n),T=1+(S=n*m+1);
	for(int i=1,f;i<=m;i++)for(int j=1;j<=n;j++)
	{
		read(f),ans+=f;
		if((i^j)&1)
		{
			add(S,(i-1)*n+j,f);
			if(i!=1)add((i-1)*n+j,(i-2)*n+j,1e9);
			if(i!=m)add((i-1)*n+j,i*n+j,1e9);
			if(j!=1)add((i-1)*n+j,(i-1)*n+j-1,1e9);
			if(j!=n)add((i-1)*n+j,(i-1)*n+j+1,1e9);
		}
		else add((i-1)*n+j,T,f);
	}
	while(bfs())memcpy(cur+1,head+1,T<<2),ans-=dfs(S,1e9);
	write(ans);
	return 0;
}
