#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MX=33;

int N,p[3][MX],x[7],y[7];
LL dp[3][MX];
char s[4];

int main()
{
    ios::sync_with_stdio(0);
    cin>>N;
    for(int i=0;i<6;i++)cin>>(s+1),x[i]=s[1]-'A',y[i]=s[2]-'A';
    for(int i=5;~i;i--)p[x[i]][1]=y[i];
    dp[0][1]=dp[1][1]=dp[2][1]=1;
    for(int i=2;i<=N;i++)for(int a=0,b,c;a<3;a++)
    {
        b=p[a][i-1],c=3-a-b;
        if(p[b][i-1]==c)dp[a][i]=dp[a][i-1]+1+dp[b][i-1],p[a][i]=c;
        else if(p[b][i-1]==a)dp[a][i]=dp[a][i-1]+1+dp[b][i-1]+1+dp[a][i-1],p[a][i]=b;
    }
    printf("%lld\n",dp[0][N]);
    return 0;
}