#include<bits/stdc++.h>
using namespace std;

int n,m;
double a[105][105],tmp;
char c;

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<n;i++)
	{
		a[i][i]=1-n;
		for(int j=1;j<=n;j++)
		{
			scanf("%lf",&tmp);
			if(i!=j)a[i][j]=tmp,a[i][i]+=tmp;
		}
	}
	for(int i=1;i<=n;i++)scanf("%lf",&tmp),a[n][i]=1;
	a[n][n+1]=1;
	for(int i=1,j,k;i<=n;i++)
	{
		for(j=k=i;j<=n;j++)if(fabs(a[j][i])>fabs(a[k][i]))k=j;
		if(i!=k)swap(a[i],a[k]);
		for(j=i+1;j<=n;j++)
		{
			tmp=a[j][i]/a[i][i];
			for(k=i;k<=n+1;k++)a[j][k]-=tmp*a[i][k];
		}
	}
	for(int i=n;i;i--)
	{
		for(int j=i+1;j<=n;j++)a[i][n+1]-=a[i][j]*a[j][n+1];
		a[i][n+1]/=a[i][i];
	}
	while(m--)
	{
		tmp=0;
		for(int i=1;i<=n;i++)
		{
			do c=getchar();while(c!='0'&&c!='1');
			if(c=='1')tmp+=a[i][n+1];
		}
		printf("%.8lf\n",tmp);
	}
	return 0;
}
