#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long LL;
typedef long double LD;
const int N=131072;
const LD _2Pi=2*acos(-1.0);

struct cpl
{
	LD x,y;
	cpl(LD x,LD y):x(x),y(y){}
	cpl(){}
}A[N],B[N],w[2][N],_x;
cpl operator + (cpl a,cpl b) {return cpl(a.x+b.x,a.y+b.y);}
cpl operator - (cpl a,cpl b) {return cpl(a.x-b.x,a.y-b.y);}
cpl operator * (cpl a,cpl b) {return cpl(a.x*b.x-a.y*b.y,a.x*b.y+a.y*b.x);}
int m,K,X=1,rev[N];
LD kpi;
char ch;

void print()
{
	int ret=2*m-1;
	for(int i=ret-1;i;i--)
	{
		A[i-1].x+=A[i].x/10;
		A[i].x=(LL)A[i].x%10;
	}
	for(int i=0;i<ret;i++)  printf("%lld",(LL)A[i].x);
}

void FFT(cpl a[],bool fl)
{
	for(int i=0;i<X;i++)  if(i<rev[i])  swap(a[i],a[rev[i]]);
	for(int i=1,l=X>>1;i<X;i<<=1,l>>=1)
		for(int j=0;j<X;j+=i*2)
			for(int k=0,l0=0;k<i;k++,l0+=l)
				_x=a[i+j+k]*w[fl][l0],a[i+j+k]=a[j+k]-_x,a[j+k]=a[j+k]+_x;
	if(fl)  for(int i=0;i<X;i++)  a[i].x/=X;
}

int main()
{
	scanf("%d",&m);  ch=getchar();
	for(int i=0;i<m;i++)  {ch=getchar();  A[i].x=ch-'0';}
	ch=getchar();
	for(int i=0;i<m;i++)  {ch=getchar();  B[i].x=ch-'0';}
	for(;X<m*2-1;X<<=1,K++);
	for(int i=1;i<X;i++)  rev[i]=(rev[i>>1]>>1)|((i&1)<<K-1);
	for(int i=0;i<X;i++)
	{
		kpi=_2Pi/X*i;
		w[0][i].x=w[1][i].x=cos(kpi);
		w[0][i].y=w[1][i].y=sin(kpi);  w[1][i].y=-w[1][i].y;
	}
	FFT(A,0),FFT(B,0);
	for(int i=0;i<X;i++)  A[i]=A[i]*B[i];
	FFT(A,1);
	print();
	return 0;
}
