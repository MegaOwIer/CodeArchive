#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

struct edge{int to,next,w;}e[20500];
int n,tot=1,head[905],S,T,f,sum,delta,dep[905],cur[905];
queue<int> q;
char c;

inline void read(int& x)
{
	x=0,c=getchar(),f=1;
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c))x=x*10+c-'0',c=getchar();x*=f;
}
inline void add(int u,int v,int w)
{
	e[++tot]=(edge){v,head[u],w},head[u]=tot;
	e[++tot]=(edge){u,head[v],0},head[v]=tot;
}
inline bool bfs()
{
	while(!q.empty())q.pop();
	memset(dep+1,-1,T<<2),q.push(S),dep[S]=0;
	while(!q.empty())
	{
		int now=q.front();q.pop();
		for(int i=head[now];i;i=e[i].next)if(e[i].w&&!~dep[e[i].to])
			dep[e[i].to]=dep[now]+1,q.push(e[i].to);
	}
	return ~dep[T];
}
inline int dfs(int u,int flow)
{
	if(u==T)return flow;
	int w,used=0;
	for(int i=cur[u];i;i=e[i].next)if(dep[e[i].to]==dep[u]+1)
	{
		w=dfs(e[i].to,min(flow-used,e[i].w));
		e[i].w-=w,e[i^1].w+=w;
		if(e[i].w)cur[u]=i;
		used+=w;
		if(used==flow)return flow;
	}
	if(!used)dep[u]=-1;
	return used;
}

int main()
{
	read(n),T=(S=n*n+1)+1;
	for(int i=1,now=1,a;i<=n;i++)for(int j=1;j<=n;j++,now++)
	{
		read(a),sum+=a;
		if((i^j)&1)
		{
			add(now,T,a);
			if(i>1)add(now-n,now,1e9);
			if(i<n)add(now+n,now,1e9);
			if(j>1)add(now-1,now,1e9);
			if(j<n)add(now+1,now,1e9);
		}
		else
		{
			add(S,now,a);
			if(i>1)add(now,now-n,1e9);
			if(i<n)add(now,now+n,1e9);
			if(j>1)add(now,now-1,1e9);
			if(j<n)add(now,now+1,1e9);
		}
	}
	while(bfs())
	{
		for(int i=1;i<=T;i++)cur[i]=head[i];
		delta+=dfs(S,1e9);
	}
	printf("%d",sum-delta);
	return 0;
}
