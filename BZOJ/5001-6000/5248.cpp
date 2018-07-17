#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int MX=12,P=11,INF=2147483647;

int N,M,used[MX],A[MX][MX],B[MX][MX];
map<LL,int> dp;

inline int read()
{
    int x=0,c=getchar();
    while(!isdigit(c))c=getchar();
    while(isdigit(c))x=x*10+c-'0',c=getchar();
    return x;
}
inline int max(int a,int b){return a>b?a:b;}
inline int min(int a,int b){return a<b?a:b;}

int dfs(LL S)
{
    if(dp.count(S))return dp[S];
    int cnt=0,ans,(*cmp)(int,int),(*val)[MX];
    LL tmp=1;
    for(int i=1;i<=N;i++)cnt+=used[i];
    if(cnt==N*M)return 0;
    if(cnt&1)ans=INF,cmp=min,val=B;
    else ans=-INF,cmp=max,val=A;
    for(int i=1;i<=N;i++,tmp*=P)if(used[i]<M&&used[i]<used[i-1])
        ++used[i],ans=cmp(ans,val[i][used[i]]+dfs(S+tmp)),--used[i];
    return dp[S]=ans;
}

int main()
{
    N=read(),M=read();
    for(int i=1;i<=N;i++)for(int j=1;j<=M;j++)A[i][j]=read();
    for(int i=1;i<=N;i++)for(int j=1;j<=M;j++)B[i][j]=-read();
    used[0]=MX;
    cout<<dfs(0)<<endl;
    return 0;
}
