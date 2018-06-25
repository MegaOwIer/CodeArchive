#include<bits/stdc++.h>

int nl,nr,m,lk[505],ans;
bool g[505][505],vis[505];

inline int find(int u)
{
	for(int i=1;i<=nl;i++)if(g[u][i]&&!vis[i])
	{
		vis[i]=1;
		if(!lk[i]||find(lk[i])){lk[i]=u;return 1;}
	}
	return 0;
}

int main()
{
	scanf("%d%d%d",&nl,&nr,&m);
	for(int i=1,u,v;i<=m;i++)scanf("%d%d",&u,&v),g[v][u]=1;
	for(int i=1;i<=nr;i++)memset(vis+1,0,nl),ans+=find(i);
	printf("%d\n",ans);
	for(int i=1;i<=nl;i++)printf("%d ",lk[i]);
	return 0;
}
