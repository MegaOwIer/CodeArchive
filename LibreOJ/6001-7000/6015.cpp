#include<bits/stdc++.h>
using namespace std;
const int MV=1505,ME=8000;

int S,T,dep[MV],N,M,K,h[MV],r[MV];
vector<int> vis[MV];

struct edge
{
	int to,f;
	edge *nxt,*rev;
	edge(){}
	edge(int t,edge *n,int f):to(t),f(f),nxt(n){}
	void* operator new(size_t);
}*E[MV],ePool[ME],*ptr=ePool,*cur[MV];
inline void* edge::operator new(size_t){return ptr++;}

inline void read(int& x)
{
	static char c;
	static int f;
	c=getchar(),x=0;
	while(!isdigit(c)){if(c=='-')f=1;c=getchar();}
	while(isdigit(c))x=x*10+c-'0',c=getchar();
	if(f)x=-x,f=0;
}
inline void add(int u,int v,int f)
{
	E[u]=new edge(v,E[u],f),E[v]=new edge(u,E[v],0);
	E[u]->rev=E[v],E[v]->rev=E[u];
}
inline bool bfs()
{
	int now;
	queue<int> q;
	memset(dep+1,-1,sizeof(int)*T),dep[S]=0;
	q.push(S);
	while(!q.empty())
	{
		now=q.front(),q.pop();
		for(edge *i=E[now];i;i=i->nxt)if(i->f&&!~dep[i->to])
			dep[i->to]=dep[now]+1,q.push(i->to);
	}
	return ~dep[T];
}
int dfs(int u,int flow)
{
	if(u==T||!flow)return flow;
	int used=0,w;
	for(edge* &i=cur[u];i;i=i->nxt)
		if(i->f&&dep[i->to]==dep[u]+1)
		{
			w=dfs(i->to,min(flow-used,i->f));
			i->f-=w,i->rev->f+=w,used+=w;
			if(used==flow)return flow;
		}
	if(!used)dep[u]=-1;
	return used;
}
inline int Dinic()
{
	static int ans=0;
	while(bfs())memcpy(cur+1,E+1,sizeof(edge*)*T),ans+=dfs(S,1e9);
	return ans;
}
inline int ask(int id,int day){return day*N+vis[id][day%r[id]];}

int main()
{
	read(N),read(M),read(K),N+=2;
	for(int i=1,p;i<=M;i++)
	{
		read(h[i]),read(r[i]);
		for(int j=1;j<=r[i];j++)read(p),vis[i].push_back(p+2);
	}
	S=1501,T=1502;
	for(int ans=0;ans<=100;ans++)
	{
		add(S,ans*N+2,1e9),add(ans*N+1,T,1e9);
		if(ans)
		{
			for(int i=1;i<=N;i++)add((ans-1)*N+i,ans*N+i,1e9);
			for(int i=1;i<=M;i++)add(ask(i,ans-1),ask(i,ans),h[i]);
			if(Dinic()>=K)return printf("%d\n",ans),0;
		}
	}
	return puts("0"),0;
}
