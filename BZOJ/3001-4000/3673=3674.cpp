#include<bits/stdc++.h>
#include<ext/rope>
using namespace std;
using namespace __gnu_cxx;
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
		if(x<0)putchar('-'),x=-x;
		top=0;
		do buf[++top]=x%10,x/=10;while(x);
		while(top)putchar(48+buf[top--]);
		putchar('\n');
	}
}
using FastIO::read;
using FastIO::write;
const int maxn=2e5+5;

int n,m,a[maxn],ans;
rope<int> *fa[maxn];

inline int Root(int id,int x)
{
	if(fa[id]->at(x)==x)return x;
	int rt=Root(id,fa[id]->at(x));
	if(rt!=fa[id]->at(x))fa[id]->replace(x,rt);
	return rt;
}
inline void Union(int id,int x,int y)
{
	int f1=Root(id,x),f2=Root(id,y);
	fa[id]->replace(f2,f1);
}

int main()
{
	read(n),read(m);
	for(int i=1;i<=n;i++)a[i]=i;
	fa[0]=new rope<int>(a,a+n+1);
	for(int i=1,op,a,b;i<=m;i++)
	{
		fa[i]=new rope<int>(*fa[i-1]);
		read(op),read(a),a^=ans;
		if(op==1)read(b),b^=ans,Union(i,a,b);
		else if(op==2)fa[i]=fa[a];
		else read(b),b^=ans,ans=(Root(i,b)==Root(i,a)),write(ans);
	}
	return 0;
}
