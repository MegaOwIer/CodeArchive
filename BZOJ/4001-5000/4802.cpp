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
const int pr[]={0,2,3,5,7,11,13,17,19,23,29,31,37,41};

LL n,seed=2547345;
vector<LL> d;

inline LL rd(){return seed=((seed<<12)^(seed>>4)|(seed<<6))&LLONG_MAX;}

inline LL mul(LL a,LL b,LL mod)
{
	LL ans=0;
	a%=mod,b%=mod;
	while(b)
	{
		if(b&1)ans=(ans+a)%mod;
		a=(a<<1)%mod,b>>=1;
	}
	return ans;
}
inline LL Pow(LL a,LL b,LL mod)
{
	LL ans=1;
	a%=mod;
	for(;b;b>>=1,a=mul(a,a,mod))if(b&1)ans=mul(a,ans,mod);
	return ans;
}
inline bool Judge(int pr,LL res,int tms,LL n)
{
	LL p=Pow(pr,res,n);
	if(p==1)return 0;
	for(int i=0;i<tms;i++)
	{
		if(p==n-1||p==1)return 0;
		p=mul(p,p,n);
	}
	return 1;
}
bool Millar_Rabin(LL n)
{
	for(int i=1;i<=13;i++)if(n%pr[i]==0)return n==pr[i];
	LL p=n-1;
	int tms=0;
	while(!(p&1))tms++,p>>=1;
	for(int i=1;i<=13;i++)if(Judge(pr[i],p,tms,n))return 0;
	return 1;
}
inline LL gcd(LL a,LL b){return b?gcd(b,a%b):a;}
inline void PollardRho(LL n)
{
	if(Millar_Rabin(n))return d.push_back(n);
	LL a,b,c,del;
	while(1)
	{
		c=rd()%n,a=b=rd()%n,b=(mul(b,b,n)+c)%n;
		while(a!=b)
		{
			del=gcd(abs(a-b),n);
			if(del>1&&del<n)return PollardRho(del),PollardRho(n/del);
			a=(mul(a,a,n)+c)%n,b=(mul(b,b,n)+c)%n,b=(mul(b,b,n)+c)%n;
		}
	}
}

int main()
{
	read(n);
	if(n==1)return puts("1"),0;
	PollardRho(n);
	sort(d.begin(),d.end()),d.erase(unique(d.begin(),d.end()),d.end());
	for(vector<LL>::iterator it=d.begin();it!=d.end();++it)n=n/(*it)*(*it-1);
	write(n);
	return 0;
}
