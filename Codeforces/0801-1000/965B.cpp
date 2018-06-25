#include<bits/stdc++.h>
using namespace std;
const int MX=103;

int N,K,ans[MX][MX],a[MX],b[MX],x=1,y=1;
char s[MX][MX];

int main()
{
    ios::sync_with_stdio(0);
    cin>>N>>K;
    for(int i=1;i<=N;i++)cin>>(s[i]+1);
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=N;j++)a[j]=(s[i][j]=='.'?a[j-1]+1:0);
        for(int j=N;j>=1;j--)b[j]=(s[i][j]=='.'?b[j+1]+1:0);
        for(int j=1;j<=N;j++)
            ans[i][j]+=max(min(j,j+b[j]-K)-max(j-a[j]+1,j-K+1)+1,0);
    }
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=N;j++)a[j]=(s[j][i]=='.'?a[j-1]+1:0);
        for(int j=N;j>=1;j--)b[j]=(s[j][i]=='.'?b[j+1]+1:0);
        for(int j=1;j<=N;j++)
            ans[j][i]+=max(min(j,j+b[j]-K)-max(j-a[j]+1,j-K+1)+1,0);
    }
    for(int i=1;i<=N;i++)for(int j=1;j<=N;j++)
        if(ans[i][j]>ans[x][y])x=i,y=j;
    cout<<x<<' '<<y<<endl;
    return 0;
}
