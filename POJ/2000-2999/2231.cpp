#include<cstdio>
#include<algorithm>
#include<functional>
#include<iostream>
using namespace std;

long long ans,c[10005],n;

int main()
{
	while(scanf("%lld",&n)!=EOF)
	{
		for(int i=0;i<n;i++)  scanf("%d",&c[i]);
		sort(c,c+n,less<int>());
		for(int i=n-1;i;i--)  c[i]-=c[i-1];
		for(int i=1;i<n;i++)  ans+=i*(n-i)*c[i];
		printf("%lld",ans*2);
	}
	return 0;
}
