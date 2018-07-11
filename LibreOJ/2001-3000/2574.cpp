#include<bits/stdc++.h>
using namespace std;

const int MX=503;

int M,N,val[MX],ls[MX],tot,lft[MX];
char vis[MX];
bitset<MX> G[MX];

inline int read()
{
    int x=0,c=getchar();
    while(!isdigit(c))c=getchar();
    while(isdigit(c))x=x*10+c-'0',c=getchar();
    return x;
}
bool dfs(int u,int v)
{
    for(int i=1;i<=N;i++)
        if(!vis[i]&&G[u][i]&&u!=i&&val[i]<v)
        {
            vis[i]=1;
            if(!lft[i]||dfs(lft[i],v))return lft[i]=u,true;
        }
    return false;
}
bool check(int v)
{
    int cnt=0;
    for(int i=1;i<=N;i++)if(val[i]<v)cnt++;
    memset(lft+1,0,sizeof(int)*N);
    for(int i=1;i<=N;i++)if(val[i]<v)
    {
        memset(vis+1,0,sizeof(char)*N);
        if(dfs(i,v))cnt--;
    }
    return cnt<=M+1;
}

int main()
{
    M=read(),N=read();
    for(int i=1;i<=N;i++)
    {
        val[i]=ls[i]=read();
        for(int k=read();k--;)G[i].set(read());
    }
    sort(ls+1,ls+N+1),tot=unique(ls+1,ls+N+1)-ls-1;
    for(int i=1;i<=N;i++)val[i]=lower_bound(ls+1,ls+tot+1,val[i])-ls;
    for(int k=1;k<=N;k++)for(int i=1;i<=N;i++)if(G[i][k])G[i]|=G[k];
    if(check(tot+1))return puts("AK"),0;
    int L=1,R=tot,ans;
    while(L<=R)
    {
        int mid=L+R>>1;
        if(check(mid))L=mid+1,ans=mid;
        else R=mid-1;
    }
    printf("%d\n",val[ans]);
    return 0;
}
