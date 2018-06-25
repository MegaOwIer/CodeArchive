#include<cstdio>
#include<cmath>
#include<cstring> 
#include<algorithm>
using namespace std;

struct Point{double x,y;}p[1010];
inline double dis(int a,int b)  {return  (p[a].x-p[b].x)*(p[a].x-p[b].x)+(p[a].y-p[b].y)*(p[a].y-p[b].y);}
bool g[1010][1010];
struct Edge{int st,en;double len;}ed[999*500+10];
bool cmp(Edge u,Edge v)  {return  u.len<v.len;}
int m,n,fa[1010];
inline int find(int x)  {return x==fa[x]?fa[x]:fa[x]=find(fa[x]);}

int main()
{
	while(scanf("%d%d",&n,&m)!=EOF&&n)
	{
		memset(g,0,sizeof(g));
		int cnt=0,tot=0;double ans=0;
		for(int i=1;i<=n;i++)  fa[i]=i;
	    for(int i=1;i<=n;i++)  scanf("%lf%lf",&p[i].x,&p[i].y);
		for(int i=1,aa,bb;i<=m;i++)  {scanf("%d%d",&aa,&bb);  if(aa>bb)  swap(aa,bb);  g[aa][bb]=1;
		                              ed[++cnt].st=aa;  ed[cnt].en=bb;  ed[cnt].len=0;}
		for(int i=1;i<n;i++)  for(int j=i+1;j<=n;j++)  if(!g[i][j])  {ed[++cnt].st=i;  ed[cnt].en=j;  ed[cnt].len=dis(i,j);}
		sort(ed+1,ed+cnt+1,cmp);
		for(int i=1;i<=cnt;i++)
		{
			int x=find(ed[i].st),y=find(ed[i].en);
			if(x==y)  continue;
			fa[y]=x;
			ans+=sqrt(ed[i].len);
			tot++;
			if(tot==n-1)  break;
		}
		printf("%.2lf\n",ans);
    }
    return 0;
}
