#include<bits/stdc++.h>
using namespace std;
const int maxn=200005;
#define clear(a) memset(a,0,sizeof(a))

struct edge {int to,next,w;}e[maxn<<1];
int n,m,head[maxn],tot,cnt,now,pa,pb,mx;
long long disa[maxn],disb[maxn],ans;
bool vis[maxn];
queue<int> q;

inline int read()
{
	char ch=getchar();  int ans=0;
	while(ch<'0'||ch>'9')  ch=getchar();
	while(ch>='0'&&ch<='9')  ans=ans*10+ch-'0',ch=getchar();
	return ans;
}
inline void add(int u,int v,int w)
{
	e[++tot]=(edge){v,head[u],w},head[u]=tot;
	e[++tot]=(edge){u,head[v],w},head[v]=tot;
}
int bfs(int u,long long dis[])
{
	clear(vis);  while(!q.empty())  q.pop();
	cnt=n-1;  q.push(u);  vis[u]=1;  mx=0;
	while(cnt)
	{
		now=q.front();  q.pop();
		for(int i=head[now];i;i=e[i].next)  if(!vis[e[i].to])
		{
			vis[e[i].to]=1;  cnt--;
			q.push(e[i].to);
			dis[e[i].to]=dis[now]+e[i].w;
		}
	}
	for(int i=1;i<=n;i++)  if(dis[i]>dis[mx])  mx=i;
	return mx;
}

int main()
{
	n=read(),m=read();
	for(int i=1,a,b,c;i<=m;i++)  a=read(),b=read(),c=read(),add(a,b,c);
	pa=bfs(1,disa);  clear(disa);
	pb=bfs(pa,disa);
	bfs(pb,disb);
	for(int i=1;i<=n;i++)  ans=max(ans,min(disa[i],disb[i]));
	printf("%lld",ans+disb[pa]);
	return 0;
}
