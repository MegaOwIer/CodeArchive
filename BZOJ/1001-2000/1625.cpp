#include<bits/stdc++.h>
using namespace std;

int n,m,dp[12900];
char c;

inline void read(int& x)
{
	x=0,c=getchar();
	while(!isdigit(c))c=getchar();
	while(isdigit(c))x=x*10+c-48,c=getchar();
}

int main()
{
	read(n),read(m);
	for(int i=1,w,d;i<=n;i++)
	{
		read(w),read(d);
		for(int i=m;i>=w;i--)dp[i]=max(dp[i],dp[i-w]+d);
	}
	printf("%d",dp[m]);
	return 0;
}
