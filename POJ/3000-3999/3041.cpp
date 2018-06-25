#include<cstdio>
#include<cstring>
using namespace std;

int n,k,link[505];
bool g[505][505],fl[505];
int hungry();
bool path(int);

int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1,a,b;i<=k;i++)  {scanf("%d%d",&a,&b);  g[a][b]=1;}
	printf("%d",hungry());
	return 0;
}
int hungry()
{
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		memset(fl,0,sizeof(fl));
	    if(path(i))  ans++;
	}
	return ans;
}
bool path(int u)
{
	for(int i=1;i<=n;i++)  if(g[u][i]&&!fl[i])
	{
		fl[i]=1;
		if(!link[i]||path(link[i]))
		{
			link[i]=u;
			return 1;
		}
	}
	return 0;
}
