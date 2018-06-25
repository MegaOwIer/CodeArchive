#include<bits/stdc++.h>
using namespace std;

int M,N;
long long dp[17][105];

int main()
{
    scanf("%d%d",&M,&N);
    dp[0][0]=1;
    for(int i=1;i<=M;i++)dp[0][i]=2;
    for(int i=1;i<=N;i++)
    {
        dp[i][0]=1;
        for(int j=1;j<=M;j++)dp[i][j]=dp[i][j-1]+dp[i-1][j-1];
    }
    printf("%lld\n",dp[N][M]);
    return 0;
}
