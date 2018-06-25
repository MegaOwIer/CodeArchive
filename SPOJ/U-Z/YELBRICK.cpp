#include<bits/stdc++.h>
using namespace std;
namespace FastIO
{
	static char c;
	static int top,buf[22]; 
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

LL ans;
int N,a,b,c,res;

inline int gcd(int u,int v){return v?gcd(v,u%v):u;}

int main()
{
	while(read(N),N)
	{
		res=ans=0;
		for(int i=1;i<=N;i++)
		{
			read(a),read(b),read(c);
			res=gcd(res,gcd(a,gcd(b,c)));
			ans+=(LL)a*b*c;
		}
		write(ans/res/res/res);
	}
	return 0;
}
