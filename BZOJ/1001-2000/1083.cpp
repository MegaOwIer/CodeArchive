#include<cstdio>
#include<algorithm>
using namespace std;

struct edge {int s,t,w;}e[45000];
bool operator < (edge a,edge b) {return a.w<b.w;}
int n,m,fa[305],cnt;

int find(int u)  {return u==fa[u]?u:fa[u]=find(fa[u]);}

int main()
{
	scanf("%d%d",&n,&m);  cnt=n-1;
	for(int i=1;i<=n;i++)  fa[i]=i;
	for(int i=1;i<=m;i++)  scanf("%d%d%d",&e[i].s,&e[i].t,&e[i].w);
	sort(e+1,e+m+1);
	for(int i=1;;i++)
	{
		int x=find(e[i].s),y=find(e[i].t);
		if(x==y)  continue;
		fa[x]=y;
		cnt--;
		if(!cnt)  {printf("%d %d",n-1,e[i].w);  break;}
	}
	return 0;
}
