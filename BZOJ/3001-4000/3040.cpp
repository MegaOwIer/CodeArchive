#include<bits/stdc++.h>
#include<ext/pb_ds/priority_queue.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long LL;
typedef pair<LL,int> pLi;
typedef __gnu_pbds::priority_queue<pLi,greater<pLi> > pairing_heap;
const int maxn=1000005;
#define mp make_pair
#define st first
#define nd second

namespace FastIO
{
    char c;
    int top,bf[22];
    template<typename T>inline void read(T& x)
    {
        x=0,c=getchar();
        while(!isdigit(c))c=getchar();
        while(isdigit(c))x=x*10+c-'0',c=getchar();
    }
    template<typename T>inline void write(T x)
    {
        top=0;
        do bf[++top]=x%10,x/=10;while(x);
        while(top)putchar(48+bf[top--]);
        putchar('\n');
    }
}
using FastIO::read;
using FastIO::write;

struct edge{int to,next,w;}e[maxn*10];
int n,m,T,rxa,rxc,rya,ryc,rp,h,head[maxn],u,v,w;
LL dis[maxn];
pairing_heap q;
pairing_heap::point_iterator id[maxn];

inline void Dijkstra()
{
    register int now,i;
    memset(dis+2,0x3f,sizeof(LL)*(n-1));
    q.push(mp(0,1));
    while(!q.empty())
    {
        now=q.top().nd,q.pop();
        for(i=head[now];i;i=e[i].next)
            if(e[i].w+dis[now]<dis[e[i].to])
            {
                dis[e[i].to]=e[i].w+dis[now];
                if(id[e[i].to]!=0)
                    q.modify(id[e[i].to],mp(dis[e[i].to],e[i].to));
                else id[e[i].to]=q.push(mp(dis[e[i].to],e[i].to));
            }
    }
}

int main()
{
    read(n),read(m);
    read(T),read(rxa),read(rxc),read(rya),read(ryc),read(rp);
    register int i,x,y,a,b;
    for(i=1;i<=T;i++)
    {
        x=((LL)x*rxa+rxc)%rp;
        y=((LL)y*rya+ryc)%rp;
        a=x%n+1,b=y%n+1;
        if(a>b)swap(a,b);
        e[i]=(edge){b,head[a],100000000-100*a},head[a]=i;
    }
    for(i=T+1;i<=m;i++)
    {
        read(u),read(v),read(w);
        e[i]=(edge){v,head[u],w},head[u]=i;
    }
    Dijkstra();
    write(dis[n]);
    return 0;
}
