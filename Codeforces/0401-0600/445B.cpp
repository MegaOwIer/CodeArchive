#include<cstdio>
#include<algorithm>
using namespace std;

int n,m,ans,fa[55],f1,f2;

int find(int x) {return x==fa[x]?x:fa[x]=find(fa[x]);}

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)  fa[i]=i;
	for(int i=1,u,v;i<=m;i++)
	{
		scanf("%d%d",&u,&v);
		f1=find(u),f2=find(v);
		if(f1==f2)  continue;
		fa[f1]=f2;
	}
	for(int i=1;i<=n;i++)  if(i==fa[i])  ans++;
	printf("%I64d",1LL<<n-ans);
	return 0;
}
