#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MV=1010,ME=12500,INF=2147483647;

int N,M,A[MV],S,T,deg[MV];

struct edge{int u,v,f,c;};
vector<edge> EDGE;
typedef vector<edge>::iterator Eit;

struct MinCostMaxFlow
{
    struct edge
    {
        int to,f,c;
        edge *rev;
        edge(){}
        edge(int t,int f,int c,edge *r):to(t),f(f),c(c),rev(r){}
    }*G[MV],Pool[ME<<1],*pre[MV];
    LL p[MV],dis[MV];
    char vis[MV];

    MinCostMaxFlow(){}
    void build()
    {
        G[1]=Pool;
        for(int i=1;i<=T;i++)G[i+1]=G[i]+deg[i];
        for(Eit it=EDGE.begin();it!=EDGE.end();++it)
        {
            int du=--deg[it->u],dv=--deg[it->v];
            G[it->u][du]=edge(it->v,it->f,it->c,G[it->v]+dv);
            G[it->v][dv]=edge(it->u,0,-it->c,G[it->u]+du);
        }
    }
    void SPFA()
    {
        queue<int> q;
        q.push(S);
        while(!q.empty())
        {
            int nw=q.front();
            q.pop(),vis[nw]=0;
            for(edge *i=G[nw];i!=G[nw+1];i++)
                if(i->f&&p[i->to]>p[nw]+i->c)
                {
                    p[i->to]=p[nw]+i->c;
                    if(!vis[i->to])q.push(i->to),vis[i->to]=1;
                }
        }
    }
    bool Dijkstra()
    {
        typedef pair<LL,int> pLi;
        priority_queue<pLi,vector<pLi>,greater<pLi> > q;
        memset(dis+1,0x3f,sizeof(LL)*T);
        memset(vis+1,0,sizeof(char)*T);
        q.push(make_pair(dis[S]=0,S));
        while(!q.empty())
        {
            int nw=q.top().second,tmp;
            q.pop();
            if(vis[nw])continue;
            vis[nw]=1;
            for(edge *i=G[nw];i!=G[nw+1];i++)
                if(i->f&&dis[i->to]>(tmp=dis[nw]+i->c+p[nw]-p[i->to]))
                    q.push(make_pair(dis[i->to]=tmp,i->to)),pre[i->to]=i;
        }
        return dis[T]<0x3f3f3f3f3f3f3f3fLL;
    }
    LL operator () ()
    {
        build(),SPFA();
        LL ans=0;
        while(Dijkstra())
        {
            int flow=INF;
            for(int i=T;i!=S;i=pre[i]->rev->to)flow=min(flow,pre[i]->f);
            for(int i=T;i!=S;i=pre[i]->rev->to)
                pre[i]->f-=flow,pre[i]->rev->f+=flow;
            ans+=LL(dis[T]+p[T])*flow;
            for(int i=1;i<=T;i++)p[i]+=dis[i];
        }
        return ans;
    }
}Johnson;

inline int read()
{
    int x=0,c=getchar();
    while(!isdigit(c))c=getchar();
    while(isdigit(c))x=x*10+c-'0',c=getchar();
    return x;
}
inline void add(int u,int v,int f,int c)
{
    ++deg[u],++deg[v];
    EDGE.push_back((edge){u,v,f,c});
}

int main()
{
    N=read(),M=read(),T=(S=N+2)+1;
    for(int i=1;i<=N;i++)A[i]=read();
    for(int i=1,s,t,c;i<=M;i++)
        s=read(),t=read(),c=read(),add(s,t+1,INF,c);
    for(int i=1;i<=N+1;i++)
        if(A[i]-A[i-1]>0)add(S,i,A[i]-A[i-1],0);
        else add(i,T,A[i-1]-A[i],0);
    for(int i=1;i<=N;i++)add(i+1,i,INF,0);
    printf("%lld\n",Johnson());
    return 0;
}