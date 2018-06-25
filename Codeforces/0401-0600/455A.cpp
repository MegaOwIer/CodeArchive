#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn=1e5+5;

int n,a[maxn],mx;
LL dp[maxn][2];
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
	for(int i=1,u;i<=n;i++)read(u),a[u]++,mx=max(mx,u);
	for(int i=1;i<=mx;i++)
	{
		if(a[i])dp[i][1]=1LL*a[i]*i+dp[i-1][0];
		dp[i][0]=max(dp[i-1][0],dp[i-1][1]);
	}
	printf("%lld",max(dp[mx][1],dp[mx][0]));
	return 0;
}
