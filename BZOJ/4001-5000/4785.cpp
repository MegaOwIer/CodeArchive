#include<bits/stdc++.h>
using namespace std;
namespace FastIO
{
	static char c;
	static int top,buf[20];
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
		putchar('\n');
	}
}
using FastIO::read;
using FastIO::write;
typedef long long LL;
const int MX=100005,mod=998244353;

int N,M,ans,p,Y1,Y2,v;
struct O_Segment
{
	struct I_Segment
	{
		I_Segment *ls,*rs;
		int val;
		I_Segment():ls(NULL),rs(NULL),val(0){}
		inline int query(int pos,int L=0,int R=N)
		{
			if(!this)return 0;
			LL ans=0;
			if(L==R)return val;
			int mid=L+R>>1;
			if(mid>=pos)ans=ls->query(pos,L,mid);
			else ans=rs->query(pos,mid+1,R);
			return (ans*(1-val+mod)+val*(1-ans+mod))%mod;
		}
		inline void upd(LL v){val=(val*(1-v+mod)+v*(1-val+mod))%mod;}
	}*root;
	O_Segment *ls,*rs;
	O_Segment():root(),ls(NULL),rs(NULL){}
	inline LL query(int l,int r,int L=0,int R=N)
	{
		if(!this)return 0;
		LL ans=0,tmp=root->query(r);
		if(L==R)return tmp;
		int mid=L+R>>1;
		if(l<=mid)ans=ls->query(l,r,L,mid);
		else ans=rs->query(l,r,mid+1,R);
		return (ans*(1-tmp+mod)+tmp*(1-ans+mod))%mod;
	}
	inline void update(I_Segment* &o,int l,int r,int L=0,int R=N)
	{
		if(l>r)return;
		if(!o)o=new I_Segment;
		if(L==l&&r==R)return o->upd(v);
		int mid=L+R>>1;
		if(r<=mid)update(o->ls,l,r,L,mid);
		else if(l>mid)update(o->rs,l,r,mid+1,R);
		else update(o->ls,l,mid,L,mid),update(o->rs,mid+1,r,mid+1,R);
	}
}*root;

inline int Pow(LL a,int b)
{
	LL ans=1;
	for(;b;b>>=1,a=a*a%mod)if(b&1)ans=ans*a%mod;
	return ans;
}
inline void update(O_Segment* &o,int l,int r,int L=0,int R=N)
{
	if(l>r)return;
	if(!o)o=new O_Segment;
	if(L==l&&r==R)return o->update(o->root,Y1,Y2);
	int mid=L+R>>1;
	if(r<=mid)update(o->ls,l,r,L,mid);
	else if(l>mid)update(o->rs,l,r,mid+1,R);
	else update(o->ls,l,mid,L,mid),update(o->rs,mid+1,r,mid+1,R);
}

int main()
{
	read(N),read(M);
	for(int i=1,op,l,r;i<=M;i++)
	{
		read(op),read(l),read(r);
		if(op==1)
		{
			p=Pow(r-l+1,mod-2);
			Y1=1,Y2=l-1,v=p,update(root,l,r);
			Y1=r+1,Y2=N,update(root,l,r);
			Y1=l,Y2=r,update(root,1,l-1);
			update(root,r+1,N);
			v=p*2,update(root,l,r);
			Y1=1,Y2=l-1,v=1,update(root,0,0);
			Y1=r+1,Y2=N,update(root,0,0);
			Y1=l,Y2=r,v=1-p,update(root,0,0);
		}
		else write((mod+1-root->query(l-1,r))%mod);
	}
	return 0;
}
