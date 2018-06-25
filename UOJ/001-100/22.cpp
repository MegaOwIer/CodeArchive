#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MX=1005,mod=998244353;

int N,x,a[MX],dp[2][MX*5];

int main()
{
    ios::sync_with_stdio(false);
    cin>>N>>x;
    for(int i=1;i<=N;i++)cin>>a[i];
    sort(a+1,a+N+1,greater<int>());
    dp[0][x]=1;
    for(int I=1,i=1;I<=N;I++,i^=1)
    {
        memset(dp[i],0,sizeof(int)*(x+1));
        for(int j=0;j<=x;j++)if(dp[i^1][j])
        {
            dp[i][j%a[I]]=(dp[i][j%a[I]]+dp[i^1][j])%mod;
            dp[i][j]=(dp[i][j]+1LL*(N-I)*dp[i^1][j])%mod;
        }
    }
    for(int i=x;;i--)if(dp[N&1][i])return printf("%d\n%d\n",i,dp[N&1][i]),0;
    return 0;
}