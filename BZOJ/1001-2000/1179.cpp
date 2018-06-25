#include<bits/stdc++.h>
using namespace std;
typedef vector<int>::iterator Vit;
const int MX=500005;

int N,M,dfn[MX],low[MX],val[MX],blt[MX],dis[MX],S,ans;
vector<int> G1[MX],G2[MX];
bool ins[MX];
queue<int> q;

inline int read()
{
    int x,c;
    x=0,c=getchar();
    while(!isdigit(c))c=getchar();
    while(isdigit(c))x=x*10+c-'0',c=getchar();
    return x;
}

void Tarjan(int u)
{
    static int tot=0,v,stk[MX],top=0;
    low[u]=dfn[u]=++tot,ins[u]=1,stk[++top]=u;
    for(Vit it=G1[u].begin();it!=G1[u].end();++it)
        if(!dfn[*it])Tarjan(*it),low[u]=min(low[u],low[*it]);
        else if(ins[*it])low[u]=min(low[u],dfn[*it]);
    if(low[u]==dfn[u])
    {
        while((v=stk[top--])!=u)
            blt[v]=u,val[u]+=val[v],ins[v]=0;
        ins[u]=0,blt[u]=u;
    }
}

int main()
{
    N=read(),M=read();
    for(int i=1,u,v;i<=M;i++)
    {
        u=read(),v=read();
        G1[u].push_back(v);
    }
    for(int i=1;i<=N;i++)val[i]=read();
    for(int i=1;i<=N;i++)if(!dfn[i])Tarjan(i);
    for(int i=1,u,v;i<=N;i++)for(Vit it=G1[i].begin();it!=G1[i].end();++it)
        if((u=blt[i])!=(v=blt[*it]))G2[u].push_back(v);
    memset(dis+1,0xc8,sizeof(int)*N);
    S=blt[read()],dis[S]=val[S],q.push(S);
    while(!q.empty())
    {
        int now=q.front();
        q.pop(),ins[now]=0;
        for(Vit it=G2[now].begin();it!=G2[now].end();++it)
            if(dis[*it]<dis[now]+val[*it])
            {
                dis[*it]=dis[now]+val[*it];
                if(!ins[*it])ins[*it]=0,q.push(*it);
            }
    }
    for(int P=read();P--;)ans=max(ans,dis[blt[read()]]);
    cout<<ans<<endl;
    return 0;
}