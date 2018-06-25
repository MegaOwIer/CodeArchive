#include<bits/stdc++.h>
using namespace std;

long long a,b,c,d,n0,n1,suf,pre,l;

int main()
{
	ios::sync_with_stdio(0);
	cin>>a>>b>>c>>d;
	n0=ceil(sqrt(2.0*a)),n1=ceil(sqrt(2.0*d));
	if((n0-1)*n0/2!=a)return puts("Impossible"),0;
	if((n1-1)*n1/2!=d)return puts("Impossible"),0;
	if(n0&&n1&&b+c!=n0*n1)return puts("Impossible"),0;
	if(n0+n1==0)
	{
		if(b+c>1)puts("Impossible");
		else if(b+c)puts(b?"01":"10");
		else puts("1");
	}
	else if(!n0)
	{
		if(a+b+c==0)while(n1--)putchar('1');
		else if(b+c==n1)
		{
			while(c--)putchar('1');
			putchar('0');
			while(b--)putchar('1');
		}
		else puts("Impossible");
	}
	else if(!n1)
	{
		if(b+c+d==0)while(n0--)putchar('0');
		else if(b+c==n0)
		{
			while(b--)putchar('0');
			putchar('1');
			while(c--)putchar('0');
		}
		else puts("Impossible");
	}
	else
	{
		suf=b/n0,l=b%n0,pre=n1-suf-(bool)l;
		while(pre--)putchar('1');
		pre=n0-l;
		while(l--)putchar('0');
		if(b%n0)putchar('1');
		while(pre--)putchar('0');
		while(suf--)putchar('1');
	}
	return 0;
}