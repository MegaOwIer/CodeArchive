#include<bits/stdc++.h>
using namespace std;
const int MV=205,ME=20500;

int dis[MV],S,T,N,val[105][105];
char inq[MV];

struct edge
{
    int to,f,c;
    edge *nxt,*rev;
    edge(){}
    edge(int t,edge *n,int f,int c):to(t),f(f),c(c),nxt(n){}
    void* operator new(size_t);
}*E[MV],ePool[ME],*ptr,*from[MV];
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
    read(N),T=(S=N<<1|1)+1;
    for(int i=1;i<=N;i++)for(int j=1;j<=N;j++)read(val[i][j]);
    ptr=ePool,memset(E+1,0,sizeof(edge*)*T);
    for(int i=1;i<=N;i++)add(S,i,1,0);
    for(int i=1;i<=N;i++)for(int j=1;j<=N;j++)add(i,N+j,1,val[i][j]);
    for(int i=1;i<=N;i++)add(N+i,T,1,0);
    printf("%d\n",MinCostMaxFlow());
    ptr=ePool,memset(E+1,0,sizeof(edge*)*T);
    for(int i=1;i<=N;i++)add(S,i,1,0);
    for(int i=1;i<=N;i++)for(int j=1;j<=N;j++)add(i,N+j,1,-val[i][j]);
    for(int i=1;i<=N;i++)add(N+i,T,1,0);
    printf("%d\n",-MinCostMaxFlow());
    return 0;
}