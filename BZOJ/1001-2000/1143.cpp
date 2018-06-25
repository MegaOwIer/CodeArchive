#include<bits/stdc++.h>
using namespace std;
const int MX=100;

int N,M,ans,linked[MX];
bitset<MX> G[MX];
char vis[MX];

inline int read()
{
    static int x,c;
    c=getchar(),x=0;
    while(!isdigit(c))c=getchar();
    while(isdigit(c))x=x*10+c-'0',c=getchar();
    return x;
}
int dfs(int u)
{
    for(int i=0;i<N;i++)if(G[u][i]&&!vis[i])
    {
        vis[i]=1;
        if(!~linked[i]||dfs(linked[i]))return linked[i]=u,1;
    }
    return 0;
}

int main()
{
    ans=N=read(),M=read();
    for(int i=1,u,v;i<=M;i++)
        u=read()-1,v=read()-1,G[u][v]=1;
    for(int i=0;i<N;i++)for(int j=0;j<N;j++)
        if(G[j][i])G[j]|=G[i];
    memset(linked,-1,sizeof(int)*N);
    for(int i=0;i<N;i++)
        memset(vis,0,sizeof(char)*N),ans-=dfs(i);
    printf("%d\n",ans);
    return 0;
}