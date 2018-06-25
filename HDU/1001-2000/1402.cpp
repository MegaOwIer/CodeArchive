#include<bits/stdc++.h>
using namespace std;
const int MX=131073;
const double _2pi=acos(-1.0)*2;

int ls,lt,rev[MX],X,K,ans[MX];
char s[MX],t[MX];

struct Complex
{
    double x,y;
    Complex(double x=0.0,double y=0.0):x(x),y(y){}
    Complex operator + (const Complex& a){return Complex(x+a.x,y+a.y);}
    Complex operator - (const Complex& a){return Complex(x-a.x,y-a.y);}
    Complex operator * (const Complex& a){return Complex(x*a.x-y*a.y,x*a.y+y*a.x);}
}w[2][MX],A[MX],B[MX];

inline void DFT(Complex *A,int r)
{
    static Complex tmp;
    for(int i=0;i<X;i++)if(i<rev[i])swap(A[i],A[rev[i]]);
    for(int i=1,l=X>>1;i<X;i<<=1,l>>=1)
        for(int j=0;j<X;j+=2*i)for(int k=0,l0=0;k<i;k++,l0+=l)
            tmp=A[i+j+k]*w[r][l0],A[i+j+k]=A[j+k]-tmp,A[j+k]=A[j+k]+tmp;
    if(r)for(int i=0;i<X;i++)A[i].x/=X;
}

int main()
{
    while(~scanf("%s%s",s,t))
    {
        ls=strlen(s),lt=strlen(t);
        if(ls==1&&s[0]=='0'){puts("0");continue;}
        if(lt==1&&t[0]=='0'){puts("0");continue;}
        for(K=0,X=1;X<ls+lt-1;X<<=1,K++);
        memset(A,0,sizeof(Complex)*X);
        memset(B,0,sizeof(Complex)*X);
        for(int i=0,j=ls-1;i<ls;i++,j--)A[i]=s[j]-48;
        for(int i=0,j=lt-1;i<lt;i++,j--)B[i]=t[j]-48;
        for(int i=0;i<X;i++)rev[i]=(rev[i>>1]>>1)|((i&1)<<K-1);
        for(int i=0;i<X;i++)
        {
            double tmp=_2pi/X*i;
            w[0][i]=Complex(cosl(tmp),sinl(tmp));
            w[1][i]=Complex(cosl(tmp),-sinl(tmp));
        }
        DFT(A,0),DFT(B,0);
        for(int i=0;i<X;i++)A[i]=A[i]*B[i];
        DFT(A,1);
        memset(ans,0,sizeof(int)*(ls+lt));
        for(int i=0;i<ls+lt-1;i++)ans[i]=int(A[i].x+1e-6);
        for(int i=0;i<ls+lt-1;i++)ans[i+1]+=ans[i]/10,ans[i]%=10;
        if(ans[ls+lt-1])printf("%d",ans[ls+lt-1]);
        for(int i=ls+lt-2;i>=0;i--)printf("%d",ans[i]);
        puts("");
    }
    return 0;
}