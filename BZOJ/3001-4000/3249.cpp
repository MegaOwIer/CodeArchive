#include<bits/stdc++.h>
using namespace std;
namespace FastIO
{
	static char c;
	static int buf[22],top;
	template<typename T>inline void read(T& x)
	{
		x=0,c=getchar();
		while(!isdigit(c))c=getchar();
		while(isdigit(c))x=x*10+c-'0',c=getchar();
	}
	template<typename T>inline void write(T x)
	{
		top=0;
		do buf[top++]=x%10,x/=10;while(x);
		while(top)putchar(48+buf[--top]);
		putchar('\n');
	}
}
using FastIO::read;
using FastIO::write;
typedef long long LL;

LL gcd(LL,LL);
struct Segment
{
	struct Splay
	{
		Splay *fa,*son[2];
		LL val,GCD;
		int pos;
		Splay(){} 
		Splay(int p,LL v,Splay* f)
		{
			pos=p,val=v,fa=f;
			GCD=v,son[0]=son[1]=NULL;
		}
		inline bool cmp(int _){return _>pos;}
		inline int dir(){return this==fa->son[1];}
		inline void maintain()
		{
			GCD=val;
			if(son[0])GCD=gcd(GCD,son[0]->GCD);
			if(son[1])GCD=gcd(GCD,son[1]->GCD);
		}
	}*root;
	int l,r;
	Segment *son[2];
	Segment(){}
	Segment(int l,int r):l(l),r(r){root=NULL;son[0]=son[1]=NULL;}
	inline void rotate(Splay* o)
	{
		Splay* p=o->fa;
		int d=o->dir();
		p->son[d]=o->son[d^1];
		if(o->son[d^1])o->son[d^1]->fa=p;
		o->fa=p->fa;
		if(p->fa)p->fa->son[p->dir()]=o;
		p->fa=o,o->son[d^1]=p;
		p->maintain();
	}
	inline void splay(Splay* o,const Splay* f)
	{
		Splay* p;
		while(o->fa!=f)
		{
			p=o->fa;
			if(p->fa==f)rotate(o);
			else if(o->dir()==p->dir())rotate(p),rotate(o);
			else rotate(o),rotate(o);
		}
		if(!f)root=o;
		o->maintain();
	}
	inline Splay* Splay_insert(Splay* &o,Splay* p,int pos,LL _)
	{
		if(!o)return o=new Splay(pos,_,p);
		else if(o->pos==pos)
		{
			o->val=_,o->maintain();
			return o;
		}
		else return Splay_insert(o->son[o->cmp(pos)],o,pos,_);
	}
	inline Splay* Find(int pos)
	{
		Splay* tmp=root;
		while(tmp)
		{
			if(tmp->pos==pos)return tmp;
			tmp=tmp->son[tmp->cmp(pos)];
		}
		return NULL;
	}
	inline void insert(int pos)
	{
		Splay *tmp;
		LL __=0;
		for(int i=0;i<2;i++)if(son[i])
		{
			tmp=son[i]->Find(pos);
			if(tmp)__=gcd(__,tmp->val);
		}
		splay(Splay_insert(root,NULL,pos,__),NULL);
	}
	template<typename T>inline Splay* Kth(int _,T cmp)
	{
		Splay* ans=NULL;
		int d;
		for(Splay* o=root;o;o=o->son[d])
		{
			if(cmp(o->pos,_))ans=o;
			if(o->pos!=_)d=o->cmp(_);
			else d=cmp(2,1);
		}
		return ans;
	}
	inline LL query(int l,int r)
	{
		Splay *tmp1=Kth(r,greater<int>()),*tmp2=Kth(l,less<int>());
		if(tmp1)
		{
			splay(tmp1,NULL);
			if(tmp2)
			{
				splay(tmp2,tmp1);
				return root->son[0]->son[1]?root->son[0]->son[1]->GCD:0;
			}
			return root->son[0]?root->son[0]->GCD:0;
		}
		else if(tmp2)
		{
			splay(tmp2,NULL);
			return root->son[1]?root->son[1]->GCD:0;
		}
		else return root?root->GCD:0;
	}
}*root;
int N,M,Q,opt,p,q,u,v;
LL k;

inline LL gcd(LL a,LL b)
{
	while(b)a%=b,swap(a,b);
	return a;
}
void update(int x,int y,LL _,Segment* &o,int L=1,int R=M)
{
	if(!o)o=new Segment(L,R);
	if(L==R)return o->splay(o->Splay_insert(o->root,NULL,x,_),NULL);
	int mid=L+R>>1;
	if(mid>=y)update(x,y,_,o->son[0],L,mid);
	else update(x,y,_,o->son[1],mid+1,R);
	o->insert(x);
}
LL query(int x1,int x2,int y1,int y2,Segment* o,int L=1,int R=M)
{
	if(!o)return 0;
	if(L==y1&&y2==R)return o->query(x1,x2);
	int mid=L+R>>1;
	if(mid>=y2)return query(x1,x2,y1,y2,o->son[0],L,mid);
	else if(mid<y1)return query(x1,x2,y1,y2,o->son[1],mid+1,R);
	else return gcd(query(x1,x2,y1,mid,o->son[0],L,mid),query(x1,x2,mid+1,y2,o->son[1],mid+1,R));
}

int main()
{
	read(N),read(M),read(Q);
	for(int i=1;i<=Q;i++)
	{
		read(opt),read(p),read(q),++p,++q;
		if(opt==1)read(k),update(p,q,k,root);
		else
		{
			read(u),read(v),++u,++v;
			if(u<p)swap(p,u);
			if(v<q)swap(q,v);
			write(query(p,u,q,v,root));
		}
	}
	return 0;
}
