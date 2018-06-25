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
		putchar('\n');
	}
}
using FastIO::read;
using FastIO::write;
typedef long long LL;
const int maxn=100005;

int n,fa[maxn],a[maxn],m;
LL tr[maxn];

inline int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
inline void add(int u,int v){for(;u<=n;u+=u&-u)tr[u]+=v;}
inline LL ask(int u){LL ans=0;for(;u;u-=u&-u)ans+=tr[u];return ans;}

int main()
{
	read(n);
	for(int i=1;i<=n;i++)read(a[i]),add(i,a[i]),fa[i]=i;
	fa[n+1]=n+1,read(m);
	for(int i=1,op,l,r,tmp;i<=m;i++)
	{
		read(op),read(l),read(r);
		if(op==1)write(ask(r)-ask(l-1));
		else for(int j=l;j<=r;j=(find(j)==j?j+1:fa[j]))
		{
			tmp=floor(sqrt(a[j])-a[j]),a[j]+=tmp,add(j,tmp);
			if(a[j]<=1)fa[j]=j+1;
		}
	}
	return 0;
}
