#include<cstdio>
#include<cstring>
using namespace std;

int k,n,m,cow[105],ans,cnt[1005];
bool ma[1005][1005],df[1005];
void dfs(int);

int main()
{
	scanf("%d%d%d",&k,&n,&m);
	for(int i=1;i<=k;i++)  scanf("%d",&cow[i]);
	for(int i=1,a,b;i<=m;i++)  {scanf("%d%d",&a,&b);  ma[a][b]=1;}
	for(int i=1;i<=n;i++)  ma[i][i]=1;
	for(int i=1;i<=k;i++)  {memset(df,0,sizeof(df));  dfs(cow[i]);}
	for(int i=1;i<=n;i++)  if(cnt[i]==k)  ans++;
	printf("%d",ans);
	return 0;
}
void dfs(int u)
{
	df[u]=1;  cnt[u]++;
	for(int i=1;i<=n;i++)  if(ma[u][i]&&!df[i])  dfs(i);
}
