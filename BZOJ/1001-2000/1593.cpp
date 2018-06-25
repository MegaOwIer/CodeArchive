#include<bits/stdc++.h>
using namespace std;
namespace fastIO
{
	static int f;
	static char c;
	template<typename T>
	inline void read(T& x)
	{
		x=0,c=getchar(),f=1;
		while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
		while(isdigit(c))x=x*10+c-'0',c=getchar();x*=f;
	}
	#define getalpha(x) do x=getchar();while(!isalpha(x))
}
using namespace fastIO;
const int maxn=50005;
#define lson p[id<<1]
#define rson p[id<<1|1]

struct node{int l,r,lm,rm,mx,fl;}p[maxn<<2];
int n,m,ans;

inline void pushup(int id)
{
	p[id].mx=max(max(lson.mx,rson.mx),lson.rm+rson.lm);
	p[id].lm=lson.lm+((lson.lm==lson.r-lson.l+1)?rson.lm:0);
	p[id].rm=rson.rm+((rson.rm==rson.r-rson.l+1)?lson.rm:0);
}
inline void pushdown(int id)
{
	if(!p[id].fl)return;
	if(p[id].fl==1)
	{
		lson.fl=rson.fl=1;
		lson.lm=lson.rm=lson.mx=lson.r-lson.l+1;
		rson.lm=rson.rm=rson.mx=rson.r-rson.l+1;	
	}
	else
	{
		lson.fl=rson.fl=2;
		lson.lm=lson.rm=lson.mx=0;
		rson.lm=rson.rm=rson.mx=0;
	}
	p[id].fl=0;
}
inline void build(int l,int r,int id)
{
	p[id]=(node){l,r,r-l+1,r-l+1,r-l+1,0};
	if(l==r)return;int mid=l+r>>1;
	build(l,mid,id<<1),build(mid+1,r,id<<1|1);
}
inline int ask(int val,int id)
{
	pushdown(id);
	if(p[id].l==p[id].r)return p[id].l;
	if(lson.mx>=val)return ask(val,id<<1);
	if(lson.rm+rson.lm>=val)return lson.r-lson.rm+1;
	return ask(val,id<<1|1);
}
inline void insert(int l,int r,int f,int id)
{
	if(p[id].l==l&&p[id].r==r){p[id].fl=f,p[id].lm=p[id].rm=p[id].mx=(f&1)?r-l+1:0;return;}
	pushdown(id);
	int mid=p[id].l+p[id].r>>1;
	if(r<=mid)insert(l,r,f,id<<1);
	else if(mid<l)insert(l,r,f,id<<1|1);
	else insert(l,mid,f,id<<1),insert(mid+1,r,f,id<<1|1);
	pushup(id);
}

int main()
{
	read(n),read(m),build(1,n,1);
	for(int i=1,a,b,c;i<=m;i++)
	{
		read(a),read(b);
		if(a==1)
		{
			if(p[1].mx<b)puts("0");
			else ans=ask(b,1),printf("%d\n",ans),insert(ans,ans+b-1,2,1);
		}
		else read(c),insert(b,b+c-1,1,1);
	}
	return 0;
}

