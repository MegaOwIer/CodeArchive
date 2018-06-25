#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

struct edge{int to,w;}e[12405];
int n,m,tot,S,T;
LL dis[2505];
char c;
bool inq[2505];
vector<int> g[2505];
queue<int> q;
vector<int>::iterator it;

inline void read(int& x)
{
	c=getchar(),x=0;
	while(!isdigit(c))c=getchar();
	while(isdigit(c))x=x*10+c-'0',c=getchar();
}

int main()
{
	read(n),read(m),read(S),read(T);
	for(int i=1,u,v,w;i<=m;i++)
	{
		read(u),read(v),read(w);
		e[++tot]=(edge){v,w},g[u].push_back(tot);
		e[++tot]=(edge){u,w},g[v].push_back(tot);
	}
	fill(dis+1,dis+n+1,1e18),dis[S]=0;
	q.push(S),inq[S]=1;
	while(!q.empty())
	{
		int now=q.front();q.pop(),inq[now]=0;
		for(it=g[now].begin();it!=g[now].end();++it)
			if(dis[e[*it].to]>dis[now]+e[*it].w)
			{
				dis[e[*it].to]=dis[now]+e[*it].w;
				if(!inq[e[*it].to])inq[e[*it].to]=1,q.push(e[*it].to);
			}
	}
	printf("%lld",dis[T]);
	return 0;
}
