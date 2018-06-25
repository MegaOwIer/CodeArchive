#include<bits/stdc++.h>
using namespace std;
const double eps=1e-6;

int N,ans;
struct Point
{
	double x,y;
	Point(double x=0,double y=0):x(x),y(y){}
	bool operator<(const Point& a)const{return fabs(x-a.x)>eps?x<a.x:y<a.y;}
	bool operator==(const Point& a){return fabs(x-a.x)<eps&&fabs(y-a.y)<eps;}
	Point operator+(const Point& a){return Point(x+a.x,y+a.y);}
	Point operator-(const Point& a){return Point(x-a.x,y-a.y);}
	double operator*(Point a){return x*a.y-y*a.x;}
	Point operator*(double a){return Point(x*a,y*a);}
	Point operator/(double a){return Point(x/a,y/a);}
	Point operator~(){return Point(y,-x);}
	double length(){return sqrt(x*x+y*y);}
	Point identity(){return (*this)/length();}
}p[105],O[105];
typedef Point Vector;
struct Line
{
	Point a,b;
	Line(){}
	Line(const Point& a,const Point& b):a(a),b(b){}
	bool operator^(Line& a){return dir()*a.dir();}
	Vector dir(){return b-a;}
	Vector normal(){return ~(b-a);}
	Line pb(){return Line((a+b)/2,(a+b)/2+normal());}
};

template<typename T>inline void read(T& x)
{
	static char c;
	static bool f=0;
	c=getchar(),x=0;
	while(!isdigit(c)){if(c=='-')f=1;c=getchar();}
	while(isdigit(c))x=x*10+c-'0',c=getchar();
	if(f)x=-x,f=0;
}
inline Point inter(Line& a,Line& b)
{
	static double k1,k2,t;
	k1=(b.b-a.a)*(a.b-a.a);
	k2=(a.b-a.a)*(b.a-a.a);
	t=k1/(k1+k2);
	return Point(b.b.x+(b.a.x-b.b.x)*t,b.b.y+(b.a.y-b.b.y)*t);
}
inline int get(int u,int v)
{
	int tmp=0,siz=0,ans=0;
	Line A=Line(p[u],p[v]).pb(),B;
	for(int i=1;i<=N;i++)if((i^u)&&(i^v))
	{
		B=Line(p[u],p[i]).pb();
		if(A^B)O[++siz]=inter(A,B);
	}
	sort(O+1,O+siz+1);
	O[++siz]=Point(1e20,1e20);
	for(int i=1;i<=siz;i++)
	{
		if(O[i]==O[i-1])tmp++;
		else ans=max(ans,tmp),tmp=1;
	}
	return ans;
}

int main()
{
	while(read(N),N)
	{
		for(int i=1;i<=N;i++)read(p[i].x),read(p[i].y);
		ans=0;
		for(int i=1;i<N;i++)for(int j=i+1;j<=N;j++)
			ans=max(ans,get(i,j));
		printf("%d\n",ans+2);
	}
	return 0;
}
