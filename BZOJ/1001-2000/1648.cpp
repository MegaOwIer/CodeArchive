#include<bits/stdc++.h>
using namespace std;
namespace FastIO
{
	static char c;
	static int top,buf[22];
	template<typename T>inline void read(T& x)
	{
		x=0,c=getchar();
		while(!isdigit(c))c=getchar();
		while(isdigit(c))x=x*10+c-'0',c=getchar();
	}
	template<typename T>inline void write(T x)
	{
		top=0;
		do buf[++top]=x%10,x/=10;while(x);
		while(top)putchar(48+buf[top--]);
	}
}
using FastIO::read;
using FastIO::write;

struct edge{int to,next;}e[10005];
int K,N,M,tot,head[1005],a[105],cnt[1005],now,ans;
queue<int> q;
bool vis[1005];

int main()
{
	read(K),read(N),read(M);
	for(int i=1;i<=K;i++)read(a[i]);
	for(int i=1,u,v;i<=M;i++)
		read(u),read(v),e[++tot]=(edge){v,head[u]},head[u]=tot;
	for(int i=1;i<=K;i++)
	{
		q.push(a[i]),memset(vis+1,0,N),vis[a[i]]=1;
		while(!q.empty())
		{
			now=q.front(),q.pop(),cnt[now]++;
			for(int i=head[now];i;i=e[i].next)
				if(!vis[e[i].to])vis[e[i].to]=1,q.push(e[i].to);
		}
	}
	for(int i=1;i<=N;i++)if(cnt[i]==K)ans++;
	write(ans);
	return 0;
}
