#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MX=500005;

int N,a[15];
LL A,B,dis[MX];

template<typename T>inline void read(T& x)
{
    static char c;
    x=0,c=getchar();
    while(!isdigit(c))c=getchar();
    while(isdigit(c))x=x*10+c-'0',c=getchar();
}
inline void Dijkstra()
{
    typedef pair<LL,int> pli;
    static bool vis[MX];
    LL tmp;
    priority_queue<pli,vector<pli>,greater<pli> > q;
    memset(dis,0x3f,sizeof(LL)*a[1]);
    q.push(make_pair(dis[0]=0,0));
    while(!q.empty())
    {
        int now=q.top().second;
        q.pop();
        if(vis[now])continue;
        vis[now]=1;
        for(int i=2,to;i<=N;i++)
        {
            to=(now+a[i])%a[1],tmp=dis[now]+(now+a[i])/a[1];
            if(dis[to]>tmp)q.push(make_pair(dis[to]=tmp,to));
        }
    }
}
inline LL calc(LL x)
{
    LL ans=0;
    for(int i=0,tmp=x%a[1];i<a[1];i++)
        ans+=max(0LL,x/a[1]+(tmp>=i)-dis[i]);
    return ans;
}

int main()
{
    read(N),read(A),read(B);
    for(int i=1;i<=N;i++)read(a[i]);
    sort(a+1,a+N+1,greater<int>());
    if(!a[1])return puts("0"),0;
    Dijkstra();
    printf("%lld\n",calc(B)-calc(A-1));
    return 0;
}