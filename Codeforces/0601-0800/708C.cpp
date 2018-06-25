#include<bits/stdc++.h>
using namespace std;
const int MX=400005;

int N,mxs[MX][2],siz[MX],dfn[MX],ed[MX],mxcut[MX],ans[MX];
vector<int> G[MX];

void dfs1(int u,int f)
{
    siz[u]=1;
    for(int i:G[u])if(i!=f)
    {
        dfs1(i,u);
        siz[u]+=siz[i];
        if(mxcut[i]>mxcut[u])
            mxcut[u]=mxcut[i],mxs[u][1]=mxs[u][0],mxs[u][0]=i;
        else if(mxcut[i]>mxcut[mxs[u][1]])mxs[u][1]=i;
    }
    if(siz[u]<=N/2)mxcut[u]=siz[u];
}
void dfs2(int u,int f,int mx)
{
    ans[u]=1;
    for(int i:G[u])
        if(i==f)
        {
            int tmp=N-siz[u];
            if(tmp>N/2&&tmp-mx>N/2)ans[u]=0;
        }
        else if(siz[i]>N/2&&siz[i]-mxcut[i]>N/2)ans[u]=0;
    for(int i:G[u])if(i!=f)
    {
        int tmp;
        if(N-siz[i]<=N/2)tmp=N-siz[i];
        else if(i==mxs[u][0])tmp=max(mx,mxcut[mxs[u][1]]);
        else tmp=max(mx,mxcut[mxs[u][0]]);
        dfs2(i,u,tmp);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin>>N;
    for(int i=1,u,v;i<N;i++)
    {
        cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs1(1,-1);
    dfs2(1,-1,0);
    for(int i=1;i<=N;i++)cout<<ans[i]<<' ';
    return 0;
}
