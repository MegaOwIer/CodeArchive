#include<bits/stdc++.h>
using namespace std;
const int ME=50005,MV=10005,INF=1000000000;
const int dx[]={0,1,0,-1},dy[]={1,0,-1,0};

int N,M,a[105][105],S,T,u[ME],v[ME],f[ME],deg[MV],tot;

struct MaxFlow
{
    struct edge
    {
        int to,f;
        edge *rev;
        edge(){}
        edge(int t,int f,edge *r):to(t),f(f),rev(r){}
    }*G[MV],*cur[MV],Pool[ME<<1];
    int dep[MV];

    MaxFlow(){}
    void build()
    {
        G[1]=Pool;
        for(int i=1;i<=T;i++)G[i+1]=G[i]+deg[i];
        for(int i=1;i<=tot;i++)
        {
            int du=--deg[u[i]],dv=--deg[v[i]];
            G[u[i]][du]=edge(v[i],f[i],G[v[i]]+dv);
            G[v[i]][dv]=edge(u[i],0,G[u[i]]+du);
        }
    }
    bool bfs()
    {
        memset(dep+1,-1,sizeof(int)*T);
        queue<int> q;
        q.push(S),dep[S]=0;
        while(!q.empty())
        {
            int nw=q.front();
            q.pop();
            for(edge *i=G[nw];i!=G[nw+1];i++)if(!~dep[i->to]&&i->f)
                dep[i->to]=dep[nw]+1,q.push(i->to);
        }
        return ~dep[T];
    }
    int dfs(int u,int flow)
    {
        if(u==T||!flow)return flow;
        int w,used=0;
        for(edge* &i=cur[u];i!=G[u+1];i++)if(dep[i->to]==dep[u]+1&&i->f)
        {
            w=dfs(i->to,min(flow-used,i->f));
            i->f-=w,i->rev->f+=w,used+=w;
            if(flow==used)break;
        }
        return used;
    }
    int operator () ()
    {
        build();
        int ans=0;
        while(bfs())memcpy(cur+1,G+1,sizeof(edge*)*(T+1)),ans+=dfs(S,INF);
        return ans;
    }
}Dinic;

inline int read()
{
    int x=0,c=getchar();
    while(!isdigit(c))c=getchar();
    while(isdigit(c))x=x*10+c-'0',c=getchar();
    return x;
}
inline int getid(int x,int y){return (x-1)*M+y;}
inline void add(int _u,int _v,int _f)
{
    ++tot,++deg[_u],++deg[_v];
    u[tot]=_u,v[tot]=_v,f[tot]=_f;
}

int main()
{
    N=read(),M=read(),T=(S=N*M+1)+1;
    for(int i=1;i<=N;i++)for(int j=1;j<=M;j++)
    {
        a[i][j]=read();
        if(a[i][j]==1)add(S,getid(i,j),INF);
        else if(a[i][j]==2)add(getid(i,j),T,INF);
    }
    for(int i=1;i<=N;i++)for(int j=1;j<=M;j++)if(a[i][j]<=1)
        for(int k=0;k<4;k++)
        {
            int nx=i+dx[k],ny=j+dy[k];
            if(!nx||!ny||nx>N||ny>M)continue;
            if(a[nx][ny]!=1)add(getid(i,j),getid(nx,ny),1);
        }
    printf("%d\n",Dinic());
    return 0;
}