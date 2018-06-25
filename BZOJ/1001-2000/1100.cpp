#include<bits/stdc++.h>
using namespace std;
const int MX=100005;
const double eps=1e-8;

namespace FastIO
{
	const int MXL=200000;
	struct Template
	{
		char Pool[MXL],*p1,*p2;
		FILE *F;
	};
	struct FastIn : Template
	{
		char c;
		int f;
		FastIn(FILE* _F){F=_F,p1=p2=Pool;}
		char getchar(){return p1==p2?(p2=(p1=Pool)+fread(Pool,1,MXL,F),p1==p2?EOF:*p1++):*p1++;}
		void operator()(int& x)
		{
			c=getchar(),f=0,x=0;
			while(!isdigit(c)){if(c=='-')f=1;c=getchar();}
			while(isdigit(c))x=x*10+c-'0',c=getchar();
			if(f)x=-x;
		}
	};
}

int T,N,nxt[MX];
FastIO::FastIn IN(stdin);

struct Point
{
	double x,y;
	Point(){}
	Point(double x,double y):x(x),y(y){}
	Point operator - (Point a){return Point(x-a.x,y-a.y);}
	double operator * (Point a){return x*a.y-y*a.x;}
	void operator += (Point a){x+=a.x,y+=a.y;}
	void operator /= (double t){x/=t,y/=t;}
	double length(){return sqrt(x*x+y*y);}
	double distance(Point a){return (a-*this).length();}
}p[MX],O;

struct Line
{
	double d1,d2,cro;
	Line(){}
	Line(double a,double b,double c):d1(a),d2(b),cro(c){}
	Line(Point& A,Point& B,Point& C)
	{
		d1=A.distance(B),d2=A.distance(C);
		cro=(B-A)*(C-A)/d1/d2;
	}
	bool operator == (const Line& a)const
	{
		return fabs(d1-a.d1)<eps&&fabs(d2-a.d2)<eps&&fabs(cro-a.cro)<eps;
	}
	bool operator != (const Line& a)const{return !(a==*this);}
}b[MX<<1],a[MX];

inline int KMP(int len)
{
	int ans=0;
	for(int i=2,j=0;i<=N;i++)
	{
		while(j&&a[i]!=a[j+1])j=nxt[j];
		if(a[j+1]==a[i])++j;
		nxt[i]=j;
	}
	for(int i=1,j=0;i<=len;i++)
	{
		while(j&&b[i]!=a[j+1])j=nxt[j];
		if(a[j+1]==b[i])++j;
		if(j==N)++ans,j=nxt[j];
	}
	return ans;
}

int main()
{
	IN(T);
	while(T--)
	{
		IN(N),O=Point(0.0,0.0);
		for(int i=1,x,y;i<=N;i++)IN(x),IN(y),p[i]=Point(x,y),O+=p[i];
		O/=N;
		for(int i=1;i<=N;i++)b[i]=b[i+N]=Line(O,p[i],p[i%N+1]);
		for(int i=N;i;i--)a[N-i+1]=Line(b[i].d2,b[i].d1,b[i].cro);
		printf("%d\n",KMP(N+N-1));
	}
	return 0;
}