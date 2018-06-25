#include<bits/stdc++.h>
using namespace std;
namespace FastIO
{
	static char c,buf[22];
	static int top;
	template<typename T>
	inline void read(T& x)
	{
		x=0,c=getchar();
		while(!isdigit(c))c=getchar();
		while(isdigit(c))x=x*10+c-'0',c=getchar();
	}
	template<typename T>
	inline void write(T x,int fl=0)
	{
		top=0;
		do buf[top++]=x%10,x/=10;while(x);
		for(int i=top-1;~i;i--)putchar('0'+buf[i]);
		if(fl)putchar(fl&1?' ':'\n');
	}
}
using FastIO::read;
using FastIO::write;
typedef long long LL;
const int maxn=200005;

int n,A[maxn],B[maxn],C[maxn],tr[maxn],pos[maxn];
LL ans;

inline void add(int x){for(;x<=n;x+=x&-x)tr[x]++;}
inline LL ask(int x){LL ans=0;for(;x;x-=x&-x)ans+=tr[x];return ans;}
inline LL solve(int* a,int* b)
{
	LL res=0;
	for(int i=1;i<=n;i++)pos[a[i]]=i,tr[i]=0;
	for(int i=n;i;i--)res+=ask(pos[b[i]]),add(pos[b[i]]);
	return res;
}

int main()
{
	read(n);
	for(int i=1;i<=n;i++)read(A[i]);
	for(int i=1;i<=n;i++)read(B[i]);
	for(int i=1;i<=n;i++)read(C[i]);
	ans=(LL)n*(n-1);
	ans-=solve(A,B)+solve(B,C)+solve(C,A);
	write(ans>>1);
	return 0;
}
