#include<bits/stdc++.h>
using namespace std;

using LL=long long;
using pii=pair<int,int>;
#define endl "\n"
const int MX=300005;

int N,M,head[MX],tot=1,dfn[MX],low[MX],Bcnt,blt[MX],ans,dp[MX];
vector<int> G[MX];

struct edge{int to,nxt,isb;}e[MX<<1];

inline void add(int u,int v)
{
    e[++tot]=(edge){v,head[u],0},head[u]=tot;
    e[++tot]=(edge){u,head[v],0},head[v]=tot;
}
void Tarjan(int u,int f)
{
    static int cnt=0;
    dfn[u]=low[u]=++cnt;
    for(int i=head[u];i;i=e[i].nxt)
    {
        int v=e[i].to;
        if(!dfn[v])
        {
            Tarjan(v,u);
            low[u]=min(low[u],low[v]);
            if(low[v]>dfn[u])
                e[i].isb=e[i^1].isb=1;
        }
        else if(dfn[v]<dfn[u]&&v!=f)
            low[u]=min(low[u],dfn[v]);
    }
}
void dfs(int u)
{
    dfn[u]=1,blt[u]=Bcnt;
    for(int i=head[u];i;i=e[i].nxt)
        if(!e[i].isb&&!dfn[e[i].to])dfs(e[i].to);
}
inline void link(int u,int v)
{
    G[u].push_back(v),G[v].push_back(u);
}
void dfs2(int u,int f)
{
    int cur=0;
    for(int i:G[u])if(i!=f)
    {
        dfs2(i,u);
        ans=max(ans,cur+dp[i]+1);
        cur=max(cur,dp[i]+1);
    }
    dp[u]=cur;
}

int main()
{
    ios::sync_with_stdio(0);
    cin>>N>>M;
    for(int i=1,u,v;i<=M;i++)
        cin>>u>>v,add(u,v);
    for(int i=1;i<=N;i++)if(!dfn[i])Tarjan(i,-1);
    memset(dfn+1,0,sizeof(int)*N);
    for(int i=1;i<=N;i++)if(!dfn[i])
        ++Bcnt,dfs(i);
    for(int u=1;u<=N;u++)
    {
        for(int i=head[u];i;i=e[i].nxt)if(i&1)
            if(blt[u]!=blt[e[i].to])link(blt[u],blt[e[i].to]);
    }
    for(int i=1;i<=Bcnt;i++)
    {
        sort(G[i].begin(),G[i].end());
        G[i].erase(
            unique(G[i].begin(),G[i].end()),
            G[i].end()
        );
    }
    dfs2(1,0);
    cout<<ans<<endl;
    return 0;
}
