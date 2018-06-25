#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
typedef long long LL;

LL n,a[100005],ans1,ans2;

int main()
{
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)  scanf("%lld",a+i);
	for(int i=n;i>1;i--)
	{
		a[i]-=a[i-1];
		if(a[i]>0)  ans1+=a[i];
		else  if(a[i]<0)  ans2-=a[i];
	}
	printf("%lld\n%lld",max(ans1,ans2),1+abs(ans1-ans2));
	return 0;
}
