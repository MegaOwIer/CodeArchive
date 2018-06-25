#include<bits/stdc++.h>
using namespace std;
const int MX=100005;

int N,a[MX],M,l,r,R,ans;
struct nulltag{};
struct Segment
{
	Segment *l,*r;
	int val;
	Segment(nulltag):l(this),r(this),val(0){}
	Segment();	
}*root[MX],*null=new Segment(nulltag());

inline Segment::Segment():l(null),r(null),val(0){}

inline void read(int& x)
{
	static char c;
	x=0,c=getchar();
	while(!isdigit(c))c=getchar();
	while(isdigit(c))x=x*10+c-'0',c=getchar();
}
inline void insert(Segment* &o,Segment *p,int pos,int L,int R)
{
	o=new Segment;
	o->val=p->val+pos;
	if(L==R)return;
	int mid=L+R>>1;
	if(pos<=mid)insert(o->l,p->l,pos,L,mid),o->r=p->r;
	else insert(o->r,p->r,pos,mid+1,R),o->l=p->l;
}
inline int query(Segment *o,Segment *p,int r,int L,int R)
{
	if(L==R)return o->val-p->val;
	int mid=L+R>>1;
	if(r<=mid)return query(o->l,p->l,r,L,mid);
	else return o->l->val-p->l->val+query(o->r,p->r,r,mid+1,R);
}

int main()
{
	read(N),root[0]=null;
	for(int i=1;i<=N;i++)
		read(a[i]),insert(root[i],root[i-1],a[i],1,1e9);
	for(read(M);M--;)
	{
		read(l),read(r),R=1,ans=0;
		ans=query(root[r],root[l-1],R,1,1e9);
		while(ans>=R&&R!=1000000000)
		{
			R=min(1000000000,ans+1);
			ans=query(root[r],root[l-1],R,1,1e9);
		}
		printf("%d\n",ans+1);
	}
	return 0;
}
