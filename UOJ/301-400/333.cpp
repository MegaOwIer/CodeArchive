#include<bits/stdc++.h>
using namespace std;

const int INF=0x3f3f3f3f,MX=12,MS=1<<12|1;

int N,M,G[MX][MX],S,ans=INF;
int dp[MX+5][MS],dis[MS][MX];

inline void update(int &a,int b){a=min(a,b);}
int f(int S,int T)
{
    int ans=0;
    for(int i=0;i<N;i++)if(T>>i&1)
    {
        if(dis[S][i]==INF)return INF;
        ans+=dis[S][i];
    }
    return ans;
}

int main()
{
    memset(G,0x3f,sizeof(G));
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>N>>M;
    S=1<<N;
    for(int i=0;i<N;i++)G[i][i]=0;
    while(M--)
    {
        int a,b,c;
        cin>>a>>b>>c;
        --a,--b;
        G[a][b]=G[b][a]=min(G[a][b],c);
    }
    for(int i=0;i<S;i++)for(int j=0;j<N;j++)
        if(i>>j&1)continue;
        else
        {
            int &cur=dis[i][j];
            cur=INF;
            for(int k=0;k<N;k++)if(i>>k&1)cur=min(cur,G[j][k]);
        }
    memset(dp[1],0x3f,sizeof(int[S]));
    for(int i=0;i<N;i++)dp[1][1<<i]=0;
    for(int d=1;d<N;d++)
    {
        memset(dp[d+1],0x3f,sizeof(int[S]));
        for(int i=0;i<S;i++)if(dp[d][i]!=INF)
        {
            int T=(S-1)^i,cur=dp[d][i];
            for(int j=T;j;j=(j-1)&T)
            {
                int tmp=f(i,j);
                if(tmp!=INF)update(dp[d+1][i|j],cur+tmp*d);
            }
        }
    }
    for(int i=1;i<=N;i++)ans=min(ans,dp[i][S-1]);
    cout<<ans<<endl;
    return 0;
}
