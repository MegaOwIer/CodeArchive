#include<bits/stdc++.h>
using namespace std;

int n;
bool fl,fl2=1;

template<typename T>
inline void read(T& x)
{
	x=0;  char ch=getchar();
	while(ch<'0'||ch>'9')  ch=getchar();
	while(ch>='0'&&ch<='9')  x=x*10+ch-'0',ch=getchar();
}

int main()
{
	read(n);
	for(int i=1,a;i<=n;i++)  {read(a),fl^=(a&1);if(a&1)fl2=0;}
	if(fl)  return puts("First"),0;
	if(fl2)  return puts("Second"),0;
	return puts("First"),0;
}
