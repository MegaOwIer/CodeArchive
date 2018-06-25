#include<bits/stdc++.h>
using namespace std;
const int MX=10005;

int T,N,M,a[MX],dp[MX],S,ans[52],cnt;

inline int read()
{
    int x=0,c=getchar();
    while(!isdigit(c))c=getchar();
    while(isdigit(c))x=x*10+c-'0',c=getchar();
    return x;
}

int main()
{
    T=read();
    while(T--)
    {
        N=read(),M=read(),S=0,cnt=0;
        for(int i=0;i<=M;i++)a[i]=read();
        memset(dp+1,0,sizeof(int)*M),dp[0]=1;
        for(int i=0;i<=M;i++)while(dp[i]<a[i])
        {
            ans[++cnt]=i;
            for(int j=S;j>=0;j--)dp[j+i]+=dp[j];
            S+=i;
        }
        for(int i=1;i<=N;i++)
            printf("%d%c",ans[i]," \n"[i==N]);
    }
    return 0;
}