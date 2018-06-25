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
		do buf[++top]=x%10,x/=10;while(x);
		while(top)putchar(48+buf[top--]);
		putchar(' ');
	}
}
using FastIO::read;
using FastIO::write;
const int maxn=200005;

char Pool[200000000],*p=Pool;
inline void* operator new (size_t SIZ){return (p+=SIZ)-SIZ;}
inline void operator delete(void*){}

struct Segment
{
	int cnt;
	Segment *son[2];
	Segment():cnt(0){son[0]=son[1]=NULL;}
	void maintain()
	{
		cnt=0;
		for(int i=0;i<2;i++)if(son[i])cnt+=son[i]->cnt;
	}
}*root[105];
int n,Q,a[maxn];

#define lson ->son[0]
#define rson ->son[1]
inline void insert(Segment* &o,int pos,int L=1,int R=n)
{
	if(!o)o=new Segment;
	if(L==R){o->cnt=1;return;}
	int mid=L+R>>1;
	if(mid>=pos)insert(o lson,pos,L,mid);
	else insert(o rson,pos,mid+1,R);
	o->maintain();
}
#define search_down \
int mid=L+R>>1; \
if(mid>=r)change(pre lson,o lson,l,r,L,mid); \
else if(l>mid)change(pre rson,o rson,l,r,mid+1,R); \
else change(pre lson,o lson,l,mid,L,mid),change(pre rson,o rson,mid+1,r,mid+1,R);
inline void change(Segment* &pre,Segment* &o,int l,int r,int L=1,int R=n)
{
	if(!pre||!pre->cnt)return;
	if(!o)o=new Segment;
	if(L==l&&R==r)
	{
		if(!o->cnt){o=pre,pre=NULL;return;}
		search_down;
		o->maintain(),pre=NULL;
		return;
	}
	search_down;
	o->maintain(),pre->maintain();
}
#undef search_down
inline void search(Segment* o,int id,int L=1,int R=n)
{
	if(!o||!o->cnt)return;
	if(L==R)a[L]=id;
	int mid=L+R>>1;
	search(o lson,id,L,mid),search(o rson,id,mid+1,R);
}
#undef lson
#undef rson

int main()
{
	read(n);
	for(int i=1,a;i<=n;i++)read(a),insert(root[a],i);
	read(Q);
	for(int i=1,l,r,x,y;i<=Q;i++)
	{
		read(l),read(r),read(x),read(y);
		if(x==y)continue;
		change(root[x],root[y],l,r);
	}
	for(int i=1;i<=100;i++)search(root[i],i);
	for(int i=1;i<=n;i++)write(a[i]);
	return 0;
}
