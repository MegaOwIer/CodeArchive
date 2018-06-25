#include<cstdio>
#include<algorithm>
using namespace std;

int n,m,a[20005],b[20005];

int main()
{
	while(scanf("%d%d",&n,&m)==2&&m&&n)
	{
		int ans=0;
		for(int i=1;i<=n;i++)  scanf("%d",a+i);  sort(a+1,a+n+1);
		for(int i=1;i<=m;i++)  scanf("%d",b+i);  sort(b+1,b+m+1);
		int j=1;
		for(int i=1;i<=m;i++)  if(b[i]>=a[j])
		{
			ans+=b[i];
			if(++j>n)  break;
		}
		if(j>n)  printf("%d\n",ans);
		else  puts("Loowater is doomed!");
	}
	return 0;
}
