#include<bits/stdc++.h>
using namespace std;

using LL=long long;
const int mod=998244353;
const int MK=77,MX=4002;
#define endl "\n"

int N1,N2,K,res[2][MK],ans,fa[MX];
int s[MX][MK],f[MX][MK];
vector<int> G[MX];

void dfs1(int u,int f)
{
    fa[u]=f;
    int *cur=s[u];
    memset(cur,0,sizeof(int)*(K+1));
    cur[0]=1;
    for(int i:G[u])if(i!=f)dfs1(i,u);
    for(int j=2;j<=K;j+=2)for(int i:G[u])if(i!=f)
        for(int k=0;k<=j-2;k+=2)
            cur[j]=(cur[j]+(LL)cur[j-k-2]*s[i][k])%mod;
}
void dfs2(int u,int _f)
{
    for(int i:G[u])if(i!=_f)
        memset(f[i],0,sizeof(int)*(K+1)),f[i][0]=1;
    for(int k=2;k<=K;k+=2)
    {
        static int tmp[MK];
        memset(tmp,0,sizeof(int)*(K+1));
        for(int i=0;i<=k-2;i+=2)tmp[i]=(tmp[i]+f[u][i])%mod;
        for(int i:G[u])if(i!=_f)
            for(int j=0;j<=k-2;j+=2)tmp[j]=(tmp[j]+s[i][j])%mod;
        for(auto i:G[u])if(i!=_f)
        {
            int *cur=s[i];
            for(int j=0;j<=k-2;j+=2)tmp[j]=(tmp[j]+mod-cur[j])%mod;
            for(int j=0;j<=k-2;j+=2)
                f[i][k]=(f[i][k]+(LL)f[i][k-j-2]*tmp[j])%mod;
            for(int j=0;j<=k-2;j+=2)tmp[j]=(tmp[j]+cur[j])%mod;
        }
    }
    for(int i:G[u])if(i!=_f)dfs2(i,u);
}
void solve(int N,int *ans)
{
    for(int i=1;i<=N;i++)G[i].clear();
    for(int i=1,u,v;i<N;i++)
    {
        cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs1(1,0),dfs2(1,0);
    for(int i=1;i<=N;i++)
    {
        static int dp[MK];
        memset(dp,0,sizeof(int)*(K+1));
        dp[0]=1;
        for(int j=2;j<=K;j+=2)
        {
            for(int k=0;k<=j-2;k+=2)
                dp[j]=(dp[j]+(LL)f[i][k]*dp[j-k-2])%mod;
            for(int u:G[i])if(u!=fa[i])
                for(int k=0;k<=j-2;k+=2)
                    dp[j]=(dp[j]+(LL)s[u][k]*dp[j-k-2])%mod;
        }
        for(int j=0;j<=K;j+=2)ans[j]=(ans[j]+dp[j])%mod;
    }
}

int main()
{
    static int C[MK][MK];
    for(int i=0;i<=75;i++)C[i][0]=1;
    for(int i=1;i<=75;i++)for(int j=1;j<=i;j++)
        C[i][j]=(C[i-1][j]+C[i-1][j-1])%mod;
    ios::sync_with_stdio(0);
    cin>>N1>>N2>>K;
    solve(N1,res[0]),solve(N2,res[1]);
    for(int i=0;i<=K;i++)
        ans=(ans+(LL)C[K][i]*res[0][i]%mod*res[1][K-i])%mod;
    cout<<ans<<endl;
    return 0;
}
