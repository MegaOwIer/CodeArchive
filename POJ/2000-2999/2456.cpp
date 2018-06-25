#include<cstdio>
#include<functional>
#include<cmath>
#include<algorithm>
using namespace std;

int n,c,x[100005],now,mn,mx;
bool ok(int);

int main()
{
	scanf("%d%d",&n,&c);
	for(int i=1;i<=n;i++)  scanf("%d",&x[i]);
	sort(x+1,x+n+1,less<int>());
	mx=(x[n]-x[1])/(c-1)+9;
	now=mx/2;
	while(mx-mn>1)
	{
		if(ok(now))  mn=now;
		else  mx=now;
		now=(mx+mn)/2;
	}
	printf("%d",now);
	return 0;
}
bool ok(int u)
{
	int goal=x[1]+u,now=2,left=c-1;
	for(int i=2;i<=c;i++)
	{
		while(x[now]<goal&&now<=n)  now++;
		if(x[now]>=goal)  left--;
		goal=x[now]+u;
	}
	return !left;
}
