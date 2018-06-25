#include<bits/stdc++.h>
using namespace std;
namespace FastIO
{
	static char c;
	static int top,buf[22];
	template<typename T>inline void IN(T& x)
	{
		x=0,c=getchar();
		while(!isdigit(c))c=getchar();
		while(isdigit(c))x=x*10+c-48,c=getchar();
	}
	template<typename T>inline void OUT(T x)
	{
		top=0;
		do buf[++top]=x%10,x/=10;while(x);
		while(top)putchar(48+buf[top--]);
		putchar(' ');
	}
}
using FastIO::IN;
using FastIO::OUT;
const int maxn=200005;

pair<int,int> a[maxn];
int n,m,tmp;

int main()
{
	IN(n),IN(m);
	for(int i=0;i<=n;i++)IN(a[i].first),a[i].second=i;
	sort(a,a+n+1),tmp=a[0].second;
	while(n--)OUT(a[tmp].first),tmp=a[tmp].second;
	return 0;
}
