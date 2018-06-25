#include<bits/stdc++.h>
using namespace std;
const int MX=50005;

int tr[MX],n;

inline void read(int& x)
{
	static char c;
	static bool f=0;
	x=0,c=getchar();
	while(!isdigit(c)){if(c=='-')f=1;c=getchar();}
	while(isdigit(c))x=x*10+c-'0',c=getchar();
	if(f)x=-x,f=0;
}
inline void write(int x)
{
	static int bf[12],tp;
	tp=0;
	if(x<0)putchar('-'),x=-x;
	do bf[++tp]=x%10,x/=10;while(x);
	while(tp)putchar(48+bf[tp--]);
	putchar('\n');
}
inline void add(int u,int v){for(;u<=n;u+=u&-u)tr[u]+=v;}
inline int ask(int u){int ans=0;for(;u;u-=u&-u)ans+=tr[u];return ans;}

int main()
{
	read(n);
	for(int i=1,ls=0,x;i<=n;i++)read(x),add(i,x-ls),ls=x;
	for(int i=1,op,l,r,c;i<=n;i++)
	{
		read(op),read(l),read(r),read(c);
		if(op)write(ask(r));
		else add(l,c),add(r+1,-c);
	}
	return 0;
}
