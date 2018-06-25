#include<bits/stdc++.h>
using namespace std;
namespace FastIO
{
	static char c;
	static int f,top,buf[12];
	template<typename T>inline void read(T& x)
	{
		x=0,c=getchar(),f=1;
		while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
		while(isdigit(c))x=x*10+c-'0',c=getchar();x*=f;
	}
	template<typename T>inline void write(T x)
	{
		if(x<0)putchar('-'),x=-x;top=0;
		do buf[++top]=x%10,x/=10;while(x);
		while(top)putchar(48+buf[top--]);
		putchar('\n');
	}
}
using FastIO::read;
using FastIO::write;
typedef long long LL;
const int maxn=100005,INF=-2147483648;
#define lson p[id<<1]
#define rson p[id<<1|1]
#define cur p[id<<1|i]

struct Node
{
	int mx,ptg,ctg,_mx,_ptg,_ctg;
	Node(){ptg=_ptg=0,_ctg=ctg=INF;}
	inline void setv(int _){ptg=0,ctg=mx=_,_mx=max(_mx,mx);}
	inline void plus(int _){mx+=_,_mx=max(_mx,mx),ptg+=_;}
}p[maxn<<2];
int T,E;
char op;

inline void pushup(int id)
{
	p[id].mx=max(lson.mx,rson.mx);
	p[id]._mx=max(lson._mx,rson._mx);
}
inline void pushdown(int id)
{
	for(int i=0;i<2;i++)
	{
		cur._mx=max(cur._mx,max(p[id]._ctg,cur.mx+p[id]._ptg));
		if(cur.ctg==INF)cur._ptg=max(cur._ptg,cur.ptg+p[id]._ptg);
		else cur._ctg=max(cur._ctg,cur.ctg+p[id]._ptg);
		if(p[id].ptg)
		{
			if(cur.ctg!=INF)cur.ctg+=p[id].ptg;
			else cur.ptg+=p[id].ptg;
			cur.mx+=p[id].ptg;
		}
		if(p[id].ctg!=INF)cur.mx=cur.ctg=p[id].ctg,cur.ptg=0;
		cur._ctg=max(cur._ctg,max(cur.ctg,p[id]._ctg));
		cur._ptg=max(cur._ptg,cur.ptg);
	}
	p[id].ptg=p[id]._ptg=0;
	p[id].ctg=p[id]._ctg=INF;
}
inline void build(int l,int r,int id)
{
	if(l==r)
	{
		read(p[id].mx),p[id]._mx=p[id].mx;
		return;
	}
	int mid=l+r>>1;
	build(l,mid,id<<1),build(mid+1,r,id<<1|1),pushup(id);
}
inline void ins(int l,int r,int _,int id,int f=0,int L=1,int R=T)
{
	if(L!=R)pushdown(id);
	if(l==L&&R==r)
	{
		if(f)p[id].ctg=p[id]._ctg=p[id].mx=_;
		else p[id].ptg+=_,p[id].mx+=_,p[id]._ptg+=_;
		p[id]._mx=max(p[id]._mx,p[id].mx);
		return;
	}
	int mid=L+R>>1;
	if(r<=mid)ins(l,r,_,id<<1,f,L,mid);
	else if(l>mid)ins(l,r,_,id<<1|1,f,mid+1,R);
	else ins(l,mid,_,id<<1,f,L,mid),ins(mid+1,r,_,id<<1|1,f,mid+1,R);
	pushup(id);
}
inline int ask(int l,int r,int id,int f=0,int L=1,int R=T)
{
	if(L!=R)pushdown(id);
	if(l==L&&r==R)return f?p[id]._mx:p[id].mx;
	int mid=L+R>>1;
	if(r<=mid)return ask(l,r,id<<1,f,L,mid);
	else if(l>mid)return ask(l,r,id<<1|1,f,mid+1,R);
	else return max(ask(l,mid,id<<1,f,L,mid),ask(mid+1,r,id<<1|1,f,mid+1,R));
}

int main()
{
	read(T),build(1,T,1),read(E);
	for(int i=1,x,y,z;i<=E;i++)
	{
		do op=getchar();while(!isalpha(op));
		read(x),read(y);
		if(op=='Q')write(ask(x,y,1));
		else if(op=='A')write(ask(x,y,1,1));
		else if(op=='P')read(z),ins(x,y,z,1);
		else read(z),ins(x,y,z,1,1);
	}
	return 0;
}
