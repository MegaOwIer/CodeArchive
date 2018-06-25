#include<bits/stdc++.h>
using namespace std;
namespace FastIO
{
	static char c;
	template<typename T>
	inline void read(T& x)
	{
		x=0,c=getchar();
		while(!isdigit(c))c=getchar();
		while(isdigit(c))x=x*10+c-'0',c=getchar();
	}
	inline void getc(char& x){do x=getchar();while(x!='.'&&x!='#');}
}
using FastIO::read;
using FastIO::getc;

int n,m;
char f;
bool c[505][505];

int main()
{
	read(n),read(m);
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)
		getc(f),c[i][j]=(f=='#');
	for(int i=1;i<=n;i++)
	{
		putchar('#');
		for(int j=2;j<m;j++)putchar(i&1||c[i][j]?'#':'.');
		putchar('.'),putchar('\n');
	}
	putchar('\n');
	for(int i=1;i<=n;i++)
	{
		putchar('.');
		for(int j=2;j<m;j++)putchar(!(i&1)||c[i][j]?'#':'.');
		putchar('#'),putchar('\n');
	}
	return 0;
}
