#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const int MX=200005;

int pw[33],N,Q,a[MX];
LL d[MX];
set<int> S[35];

inline int read()
{
    int x=0,c=getchar();
    while(!isdigit(c))c=getchar();
    while(isdigit(c))x=x*10+c-'0',c=getchar();
    return x;
}
void insert(int u,int v){for(;u<=N;u+=u&-u)d[u]+=v;}
LL ask(int u){LL ans=0;for(;u;u-=u&-u)ans+=d[u];return ans;}
int getans()
{
    if(a[1]==0)return 1;
    for(int i=0;i<30;i++)if(S[i].size())
    {
        auto it=S[i].begin();
        if(ask(*it)==2*a[*it])return *it;
        if(++it!=S[i].end()&&ask(*it)==2*a[*it])return *it;
    }
    return -1;
}

#define getset(a) lower_bound(pw,pw+30,a)-pw
int main()
{
    pw[0]=1;
    for(int i=1;i<=29;i++)pw[i]=1<<i;
    N=read(),Q=read();
    for(int i=1;i<=N;i++)
    {
        a[i]=read();
        if(a[i])S[getset(a[i])].insert(i);
        insert(i,a[i]);
    }
    while(Q--)
    {
        int p=read(),x=read();
        S[getset(a[p])].erase(p);
        insert(p,x-a[p]),a[p]=x;
        if(x)S[getset(x)].insert(p);
        printf("%d\n",getans());
    }
    return 0;
}
#undef getset
