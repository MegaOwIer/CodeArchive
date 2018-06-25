#include<bits/stdc++.h>
using namespace std;
const int maxn=100005;

struct edge {int to,next;}e[maxn];
int n,tot,head[maxn],dp[maxn];
char C;

inline void read(int& x)
{
	x=0,C=getchar();
	while(C<'0'||C>'9')C=getchar();
	while(C>='0'&&C<='9')x=x*10+C-'0',C=getchar();
}
inline void add(int u,int v){e[++tot]=(edge){v,head[u]},head[u]=tot;}
inline void dfs(int u)
{
	bool lvs=1;
	vector<int> q;q.clear();
	for(int i=head[u];i;i=e[i].next)
	{
		lvs=0,dfs(e[i].to);
		q.push_back(dp[e[i].to]);
	}
	if(lvs)return;
	sort(q.begin(),q.end(),greater<int>());
	for(int i=0;i<q.size();i++)dp[u]=max(dp[u],q[i]+i+1);
}

int main()
{
	read(n);
	for(int i=2,b;i<=n;i++)read(b),add(b,i);
	dfs(1);
	printf("%d",dp[1]);
	return 0;
}
