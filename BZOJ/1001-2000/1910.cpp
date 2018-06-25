#include<bits/stdc++.h>
using namespace std;
const int MX=203;

int N,M,s[MX][MX],dp[2][MX][MX][3],g[MX][MX][2],ans;

inline int read()
{
    int x=0,c=getchar();
    while(!isdigit(c))c=getchar();
    while(isdigit(c))x=x*10+c-'0',c=getchar();
    return x;
}

int main()
{
    N=read(),M=read();
    for(int i=1;i<=N;i++)for(int j=1;j<=M;j++)
        s[i][j]=s[i][j-1]+read();
    memset(dp[0],0xc0,sizeof(dp[0]));
    memset(g,0xc0,sizeof(g));
    for(int i=1,nw=1,j,k,x;i<=N;i++,nw^=1)
    {
        memset(dp[nw],0xc0,sizeof(dp[nw]));
        for(j=1;j<=M;j++)for(k=j;k<=M;k++)if(s[i][k]==s[i][j-1])
        {
            x=k-j+1;
            dp[nw][j][k][0]=max(dp[nw^1][j][k][0],0)+x;
            dp[nw][j][k][1]=max(dp[nw^1][j][k][1],g[j][k][0])+x;
            dp[nw][j][k][2]=max(dp[nw^1][j][k][2],g[j][k][1])+x;
            ans=max(ans,dp[nw][j][k][2]);
        }
        if(i==N)return printf("%d\n",ans),0;
        memset(g,0xc0,sizeof(g));
        for(j=2;j<M;j++)for(k=M-1;k>=j;k--)
            g[j][k][0]=max(max(g[j-1][k][0],g[j][k+1][0]),dp[nw][j-1][k+1][0]);
        for(j=M-2;j;j--)for(k=j+2;k<=M;k++)
            g[j][k][1]=max(max(g[j+1][k][1],g[j][k-1][1]),dp[nw][j+1][k-1][1]);
    }
}
