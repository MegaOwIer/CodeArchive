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
		while(top)putchar(48+buf[top--]);
		putchar('\n');
	}
}
using FastIO::read;
using FastIO::write;
typedef long long LL;
const int maxn=262144,mod=998244353,g=3;

int N,rev[maxn],K,X=1,rev_X;
LL w[2][maxn],A[maxn],B[maxn],fac[maxn],_fac[maxn],tmp,ans;

inline int Pow(LL a,int b)
{
	if(!a)return 0;
	LL res=1;
	while(b)
	{
		if(b&1)res=res*a%mod;
		a=a*a%mod,b>>=1;
	}
	return res;
}
inline void DFT(LL* a,int r=0)
{
	for(int i=0;i<X;i++)if(i<rev[i])swap(a[i],a[rev[i]]);
	for(int i=1,l=X>>1;i<X;i<<=1,l>>=1)
		for(int j=0;j<X;j+=i*2)for(int k=0,l0=0;k<i;k++,l0+=l)
			tmp=a[i+j+k]*w[r][l0]%mod,a[i+j+k]=(mod+a[j+k]-tmp)%mod,a[j+k]=(a[j+k]+tmp)%mod;
	if(r)for(int i=0;i<X;i++)a[i]=a[i]*rev_X%mod;
}

int main()
{
	read(N);
	for(;X<=N+N;X<<=1,K++);
	for(int i=0;i<X;i++)rev[i]=(rev[i>>1]>>1)|((i&1)<<K-1);
	rev_X=Pow(X,mod-2);
	w[1][0]=w[0][0]=1,w[0][1]=Pow(g,(mod-1)/X);
	for(int i=2;i<X;i++)w[0][i]=w[0][i-1]*w[0][1]%mod;
	for(int i=1;i<X;i++)w[1][i]=w[0][X-i];
	fac[0]=1;
	for(int i=1;i<=N;i++)fac[i]=fac[i-1]*i%mod;
	_fac[N]=Pow(fac[N],mod-2);
	for(int i=N;i;i--)_fac[i-1]=_fac[i]*i%mod;
	for(int i=0;i<=N;i++)A[i]=(i&1)?mod-_fac[i]:_fac[i];
	B[0]=1,B[1]=N+1;
	for(int i=2;i<=N;i++)B[i]=(Pow(i,N+1)-1)*_fac[i]%mod*Pow(i-1,mod-2)%mod;
	DFT(A),DFT(B);
	for(int i=0;i<X;i++)A[i]=A[i]*B[i]%mod;
	DFT(A,1);
	for(int i=0;i<=N;i++)ans=(ans+Pow(2,i)*fac[i]%mod*A[i])%mod;
	write(ans);
	return 0;
}
