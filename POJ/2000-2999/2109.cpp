#include<cstdio>
#include<cmath>

double n,p;

int main()
{
	while(scanf("%lf%lf",&n,&p)==2&&n&&p)  printf("%d\n",(int) (pow(p,1.0/n)+0.5));
	return 0;
}
