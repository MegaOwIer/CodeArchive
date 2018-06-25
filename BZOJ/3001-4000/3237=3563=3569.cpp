#include<bits/stdc++.h>
using namespace std;
typedef unsigned ULL;
const int MX=100005;

namespace FastIO
{
	char c;
	template<typename T>inline void read(T& x)
	{
		x=0,c=getchar();
		while(!isdigit(c))c=getchar();
		while(isdigit(c))x=x*10+c-'0',c=getchar();
	}
}
using FastIO::read;

struct edge{int to,nxt;}e[MX*5];
int N,M,tot,head[MX],fa[MX],ans,a[MX*5],b[MX],T,c[20],k;
char vis[MX];

inline void add(int u,int v)
{
	e[++tot]=(edge){v,head[u]},head[u]=tot;
}
inline void dfs1(int u)
{
	vis[u]=1;
	for(int i=head[u];i;i=e[i].nxt)
		if(!vis[e[i].to])dfs1(e[i].to);
		else a[i]=rand(),b[u]^=a[i],b[e[i].to]^=a[i];
}
inline void dfs2(int u)
{
	vis[u]=1;
	for(int i=head[u];i;i=e[i].nxt)if(!vis[e[i].to])
		dfs2(e[i].to),a[i]^=b[e[i].to],b[u]^=b[e[i].to];
}
inline bool check()
{
	int now=0;
	for(int i=1<<30,j;i;i>>=1)
	{
		for(j=now+1;j<=k;j++)if(c[j]&i)break;
		if(j==k+1)continue;
		swap(c[j],c[++now]);
		for(j=1;j<=k;j++)if(j!=now&&c[j]&i)c[j]^=c[now];
	}
	return !c[k];
}

int main()
{
	read(N),read(M);
	for(int i=1,u,v;i<=M;i++)
	{
		read(u),read(v);
		if(u>v)swap(u,v);
		add(u,v);
	}
	dfs1(1),memset(vis+1,0,sizeof(char)*N),dfs2(1);
	read(T);
	while(T--)
	{
		read(k);   //k^=ans;    //BZOJ3563
		for(int i=1,x;i<=k;i++)
            //read(x),c[i]=a[x^ans];   //BZOJ3569
            read(x),c[i]=a[x];       //BZOJ3237
		if(check())puts("Disconnected");
		else ans++,puts("Connected");
	}
	return 0;
}