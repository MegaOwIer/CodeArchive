#include<bits/stdc++.h>
using namespace std;
const int MX=505;

int N,K,link[MX];
char vis[MX];
vector<int> G[MX];

inline int read()
{
    int x=0,c=getchar();
    while(!isdigit(c))c=getchar();
    while(isdigit(c))x=x*10+c-'0',c=getchar();
    return x;
}
bool find(int u)
{
    for(auto i:G[u])if(!vis[i])
    {
        vis[i]=1;
        if(!link[i]||find(link[i]))
            return link[i]=u,true;
    }
    return false;
}
bool Hungray()
{
    memset(link+1,0,sizeof(int)*N);
    for(int i=1;i<=N;i++)
    {
        memset(vis+1,0,sizeof(char)*N);
        if(!find(i))return false;
    }
    return true;
}

int main()
{
    for(int T=read();T--;)
    {
        N=read(),K=read();
        for(int i=1;i<=N;i++)G[i].clear();
        for(int i=2,u;i<=N;i++)
            u=read(),G[u].push_back(i),G[i].push_back(u);
        puts((~N&1)&&(N-1-N/2)<=K&&Hungray()?"Bob":"Alice");
    }
    return 0;
}