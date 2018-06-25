#include<cstdio>
#include<cctype>
#include<iostream>
using namespace std;
typedef long long LL;
const int MX=31625;

int T,N,P,pr[3405],cnt,d[12],pw[12],tot,t[12],ans;
bool vis[MX];

inline int read()
{
    static int c,x;
    x=0,c=getchar();
    while(!isdigit(c))c=getchar();
    while(isdigit(c))x=x*10+c-'0',c=getchar();
    return x;
}
inline int Pow(int a,int b)
{
    int ans=1;
    for(;b;b>>=1,a=(LL)a*a%P)
        if(b&1)ans=(LL)ans*a%P;
    return ans;
}
inline void divide(int N)
{
    tot=0;
    for(int i=1;pr[i]*pr[i]<=N;i++)if(N%pr[i]==0)
    {
        d[++tot]=pr[i],pw[tot]=0;
        while(N%pr[i]==0)pw[tot]++,N/=pr[i];
    }
    if(N>1)d[++tot]=N,pw[tot]=1;
}
void dfs(int index,int S)
{
    if(index>tot)
    {
        int tmp=Pow(N,N/S-1);
        for(int i=1;i<=tot;i++)if(t[i])
            S-=S/d[i];
        ans=(ans+(LL)tmp*S)%P;
        return;
    }
    for(int i=0,tmp=1;i<=pw[index];i++,tmp*=d[index])
        t[index]=i,dfs(index+1,S*tmp);
}

int main()
{
    for(int i=2,tmp;i<=31622;i++)
    {
        if(!vis[i])pr[++cnt]=i;
        for(int j=1;j<=cnt&&(tmp=i*pr[j])<=31622;j++)
        {
            vis[tmp]=1;
            if(i%pr[j]==0)break;
        }
    }
    T=read();
    while(T--)
    {
        divide(N=read()),P=read();
        ans=0,dfs(1,1);
        printf("%d\n",ans);
    }
    return 0;
}