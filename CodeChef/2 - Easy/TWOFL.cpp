#include<bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
const int MX=2002,MN=4000002,dx[]={0,1,0,-1},dy[]={1,0,-1,0};
#define REP(i,a,b) for(int i=a;i<=b;i++)

int N,M,col[MX][MX],id[MX][MX],V,siz[MN],color[MN],ans,tmp,ins[MN],dfs_cnt;
bool vis[MX*MX*2];
vector<pii> G[MN];

inline int read()
{
    int x=0,c=getchar();
    while(!isdigit(c))c=getchar();
    while(isdigit(c))x=x*10+c-'0',c=getchar();
    return x;
}
void dfs1(int x,int y,int c,int& siz)
{
    ++siz,id[x][y]=V;
    REP(i,0,3)
    {
        int xx=x+dx[i],yy=y+dy[i];
        if(!xx||!yy||xx>N||yy>M)continue;
        if(col[xx][yy]!=c||id[xx][yy])continue;
        dfs1(xx,yy,c,siz);
    }
}
inline void add(int u,int v)
{
    static int tot=0;
    ++tot;
    G[u].push_back(make_pair(v,tot));
    G[v].push_back(make_pair(u,tot));
}
void dfs2(int u,int c1,int c2)
{
    tmp+=siz[u],ins[u]=dfs_cnt;
    for(auto i:G[u])if(!vis[i.second]&&(color[i.first]==c1||color[i.first]==c2))
    {
        vis[i.second]=1;
        if(ins[i.first]!=dfs_cnt)dfs2(i.first,c1,c2);
    }
}

int main()
{
    N=read(),M=read();
    REP(i,1,N)REP(j,1,M)col[i][j]=read();
    REP(i,1,N)REP(j,1,M)if(!id[i][j])
        dfs1(i,j,col[i][j],siz[++V]),color[V]=col[i][j],ans=max(ans,siz[V]);
    REP(i,1,N)REP(j,1,M)REP(k,0,1)
    {
        int xx=i+dx[k],yy=j+dy[k];
        if(!xx||!yy||xx>N||yy>M)continue;
        if(col[i][j]!=col[xx][yy])add(id[i][j],id[xx][yy]);
    }
    REP(i,1,V)
    {
        sort(G[i].begin(),G[i].end());
        G[i].erase(
            unique(G[i].begin(),G[i].end(),[](pii a,pii b){return a.first==b.first;}),
            G[i].end()
        );
    }
    REP(i,1,V)for(pii it:G[i])if(!vis[it.second])
        ++dfs_cnt,tmp=0,dfs2(i,color[i],color[it.first]),ans=max(ans,tmp);
    cout<<ans<<endl;
    return 0;
}
