#include<cstdio>
#include<ctime>
#include<cstdlib>
#include<cctype>
using namespace std;
namespace FastIO
{
	static char c;
	static int top,buf[12],f;
	template<typename T>
	inline void read(T& x)
	{
		x=0,c=getchar(),f=1;
		while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
		while(isdigit(c))x=x*10+c-'0',c=getchar();x*=f;
	}
	template<typename T>
	inline void write(T x,int f=0)
	{
		top=0;
		if(x<0)putchar('-'),x=-x;
		do buf[top++]=x%10,x/=10;while(x);
		for(int i=top-1;~i;i--)putchar(buf[i]+48);
		if(f)putchar(f&1?' ':'\n');
	}
}
using FastIO::read;
using FastIO::write;

struct Treap_Node
{
	int siz,key,fix;
	Treap_Node *fa,*son[2];
	Treap_Node(){}
	Treap_Node(int _,Treap_Node* f):siz(1),key(_),fix(rand()),fa(f){son[0]=son[1]=NULL;}
	inline bool dir(){return this==fa->son[1];}
	inline bool cmp(int _){return _>=key;}
	inline void maintain()
	{
		siz=1;
		for(int i=0;i<2;i++)if(son[i])siz+=son[i]->siz;
	}
}*root;
int n,m,a[30005];

inline void rotate(Treap_Node* o,int d)
{
	Treap_Node* tmp=o->son[d];
	tmp->fa=o->fa;
	if(o->fa)o->fa->son[o->dir()]=tmp;
	else root=tmp;
	o->son[d]=tmp->son[d^1];
	if(tmp->son[d^1])tmp->son[d^1]->fa=o;
	o->fa=tmp,tmp->son[d^1]=o;
	o->maintain(),tmp->maintain();
}
inline void insert(Treap_Node* &o,Treap_Node* p,int val)
{
	if(!o){o=new Treap_Node(val,p);return;}
	int d=o->cmp(val);
	insert(o->son[d],o,val);
	if(o->son[d]->fix>o->fix)rotate(o,d);
	o->maintain();
}
inline int Kth(int rank)
{
	int del;
	Treap_Node* o=root;
	while(1)
	{
		del=1;
		if(o->son[0])del+=o->son[0]->siz;
		if(del>rank)o=o->son[0];
		else if(del==rank)return o->key;
		else rank-=del,o=o->son[1];
	}
}

int main()
{
	srand(time(NULL));
	read(n),read(m);
	for(int i=1;i<=n;i++)read(a[i]);
	for(int i=1,index=1,u;i<=m;i++)
	{
		read(u);
		for(;index<=u;index++)insert(root,NULL,a[index]);
		write(Kth(i),2);
	}
	return 0;
}
