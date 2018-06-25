#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn=100005;

int n,k,val[16],res,pre[16],m;
double dp[105][32770];

inline int read()
{
	int ans=0,f=1;  char ch=getchar();
	while(ch<'0'||ch>'9')  {if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')  ans=ans*10+ch-'0',ch=getchar();
	return ans*f;
}

int main()
{
	k=read(),n=read(),m=1<<n;
	for(int i=1;i<=n;i++)
	{
		val[i]=read();
		while(res=read())  pre[i]|=(1<<(res-1));
	}
	for(int i=k;i;i--)  for(int j=0;j<m;j++)
	{
		for(int l=1;l<=n;l++)
			if(pre[l]==(pre[l]&j))  dp[i][j]+=max(dp[i+1][j],dp[i+1][(1<<(l-1))|j]+val[l]);
			else  dp[i][j]+=dp[i+1][j];
		dp[i][j]/=n;
	}
	printf("%.6lf",dp[1][0]);
	return 0;
}
