#include<bits/stdc++.h>
using namespace std;
const int MV=1005,ME=3200;

int dis[MV],S,T,N,K,ls[MV],cnt;
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
    c=getchar(),x=0;
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
	read(N),read(K);
	for(int i=1,l,r;i<=N;i++)
	{
		read(l),read(r);
		if(l>r)swap(l,r);
		ls[++cnt]=l,ls[++cnt]=r;
		s[i]=make_pair(l,r);
	}
	sort(ls+1,ls+cnt+1),cnt=unique(ls+1,ls+cnt+1)-ls-1;
	T=(S=cnt+1)+1;
	for(int i=1;i<=N;i++)
		add(lower_bound(ls+1,ls+cnt+1,s[i].first)-ls,
			lower_bound(ls+1,ls+cnt+1,s[i].second)-ls,
			1,s[i].first-s[i].second);
	add(S,1,K,0),add(cnt,T,K,0);
	for(int i=1;i<cnt;i++)add(i,i+1,1e9,0);
	printf("%d\n",-MinCostMaxFlow());
    return 0;
}
