#include<bits/stdc++.h>
using namespace std;

int n,ans,now,q[2002],h,t;
bool vis[2002];
char c;
vector<int> g[2002];
vector<int>::iterator it;

inline void getd(){do c=getchar();while(c<48||c>49);}
inline void bfs(int u)
{
	memset(vis+1,0,n),q[h=t=1]=u,ans++,vis[u]=1;
	while(h<=t)
	{
		now=q[h++];
		for(it=g[now].begin();it!=g[now].end();++it)
			if(!vis[*it])q[++t]=*it,ans++,vis[*it]=1;
	}
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++){getd();if(c==49)g[i].push_back(j);}
	for(int i=1;i<=n;i++)bfs(i);
	printf("%d",ans);
	return 0;
}
