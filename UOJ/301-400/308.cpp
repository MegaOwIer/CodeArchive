#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int mod=6,MX=100005;

int N,M,K,col[MX];
vector<int> G[MX];

inline int read()
{
    int x=0,c=getchar();
    while(!isdigit(c))c=getchar();
    while(isdigit(c))x=x*10+c-'0',c=getchar();
    return x;
}
inline int Pow(int a,int b)
{
    int ans=1;
    a%=mod;
    for(;b;b>>=1,a=a*a%mod)
        if(b&1)ans=ans*a%mod;
    return ans;
}

bool dfs(int u,int c)
{
    col[u]=c;
    for(int i:G[u])
        if(col[i]==col[u])return false;
        else if(!~col[i]&&!dfs(i,c^1))return false;
    return true;
}
int solve()
{
    int cnt=0;
    for(int i=1;i<=N;i++)if(!~col[i])
    {
        if(!dfs(i,0))return 0;
        cnt++;
    }
    return Pow(2,cnt);
}

int main()
{
    for(int T=read();T--;)
    {
        N=read(),M=read(),K=read();
        if(!M)
        {
            printf("%d\n",Pow(K,N));
            continue;
        }
        for(int i=1;i<=N;i++)G[i].clear();
        memset(col+1,-1,sizeof(int)*N);
        for(int i=1,u,v;i<=M;i++)
        {
            u=read(),v=read();
            G[u].push_back(v);
            G[v].push_back(u);
        }
        printf("%d\n",solve()*K*LL(K-1)/2%mod);
    }
    return 0;
}
