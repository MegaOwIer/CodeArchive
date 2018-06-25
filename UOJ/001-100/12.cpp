#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int T;
LL a,b;

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%lld%lld",&a,&b);
		printf("%lld %lld\n",(LL)sqrt(b/a)*a*2,a+b);
	}
	return 0;
}
