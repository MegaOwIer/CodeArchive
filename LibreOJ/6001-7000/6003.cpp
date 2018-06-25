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

struct edge{int to,next,f;}e[41000]; 
int n,m,tot=1,head[3205],cur[3205],ans,dep[3205],S=3201,T=3202,to[1600]; 
queue<int> q;
bool pr[1600];

inline void add(int u,int v)
{
	e[++tot]=(edge){v,head[u],1},head[u]=tot;
	e[++tot]=(edge){u,head[v],0},head[v]=tot; 
}
inline bool bfs()
{
	memset(dep+1,-1,T<<2),q.push(S),dep[S]=0;
	while(!q.empty())
	{
		int now=q.front();q.pop();
		for(int i=head[now];i;i=e[i].next)if(e[i].f&&!~dep[e[i].to])
			dep[e[i].to]=dep[now]+1,q.push(e[i].to); 
	}
	return ~dep[T];
}
inline int dfs(int u,int f)
{
	if(u==T)return f;
	int w,use=0;
	for(int &i=cur[u];i;i=e[i].next)if(e[i].f&&dep[e[i].to]==dep[u]+1)
	{
		w=dfs(e[i].to,min(e[i].f,f-use));
		use+=w,e[i].f-=w,e[i^1].f+=w;
		if(use==f)return f; 
	}
	if(!use)dep[u]=-1;
	return use;
}

int main()
{
	read(m);
	while(1)
	{
		n++,ans++;
		add(S,n),add(n+1600,T);
		for(int i=1;i<n;i++)if(sqrt(i+n)==(int)sqrt(i+n))add(i,n+1600);
		while(bfs())memcpy(cur+1,head+1,T<<2),ans-=dfs(S,1e9);
		if(ans>m)break;
	}
	printf("%d\n",n-1);
	for(int i=1;i<n;i++)for(int j=head[i];j;j=e[j].next)
		if(!e[j].f){to[i]=e[j].to-1600;break;}
	for(int i=1;i<n;i++)if(!pr[i])
	{
		for(int j=i;j<n;j=to[j])pr[j]=1,printf("%d ",j);
		putchar('\n'); 
	} 
	return 0;
}
