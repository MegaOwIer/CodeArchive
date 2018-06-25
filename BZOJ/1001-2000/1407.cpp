#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int n,c[17],p[17],l[17],mx,d;
LL dc,dp,x,y,step;

inline int exgcd(int a,int b,LL& x,LL& y)
{
    if(!b){x=1,y=0;return a;}
    int ret=exgcd(b,a%b,y,x);
    y=y-a/b*x;
    return ret;
}
inline int read()
{
    int x=0;char c=getchar();
    while(c<'0'||c>'9')c=getchar();
    while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
    return x;
}
inline bool check(int u)
{
    for(int i=1;i<n;i++)for(int j=i+1;j<=n;j++)
    {
        dc=c[i]-c[j],dp=p[j]-p[i];
        dc=(dc%u+u)%u,dp=(dp%u+u)%u;
        d=exgcd(dp,u,x,y);
        if(dc%d)continue;
        x=x*dc/d,y=y*dc/d;
        step=u/d;
        x=(x%step+step)%step;
        if(x<=l[i]&&x<=l[j])return 0;
    }
    return 1;
}

int main()
{
    n=read();
    for(int i=1;i<=n;i++)c[i]=read(),p[i]=read(),l[i]=read(),mx=max(mx,c[i]),c[i]--;
    for(int i=mx;i<=1000000;i++)if(check(i))return printf("%d",i)*0;
}
