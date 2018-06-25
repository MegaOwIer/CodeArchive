#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn=3e6+5;

int n,mod;
LL a[maxn];

int main()
{
	scanf("%d%d",&n,&mod),a[1]=1;
	for(int i=2;i<=n;i++)a[i]=(-(mod/i)*a[mod%i]%mod+mod)%mod;
	for(int i=1;i<=n;i++)printf("%lld\n",a[i]);
	return 0;
}
