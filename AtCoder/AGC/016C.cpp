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

int H,W,h,w,a[505];

int main()
{
	read(H),read(W),read(h),read(w);
	if(H%h==0&&W%w==0)return puts("No"),0;
	puts("Yes");
	if(W%w)
	{
		for(int i=1;i<=W;i+=w)a[i]=1e9-1;
		for(int i=w;i<=W;i+=w)a[i]=-1e9;
		for(int i=1;i<=H;i++)
		{
			for(int j=1;j<=W;j++)write(a[j],1);
			putchar('\n');
		}
	}
	else
	{
		for(int i=1;i<=H;i+=h)a[i]=1e9-1;
		for(int i=h;i<=H;i+=h)a[i]=-1e9;
		for(int i=1;i<=H;i++)
		{
			for(int j=1;j<=W;j++)write(a[i],1);
			putchar('\n');
		}
	}
	return 0;
}
