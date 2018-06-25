#include<bits/stdc++.h>
using namespace std;
const int maxn=50005,mod=10007;

int n,m,a[maxn],mn,mx,ans,dp[2][maxn],now;
char c;

inline void read(int& x)
{
	c=getchar(),x=0;
	while(!isdigit(c))c=getchar();
	while(isdigit(c))x=x*10+c-48,c=getchar();
}
inline bool check(int u)
{
	int sum=0,cnt=0;
	for(int i=1;i<=n;i++)
	{
		sum+=a[i];
		if(sum>u)cnt++,sum=a[i];
		if(cnt>m)return 0;
	}
	return 1;
}

int main()
{
	read(n),read(m);
	for(int i=1;i<=n;i++)read(a[i]),mn=max(a[i],mn),mx+=a[i];
	while(mn<mx)
	{
		int mid=mn+mx>>1;
		if(check(mid))mx=mid;
		else mn=mid+1;
	}
	printf("%d ",mn);
	for(int i=2;i<=n;i++)a[i]+=a[i-1];
	for(int i=1;a[i]<=mn;i++)dp[1][i]=1;ans=dp[1][n];now=1;
	for(int i=2;i<=m+1;i++)
	{
		for(int j=i;j<=n;j++)(dp[now][j]+=dp[now][j-1])%=mod;
		now^=1;
		for(int j=i,k=i-1;j<=n;j++)
		{
			while(a[j]-a[k]>mn)k++;
			dp[now][j]=(dp[now^1][j-1]-dp[now^1][k-1]+mod)%mod;
		}
		ans=(ans+dp[now][n])%mod;
	}
	printf("%d",ans);
	return 0;
}
