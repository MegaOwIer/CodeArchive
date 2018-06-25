#include<bits/stdc++.h>
using namespace std;
namespace FastIO
{
	static char c;
	static int top,buf[22];
	template<typename T>inline void IN(T& x)
	{
		x=0,c=getchar();
		while(!isdigit(c))c=getchar();
		while(isdigit(c))x=x*10+c-48,c=getchar();
	}
	template<typename T>inline void OUT(T x)
	{
		top=0;
		do buf[++top]=x%10,x/=10;while(x);
		while(top)putchar(48+buf[top--]);
		putchar('\n');
	}
}
using FastIO::IN;
using FastIO::OUT;
typedef long long LL;
const int maxn=5e6+5,mod=1e9+7;

int n,m,cnt,pr[348520],T,K;
LL f[maxn],ans;
bool vis[maxn];

inline LL Pow(LL a,int b)
{
	LL ans=1;
	for(;b;b>>=1,a=a*a%mod)if(b&1)ans=ans*a%mod;
	return ans;
}

int main()
{
	f[1]=1,IN(T),IN(K);
	for(int i=2,tmp;i<=5e6;i++)
	{
		if(!vis[i])pr[++cnt]=i,f[i]=Pow(i,K)-1;
		for(int j=1;j<=cnt&&(tmp=i*pr[j])<=5e6;j++)
		{
			vis[tmp]=1;
			if(i%pr[j]==0){f[tmp]=f[i]*(f[pr[j]]+1)%mod;break;}
			f[tmp]=f[i]*f[pr[j]]%mod;
		}
	}
	for(int i=2;i<=5e6;i++)f[i]=(f[i]+f[i-1])%mod;
	while(T--)
	{
		IN(n),IN(m),ans=0;
		if(n>m)swap(n,m);
		for(int i=1,j;i<=n;i=j+1)
		{
			j=min(n/(n/i),m/(m/i));
			ans=(ans+(f[j]-f[i-1]+mod)*(n/i)%mod*(m/i))%mod;
		}
		OUT(ans);
	}
	return 0;
}
