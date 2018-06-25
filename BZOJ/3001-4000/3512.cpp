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
	}
}
using FastIO::read;
using FastIO::write;
typedef long long LL;
const int maxn=4e6+5,mod=1e9+7;

int n,m,pr[283150],cnt,d[maxn],phi[maxn];
LL ans,sum[maxn],PHI[1005];
map<int,int> _p[100005];

inline LL solve(int n,int m)
{
	if(m<=1)return phi[n*m];
	if(n==1)
	{
		if(m<=4e6)return sum[m];
		if(PHI[::m/m])return PHI[::m/m];
		LL ans=(LL)m*(m+1)/2;
		for(int i=2,j;i<=m;i=j+1)
		{
			j=m/(m/i);
			ans-=solve(1,m/i)*(j-i+1);
		}
		return PHI[::m/m]=ans%mod;
	}
	if(_p[n][m])return _p[n][m];
	LL ans=0;
	for(int i=1,j,k;i*i<=n;i++)if(n%i==0)
	{
		j=n/i,k=m/i,ans=(ans+solve(i,k)*phi[j])%mod;
		if(i*i!=n)ans=(ans+solve(j,m/j)*phi[i])%mod;
	}
	return _p[n][m]=ans%mod;
}

int main()
{
	read(n),read(m);
	if(n>m)swap(n,m);
	d[1]=phi[1]=1;
	for(int i=2,tmp;i<=4e6;i++)
	{
		if(!d[i])pr[++cnt]=d[i]=i,phi[i]=i-1;
		for(int j=1;j<=cnt&&(tmp=i*pr[j])<=4e6;j++)
		{
			if(i%pr[j]==0)
			{
				d[tmp]=d[i],phi[tmp]=phi[i]*pr[j];
				break;
			}
			phi[tmp]=phi[i]*(pr[j]-1),d[tmp]=d[i]*pr[j];
		}
	}
	for(int i=1;i<=4e6;i++)sum[i]=(phi[i]+sum[i-1])%mod;
	for(int i=1;i<=n;i++)ans=(ans+solve(d[i],m)*i/d[i])%mod;
	write(ans);
	return 0;
}
