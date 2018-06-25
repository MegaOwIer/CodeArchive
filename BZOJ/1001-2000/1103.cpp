#include<bits/stdc++.h>
using namespace std;
const int MX=250005;

int N,tr[MX],dfn[MX],ed[MX],M;
vector<int> G[MX];
char op;

inline int read()
{
    static int x,c;
    x=0,c=getchar();
    while(!isdigit(c))c=getchar();
    while(isdigit(c))x=x*10+c-'0',c=getchar();
    return x;
}
inline void add(int u,int v){for(;u<=N;u+=u&-u)tr[u]+=v;}
inline int ask(int u){int ans=0;for(;u;u-=u&-u)ans+=tr[u];return ans-1;}
void dfs(int u,int f)
{
    static int cnt=0;
    add(dfn[u]=++cnt,1);
    for(vector<int>::iterator it=G[u].begin();it!=G[u].end();++it)
        if(f!=*it)dfs(*it,u);
    add((ed[u]=cnt)+1,-1);
}

int main()
{
    N=read();
    for(int i=1,u,v;i<N;i++)
    {
        u=read(),v=read();
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(1,0);
    M=read();
    for(int i=1,u,v;i<N+M;i++)
    {
        do op=getchar();while(!isalpha(op));
        if(op=='A')
        {
            u=read(),v=read();
            if(dfn[u]<dfn[v])swap(u,v);
            add(dfn[u],-1),add(ed[u]+1,1);
        }
        else u=read(),printf("%d\n",ask(dfn[u]));
    }
    return 0;
}