#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const int MX=1000005;

int N,K,c[MX];
LL s[MX],dp[MX],mx[MX];

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
    N=read(),K=read();
    memset(mx+1,0x80,sizeof(LL)*K);
    for(int i=1;i<=N;i++)c[i]=read();
    for(int i=1;i<=N;i++)s[i]=s[i-1]+read();
    for(int i=1;i<=N;i++)
    {
        dp[i]=max(dp[i-1],s[i]+mx[c[i]]);
        mx[c[i]]=max(mx[c[i]],dp[i-1]-s[i-1]);
    }
    cout<<dp[N]<<endl;
    return 0;
}
