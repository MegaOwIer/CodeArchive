#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MX=50005;

int N,q[MX],*h=q+1,*t=q+1,tmp=1;
LL dp[MX];

struct Field
{
    int x,y;
    bool operator < (const Field& a)const
        {return x==a.x?y>a.y:x<a.x;}
}P[MX];

inline int read()
{
    int x=0,c=getchar();
    while(!isdigit(c))c=getchar();
    while(isdigit(c))x=x*10+c-'0',c=getchar();
    return x;
}

int main()
{
    N=read();
    for(int i=1;i<=N;i++)P[i].x=read(),P[i].y=read();
    sort(P+1,P+N+1);
    for(int i=2;i<=N;i++)
    {
        while(tmp&&P[i].y>=P[tmp].y)tmp--;
        P[++tmp]=P[i];
    }
    N=tmp;
    for(int i=1;i<=N;i++)
    {
        while(t>h&&P[i].x*LL(P[*h+1].y-P[*(h+1)+1].y)>dp[*(h+1)]-dp[*h])h++;
        dp[i]=dp[*h]+(LL)P[*h+1].y*P[i].x;
        while(t>h&&(dp[i]-dp[*(t-1)])*(P[*t+1].y-P[i+1].y)>=(dp[i]-dp[*t])*(P[*(t-1)+1].y-P[i+1].y))t--;
        *++t=i;
    }
    printf("%lld\n",dp[N]);
    return 0;
}
