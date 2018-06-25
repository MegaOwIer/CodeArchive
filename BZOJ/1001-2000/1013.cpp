#include<cstdio>
#include<algorithm>
using namespace std;

int n;
double a[2][15],x[15][15],ans[15],tmp;

void solve()
{
	for(int i=1;i<n;i++)
	{
		if(!x[i][1])  for(int j=i+1;j<=n;j++)  if(x[j][1])  {swap(x[i],x[j]);  break;}
		for(int j=i+1;j<=n;j++)
		{
			tmp=x[j][i]/x[i][i];
			for(int k=i+1;k<=n+1;k++)  x[j][k]-=tmp*x[i][k];
		}
	}
	ans[n]=x[n][n+1]/x[n][n];
	for(int i=n-1;i;i--)
	{
		for(int j=n;j>i;j--)  x[i][n+1]-=x[i][j]*ans[j];
		ans[i]=x[i][n+1]/x[i][i];
	}
	for(int i=1;i<n;i++)  printf("%.3lf ",ans[i]);
	printf("%.3lf",ans[n]);
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)  scanf("%lf",a[0]+i);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)  scanf("%lf",a[i&1]+j);
		for(int j=1;j<=n;j++)  x[i][j]=(a[1][j]-a[0][j])*2,x[i][n+1]+=a[1][j]*a[1][j]-a[0][j]*a[0][j];
	}
	solve();
	return 0;
}
