#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

LL n,m,p;

inline LL cheng(LL a,LL b)
{
	LL ans=0;
	if(a<b)swap(a,b);
	while(b)
	{
		if(b&1)(ans+=a)%=p;
		(a<<=1)%=p,b>>=1;
	}
	return ans;
}
inline LL Pow(LL a,LL b)
{
	if(!b)return 1;
	LL ans=1;
	while(b)
	{
		if(b&1)ans=cheng(ans,a);
		a=cheng(a,a),b>>=1;
	}
	return ans;
}

int main()
{
	scanf("%lld%lld%lld",&n,&m,&p);
	printf("%lld",cheng(Pow(n,m-1),Pow(m,n-1)));
	return 0;
}
