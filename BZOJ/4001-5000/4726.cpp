#include<bits/stdc++.h>
using namespace std;
const int maxn=500005;

int fa[maxn],n,siz[maxn],k;
char c;
double ans[maxn],res;
vector<int> g[maxn];

inline void read(int& x)
{
	x=0,c=getchar();
	while(!isdigit(c))c=getchar();
	while(isdigit(c))x=x*10+c-'0',c=getchar();
}
inline void dfs(int u)
{
	siz[u]=1;
	for(vector<int>::iterator it=g[u].begin();it!=g[u].end();++it)
		dfs(*it),siz[u]+=siz[*it];
	if(!g[u].size())ans[u]=1.0;
	else for(vector<int>::iterator it=g[u].begin();it!=g[u].end();++it)
		 	 ans[u]=max(ans[u],min(1.0*siz[*it]/(siz[u]-1),ans[*it]));
	if(siz[u]>k)res=max(ans[u],res);
}

int main()
{
	read(n),read(k);
	for(int i=2;i<=n;i++)read(fa[i]),g[fa[i]].push_back(i);
	dfs(1);
	printf("%.8lf",res);
	return 0;
}
