#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;

bool cmp(int a,int b) {return abs(a)<abs(b);}
int t,n,w[50001],ans=1;

int main()
{
	scanf("%d%d",&t,&n);
	for(int i=1;i<=n;i++)  scanf("%d",&w[i]);
	sort(w+1,w+n+1,cmp);
	for(;t>=abs(w[ans]-w[ans-1]);ans++)  t-=abs(w[ans]-w[ans-1]);
	printf("%d",ans-1);
	return 0;
}
