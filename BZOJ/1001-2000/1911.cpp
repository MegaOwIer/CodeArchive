#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef long double LD;
const int MX=1000005;

int N,a,b,c,S[MX],q[MX],*h=q+1,*t=q+1;
LL dp[MX];

inline int read()
{
    int x=0,c=getchar(),f=1;
    while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
    while(isdigit(c))x=x*10+c-'0',c=getchar();
    return x*f;
}
inline LL f(LL x){return a*x*x+b*x+c;}
inline LD getK(int u,int v)
{
    return LD(dp[v]-dp[u])/(S[v]-S[u])+a*LD(S[u]+S[v]);
}

int main()
{
    N=read(),a=read(),b=read(),c=read();
    for(int i=1;i<=N;i++)
    {
        S[i]=S[i-1]+read();
        while(t>h&&f(S[i]-S[*h])-f(S[i]-S[*(h+1)])<dp[*(h+1)]-dp[*h])h++;
        dp[i]=dp[*h]+f(S[i]-S[*h]);
        while(t>h&&getK(*(t-1),i)<getK(*t,i))t--;
        *++t=i;
    }
    printf("%lld\n",dp[N]);
    return 0;
}
