#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int T;
LL a,dp[160];

inline int solve(LL a)
{
	int mid,l=1,r=150;
	while(l<r)
	{
		mid=l+r>>1;
		if(dp[mid]<a)l=mid+1;
		else r=mid;
	}
	return r;
}

int main()
{
	dp[2]=1;
	for(int i=3;i<=150;i++)
	{
		dp[i]=i-1;
		for(int j=1;j<i-1;j++)dp[i]=max(dp[i],j*dp[i-j-1]);
	}
	scanf("%d",&T);
	while(T--)scanf("%lld",&a),printf("%d\n",solve(a)<<1);
}
