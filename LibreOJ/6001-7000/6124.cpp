#include<bits/stdc++.h>
using namespace std;
const int MV=270,ME=2000;

int dis[MV],S,T,A,B,P,Q,cnt,id[17][17];
char inq[MV];

struct edge
{
    int to,f,c;
    edge *nxt,*rev;
    edge(){}
    edge(int t,edge *n,int f,int c):to(t),f(f),c(c),nxt(n){}
    void* operator new(size_t);
}*E[MV],ePool[ME],*ptr=ePool,*from[MV];
inline void* edge::operator new(size_t){return ptr++;}

inline void read(int& x)
{
    static char c;
    c=getchar(),x=0;
    while(!isdigit(c))c=getchar();
    while(isdigit(c))x=x*10+c-48,c=getchar();
}
inline void add(int u,int v,int f,int c)
{
    E[u]=new edge(v,E[u],f,c),E[v]=new edge(u,E[v],0,-c);
    E[u]->rev=E[v],E[v]->rev=E[u];
}
inline bool spfa()
{
    queue<int> q;
    int now;
    memset(dis+1,0x3f,sizeof(int)*T),dis[S]=0;
    memset(inq+1,0,sizeof(char)*T),inq[S]=1;
    q.push(S);
    while(!q.empty())
    {
        now=q.front(),q.pop(),inq[now]=0;
        for(edge *i=E[now];i;i=i->nxt)if(i->f&&dis[i->to]>dis[now]+i->c)
        {
            dis[i->to]=dis[now]+i->c,from[i->to]=i;
            if(!inq[i->to])q.push(i->to),inq[i->to]=1;
        }
    }
    return dis[T]<0x3f3f3f3f;
}
inline int MinCostMaxFlow()
{
    int ans=0,flow;
    while(spfa())
    {
        flow=2147483647;
        for(int i=T;i!=S;i=from[i]->rev->to)flow=min(flow,from[i]->f);
        for(int i=T;i!=S;i=from[i]->rev->to)from[i]->f-=flow,from[i]->rev->f+=flow;
        ans+=flow*dis[T];
    }
    return ans;
}

int main()
{
	read(A),read(B),read(P),read(Q);
	for(int i=0;i<=P;i++)for(int j=0;j<=Q;j++)id[i][j]=++cnt;
	T=(S=cnt+1)+1;
	for(int i=0,val;i<=P;i++)for(int j=0;j<Q;j++)
	{
		read(val);
		add(id[i][j],id[i][j+1],1,-val);
		add(id[i][j],id[i][j+1],1e9,0);
	}
	for(int j=0,val;j<=Q;j++)for(int i=0;i<P;i++)
	{
		read(val);
		add(id[i][j],id[i+1][j],1,-val);
		add(id[i][j],id[i+1][j],1e9,0);
	}
	for(int k,x,y;A--;)read(k),read(x),read(y),add(S,id[x][y],k,0);
	for(int k,x,y;B--;)read(k),read(x),read(y),add(id[x][y],T,k,0);
	printf("%d\n",-MinCostMaxFlow());
    return 0;
}
