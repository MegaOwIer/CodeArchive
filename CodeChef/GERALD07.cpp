#include<bits/stdc++.h>
using namespace std;
const int MX=200005;

struct nulltag{};
struct edge{int u,v;}e[MX];
int N,M,K,st[MX],ans,T,cnt;
struct Splay
{
	Splay *son[2],*fa;
	int mn,id;
	bool rev;
	void init()
	{
		rev=0,fa=0,son[0]=son[1]=0;
		mn=id=MX;
	}
	void maintain()
	{
		mn=id;
		if(son[0]&&son[0]->mn<mn)mn=son[0]->mn;
		if(son[1]&&son[1]->mn<mn)mn=son[1]->mn;
	}
	void pushdown()
	{
		if(rev)
		{
			if(son[0])son[0]->rev^=1;
			if(son[1])son[1]->rev^=1;
			rev=0,swap(son[0],son[1]);
		}
	}
	bool isroot(){return !fa||(fa->son[0]!=this&&fa->son[1]!=this);}
	int dir(){return fa->son[1]==this;}
}Node[MX<<1],*stk[MX<<1],**top=stk;
struct Segment
{
	Segment *l,*r;
	int cnt;
	Segment(int);
	Segment(nulltag):l(this),r(this),cnt(0){}
	void* operator new(size_t);
}*root[MX],*null=new Segment(nulltag());

inline Segment::Segment(int v=0):l(null),r(null),cnt(v){}
inline void* Segment::operator new(size_t)
{
	static Segment Pool[MX<<5];
	return Pool+(::cnt++);
}

inline void read(int& x)
{
	static char c;
	x=0,c=getchar();
	while(!isdigit(c))c=getchar();
	while(isdigit(c))x=x*10+c-'0',c=getchar();
}
inline Splay* find(Splay *u)
{
	while(u->fa)u=u->fa;
	return u;
}
inline void rotate(Splay *o)
{
	Splay *p=o->fa;
	int d=o->dir();
	p->son[d]=o->son[d^1];
	if(o->son[d^1])o->son[d^1]->fa=p;
	o->fa=p->fa;
	if(!p->isroot())p->fa->son[p->dir()]=o;
	p->fa=o,o->son[d^1]=p;
	p->maintain();
}
inline void splay(Splay *o)
{
	Splay *p=o;
	*++top=o;
	while(!p->isroot())*++top=p=p->fa;
	while(top!=stk)(*top--)->pushdown();
	while(!o->isroot())
	{
		p=o->fa;
		if(!p->isroot())rotate(p->dir()==o->dir()?p:o);
		rotate(o);
	}
	o->maintain();
}
inline void access(Splay *o)
{
	for(Splay* p=0;o;p=o,o=o->fa)
		splay(o),o->son[1]=p,o->maintain();
}
inline void makeroot(Splay *u){access(u),splay(u),u->rev^=1;}
inline int query(Splay *u,Splay *v)
{
	makeroot(u),access(v),splay(v);
	return v->mn;
}
inline void link(Splay *u,Splay *v){makeroot(v),v->fa=u;}
inline void cut(Splay *u,Splay *v)
{
	makeroot(u),access(v),splay(v);
	v->son[0]=u->fa=0;
}
inline void insert(Segment* &o,Segment *p,int pos,int L,int R)
{
	o=new Segment(p->cnt+1);
	if(L==R)return;
	int mid=L+R>>1;
	if(pos<=mid)insert(o->l,p->l,pos,L,mid),o->r=p->r;
	else insert(o->r,p->r,pos,mid+1,R),o->l=p->l;
}
inline int query(Segment *o,Segment *p,int r,int L,int R)
{
	if(R==r)return o->cnt-p->cnt;
	int mid=L+R>>1;
	if(r<=mid)return query(o->l,p->l,r,L,mid);
	else return o->l->cnt-p->l->cnt+query(o->r,p->r,r,mid+1,R);
}

int main()
{
	read(T),root[0]=null;
	while(T--)
	{
		read(N),read(M),read(K),cnt=1;
		for(int i=1;i<=N+M;i++)Node[i].init();
		for(int i=1,t;i<=M;i++)
		{
			read(e[i].u),read(e[i].v),st[i]=0;
			if(e[i].u==e[i].v){st[i]=i;continue;}
			else if(find(&Node[e[i].u])==find(&Node[e[i].v]))
			{
				st[i]=query(&Node[e[i].u],&Node[e[i].v]);
				cut(&Node[e[st[i]].u],&Node[st[i]+N]);
				cut(&Node[e[st[i]].v],&Node[st[i]+N]);
			}
			Node[i+N].mn=Node[i+N].id=i;
			link(&Node[e[i].u],&Node[i+N]);
			link(&Node[e[i].v],&Node[i+N]);
		}
		for(int i=1;i<=M;i++)insert(root[i],root[i-1],st[i],0,M);
		for(int i=1,l,r;i<=K;i++)
		{
			read(l),read(r);
			printf("%d\n",ans=N-query(root[r],root[l-1],l-1,0,M));
		}
	}
	return 0;
}
