#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MX=12,INF=2000000000;

int N,M,a[MX][MX],b[MX][MX],used[MX];
LL pw[MX];
map<LL,int> dp;

inline int read()
{
    static int x,c;
    x=0,c=getchar();
    while(!isdigit(c))c=getchar();
    while(isdigit(c))x=x*10+c-'0',c=getchar();
    return x;
}
int dfs(LL S,int sgn)
{
    if(dp.count(S))return dp[S];
    int ans;
    if(sgn)
    {
        ans=-INF;
        for(int i=1;i<=N;i++)if(used[i]<used[i-1]&&used[i]<M)
            ++used[i],ans=max(ans,dfs(S+pw[i-1],sgn^1)+a[i][used[i]]),--used[i];
    }
    else
    {
        ans=INF;
        for(int i=1;i<=N;i++)if(used[i]<used[i-1]&&used[i]<M)
            ++used[i],ans=min(ans,dfs(S+pw[i-1],sgn^1)-b[i][used[i]]),--used[i];
    }
    return dp[S]=ans;
}

int main()
{
    N=read(),M=read(),pw[0]=1;
    for(int i=1;i<=N;i++)pw[i]=pw[i-1]*(M+1);
    for(int i=1;i<=N;i++)for(int j=1;j<=M;j++)a[i][j]=read();
    for(int i=1;i<=N;i++)for(int j=1;j<=M;j++)b[i][j]=read();
    used[0]=M,dp[pw[N]-1]=0;
    printf("%d\n",dfs(0,1));
    return 0;
}