//×¢Òâ¿¼ÂÇÖØ±ß 
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;

int n,m,g[205][205],ans,dis[205],det;

bool bfs()
{
	memset(dis,-1,sizeof(dis));  dis[1]=0;
	queue<int> q;  q.push(1);
	while(!q.empty())
	{
		int now=q.front();  q.pop();
		for(int i=1;i<=m;i++)  if(dis[i]<0&&g[now][i])
		{
			q.push(i);
			dis[i]=dis[now]+1;
		}
	}
	if(dis[m]<=0)  return 0;
	else  return 1;
}
int find(int u,int ans1)
{
	int a;
	if(u==m)  return ans1;
	for(int i=1;i<=m;i++)  if(g[u][i]&&dis[i]==dis[u]+1&&(a=find(i,min(ans1,g[u][i]))))
	{
		g[u][i]-=a;
		g[i][u]+=a;
		return a;
	}
	return 0;
}

int main()
{
	while(scanf("%d%d",&n,&m)==2)
	{
		ans=0;  memset(g,0,sizeof(g));
		for(int i=1,a,b,c;i<=n;i++)  {scanf("%d%d%d",&a,&b,&c);  g[a][b]+=c;}
		while(bfs())
		{
			while(det=find(1,10000001))  ans+=det;
		}
		printf("%d\n",ans);
	}
	return 0;
}
