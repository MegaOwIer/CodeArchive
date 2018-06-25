#include<bits/stdc++.h>
using namespace std;
const int maxn=10005;

struct edge {int to,next,w;}e[maxn<<3];
int n,m,tot=1,head[maxn<<1],cur[maxn<<1],mn=1,mx,dis[maxn<<1];
char c;
queue<int> q;

inline void read(int& x)
{
	x=0,c=getchar();
	while(c<'0'||c>'9')c=getchar();
	while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
}
inline void add(int u,int v,int w)
{
	e[++tot]=(edge){v,head[u],w},head[u]=tot;
	e[++tot]=(edge){u,head[v],0},head[v]=tot;
}
inline bool bfs()
{
	memset(dis+1,-1,(n+m+2)<<2);
	q.push(n+m+1),dis[n+m+1]=0;
	while(!q.empty())
	{
		int now=q.front();q.pop();
		for(int i=head[now];i;i=e[i].next)if(e[i].w>0&&dis[e[i].to]<0)
		{
			dis[e[i].to]=dis[now]+1;
			q.push(e[i].to);
		}
	}
	return ~dis[n+m+2];
}
inline int dfs(int u,int val)
{
	int tmp=val,a=0;
	if(u==m+n+2)return val;
	for(int i=cur[u];i;i=e[i].next)if(dis[e[i].to]==dis[u]+1&&e[i].w)
	{
		a=dfs(e[i].to,min(tmp,e[i].w));
		e[i].w-=a,e[i^1].w+=a,tmp-=a;
		if(e[i].w)cur[u]=i;
		if(!tmp)return val;
	}
	if(val==tmp)dis[u]=-1;
	return val-tmp;
}
inline bool check(int u)
{
	int ans=0;
	while(bfs())
	{
		for(int i=1;i<n+m+3;i++)cur[i]=head[i];
		ans+=dfs(m+n+1,0x7fffffff);
	}
	return ans>=m;
}

int main()
{
	read(n),read(m),mx=m;
	for(int i=1;i<=n;i++)add(m+n+1,i,0);
	for(int i=1,a,b;i<=m;i++)read(a),read(b),add(a,n+i,1),add(b,n+i,1),add(n+i,n+m+2,1);
	while(mn<mx)
	{
		int mid=mn+mx>>1;
		for(int i=2;i<2+2*n;i++)e[i].w=(i&1)?0:mid;
		for(int i=2+2*n;i<=tot;i++)e[i].w=(i&1)?0:1;
		if(check(mid))mx=mid;
		else mn=mid+1;
	}
	printf("%d",mx);
	return 0;
}
