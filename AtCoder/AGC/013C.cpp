#include<bits/stdc++.h>
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
const int maxn=1e5+5;

int N,L,T,st,a[maxn],dt,cc;

int main()
{
	read(N),read(L),read(T),dt=T%L,cc=T/L;
	for(int i=0,w;i<N;i++)
	{
		read(a[i]),read(w);
		if(w==1)
		{
			st=(st+cc)%N;
			a[i]+=dt;
			if(a[i]>=L)a[i]-=L,st=(st+1)%N;
		}
		else
		{
			st=((st-cc)%N+N)%N;
			a[i]-=dt;
			if(a[i]<0)a[i]+=L,st=(st+N-1)%N;
		}
	}
	sort(a,a+N);
	for(int i=st;i<st+N;i++)write(a[i%N],2);
	return 0;
}
