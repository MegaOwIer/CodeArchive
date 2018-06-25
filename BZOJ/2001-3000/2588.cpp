#include<bits/stdc++.h>
using namespace std;
namespace FastIO
{
	static char c,buf[22];
	static int top,f;
	template<typename T>
	inline void read(T& x)
	{
		x=0,c=getchar(),f=1;
		while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
		while(isdigit(c))x=x*10+c-'0',c=getchar();x*=f;
	}
	template<typename T>
	inline void write(T x,int fl=0)
	{
		top=0;
		do buf[top++]=x%10,x/=10;while(x);
		for(int i=top-1;~i;i--)putchar('0'+buf[i]);
		if(fl)putchar(fl&1?' ':'\n');
	}
}
using FastIO::read;
using FastIO::write;
const int maxn=100005;

struct node{int l,r,x;}p[maxn*20];
struct edge{int to,next;}e[maxn<<1];
int n,m,val[maxn],ls[maxn],cnt,tot,head[maxn],fa[maxn][22],dep[maxn],ans,cntp,root[maxn];

inline void add(int u,int v)
{
	e[++tot]=(edge){v,head[u]},head[u]=tot;
	e[++tot]=(edge){u,head[v]},head[v]=tot;
}
inline void add(int last,int& now,int x,int L=1,int R=cnt)
{
	now=++cntp;
	if(L==R){p[now].x=p[last].x+1;return;}
	int mid=L+R>>1;
	if(x<=mid)add(p[last].l,p[now].l,x,L,mid),p[now].r=p[last].r;
	else add(p[last].r,p[now].r,x,mid+1,R),p[now].l=p[last].l;
	p[now].x=p[p[now].l].x+p[p[now].r].x;
}
inline void dfs(int u)
{
	add(root[fa[u][0]],root[u],val[u]);
	for(int i=1;(1<<i)<=dep[u];i++)fa[u][i]=fa[fa[u][i-1]][i-1];
	for(int i=head[u];i;i=e[i].next)if(e[i].to!=fa[u][0])
		fa[e[i].to][0]=u,dep[e[i].to]=dep[u]+1,dfs(e[i].to);
}
inline int lca(int u,int v)
{
	if(dep[u]<dep[v])swap(u,v);
	for(int i=20;dep[u]-dep[v];i--)if(dep[u]-dep[v]>=(1<<i))u=fa[u][i];
	if(u==v)return u;
	for(int i=20;~i;i--)if(fa[u][i]!=fa[v][i])u=fa[u][i],v=fa[v][i];
	return fa[u][0];
}
inline int query(int a,int b,int A,int B,int k,int L=1,int R=cnt)
{
	int x=p[p[a].l].x+p[p[b].l].x-p[p[A].l].x-p[p[B].l].x;
	if(L==R)return L;
	int mid=L+R>>1;
	if(k<=x)return query(p[a].l,p[b].l,p[A].l,p[B].l,k,L,mid);
	else return query(p[a].r,p[b].r,p[A].r,p[B].r,k-x,mid+1,R);
}

int main()
{
	read(n),read(m);
	for(int i=1;i<=n;i++)read(val[i]),ls[i]=val[i];
	sort(ls+1,ls+n+1),cnt=unique(ls+1,ls+n+1)-ls-1;
	for(int i=1;i<=n;i++)val[i]=lower_bound(ls+1,ls+cnt+1,val[i])-ls;
	for(int i=1,u,v;i<n;i++)read(u),read(v),add(u,v);
	dfs(1);
	for(int i=1,a,b,c,f;i<=m;i++)
	{
		read(a),read(b),read(c),a^=ans,f=lca(a,b);
		ans=ls[query(root[a],root[b],root[f],root[fa[f][0]],c)];
		write(ans,i==m?0:2);
	}
	return 0;
}
