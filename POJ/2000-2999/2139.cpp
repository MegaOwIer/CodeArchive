#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

int n,m,vis[305],g[305][305],ans=0x7fffffff,ans1;

int main()
{
	while(scanf("%d%d",&n,&m)==2)
	{
		for(int i=1;i<=n;i++)  for(int j=1;j<=n;j++)  g[i][j]=100000;
		for(int i=1;i<=n;i++)  g[i][i]=0;
		for(int i=1,a;i<=m;i++)
		{
			scanf("%d",&a);
			for(int i=1;i<=a;i++)  scanf("%d",&vis[i]);
			for(int i=1;i<a;i++)  for(int j=i+1;j<=a;j++)  g[vis[i]][vis[j]]=g[vis[j]][vis[i]]=1;
		}
		for(int k=1;k<=n;k++)  for(int i=1;i<=n;i++)  for(int j=1;j<=n;j++)  g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
		for(int i=1;i<=n;i++)
		{
			ans1=0;
		    for(int j=1;j<=n;j++)  ans1+=g[i][j];
		    ans=min(ans,ans1);
		}
		printf("%d\n",ans*100/(n-1));
	}
	return 0;
}
