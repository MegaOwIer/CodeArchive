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
}
using FastIO::read;
typedef long long LL;
const int mod=1e9+7;

LL a,b;

LL Pow(LL a,int b)
{
	LL ans=1;
	while(b)
	{
		if(b&1)ans=ans*a%mod;
		a=a*a%mod,b>>=1;
	}
	return ans;
}

int main()
{
	read(a),read(b);
	printf("%lld\n",Pow(Pow(2,a),b));
	return 0;
}
