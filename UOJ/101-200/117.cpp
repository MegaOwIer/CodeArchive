#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;

struct edge{int to,next;}e[maxn<<2];
int n,m,d,tot=1,head[maxn],in[maxn],out[maxn],ans[maxn<<1],cnt,u;
char c;
bool vis[maxn<<1];

inline void read(int& x)
{
	x=0,c=getchar();
	while(!isdigit(c))c=getchar();
	while(isdigit(c))x=x*10+c-'0',c=getchar();
}
inline void dfs(int u)
{
	int j;
	for(int& i=head[u];i;i=e[i].next)if(!vis[i>>1])
		j=i,vis[j>>1]=1,dfs(e[j].to),ans[++cnt]=j;
}

int main()
{
	read(d),read(n),read(m);
	for(int i=1,v;i<=m;i++)
	{
		read(u),read(v);
		e[++tot]=(edge){v,head[u]},head[u]=tot;
		if(d&1)e[++tot]=(edge){u,head[v]},head[v]=tot,in[u]++,in[v]++;
		else ++tot,in[v]++,out[u]++;
	}
	if(d&1)
	{
		for(int i=1;i<=n;i++)
			if(in[i]&1)return puts("NO"),0;
	}
	else
	{
		for(int i=1;i<=n;i++)if(in[i]!=out[i])
			return puts("NO"),0;
	}
	dfs(u);
	if(cnt!=m)return puts("NO"),0;
	puts("YES");
	for(int i=cnt;i;i--)
		printf("%d ",ans[i]&1?-(ans[i]>>1):(ans[i]>>1));
	return 0;
}
