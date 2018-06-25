#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MV=1005,ME=3200;

int dis[MV],S,T,N,K,ls[MV],cnt,lth[505];
char inq[MV];
pair<int,int> s[505];

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
    static int f=0;
    c=getchar(),x=0;
    while(!isdigit(c)){if(c=='-')f=1;c=getchar();}
    while(isdigit(c))x=x*10+c-48,c=getchar();
    if(f)f=0,x=-x;
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
inline LL sqr(int x){return (LL)x*x;}

int main()
{
	read(N),read(K);
	for(int i=1,x1,x2,y1,y2;i<=N;i++)
	{
		read(x1),read(y1),read(x2),read(y2);
		lth[i]=floor(sqrt(sqr(x1-x2)+sqr(y1-y2)));
		x1=x1<<1|1,x2=x2<<1;
		if(x1>x2)swap(x1,x2);
		ls[++cnt]=x1,ls[++cnt]=x2;
		s[i]=make_pair(x1,x2);
	}
	sort(ls+1,ls+cnt+1),cnt=unique(ls+1,ls+cnt+1)-ls-1;
	T=(S=cnt+1)+1;
	for(int i=1;i<=N;i++)
		add(lower_bound(ls+1,ls+cnt+1,s[i].first)-ls,
			lower_bound(ls+1,ls+cnt+1,s[i].second)-ls,
			1,-lth[i]);
	add(S,1,K,0),add(cnt,T,K,0);
	for(int i=1;i<cnt;i++)add(i,i+1,1e9,0);
	printf("%d\n",-MinCostMaxFlow());
    return 0;
}
