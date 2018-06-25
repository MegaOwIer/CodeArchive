#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn=131100;
const double _2pi=2*acos(-1.0);

struct cpl
{
    double x,y;
    inline cpl operator + (cpl b){return (cpl){x+b.x,y+b.y};}
    inline cpl operator - (cpl b){return (cpl){x-b.x,y-b.y};}
    inline cpl operator * (cpl b){return (cpl){x*b.x-y*b.y,x*b.y+y*b.x};}
    inline void operator *= (cpl b){(*this)=(*this)*b;}
}A[maxn],B[maxn],tmp,w[2][maxn];
int n,m,K,X,ans,ans2,r1,del,rev[maxn];
double th;

inline void read(int& x)
{
    x=0;char c=getchar();
    while(c>'9'||c<'0')c=getchar();
    while(c<='9'&&c>='0')x=x*10+c-'0',c=getchar();
}

void FFT(cpl* A,int r)
{
    for(int i=0;i<X;i++)if(i<rev[i])swap(A[i],A[rev[i]]);
    for(int i=1,l=X>>1;i<X;l>>=1,i<<=1)
        for(int j=0;j<X;j+=2*i)for(int k=0,l0=0;k<i;k++,l0+=l)
            tmp=A[i+j+k]*w[r][l0],A[i+j+k]=A[j+k]-tmp,A[j+k]=A[j+k]+tmp;
    if(r)for(int i=0;i<X;i++)A[i].x/=X;
}

int main()
{
    read(n),read(m);
    for(int i=0,a;i<n;i++)read(a),ans+=a*a,ans2+=a,A[i].x=a;
    for(int i=n-1,a;i>=0;i--)read(a),ans+=a*a,ans2-=a,B[i].x=a;
    for(X=1;X<n+n-1;X<<=1,K++);
    for(int i=0;i<X;i++)rev[i]=(rev[i>>1]>>1)|((i&1)<<K-1);
    for(int i=0;i<X;i++)
    {
        th=_2pi*i/X;
        w[0][i]=(cpl){cos(th),sin(th)},w[1][i]=(cpl){cos(-th),sin(-th)};
    }
    FFT(A,0),FFT(B,0);
    for(int i=0;i<X;i++)A[i]*=B[i];
    FFT(A,1);
    for(int i=n;i<n+n-1;i++)A[i-n].x+=A[i].x;
    for(int i=1;i<n;i++)if(A[i].x>A[0].x)A[0].x=A[i].x;
    if(ans2>=0)printf("%lld",ans-2*(LL)(A[0].x+1e-5));
    else
    {
        ans2=-ans2,r1=ans2/n;
        del=min(n*r1*r1-2*ans2*r1,n*(r1+1)*(r1+1)-2*ans2*(1+r1));
        printf("%lld",ans-2*(LL)(A[0].x+1e-5)+del);
    }
    return 0;
}
