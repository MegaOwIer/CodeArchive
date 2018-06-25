#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MX=200005;

int N,cnt,vis[MX],col[MX],siz[MX],m[MX];
LL ans;
vector<int> G[MX];

inline int read()
{
    int x=0,c=getchar();
    while(!isdigit(c))c=getchar();
    while(isdigit(c))x=x*10+c-'0',c=getchar();
    return x;
}
void dfs(int u,int f)
{
    int cnt=0,tmp,p;
    siz[u]=1;
    for(vector<int>::iterator it=G[u].begin();it!=G[u].end();++it)if(*it!=f)
    {
        tmp=m[col[u]];
        dfs(*it,u);
        siz[u]+=siz[*it];
        cnt+=(p=m[col[u]]-tmp);
        ans-=LL(siz[*it]-p)*(siz[*it]-p-1)/2;
    }
    m[col[u]]+=siz[u]-cnt;
}

int main()
{
    for(int cas=1;~scanf("%d",&N);cas++)
    {
        cnt=0;
        memset(m,0,sizeof(m));
        for(int i=1;i<=N;i++)G[i].clear();
        for(int i=1;i<=N;i++)
        {
            col[i]=read();
            if(vis[col[i]]!=cas)cnt++,vis[col[i]]=cas;
        }
        ans=LL(N-1)*N/2*cnt;
        for(int i=1,u,v;i<N;i++)
        {
            u=read(),v=read();
            G[u].push_back(v);
            G[v].push_back(u);
        }
        dfs(1,-1);
        for(int i=1;i<=N;i++)if(vis[i]==cas)
            ans-=LL(N-m[i])*(N-m[i]-1)/2;
        printf("Case #%d: %lld\n",cas,ans);
    }
    return 0;
}