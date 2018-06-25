#include<cstdio>
#include<algorithm>
using namespace std;

int n,m,g[105],sta[62],cnt,num[62],dp[105][62][62],ans;
char c;

inline int cal(int u)
{
    int ans=0;
    for(;u;ans+=u&1,u>>=1);
    return ans;
}
void init()
{
    for(int i=0;i<(1<<m);i++)
    {
        if((i&(i<<1))||(i&(i<<2))||(i&(i>>1))||(i&(i>>1)))  continue;
        sta[++cnt]=i;
        num[cnt]=cal(i);
    }
}

int main()
{
    scanf("%d%d",&n,&m);  getchar();
    init();
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
			g[i]<<=1;
            c=getchar();
            if(c=='H')  g[i]|=1;
        }
        getchar();
    }
    for(int i=1;i<=cnt;i++)  if((sta[i]&g[1])==0)  dp[1][i][1]=num[i];
    for(int i=2;i<=n;i++)  for(int j=1;j<=cnt;j++)  if(0==(sta[j]&g[i]))
    {
        for(int k=1;k<=cnt;k++)  if((sta[k]&sta[j])==0&&(g[i-1]&sta[k])==0)
        {
            for(int x=1;x<=cnt;x++)  if((sta[x]&g[i-2])==0&&(sta[k]&sta[x])==0&&(sta[x]&sta[j])==0)
                dp[i][j][k]=max(dp[i][j][k],dp[i-1][k][x]);
            dp[i][j][k]+=num[j];
        }
    }
    for(int i=1;i<=cnt;i++)  for(int j=1;j<=cnt;j++)  ans=max(ans,dp[n][i][j]);
    printf("%d",ans);
    return 0;
}
