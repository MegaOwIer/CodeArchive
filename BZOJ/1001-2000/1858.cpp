#include<bits/stdc++.h>
using namespace std;
namespace FastIO
{
	static char c;
	template<typename T>
	inline void read(T& x)
	{
		x=0,c=getchar();
		while(!isdigit(c))c=getchar();
		while(isdigit(c))x=x*10+c-'0',c=getchar();
	}
}
using FastIO::read;
const int maxn=100005;
#define lson p[id<<1]
#define rson p[id<<1|1]

struct node
{
	int l,r,sum,ml1,mr1,mx1,ml0,mr0,mx0,tag;
	bool rev;
	inline void setv(int _)
	{
		tag=_+1,rev=0;
		if(_)sum=ml1=mr1=mx1=r-l+1,ml0=mr0=mx0=0;
		else sum=ml1=mr1=mx1=0,ml0=mr0=mx0=r-l+1;
	}
	inline void rvs()
	{
		rev^=1,sum=r-l+1-sum;
		swap(ml1,ml0),swap(mr1,mr0),swap(mx1,mx0);
	}
}p[maxn<<2];
int n,m;
#define pushup(id) p[id]=merge(lson,rson)

inline node merge(node a,node b)
{
	node c;
	c.l=a.l,c.r=b.r,c.tag=c.rev=0,c.sum=a.sum+b.sum;
	c.ml0=a.ml0;if(a.ml0==a.r-a.l+1)c.ml0+=b.ml0;
	c.mr0=b.mr0;if(b.mr0==b.r-b.l+1)c.mr0+=a.mr0;
	c.mx0=max(max(a.mx0,b.mx0),a.mr0+b.ml0);
	c.ml1=a.ml1;if(a.ml1==a.r-a.l+1)c.ml1+=b.ml1;
	c.mr1=b.mr1;if(b.mr1==b.r-b.l+1)c.mr1+=a.mr1;
	c.mx1=max(max(a.mx1,b.mx1),a.mr1+b.ml1);
	return c;
}
inline void pushdown(int id)
{
	if(p[id].l==p[id].r){p[id].tag=p[id].rev=0;return;}
	if(p[id].tag)lson.setv(p[id].tag-1),rson.setv(p[id].tag-1),p[id].tag=0;
	if(p[id].rev)lson.rvs(),rson.rvs(),p[id].rev=0;
}
inline void reverse(int l,int r,int id)
{
	pushdown(id);
	if(p[id].l==l&&p[id].r==r)return p[id].rvs();	
	int mid=p[id].l+p[id].r>>1;
	if(r<=mid)reverse(l,r,id<<1);
	else if(l>mid)reverse(l,r,id<<1|1);
	else reverse(l,mid,id<<1),reverse(mid+1,r,id<<1|1);
	pushup(id);
}
inline void insert(int l,int r,int _,int id)
{
	pushdown(id);
	if(p[id].l==l&&p[id].r==r)return p[id].setv(_);
	int mid=p[id].r+p[id].l>>1;
	if(r<=mid)insert(l,r,_,id<<1);
	else if(l>mid)insert(l,r,_,id<<1|1);
	else insert(l,mid,_,id<<1),insert(mid+1,r,_,id<<1|1);
	pushup(id);
}
inline void build(int l,int r,int id)
{
	p[id].l=l,p[id].r=r;
	if(l==r)
	{
		read(p[id].sum);
		if(p[id].sum)p[id].ml1=p[id].mr1=p[id].mx1=1;
		else p[id].ml0=p[id].mr0=p[id].mx0=1;
		return;
	}
	int mid=l+r>>1;
	build(l,mid,id<<1),build(mid+1,r,id<<1|1),pushup(id);
}
inline int ask(int l,int r,int id)
{
	pushdown(id);
	if(p[id].l==l&&p[id].r==r)return p[id].sum;
	int mid=p[id].l+p[id].r>>1;
	if(r<=mid)return ask(l,r,id<<1);
	else if(l>mid)return ask(l,r,id<<1|1);
	else return ask(l,mid,id<<1)+ask(mid+1,r,id<<1|1);
}
inline node ask1(int l,int r,int id)
{
	pushdown(id);
	if(p[id].l==l&&p[id].r==r)return p[id];
	int mid=p[id].l+p[id].r>>1;
	if(r<=mid)return ask1(l,r,id<<1);
	else if(l>mid)return ask1(l,r,id<<1|1);
	else return merge(ask1(l,mid,id<<1),ask1(mid+1,r,id<<1|1));
}

int main()
{
	read(n),read(m),build(1,n,1);
	for(int i=1,op,a,b;i<=m;i++)
	{
		read(op),read(a),read(b),a++,b++;
		if(op<2)insert(a,b,op,1);
		else if(op==2)reverse(a,b,1);
		else if(op==3)printf("%d\n",ask(a,b,1));
		else printf("%d\n",ask1(a,b,1).mx1);
	}
	return 0;
}
