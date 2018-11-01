#include<bits/stdc++.h>
using namespace std;

#define cin FAKE_ISTREAM
using edge_t=tuple<int,int,int>;
const int MX=200005,MXLG=20;

int T,N,M,fa[MX<<1],V,val[MX<<1],dis[MX<<1],Q,K,S;
int par[MXLG][MX<<1];
char vis[MX];
vector<int> TR[MX<<1];
vector<pair<int,int>> G[MX];
vector<edge_t> E;

struct Istream
{
    static const int MXL=2000000;
    char bf[MXL],*p1,*p2;
    FILE *F;
    Istream(FILE *F):p1(bf),p2(bf),F(F){}
    char getchar(){return p1==p2&&(p2=(p1=bf)+fread(bf,1,MXL,F))==bf?EOF:*p1++;}
    Istream& operator >> (int &x)
    {
        x=0;  int c=getchar();
        while(!isdigit(c))c=getchar();
        while(isdigit(c))x=x*10+c-'0',c=getchar();
        return *this;
    }
}cin(stdin);

void Dijkstra()
{
    using pii=pair<int,int>;
    priority_queue<pii,vector<pii>,greater<pii>> Q;
    memset(vis+1,0,sizeof(char[N]));
    fill(dis+1,dis+N+1,2000000100);
    Q.push(make_pair(dis[1]=0,1));
    while(!Q.empty())
    {
        int nw=Q.top().second;
		Q.pop();
        if(vis[nw])continue;
        vis[nw]=1;
        for(pair<int,int> &i:G[nw])
            if(dis[i.first]>dis[nw]+i.second)
                Q.push(make_pair(dis[i.first]=dis[nw]+i.second,i.first));
    }
}

void dfs(int u,int dep)
{
    if(u>N)dis[u]=INT_MAX;
    for(int i=1;(1<<i)<=dep;i++)
        par[i][u]=par[i-1][par[i-1][u]];
    for(int i:TR[u])
    {
        par[0][i]=u;
        dfs(i,dep+1);
        dis[u]=min(dis[u],dis[i]);
    }
}
int find(int u){return u==fa[u]?u:fa[u]=find(fa[u]);}
int solve(int u,int H)
{
    for(int i=18;i>=0;i--)
        if(!par[i][u]||val[par[i][u]]<=H)continue;
        else u=par[i][u];
    return dis[u];
}

int main()
{
    cin>>T;
    while(T--)
    {
        cin>>N>>M;
        for(int i=1;i<=N;i++)G[i].clear();
        for(int i=1;i<=N+N;i++)TR[i].clear();
        E.clear();
        memset(par,0,sizeof(par));
        for(int i=1;i<=N+N;i++)fa[i]=i;
        for(int i=1,u,v,l,a;i<=M;i++)
        {
            cin>>u>>v>>l>>a;
            G[u].push_back(make_pair(v,l));
            G[v].push_back(make_pair(u,l));
            E.push_back(make_tuple(a,u,v));
        }
        Dijkstra();
        sort(E.begin(),E.end(),[](const edge_t &a,const edge_t &b)->const bool{return get<0>(a)>get<0>(b);});
        V=N;
        for(edge_t &i:E)
        {
            int u=get<1>(i),v=get<2>(i);
            if(find(u)==find(v))continue;
            val[++V]=get<0>(i);
            TR[V].push_back(fa[u]);
            TR[V].push_back(fa[v]);
            fa[fa[u]]=fa[fa[v]]=V;
        }
        dfs(V,0);
        long long lastans=0;
		int v,p;
        cin>>Q>>K>>S;
        while(Q--)
        {
            cin>>v>>p;
            v=(v+K*lastans-1)%N+1;
            p=(p+K*lastans)%(S+1);
            printf("%d\n",lastans=solve(v,p));
        }
    }
    return 0;
}
