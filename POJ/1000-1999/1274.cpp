#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int m,n,lt[205];
bool g[205][205],fl,jud[205];

void read(int u)
{
	int k;
	scanf("%d",&k);
	for(int i=1,c;i<=k;i++)  {scanf("%d",&c);  g[u][c]=1;}
}
bool path(int x)
{
	for(int i=1;i<=n;i++)  if(g[x][i]==1&&jud[i]==0)
	{
		jud[i]=1;
		if(lt[i]==0||path(lt[i]))  {lt[i]=x;  return 1;}
	}
	return 0;
}
void hungry()
{
	int ans=0;
	memset(lt,0,sizeof(lt));
	for(int i=1;i<=m;i++)
	{
		memset(jud,0,sizeof(jud));
		if(path(i))  ans++;
	}
	printf("%d\n",ans);
}

int main()
{
	while(scanf("%d%d",&n,&m)==2)
	{
		memset(g,0,sizeof(g));
		for(int i=1;i<=n;i++)  read(i);
		hungry();
	}
	return 0;
}
