#include<bits/stdc++.h>
using namespace std;

long long p,q;

int main()
{
	scanf("%lld%lld",&p,&q);
	if(p==q)printf("%lld",(p*p-1)>>2);
	else printf("%lld",(p-1)*(q-1)>>2);
	return 0;
}
