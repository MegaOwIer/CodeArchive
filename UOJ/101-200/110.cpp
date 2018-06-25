#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const int MX=2005;

int N,A,B;
LL a[MX],ans;

inline bool check(LL a,LL S,int T){return S==(S|((a>>T)<<T));}
void Solve1()
{
    bool dp[105][105],tmp[105][105];
    for(int i=1;i<=N;i++)for(int j=i;j<=N;j++)dp[i][j]=true;
    for(int T=40;~T;T--)
    {
        memcpy(tmp,dp,sizeof(dp));
        for(int i=1;i<=N;i++)dp[1][i]&=check(a[i],ans,T);
        for(int i=2;i<=N;i++)for(int j=i;j<=N;j++)
        {
            bool flag=false;
            for(int k=i-1;k<j;k++)
                flag|=dp[i-1][k]&&check(a[j]-a[k],ans,T);
            dp[i][j]&=flag;
        }
        bool flag=false;
        for(int i=A;i<=B;i++)flag|=dp[i][N];
        if(!flag)memcpy(dp,tmp,sizeof(dp)),ans|=1LL<<T;
    }
}
void Solve2()
{
    int dp[MX];
    dp[0]=0;
    for(int T=40;~T;T--)
    {
        memset(dp+1,0x3f,sizeof(int)*N);
        for(int i=1;i<=N;i++)for(int j=0;j<i;j++)
            if(check(a[i]-a[j],ans,T))dp[i]=min(dp[i],dp[j]+1);
        if(dp[N]>B)ans|=1LL<<T;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin>>N>>A>>B;
    for(int i=1;i<=N;i++)cin>>a[i];
    for(int i=2;i<=N;i++)a[i]+=a[i-1];
    if(N<=100)Solve1();
    else Solve2();
    printf("%lld\n",ans);
    return 0;
}