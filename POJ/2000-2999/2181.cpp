#include<cstdio>
#include<algorithm>
using namespace std;

int n,w[150001],ans;
bool fl;

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)  scanf("%d",&w[i]);
	for(int i=1;i<=n;i++)
	{
		if(w[i]>=w[i+1]&&w[i]>=w[i-1]&&!fl)  ans+=w[i],fl=!fl;
		if(w[i]<=w[i+1]&&w[i]<=w[i-1]&&fl)  ans-=w[i],fl=!fl;
	}
	printf("%d",ans);
	return 0;
}
