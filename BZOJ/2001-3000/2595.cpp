#include<bits/stdc++.h>
using namespace std;
const int INF=0x3f3f3f3f,dx[]={1,0,-1,0},dy[]={0,1,0,-1},MX=15;

int N,M,dp[MX][MX][1<<10|3],a[MX][MX],cnt,S,x,y,ans=INF;
char vis[MX][MX];

struct Data
{
    int x,y,sta;
    Data(){}
    Data(int x,int y,int s):x(x),y(y),sta(s){}
}pre[MX][MX][1<<10|3];

inline int read()
{
    int x=0,c=getchar();
    while(!isdigit(c))c=getchar();
    while(isdigit(c))x=x*10+c-'0',c=getchar();
    return x;
}
void SPFA(int sta)
{
    typedef pair<int,int> pii;
    queue<pii> q;
    for(int i=1;i<=N;i++)for(int j=1;j<=M;j++)
        if(dp[i][j][sta]!=INF)q.push(make_pair(i,j));
    memset(vis,0,sizeof(vis));
    while(!q.empty())
    {
        pii nw=q.front();
        int x=nw.first,y=nw.second;
        q.pop(),vis[x][y]=0;
        for(int i=0;i<4;i++)
        {
            int nx=x+dx[i],ny=y+dy[i];
            if(!nx||!ny||x>N||y>M)continue;
            if(dp[nx][ny][sta]>dp[x][y][sta]+a[nx][ny])
            {
                dp[nx][ny][sta]=dp[x][y][sta]+a[nx][ny];
                pre[nx][ny][sta]=Data(x,y,sta);
                if(!vis[nx][ny])vis[nx][ny]=1,q.push(make_pair(nx,ny));
            }
        }
    }
}
void dfs(int x,int y,int sta)
{
    if(a[x][y])a[x][y]=-1;
    if(pre[x][y][sta].x)
    {
        dfs(pre[x][y][sta].x,pre[x][y][sta].y,pre[x][y][sta].sta);
        if(pre[x][y][sta].x==x&&pre[x][y][sta].y==y)
            dfs(x,y,sta^pre[x][y][sta].sta);
    }
}

int main()
{
    N=read(),M=read();
    memset(dp,0x3f,sizeof(dp));
    for(int i=1;i<=N;i++)for(int j=1;j<=M;j++)
        if(!(a[i][j]=read()))dp[i][j][1<<(cnt++)]=0;
    S=(1<<cnt)-1;
    for(int k=0,tmp;k<=S;k++)
    {
        for(int i=1;i<=N;i++)for(int j=1;j<=M;j++)for(int s=(k-1)&k;s;s=(s-1)&k)
            if(dp[i][j][k]>(tmp=dp[i][j][s]+dp[i][j][s^k]-a[i][j]))
            {
                dp[i][j][k]=tmp;
                pre[i][j][k]=Data(i,j,s);
            }
        SPFA(k);
    }
    for(int i=1;i<=N;i++)for(int j=1;j<=M;j++)
        if(ans>dp[i][j][S])ans=dp[i][j][S],x=i,y=j;
    dfs(x,y,S);
    printf("%d\n",ans);
    for(int i=1;i<=N;i++,putchar('\n'))for(int j=1;j<=M;j++)
        if(a[i][j]==-1)putchar('o');
        else if(!a[i][j])putchar('x');
        else putchar('_');
    return 0;
}
