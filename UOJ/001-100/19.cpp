#include<bits/stdc++.h>
using namespace std;
const int maxm=200005,maxn=10005;

struct edge{int to,next;}e[maxm],r[maxm];
int n,m,heade[maxn],headr[maxn],S,T,dis[maxn];
char c;
queue<int> q;
bool vis[maxn],inq[maxn],fail[maxn];

inline void read(int& x)
{
	x=0,c=getchar();
	while(!isdigit(c))c=getchar();
	while(isdigit(c))x=x*10+c-'0',c=getchar();
}

int main()
{
	read(n),read(m);
	for(int i=1,u,v;i<=m;i++)
	{
		read(u),read(v);
		e[i]=(edge){v,heade[u]},heade[u]=i;
		r[i]=(edge){u,headr[v]},headr[v]=i;
	}
	read(S),read(T);
	q.push(T),vis[T]=1;
	while(!q.empty())
	{
		int now=q.front();q.pop();
		for(int i=headr[now];i;i=r[i].next)if(!vis[r[i].to])
			vis[r[i].to]=1,q.push(r[i].to);
	}
	for(int i=1;i<=n;i++)if(!vis[i])
		for(int j=headr[i];j;j=r[j].next)fail[r[j].to]=1;
	if(!vis[S]||fail[S])return puts("-1"),0;
	memset(dis+1,0x3f,n<<2),dis[S]=0;
	q.push(S);
	while(!q.empty())
	{
		int now=q.front();q.pop(),inq[now]=0;
		for(int i=heade[now];i;i=e[i].next)if(dis[e[i].to]>dis[now]+1&&vis[e[i].to]&&!fail[e[i].to])
		{
			dis[e[i].to]=dis[now]+1;
			if(!inq[e[i].to])inq[e[i].to]=1,q.push(e[i].to);
		}
	}
	printf("%d",dis[T]>n?-1:dis[T]);
	return 0;
}
