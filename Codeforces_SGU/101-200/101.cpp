#include<bits/stdc++.h>
using namespace std;
const int MV=10,ME=105;

int N,deg[MV],S;
bool vis[ME];
vector<int> ans;

struct edge
{
    int to,id;
    edge *nxt;

    edge(){}
    edge(int t,edge *n,int d):to(t),nxt(n),id(d){}
    void* operator new (size_t);
}*E[MV];
inline void* edge::operator new (size_t)
{
    static edge Pool[ME<<1],*ptr=Pool;
    return ptr++;
}

inline int read()
{
    int x=0,c=getchar();
    while(!isdigit(c))c=getchar();
    while(isdigit(c))x=x*10+c-'0',c=getchar();
    return x;
}
inline void add(int u,int v,int id)
{
    E[u]=new edge(v,E[u],id);
    E[v]=new edge(u,E[v],-id);
}
inline void check()
{
    int cnt=0;
    for(int i=0;i<=6;i++)if(deg[i]&1)
        S=i,cnt++;
    if(cnt!=0&&cnt!=2)puts("No solution"),exit(0);
}
void dfs(int u)
{
    static auto abs=[](int a){return a>0?a:-a;};
    for(edge *i=E[u];i;i=i->nxt)if(!vis[abs(i->id)])
        vis[abs(i->id)]=1,dfs(i->to),ans.push_back(i->id);
}

int main()
{
    N=read();
    for(int i=1,u,v;i<=N;i++)
        deg[S=u=read()]++,deg[v=read()]++,add(u,v,i);
    check(),dfs(S);
    for(int i=1;i<=N;i++)if(!vis[i])return puts("No solution"),0;
    for(int i:ans)
        if(i>0)printf("%d -\n",i);
        else printf("%d +\n",-i);
    return 0;
}
