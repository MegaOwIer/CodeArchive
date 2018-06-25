#include<cstdio>
#include<cctype>
#include<queue>
#include<cstring>
using namespace std;
const int MV=210,ME=2500;

int S,T,dep[MV],N,M,cas,ind[MV],oud[MV];
bool fail;

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
	c=getchar(),x=0;
	while(!isdigit(c))c=getchar();
	while(isdigit(c))x=x*10+c-'0',c=getchar();
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
	while(bfs())memcpy(cur+1,E+1,sizeof(edge*)*T),dfs(S,1e9);
	for(edge *i=E[S];i;i=i->nxt)if(i->f)return 0;
	return 1;
}

int main()
{
	read(cas);
	while(cas--)
	{
		read(N),read(M),T=(S=N+1)+1;
		fail=0;
		ptr=ePool,memset(E+1,0,sizeof(int)*T);
		memset(ind+1,0,sizeof(int)*N);
		memset(oud+1,0,sizeof(int)*N);
		for(int i=1,u,v,d;i<=M;i++)
		{
			read(u),read(v),read(d);
			ind[v]++,oud[u]++;
			if(!d)add(v,u,1);
		}
		for(int i=1;i<=N;i++)
			if((ind[i]-oud[i])&1)fail=1;
			else if(ind[i]>oud[i])add(S,i,(ind[i]-oud[i])/2);
			else if(ind[i]<oud[i])add(i,T,(oud[i]-ind[i])/2);
		if(!fail&&Dinic())puts("possible");
		else puts("impossible");
	}
	return 0;
}
