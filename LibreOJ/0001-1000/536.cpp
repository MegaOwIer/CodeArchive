#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;

struct edge{int to,w;}e[480005];
int m,c,n1,n2,S,T,l[40005][2],r[40005][2],tot=1,dep[maxn],q[maxn<<3],h,t,now,dis[maxn];
char ch;
bool inq[maxn];
vector<int> g[maxn];
vector<int>::iterator cur[maxn];

inline void read(int& x)
{
	x=0,ch=getchar();
	while(!isdigit(ch))ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
}
inline void add(int u,int v)
{
	e[++tot]=(edge){v,1},g[u].push_back(tot);
	e[++tot]=(edge){u,0},g[v].push_back(tot);
}
inline bool bfs()
{
	memset(dep+1,-1,T<<2),q[h=t=1]=S,dep[S]=0;
	while(h<=t)
	{
		now=q[h++];
		for(vector<int>::iterator it=g[now].begin();it!=g[now].end();++it)
			if(e[*it].w&&!~dep[e[*it].to])dep[e[*it].to]=dep[now]+1,q[++t]=e[*it].to;
	}
	return ~dep[T];
}
inline int dfs(int u,int flow)
{
	if(u==T||!flow)return flow;
	int used=0,w;
	for(vector<int>::iterator &it=cur[u];it!=g[u].end();++it)if(dep[e[*it].to]==dep[u]+1)
	{
		w=dfs(e[*it].to,min(e[*it].w,flow-used));
		e[*it].w-=w,e[*it^1].w+=w;
		used+=w;
		if(used==flow)return flow;
	}
	if(!used)dep[u]=-1;
	return used;
}
void spfa()
{
	q[h=t=1]=S,memset(dis+1,0x3f,T<<2),dis[S]=0;
	while(h<=t)
	{
		now=q[h++],inq[now]=0;
		for(vector<int>::iterator it=g[now].begin();it!=g[now].end();++it)
			if(e[*it].w&&dis[e[*it].to]>dis[now]+e[*it].w)
			{
				dis[e[*it].to]=dis[now]+e[*it].w;
				if(!inq[e[*it].to])q[++t]=e[*it].to,inq[e[*it].to]=1;
			}
	}
}

int main()
{
	read(m),read(c);
	read(n1);
	for(int i=1;i<=n1;i++)read(l[i][0]),read(l[i][1]);
	read(n2);
	for(int i=1;i<=n2;i++)read(r[i][0]),read(r[i][1]);
	T=(S=n1+n2+m+c+1)+1;
	for(int i=1;i<=n1;i++)
		add(S,i),add(i,n1+n2+l[i][0]),add(i,n1+n2+m+l[i][1]);
	for(int i=1;i<=n2;i++)
		add(n1+n2+r[i][0],i+n1),add(n1+n2+m+r[i][1],n1+i),add(n1+i,T);
	int ans=0;
	while(bfs())
	{
		for(int i=1;i<=T;i++)cur[i]=g[i].begin();
		ans+=dfs(S,1e9);
	}
	spfa();
	for(vector<int>::iterator it=g[S].begin();it!=g[S].end();++it)
		puts(!e[*it].w&&dis[e[*it].to]>maxn?"1":"0");
	return 0;
}
