#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;

int ans[100001],T,N,i;
void InIt();

int main()
{
	InIt();
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&N);
		for(i=max(0,N-45);i<N;i++)  if(ans[i]==N)  {printf("%d\n",i);  break;}
		if(i==N)  printf("0\n");
	}
	return 0;
}
void InIt()
{
	int i=1;
	for(;i<10;i++)  ans[i]=2*i;
	for(;i<100;i++)  ans[i]=i+i/10+i%10;
	for(;i<1000;i++)  ans[i]=i+i%10+i/10%10+i/100;
	for(;i<10000;i++)  ans[i]=i+i%10+i/10%10+i/100%10+i/1000;
	for(;i<100000;i++)  ans[i]=i+i%10+i/10%10+i/100%10+i/1000%10+i/10000;
	ans[i]=i+1;
}
