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
const int maxn=1e7+5,mod=1e8+9;

int T,n,m,pr[664600],cnt;
LL ans,f[maxn];
bool vis[maxn];

inline LL cal(int u){return (LL)u*(u+1)/2%mod;}
inline LL sum(int i,int j){return (LL)(i+j)*(j-i+1)/2%mod;}

int main()
{
	f[1]=1;
	for(int i=2,tmp;i<=1e7;i++)
	{
		if(!vis[i])pr[++cnt]=i,f[i]=(LL)i*(1-i)%mod;
		for(int j=1;j<=cnt&&(tmp=pr[j]*i)<=1e7;j++)
		{
			vis[tmp]=1;
			if(i%pr[j]==0){f[tmp]=f[i]*pr[j]%mod;break;}
			f[tmp]=f[i]*f[pr[j]]%mod;
		}
	}
	for(int i=1;i<=1e7;i++)f[i]=(f[i]+f[i-1]+mod)%mod;
	read(T);
	while(T--)
	{
		read(n),read(m),ans=0;
		if(n>m)swap(n,m);
		for(int i=1,j;i<=n;i=j+1)
		{
			j=min(n/(n/i),m/(m/i));
			ans=(ans+cal(n/i)*cal(m/i)%mod*(f[j]-f[i-1])%mod)%mod;
		}
		write((mod+ans)%mod);
	}
	return 0;
}
