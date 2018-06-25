#include<bits/stdc++.h>
using namespace std;

int n,m[2505],dp[2505];
char c;

inline void read(int& x)
{
	c=getchar(),x=0;
	while(!isdigit(c))c=getchar();
	while(isdigit(c))x=x*10+c-48,c=getchar();
}

int main()
{
	read(n),read(m[0]),m[0]<<=1;
	for(int i=1;i<=n;i++)read(m[i]),m[i]+=m[i-1];
	memset(dp+1,0x3f,n<<2);
	for(int i=1;i<=n;i++)for(int j=0;j<i;j++)dp[i]=min(dp[i],dp[j]+m[i-j]);
	m[0]>>=1,printf("%d",dp[n]-m[0]);
	return 0;
}
