#include<cstdio>
using namespace std;

int g[5005][5005],n,r,ans,ret;

int main()
{
	scanf("%d%d",&n,&r);
	for(int i=1,a,b,c;i<=n;i++)
	{
		scanf("%d%d%d",&a,&b,&c);
		g[a+1][b+1]=c;
	}
	for(int i=1;i<=5001;i++)  for(int j=1;j<=5001;j++)  g[i][j]+=g[i-1][j]+g[i][j-1]-g[i-1][j-1];
	for(int i=r;i<=5001;i++)  for(int j=r;j<=5001;j++)
	{
		ret=g[i][j]-g[i-r][j]-g[i][j-r]+g[i-r][j-r];
		if(ret>ans)  ans=ret;
	}
	printf("%d",ans);
	return 0;
}
