#include<bits/stdc++.h>
using namespace std;
const int maxn=100005;

struct edge{int to,next;}e[maxn<<1];
int n,pos,tot,head[maxn],in[maxn],out[maxn],cnt,tr[maxn<<1];
char c;

inline void read(int& x)
{
	x=0,c=getchar();
	while(!isdigit(c))c=getchar();
	while(isdigit(c))x=x*10+c-'0',c=getchar();
}
inline void add(int u,int v)
{
	e[++tot]=(edge){v,head[u]},head[u]=tot;
	e[++tot]=(edge){u,head[v]},head[v]=tot;
}
inline void dfs(int u,int fa)
{
	in[u]=++cnt;
	for(int i=head[u];i;i=e[i].next)if(e[i].to!=fa)dfs(e[i].to,u);
	out[u]=++cnt;
}
inline void insert(int u,int v){for(;u<=n*2;u+=(u&(-u)))tr[u]+=v;}
inline int sum(int x){if(!x)return 0;int ans=0;for(;x;x-=(x&(-x)))ans+=tr[x];return ans;}

int main()
{
	read(n);
	for(int i=1,u,v;i<n;i++)read(u),read(v),add(u,v);
	dfs(1,-1);
	for(int i=1;i<=n;i++)
	{
		read(pos);
		printf("%d\n",sum(in[pos]-1));
		insert(in[pos],1),insert(out[pos],-1);
	}
	return 0;
}
