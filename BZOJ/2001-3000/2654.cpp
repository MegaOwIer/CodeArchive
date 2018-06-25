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
const int maxn=5e4+5,maxm=1e5+5;

struct edge{int u,v,w,c;}e[maxm];
int n,m,need,fa[maxn],res,u[maxm],v[maxm],w[maxm],col[maxm],l=-105,r=105,mid,ans;

inline bool operator < (edge a,edge b){return a.w<b.w;}
inline int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
inline bool Kruskal(int val)
{
	int cnt=0;
	for(int i=1;i<=m;i++)e[i]=(edge){u[i],v[i],col[i]?w[i]:w[i]+val,col[i]};
	for(int i=1;i<=n;i++)fa[i]=i;
	sort(e+1,e+m+1),res=0;
	for(int i=1,f1,f2;i<=m;i++)
	{
		f1=find(e[i].u),f2=find(e[i].v);
		if(f1!=f2)
		{
			fa[f1]=f2,res+=e[i].w;
			if(!e[i].c)cnt++;
		}
	}
	res-=cnt*val;
	return cnt>=need;
}

int main()
{
	read(n),read(m),read(need);
	for(int i=1;i<=m;i++)
		read(u[i]),read(v[i]),read(w[i]),read(col[i]),u[i]++,v[i]++;
	while(l<=r)
	{
		mid=l+r>>1;
		if(Kruskal(mid))ans=res,l=mid+1;
		else r=mid-1;
	}
	write(ans);
	return 0;
}
