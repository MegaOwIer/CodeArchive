#include<bits/stdc++.h>
using namespace std;
const int MX=200005;
unsigned RD();

int N,M;
pair<int,int> a[MX];
struct Treap
{
	Treap *l,*r;
	int val,cnt,tagv,tagc;
	unsigned rnd;
	Treap(){}
	Treap(int v):l(0),r(0),val(v){tagv=0,cnt=tagc=0,rnd=RD();}
	void pushdown()
	{
		if(tagc)
		{
			if(l)l->tagc+=tagc,l->cnt+=tagc;
			if(r)r->tagc+=tagc,r->cnt+=tagc;
			tagc=0;
		}
		if(tagv)
		{
			if(l)l->tagv+=tagv,l->val+=tagv;
			if(r)r->tagv+=tagv,r->val+=tagv;
			tagv=0;
		}
	}
	void down()
	{
		pushdown();
		if(l)l->down();
		if(r)r->down();
	}
}*root,Node[MX],*r1,*r2,*r3,*r4;

inline unsigned RD()
{
	static unsigned seed=time(NULL);
	return seed^=seed<<17,seed^=seed>>12,seed^=seed<<6;
}
void split(Treap *o,Treap* &x,Treap* &y,int val)
{
	if(!o){x=y=0;return;}
	o->pushdown();
	if(o->val<val)x=o,split(o->r,x->r,y,val);
	else y=o,split(o->l,x,y->l,val);
}
Treap* merge(Treap *x,Treap *y)
{
	if(!x)return y;
	if(!y)return x;
	if(x->rnd<y->rnd)
	{
		x->pushdown();
		x->r=merge(x->r,y);
		return x;
	}
	else
	{
		y->pushdown();
		y->l=merge(x,y->l);
		return y;
	}
}
inline void insert(Treap* &o,Treap *p)
{
	Treap *r1=0,*r2=0;
	split(o,r1,r2,p->val);
	r1=merge(r1,p),o=merge(r1,r2);
}
Treap* dfs(Treap *x,Treap *y)
{
	if(!x)return y;
	x->pushdown();
	y=dfs(x->l,y),y=dfs(x->r,y);
	x->l=x->r=0;
	insert(y,x);
	return y;
}

int main()
{
	scanf("%d",&N);
	for(int i=1,q,c;i<=N;i++)
		scanf("%d%d",&c,&q),a[i]=make_pair(-q,c);
	sort(a+1,a+N+1);
	scanf("%d",&M);
	for(int i=1,u;i<=M;i++)
	{
		scanf("%d",&u);
		Node[i]=Treap(u);
		insert(root,Node+i);
	}
	for(int i=1;i<=N;i++)
	{
		r1=r2=r3=r4=0;
		split(root,r1,r2,a[i].second);
		if(r2)
		{
			r2->val-=a[i].second,r2->tagv-=a[i].second;
			r2->cnt++,r2->tagc++;
		}
		split(r2,r3,r4,a[i].second-1);
		r1=dfs(r3,r1),root=merge(r1,r4);
	}
	root->down();
	for(int i=1;i<=M;i++)printf("%d ",Node[i].cnt);
	return 0;
}
