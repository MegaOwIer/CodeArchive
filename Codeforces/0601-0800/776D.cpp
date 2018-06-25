#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=100005;

struct edge {int u,v;}e[maxn<<2];
int n,m,sta[maxn],fa[maxn<<1],oper[maxn][2];

inline int find(int x) {return x==fa[x]?x:fa[x]=find(fa[x]);}

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=(m<<1);i++)  fa[i]=i;
	for(int i=1;i<=n;i++)  scanf("%d",sta+i);
	for(int i=1,a,b;i<=m;i++)
	{
		scanf("%d",&a);
		for(int j=1;j<=a;j++)
		{
			scanf("%d",&b);
			if(oper[b][0])  oper[b][1]=i;
			else  oper[b][0]=i;
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(!sta[i])  e[(i<<1)-1]=(edge){oper[i][0]+m,oper[i][1]},e[i<<1]=(edge){oper[i][0],oper[i][1]+m};
		else  e[(i<<1)-1]=(edge){oper[i][0],oper[i][1]},e[i<<1]=(edge){oper[i][0]+m,oper[i][1]+m};
	}
	for(int i=1;i<=(n<<1);i++)
	{
		int f1=find(e[i].u),f2=find(e[i].v);
		if(f1==f2)  continue;
		fa[f1]=f2;
	}
	for(int i=1;i<=m;i++)  if(find(i)==find(i+m))  return puts("NO"),0;
	return puts("YES"),0;
}
