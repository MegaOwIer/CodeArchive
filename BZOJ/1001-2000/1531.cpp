#include<bits/stdc++.h>
using namespace std;
const int maxn=20005;

int n,b[205],c[205],k,w[maxn*15],cnt,dp[maxn],v[maxn];
char ch;

inline void read(int& x)
{
	x=0,ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
}

int main()
{
	read(n);
	for(int i=1;i<=n;i++)read(b[i]);
	for(int i=1;i<=n;i++)read(c[i]);
	read(k);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<c[i];j<<=1)w[++cnt]=b[i]*j,c[i]-=j,v[cnt]=j;
		if(c[i])w[++cnt]=b[i]*c[i],v[cnt]=c[i];
	}
	memset(dp+1,-1,k<<2);
	for(int i=1;i<=cnt;i++)for(int j=k-w[i];j>=0;j--)if(~dp[j])
	{
		if(~dp[j+w[i]])dp[j+w[i]]=min(dp[j+w[i]],dp[j]+v[i]);
		else dp[j+w[i]]=dp[j]+v[i];
	}
	printf("%d",dp[k]);
	return 0;
}
