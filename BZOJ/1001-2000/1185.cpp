#include<bits/stdc++.h>
using namespace std;
const int MX=50005;
const double eps=1e-8;

int N,top,fi;
double ans=1e30;

struct Point
{
	double x,y;
	Point(){}
	Point(double x,double y):x(x),y(y){}
	bool operator<(const Point& a)const{return fabs(y-a.y)<eps?x<a.x:y<a.y;}
	Point operator+(Point a){return Point(x+a.x,y+a.y);}
	Point operator-(Point a){return Point(x-a.x,y-a.y);}
	double operator*(Point a){return x*a.y-y*a.x;}
	double operator/(Point a){return x*a.x+y*a.y;}
	Point operator*(double a){return Point(x*a,y*a);}
	Point operator/(double a){return Point(x/a,y/a);}
	void read(){scanf("%lf%lf",&x,&y);}
	double length(){return sqrt(x*x+y*y);}
}p[MX],q[MX],t[5];

inline bool cmp(Point a,Point b)
{
	double t=(a-p[1])*(b-p[1]);
	if(fabs(t)<eps)return (p[1]-a).length()<(p[1]-b).length();
	return t>0;
}

inline void getConvexHull()
{
	for(int i=2;i<=N;i++)if(p[i]<p[1])swap(p[1],p[i]);
	sort(p+2,p+N+1,cmp);
	q[++top]=p[1];
	for(int i=2;i<=N;i++)
	{
		while(top>1&&(q[top]-q[top-1])*(p[i]-q[top])<eps)top--;
		q[++top]=p[i];
	}
	q[0]=q[top];
}
inline void RotatingCaliper()
{
	int l=1,r=1,p=1;
	double L,R,D,P,tmp;
	for(int i=0;i<top;i++)
	{
		D=(q[i]-q[i+1]).length();
		while((q[i+1]-q[i])*(q[p+1]-q[i])-(q[i+1]-q[i])*(q[p]-q[i])>-eps)p=(p+1)%top;
		while((q[i+1]-q[i])/(q[r+1]-q[i])-(q[i+1]-q[i])/(q[r]-q[i])>-eps)r=(r+1)%top;
		if(!i)l=r;
		while((q[i+1]-q[i])/(q[l+1]-q[i])-(q[i+1]-q[i])/(q[l]-q[i])<eps)l=(l+1)%top;
		L=(q[i+1]-q[i])/(q[l]-q[i])/D,R=(q[i+1]-q[i])/(q[r]-q[i])/D;
		P=fabs((q[i+1]-q[i])*(q[p]-q[i])/D);
		tmp=(R-L)*P;
		if(tmp<ans)
		{
			ans=tmp;
			t[0]=q[i]+(q[i+1]-q[i])*(R/D);
			t[1]=t[0]+(q[r]-t[0])*(P/(t[0]-q[r]).length());
			t[2]=t[1]-(t[0]-q[i])*((R-L)/(q[i]-t[0]).length());
			t[3]=t[2]-t[1]+t[0];
		}
	}
}

int main()
{
	scanf("%d",&N);
	for(int i=1;i<=N;i++)p[i].read();
	getConvexHull(),RotatingCaliper();
	printf("%.5lf\n",ans);
	for(int i=1;i<4;i++)if(t[i]<t[fi])fi=i;
	for(int i=0;i<4;i++)
		printf("%.5lf %.5lf\n",t[(i+fi)&3].x,t[(i+fi)&3].y);
	return 0;
}