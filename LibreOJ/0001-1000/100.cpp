#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;

int n,m,p;
long long a[505][505],b[505][505],c[505][505];

int main()
{
	scanf("%d%d%d",&n,&p,&m);
	for(int i=1;i<=n;i++)for(int j=1;j<=p;j++){scanf("%lld",&a[i][j]);if(a[i][j]<0)a[i][j]+=mod;}
	for(int i=1;i<=p;i++)for(int j=1;j<=m;j++){scanf("%lld",&b[i][j]);if(b[i][j]<0)b[i][j]+=mod;}
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)for(int k=1;k<=p;k++)
		c[i][j]=(c[i][j]+a[i][k]*b[k][j])%mod;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)printf("%lld ",c[i][j]);
		puts("");
	}
	return 0;
}
