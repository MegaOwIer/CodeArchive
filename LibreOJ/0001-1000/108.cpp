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
		putchar(' ');
	}
}
using FastIO::read;
using FastIO::write;
typedef long long LL;
const int maxn=262144;
const double _2Pi=2*acos(-1.0);

struct Complex
{
	double x,y;
	Complex(double x=0,double y=0):x(x),y(y){}
	inline Complex operator + (const Complex &a){return Complex(x+a.x,y+a.y);}
	inline Complex operator - (const Complex &a){return Complex(x-a.x,y-a.y);}
	inline Complex operator * (const Complex &a){return Complex(x*a.x-y*a.y,x*a.y+y*a.x);}
	inline void operator *= (const Complex &a){(*this)=(*this)*a;}
	inline Complex Rvs(){return Complex(x,-y);}
}w[2][maxn],A[maxn],B[maxn],tmp;
int N,M,X=1,K,rev[maxn];
double th;

inline void FFT(Complex* a,int r=0)
{
	for(int i=0;i<X;i++)if(rev[i]<i)swap(a[i],a[rev[i]]);
	for(int i=1,l=X/2;i<X;i<<=1,l>>=1)
		for(int j=0;j<X;j+=i*2)for(int k=0,l0=0;k<i;k++,l0+=l)
			tmp=a[i+j+k]*w[r][l0],a[i+j+k]=a[j+k]-tmp,a[j+k]=a[j+k]+tmp;
	if(r)for(int i=0;i<X;i++)a[i].x/=X;
}

int main()
{
	read(N),read(M);
	for(int i=0;i<=N;i++)read(A[i].x);
	for(int i=0;i<=M;i++)read(B[i].x);
	for(;X<=N+M;X<<=1,K++);
	for(int i=0;i<X;i++)rev[i]=(rev[i>>1]>>1)|((i&1)<<K-1);
	for(int i=0;i<X;i++)
	{
		th=_2Pi*i/X;
		w[0][i]=Complex(cos(th),sin(th)),w[1][i]=w[0][i].Rvs();
	}
	FFT(A),FFT(B);
	for(int i=0;i<X;i++)A[i]*=B[i];
	FFT(A,1);
	for(int i=0;i<=N+M;i++)write((LL)(A[i].x+1e-5));
	return 0;
}
