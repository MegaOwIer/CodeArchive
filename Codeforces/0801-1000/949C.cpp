#include<bits/stdc++.h>
using namespace std;
const int MX=100005;

struct edge{int to,nxt;}e[MX<<1];
int n,m,h,val[MX],head[MX],tot,dfn[MX],low[MX],cnt,stk[MX],top;
int num,blt[MX],siz[MX],out[MX],ans=1e9,id;
bool ins[MX];

inline void add(int u,int v)
{
    e[++tot]=(edge){v,head[u]},head[u]=tot;
}
inline void Tarjan(int u)
{
    low[u]=dfn[u]=++cnt;
    stk[++top]=u,ins[u]=1;
    for(int i=head[u];i;i=e[i].nxt)
        if(!dfn[e[i].to])Tarjan(e[i].to),low[u]=min(low[u],low[e[i].to]);
        else if(ins[e[i].to])low[u]=min(low[u],dfn[e[i].to]);
    if(dfn[u]==low[u])
    {
        ++num;
        do blt[stk[top]]=num,siz[num]++;
        while(stk[top--]!=u);
    }
}

int main()
{
    scanf("%d%d%d",&n,&m,&h);
    for(int i=1;i<=n;i++)scanf("%d",val+i);
    for(int i=1,u,v;i<=m;i++)
    {
        scanf("%d%d",&u,&v);
        if((val[u]+1)%h==val[v])add(u,v);
        if((val[v]+1)%h==val[u])add(v,u);
    }
    for(int i=1;i<=n;i++)if(!dfn[i])Tarjan(i);
    for(int i=1;i<=n;i++)
        for(int j=head[i];j;j=e[j].nxt)
            if(blt[i]!=blt[e[j].to])out[blt[i]]++;
    for(int i=1;i<=num;i++)if(!out[i])
        if(ans>siz[i])ans=siz[i],id=i;
    printf("%d\n",ans);
    for(int i=1;i<=n;i++)if(blt[i]==id)printf("%d ",i);
    return 0;
}
