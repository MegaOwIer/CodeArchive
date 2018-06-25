#include<bits/stdc++.h>
using namespace std;
namespace FastIO
{
	static char c;
	static int top,buf[20];
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
typedef long long LL;
const int MX=100005;

int N,M,a[MX];
LL tr[MX],TR[MX];
char op;

inline void add(LL* A,int u,LL v){for(;u<=N;u+=u&-u)A[u]+=v;}
inline LL ask(LL* A,int u){LL ans=0;for(;u;u-=u&-u)ans+=A[u];return ans;}

int main()
{
	read(N),read(M);
	for(int i=1;i<=N;i++)
		read(a[i]),add(tr,i,a[i]),add(TR,i,(LL)a[i]*(N-i+1));
	for(int i=1,u,x;i<=M;i++)
	{
		do op=getchar();while(!isalpha(op));
		read(u);
		if(op=='Q')write(ask(TR,u)-ask(tr,u)*(N-u));
		else read(x),add(tr,u,x-a[u]),add(TR,u,(LL)(N-u+1)*(x-a[u])),a[u]=x;
	}
	return 0;
}
