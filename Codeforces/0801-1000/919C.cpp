#include<bits/stdc++.h>
using namespace std;
const int MX=2005;

int n,m,k,cnt,ans;
char g[MX][MX];

int main()
{
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=n;i++)
    {
        scanf("%s",g[i]+1);
        g[i][m+1]='*';
    }
    m++;
    for(int i=1;i<=m;i++)g[n+1][i]='*';
    n++;
    for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)
    {
        if(g[i][j]=='*')
            ans+=max(0,cnt-k+1),cnt=0;
        else cnt++;
    }
    for(int i=1;i<=m;i++)for(int j=1;j<=n;j++)
        if(g[j][i]=='*')
            ans+=max(0,cnt-k+1),cnt=0;
        else cnt++;
    if(k==1)ans/=2;
    cout<<ans<<endl;
    return 0;
}