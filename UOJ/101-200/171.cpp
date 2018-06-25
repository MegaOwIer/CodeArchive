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
	template<typename T>inline void write(T x,int f=1)
	{
		top=0;
		do buf[top++]=x%10,x/=10;while(x);
		while(top)putchar(48+buf[--top]);
		putchar(f?' ':'\n');
	}
}
using FastIO::read;
using FastIO::write;
const int maxn=605;
#define pb push_back
#define add(a,b) g[a].pb(b),g[b].pb(a)

int cas,N,M,E,tot,ans,q[maxn],h,t,type[maxn],fa[maxn],x,y,p,match[maxn],pre[maxn],T,path[maxn];
vector<int> g[maxn];
vector<int>::iterator it;

int find(int u){return u==fa[u]?u:fa[u]=find(fa[u]);}
inline int lca(int x,int y)
{
	for(T++;;swap(x,y))if(x)
	{
		x=find(x);
		if(path[x]==T)return x;
		path[x]=T;
		x=match[x]?pre[match[x]]:0;
	}
}
inline void shrink(int x,int y,int k)
{
	int z;
	while(find(x)!=k)
	{
		pre[x]=y,z=match[x];
		if(type[z]==1)q[++t]=z,type[z]=0;
		if(find(x)==x)fa[x]=k;
		if(find(z)==z)fa[z]=k;
		y=z,x=pre[y];
	}
}
inline bool bfs(int u)
{
	q[h=t=1]=u,memset(type+1,-1,tot<<2),type[u]=0;
	for(int i=1;i<=tot;i++)fa[i]=i;
	while(h<=t)
	{
		x=q[h++];
		for(it=g[x].begin();it!=g[x].end();++it)
		{
			y=*it;
			if(!~type[y])
			{
				type[y]=1,pre[y]=x;
				if(!match[y])
				{
					for(int now=y,tmp,c;now;now=tmp)
						tmp=match[c=pre[now]],match[c]=now,match[now]=c;
					return 1;
				}
				type[match[y]]=0,q[++t]=match[y];
			}
			else if(!type[y]&&find(x)!=find(y))
				p=lca(x,y),shrink(x,y,p),shrink(y,x,p);
		}
	}
	return 0;
}

int main()
{
	read(cas);
	while(cas--)
	{
		read(N),read(M),read(E),tot=3*M+N;
		ans=0,T=0;
		for(int i=1;i<=tot;i++)g[i].clear();
		memset(match+1,0,tot<<2),memset(path+1,0,tot<<2);
		for(int i=1;i<=M;i++)
			add(N+i*3,N+i*3-1),add(N+i*3-1,N+i*3-2),add(N+i*3-2,N+i*3);
		for(int i=1,u,v;i<=E;i++)
			read(v),read(u),add(v,N+3*u),add(v,N+3*u-1),add(v,N+3*u-2);
		for(int i=1;i<=tot;i++)if(!match[i])ans+=bfs(i);
		write(ans-N,0);
		for(int i=1;i<=N;i++)write((match[i]-1-N)/3+1);
		putchar('\n');
	}
	return 0;
}
