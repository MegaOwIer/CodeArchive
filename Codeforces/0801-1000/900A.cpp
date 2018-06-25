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

int cnt1,cnt2,x,n;

int main()
{
	read(n);
	for(int i=1;i<=n;i++)
	{
		read(x);
		if(x>0)cnt1++;
		else cnt2++;
		read(x);
	}
	if(cnt1<=1||cnt2<=1)puts("Yes");
	else puts("No");
	return 0;
}
