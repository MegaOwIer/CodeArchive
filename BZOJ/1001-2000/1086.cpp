#include<bits/stdc++.h>
using namespace std;
const int maxn=1005;

struct edge {int to,next;}e[maxn<<1];
int N,B,head[maxn],tot,cpt[maxn],bl[maxn],siz[maxn],cnt,q[maxn],top,win;

inline int read()
{
	int ans=0;  char ch=getchar();
	while(ch<'0'||ch>'9')  ch=getchar();
	while(ch>='0'&&ch<='9')  ans=ans*10+ch-'0',ch=getchar();
	return ans;
}
inline void add(int u,int v)
{
	e[++tot]=(edge){v,head[u]},head[u]=tot;
	e[++tot]=(edge){u,head[v]},head[v]=tot;
}
inline void dfs(int u,int fa)
{
	q[++top]=u;
	for(int i=head[u];i;i=e[i].next)  if(e[i].to!=fa)
	{
		dfs(e[i].to,u);
		siz[u]+=siz[e[i].to];
		if(siz[u]>=B)
		{
			siz[u]=0;
			cpt[++cnt]=u;
			while(q[top]!=u)  bl[q[top--]]=cnt;
		}
	}
	siz[u]++;
}
inline void dfs2(int u,int fa)
{
	if(bl[u])
	{
		win=bl[u];
		while(top)  bl[q[top--]]=win;
		return;
	}
	for(int i=head[u];i&&!win;i=e[i].next)  if(e[i].to!=fa)  dfs2(e[i].to,u);
}

int main()
{
	N=read(),B=read();
	if(N<B)  return puts("0"),0;
	if(N==B)
	{
		puts("1");
		for(int i=1;i<=N;i++)  putchar('1'),putchar(' ');puts("");
		return puts("1"),0;
	}
	for(int i=1,a,b;i<N;i++)  a=read(),b=read(),add(a,b);
	dfs(1,-1);
	if(!bl[1])  dfs2(1,-1);
	printf("%d\n",cnt);
	for(int i=1;i<=N;i++)  printf("%d ",bl[i]);
	puts("");
	for(int i=1;i<=cnt;i++)  printf("%d ",cpt[i]);
	return 0;
}
