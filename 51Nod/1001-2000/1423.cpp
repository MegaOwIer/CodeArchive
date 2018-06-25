#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=100005;

int n,x[maxn],sta[maxn],head,ans;

int main()
{
	sta[0]=0x7fffffff;
	while(scanf("%d",&n)==1)
	{
		for(int i=1;i<=n;i++)  scanf("%d",x+i);
		ans=0;  head=0;
		for(int i=1;i<=n;i++)
		{
			while(sta[head]<x[i])  ans=max(ans,sta[head]^x[i]),head--;
			sta[++head]=x[i];
		}
		head=0;
		for(int i=n;i;i--)
		{
			while(sta[head]<x[i])  ans=max(ans,sta[head]^x[i]),head--;
			sta[++head]=x[i];
		}
		printf("%d\n",ans);
	}
	return 0;
}
