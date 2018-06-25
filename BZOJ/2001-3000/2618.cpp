#include<bits/stdc++.h>
using namespace std;
const double eps=1e-8;

int N,k,cnt,tot=1,L=1,R=2;
struct Point
{
	double x,y;
	Point(double x=0,double y=0):x(x),y(y){}
	Point operator-(const Point& a)const{return Point(x-a.x,y-a.y);}
	double operator*(const Point& a)const{return x*a.y-y*a.x;}
}p[55],a[505];
struct Line
{
	Point a,b;
	double slop;
	Line(){}
	Line(const Point& a,const Point& b):a(a),b(b)
	{
		slop=atan2(b.y-a.y,b.x-a.x);
	}
	bool operator<(const Line& x)const
	{
		if(fabs(x.slop-slop)<eps)return (b-a)*(x.b-a)>eps;
		else return slop<x.slop;
	}
}l[505],q[505];
double ans;

template<typename T>inline void read(T& x)
{
	static char c;
	static int f;
	x=0,f=0,c=getchar();
	while(!isdigit(c)){if(c=='-')f=1;c=getchar();}
	while(isdigit(c))x=x*10+c-'0',c=getchar();
	if(f)x=-x;
}
inline Point inter(const Line& a,Line& b)
{
	static double k1,k2,t;
	k1=(b.b-a.a)*(a.b-a.a);
	k2=(a.b-a.a)*(b.a-a.a);
	t=k1/(k1+k2);
	return Point(b.b.x+(b.a.x-b.b.x)*t,b.b.y+(b.a.y-b.b.y)*t);
}
inline bool jud(Line& a,Line& b,Line& t){return (t.b-t.a)*(inter(a,b)-t.a)<-eps;}

int main()
{
	read(N);
	while(N--)
	{
		read(k);
		for(int i=1;i<=k;i++)read(p[i].x),read(p[i].y);
		p[k+1]=p[1];
		for(int i=1;i<=k;i++)l[++cnt]=Line(p[i],p[i+1]);
	}
	sort(l+1,l+cnt+1);
	for(int i=2;i<=cnt;i++)
	{
		if(l[i].slop!=l[i-1].slop)++tot;
		l[tot]=l[i];
	}
	cnt=tot,q[1]=l[1],q[2]=l[2];
	for(int i=3;i<=cnt;i++)
	{
		while(L<R&&jud(q[R-1],q[R],l[i]))R--;
		while(L<R&&jud(q[L+1],q[L],l[i]))L++;
		q[++R]=l[i];
	}
	while(L<R&&jud(q[R-1],q[R],q[L]))R--;
	while(L<R&&jud(q[L+1],q[L],q[R]))L++;
	q[R+1]=q[L],tot=0;
	for(int i=L;i<=R;i++)a[++tot]=inter(q[i],q[i+1]);
	a[tot+1]=a[1];
	if(tot<3)return puts("0.000"),0;
	for(int i=1;i<=tot;i++)ans+=a[i]*a[i+1];
	printf("%.3lf",fabs(ans)/2);
	return 0;
}
