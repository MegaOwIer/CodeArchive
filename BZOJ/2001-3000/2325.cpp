#include<bits/stdc++.h>
using namespace std;
namespace FastIO
{
	static char c;
	static int top,buf[22];
	template<typename T>inline void read(T& x)
	{
		x=0,c=getchar();
		while(!isdigit(c))c=getchar();
		while(isdigit(c))x=x*10+c-'0',c=getchar();
	}
	template<typename T>inline void write(T x)
	{
		top=0;
		do buf[++top]=x%10,x/=10;while(x);
		while(top)putchar(48+buf[top--]);
		putchar('\n');
	}
}
using FastIO::read;
using FastIO::write;
const int MX=30005;
#define lson p[id<<1]
#define rson p[id<<1|1]

struct Node
{
	int d1,d2,d3,d4,r1,r2,l1,l2;
	inline void init(int _=-1e9){d1=d2=d3=d4=r1=r2=l1=l2=_;}
}p[MX<<2],a,b,src;
struct edge{int to,next;}e[MX<<1];
int n,m,tot,head[MX],siz[MX],dep[MX],fa[MX],mxs[MX],bl[MX],pos[MX],po[MX],cnt;
char s[MX][3],op;

inline void add(int u,int v)
{
	e[++tot]=(edge){v,head[u]},head[u]=tot;
	e[++tot]=(edge){u,head[v]},head[v]=tot;
}
inline void dfs1(int u,int pre)
{
	siz[u]=1,dep[u]=dep[pre]+1;
	for(int i=head[u];i;i=e[i].next)if(e[i].to!=pre)
	{
		fa[e[i].to]=u,dfs1(e[i].to,u),siz[u]+=siz[e[i].to];
		if(siz[e[i].to]>siz[mxs[u]])mxs[u]=e[i].to;
	}
}
inline void dfs2(int u,int root)
{
	pos[u]=++cnt,po[cnt]=u,bl[u]=root;
	if(!mxs[u])return;
	dfs2(mxs[u],root);
	for(int i=head[u];i;i=e[i].next)if(e[i].to!=mxs[u]&&e[i].to!=fa[u])
		dfs2(e[i].to,e[i].to);
}
inline Node merge(const Node& l,const Node& r)
{
	src.d1=max(l.d1+r.d1,l.d2+r.d3);if(src.d1<0)src.d1=-1e9;
	src.d2=max(l.d2+r.d4,l.d1+r.d2);if(src.d2<0)src.d2=-1e9;
	src.d3=max(l.d3+r.d1,l.d4+r.d3);if(src.d3<0)src.d3=-1e9;
	src.d4=max(l.d3+r.d2,l.d4+r.d4);if(src.d4<0)src.d4=-1e9;
	src.l1=max(l.l1,max(l.d1+r.l1,l.d2+r.l2));if(src.l1<0)src.l1=-1e9;
	src.l2=max(l.l2,max(l.d4+r.l2,l.d3+r.l1));if(src.l2<0)src.l2=-1e9;
	src.r1=max(r.r1,max(r.d1+l.r1,r.d3+l.r2));if(src.r1<0)src.r1=-1e9;
	src.r2=max(r.r2,max(r.d2+l.r1,r.d4+l.r2));if(src.r2<0)src.r2=-1e9;
	return src;
}
inline void build(int l,int r,int id)
{
	if(l==r)
	{
		int x=po[l];
		p[id].init();
		if(s[x][0]=='.')p[id].d1=p[id].l1=p[id].r1=1;
		if(s[x][1]=='.')p[id].d4=p[id].l2=p[id].r2=1;
		if(s[x][0]=='.'&&s[x][1]=='.')
			p[id].d2=p[id].d3=p[id].l1=p[id].l2=p[id].r1=p[id].r2=2;
		return;
	}
	int mid=l+r>>1;
	build(l,mid,id<<1),build(mid+1,r,id<<1|1);
	p[id]=merge(lson,rson);
}
inline void change(int l,int r,int pos,int id)
{
	if(l==r)
	{
		int x=po[l];
		p[id].init();
		if(s[x][0]=='.')p[id].d1=p[id].l1=p[id].r1=1;
		if(s[x][1]=='.')p[id].d4=p[id].l2=p[id].r2=1;
		if(s[x][0]=='.'&&s[x][1]=='.')
			p[id].d2=p[id].d3=p[id].l1=p[id].l2=p[id].r1=p[id].r2=2;
		return;
	}
	int mid=l+r>>1;
	if(mid>=pos)change(l,mid,pos,id<<1);
	else change(mid+1,r,pos,id<<1|1);
	p[id]=merge(lson,rson);
}
inline Node ask(int l,int r,int id,int L,int R)
{
	if(l==L&&R==r)return p[id];
	int mid=l+r>>1;
	if(R<=mid)return ask(l,mid,id<<1,L,R);
	else if(L>mid)return ask(mid+1,r,id<<1|1,L,R);
	else return merge(ask(l,mid,id<<1,L,mid),ask(mid+1,r,id<<1|1,mid+1,R));
}
inline int solve(int u,int v)
{
	if(s[u][0]=='#'&&s[u][1]=='#')return 0;
	a.init(0),b.init(0);
	while(bl[u]!=bl[v])
	{
		if(dep[bl[u]]>dep[bl[v]])
			a=merge(ask(1,n,1,pos[bl[u]],pos[u]),a),u=fa[bl[u]];
		else b=merge(ask(1,n,1,pos[bl[v]],pos[v]),b),v=fa[bl[v]];
	}
	if(dep[u]<dep[v])b=merge(ask(1,n,1,pos[u],pos[v]),b);
	else a=merge(ask(1,n,1,pos[v],pos[u]),a);
	swap(a.l1,a.r1),swap(a.l2,a.r2),swap(a.d2,a.d3),a=merge(a,b);
	return max(a.l1,a.l2);
}

int main()
{
	
	freopen("input.txt","r",stdin);
	freopen("1.txt","w",stdout); 
	read(n),read(m);
	for(int i=1,u,v;i<n;i++)read(u),read(v),add(u,v);
	for(int i=1;i<=n;i++)scanf("%s",s[i]); 
	dfs1(1,0),dfs2(1,1),build(1,n,1);
	for(int i=1,u,v;i<=m;i++)
	{
		do op=getchar();while(!isalpha(op));
		read(u);
		if(op=='Q')read(v),write(solve(u,v));
		else scanf("%s",s[u]),change(1,n,pos[u],1);
	}
	return 0;
}
