#include<cstdio>
#include<algorithm>
using namespace std;

int n,m,g[105][105],fa[105],f1,f2,ans;
bool flag;

inline int find(int x) {return x==fa[x]?x:fa[x]=find(fa[x]);}

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1,a,b;i<=n;i++)
	{
		scanf("%d",&a);
		if(a)  flag=1;
		for(int j=1;j<=a;j++)  {scanf("%d",&b);  g[b][++g[b][0]]=i;}
	}
	for(int i=1;i<=n;i++)  fa[i]=i;
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=g[i][0];j++)  for(int k=j+1;k<=g[i][0];k++)
		{
			f1=find(g[i][j]),f2=find(g[i][k]);
			if(f1==f2)  continue;
			fa[f1]=f2;
		}
	}
	for(int i=1;i<=n;i++)  if(i==fa[i])  ans++;
	printf("%d",ans-flag);
	return 0;
}
