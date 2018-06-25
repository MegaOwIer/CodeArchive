#include<bits/stdc++.h>
using namespace std;
const int maxn=100005;

struct edge{int to,next;}e[maxn<<1];
int n,m,tot,head[maxn],in[maxn],out[maxn],dp[maxn],ans;
char c;
queue<int> q;

inline void read(int& x)
{
	c=getchar(),x=0;
	while(!isdigit(c))c=getchar();
	while(isdigit(c))x=x*10+c-48,c=getchar();
}
inline void add(int u,int v)
{
	e[++tot]=(edge){v,head[u]},head[u]=tot;
	in[v]++,out[u]++;
}

int main()
{
	read(n),read(m);
	for(int i=1,u,v;i<=m;i++)read(u),read(v),add(u,v);
	for(int i=1;i<=n;i++)if(!in[i]&&out[i])dp[i]=1,q.push(i);
	while(!q.empty())
	{
		int now=q.front();q.pop();
		for(int i=head[now];i;i=e[i].next)
		{
			in[e[i].to]--,dp[e[i].to]+=dp[now];
			if(!in[e[i].to])
				if(out[e[i].to])q.push(e[i].to);
				else ans+=dp[e[i].to];
		}
	}
	printf("%d",ans);
	return 0;
}
