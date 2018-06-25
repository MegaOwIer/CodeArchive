#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
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
int f[maxn],g[maxn],l1,l2,K,X,ans,rev[maxn],a[maxn];
char s2[maxn],s1[maxn];
LL sum,val[maxn];

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
    scanf("%s%s",s1,s2);
    l1=strlen(s1),l2=strlen(s2);
    for(int i=0;i<l1;i++)f[i]=s1[i]-'a'+1;
    for(int i=0;i<l2;i++)g[i]=(s2[i]=='?')?0:s2[i]-'a'+1,sum+=g[i]*g[i]*g[i];
    for(X=1;X<l1+l2-1;X<<=1,K++);
    for(int i=0;i<X;i++)rev[i]=(rev[i>>1]>>1)|((i&1)<<K-1);
    for(int i=0;i<X;i++)
    {
    	double th=_2pi*i/X;
    	w[0][i]=(cpl){cos(th),sin(th)},w[1][i]=(cpl){cos(-th),sin(-th)};
    }
    for(int i=0;i<l1;i++)A[i].x=f[i]*f[i];FFT(A,0);
    for(int i=0;i<l2;i++)B[i].x=g[l2-1-i];FFT(B,0);
    for(int i=0;i<X;i++)A[i]*=B[i];FFT(A,1);
    for(int i=l2-1;i<l1;i++)val[i-l2+1]=(LL)(A[i].x+1e-5);
    memset(A,0,sizeof(A)),memset(B,0,sizeof(B));
    for(int i=0;i<l1;i++)A[i].x=f[i];FFT(A,0);
    for(int i=0;i<l2;i++)B[i].x=g[l2-1-i]*g[l2-1-i];FFT(B,0);
    for(int i=0;i<X;i++)A[i]*=B[i];FFT(A,1);
    for(int i=l2-1;i<l1;i++)val[i-l2+1]-=(LL)(2*A[i].x+1e-5);
    for(int i=0;i<=l1-l2;i++)if(val[i]==-sum)a[++ans]=i;
    printf("%d\n",ans);
    for(int i=1;i<=ans;i++)printf("%d\n",a[i]);
    return 0;
}
