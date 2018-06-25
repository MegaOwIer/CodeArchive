#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int mod=9999991;

int n;
LL ans;

LL Pow(int a,int b)
{
	LL res=a,ans=1LL;
	while(b)
	{
		if(b&1)ans=ans*res%mod;
		res=res*res%mod;
		b>>=1;
	}
	return ans;
}

int main()
{
	scanf("%d",&n);
	ans=Pow(n,n-2);
	for(int i=2;i<n;i++)ans=ans*i%mod;
	printf("%lld",ans);
	return 0;
}
