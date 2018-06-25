#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn=1e6+5;

int n;
LL ans,avg,a[maxn],C[maxn];
char c;

template<typename T>
inline void read(T& x)
{
	x=0,c=getchar();
	while(!isdigit(c))c=getchar();
	while(isdigit(c))x=x*10+c-'0',c=getchar();
}

int main()
{
	while(~scanf("%d",&n))
	{
		ans=avg=0;
		for(int i=1;i<=n;i++)read(a[i]),avg+=a[i];
		avg/=n;
		for(int i=1;i<n;i++)C[i]=C[i-1]+a[i]-avg;
		sort(C,C+n);
		for(int i=0,j=n-1;i<=j;i++,j--)ans+=C[j]-C[i];
		printf("%lld\n",ans);
	}
	return 0;
}
