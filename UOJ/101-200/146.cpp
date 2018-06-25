#include<bits/stdc++.h>
using namespace std;
const int maxn=200005;

int n,to[maxn],dep[maxn],ans=maxn,ord[maxn],cnt;
char c;
bool vis[maxn];

inline void read(int& x)
{
    x=0,c=getchar();
    while(!isdigit(c))c=getchar();
    while(isdigit(c))x=x*10+c-48,c=getchar();
}
inline void dfs(int u,int d)
{
    vis[u]=1,dep[u]=d,ord[u]=++cnt;
    if(!vis[to[u]])dfs(to[u],d+1);
    else if(ord[u]-ord[to[u]]<=d)ans=min(ans,dep[u]-dep[to[u]]);
}

int main()
{
    read(n);
    for(int i=1;i<=n;i++)read(to[i]);
    for(int i=1;i<=n;i++)dfs(i,0);
    printf("%d",ans+1);
    return 0;
}
