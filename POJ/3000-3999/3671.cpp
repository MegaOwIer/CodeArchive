#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int a[30005],n,ans;
char ch;

int main()
{
	while(scanf("%d%*c",&n)!=EOF)
	{
		memset(a,0,sizeof(a));  ans=0x7fffffff;
		for(int i=1;i<=n;i++)
		{
			ch=getchar();
			if(ch=='1')  a[i]=a[i-1]+1;
			else  a[i]=a[i-1];
			ch=getchar();
		}
		for(int i=0;i<=n;i++)  ans=min(ans,i-a[i]+a[n]-a[i]);
		printf("%d\n",ans);
	}
	return 0;
}
