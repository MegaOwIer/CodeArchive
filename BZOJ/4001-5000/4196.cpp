#include<bits/stdc++.h>
using namespace std;
const int maxn=100005;
#define lson p[id<<1]
#define rson p[id<<1|1]

struct node{int l,r,sum,tag;}p[maxn<<2];
int n,T,x,fa[maxn],siz[maxn],mxs[maxn],Time,st[maxn],en[maxn],ord[maxn],dep[maxn],root[maxn];
char c,opt;
vector<int> g[maxn];

inline void read(int& x)
{
	x=0,c=getchar();
	while(!isdigit(c))c=getchar();
	while(isdigit(c))x=x*10+c-'0',c=getchar();
}
inline void getalpha(){do opt=getchar();while(!isalpha(opt));}
inline void dfs1(int u)
{
	siz[u]=1;
	for(vector<int>::iterator it=g[u].begin();it!=g[u].end();++it)
	{
		dep[*it]=dep[u]+1,dfs1(*it),siz[u]+=siz[*it];
		if(siz[*it]>siz[mxs[u]])mxs[u]=*it;
	}
}
inline void dfs2(int u,int rt)
{
	if(!u)return;
	st[u]=++Time,ord[Time]=u,root[u]=rt;
	dfs2(mxs[u],rt);
	for(vector<int>::iterator it=g[u].begin();it!=g[u].end();++it)
		if(*it!=mxs[u])dfs2(*it,*it);
	en[u]=Time;
}
inline void pushdown(int id)
{
	if(!p[id].tag)return;
	lson.tag=rson.tag=p[id].tag;
	if(p[id].tag==1)lson.sum=lson.r-lson.l+1,rson.sum=rson.r-rson.l+1;
	else lson.sum=rson.sum=0;
	p[id].tag=0;
}
inline void pushup(int id){p[id].sum=lson.sum+rson.sum;}
inline void build(int l,int r,int id)
{
	p[id].l=l,p[id].r=r;
	if(l==r)return;
	int mid=l+r>>1;
	build(l,mid,id<<1),build(mid+1,r,id<<1|1);
}
inline int ask(int l,int r,int id)
{
	if(p[id].l==l&&p[id].r==r)return p[id].sum;
	pushdown(id);
	int mid=p[id].l+p[id].r>>1;
	if(mid<l)return ask(l,r,id<<1|1);
	else if(mid>=r)return ask(l,r,id<<1);
	else return ask(l,mid,id<<1)+ask(mid+1,r,id<<1|1);
}
inline void change(int l,int r,int id,int val)
{
	if(p[id].l==l&&p[id].r==r)
	{
		p[id].tag=val;
		if(val&1)p[id].sum=r-l+1;
		else p[id].sum=0;
		return;
	}
	pushdown(id);
	int mid=p[id].l+p[id].r>>1;
	if(mid<l)change(l,r,id<<1|1,val);
	else if(mid>=r)change(l,r,id<<1,val);
	else change(l,mid,id<<1,val),change(mid+1,r,id<<1|1,val);
	pushup(id);
}
inline void install(int x)
{
	int ans=dep[x];
	for(int i=x,f=root[i];i;i=fa[f],f=root[i])
		ans-=ask(st[f],st[i],1),change(st[f],st[i],1,1);
	printf("%d\n",ans);
}

int main()
{
	read(n),dep[1]=1;
	for(int i=2,u;i<=n;i++)
	{
		read(u),u++,fa[i]=u;
		g[u].push_back(i);
	}
	dfs1(1),dfs2(1,1),build(1,n,1);
	read(T);
	while(T--)
	{
		getalpha(),read(x),x++;
		if(opt=='i')install(x);
		else printf("%d\n",ask(st[x],en[x],1)),change(st[x],en[x],1,2);
	}
	return 0;
}
