#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int n,q;
LL a[50005],T;
char c;

template<typename T>
inline void read(T& x)
{
	x=0,c=getchar();
	while(c<'0'||c>'9')c=getchar();
	while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
}

int main()
{
	read(n),read(q);
	for(int i=2;i<=n+1;i++)read(a[i]),a[i]+=a[i-1];
	for(int i=1;i<=q;i++)
	{
		read(T);
		printf("%d\n",upper_bound(a+1,a+n+2,T)-a-1);
	}
	return 0;
}
