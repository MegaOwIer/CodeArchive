#include<bits/stdc++.h>
using namespace std;

int n,m,k,f,a[105][3],dp1[105][11],dp2[105][105][11];
char c;

inline void read(int& x)
{
	x=0,c=getchar(),f=1;
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c))x=x*10+c-48,c=getchar();x*=f;
}

int main()
{
	read(n),read(m),read(k);
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)read(a[i][j]),a[i][j]+=a[i-1][j];
	if(m==1)
	{
		for(int i=1;i<=n;i++)for(int j=1;j<=k;j++)
		{
			dp1[i][j]=dp1[i-1][j];
			for(int l=0;l<i;l++)dp1[i][j]=max(dp1[i][j],dp1[l][j-1]+a[i][1]-a[l][1]);
		}
		printf("%d",dp1[n][k]);
	}
	else
	{
		for(int i=1;i<=k;i++)for(int j=1;j<=n;j++)for(int l=1;l<=n;l++)
		{
			dp2[j][l][i]=max(dp2[j-1][l][i],dp2[j][l-1][i]);
			for(int p=0;p<j;p++)dp2[j][l][i]=max(dp2[j][l][i],dp2[p][l][i-1]+a[j][1]-a[p][1]);
			for(int p=0;p<l;p++)dp2[j][l][i]=max(dp2[j][l][i],dp2[j][p][i-1]+a[l][2]-a[p][2]);
			if(j==l)for(int p=0;p<j;p++)dp2[j][l][i]=max(dp2[j][l][i],dp2[p][p][i-1]+a[j][1]+a[j][2]-a[p][1]-a[p][2]);
		}
		printf("%d",dp2[n][n][k]);
	}
	return 0;
}
