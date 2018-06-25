#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MX=100005;

namespace FastIO
{
	char c;
	int tp,bf[22];
	template<typename T>inline void read(T& x)
	{
		c=getchar(),x=0;
		while(!isdigit(c))c=getchar();
		while(isdigit(c))x=x*10+c-'0',c=getchar();
	}
	template<typename T>inline void write(T x)
	{
		if(x<0)return;
		tp=0;
		do bf[++tp]=x%10,x/=10;while(x);
		while(tp)putchar(48+bf[tp--]);
		putchar('\n');
	}
}
using FastIO::read;
using FastIO::write;

struct Ques{int l,r,t,id;}a[MX];
struct Change{int x,y,pre;}b[MX];
struct edge{int to,nxt;}e[MX<<1];
int n,m,q,B,val[MX],w[MX],head[MX],tot,col[MX],pre[MX],cnt1,cnt2;
int dep[MX],fa[20][MX],dfn[MX],cnt,Bcnt,pos[MX],stk[MX],top;
int Num[MX],LCA;
LL ans[MX],Ans;
bool vis[MX];

inline bool cmp(const Ques& a,const Ques& b)
{
	if(pos[a.l]==pos[b.l]&&pos[a.r]==pos[b.r])return a.t<b.t;
	if(pos[a.l]==pos[b.l])return dfn[a.r]<dfn[b.r];
	return pos[a.l]<pos[b.l];
}
inline void add(int u,int v)
{
	e[++tot]=(edge){v,head[u]},head[u]=tot;
	e[++tot]=(edge){u,head[v]},head[v]=tot;
}
inline int lca(int x,int y)
{
	if(dep[x]<dep[y])swap(x,y);
	for(int i=16;dep[x]-dep[y];i--)if(dep[x]-dep[y]>=(1<<i))x=fa[i][x];
	if(x==y)return x;
	for(int i=16;~i;i--)if(fa[i][x]!=fa[i][y])
		x=fa[i][x],y=fa[i][y];
	return fa[0][x];
}
inline int dfs(int u,int f)
{
	int siz=0;
	dfn[u]=++cnt;
	for(int i=1;(1<<i)<=dep[u];i++)fa[i][u]=fa[i-1][fa[i-1][u]];
	for(int i=head[u];i;i=e[i].nxt)if(e[i].to!=f)
	{
		fa[0][e[i].to]=u,dep[e[i].to]=dep[u]+1;
		siz+=dfs(e[i].to,u);
		if(siz>=B)
		{
			++Bcnt;
			while(siz--)pos[stk[top--]]=Bcnt;
			siz=0;
		}
	}
	stk[++top]=u;
	return siz+1;
}
inline void update(int x)
{
	if(vis[x])Ans-=(LL)w[Num[col[x]]--]*val[col[x]];
	else Ans+=(LL)w[++Num[col[x]]]*val[col[x]];
	vis[x]^=1;
}
inline void change(int x,int y)
{
	while(x!=y)
		if(dep[x]<dep[y])update(y),y=fa[0][y];
		else update(x),x=fa[0][x];
}
inline void modify(int x,int c)
{
	if(!vis[x])col[x]=c;
	else update(x),col[x]=c,update(x);
}

int main()
{
	read(n),read(m),read(q),B=1+pow(n,0.60);
	for(int i=1;i<=m;i++)read(val[i]);
	for(int i=1;i<=n;i++)read(w[i]);
	for(int i=1,u,v;i<n;i++)read(u),read(v),add(u,v);
	for(int i=1;i<=n;i++)read(col[i]),pre[i]=col[i];
	dfs(1,-1);
	while(top)pos[stk[top--]]=Bcnt;
	for(int i=1,op,x,y;i<=q;i++)
	{
		read(op),read(x),read(y);
		if(op)
		{
			if(dfn[x]>dfn[y])swap(x,y);
			++cnt1,a[cnt1]=(Ques){x,y,cnt2,cnt1};
		}
		else b[++cnt2]=(Change){x,y,pre[x]},pre[x]=y;
	}
	sort(a+1,a+cnt1+1,cmp);
	cnt2=a[1].t;
	for(int i=1;i<=a[1].t;i++)modify(b[i].x,b[i].y);
	change(a[1].l,a[1].r),LCA=lca(a[1].l,a[1].r);
	update(LCA),ans[a[1].id]=Ans,update(LCA);
	for(int i=2;i<=cnt1;i++)
	{
		while(cnt2<a[i].t)cnt2++,modify(b[cnt2].x,b[cnt2].y);
		while(cnt2>a[i].t)modify(b[cnt2].x,b[cnt2].pre),cnt2--;
		change(a[i-1].l,a[i].l),change(a[i-1].r,a[i].r);
		LCA=lca(a[i].l,a[i].r);
		update(LCA),ans[a[i].id]=Ans,update(LCA);
	}
	for(int i=1;i<=cnt1;i++)write(ans[i]);
	return 0;
}