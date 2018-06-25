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
const int MX=500005,mod=1e9+7;

int N,M,pr[MX],cnt,inv[MX];
LL ans,pw[MX],fac[MX],ifac[MX],A[MX],B[MX],R,K,tmp,P[MX],l[MX],r[MX],p;

inline LL Pow(LL a,int b)
{
	LL ans=1;
	for(;b;b>>=1,a=a*a%mod)if(b&1)ans=ans*a%mod;
	return ans;
}
inline LL C(int m,int n){return fac[m]*ifac[n]%mod*ifac[m-n]%mod;}

int main()
{
	read(N),read(M),pw[1]=1;
	if(M==1)return write(((LL)N*(N+1)>>1)%mod),0;
	for(int i=2;i<=M+1;i++)
	{
		if(!pw[i])pr[++cnt]=i,pw[i]=Pow(i,M);
		for(int j=1;j<=cnt&&i*pr[j]<=M+1;j++)
		{
			pw[i*pr[j]]=pw[i]*pw[pr[j]]%mod;
			if(i%pr[j]==0)break;
		}
	}
	if(N<=M)
	{
		for(int i=1,res=M;i<=N;i++,res=(LL)res*M%mod)
			ans=(ans+pw[i]*res)%mod;
		return write(ans),0;
	}
	inv[1]=fac[0]=ifac[0]=1;
	for(int i=2;i<=M+1;i++)inv[i]=mod-(LL)inv[mod%i]*(mod/i)%mod;
	for(int i=1;i<=M+1;i++)
		fac[i]=fac[i-1]*i%mod,ifac[i]=ifac[i-1]*inv[i]%mod;
	A[0]=1,B[0]=0; 
	for(int i=1;i<=M+1;i++)
		A[i]=A[i-1]*inv[M]%mod,B[i]=(B[i-1]*inv[M]+pw[i])%mod;
	for(int i=0;i<=M+1;i++)
	{
		tmp=(i&1)?-C(M+1,i):C(M+1,i);
		R=(R+tmp*A[i])%mod,K=(K+tmp*B[i])%mod;
	}
	P[0]=-K*Pow(R,mod-2)%mod;
	for(int i=1;i<=M;i++)P[i]=(A[i]*P[0]+B[i])%mod;
	l[0]=N-M,r[0]=N;
	for(int i=1;i<=M;i++)
		l[i]=l[i-1]*(N-M+i)%mod,r[i]=r[i-1]*(N-i)%mod;
	for(int i=0;i<=M;i++)
	{
		tmp=ifac[i]*ifac[M-i]%mod;
		if(i!=M)tmp=tmp*l[M-i-1]%mod;
		if(i)tmp=tmp*r[i-1]%mod;
		if((M^i)&1)tmp=-tmp;
		p=(p+tmp*P[i])%mod;
	}
	ans=(Pow(M,N)*p-P[0])%mod;
	write((ans+mod)%mod);
	return 0;
}
