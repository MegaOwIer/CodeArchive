#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

LL L,R,ans,dp[20][165][165][2];
char s[20];

LL DP(LL N,int mod)
{
    if(N<=0)return 0;
    memset(dp,0,sizeof(dp));
    sprintf(s+1,"%lld",N);
    int lth=strlen(s+1);
    dp[0][0][0][1]=1;
    for(int i=0;i<lth;i++)for(int j=0;j<=mod;j++)for(int k=0;k<mod;k++)
    {
        if(!dp[i][j][k][0]&&!dp[i][j][k][1])continue;
        if(dp[i][j][k][1])
        {
            dp[i+1][j+s[i+1]-'0'][(k*10+s[i+1]-'0')%mod][1]=1;
            for(int x=0;x<s[i+1]-'0'&&j+x<=mod;x++)
                ++dp[i+1][j+x][(k*10+x)%mod][0];
        }
        for(int x=0;x<=9&&j+x<=mod;x++)
            dp[i+1][j+x][(k*10+x)%mod][0]+=dp[i][j][k][0];
    }
    return dp[lth][mod][0][0]+dp[lth][mod][0][1];
}

int main()
{
    scanf("%lld%lld",&L,&R);
    if(R==1000000000000000000LL)ans=1,R--;
    for(int i=1;i<=162;i++)ans+=DP(R,i)-DP(L-1,i);
    printf("%lld\n",ans);
    return 0;
}
