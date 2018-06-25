#include<bits/stdc++.h>
using namespace std;
const int MX=10005;

struct edge
{
	int to;
	edge* nxt;
	edge(int t,edge* i):to(t),nxt(i){}
}*E[MX];
int N,dep[MX],mx;
char vis[MX];

inline void add(int u,int v)
{
	E[u]=new edge(v,E[u]);
	E[v]=new edge(u,E[v]);
}
inline void bfs(int u)
{
	queue<int> q;
	memset(vis+1,0,sizeof(char)*N);
	q.push(u),vis[u]=1;
	int now;
	while(!q.empty())
	{
		now=q.front(),q.pop();
		for(edge* i=E[now];i;i=i->nxt)if(!vis[i->to])
			q.push(i->to),dep[i->to]=dep[now]+1,vis[i->to]=1;
	}
}

int main()
{
	scanf("%d",&N);
	for(int i=1,u,v;i<N;i++)
		scanf("%d%d",&u,&v),add(u,v);
	bfs(1);
	for(int i=1;i<=N;i++)if(dep[i]>dep[mx])mx=i;
	memset(dep+1,0,sizeof(int)*N),bfs(mx);
	mx=0;
	for(int i=1;i<=N;i++)mx=max(mx,dep[i]);
	printf("%d",mx);
}
