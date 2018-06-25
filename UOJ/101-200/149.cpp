#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;

int n,m,k,dp[2][205][205][2],now;
char A[1005],B[205];

int main()
{
    scanf("%d%d%d%s%s",&n,&m,&k,A+1,B+1);
    dp[0][0][0][0]=dp[1][0][0][0]=1;
    for(int i=1;i<=n;i++)
    {
        now=i&1;
        for(int j=1;j<=m;j++)for(int l=1;l<=k;l++)
        {
            dp[now][j][l][0]=dp[now^1][j][l][0];
            dp[now][j][l][1]=0;
            if(A[i]==B[j])
            {
                dp[now][j][l][1]=(dp[now^1][j-1][l][1]+dp[now^1][j-1][l-1][0])%mod;
                dp[now][j][l][0]=(dp[now][j][l][0]+dp[now][j][l][1])%mod;
            }
        }
    }
    printf("%d",dp[n&1][m][k][0]);
    return 0;
}
