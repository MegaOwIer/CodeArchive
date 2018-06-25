#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn=1e5+5;

struct point{int l,r;LL tag,sum;}p[maxn<<2];
struct edge{int to,next;}e[maxn<<1];
int n,m,val[maxn],f,head[maxn],tot,fa[maxn],mxs[maxn],siz[maxn];
int rt[maxn],en[maxn],pos[maxn],order,cnt=1,po[maxn];
char c;

inline void read(int& x)
{
	c=getchar(),x=0,f=1;
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c))x=x*10+c-'0',c=getchar();x*=f;
}
inline void add(int u,int v)
{
	e[++tot]=(edge){v,head[u]},head[u]=tot;
	e[++tot]=(edge){u,head[v]},head[v]=tot;
}
inline void dfs(int u)
{
	siz[u]=1;
	for(int i=head[u];i;i=e[i].next)if(e[i].to!=fa[u])
	{
		fa[e[i].to]=u;
		dfs(e[i].to),siz[u]+=siz[e[i].to];
		if(siz[e[i].to]>siz[mxs[u]])mxs[u]=e[i].to;
	}
}
inline void dfs2(int u,int root)
{
	if(!u)return;
	rt[u]=root,pos[u]=++order,po[order]=u;
	dfs2(mxs[u],root);
	for(int i=head[u];i;i=e[i].next)if(e[i].to!=fa[u]&&e[i].to!=mxs[u])
		dfs2(e[i].to,e[i].to);
	en[u]=order;
}
inline void pushup(int id){p[id].sum=p[id<<1].sum+p[id<<1|1].sum;}
inline void pushdown(int id)
{
	if(p[id].tag)
	{
		p[id<<1].tag+=p[id].tag,p[id<<1|1].tag+=p[id].tag;
		p[id<<1].sum+=p[id].tag*(p[id<<1].r-p[id<<1].l+1);
		p[id<<1|1].sum+=p[id].tag*(p[id<<1|1].r-p[id<<1|1].l+1);
		p[id].tag=0;
	}
}
inline void build(int l,int r,int id)
{
	p[id].l=l,p[id].r=r;
	if(l==r){p[id].sum=val[po[l]];return;}
	int mid=l+r>>1;
	build(l,mid,id<<1),build(mid+1,r,id<<1|1),pushup(id);
}
inline void insert(int l,int r,int id,int val)
{
	if(p[id].l==l&&p[id].r==r)
	{
		p[id].tag+=val,p[id].sum+=(LL)val*(r-l+1);
		return;
	}
	pushdown(id);
	int mid=p[id].l+p[id].r>>1;
	if(mid<l)insert(l,r,id<<1|1,val);
	else if(mid>=r)insert(l,r,id<<1,val);
	else insert(l,mid,id<<1,val),insert(mid+1,r,id<<1|1,val);
	pushup(id);
}
inline LL ask(int l,int r,int id)
{
	if(p[id].l==l&&p[id].r==r)return p[id].sum;
	pushdown(id);
	int mid=p[id].l+p[id].r>>1;
	if(mid<l)return ask(l,r,id<<1|1);
	else if(mid>=r)return ask(l,r,id<<1);
	else return ask(l,mid,id<<1)+ask(mid+1,r,id<<1|1);
}
inline void query(int x)
{
	LL ans=0;
	for(int now=x,f=rt[x];now;now=fa[f],f=rt[now])
		ans+=ask(pos[f],pos[now],1);
	printf("%lld\n",ans);
}

int main()
{
	read(n),read(m);
	for(int i=1;i<=n;i++)read(val[i]);
	for(int i=1,u,v;i<n;i++)read(u),read(v),add(u,v);
	dfs(1),dfs2(1,1),build(1,n,1);
	for(int i=1,opt,x,a;i<=m;i++)
	{
		read(opt),read(x);
		if(opt==1)read(a),insert(pos[x],pos[x],1,a);
		else if(opt==2)read(a),insert(pos[x],en[x],1,a);
		else query(x);
	}
	return 0;
}
