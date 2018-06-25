#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

int n,m,g[105][105];

int main()
{
	while(scanf("%d%d",&n,&m)==2&&n&&m)
	{
		memset(g,0x1f,sizeof(g));
		for(int i=1,a,b,c;i<=m;i++)  {scanf("%d%d%d",&a,&b,&c);  g[a][b]=g[b][a]=min(g[a][b],c);}
		for(int k=1;k<=n;k++)  for(int i=1;i<=n;i++)  for(int j=1;j<=n;j++)  g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
		printf("%d\n",g[1][n]);
	}
	return 0;
}
