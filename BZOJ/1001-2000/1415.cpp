#include<bits/stdc++.h>
using namespace std;
#define pb push_back
typedef vector<int>::iterator vit;
const int MX=1005;

int N,E,f[MX][MX],C,M;
double ans[MX][MX];
vector<int> G[MX];

inline void read(int& x)
{
	static char c;
	c=getchar(),x=0;
	while(!isdigit(c))c=getchar();
	while(isdigit(c))x=x*10+c-'0',c=getchar();
}
inline void prework(int S,int *pre)
{
	typedef pair<int,int> pii;
#define mp make_pair
	static int dis[MX],now;
	static char vis[MX];
	priority_queue<pii,vector<pii>,greater<pii> > q;
	memset(dis+1,0x3f,sizeof(int)*N);
	memset(vis+1,0,sizeof(char)*N);
	q.push(mp(dis[S]=0,S));
	while(!q.empty())
	{
		now=q.top().second,q.pop();
		if(vis[now])continue;
		vis[now]=1;
		for(vit i=G[now].begin();i!=G[now].end();i++)
			if(dis[now]+1<dis[*i])pre[*i]=now,q.push(mp(dis[*i]=dis[now]+1,*i));
			else if(dis[now]+1==dis[*i]&&now<pre[*i])pre[*i]=now;
	}
#undef mp
}
double solve(int x,int y)
{
	if(x==y)return ans[x][y]=0;
	if(f[x][y]==x||f[x][f[x][y]]==x)return ans[x][y]=1;
	if(ans[x][y]>1e-3)return ans[x][y];
	int u=f[x][f[x][y]];
	double res=0.0;
	for(vit i=G[x].begin();i!=G[x].end();i++)res+=solve(*i,u);
	return ans[x][y]=(res+solve(x,u))/(G[x].size()+1)+1;
}

int main()
{
	read(N),read(E),read(C),read(M);
	for(int i=1,u,v;i<=E;i++)
		read(u),read(v),G[u].pb(v),G[v].pb(u);
	for(int i=1;i<=N;i++)prework(i,f[i]);
	for(int i=1;i<=N;i++)memset(ans[i]+1,0xc2,sizeof(double)*N);
	printf("%.3lf\n",solve(M,C));
	return 0;
}