#include<bits/stdc++.h>
using namespace std;
const int MX=500005;
typedef long long LL;
typedef int Array[MX<<2];

char Pool[300000000],*ptr=Pool;
inline void* operator new(size_t siz){return (ptr+=siz)-siz;}
inline void operator delete(void*){}

int N,pos[MX],num,ans,top;
Array dfn,low,stk,bl,ind;
LL X[MX],R[MX],mn[MX<<2],mx[MX<<2],vmn[MX<<2],vmx[MX<<2];
bool ins[MX<<2];

struct Graph
{
	struct edge
	{
		int to;
		edge* nxt;
		edge(){}
		edge(int t,edge* n):to(t),nxt(n){}
	}*E[MX<<2];
	
	void operator=(Graph&);
	void add(int u,int v){E[u]=new edge(v,E[u]);}
	void Tarjan(int);
	void Toposort();
}A,B;
void Graph::operator=(Graph& a)
{
	for(int p=1;p<=N<<2;p++)
		for(edge* i=a.E[p];i;i=i->nxt)if(bl[p]!=bl[i->to])
			add(bl[i->to],bl[p]),ind[bl[p]]++;	
}
void Graph::Tarjan(int u)
{
	static int cnt=0;
	low[u]=dfn[u]=++cnt,stk[++top]=u,ins[u]=1;
	for(edge *i=E[u];i;i=i->nxt)
		if(!dfn[i->to])Tarjan(i->to),low[u]=min(low[u],low[i->to]);
		else if(ins[i->to])low[u]=min(low[u],dfn[i->to]);
	if(dfn[u]==low[u])
	{
		++num,vmn[num]=1LL<<62,vmx[num]=-1LL<<62;
		do
		{
			ins[stk[top]]=0,bl[stk[top]]=num;
			vmn[num]=min(vmn[num],mn[stk[top]]);
			vmx[num]=max(vmx[num],mx[stk[top]]);
		}
		while(stk[top--]!=u);
	}
}
void Graph::Toposort()
{
	int now;
	for(int i=1;i<=num;i++)if(!ind[i])stk[++top]=i;
	while(top)
	{
		now=stk[top--];
		for(edge *i=E[now];i;i=i->nxt)
		{
			vmn[i->to]=min(vmn[i->to],vmn[now]);
			vmx[i->to]=max(vmx[i->to],vmx[now]);
			if(!--ind[i->to])stk[++top]=i->to;
		}
	}
}

template<typename T>inline void read(T& x)
{
	static char c;
	static int f=0;
	c=getchar(),x=0;
	while(!isdigit(c)){if(c=='-')f=1;c=getchar();}
	while(isdigit(c))x=x*10+c-'0',c=getchar();
	if(f)x=-x,f=0;
}
void build(int L,int R,int id)
{
	if(L==R)mn[id]=mx[id]=X[L],pos[L]=id;
	else
	{
		mn[id]=1LL<<62,mx[id]=-1LL<<62;
		int mid=L+R>>1;
		build(L,mid,id<<1),A.add(id,id<<1);
		build(mid+1,R,id<<1|1),A.add(id,id<<1|1);
	}
}
void update(int l,int r,int p,int L,int R,int id)
{
	if(l<=L&&R<=r)return A.add(p,id);
	int mid=L+R>>1;
	if(l<=mid)update(l,r,p,L,mid,id<<1);
	if(r>mid)update(l,r,p,mid+1,R,id<<1|1);
}

int main()
{
	read(N),X[N+1]=1LL<<62;
	for(int i=1;i<=N;i++)read(X[i]),read(R[i]);
	build(1,N,1);
	for(int i=1;i<=N;i++)
		update(lower_bound(X+1,X+N+2,X[i]-R[i])-X,
			upper_bound(X+1,X+N+2,X[i]+R[i])-X-1,pos[i],1,N,1);
	for(int i=1;i<=(N<<2);i++)if(!dfn[i])A.Tarjan(i);
	B=A,B.Toposort();
	for(int i=1;i<=N;i++)
		ans=(ans+
			(LL)i*(upper_bound(X+1,X+N+1,vmx[bl[pos[i]]])-lower_bound(X+1,X+N+1,vmn[bl[pos[i]]]))
		)%1000000007;
	printf("%d\n",ans);
	return 0;
}
