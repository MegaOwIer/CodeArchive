#include<bits/stdc++.h>
using namespace std;
typedef vector<int>::iterator Vit;
const int MX=100005;

int N,M,mod,siz[MX],cnt,stk[MX],top,ind[MX],dp[MX],num[MX];
int dfn[MX],low[MX],blt[MX],ans,ansnum;
vector<int> G1[MX],G2[MX];
bool ins[MX];

inline int read()
{
    int x=0,c=getchar();
    while(!isdigit(c))c=getchar();
    while(isdigit(c))x=x*10+c-'0',c=getchar();
    return x;
}
void Tarjan(int u)
{
    static int tot=0,v;
    dfn[u]=low[u]=++tot,ins[u]=1,stk[++top]=u;
    for(Vit it=G1[u].begin();it!=G1[u].end();++it)
        if(!dfn[*it])Tarjan(*it),low[u]=min(low[u],low[*it]);
        else if(ins[*it])low[u]=min(low[u],dfn[*it]);
    if(low[u]==dfn[u])
    {
        blt[u]=++cnt,siz[cnt]=1,ins[u]=0;
        while((v=stk[top--])!=u)blt[v]=cnt,siz[cnt]++,ins[v]=0;
    }
}

int main()
{
    N=read(),M=read(),mod=read();
    for(int i=1,u,v;i<=M;i++)
        u=read(),v=read(),G1[u].push_back(v);
    for(int i=1;i<=N;i++)if(!dfn[i])Tarjan(i);
    assert(top==0);
    for(int i=1,u,v;i<=N;i++)
    {
        u=blt[i];
        for(Vit j=G1[i].begin();j!=G1[i].end();++j)
            if((v=blt[*j])!=u)G2[u].push_back(v);
    }
    for(int i=1;i<=cnt;i++)
    {
        sort(G2[i].begin(),G2[i].end());
        G2[i].erase(unique(G2[i].begin(),G2[i].end()),G2[i].end());
        for(Vit j=G2[i].begin();j!=G2[i].end();++j)ind[*j]++;
    }
    for(int i=1;i<=cnt;i++)if(!ind[i])stk[++top]=i,dp[i]=siz[i],num[i]=1;
    for(int i=1,u;i<=top;i++)for(Vit j=G2[stk[i]].begin();j!=G2[stk[i]].end();++j)
    {
        u=stk[i];
        if(dp[u]+siz[*j]>dp[*j])dp[*j]=dp[u]+siz[*j],num[*j]=num[u];
        else if(dp[u]+siz[*j]==dp[*j])num[*j]=(num[*j]+num[u])%mod;
        if(!--ind[*j])stk[++top]=*j;
    }
    for(int i=1;i<=cnt;i++)
        if(dp[i]>ans)ans=dp[i],ansnum=num[i];
        else if(dp[i]==ans)ansnum=(ansnum+num[i])%mod;
    printf("%d\n%d\n",ans,ansnum%mod);
    return 0;
}
