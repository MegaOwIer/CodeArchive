#include<bits/stdc++.h>
using namespace std;
namespace FastIO
{
	static char c;
	static int buf[22],top;
	template<typename T>inline void read(T& x)
	{
		x=0,c=getchar();
		while(!isdigit(c))c=getchar();
		while(isdigit(c))x=x*10+c-'0',c=getchar();
	}
	template<typename T>inline void write(T x)
	{
		top=0;
		do buf[top++]=x%10,x/=10;while(x);
		while(top)putchar(48+buf[--top]);
		putchar('\n');
	}
}
using FastIO::read;
using FastIO::write;
typedef long long LL;

int n,a[1505],inv[1505],res,m;

int main()
{
	read(n);
	for(int i=1;i<=n;i++)read(a[i]),inv[a[i]]=i;
	for(int i=1;i<=n;i++)if(a[i]!=i)
		inv[a[i]]=inv[i],swap(a[i],a[inv[i]]),inv[i]=i,res^=1;
	read(m);
	for(int i=1,l,r;i<=m;i++)
	{
		read(l),read(r);
		l=r-l+1;
		if(l%4==2||l%4==3)res^=1;
		puts(res?"odd":"even");
	}
	return 0;
}
