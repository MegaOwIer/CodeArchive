#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

int n,m,e,v,c[2005],d[2005],g[305][305];
double k[2005],dp[2005][2005][2],ans=1e10;

int main()
{
    scanf("%d%d%d%d",&n,&m,&v,&e);
    memset(g,1,sizeof(g));
    for(int i=1;i<=n;i++)  g[i][i]=0;
    for(int i=1;i<=n;i++)  scanf("%d",c+i);
    for(int i=1;i<=n;i++)  scanf("%d",d+i);
    for(int i=1;i<=n;i++)  scanf("%lf",k+i);
    for(int i=1,a,b,w;i<=e;i++)  {scanf("%d%d%d",&a,&b,&w);  g[a][b]=g[b][a]=min(g[a][b],w);}
    for(int k=1;k<=v;k++)  for(int i=1;i<=v;i++)  for(int j=1;j<=v;j++)
    {
        if(i==j||i==k||j==k)  continue;
        g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
    }
    for(int i=1;i<=n;i++)  for(int j=0;j<=m;j++)  dp[i][j][1]=dp[i][j][0]=1e10;
    dp[1][0][0]=dp[1][1][1]=0;
    for(int i=2;i<=n;i++)  for(int j=0;j<=m;j++)
    {
        if(j>i)  break;
        dp[i][j][0]=min(dp[i-1][j][0]+g[c[i-1]][c[i]],dp[i-1][j][1]+g[d[i-1]][c[i]]*k[i-1]+g[c[i-1]][c[i]]*(1.0-k[i-1]));
        if(j) dp[i][j][1]=min(dp[i-1][j-1][0]+g[c[i-1]][d[i]]*k[i]+g[c[i-1]][c[i]]*(1.0-k[i]),dp[i-1][j-1][1]+g[d[i-1]][d[i]]*k[i-1]*k[i]+g[d[i-1]][c[i]]*k[i-1]*(1.0-k[i])+g[c[i-1]][d[i]]*(1.0-k[i-1])*k[i]+g[c[i-1]][c[i]]*(1.0-k[i-1])*(1.0-k[i]));
    }
    for(int i=0;i<=m;i++)  ans=min(ans,min(dp[n][i][0],dp[n][i][1]));
    printf("%.2lf",ans);
    return 0;
}
