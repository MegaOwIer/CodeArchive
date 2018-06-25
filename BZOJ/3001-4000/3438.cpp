#include<bits/stdc++.h>
using namespace std;
const int MV=3005,ME=2100000,INF=2147483647;

int S,T,dep[MV],N,M,sum,a[1005],b[1005];

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
	for(edge* &i=cur[u];i;i=i->nxt)if(i->f&&dep[i->to]==dep[u]+1)
		w=dfs(i->to,min(flow-used,i->f)),i->f-=w,i->rev->f+=w,used+=w;
	return used;
}
inline int Dinic()
{
	int ans=0;
	while(bfs())memcpy(cur+1,E+1,sizeof(edge*)*T),ans+=dfs(S,INF);
	return ans;
}

int main()
{
	read(N);
	for(int i=1;i<=N;i++)read(a[i]),sum+=a[i];
	for(int i=1;i<=N;i++)read(b[i]),sum+=b[i];
	read(M),T=(S=N+M+M+1)+1;
	for(int i=1;i<=N;i++)add(S,i,a[i]);
	for(int i=1;i<=N;i++)add(i,T,b[i]);
	for(int i=1,k,u,c1,c2,i1,i2;i<=M;i++)
	{
		i1=N+i*2-1,i2=N+i*2;
		read(k),read(c1),read(c2),sum+=c1+c2;
		add(S,i1,c1),add(i2,T,c2);
		while(k--)read(u),add(i1,u,INF),add(u,i2,INF);
	}
	printf("%d\n",sum-Dinic());
}
