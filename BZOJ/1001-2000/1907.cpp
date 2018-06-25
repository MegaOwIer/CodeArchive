#include<bits/stdc++.h>
using namespace std;
const int maxn=10005;

struct edge{int to,next;}e[maxn<<1];
int T,n,head[maxn],tot,ans[maxn];
char c;
bool vis[maxn];

inline void read(int& x)
{
	x=0,c=getchar();
	while(c<'0'||c>'9')c=getchar();
	while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
}
inline void add(int u,int v)
{
	e[++tot]=(edge){v,head[u]},head[u]=tot;
	e[++tot]=(edge){u,head[v]},head[v]=tot;
}
inline void init()
{
	tot=0,memset(head+1,0,n<<2);
	memset(ans+1,0,n<<2),memset(vis+1,0,n);
}
inline void dfs(int u,int fa)
{
	ans[u]=1;int tt=0;
	for(int i=head[u];i;i=e[i].next)if(e[i].to!=fa)
	{
		dfs(e[i].to,u);
		ans[u]+=ans[e[i].to];
		if(!vis[e[i].to])tt++;
	}
	if(tt>=2)ans[u]-=2,vis[u]=1;
	else if(tt==1)ans[u]--;
}

int main()
{
	read(T);
	while(T--)
	{
		read(n),init();
		for(int i=1,a,b;i<n;i++)read(a),read(b),add(a,b);
		dfs(1,-1);
		printf("%d\n",ans[1]);
	}
	return 0;
}
