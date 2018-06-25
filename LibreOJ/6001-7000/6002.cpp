#include<bits/stdc++.h>
using namespace std;
namespace FastIO
{
	static char c;
	template<typename T>
	inline void read(T& x)
	{
		x=0,c=getchar();
		while(!isdigit(c))c=getchar();
		while(isdigit(c))x=x*10+c-'0',c=getchar();
	}
}
using FastIO::read;

int n,m,g[205][205],lft[205],ans,rgt[205];
bool vis[205];

inline bool find(int u)
{
	for(int i=1;i<=n;i++)if(!vis[i]&&g[u][i])
	{
		vis[i]=1;
		if(!lft[i]||find(lft[i]))
		{
			lft[i]=u;
			return 1;
		}
	}
	return 0;
}

int main()
{
	read(n),read(m),ans=n;
	for(int i=1,u,v;i<=m;i++)read(u),read(v),g[u][v]=1;
	for(int i=1;i<=n;i++)
	{
		memset(vis+1,0,n);
		if(find(i))ans--;
	}
	for(int i=1;i<=n;i++)rgt[lft[i]]=i;
	for(int i=1;i<=n;i++)if(!lft[i])
	{
		printf("%d ",i);
		for(int j=i;rgt[j];j=rgt[j])printf("%d ",rgt[j]);
		putchar('\n');
	}
	printf("%d",ans);
	return 0;
}
