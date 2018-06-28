#include<bits/stdc++.h>
using namespace std;

using LL=long long;
const int MX=3003,mod=1000000007;
#define endl "\n"

int N,D,dp[MX][MX];
vector<int> G[MX];

int Inv(int u)
{
    if(u==1)return 1;
    if(u<0)return mod-Inv(-u);
    return LL(mod-mod/u)*Inv(mod%u)%mod;
}

void dfs(int u)
{
    for(int i=0;i<=N;i++)dp[u][i]=1;
    for(int i:G[u])
    {
        dfs(i);
        for(int j=0,tmp=0;j<=N;j++)
        {
            tmp=(tmp+dp[i][j])%mod;
            dp[u][j]=(LL)dp[u][j]*tmp%mod;
        }
    }
}
int Largrange(int x)
{
    int *y=dp[1],ans=0,tmp=1;
    for(int i=1;i<=N;i++)y[i]=(y[i]+y[i-1])%mod;
    if(x<=N)return dp[1][x];
    static int fac[MX],inv[MX];
    fac[0]=1;
    for(int i=1;i<=N;i++)fac[i]=(LL)fac[i-1]*i%mod;
    inv[N]=Inv(fac[N]);
    for(int i=N;i;i--)inv[i-1]=(LL)inv[i]*i%mod;
    for(int i=0;i<=N;i++)tmp=LL(x-i)*tmp%mod;
    for(int i=0;i<=N;i++)
        ans=(ans+(LL)y[i]*inv[i]%mod*((N-i)&1?mod-inv[N-i]:inv[N-i])%mod*tmp%mod*Inv(x-i))%mod;
    return ans;
}

int main()
{
    ios::sync_with_stdio(0);
    cin>>N>>D;
    for(int i=2,x;i<=N;i++)
        cin>>x,G[x].push_back(i);
    dfs(1);
    cout<<Largrange(D-1)<<endl;
    return 0;
}