#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+5;

struct node{int l,r,mx,sum,ml,mr;}p[maxn<<2];
int f,n,m,a[maxn];
char c;

inline void read(int& x)
{
	f=1,x=0,c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c))x=x*10+c-'0',c=getchar();x*=f;
}
inline void pushup(int id)
{
	p[id].sum=p[id<<1].sum+p[id<<1|1].sum;
	p[id].mx=max(p[id<<1].mx,max(p[id<<1|1].mx,p[id<<1].mr+p[id<<1|1].ml));
	p[id].ml=max(p[id<<1].ml,p[id<<1].sum+p[id<<1|1].ml);
	p[id].mr=max(p[id<<1|1].mr,p[id<<1].mr+p[id<<1|1].sum);
}
inline void build(int l,int r,int id)
{
	p[id].l=l,p[id].r=r;
	if(l==r){p[id].sum=p[id].ml=p[id].mr=p[id].mx=a[l];return;}
	int mid=l+r>>1;
	build(l,mid,id<<1),build(mid+1,r,id<<1|1),pushup(id);
}
inline void change(int l,int id)
{
	if(p[id].l==l&&p[id].r==l){p[id].sum=p[id].ml=p[id].mr=p[id].mx=a[l];return;}
	int mid=p[id].l+p[id].r>>1;
	if(l<=mid)change(l,id<<1);
	else change(l,id<<1|1);
	pushup(id);
}
inline node ask(int l,int r,int id)
{
	if(p[id].l==l&&p[id].r==r)return p[id];
	int mid=p[id].l+p[id].r>>1;
	if(mid>=r)return ask(l,r,id<<1);
	else if(mid<l)return ask(l,r,id<<1|1);
	else
	{
		node ls=ask(l,mid,id<<1),rs=ask(mid+1,r,id<<1|1),res;
		res.sum=ls.sum+rs.sum;
		res.mx=max(ls.mx,max(rs.mx,ls.mr+rs.ml));
		res.ml=max(ls.ml,ls.sum+rs.ml);
		res.mr=max(rs.mr,ls.mr+rs.sum);
		return res;
	}
}

int main()
{
	read(n),read(m);
	for(int i=1;i<=n;i++)read(a[i]);build(1,n,1);
	for(int i=1,opt,u,v;i<=m;i++)
	{
		read(opt),read(u),read(v);
		if(opt==1){if(u>v)swap(u,v);printf("%d\n",ask(u,v,1).mx);}
		else a[u]=v,change(u,1);
	}
	return 0;
}
