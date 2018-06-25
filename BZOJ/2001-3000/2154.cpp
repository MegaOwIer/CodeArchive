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
const int maxn=1e7+5,mod=20101009;

int n,m,pr[maxn],cnt;
LL ans,f[maxn],sum[maxn];
bool vis[maxn];

int main()
{
	read(n),read(m),f[1]=1;
	if(n>m)swap(n,m);
	for(int i=2,tmp;i<=n;i++)
	{
		if(!vis[i])pr[++cnt]=i,f[i]=1-i;
		for(int j=1;j<=cnt&&(tmp=pr[j]*i)<=n;j++)
		{
			vis[tmp]=1;
			if(i%pr[j]==0){f[tmp]=f[i];break;}
			f[tmp]=f[i]*(1-pr[j]);
		}
	}
	for(int i=1;i<=1e7;i++)sum[i]=(sum[i-1]+i)%mod;
	for(int i=1;i<=n;i++)
		ans=(ans+sum[n/i]*sum[m/i]%mod*i%mod*f[i])%mod;
	write((mod+ans)%mod);
	return 0;
}
