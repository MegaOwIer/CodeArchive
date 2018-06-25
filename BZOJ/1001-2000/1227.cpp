#include<bits/stdc++.h>
using namespace std;
const int MX=100005;

int N,M,W,K,ls[MX],cnt,sum[MX];
unsigned C[MX][12],ans,tr[MX];

struct Point
{
    int x,y,l,r,u,d;
    bool operator < (const Point& a)const
        {return x==a.x?y<a.y:x<a.x;}
}P[MX];

inline int read()
{
    int x=0,c=getchar();
    while(!isdigit(c))c=getchar();
    while(isdigit(c))x=x*10+c-'0',c=getchar();
    return x;
}
void add(int u,unsigned v){for(;u<=W;u+=u&-u)tr[u]+=v;}
unsigned query(int u){unsigned ans=0;for(;u;u-=u&-u)ans+=tr[u];return ans;}

int main()
{
    N=read(),M=read(),W=read();
    for(int i=1;i<=W;i++)P[i].x=read(),P[i].y=read();
    for(int i=1;i<=W;i++)ls[i]=P[i].x;
    sort(ls+1,ls+W+1),cnt=unique(ls+1,ls+W+1)-ls-1;
    for(int i=1;i<=W;i++)P[i].x=lower_bound(ls+1,ls+cnt+1,P[i].x)-ls;
    for(int i=1;i<=W;i++)ls[i]=P[i].y;
    sort(ls+1,ls+W+1),cnt=unique(ls+1,ls+W+1)-ls-1;
    for(int i=1;i<=W;i++)P[i].y=lower_bound(ls+1,ls+cnt+1,P[i].y)-ls;
    sort(P+1,P+W+1);
    for(int i=1,tmp=0;i<=W;i++)
    {
        if(P[i].x==P[i-1].x)tmp++;
        else tmp=1;
        P[i].d=tmp,P[i].l=++sum[P[i].y];
    }
    for(int i=W,tmp=0;i;i--)
    {
        if(P[i].x==P[i+1].x)tmp++;
        else tmp=1;
        P[i].u=tmp,P[i].r=sum[P[i].y]-P[i].l;
    }
    K=read();
    for(int i=0;i<=W;i++)C[i][0]=1;
    for(int i=1;i<=W;i++)for(int j=1;j<=i&&j<=K;j++)
        C[i][j]=C[i-1][j-1]+C[i-1][j];
    for(int i=1;i<=W;i++)
    {
        add(P[i].y,C[P[i].l][K]*C[P[i].r][K]-query(P[i].y)+query(P[i].y-1));
        if(P[i].x==P[i-1].x)
            ans+=C[P[i-1].d][K]*C[P[i].u][K]*(query(P[i].y-1)-query(P[i-1].y));
    }
    printf("%u\n",ans&2147483647);
    return 0;
}