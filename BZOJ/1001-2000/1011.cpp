#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;

int n;
double ans[maxn],a,sum[maxn],m[maxn];

int main()
{
	scanf("%d%lf",&n,&a);
	for(int i=1;i<=n;i++)scanf("%lf",m+i),sum[i]=sum[i-1]+m[i];
	for(int i=1,k;i<=n;i++)
	{
		k=floor(i*a+1e-8);
		if(k<=70)
			for(int j=1;j<=k;j++)ans[i]+=m[i]*m[j]/(i-j);
		else ans[i]=sum[k]*m[i]/(i-(1+k>>1));
	}
	for(int i=1;i<=n;i++)printf("%.6lf\n",ans[i]);
	return 0;
}
