#include<bits/stdc++.h>
using namespace std;
namespace FastIO
{
	static char c;
	template<typename T>
	inline void read(T& x)
	{
		x=0,c=getchar();
		while(!isdigit(c))c=getchar();
		while(isdigit(c))x=x*10+c-'0',c=getchar();
	}
}
using FastIO::read;
const int maxn=50005,maxm=maxn*3;

struct edge{int u,v,a,b;}e[maxn<<1];
int n,m,par[maxn],ans=-1,val[maxm],mx[maxm],son[maxm][2],sta[maxm],top,fa[maxm];
bool rev[maxm];

inline bool operator < (edge a,edge b){return a.a<b.a;}
inline int find(int u){return u==par[u]?u:par[u]=find(par[u]);}
inline void Min(int& x,int y){if(x<0||y<x)x=y;}
inline bool isroot(int x){return son[fa[x]][0]!=x&&son[fa[x]][1]!=x;}
inline void maintain(int x)
{
	int l=son[x][0],r=son[x][1];
	mx[x]=x;
	if(val[mx[l]]>val[mx[x]])mx[x]=mx[l];
	if(val[mx[r]]>val[mx[x]])mx[x]=mx[r]; 
}
inline void pushdown(int x)
{
	int l=son[x][0],r=son[x][1];
	if(rev[x])rev[x]^=1,rev[l]^=1,rev[r]^=1,swap(son[x][0],son[x][1]);
}
inline void rotate(int x)
{
	int y=fa[x],z=fa[y],l,r;
	l=!(r=(son[y][0]==x));
	if(!isroot(y))
	{
		if(son[z][0]==y)son[z][0]=x;
		else son[z][1]=x;
	}
	fa[x]=z,fa[y]=x,fa[son[x][r]]=y;
	son[y][l]=son[x][r],son[x][r]=y;
	maintain(y),maintain(x);
}
inline void splay(int x)
{
	sta[top=1]=x;
	for(int i=x;!isroot(i);i=fa[i])sta[++top]=fa[i];
	while(top)pushdown(sta[top--]);
	while(!isroot(x))
	{
		 int y=fa[x],z=fa[y];
		 if(!isroot(y))
		 {
		 	if((son[y][0]==x)^(son[z][0]==y))rotate(x);
		 	else rotate(y);
		 }
		 rotate(x);
	}
}
inline void access(int u){for(int t=0;u;t=u,u=fa[u])splay(u),son[u][1]=t,maintain(u);}
inline void makeroot(int u){access(u),splay(u),rev[u]^=1;}
inline void link(int u,int v){makeroot(u),fa[u]=v;}
inline void cut(int u,int v){makeroot(u),access(v),splay(v),fa[u]=son[v][0]=0,maintain(v);}
inline int query(int u,int v){makeroot(u),access(v),splay(v);return mx[v];}

int main()
{
	read(n),read(m);
	for(int i=1;i<=m;i++)read(e[i].u),read(e[i].v),read(e[i].a),read(e[i].b);
	for(int i=1;i<=n;i++)par[i]=i; 
	sort(e+1,e+m+1);
	for(int i=1,f1,f2,t;i<=m;i++)if(e[i].u!=e[i].v)
	{
		f1=find(e[i].u),f2=find(e[i].v);
		if(f1==f2)
		{
			t=query(e[i].u,e[i].v);
			if(val[t]>e[i].b)cut(t,e[t-n].u),cut(e[t-n].v,t);
			else
			{
				if(find(1)==find(n))Min(ans,e[i].a+val[query(1,n)]);
				continue;
			}
		}
		else par[f1]=f2;
		val[i+n]=e[i].b,mx[n+i]=n+i,link(i+n,e[i].u),link(i+n,e[i].v);
		if(find(1)==find(n))Min(ans,e[i].a+val[query(1,n)]);
	}
	printf("%d",ans);
	return 0;
}
