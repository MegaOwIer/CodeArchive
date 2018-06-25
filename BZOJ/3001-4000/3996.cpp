#include<bits/stdc++.h>
using namespace std;
const int MV=500*501+5,ME=500*500*3+550,INF=2147483647;
 
int N,id,sum;
int S,T,u[ME],v[ME],f[ME],tot,deg[MV];
 
struct MaxFlow
{
    struct edge
    {
        int to,f;
        edge *rev;
        edge(){}
        edge(int t,int f,edge *r):to(t),f(f),rev(r){}
    }*E[MV],*cur[MV],Pool[ME<<1];
    int dep[MV],S,T,q[MV],hd,tl;
     
    void build_graph()
    {
        E[1]=Pool;
        for(int i=1;i<=T;i++)E[i+1]=E[i]+deg[i];
        for(int i=1;i<=tot;i++)
        {
            --deg[u[i]],--deg[v[i]];
            E[u[i]][deg[u[i]]]=edge(v[i],f[i],E[v[i]]+deg[v[i]]);
            E[v[i]][deg[v[i]]]=edge(u[i],0,E[u[i]]+deg[u[i]]);
        }
    }
    bool bfs()
    {
        int now;
        q[hd=tl=1]=S;
        memset(dep+1,-1,sizeof(int)*T),dep[S]=0;
        while(hd<=tl)
        {
            now=q[hd++];
            for(edge *i=E[now];i!=E[now+1];i++)if(i->f&&!~dep[i->to])
                dep[i->to]=dep[now]+1,q[++tl]=i->to;
        }
        return ~dep[T];
    }
    int dfs(int u,int flow)
    {
        if(u==T||!flow)return flow;
        int used=0,w;
        for(edge* &i=cur[u];i!=E[u+1];i++)if(i->f&&dep[i->to]==dep[u]+1)
            w=dfs(i->to,min(flow-used,i->f)),i->f-=w,i->rev->f+=w,used+=w;
        return used;
    }
    int operator()(int _S,int _T)
    {
        int ans=0;
        S=_S,T=_T,build_graph();
        while(bfs())memcpy(cur+1,E+1,sizeof(edge*)*(T+1)),ans+=dfs(S,INF);
        return ans;
    }
}Dinic;
 
inline void read(int& x)
{
    static char c;
    c=getchar(),x=0;
    while(!isdigit(c))c=getchar();
    while(isdigit(c))x=x*10+c-'0',c=getchar();
}
inline void add(int _u,int _v,int _f)
{
    ++tot,u[tot]=_u,v[tot]=_v,f[tot]=_f;
    deg[_u]++,deg[_v]++;
}
 
int main()
{
    read(N),T=(S=N*N+N+1)+1,id=N;
    for(int i=1,x;i<=N;i++)for(int j=1;j<=N;j++)
    {
        read(x),++id;
        add(i,id,INF),add(j,id,INF),add(id,T,x);
        sum+=x;
    }
    for(int i=1,x;i<=N;i++)read(x),add(S,i,x);
    printf("%d\n",sum-Dinic(S,T));
}
