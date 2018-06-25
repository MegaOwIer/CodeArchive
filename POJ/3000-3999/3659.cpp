#include<algorithm>
#include<cstdio>
#include<vector>
using namespace std;

vector<int> g[10005];
int n,ans;
bool vis[10005],have[10005];

void dfs(int u,int fa)
{
	vis[u]=1;  bool fl=0;
	for(int i=0;i<g[u].size();i++)  if(!vis[g[u][i]])
	{
		dfs(g[u][i],u);
		if(have[g[u][i]])  fl=1;
	}
	if(fa<0)  ans+=!(have[u]||fl);
	else  if(!(have[fa]||have[u]||fl))  have[fa]=1,ans++;
}

int main()
{
	scanf("%d",&n);
	for(int i=1,a,b;i<n;i++)  {scanf("%d%d",&a,&b);  g[a].push_back(b);  g[b].push_back(a);}
	dfs(1,-1);
	printf("%d",ans);
	return 0;
}
