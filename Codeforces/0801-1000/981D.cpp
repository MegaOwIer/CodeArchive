#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const int MX=55;

int N,K;
bool dp[MX][MX],tmp[MX][MX];
LL a[MX],ans;

inline int check(LL a,LL S,int T){return S==(S&((a>>T)<<T));}
inline int getdig(LL a,int T){return (a>>T)&1;}

int main()
{
    ios::sync_with_stdio(0);
    cin>>N>>K;
    for(int i=1;i<=N;i++)cin>>a[i],a[i]+=a[i-1];
    for(int i=1;i<=N;i++)for(int j=1;j<=i;j++)dp[i][j]=1;
    for(int T=60;~T;T--)
    {
        memcpy(tmp,dp,sizeof(dp));
        dp[0][0]=1;
        for(int i=1;i<=N;i++)for(int j=1;j<=i;j++)if(dp[i][j])
        {
            dp[i][j]=0;
            for(int k=0;k<i;k++)
                if(dp[k][j-1]&&check(a[i]-a[k],ans,T)&&getdig(a[i]-a[k],T))
                    {dp[i][j]=1;break;}
        }
        if(dp[N][K])ans|=1LL<<T;
        else memcpy(dp,tmp,sizeof(dp));
    }
    cout<<ans<<endl;
    return 0;
}

