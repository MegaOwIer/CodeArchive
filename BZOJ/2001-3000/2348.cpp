#include<bits/stdc++.h>
using namespace std;

int n,a[100005],res;
long long ans;
char c;

inline void read(int& x)
{
	x=0,c=getchar();
	while(c<'0'||c>'9')c=getchar();
	while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
}

int main()
{
	read(n);
	for(int i=1;i<=n;i++)read(a[i]);
	sort(a+1,a+n+1),a[n+1]=100000005;
	for(int i=n;i;i--)
	{
		res=(a[i]*9+9)/10;
		ans+=a-lower_bound(a+1,a+n,res)+i;
	}
	printf("%lld",ans);
	return 0;
}
