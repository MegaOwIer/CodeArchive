#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+5;

struct edge{int to,w;}e[maxn<<3];
int n,m,S,T,f,tot=1,dep[maxn],ans,q[maxn],h,t;
vector<int> g[maxn];
vector<int>::iterator cur[maxn];
char c;

inline void read(int& x)
{
	c=getchar(),x=0,f=1;
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c))x=x*10+c-'0',c=getchar();x*=f;
}
inline void add(int u,int v,int w)
{
	e[++tot]=(edge){v,w},g[u].push_back(tot);
	e[++tot]=(edge){u,0},g[v].push_back(tot);
}
inline bool bfs()
{
	memset(dep,-1,sizeof(dep));
	q[h=t=1]=S,dep[S]=0;
	while(h<=t)
	{
		int now=q[h++];
		for(vector<int>::iterator it=g[now].begin();it!=g[now].end();++it)
			if(!~dep[e[*it].to]&&e[*it].w)dep[e[*it].to]=dep[now]+1,q[++t]=e[*it].to;
	}
	return ~dep[T];
}
int dfs(int u,int flow)
{
	if(u==T||flow==0)return flow;
	int used=0,w;
	for(vector<int>::iterator &it=cur[u];it!=g[u].end();++it)if(dep[e[*it].to]==dep[u]+1)
	{
		w=dfs(e[*it].to,min(flow-used,e[*it].w));
		e[*it].w-=w,e[*it^1].w+=w;
		used+=w;
		if(used==flow)return flow;
	}
	if(!used)dep[u]=-1;
	return used;
}

int main()
{
	read(n),read(m),read(S),read(T);
	for(int i=1,u,v,w;i<=m;i++)read(u),read(v),read(w),add(u,v,w);
	while(bfs())
	{
		for(int i=1;i<=n;i++)cur[i]=g[i].begin();
		ans+=dfs(S,1e9);
	}
	printf("%d",ans);
	return 0;
}
