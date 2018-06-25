#include<bits/stdc++.h>
using namespace std;
const double eps=1e-7;

int hp[2],dt[2],l[2],r[2],p[2],t[2],T=10000;
double P[2],dp[2][205],ans[2],tmp;

inline void work(int f)
{
	t[f]+=dt[f];
	for(int i=1;i<=hp[f^1];i++)if(dp[f^1][i]>eps)
	{
		for(int j=l[f];j<=r[f];j++)
			dp[f^1][max(0,i-j)]+=P[f]*dp[f^1][i];
		dp[f^1][i]*=p[f]*0.01;
	}
	ans[f]+=(1-dp[f][0])*dp[f^1][0];
	if(!f)dp[1][0]=0;
}

int main()
{
	for(int i=0;i<2;i++)
	{
		scanf("%d%d%d%d%d",hp+i,dt+i,l+i,r+i,p+i);
		if(p[i]==100)return printf("%d",i),0;
		P[i]=1.0/(r[i]-l[i]+1)*(1-0.01*p[i]);
		dp[i][hp[i]]=1;
	}
	while(T--)work(t[1]<t[0]);
	printf("%.6lf\n",ans[0]);
	return 0;
}
