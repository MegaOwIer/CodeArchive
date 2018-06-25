#include<bits/stdc++.h>
using namespace std;
namespace FastIO
{
	static char c;
	static int top,buf[22];
	template<typename T>
	inline void read(T& x)
	{
		x=0,c=getchar();
		while(!isdigit(c))c=getchar();
		while(isdigit(c))x=x*10+c-'0',c=getchar();
	}
	template<typename T>
	inline void write(T x,int f=0)
	{
		top=0;
		do buf[top++]=x%10,x/=10;while(x);
		for(int i=top-1;~i;i--)putchar(buf[i]+48);
		if(f)putchar(f&1?' ':'\n');
	}
}
using FastIO::read;
using FastIO::write;
const int maxn=100005;
typedef long long LL;

int n,m,fa[maxn],siz[maxn],t[maxn];
LL e,p,q;
vector<int> g[maxn];
bool odd[maxn];

inline int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
inline bool dfs(int u,int d)
{
	t[u]=d;
	for(vector<int>::iterator it=g[u].begin();it!=g[u].end();++it)
		if(!t[*it]&&dfs(*it,d+1))return 1;
		else if((t[*it]+d+1)&1)return 1;
	return 0;
}

int main()
{
	read(n),read(m);
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1,u,v,f1,f2;i<=m;i++)
	{
		read(u),read(v);
		g[u].push_back(v),g[v].push_back(u);
		f1=find(u),f2=find(v);
		if(f1==f2)continue;
		fa[f1]=f2;
	}
	for(int i=1,f;i<=n;i++)
	{
		f=find(i),siz[f]++;
		if(f!=i)continue;
		if(dfs(i,1))odd[i]=1;
	}
	for(int i=1;i<=n;i++)
		if(siz[i]==1)e++;
		else if(siz[i]&&odd[i])p++;
		else if(siz[i]&&!odd[i])q++;
	write(2*e*n-e*e+(p+q)*(p+q)+q*q);
	return 0;
}
