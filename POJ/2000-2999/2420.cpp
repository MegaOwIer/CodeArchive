#include<cstdio>
#include<cmath>
using namespace std;

struct point {double x,y;}p[105];
int n,dx[]={0,1,0,-1,0},dy[]={0,0,-1,0,1};
void tuihuo();
double dis(point);

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)  scanf("%lf%lf",&p[i].x,&p[i].y);
	tuihuo();
	return 0;
}
void tuihuo()
{
	double t=100,eps=1e-8,q=.95,ans=1e15;
	point s=p[1];
	while(t>eps)
	{
		bool fl=1;
		while(fl)
		{
			fl=0;
			for(int i=1;i<5;i++)
			{
				point z;
				z.x=s.x+dx[i]*t;
				z.y=s.y+dy[i]*t;
				double tp=dis(z);
				if(ans>tp)  {ans=tp;  s=z;  fl=1;}
			}
	    }
		t*=q;
	}
	printf("%d",(int)(ans+0.5));
}
double dis(point u)
{
	double ans=0;
	for(int i=1;i<=n;i++)  ans+=sqrt((u.x-p[i].x)*(u.x-p[i].x)+(u.y-p[i].y)*(u.y-p[i].y));
	return ans;
}
