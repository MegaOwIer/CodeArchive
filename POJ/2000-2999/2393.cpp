#include<cstdio>
#include<algorithm>
using namespace std;

int n,s,mi=10000;
long long ans;

int main()
{
	scanf("%d%d",&n,&s);
	for(int i=1,c,y;i<=n;i++)
	{
		scanf("%d%d",&c,&y);
		mi=min(mi+s,c);
		ans+=mi*y;
	}
	printf("%lld",ans);
	return 0;
}
