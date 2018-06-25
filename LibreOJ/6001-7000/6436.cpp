#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef vector<int>::iterator Vit;
const int MX=1048577,MN=500005;
const double _2pi=acos(-1.0)*2,eps=1e-5;

int N,rev[MX],K,X=1;
vector<int> d[MN];
LL ans;
bool invilid[MN];
char s[MN];

struct Complex
{
    double x,y;

    Complex(double x=0,double y=0):x(x),y(y){}
    Complex operator + (Complex a){return Complex(x+a.x,y+a.y);}
    Complex operator - (Complex a){return Complex(x-a.x,y-a.y);}
    Complex operator * (Complex a){return Complex(x*a.x-y*a.y,x*a.y+y*a.x);}
    void operator /= (double a){x/=a,y/=a;}
}A[MX],B[MX],w[2][MX];

void DFT(Complex *A,int r)
{
    for(int i=0;i<X;i++)if(i<rev[i])swap(A[i],A[rev[i]]);
    for(int i=1,l=X>>1;i<X;i<<=1,l>>=1)
        for(int j=0;j<X;j+=i*2)for(int k=0,l0=0;k<i;k++,l0+=l)
        {
            Complex tmp=A[i+j+k]*w[r][l0];
            A[i+j+k]=A[j+k]-tmp,A[j+k]=A[j+k]+tmp;
        }
    if(r)for(int i=0;i<X;i++)A[i]/=X;
}

int main()
{
    scanf("%s",s),N=strlen(s);
    for(int i=2;i<=N;i++)if(d[i].empty())
        for(int j=i;j<=N;j+=i)d[j].push_back(i);
    for(int i=0;i<N;i++)
        if(s[i]=='0')A[i]=1;
        else if(s[i]=='1')B[N-i]=1;
    for(;X<=N+N;K++,X<<=1);
    for(int i=1;i<X;i++)rev[i]=(rev[i>>1]>>1)|((i&1)<<K-1);
    for(int i=0;i<X;i++)
    {
        double th=_2pi/X*i;
        w[0][i]=Complex(cos(th),sin(th)),w[1][i]=Complex(cos(th),-sin(th));
    }
    DFT(A,0),DFT(B,0);
    for(int i=0;i<X;i++)A[i]=A[i]*B[i];
    DFT(A,1);
    for(int i=0;i<N;i++)if(int(A[i].x+eps)!=0)invilid[N-i]=1;
    for(int i=N;i<N+N;i++)if(int(A[i].x+eps)!=0)invilid[i-N]=1;
    for(int i=N-1;i>=0;i--)
        if(invilid[i])
        {
            invilid[1]=1;
            for(Vit it=d[i].begin();it!=d[i].end();++it)
                invilid[i/ *it]=1;
        }
        else ans^=LL(N-i)*(N-i);
    printf("%lld\n",ans);
    return 0;
}
