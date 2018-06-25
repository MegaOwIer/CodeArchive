#include<bits/stdc++.h>
using namespace std;
const int MX=131075;
const double PI=acos(-1.0);

namespace FastIO
{
    const int MXL=500000;
    class FastIn
    {
    private:
        char BF[MXL],*p1,*p2;
        char getchar(){return p1==p2?(p2=(p1=BF)+fread(BF,1,MXL,stdin)),p1==p2?EOF:*p1++:*p1++;}
    public:
        FastIn():p1(BF),p2(BF){}
        template<typename T>void operator()(T& x){x=getchar()-'0',getchar();}
    };
    class FastOut
    {
    private:
        char BF[MXL],*p1,*const p2;
        int bf[22],tp;
        void putchar(char c){if(p1==p2)flush();*p1++=c;}
        void flush(){fwrite(BF,1,p1-BF,stdout),p1=BF;}
    public:
        FastOut():p1(BF),p2(BF+MXL){}
        ~FastOut(){flush();}
        template<typename T>void operator()(T x)
        {
            bf[tp=1]=' '-48;
            do bf[++tp]=x%10,x/=10;while(x);
            while(tp)putchar(48+bf[tp--]);
        }
    };
}
FastIO::FastIn read;
FastIO::FastOut write;

struct Complex
{
    double x,y;
    Complex(double x=0,double y=0):x(x),y(y){}
    Complex operator+(const Complex& a){return Complex(x+a.x,y+a.y);}
    Complex operator-(const Complex& a){return Complex(x-a.x,y-a.y);}
    Complex operator*(const Complex& a){return Complex(x*a.x-y*a.y,x*a.y+y*a.x);}
    Complex operator~(){return Complex(x,-y);}
    Complex operator-(){return Complex(-x,-y);}
}w[MX],tmp,A[MX],B[MX],C[MX],tmp1;
int N,M,X,K,rev[MX],X0;

inline void FFT()
{
    register int i,j,k;
    for(i=0;i<X;i++)if(i<rev[i])
        swap(A[i],A[rev[i]]),swap(B[i],B[rev[i]]);
    w[0]=1;
    for(i=1;i<X;i<<=1)
    {
        w[1]=Complex(cos(PI/i),sin(PI/i));
        for(j=2;j<i;j++)w[j]=w[j-1]*w[1];
        for(j=0;j<X;j+=i<<1)for(k=0;k<i;k++)
            tmp=A[i+j+k]*w[k],A[i+j+k]=A[j+k]-tmp,A[j+k]=A[j+k]+tmp,
            tmp1=B[i+j+k]*w[k],B[i+j+k]=B[j+k]-tmp1,B[j+k]=B[j+k]+tmp1;
    }
}
inline void IFFT()
{
    register int i,j,k;
    for(i=0;i<X;i++)if(i<rev[i])swap(C[i],C[rev[i]]);
    w[0]=1;
    for(i=1;i<X;i<<=1)
    {
        w[1]=Complex(cos(PI/i),sin(-PI/i));
        for(j=2;j<i;j++)w[j]=w[j-1]*w[1];
        for(j=0;j<X;j+=i<<1)for(k=0;k<i;k++)
            tmp=C[i+j+k]*w[k],C[i+j+k]=C[j+k]-tmp,C[j+k]=C[j+k]+tmp;
    }
    for(i=0;i<X;i++)C[i].x/=X,C[i].y/=X;
}

int main()
{
    register int i,j;
    scanf("%d%d",&N,&M),getchar();
    for(i=0;i<=N;i++)read(i&1?A[i>>1].y:A[i>>1].x);
    for(i=0;i<=M;i++)read(i&1?B[i>>1].y:B[i>>1].x);
    for(X=1;X<=N||X<=M;X<<=1,K++);X0=X>>1;
    for(i=0;i<X;i++)rev[i]=(rev[i>>1]>>1)|((i&1)<<K-1);
    FFT();
    C[0]=A[0]*B[0]+2*A[0].y*B[0].y;
    for(i=1,j=X-1;i<X;i++,j--)
        C[i]=A[i]*B[i]-(A[i]-~A[j])*(B[i]-~B[j])*(((i&X0)?-w[i^X0]:w[i])+1)*0.25;
    IFFT();
    for(i=0;i<=N+M;i++)write((int)((i&1?C[i>>1].y:C[i>>1].x)+0.5));
    return 0;
}