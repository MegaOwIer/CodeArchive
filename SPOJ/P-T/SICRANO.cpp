#include<bits/stdc++.h>
using namespace std;

struct Point
{
	int x,y;
	Point(int x=0,int y=0):x(x),y(y){}
	Point operator-(const Point& a)const{return Point(x-a.x,y-a.y);}
	int operator*(const Point& a)const{return x*a.y-y*a.x;}
}p[55],a,b,a1,b1;
int T,N,M,ans;

inline void read(int& x)
{
	static char c;
	x=0,c=getchar();
	while(!isdigit(c))c=getchar();
	while(isdigit(c))x=x*10+c-'0',c=getchar();
}

int main()
{
	read(T);
	while(T--)
	{
		read(N),read(M);
		for(int i=1;i<=N;i++)read(p[i].x),read(p[i].y);
		while(M--)
		{
			ans=0;
			read(a.x),read(a.y),read(b.x),read(b.y);
			for(int i=1;i<=N;i++)
			{
				a1=p[i]-a,b1=p[i]-b;
				if(a1*b1==0)ans+=(a1.x*b1.x<=0&&a1.y*b1.y<=0);
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}
