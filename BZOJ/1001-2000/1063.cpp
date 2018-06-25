#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MX=100005;

int N,Q,M,fa[MX],dp[MX][20][3];
vector<int> G[MX];

inline int read()
{
    static int c,x;
    x=0,c=getchar();
    while(!isdigit(c))c=getchar();
    while(isdigit(c))x=x*10+c-'0',c=getchar();
    return x;
}
int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
inline int calc(LL x){return x?(x-1)%Q+1:0;}
int dfs(int u,int lim,int f)
{
    static LL t1,t2;
    dp[u][lim][0]=1;
    for(vector<int>::iterator it=G[u].begin();it!=G[u].end();++it)if(f!=*it)
    {
        int v=*it;
        dfs(v,lim,u);
        t1=lim?calc(dp[v][lim-1][0]+dp[v][lim-1][1]+dp[v][lim-1][2]):0;
        t2=calc(dp[v][lim][0]+dp[v][lim][1]);
        dp[u][lim][2]=calc(dp[u][lim][2]*t1+dp[u][lim][1]*t2);
        dp[u][lim][1]=calc(dp[u][lim][1]*t1+dp[u][lim][0]*t2);
        dp[u][lim][0]=calc(dp[u][lim][0]*t1);
    }
}

int main()
{
    N=read(),M=read(),Q=read();
    for(int i=1;i<=N;i++)fa[i]=i;
    for(int i=1,u,v;i<=M;i++)
    {
        u=read(),v=read();
        G[u].push_back(v),G[v].push_back(u);
        if(find(u)==find(v))continue;
        fa[fa[u]]=fa[v];
    }
    for(int i=1,cnt=0;i<=N;i++)
    {
        if(i==fa[i])cnt++;
        if(cnt>1)puts("-1\n-1"),exit(0);
    }
    for(int i=0,tmp;;i++)
    {
        dfs(1,i,0);
        tmp=dp[1][i][0]+dp[1][i][1]+dp[1][i][2];
        if(tmp)printf("%d\n%d\n",i,tmp%Q),exit(0);
    }
}