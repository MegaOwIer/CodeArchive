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
typedef long long LL;
const int maxn=100005;

int N,M,T;
LL r[maxn],c[maxn],ans;
bool R,C;

int main()
{
	read(N),read(M),read(T);
	for(int i=1,n,m;i<=T;i++)read(n),read(m),r[n]++,c[m]++;
	for(int i=1;i<=N;i++)r[0]+=r[i];
	for(int i=1;i<=M;i++)c[0]+=c[i];
	if(r[0]%N==0)
	{
		r[0]/=N,R=1;
		for(int i=N-1;~i;i--)r[i]-=r[0];
		for(int i=1;i<N;i++)r[i]+=r[i-1];
		sort(r,r+N);
		for(int i=0;i<N;i++)ans+=abs(r[i]-r[N>>1]);
	}
	if(c[0]%M==0)
	{
		c[0]/=M,C=1;
		for(int i=M-1;~i;i--)c[i]-=c[0];
		for(int i=1;i<M;i++)c[i]+=c[i-1];
		sort(c,c+M);
		for(int i=0;i<M;i++)ans+=abs(c[i]-c[M>>1]);
	}
	if(R&&C)printf("both %lld",ans);
	else if(R)printf("row %lld",ans);
	else if(C)printf("column %lld",ans);
	else puts("impossible");
	return 0;
}
