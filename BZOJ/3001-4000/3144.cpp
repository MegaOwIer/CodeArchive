#include<bits/stdc++.h>
using namespace std;
const int MV=40*40*40+5,ME=40*40*81,INF=2147483647;
#define rep(i,a,b) for(int i=a;i<=b;i++)
 
int P,Q,R,D,val[42][42][42],S,T;
int u[ME],v[ME],f[ME],tot,deg[MV];
 
struct MaxFlow
{
    struct edge
    {
        int to,f;
        edge *rev;
        edge(){}
        edge(int t,int f,edge *r):to(t),f(f),rev(r){}
    }*E[MV],*cur[MV],Pool[ME<<1];
    int dep[MV],S,T;
     
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
        queue<int> q;
        memset(dep+1,-1,sizeof(int)*T),dep[S]=0;
        q.push(S);
        while(!q.empty())
        {
            now=q.front(),q.pop();
            for(edge *i=E[now];i!=E[now+1];i++)if(i->f&&!~dep[i->to])
                dep[i->to]=dep[now]+1,q.push(i->to);
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
inline int id(int x,int y,int z){return (x-1)*Q*R+(y-1)*R+z;}
inline void add(int _u,int _v,int _f)
{
    ++tot,u[tot]=_u,v[tot]=_v,f[tot]=_f;
    deg[_u]++,deg[_v]++;
}
 
int main()
{
    read(P),read(Q),read(R),read(D),T=(S=P*Q*R+1)+1;
    rep(k,1,R)rep(i,1,P)rep(j,1,Q)read(val[i][j][k]);
    rep(i,1,P)rep(j,1,Q)
    {
        add(S,id(i,j,1),val[i][j][1]);
        rep(k,2,R)add(id(i,j,k-1),id(i,j,k),val[i][j][k]);
        add(id(i,j,R),T,INF);
        rep(k,D+1,R)
        {
            if(i!=1)add(id(i,j,k),id(i-1,j,k-D),INF);
            if(i!=P)add(id(i,j,k),id(i+1,j,k-D),INF);
            if(j!=1)add(id(i,j,k),id(i,j-1,k-D),INF);
            if(j!=Q)add(id(i,j,k),id(i,j+1,k-D),INF);
        }
    }
    printf("%d\n",Dinic(S,T));
}
