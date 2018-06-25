#include<bits/stdc++.h>
using namespace std;
const int maxn=262150;
const double _2pi=2*acos(-1.0);

struct cpl
{
    double x,y;
    inline cpl operator + (cpl b){return (cpl){x+b.x,y+b.y};}
    inline cpl operator - (cpl b){return (cpl){x-b.x,y-b.y};}
    inline cpl operator * (cpl b){return (cpl){x*b.x-y*b.y,x*b.y+y*b.x};}
    inline void operator *= (cpl b){(*this)=(*this)*b;}
}w[2][maxn],A[maxn],B[maxn],tmp;
int n,rev[maxn],X=1,K;
double ans[100005],th;

void FFT(cpl *A,int r)
{
    for(int i=0;i<X;i++)if(i<rev[i])swap(A[i],A[rev[i]]);
    for(int i=1,l=X>>1;i<X;i<<=1,l>>=1)
        for(int j=0;j<X;j+=2*i)for(int k=0,l0=0;k<i;k++,l0+=l)
            tmp=A[i+j+k]*w[r][l0],A[i+j+k]=A[j+k]-tmp,A[j+k]=A[j+k]+tmp;
    if(r)for(int i=0;i<X;i++)A[i].x/=X;
}

int main()
{
    scanf("%d",&n);
    for(;X<n+n-1;X<<=1,K++);
    for(int i=0;i<X;i++)rev[i]=(rev[i>>1]>>1)|((i&1)<<K-1);
    for(int i=0;i<X;i++)
    {
        th=_2pi*i/X;
        w[0][i]=(cpl){cos(th),sin(th)},w[1][i]=(cpl){cos(-th),sin(-th)};
    }
    for(int i=0;i<n;i++)scanf("%lf",&B[i].x);FFT(B,0);
    for(int i=1;i<=n;i++)A[n-i].x=1.0/i/i;FFT(A,0);
    for(int i=0;i<X;i++)A[i]*=B[i];FFT(A,1);
    for(int i=0;i<n-1;i++)ans[i]=-A[n+i].x;
    memset(A,0,sizeof(A));
    for(int i=1;i<=n;i++)A[i-1].x+=1.0/i/i;FFT(A,0);
    for(int i=0;i<X;i++)A[i]*=B[i];FFT(A,1);
    for(int i=1;i<n;i++)ans[i]+=A[i-1].x;
    for(int i=0;i<n;i++)printf("%.5lf\n",ans[i]);
    return 0;
}
