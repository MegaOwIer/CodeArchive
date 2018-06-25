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
const int maxn=200005,maxm=maxn*20;

int n,a[maxn],m,root[maxn],tot,l[maxm],r[maxm],val[maxm],cnt,id[maxn];

inline void insert(int last,int& now,int L,int R,int pos,int _)
{
	now=++tot;
	if(L==R){val[now]=_;return;}
	int mid=L+R>>1;
	if(mid>=pos)insert(l[last],l[now],L,mid,pos,_),r[now]=r[last];
	else insert(r[last],r[now],mid+1,R,pos,_),l[now]=l[last];
	val[now]=min(val[l[now]],val[r[now]]);
}
inline int ask(int id,int L,int R,int _)
{
	if(L==R)return L;
	int mid=L+R>>1;
	if(val[l[id]]>=_)return ask(r[id],mid+1,R,_);
	else return ask(l[id],L,mid,_);
}

int main()
{
	read(n),read(m);
	for(int i=1;i<=n;i++)
	{
		read(a[i]);
		if(a[i]>n)a[i]=n;
		insert(root[i-1],root[i],0,n,a[i],i);
	}
	for(int i=1,L,R;i<=m;i++)read(L),read(R),write(ask(root[R],0,n,L));
	return 0;
}
