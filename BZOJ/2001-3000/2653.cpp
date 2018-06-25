#include<bits/stdc++.h>
using namespace std;
namespace FastIO
{
	static char c;
	static int top,buf[20];
	template<typename T>
	inline void read(T& x)
	{
		x=0,c=getchar();
		while(!isdigit(c))c=getchar();
		while(isdigit(c))x=x*10+c-'0',c=getchar();
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
const int maxn=20005;

struct node
{
	int sum,l,r,ls,rs;
	inline void set(int _){sum=ls=rs=_;}
}p[maxn<<4];
int n,Q,root[maxn],cnt,ans,q[5],L,R,mid;
pair<int,int> a[maxn];

inline void pushup(int id)
{
	p[id].sum=p[p[id].l].sum+p[p[id].r].sum;
	p[id].ls=max(p[p[id].l].ls,p[p[id].l].sum+p[p[id].r].ls);
	p[id].rs=max(p[p[id].r].rs,p[p[id].r].sum+p[p[id].l].rs);
}
inline void build(int l,int r,int &id)
{
	id=++cnt;
	if(l==r)return p[id].set(1);
	int mid=l+r>>1;
	build(l,mid,p[id].l),build(mid+1,r,p[id].r);
	pushup(id);
}
inline void insert(int last,int& now,int pos,int L=1,int R=n)
{
	if(!now)now=++cnt;
	if(L==R)return p[now].set(-1);
	int mid=L+R>>1;
	if(pos<=mid)insert(p[last].l,p[now].l,pos,L,mid),p[now].r=p[last].r;
	else insert(p[last].r,p[now].r,pos,mid+1,R),p[now].l=p[last].l;
	pushup(now);
}
inline int sum(int id,int l,int r,int L=1,int R=n)
{
	if(l>r)return 0;
	if(l==L&&r==R)return p[id].sum;
	int mid=L+R>>1;
	if(r<=mid)return sum(p[id].l,l,r,L,mid);
	else if(l>mid)return sum(p[id].r,l,r,mid+1,R);
	else return sum(p[id].l,l,mid,L,mid)+sum(p[id].r,mid+1,r,mid+1,R);
}
inline int lt(int id,int l,int r,int L=1,int R=n)
{
	if(L==l&&R==r)return p[id].ls;
	int mid=L+R>>1;
	if(r<=mid)return lt(p[id].l,l,r,L,mid);
	else if(l>mid)return lt(p[id].r,l,r,mid+1,R);
	else return max(lt(p[id].l,l,mid,L,mid),sum(p[id].l,l,mid,L,mid)+lt(p[id].r,mid+1,r,mid+1,R));
}
inline int rt(int id,int l,int r,int L=1,int R=n)
{
	if(L==l&&R==r)return p[id].rs;
	int mid=L+R>>1;
	if(r<=mid)return rt(p[id].l,l,r,L,mid);
	else if(l>mid)return rt(p[id].r,l,r,mid+1,R);
	else return max(rt(p[id].r,mid+1,r,mid+1,R),sum(p[id].r,mid+1,r,mid+1,R)+rt(p[id].l,l,mid,L,mid));
}

int main()
{
	read(n);
	for(int i=1;i<=n;i++)read(a[i].first),a[i].second=i;
	sort(a+1,a+n+1),build(1,n,root[1]);
	for(int i=1;i<=n;i++)insert(root[i],root[i+1],a[i].second);
	read(Q);
	while(Q--)
	{
		for(int i=0;i<4;i++)read(q[i]),(q[i]+=ans)%=n,q[i]++;
		sort(q,q+4),L=1,R=n;
		while(L<=R)
		{
			mid=L+R>>1;
			if(sum(root[mid],q[1]+1,q[2]-1)+rt(root[mid],q[0],q[1])+lt(root[mid],q[2],q[3])>=0)ans=mid,L=mid+1;
			else R=mid-1;
		}
		ans=a[ans].first,write(ans,2);
	}
	return 0;
}
