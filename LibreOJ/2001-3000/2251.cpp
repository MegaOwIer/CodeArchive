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
const int maxn=100005,mod=998244353;

int N,M,ans,p,Y1,Y2,v,l,r;
int Root[maxn<<2],I_cnt,I_ls[maxn*500],I_rs[maxn*500],val[maxn*500];

inline int Pow(LL a,int b)
{
	LL ans=1;
	for(;b;b>>=1,a=a*a%mod)if(b&1)ans=ans*a%mod;
	return ans;
}
void I_update(int &o,int l,int r,int L=0,int R=N)
{
	if(l>r)return;
	if(!o)o=++I_cnt;
	if(L==l&&r==R){val[o]=((LL)val[o]*(1-v)+(LL)v*(1-val[o]))%mod;return;}
	int mid=L+R>>1;
	if(r<=mid)I_update(I_ls[o],l,r,L,mid);
	else if(l>mid)I_update(I_rs[o],l,r,mid+1,R);
	else I_update(I_ls[o],l,mid,L,mid),I_update(I_rs[o],mid+1,r,mid+1,R);
}
void O_update(int o,int l,int r,int L=0,int R=N)
{
	if(l>r)return;
	if(L==l&&r==R)return I_update(Root[o],Y1,Y2);
	int mid=L+R>>1;
	if(r<=mid)O_update(o<<1,l,r,L,mid);
	else if(l>mid)O_update(o<<1|1,l,r,mid+1,R);
	else O_update(o<<1,l,mid,L,mid),O_update(o<<1|1,mid+1,r,mid+1,R);
}
LL I_query(int o,int pos)
{
	if(!o)return 0;
	LL ans=0,tmp;
	for(int L=0,R=N,id=o,mid;id;)
	{
		tmp=val[id],mid=L+R>>1;
		ans=(ans*(1-tmp)+tmp*(1-ans))%mod;
		if(L==R)break;
		if(pos<=mid)id=I_ls[id],R=mid;
		else id=I_rs[id],L=mid+1;
	}
	return ans;
}
LL O_query(int o,int pos)
{
	if(!o)return 0;
	LL ans=0,tmp;
	for(int L=0,R=N,id=o,mid;id;)
	{
		tmp=I_query(Root[id],r),mid=L+R>>1;
		ans=(ans*(1-tmp)+tmp*(1-ans))%mod;
		if(L==R)break;
		if(pos<=mid)id=id<<1,R=mid;
		else id=id<<1|1,L=mid+1;
	}
	return ans;
}

int main()
{
	read(N),read(M);
	for(int i=1,op;i<=M;i++)
	{
		read(op),read(l),read(r);
		if(op==1)
		{
			p=Pow(r-l+1,mod-2);
			Y1=1,Y2=l-1,v=p,O_update(1,l,r);
			Y1=r+1,Y2=N,O_update(1,l,r);
			Y1=l,Y2=r,O_update(1,1,l-1);
			O_update(1,r+1,N);
			v=p*2,O_update(1,l,r);
			Y1=1,Y2=l-1,v=1,O_update(1,0,0);
			Y1=r+1,Y2=N,O_update(1,0,0);
			Y1=l,Y2=r,v=1-p,O_update(1,0,0);
		}
		else write((mod+1-O_query(1,l-1))%mod);
	}
	cerr<<I_cnt;
	return 0;
}
