#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int n,a[10001];

int main()
{
	while(scanf("%d",&n)!=EOF)
	{
		memset(a,0,sizeof(a));
		for(int i=1;i<=n;i++)  scanf("%d",&a[i]);
		sort(a+1,a+n+1);
		printf("%d\n",a[n/2+1]);
    }
	return 0;
}
