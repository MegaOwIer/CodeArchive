#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MV=5100,ME=50000;

int dis[MV],S,T,N,a[105][105],id[105][105],cnt,val[MV],ans,d[MV];
char inq[MV];

struct edge
{
    int to,f,c;
    edge *nxt,*rev;
    edge(){}
    edge(int t,edge *n,int f,int c):to(t),f(f),c(c),nxt(n){}
    void* operator new(size_t);
}*E[MV],ePool[ME],*ptr=ePool,*from[MV];
inline void* edge::operator new(size_t){return ptr++;}

inline void read(int& x)
{
    static char c;
    x=0,c=getchar();
    while(!isdigit(c))c=getchar();
    while(isdigit(c))x=x*10+c-48,c=getchar();
}
inline void add(int u,int v,int f,int c)
{
    E[u]=new edge(v,E[u],f,c),E[v]=new edge(u,E[v],0,-c);
    E[u]->rev=E[v],E[v]->rev=E[u];
}
inline bool spfa()
{
    queue<int> q;
    int now;
    memset(dis+1,0x3f,sizeof(int)*T),dis[S]=0;
    memset(inq+1,0,sizeof(char)*T),inq[S]=1;
    q.push(S);
    while(!q.empty())
    {
        now=q.front(),q.pop(),inq[now]=0;
        for(edge *i=E[now];i;i=i->nxt)if(i->f&&dis[i->to]>dis[now]+i->c)
        {
            dis[i->to]=dis[now]+i->c,from[i->to]=i;
            if(!inq[i->to])q.push(i->to),inq[i->to]=1;
        }
    }
    return dis[T]<0x3f3f3f3f;
}
inline int MinCostMaxFlow()
{
    int ans=0,flow;
    while(spfa())
    {
        flow=2147483647;
        for(int i=T;i!=S;i=from[i]->rev->to)flow=min(flow,from[i]->f);
        for(int i=T;i!=S;i=from[i]->rev->to)from[i]->f-=flow,from[i]->rev->f+=flow;
        ans+=flow*dis[T];
    }
    return ans;
}

int main()
{
    read(N),cnt=N,ans=N*(N-1)*(N-2)/6;
    for(int i=1;i<=N;i++)for(int j=1;j<=N;j++)
    {
        read(a[i][j]);
        if(i<=j||a[i][j]!=2)continue;
        id[i][j]=id[j][i]=++cnt;
        val[cnt]=i^j;
    }
    T=(S=cnt+1)+1;
    for(int i=1;i<=N;i++)for(int j=1;j<i;j++)
    {
    	if(a[i][j]==1)ans-=d[i],d[i]++;
    	else if(a[i][j]==0)ans-=d[j],d[j]++;
    	else add(i,id[i][j],1,0),add(j,id[i][j],1,0),add(id[i][j],T,1,0);
    }
    for(int i=1;i<=N;i++)for(int j=N-2;j>=d[i];j--)add(S,i,1,j);
    printf("%d\n",ans-MinCostMaxFlow());
    for(int i=1;i<=N;i++)
    {
        for(edge *j=E[i];j;j=j->nxt)if(j->to>N&&j->to<S)
            a[i][val[j->to]^i]=1-j->f;
        for(int j=1;j<=N;j++)printf("%d ",a[i][j]);
        putchar('\n');
    }
    return 0;
}
