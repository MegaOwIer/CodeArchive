#include<bits/stdc++.h>
using namespace std;

int v,n,a;
long long f[10005];
char c;

inline void read(int& x)
{
	c=getchar(),x=0;
	while(!isdigit(c))c=getchar();
	while(isdigit(c))x=x*10+c-'0',c=getchar();
}

int main()
{
	read(v),read(n),f[0]=1;
	for(int i=1;i<=v;i++)
	{
		read(a);
		for(int j=a;j<=n;j++)f[j]+=f[j-a];
	}
	printf("%lld",f[n]);
	return 0;
}
