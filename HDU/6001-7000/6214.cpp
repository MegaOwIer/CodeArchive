#include<bits/stdc++.h>
using namespace std;
const int MV=205,ME=1005;

int cas,N,M,u[ME],v[ME],f[ME],deg[MV],S,T,dep[MV];

struct edge
{
    int to,f;
    edge *rev;
    edge(){}
    edge(int t,int f,edge *r):to(t),f(f),rev(r){}
}Pool[ME<<1],*E[MV],*cur[MV];

inline int read()
{
    int x=0,c=getchar();
    while(!isdigit(c))c=getchar();
    while(isdigit(c))x=x*10+c-'0',c=getchar();
    return x;
}
bool bfs()
{
    queue<int> q;
    memset(dep+1,-1,sizeof(int)*N);
    dep[S]=0,q.push(S);
    while(!q.empty())
    {
        int nw=q.front();
        q.pop();
        for(edge *i=E[nw];i!=E[nw+1];i++)if(i->f&&!~dep[i->to])
            dep[i->to]=dep[nw]+1,q.push(i->to);
    }
    return ~dep[T];
}
int dfs(int u,int flow)
{
    if(u==T||!flow)return flow;
    int w,used=0;
    for(edge* &i=cur[u];i!=E[u+1];i++)if(i->f&&dep[i->to]==dep[u]+1)
    {
        w=dfs(i->to,min(flow-used,i->f));
        i->f-=w,i->rev->f+=w,used+=w;
        if(used==flow)break;
    }
    return used;
}
int Dinic()
{
    int flow=0;
    while(bfs())memcpy(cur+1,E+1,sizeof(edge*)*(N+1)),flow+=dfs(S,-1U>>1);
    return flow&1023;
}

int main()
{
    cas=read();
    while(cas--)
    {
        N=read(),M=read(),S=read(),T=read();
        memset(deg+1,0,sizeof(int)*N);
        for(int i=1;i<=M;i++)
        {
            u[i]=read(),v[i]=read(),f[i]=read()<<10|1;
            ++deg[u[i]],++deg[v[i]];
        }
        E[1]=Pool;
        for(int i=1;i<=N;i++)E[i+1]=E[i]+deg[i];
        for(int i=1;i<=M;i++)
        {
            int du=--deg[u[i]],dv=--deg[v[i]];
            E[u[i]][du]=edge(v[i],f[i],E[v[i]]+dv);
            E[v[i]][dv]=edge(u[i],0,E[u[i]]+du);
        }
        printf("%d\n",Dinic());
    }
    return 0;
}
