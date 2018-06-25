#include<bits/stdc++.h>
using namespace std;
const int MX=100005;

int N,col[MX<<1],tot;
pair<int,int> pos[MX<<1];
vector<int> G[MX<<1];
bool vis[MX<<1];

inline int read()
{
    int x=0,c=getchar();
    while(!isdigit(c))c=getchar();
    while(isdigit(c))x=x*10+c-'0',c=getchar();
    return x;
}
inline void add(int u,int v){G[u].push_back(v),G[v].push_back(u);}
void dfs(int u,int c)
{
    vis[u]=1,col[u]=c;
    for(int i:G[u])if(!vis[i])dfs(i,c^1);
}

int main()
{
    N=read();
    for(int i=1,l,r;i<=N;i++)
    {
        l=read(),r=read()+1;
        add(i*2-1,i*2);
        ++tot,pos[tot]=make_pair(l,tot);
        ++tot,pos[tot]=make_pair(r,tot);
    }
    sort(pos+1,pos+tot+1);
    for(int i=1;i<=tot;i+=2)add(pos[i].second,pos[i+1].second);
    for(int i=1;i<=tot;i++)if(!vis[i])dfs(i,0);
    for(int i=1;i<=tot;i+=2)printf("%d ",col[i]);
    return 0;
}
