#include<bits/stdc++.h>
using namespace std;
const int MX=1000005;

int N,K,siz=1,fa[22][MX];
vector<int> G[MX];
bool vis[MX];

void dfs(int u,int f,int dep)
{
	for(int i=1;(1<<i)<=dep;i++)fa[i][u]=fa[i-1][fa[i-1][u]];
	for(int i:G[u])if(i!=f)fa[0][i]=u,dfs(i,u,dep+1);
}
int getdis(int u)
{
	int ans=0;
	for(int i=19;~i;i--)if(!vis[fa[i][u]])
		ans|=1<<i,u=fa[i][u];
	return ans+1;
}

int main()
{
	ios::sync_with_stdio(0);
	cin>>N>>K;
	for(int i=1,u,v;i<N;i++)
		cin>>u>>v,G[u].push_back(v),G[v].push_back(u);
	dfs(N,0,0);
	vis[0]=vis[N]=true;
	for(int i=N-1,tmp;i;i--)if(!vis[i])
	{
		tmp=getdis(i);
		if(siz+tmp>N-K)continue;
		siz+=tmp;
		for(int j=i;!vis[j];j=fa[0][j])vis[j]=true;
	}
	for(int i=1;i<=N;i++)if(!vis[i])cout<<i<<' ';
	return 0;
}
