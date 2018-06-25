#include<bits/stdc++.h>
using namespace std;
const int MV=64050,ME=80*80*80;

int S,T,N,M,dep[MV];
char ch;

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
inline void add(int u,int v,int f1,int f2)
{
	E[u]=new edge(v,E[u],f1),E[v]=new edge(u,E[v],f2);
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
	while(bfs())memcpy(cur+1,E+1,sizeof(edge*)*T),ans+=dfs(S,1e9);
	return ans;
}
inline int f(int x,int y,int z){return (x-1)*N*N+(y-1)*N+z;}

int main()
{
	read(N),T=(S=N*N*N+1)+1;
	for(int i=1;i<=N;i++)for(int j=1;j<=N;j++)for(int k=1;k<=N;k++)
	{
		if(i!=N)add(f(i,j,k),f(i+1,j,k),1,1);
		if(j!=N)add(f(i,j,k),f(i,j+1,k),1,1);
		if(k!=N)add(f(i,j,k),f(i,j,k+1),1,1);
	}
	for(int i=1;i<=N;i++)for(int j=1;j<=N;j++)for(int k=1;k<=N;k++)
	{
		do ch=getchar();while(ch!='P'&&ch!='N'&&ch!='?');
		if(ch=='P')
			if((i+j+k)&1)add(S,f(i,j,k),1e9,0);
			else add(f(i,j,k),T,1e9,0);
		else if(ch=='N')
			if((i+j+k)&1)add(f(i,j,k),T,1e9,0);
			else add(S,f(i,j,k),1e9,0);
	}
	printf("%d\n",3*N*N*(N-1)-Dinic());
	return 0;
}
