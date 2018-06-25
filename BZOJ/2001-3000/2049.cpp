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
	inline void getalpha(char& x){do x=getchar();while(!isalpha(x));}
}
using FastIO::read;
using FastIO::getalpha;
const int maxn=10005;

int n,m,fa[maxn],son[maxn][2],sta[maxn],top;
bool rev[maxn];
char c;

inline bool isroot(int x){return son[fa[x]][0]!=x&&son[fa[x]][1]!=x;}
inline void pushdown(int k)
{
	if(rev[k])
		rev[k]^=1,rev[son[k][0]]^=1,rev[son[k][1]]^=1,swap(son[k][0],son[k][1]);
}
inline void rotate(int x)
{
	int y=fa[x],z=fa[y],l,r;
	l=(r=(son[y][0]==x))^1;
	if(!isroot(y))son[z][son[z][0]!=y]=x;
	fa[x]=z,fa[y]=x,fa[son[x][r]]=y;
	son[y][l]=son[x][r],son[x][r]=y;
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
inline void access(int u){for(int t=0;u;t=u,u=fa[u])splay(u),son[u][1]=t;}
inline void makeroot(int u){access(u),splay(u),rev[u]^=1;} 
inline void link(int u,int v){makeroot(v),fa[v]=u,splay(v);}
inline void cut(int u,int v){makeroot(u),access(v),splay(v),fa[u]=son[v][0]=0;}
inline bool linked(int u,int v)
{
	makeroot(u),access(v),splay(v);
	while(son[v][0])v=son[v][0];
	return u==v;
}

int main()
{
	read(n),read(m);
	for(int i=1,u,v;i<=m;i++)
	{
		getalpha(c),read(u),read(v);
		if(c=='C')link(u,v);
		else if(c=='D')cut(u,v);
		else puts(linked(u,v)?"Yes":"No");
	}
	return 0;
}
