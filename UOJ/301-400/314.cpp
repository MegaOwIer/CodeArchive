#include<bits/stdc++.h>
using namespace std;
const int MX=1000005;

namespace FastIO
{
	const int MXL=200000;
	class FastIn
	{
	private:
		char IBF[MXL],*p1,*p2,c;
		int f;
		char getchar(){return p1==p2?(p2=(p1=IBF)+fread(IBF,1,MXL,stdin)),p1==p2?EOF:*p1++:*p1++;}
	public:
		FastIn():p1(IBF),p2(IBF){}
		template<typename T>void operator()(T& x)
		{
			x=0,c=getchar(),f=0;
			while(!isdigit(c)){if(c=='-')f=1;c=getchar();}
			while(isdigit(c))x=x*10+c-'0',c=getchar();
			if(f)x=-x;
		}
	};
}
FastIO::FastIn IN;

int n,t,op,x,y,M;
unsigned val[MX<<2];
char O[MX<<1],*p3=O;

inline void pushup(int id)
{
	if(val[id<<1]==val[id<<1|1])val[id]=val[id<<1];
	else val[id]=1;
}
bool inc1(int id,int L,int R)
{
	if(L==R)return !(++val[id]);
	if(!~val[id])return val[id]=0,1;
	if(!val[id]||!~val[id])val[id<<1]=val[id<<1|1]=val[id];
	int mid=L+R>>1;
	inc1(id<<1,L,mid)&&inc1(id<<1|1,mid+1,R);
	pushup(id);
	return 0;
}
bool inc(int pos,unsigned v,int id,int L=0,int R=M)
{
	bool ret;
	if(L==R)return (val[id]+=v)<v;
	if(!val[id]||!~val[id])val[id<<1]=val[id<<1|1]=val[id];
	int mid=L+R>>1;
	if(pos<=mid)
		ret=inc(pos,v,id<<1,L,mid)&&inc1(id<<1|1,mid+1,R);
	else ret=inc(pos,v,id<<1|1,mid+1,R);
	pushup(id);
	return ret;
}
bool dec1(int id,int L,int R)
{
	if(L==R)return !~(--val[id]);
	if(!val[id])return val[id]=-1;
	if(!val[id]||!~val[id])val[id<<1]=val[id<<1|1]=val[id];
	int mid=L+R>>1;
	dec1(id<<1,L,mid)&&dec1(id<<1|1,mid+1,R);
	pushup(id);
	return 0;
}
bool dec(int pos,unsigned v,int id,int L=0,int R=M)
{
	bool ret;
	if(L==R)return ret=val[id]<v,val[id]-=v,ret;
	if(!val[id]||!~val[id])val[id<<1]=val[id<<1|1]=val[id];
	int mid=L+R>>1;
	if(pos<=mid)
		ret=dec(pos,v,id<<1,L,mid)&&dec1(id<<1|1,mid+1,R);
	else ret=dec(pos,v,id<<1|1,mid+1,R);
	pushup(id);
	return ret;
}
inline void insert(int _x,int y)
{
	if(!_x)return;
	static unsigned x,p1,p2;
	static bool neg;
	static int pos,l1,l2;
	neg=_x<0,x=neg?-_x:_x;
	pos=y>>5,l1=y&31,l2=32-l1;
	p1=(l2==32)?x:x&((1<<l2)-1);
	p2=(l2==32)?0:x>>l2;
	if(p1)neg?dec(pos,p1<<l1,1):inc(pos,p1<<l1,1);
	if(p2)neg?dec(pos+1,p2,1):inc(pos+1,p2,1);
}
unsigned query(int pos,int id,int L=0,int R=M)
{
	if(L==R)return val[id];
	if(!val[id]||!~val[id])val[id<<1]=val[id<<1|1]=val[id];
	int mid=L+R>>1;
	if(pos<=mid)return query(pos,id<<1,L,mid);
	else return query(pos,id<<1|1,mid+1,R);
}

int main()
{
	IN(n),IN(t),IN(t),IN(t);
	M=((n*30)>>5)+5;
	while(n--)
	{
		IN(op);
		if(op&1)IN(x),IN(y),insert(x,y);
		else IN(x),*p3++=48+((query(x>>5,1)>>(x&31))&1),*p3++='\n';
	}
	fwrite(O,1,p3-O,stdout);
	return 0;
}