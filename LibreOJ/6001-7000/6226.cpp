#include<bits/stdc++.h>
using namespace std;
const int MV=40050,ME=400000,dx[]={-2,-1,1,2,2,1,-1,-2},dy[]={1,2,2,1,-1,-2,-2,-1};

int S,T,dep[MV],N,M,id[205][205],cnt;

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
	int ans=0;
	while(bfs())memcpy(cur+1,E+1,sizeof(edge*)*T),ans+=dfs(S,1e9);
	return ans;
}
inline bool judge(int x,int y){return x>0&&x<=N&&y>0&&y<=N&&~id[x][y];}

int main()
{
	read(N),read(M);
	for(int i=1,x,y;i<=M;i++)read(x),read(y),id[x][y]=-1;
	for(int i=1;i<=N;i++)for(int j=1;j<=N;j++)if(!id[i][j])id[i][j]=++cnt;
	T=(S=cnt+1)+1;
	for(int i=1;i<=N;i++)for(int j=1;j<=N;j++)if(~id[i][j])
		if((i^j)&1)
		{
			add(S,id[i][j],1);
			for(int k=0;k<8;k++)if(judge(i+dx[k],j+dy[k]))
				add(id[i][j],id[i+dx[k]][j+dy[k]],1e9);
		}
		else add(id[i][j],T,1);
	printf("%d\n",cnt-Dinic());
	return 0;
}
