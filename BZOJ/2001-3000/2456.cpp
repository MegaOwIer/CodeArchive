#include<cstdio>
using namespace std;

int n,now,cnt,x;

int main()
{
	scanf("%d",&n);
	n--,scanf("%d",&now),cnt=1;
	while(n--)
	{
		scanf("%d",&x);
		if(now==x)cnt++;
		else if(!cnt)now=x,cnt=1;
		else cnt--;
	}
	printf("%d\n",now);
}