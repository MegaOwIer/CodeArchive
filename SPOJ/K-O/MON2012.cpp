#include<bits/stdc++.h>
using namespace std;

int ans,M;
struct Segment
{
	Segment *ls,*rs;
	bool tag;
	Segment():ls(NULL),rs(NULL),tag(0){}
	void* operator new (size_t);
	void operator delete(void*);
	int query(int l,int r,int L,int R)
	{
		if(!this)return 0;
		if(tag)return r-l+1;
		int mid=L+R>>1;
		if(r<=mid)return ls->query(l,r,L,mid);
		else if(l>mid)return rs->query(l,r,mid+1,R);
		else return ls->query(l,mid,L,mid)+rs->query(mid+1,r,mid+1,R);
	}
}*root,Pool[6000000];

inline void* Segment::operator new(size_t)
{
	static int cnt=0;
	return Pool+(cnt++);
}
inline void read(int& x)
{
	static char c;
	static int f;
	c=getchar(),x=0,f=0;
	while(!isdigit(c)){if(c=='-')f=1;c=getchar();}
	while(isdigit(c))x=x*10+c-'0',c=getchar();
	if(f)x=-x;
}
inline void insert(Segment* &o,int l,int r,int L,int R)
{
	if(!o)o=new Segment;
	if(o->tag)return;
	if(L==l&&r==R){o->tag=1;return;}
	int mid=L+R>>1;
	if(r<=mid)insert(o->ls,l,r,L,mid);
	else if(l>mid)insert(o->rs,l,r,mid+1,R);
	else insert(o->ls,l,mid,L,mid),insert(o->rs,mid+1,r,mid+1,R);
}

int main()
{
	read(M);
	for(int i=1,op,x,y;i<=M;i++)
	{
		read(op),read(x),read(y);
		x+=ans,y+=ans;
		if(op&1)printf("%d\n",ans=root->query(x,y,1,1e9));
		else insert(root,x,y,1,1e9);
	}
	return 0;
}
