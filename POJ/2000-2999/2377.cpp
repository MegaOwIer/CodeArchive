#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

struct Edge{int st,en,len;}ed[20010];
bool cmp(Edge u,Edge v)  {return  u.len>v.len;}
int m,n,fa[1010],cnt;
long long ans;
int find(int x)  {return x==fa[x]?fa[x]:fa[x]=find(fa[x]);}

int main()
{
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		bool fl=0;
		ans=0;
		for(int i=1;i<=n;i++)  fa[i]=i;
		for(int i=1,aa,b,c;i<=m;i++)
		{
		    scanf("%d%d%d",&aa,&b,&c);
		    ed[i].st=aa;
			ed[i].en=b;
			ed[i].len=c;
		}
		sort(ed+1,ed+m+1,cmp);
		for(int i=1;i<=m;i++)
		{
			int x=find(ed[i].st),y=find(ed[i].en);
			if(x==y)  continue;
			fa[y]=x;
			ans+=ed[i].len;
			cnt++;
			if(cnt==n-1)  break;
		}
		if(cnt!=n-1)  printf("-1\n");
		else  printf("%lld\n",ans);
    }
    return 0;
}
