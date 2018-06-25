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
	template<typename T>inline void write(T x,int f=0)
	{
		top=0;
		do buf[top++]=x%10,x/=10;while(x);
		while(top)putchar(48+buf[--top]);
		putchar(f?'\n':' ');
	}
}
using FastIO::read;
using FastIO::write;
const int MX=505;
#define pb push_back

int N,M,match[MX],ans,pre[MX],fa[MX],x,y,type[MX],q[MX],h,t,p,T,path[MX];
vector<int> g[MX];
vector<int>::iterator it;

int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
inline int lca(int x,int y)
{
	for(T++;;swap(x,y))if(x)
	{
		x=find(x);
		if(path[x]==T)return x;
		path[x]=T;
		x=(match[x]?pre[match[x]]:0);
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
	q[h=t=1]=u,memset(type+1,-1,N<<2),type[u]=0;
	for(int i=1;i<=N;i++)fa[i]=i;
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
						tmp=match[c=pre[now]],match[now]=c,match[c]=now;
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
	read(N),read(M);
	for(int i=1,u,v;i<=M;i++)read(u),read(v),g[u].pb(v),g[v].pb(u);
	for(int i=1;i<=N;i++)if(!match[i]&&bfs(i))ans++;
	write(ans,1);
	for(int i=1;i<=N;i++)write(match[i]);
	return 0;
}
