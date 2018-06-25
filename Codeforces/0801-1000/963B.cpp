#include<bits/stdc++.h>
using namespace std;
const int MX=200005;
typedef pair<int,int> pii;

int N,RT,siz[MX],po[MX],deg[MX];
vector<int> son[MX];
set<pii> S;

void dfs(int u)
{
	static int cnt=0;
	int dfn=++cnt,flag=1;
	siz[u]=1;
	S.insert(make_pair(dfn,u));
	for(int i:son[u])
	{
		deg[i]=1,dfs(i);
		if(siz[i])
		{
			deg[u]^=1,siz[u]+=siz[i];
			flag&=(siz[i]&1);
		}
	}
	if(deg[u]==0&&flag)
	{
		siz[u]=0;
		while(1)
		{
			auto it=S.lower_bound(make_pair(dfn,-1));
			if(it==S.end()||it->first>cnt)break;
			cout<<it->second<<'\n';
			S.erase(it);
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin>>N;
	if(N%2==0)return puts("NO"),0;
	cout<<"YES"<<endl;
	for(int i=1,x;i<=N;i++)
	{
		cin>>x;
		if(!x)RT=i;
		else son[x].push_back(i);
	}
	dfs(RT);
	assert(S.empty());
	return 0;
}