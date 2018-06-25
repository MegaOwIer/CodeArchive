#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

LL n,m,k,mod;

inline LL Pow(LL a,LL b)
{
	if(!a)return 0;
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
	scanf("%lld%lld%lld%lld",&n,&k,&m,&mod),n%=mod;
	LL ans=n*Pow(m,k-1);
	LL ans1=m*(m+1)/2%mod*Pow(m,k-2)%mod*(k-1)%mod;
	printf("%lld",(ans-ans1)%mod);
	return 0;
}
