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
typedef vector<int>::iterator ViI;
const int mod[]={0,2,3,4679,35617,999911658},
		  Ex[]={0,499955829,333303886,289138806,877424796};

int N,G;
LL res,ans,fac[40000],ifac[40000];
vector<int> d;

inline void divide(int u)
{
	for(int i=1;i*i<=u;i++)if(u%i==0)
	{
		d.push_back(i);
		if(i*i!=u)d.push_back(u/i);
	}
	sort(d.begin(),d.end());
}
inline LL Pow(LL a,int b,int mod)
{
	if(a%mod==0)return 0;
	LL ans=1;
	for(;b;b>>=1,a=a*a%mod)if(b&1)ans=ans*a%mod;
	return ans;
}
inline int C(int n,int m,int mod)
{
	int _n,_m;
	LL res=1;
	while(n)
	{
		_n=n%mod,_m=m%mod;
		if(_n<_m)return 0;
		res=res*fac[_n]%mod*ifac[_m]%mod*ifac[_n-_m]%mod;
		n/=mod,m/=mod;
	}
	return res;
}

int main()
{
	read(N),read(G),divide(N),fac[0]=1;
	for(int i=1;i<5;i++)
	{
		res=0;
		for(int j=1;j<mod[i];j++)fac[j]=fac[j-1]*j%mod[i];
		ifac[mod[i]-1]=Pow(fac[mod[i]-1],mod[i]-2,mod[i]);
		for(int j=mod[i]-1;j;j--)ifac[j-1]=ifac[j]*j%mod[i];
		for(ViI it=d.begin();it!=d.end();++it)res+=C(N,*it,mod[i]);
		ans+=(res%mod[i])*Ex[i];
	}
	write(Pow(G,ans%mod[5],mod[5]+1));
	return 0;
}
