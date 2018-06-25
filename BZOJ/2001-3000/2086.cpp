#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=1000005;

int n,m,a[maxn],k,sta[maxn],head,ans;
long long b[maxn];

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)  scanf("%d",a+i);
	while(m--)
	{
		scanf("%d",&k);  head=0;  ans=0;  b[1]=a[1]-k;
		for(int i=2;i<=n;i++)  b[i]=b[i-1]+a[i]-k;
		for(int i=1;i<=n;i++)  if(b[i]<b[sta[head]])  sta[++head]=i;
		for(int i=n,j=head;i>=0;i--)
		{
			while(j&&b[i]>=b[sta[j-1]])  j--;
			ans=max(ans,i-sta[j]);
		}
		printf(m?"%d ":"%d",ans);
	}
	return 0;
}
