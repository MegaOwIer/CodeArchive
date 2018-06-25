#include<bits/stdc++.h>
using namespace std;

int n,m,u,v,ans,lt[105];
bool g[105][105],vis[105];

inline bool find(int x)
{
	for(int i=n-m;i;i--)if(g[x][i]&&!vis[i])
	{
		vis[i]=1;
		if(!lt[i]||find(lt[i]))
		{
			lt[i]=x;
			return 1;
		}
	}
	return 0;
}

int main()
{
	scanf("%d%d",&n,&m);
	while(~scanf("%d%d",&u,&v))g[u][v-m]=1;
	for(int i=1;i<=m;i++)
	{
		memset(vis+1,0,n-m);
		if(find(i))ans++;
	}
	printf("%d",ans);
	return 0;
}
