#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn=1000005;

int n,a[maxn],ave;
LL sum,ans;
char c;

inline void read(int& x)
{
	x=0,c=getchar();
	while(!isdigit(c))c=getchar();
	while(isdigit(c))x=x*10+c-'0',c=getchar();
}

int main()
{
	read(n);
	for(int i=1;i<=n;i++)read(a[i]),sum+=a[i];ave=sum/n;
	for(int i=1;i<=n;i++)a[i]=ave-a[i],a[i]+=a[i-1];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)ans+=abs(a[i]-a[(n+1)>>1]);
	printf("%lld",ans);
	return 0;
}
