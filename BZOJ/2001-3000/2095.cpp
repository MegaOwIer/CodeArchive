#include<bits/stdc++.h>
using namespace std;
const int MV=2010,ME=6200;
typedef int Array[MV];

int S,T,N,M,l,r,mid,ans=-1;
Array dep,deg,a,b,c,d;

struct edge
{
	int to,f;
	edge *nxt,*rev;
	edge(){}
	edge(int t,edge *n,int f):to(t),f(f),nxt(n){}
	void* operator new(size_t);
}*E[MV],ePool[ME],*ptr=ePool,*cur[MV];
inline void* edge::operator new(size_t){return ptr++;}

inline void read(int& x)
{
	static char c;
	c=getchar(),x=0;
	while(!isdigit(c))c=getchar();
	while(isdigit(c))x=x*10+c-'0',c=getchar();
}
inline void add(int u,int v,int f)
{
	E[u]=new edge(v,E[u],f),E[v]=new edge(u,E[v],0);
	E[u]->rev=E[v],E[v]->rev=E[u];
}
inline bool bfs()
{
	int now;
	queue<int> q;
	memset(dep+1,-1,sizeof(int)*T),dep[S]=0;
	q.push(S);
	while(!q.empty())
	{
		now=q.front(),q.pop();
		for(edge *i=E[now];i;i=i->nxt)if(i->f&&!~dep[i->to])
			dep[i->to]=dep[now]+1,q.push(i->to);
	}
	return ~dep[T];
}
int dfs(int u,int flow)
{
	if(u==T||!flow)return flow;
	int used=0,w;
	for(edge* &i=cur[u];i;i=i->nxt)
		if(i->f&&dep[i->to]==dep[u]+1)
		{
			w=dfs(i->to,min(flow-used,i->f));
			i->f-=w,i->rev->f+=w,used+=w;
			if(used==flow)return flow;
		}
	if(!used)dep[u]=-1;
	return used;
}
inline int Dinic()
{
	int ans=0;
	while(bfs())memcpy(cur+1,E+1,sizeof(edge*)*T),ans+=dfs(S,1e9);
	return ans;
}
inline bool check(int val)
{
	int ans=0;
	ptr=ePool,memset(E+1,0,sizeof(edge*)*T);
	memset(deg+1,0,sizeof(int)*N);
	for(int i=1;i<=M;i++)
	{
		if(c[i]<=val)deg[a[i]]--,deg[b[i]]++;
		else deg[a[i]]++,deg[b[i]]--;
		if(c[i]<=val&&d[i]<=val)add(b[i],a[i],1);
	}
	for(int i=1;i<=N;i++)
		if(deg[i]&1)return 0;
		else if(deg[i]>0)add(S,i,deg[i]/2),ans+=deg[i]/2;
		else if(deg[i]<0)add(i,T,-deg[i]/2);
	return Dinic()==ans;
}

int main()
{
	read(N),read(M),T=(S=N+1)+1;
	for(int i=1;i<=M;i++)
	{
		read(a[i]),read(b[i]),read(c[i]),read(d[i]);
		l=max(l,min(c[i],d[i])),r=max(r,max(c[i],d[i]));
	}
	while(l<=r)
	{
		mid=l+r>>1;
		if(check(mid))ans=mid,r=mid-1;
		else l=mid+1;
	}
	if(~ans)printf("%d\n",ans);
	else puts("NIE");
	return 0;
}
