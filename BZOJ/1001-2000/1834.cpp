#include<bits/stdc++.h>
using namespace std;
const int MV=1005,ME=20050;
typedef int Array[MV];

int N,M,K,S,T,u[ME],v[ME],c[ME],w[ME],dis[MV];
bool inq[MV];

struct edge
{
	int to,f,c;
	edge *nxt,*rev;
	edge(){}
	edge(int t,edge* n,int f,int c):to(t),f(f),c(c),nxt(n){}
	void* operator new(size_t);
}ePool[ME],*ptr=ePool,*E[MV],*cur[MV];
inline void* edge::operator new(size_t){return ptr++;}

inline void read(int& x)
{
	static char c;
	c=getchar(),x=0;
	while(!isdigit(c))c=getchar();
	while(isdigit(c))x=x*10+c-'0',c=getchar();
}
inline void add(int u,int v,int f,int w)
{
	E[u]=new edge(v,E[u],f,w),E[v]=new edge(u,E[v],0,-w);
	E[u]->rev=E[v],E[v]->rev=E[u];
}
inline bool bfs()
{
	queue<int> q;
	int now;
	memset(dis+1,-1,sizeof(int)*T),dis[S]=0;
	q.push(S);
	while(!q.empty())
	{
		now=q.front(),q.pop();
		for(edge *i=E[now];i;i=i->nxt)if(i->f&&!~dis[i->to])
			dis[i->to]=dis[now]+1,q.push(i->to);
	}
	return ~dis[T];
}
int dfs(int u,int flow)
{
	if(u==T||!flow)return flow;
	int used=0,w;
	for(edge* &i=cur[u];i;i=i->nxt)if(i->f&&dis[i->to]==dis[u]+1)
		w=dfs(i->to,min(flow-used,i->f)),i->f-=w,i->rev->f+=w,used+=w;
	return used;
}
inline int Dinic()
{
	int ans=0;
	while(bfs())memcpy(cur+1,E+1,sizeof(edge*)*T),ans+=dfs(S,1e9);
	return ans;
}
inline bool spfa()
{
	queue<int> q;
	int now;
	memset(dis+1,0x3f,sizeof(int)*T),dis[S]=0;
	q.push(S);
	while(!q.empty())
	{
		now=q.front(),q.pop(),inq[now]=0;
		for(edge *i=E[now];i;i=i->nxt)if(i->f&&dis[i->to]>dis[now]+i->c)
		{
			dis[i->to]=dis[now]+i->c,cur[i->to]=i;
			if(!inq[i->to])inq[i->to]=1,q.push(i->to);
		}
	}
	return dis[T]<0x3f3f3f3f;
}
inline int MinCostMaxFlow()
{
	int ans=0,flow=0,w=K;
	while(spfa()&&w)
	{
		w=K-flow;
		for(int i=T;i!=S;i=cur[i]->rev->to)w=min(w,cur[i]->f);
		for(int i=T;i!=S;i=cur[i]->rev->to)cur[i]->f-=w,cur[i]->rev->f+=w;
		flow+=w,ans+=w*dis[T];
	}
	return ans;
}

int main()
{
	read(N),read(M),read(K),S=1,T=N;
	for(int i=1;i<=M;i++)
	{
		read(u[i]),read(v[i]),read(c[i]),read(w[i]);
		add(u[i],v[i],c[i],0);
	}
	printf("%d ",Dinic());
	for(int i=1;i<=M;i++)add(u[i],v[i],1e9,w[i]);
	printf("%d\n",MinCostMaxFlow());
	return 0;
}
