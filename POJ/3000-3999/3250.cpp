#include<cstdio>
#include<stack>
using namespace std;

int n,h[80005],cnt;
long long ans;
stack<int> cow;

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)  scanf("%d",&h[i]);
	cow.push(h[1]);
	for(int i=2;i<=n;i++)
	{
		bool flag=1;
		while(h[i]>=cow.top())  {cow.pop();  if(cnt)  cnt--;  if(cow.empty())  {flag=0;  break;}}
		cow.push(h[i]);  if(flag)  cnt++;
		ans+=cnt;
	}
	printf("%lld",ans);
	return 0;
}
