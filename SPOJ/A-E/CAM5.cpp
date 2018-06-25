#include<bits/stdc++.h>
using namespace std;
namespace FastIO
{
	static char c;
	static int top,buf[22];
	template<typename T>inline void read(T& x)
	{
		x=0,c=getchar();
		while(!isdigit(c))c=getchar();
		while(isdigit(c))x=x*10+c-'0',c=getchar();
	}
	template<typename T>inline void write(T x)
	{
		top=0;
		do buf[++top]=x%10,x/=10;while(x);
		while(top)putchar(48+buf[top--]);
		putchar('\n');
	}
}
using FastIO::read;
using FastIO::write;
const int maxn=100005;

int T,n,m,u,v,ans,fa[maxn];

inline int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}

int main()
{
	read(T);
	while(T--)
	{
		read(n),read(m),ans=0;
		for(int i=0;i<n;i++)fa[i]=i;
		while(m--)
		{
			read(u),read(v);
			u=find(u),v=find(v);
			if(u!=v)fa[u]=v;
		}
		for(int i=0;i<n;i++)if(find(i)==i)ans++;
		write(ans);
	}
	return 0;
}
