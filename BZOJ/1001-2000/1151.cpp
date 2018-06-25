#include<bits/stdc++.h>
using namespace std;
const int MX=10005,pw2[]={1,2,4,8,16};

int N,M,f[MX][32],ans,dp[MX][32];

inline int read()
{
    int x,c;
    x=0,c=getchar();
    while(!isdigit(c))c=getchar();
    while(isdigit(c))x=x*10+c-'0',c=getchar();
    return x;
}

int main()
{
    N=read(),M=read();
    for(int i=1,j,k,x,y,pos;i<=M;i++)
    {
        pos=read(),j=read(),k=read(),x=y=0;
        while(j--)x|=pw2[(read()-pos+N)%N];
        while(k--)y|=pw2[(read()-pos+N)%N];
        for(int s=0;s<32;s++)if((s&x)||(31^s)&y)
            f[pos][s]++;
    }
    for(int i=0;i<16;i++)
    {
        memset(dp[0],0xc8,sizeof(dp[0]));
        dp[0][i<<1]=0;
        for(int j=1;j<=N;j++)for(int k=0;k<32;k++)
            dp[j][k]=max(dp[j-1][(k&15)<<1],dp[j-1][(k&15)<<1|1])+f[j][k];
        ans=max(ans,max(dp[N][i<<1],dp[N][i<<1|1]));
    }
    printf("%d\n",ans);
    return 0;
}