#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int mod=1004535809,MX=16400;
typedef LL Array[MX];

namespace FastIO
{
	char c;
	int tp,bf[22];
	template<typename T>inline void read(T& x)
	{
		x=0,c=getchar();
		while(!isdigit(c))c=getchar();
		while(isdigit(c))x=x*10+c-'0',c=getchar();
	}
	template<typename T>inline void write(T x)
	{
		tp=0;
		do bf[++tp]=x%10,x/=10;while(x);
		while(tp)putchar(48+bf[tp--]);
		putchar('\n');
	}
}
using FastIO::read;
using FastIO::write;

Array w[2],A,B;
int n,m,x,s,K,X=1,rev[MX],g,f[8005];
LL _x,_X;

inline LL Pow(LL a,int b,int mod=::mod)
{
	LL ans=1;
	for(;b;b>>=1,a=a*a%mod)if(b&1)ans=ans*a%mod;
	return ans;
}
inline void FFT(LL *A,int r)
{
	for(int i=0;i<X;i++)if(i<rev[i])swap(A[i],A[rev[i]]);
	for(int i=1,l=X>>1;i<X;i<<=1,l>>=1)
		for(int j=0;j<X;j+=2*i)for(int k=0,l0=0;k<i;k++,l0+=l)
			_x=A[i+j+k]*w[r][l0]%mod,A[i+j+k]=(A[j+k]-_x+mod)%mod,A[j+k]=(A[j+k]+_x)%mod;
	if(r)for(int i=0;i<X;i++)A[i]=A[i]*_X%mod;
}
inline void getG(int u)
{
	int cnt=0,pr[6],r=u-1,flg;
	for(int i=2;i*i<=r;i++)if(r%i==0)
	{
		pr[++cnt]=i;
		while(r%i==0)r/=i;
	}
	if(r>1)pr[++cnt]=r;
	for(g=2;;g++)
	{
		flg=0;
		for(int i=1;i<=cnt;i++)
			if(Pow(g,(u-1)/pr[i],u)==1)
			{
				flg=1;
				break;
			}
		if(!flg)return;
	}
}
inline void solve1()
{
	int flag=0;
	for(int i=1,u;i<=s;i++)
	{
		read(u);
		if(!u){flag=1;break;}
	}
	if(!flag)puts("0");
	else write((Pow(s,n)-Pow(s-1,n)+mod)%mod);
	exit(0);
}

int main()
{
	read(n),read(m),read(x),read(s);
	if(!x)solve1();
	for(;X<=m+m;X<<=1,K++);
	_X=Pow(X,mod-2);
	for(int i=0;i<X;i++)rev[i]=(rev[i>>1]>>1)|((i&1)<<K-1);
	w[0][0]=1,w[0][1]=Pow(3,(mod-1)/X);
	for(int i=2;i<X;i++)w[0][i]=w[0][i-1]*w[0][1]%mod;
	memcpy(w[1],w[0],sizeof(LL)*X),reverse(w[1]+1,w[1]+X);
	getG(m);
	for(int i=0,t=1;i<m-1;i++,t=t*g%m)f[t]=i;
	for(int i=1,u;i<=s;i++)
	{
		read(u);
		if(u)A[f[u]]++;
	}
	B[0]=1,m--;
	while(n)
	{
		FFT(A,0);
		if(n&1)
		{
			FFT(B,0);
			for(int i=0;i<X;i++)B[i]=B[i]*A[i]%mod;
			FFT(B,1);
			for(int i=X;i>=m;i--)B[i-m]=(B[i-m]+B[i])%mod,B[i]=0;
		}
		for(int i=0;i<X;i++)A[i]=A[i]*A[i]%mod;
		FFT(A,1);
		for(int i=X;i>=m;i--)A[i-m]=(A[i-m]+A[i])%mod,A[i]=0;
		n>>=1;
	}
	write(B[f[x]]);
	return 0;
}
