#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;

struct edge
{
	int st,en,len;
}side[10000];
int n,g,fa[1000],cnt;
long long ans;
bool cmp(edge u,edge v)  {return u.len<v.len;}
int find(int u)  {return u==fa[u]?u:fa[u]=find(fa[u]);}

int main()
{
	while(scanf("%d",&n)==1)
	{
		ans=cnt=0;
	    for(int i=1;i<=n;i++)
	    {
		    fa[i]=i;
	        for(int j=1;j<=n;j++)
	        {
	        	cin>>g;
	    	    if(!g&&i>=j)  continue;
	    	    side[++cnt].st=i;  side[cnt].en=j;  side[cnt].len=g;
	        }
	    }
	    sort(side+1,side+cnt+1,cmp);
	    for(int i=1;i<=cnt;i++)
    	{
		    int x=find(side[i].st),y=find(side[i].en);
		    if(x==y)  continue;
		    fa[x]=y;
		    ans+=side[i].len;
	    }
	    cout<<ans<<endl;
    }
	return 0;
}
