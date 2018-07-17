#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int MX=20005;
const int MV=20005,ME=40005;

int N,M,deg[MX],ans,fa[MX];
int S,T,tot[MV];
bool vis[MX];

#define cin FAKE_STREAM
struct Istream
{
    static const int MXL=200000;
    char bf[MXL],*p1,*p2;
    FILE *F;
    Istream(FILE *F):p1(bf),p2(bf),F(F){}
    char getchar(){return p1==p2&&(p2=(p1=bf)+fread(bf,1,MXL,F))==bf?EOF:*p1++;}
    Istream& operator >> (int& x)
    {
        x=0;  int c=getchar(),f=1;
        while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
        while(isdigit(c))x=x*10+c-'0',c=getchar();
        return x*=f,*this;
    }
}cin(stdin);

struct Point
{
    int x,y;
    bool operator < (const Point &a)const{return y<a.y;}
    LL operator * (const Point &a){return (LL)x*a.y-(LL)y*a.x;}
}P[MX];
Istream& operator >> (Istream& os,Point& x){return os>>x.x>>x.y;}

struct edge{int u,v,f,c;};
vector<edge> E;

struct MinCostMaxFlow
{
    struct edge
    {
        int to,f,c;
        edge *rev;
        edge(){}
        edge(int t,int f,int c,edge *r):to(t),f(f),c(c),rev(r){}
    }*G[MV],*cur[MV],Pool[ME<<1];
    int dis[MV];
    char inq[MV];

    MinCostMaxFlow(){}
    void build()
    {
        G[1]=Pool;
        for(int i=1;i<=T;i++)G[i+1]=G[i]+tot[i];
        for(int i=0;i<E.size();i++)
        {
            int u=E[i].u,v=E[i].v,f=E[i].f,c=E[i].c;
            int du=--tot[u],dv=--tot[v];
            G[u][du]=edge(v,f,c,G[v]+dv);
            G[v][dv]=edge(u,0,-c,G[u]+du);
        } 
    }
    bool SPFA(int,int);
    int dfs(int,int,int);
    int operator () (int S,int T)
    {
        int cost=0;
        while(SPFA(T,S))
            memcpy(cur+1,G+1,sizeof(edge*)*(T+1)),cost+=dis[S]*dfs(S,1e9,T);
        return cost;
    }
}ZKW;
inline bool MinCostMaxFlow::SPFA(int T,int S)
{
    memset(dis+1,0x3f,sizeof(int)*T);
    memset(inq+1,0,sizeof(char)*T);
    queue<int> Q;
    Q.push(T),dis[T]=0;
    while(!Q.empty())
    {
        int nw=Q.front();  Q.pop(),inq[nw]=0;
        for(edge *i=G[nw];i!=G[nw+1];i++)
            if(i->rev->f&&dis[i->to]>dis[nw]+i->rev->c)
            {
                dis[i->to]=dis[nw]+i->rev->c;
                if(!inq[i->to])Q.push(i->to),inq[i->to]=1;
            }
    }
    return dis[S]!=0x3f3f3f3f;
}
inline int MinCostMaxFlow::dfs(int u,int flow,int T)
{
    if(u==T)return flow;
    int used=0,w;
    inq[u]=1;
    for(edge* &i=cur[u];i!=G[u+1];i++)
        if(i->f&&!inq[i->to]&&dis[i->to]==dis[u]-i->c)
        {
            w=dfs(i->to,min(flow-used,i->f),T);
            i->f-=w,i->rev->f+=w,used+=w;
            if(used==flow)break;
        }
    inq[u]=0;
    return used;
}

inline void add_edge(int u,int v,int f,int c)
{
    E.push_back((edge){u,v,f,c});
    ++tot[u],++tot[v];
}
int find(int u){return u==fa[u]?u:fa[u]=find(fa[u]);}

int main()
{
    cin>>N>>M;
    S=N+1,T=N+2;
    for(int i=1;i<=N;i++)cin>>P[i];
    for(int i=1;i<=N;i++)fa[i]=i;
    cout<<P[3]*P[4]<<endl;
    for(int i=1,u,v;i<=M;i++)
    {
        cin>>u>>v;
        fa[find(u)]=find(v);
        vis[u]=vis[v]=1;
        if(P[v]<P[u])swap(u,v);
        deg[u]--,deg[v]++;
        if(((P[u].y>=0)^(P[v].y>=0))&&P[u]*P[v]>0)
            add_edge(u,v,1,2),ans++;
        else add_edge(u,v,1,0);
    }
    for(int i=1;i<=N;i++)
        if(vis[i]&&find(i)!=find(1))return puts("-1"),0;
        else if(deg[i]&1)return puts("-1"),0;
        else if(deg[i]>0)add_edge(i,T,deg[i]>>1,0);
        else if(deg[i]<0)add_edge(S,i,-deg[i]>>1,0);
    ZKW.build();
    printf("%d\n",ans-ZKW(S,T));
    return 0;
}
