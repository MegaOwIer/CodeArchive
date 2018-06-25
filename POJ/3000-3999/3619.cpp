#include<cstdio>
#include<cmath>
using namespace std;

int n,k;

int main()
{
	while(scanf("%d%d",&n,&k)!=EOF)  while(k--)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		int m=a*b;
		int ff=n/m*(b+c)+ceil(n%m/(double) a);
		if(n%m==0)  ff-=c;
		printf("%d\n",ff);
	}
	return 0;
}
