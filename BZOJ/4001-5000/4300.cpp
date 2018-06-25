#include<bits/stdc++.h>
using namespace std;

namespace FastIO
{
	char c;
	int tp,bf[22];
	template<typename T>inline void read(T& x)
	{
		x=0,c=getchar();
		while(!isdigit(c))c=getchar();
		while(isdigit(c))x=x*10+c-'0',c=getchar();
	}
	template<typename T>inline void write(T x)
	{
		tp=0;
		do bf[++tp]=x%10,x/=10;while(x);
		while(tp)putchar(48+bf[tp--]);
	}
}
using FastIO::read;
using FastIO::write;

int n,d[35],tmp;

int main()
{
	read(n);
	for(int i=1,u;i<=n;i++)
	{
		read(u),tmp=0;
		for(int j=0;j<31;j++)if(u&(1<<j))tmp=max(tmp,d[j]+1);
		for(int j=0;j<31;j++)if(u&(1<<j))d[j]=max(tmp,d[j]);
	}
	tmp=0;
	for(int i=0;i<31;i++)tmp=max(tmp,d[i]);
	write(tmp);
	return 0;
}
