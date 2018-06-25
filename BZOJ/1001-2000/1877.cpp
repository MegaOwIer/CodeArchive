#include<bits/stdc++.h>
using namespace std;
const int MV=405,ME=20250,INF=2147483647;

int N,M;
int S,T,deg[ME],u[ME],v[ME],f[ME],c[ME],tot;

struct MinCostMaxFlow
{
	struct edge
	{
	    int to,f,c;
	    edge *rev;
	    edge(){}
	    edge(int t,int f,int c,edge *r):to(t),f(f),c(c),rev(r){}
	}*E[MV],Pool[ME<<1],*from[MV];
	int S,T,dis[MV];
	bool inq[MV];
	
	void build_graph()
	{
		E[1]=Pool;
		for(int i=1;i<=T;i++)E[i+1]=E[i]+deg[i];
		for(int i=1;i<=tot;i++)
		{
			--deg[u[i]],--deg[v[i]];
			E[u[i]][deg[u[i]]]=edge(v[i],f[i],c[i],E[v[i]]+deg[v[i]]);
			E[v[i]][deg[v[i]]]=edge(u[i],0,-c[i],E[u[i]]+deg[u[i]]);
		}
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
	        for(edge *i=E[now];i!=E[now+1];i++)if(i->f&&dis[i->to]>dis[now]+i->c)
	        {
	            dis[i->to]=dis[now]+i->c,from[i->to]=i;
	            if(!inq[i->to])q.push(i->to),inq[i->to]=1;
	        }
	    }
	    return dis[T]<0x3f3f3f3f;
	}
	void operator()(int _S,int _T)
	{
	    int ans=0,flow=0,w;
	    S=_S,T=_T,build_graph();
	    while(spfa())
	    {
	        w=INF;
	        for(int i=T;i!=S;i=from[i]->rev->to)w=min(w,from[i]->f);
	        for(int i=T;i!=S;i=from[i]->rev->to)from[i]->f-=w,from[i]->rev->f+=w;
	        ans+=w*dis[T],flow+=w;
	    }
	    printf("%d %d\n",flow,ans);
	}
}EdmondsKarp;

inline void read(int& x)
{
    static char c;
    x=0,c=getchar();
    while(!isdigit(c))c=getchar();
    while(isdigit(c))x=x*10+c-48,c=getchar();
}
inline void add(int _u,int _v,int _f,int _c)
{
	++tot,u[tot]=_u,v[tot]=_v,f[tot]=_f,c[tot]=_c;
	++deg[_u],++deg[_v];
}

int main()
{
	read(N),read(M),S=1,T=N*2;
	for(int i=1,u,v,w;i<=M;i++)read(u),read(v),read(w),add(u+N,v,1,w);
	add(1,1+N,INF,0),add(N,N+N,INF,0);
	for(int i=2;i<N;i++)add(i,i+N,1,0);
    return EdmondsKarp(S,T),0;
}
