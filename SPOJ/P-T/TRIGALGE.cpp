#include<bits/stdc++.h>
using namespace std;
const double eps=1e-6;

int T,A,B,C;
double ans;

inline double f(double x){return A*x+B*sin(x)-C;}
inline double df(double x){return A+B*cos(x);}
inline void read(int& x)
{
	static char c;
	static int f;
	x=0,c=getchar(),f=0;
	while(!isdigit(c)){if(c=='-')f=1;c=getchar();}
	while(isdigit(c))x=x*10+c-'0',c=getchar();
	if(f)x=-x;
}

int main()
{
	read(T);
	while(T--)
	{
		read(A),read(B),read(C);
		ans=(double)C/A;
		while(fabs(f(ans))>eps)
			ans-=f(ans)/df(ans);
		printf("%.6lf\n",ans);
	}
	return 0;
}
