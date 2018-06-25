#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MX=102;

int N,M,dis[MX][MX];
double ans[MX];
LL w[MX][MX];

inline int read()
{
    int x=0,c=getchar();
    while(!isdigit(c))c=getchar();
    while(isdigit(c))x=x*10+c-'0',c=getchar();
    return x;
}

int main()
{
    N=read(),M=read();
    memset(dis,0x3f,sizeof(dis));
    for(int i=1;i<=N;i++)dis[i][i]=0;
    for(int i=1,u,v;i<=M;i++)
    {
        u=read(),v=read();
        dis[u][v]=dis[v][u]=read();
        w[u][v]=w[v][u]=1;
    }
    for(int k=1;k<=N;k++)for(int i=1;i<=N;i++)for(int j=1;j<=N;j++)
        if(dis[i][k]+dis[k][j]<dis[i][j])
            dis[i][j]=dis[i][k]+dis[k][j],w[i][j]=w[i][k]*w[k][j];
        else if(dis[i][k]+dis[k][j]==dis[i][j])
            w[i][j]+=w[i][k]*w[k][j];
    for(int k=1;k<=N;k++)for(int i=1;i<=N;i++)if(i!=k)
        for(int j=1;j<=N;j++)if(i!=j&&j!=k)
            if(dis[i][k]+dis[k][j]==dis[i][j]&&w[i][j])
                ans[k]+=(double)w[i][k]*w[k][j]/w[i][j];
    for(int i=1;i<=N;i++)printf("%.3lf\n",ans[i]);
    return 0;
}