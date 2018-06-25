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
		while(top)putchar(buf[top--]+48);
		putchar('\n');
	}
}
using FastIO::read;
using FastIO::write;
typedef long long LL;
const int maxn=1e6+5,mod=1e9+7;

int T,miu[maxn],pr[78500],cnt,fib[maxn],n,m,ifib[maxn];
LL F[maxn],ans;
bool vis[maxn];

inline LL Pow(LL a,LL b)
{
	LL ans=1;
	for(;b;b>>=1,a=a*a%mod)if(b&1)ans=ans*a%mod;
	return ans;
}

int main()
{
	miu[1]=1,ifib[1]=fib[1]=1,F[0]=F[1]=1;
	for(int i=2;i<=1e6;i++)fib[i]=(fib[i-1]+fib[i-2])%mod,F[i]=1,ifib[i]=Pow(fib[i],mod-2);
	for(int i=2,tmp;i<=1e6;i++)
	{
		if(!vis[i])pr[++cnt]=i,miu[i]=-1;
		for(int j=1;j<=cnt&&(tmp=i*pr[j])<=1e6;j++)
		{
			vis[tmp]=1;
			if(i%pr[j]==0){miu[tmp]=0;break;}
			miu[tmp]=-miu[i];
		}
	}
	for(int i=1;i<=1e6;i++)for(int j=i,k=1;j<=1e6;j+=i,k++)
	{
		if(miu[k]==1)F[j]=F[j]*fib[i]%mod;
		else if(miu[k]==-1)F[j]=F[j]*ifib[i]%mod;
	}
	for(int i=1;i<=1e6;i++)F[i]=F[i]*F[i-1]%mod;
	read(T);
	while(T--)
	{
		read(n),read(m),ans=1;
		if(n>m)swap(n,m);
		for(int i=1,j;i<=n;i=j+1)
		{
			j=min(n/(n/i),m/(m/i));
			ans=ans*Pow(F[j]*Pow(F[i-1],mod-2)%mod,(LL)(n/i)*(m/i))%mod;
		}
		write(ans);
	}
	return 0;
}
