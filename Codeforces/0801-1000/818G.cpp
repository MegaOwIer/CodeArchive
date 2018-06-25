#include<bits/stdc++.h>
using namespace std;
const int MX=3005,MV=6005,ME=4507550;

int N,a[MX],S,T,u[ME],v[ME],f[ME],c[ME],tot,deg[MV];

struct MinCostMaxFlow
{
    struct edge
    {
        int to,c,f;
        edge *rev;
        edge(){}
        edge(int t,int c,int f,edge *r):to(t),c(c),f(f),rev(r){}
    }*E[MV],Pool[ME<<1],*pre[MV];
    int S,T,dis[MV],p[MV];
    char vis[MV];

    void build()
    {
        E[1]=Pool;
        for(int i=1;i<=T;i++)E[i+1]=E[i]+deg[i];
        for(int i=1;i<=tot;i++)
        {
            --deg[u[i]],--deg[v[i]];
            E[u[i]][deg[u[i]]]=edge(v[i],c[i],f[i],E[v[i]]+deg[v[i]]);
            E[v[i]][deg[v[i]]]=edge(u[i],-c[i],0,E[u[i]]+deg[u[i]]);
        }
    }
    void SPFA()
    {
        deque<int> q;
        memset(p+1,0x3f,sizeof(int)*T);
        p[S]=0,q.push_back(S);
        while(!q.empty())
        {
            int now=q.front();
            q.pop_front(),vis[now]=0;
            for(edge *i=E[now];i!=E[now+1];i++)
                if(i->f&&p[i->to]>p[now]+i->c)
                {
                    p[i->to]=p[now]+i->c;
                    if(!vis[i->to])
                    {
                        vis[i->to]=1;
                        if(!q.size()||p[q.front()]<p[i->to])q.push_back(i->to);
                        else q.push_front(i->to);
                    }
                }
        }
    }
    inline bool Dijkstra();
    int solve();
}Edmond_Karp;
inline bool MinCostMaxFlow::Dijkstra()
{
    using pii=pair<int,int>;
    priority_queue<pii,vector<pii>,greater<pii> > q;
    memset(dis+1,0x3f,sizeof(int)*T);
    memset(vis+1,0,sizeof(char)*T);
    q.push(make_pair(dis[S]=0,S));
    while(!q.empty())
    {
        int now=q.top().second,tmp;
        q.pop();
        if(vis[now])continue;
        vis[now]=1;
        for(edge *i=E[now];i!=E[now+1];i++)
        {
            if(i->f&&dis[i->to]>(tmp=dis[now]+i->c+p[now]-p[i->to]))
                q.push(make_pair(dis[i->to]=tmp,i->to)),pre[i->to]=i;
        }
    }
    return dis[T]<0x3f3f3f3f;
}
inline int MinCostMaxFlow::solve()
{
    int ans=0;
    SPFA();
    for(int i=0;i<4;i++)
    {
        Dijkstra();
        ans+=dis[T]+p[T];
        for(int i=T;i!=S;i=pre[i]->rev->to)
            pre[i]->f--,pre[i]->rev->f++;
        for(int i=1;i<=T;i++)p[i]+=dis[i];
    }
    return ans;
}

void add(int _u,int _v,int _f,int _c)
{
    ++tot,deg[_u]++,deg[_v]++;
    u[tot]=_u,v[tot]=_v,f[tot]=_f,c[tot]=_c;
}

int main()
{
    ios::sync_with_stdio(0);
    cin>>N;
    for(int i=1;i<=N;i++)cin>>a[i];
    S=N*2+1,T=S+1;
    Edmond_Karp.S=S,Edmond_Karp.T=T;
    for(int i=1;i<=N;i++)add(i,i+N,1,-1);
    for(int i=1;i<=N;i++)add(S,i,1,0);
    for(int i=1;i<=N;i++)add(i+N,T,1,0);
    for(int i=2;i<=N;i++)for(int j=1;j<i;j++)
        if(abs(a[i]-a[j])==1||(a[i]-a[j])%7==0)
            add(j+N,i,1,0);
    Edmond_Karp.build();
    cout<<-Edmond_Karp.solve()<<endl;
    return 0;
}
