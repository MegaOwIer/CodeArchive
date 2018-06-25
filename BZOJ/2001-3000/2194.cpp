#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef long double LD;
const int maxn=262150;
const LD _2pi=2*acos(-1.0);

struct cpl
{
    LD x,y;
    inline cpl operator + (cpl b){return (cpl){x+b.x,y+b.y};};
    inline cpl operator - (cpl b){return (cpl){x-b.x,y-b.y};};
    inline cpl operator * (cpl b){return (cpl){x*b.x-y*b.y,x*b.y+y*b.x};};
    inline void operator *= (cpl b){(*this)=(*this)*b;};
}A[maxn],B[maxn],w[2][maxn],tmp;
int n,K,X,rev[maxn];
LD th;

template<typename T>
inline void read(T& x)
{
    x=0;char c=getchar();
    while(c>'9'||c<'0')c=getchar();
    while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
}
void FFT(cpl* A,int r)
{
    for(int i=0;i<X;i++)if(i<rev[i])swap(A[i],A[rev[i]]);
    for(int i=1,l=X>>1;i<X;i<<=1,l>>=1)
        for(int j=0;j<X;j+=2*i)for(int k=0,l0=0;k<i;k++,l0+=l)
            tmp=A[i+j+k]*w[r][l0],A[j+k+i]=A[j+k]-tmp,A[j+k]=A[j+k]+tmp;
    if(r)for(int i=0;i<X;i++)A[i].x/=X;
}

int main()
{
    read(n);
    for(int i=0;i<n;i++)read(A[i].x),read(B[n-i-1].x);
    for(X=1;X<2*n-1;X<<=1,K++);
    for(int i=0;i<X;i++)rev[i]=(rev[i>>1]>>1)|((i&1)<<K-1);
    for(int i=0;i<X;i++)
    {
        th=_2pi*i/X;
        w[0][i]=(cpl){cos(th),sin(th)},w[1][i]=(cpl){cos(-th),sin(-th)};
    }
    FFT(A,0),FFT(B,0);
    for(int i=0;i<X;i++)A[i]*=B[i];
    FFT(A,1);
    for(int i=n-1;i<2*n-1;i++)printf("%lld\n",(LL)(A[i].x+1e-5));
    return 0;
}