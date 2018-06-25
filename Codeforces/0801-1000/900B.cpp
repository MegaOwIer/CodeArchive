#include<bits/stdc++.h>
using namespace std;
namespace FastIO
{
	static char c;
	static int top,buf[22],f; 
	template<typename T>inline void read(T& x)
	{
		x=0,c=getchar(),f=1;
		while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
		while(isdigit(c))x=x*10+c-'0',c=getchar();x*=f;
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

LL a,b;
int c;

int main()
{
	read(a),read(b),read(c);
	for(int i=1;i<=5e6;i++)
	{
		if(c==a*10/b)return printf("%d",i),0;
		a=a*10%b;
	}
	return puts("-1"),0;
}
