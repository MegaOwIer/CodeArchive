#include<bits/stdc++.h>
using namespace std;
const int MX=2005;

int N,K,ans,dep[MX];
vector<int> G[MX];

inline int read()
{
    int x=0,c=getchar();
    while(!isdigit(c))c=getchar();
    while(isdigit(c))x=x*10+c-'0',c=getchar();
    return x;
}
int dfs(int u,int f)
{
    int ans=0;
    dep[u]=dep[f]+1;
    if(dep[u]==K/2+1)ans++;
    for(int i:G[u])if(i!=f)ans+=dfs(i,u);
    return ans;
}

int main()
{
    N=read(),K=read();
    for(int i=1,u,v;i<N;i++)
        u=read(),v=read(),G[u].push_back(v),G[v].push_back(u);
    for(int i=1;i<=N;i++)
    {
        int tmp=0;
        dep[i]=0;
        for(int j:G[i])tmp=max(tmp,dfs(j,i));
        sort(dep+1,dep+N+1);
        int siz=upper_bound(dep+1,dep+N+1,K/2)-dep-1;
        if(K&1)siz+=tmp;
        ans=max(ans,siz);
    }
    printf("%d\n",N-ans);
    return 0;
}
