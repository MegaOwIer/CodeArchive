#include<bits/stdc++.h>
using namespace std;
namespace FastIO
{
	static int top,buf[22];
	template<typename T>inline void write(T x)
	{
		top=0;
		do buf[++top]=x%10,x/=10;while(x);
		while(top)putchar(48+buf[top--]);
		putchar('\n');
	}
}
using FastIO::write;

int a[2];
char s[1005];

int main()
{
	while(~scanf("%s",s+1))
	{
		a[0]=a[1]=0;
		for(int i=1;s[i];i++)a[(s[i]<'a')^(i&1)]++;
		write(min(a[0],a[1]));
	}
	return 0;
}
