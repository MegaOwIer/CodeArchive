#include<bits/stdc++.h>
using namespace std;
namespace FastIO
{
	static char c;
	static int top,buf[22];
	template<typename T>
	inline void read(T& x)
	{
		x=0,c=getchar();
		while(!isdigit(c))c=getchar();
		while(isdigit(c))x=x*10+c-'0',c=getchar();
	}
	template<typename T>
	inline void write(T x,int f=0)
	{
		top=0;
		do buf[top++]=x%10,x/=10;while(x);
		for(int i=top-1;~i;i--)putchar(buf[i]+48);
		if(f)putchar(f&1?' ':'\n');
	}
}
using FastIO::read;
using FastIO::write;

struct edge{int to,next,f;}e[502005];
int n,a[505],dp[505],ans1,S,T,tot=1,head[1005],cur[1005],dep[1005],now;
queue<int> q;

inline void add(int u,int v,int f)
{
	e[++tot]=(edge){v,head[u],f},head[u]=tot;
	e[++tot]=(edge){u,head[v],0},head[v]=tot;
}
inline bool bfs()
{
	memset(dep+1,-1,T<<2),dep[S]=0,q.push(S);
	while(!q.empty())
	{
		now=q.front(),q.pop();
		for(int i=head[now];i;i=e[i].next)if(e[i].f&&!~dep[e[i].to])
			dep[e[i].to]=dep[now]+1,q.push(e[i].to);
	}
	return ~dep[T];
}
inline int dfs(int u,int f)
{
	if(u==T||!f)return f;
	int w,used=0;
	for(int &i=cur[u];i;i=e[i].next)if(dep[e[i].to]==dep[u]+1&&e[i].f)
	{
		w=dfs(e[i].to,min(f-used,e[i].f));
		used+=w,e[i].f-=w,e[i^1].f+=w;
		if(used==f)return f;
	}
	if(!used)dep[u]=-1;
	return used;
}
inline int Dinic()
{
	int ans=0;
	while(bfs())memcpy(cur+1,head+1,T<<2),ans+=dfs(S,2e9);
	return ans;
}

int main()
{
	read(n),T=1+(S=n<<1|1);
	for(int i=1;i<=n;i++)read(a[i]);
	for(int i=1;i<=n;i++)for(int j=0;j<i;j++)
		if(a[j]<=a[i])dp[i]=max(dp[i],dp[j]+1);
	for(int i=1;i<=n;i++)ans1=max(ans1,dp[i]);
	write(ans1,2);
	if(ans1==1)return write(n,2),write(n),0;
	for(int i=1;i<=n;i++)
	{
		if(dp[i]==1)add(S,i,1);
		if(dp[i]==ans1)add(i+n,T,1);
		add(i,i+n,1);
		for(int j=1;j<i;j++)if(dp[j]+1==dp[i]&&a[j]<=a[i])add(j+n,i,1);
	}
	write(Dinic(),2);
	tot=1,memset(head+1,0,T<<2);
	for(int i=1;i<=n;i++)
	{
		if(i==n||i==1)
		{
			if(dp[i]==1)add(S,i,1e9);
			if(dp[i]==ans1)add(i+n,T,1e9);
			add(i,i+n,1e9);
		}
		else
		{
			if(dp[i]==1)add(S,i,1);
			if(dp[i]==ans1)add(i+n,T,1);
			add(i,i+n,1);
		}
		for(int j=1;j<i;j++)if(dp[j]+1==dp[i]&&a[j]<=a[i])add(j+n,i,1);
	}
	write(Dinic());
	return 0;
}
