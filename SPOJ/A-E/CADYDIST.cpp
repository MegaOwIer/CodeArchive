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
const int maxn=100005;

int n,a[maxn],b[maxn];
LL ans;

int main()
{
	while(read(n),n)
	{
		ans=0;
		for(int i=1;i<=n;i++)read(a[i]);
		for(int i=1;i<=n;i++)read(b[i]);
		sort(a+1,a+n+1),sort(b+1,b+n+1);
		for(int i=1;i<=n;i++)ans+=(LL)a[i]*b[n+1-i];
		write(ans);
	}
	return 0;
}
