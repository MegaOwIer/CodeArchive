#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long LL;
const int maxn=1010;
const double eps=1e-9;
#define pb push_back

int cas,n,h,S,T,q[maxn<<3],hd,t,now;
LL r,x[maxn],y[maxn],z[maxn];
bool vis[maxn];
vector<int> g[maxn];
vector<int>::iterator it;

template<typename T>inline void read(T& x)
{
    int c=getchar(),f=1;x=0;
    while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
    while(isdigit(c))x=x*10+c-'0',c=getchar();
    x*=f;
}
inline LL dis(int i,int j)
{
    return (x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j])+(z[i]-z[j])*(z[i]-z[j]);
}
inline void Spfa()
{
    memset(vis+1,0,T),vis[S]=1;
    q[hd=t=1]=S;
    while(hd<=t)
    {
        now=q[hd++];
        for(it=g[now].begin();it!=g[now].end();it++)if(!vis[*it])
        {
            if(*it==T)return (void)puts("Yes");
            vis[*it]=1,q[++t]=*it;
        }
    }
    puts("No");
}

int main()
{
    read(cas);
    while(cas--)
    {
        read(n),read(h),read(r),T=(S=n+1)+1;
        for(int i=1;i<=n+2;i++)g[i].clear();
        for(int i=1;i<=n;i++)read(x[i]),read(y[i]),read(z[i]);
        for(int i=1;i<=n;i++)
        {
            if(z[i]<=r)
                g[S].pb(i),g[i].pb(S);
            if(z[i]+r>=h)
                g[T].pb(i),g[i].pb(T);
        }
        r=r*r*4;
        for(int i=1;i<n;i++)for(int j=i+1;j<=n;j++)
            if(r>=dis(i,j))
                g[i].pb(j),g[j].pb(i);
        Spfa();
    }
    return 0;
}
