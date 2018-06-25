#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;

struct edge {int to,next,w;}s[800];
int k,n,m,e,head[25],tot,d,used[25][105],t[105][105],dis[25],use[25],dp[105];
bool inq[25];
queue<int> q;

void add(int u,int v,int w)
{
    s[++tot]=(edge){v,head[u],w},head[u]=tot;
    s[++tot]=(edge){u,head[v],w},head[v]=tot;
}
void spfa(int u,int v)
{
    for(int i=2;i<=m;i++)  dis[i]=1<<20;  q.push(1);
    for(int i=1;i<=m;i++)
    {
        use[i]=1;
        for(int j=u;j<=v;j++)  if(used[i][j])  {use[i]=0;  break;}
    }
    while(!q.empty())
    {
        int now=q.front();  q.pop();  inq[now]=0;
        for(int i=head[now];i;i=s[i].next)  
        if(use[s[i].to])
        {
            int dist=dis[now]+s[i].w;
            if(dis[s[i].to]>dist)
            {
                dis[s[i].to]=dist;
                if(!inq[s[i].to])  {inq[s[i].to]=1;  q.push(s[i].to);}
            }
        }
    }
    t[u][v]=dis[m];
}

int main()
{
    scanf("%d%d%d%d",&n,&m,&k,&e);
    for(int i=1,a,b,c;i<=e;i++)  {scanf("%d%d%d",&a,&b,&c);  add(a,b,c);}
    scanf("%d",&d);
    for(int i=1,a,b,c;i<=d;i++)
    {
        scanf("%d%d%d",&a,&b,&c);
        for(int j=b;j<=c;j++)  used[a][j]=1;
    }
    for(int i=1;i<=n;i++)  for(int j=i;j<=n;j++)  spfa(i,j);
    for(int i=1;i<=n;i++)
    {
        dp[i]=t[1][i]*i;
        for(int j=1;j<i;j++)  dp[i]=min(dp[i],dp[j]+t[j+1][i]*(i-j)+k);
    }
    printf("%d",dp[n]);
    return 0;
}
