#include<bits/stdc++.h>
using namespace std;
const int MV=1200,ME=4000;

int M,N,num[22][42],id[22][42],cnt,dis[MV],S,T;
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
    fill(dis+1,dis+T+1,-1e9),dis[S]=0;
    memset(inq+1,0,sizeof(char)*T),inq[S]=1;
    q.push(S);
    while(!q.empty())
    {
        now=q.front(),q.pop(),inq[now]=0;
        for(edge *i=E[now];i;i=i->nxt)if(i->f&&dis[i->to]<dis[now]+i->c)
        {
            dis[i->to]=dis[now]+i->c,from[i->to]=i;
            if(!inq[i->to])q.push(i->to),inq[i->to]=1;
        }
    }
    return dis[T]>-1e9;
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
    read(N),read(M);
    for(int i=1;i<=M;i++)for(int j=1;j<N+i;j++)read(num[i][j]),id[i][j]=++cnt;
    T=(S=cnt<<1|1)+1;
    ptr=ePool,memset(E+1,0,sizeof(edge*)*T);
    for(int i=1;i<=N;i++)add(S,id[1][i],1,0);
    for(int i=1;i<M;i++)for(int j=1;j<N+i;j++)
    {
        add(id[i][j],id[i][j]+cnt,1,num[i][j]);
        add(id[i][j]+cnt,id[i+1][j],1,0);
        add(id[i][j]+cnt,id[i+1][j+1],1,0);
    }
    for(int i=1;i<N+M;i++)add(id[M][i],T,1,num[M][i]);
    printf("%d\n",MinCostMaxFlow());
    ptr=ePool,memset(E+1,0,sizeof(edge*)*T);
    for(int i=1;i<=N;i++)add(S,id[1][i],1,0);
    for(int i=1;i<M;i++)for(int j=1;j<N+i;j++)
        add(id[i][j],id[i+1][j],1,num[i][j]),
        add(id[i][j],id[i+1][j+1],1,num[i][j]);
    for(int i=1;i<N+M;i++)add(id[M][i],T,1e9,num[M][i]);
    printf("%d\n",MinCostMaxFlow());
    ptr=ePool,memset(E+1,0,sizeof(edge*)*T);
    for(int i=1;i<=N;i++)add(S,id[1][i],1,0);
    for(int i=1;i<M;i++)for(int j=1;j<N+i;j++)
        add(id[i][j],id[i+1][j],1e9,num[i][j]),
        add(id[i][j],id[i+1][j+1],1e9,num[i][j]);
    for(int i=1;i<N+M;i++)add(id[M][i],T,1e9,num[M][i]);
    printf("%d\n",MinCostMaxFlow());
    return 0;
}