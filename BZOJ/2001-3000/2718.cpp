#include<bits/stdc++.h>
using namespace std;
namespace FastIO
{
	static char c;
	static int buf[22],top;
	template<typename T>inline void read(T& x)
	{
		x=0,c=getchar();
		while(!isdigit(c))c=getchar();
		while(isdigit(c))x=x*10+c-'0',c=getchar();
	}
	template<typename T>inline void write(T x)
	{
		top=0;
		do buf[top++]=x%10,x/=10;while(x);
		while(top)putchar(48+buf[--top]);
	}
}
using FastIO::read;
using FastIO::write;
const int maxn=205;

int n,m,ans,lf[205];
bitset<maxn> g[maxn];
bool vis[205];

bool find(int x)
{
	for(int i=1;i<=n;i++)if(g[x][i]&&!vis[i])
	{
		vis[i]=1;
		if(!lf[i]||find(lf[i]))
		{
			lf[i]=x;
			return 1;
		}
	}
	return 0;
}

int main()
{
	read(n),read(m),ans=n;
	for(int i=1;i<=n;i++)g[i].reset();
	for(int i=1,u,v;i<=m;i++)read(u),read(v),g[u][v]=1;
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)if(g[j][i])g[j]|=g[i];
	for(int i=1;i<=n;i++)
	{
		memset(vis+1,0,n);
		if(find(i))ans--;
	}
	write(ans);
	return 0;
}
