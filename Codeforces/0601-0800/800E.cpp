#include<bits/stdc++.h>
using namespace std;
#define REF(i,u) for(int i=head[u];i;i=e[i].next)  if(e[i].to!=fa)  
const int maxn=100005;

struct edge {int to,next;}e[maxn<<1];
int tot,head[maxn],n,a[maxn],fa[maxn],siz[maxn],mx[maxn];
map<int,int>* c[maxn];
long long ans[maxn];

inline void add(int u,int v)
{
	e[++tot]=(edge){v,head[u]},head[u]=tot;
	e[++tot]=(edge){u,head[v]},head[v]=tot;
}
inline void dfs(int u,int fa)
{
	siz[u]=1;
	REF(i,u)dfs(e[i].to,u),siz[u]+=siz[e[i].to];
}
inline void INS(int u,int col,int C)
{
	int t=((*(c[u]))[col]+=C);
	if(t>mx[u])  mx[u]=t,ans[u]=col;
	else  if(t==mx[u])  ans[u]+=col;
}
inline void dfswk(int u,int fa)
{
	int mxssz=0,mxs=0;
	REF(i,u)  if(siz[e[i].to]>mxssz)  mxssz=siz[e[i].to],mxs=e[i].to;
	if(mxs)
	{
		dfswk(mxs,u);
		c[u]=c[mxs];  mx[u]=mx[mxs];  ans[u]=ans[mxs];
		INS(u,a[u],1);
		REF(i,u)  if(e[i].to!=mxs)
		{
			dfswk(e[i].to,u);
			for(map<int,int>::iterator it=c[e[i].to]->begin();it!=c[e[i].to]->end();++it)
				INS(u,it->first,it->second);
		}
	}
	else
	{
		c[u]=new map<int,int>;
		c[u]->clear();
		INS(u,a[u],1);
	}
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)  scanf("%d",a+i);
	for(int i=1,u,v;i<n;i++)  scanf("%d%d",&u,&v),add(u,v);
	dfs(1,-1);
	dfswk(1,-1);
	for(int i=1;i<=n;i++)  printf("%lld ",ans[i]);
	return 0;
}
