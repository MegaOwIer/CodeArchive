#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int n,m,k,now;
LL a[5005],dp[2][5005];
char c;

template<typename T>
inline void read(T& x)
{
	c=getchar(),x=0;
	while(!isdigit(c))c=getchar();
	while(isdigit(c))x=x*10+c-'0',c=getchar();
}

int main()
{
	read(n),read(m),read(k);
	for(int i=1;i<=n;i++)read(a[i]),a[i]+=a[i-1];
	for(int i=1;i<=k;i++)
	{
		now=i&1;
		memset(dp[now]+1,0,m<<3);
		for(int j=i*m;j<=n;j++)
			dp[now][j]=max(dp[now][j-1],dp[now^1][j-m]+a[j]-a[j-m]);
	}
	printf("%lld",dp[k&1][n]);
	return 0;
}
