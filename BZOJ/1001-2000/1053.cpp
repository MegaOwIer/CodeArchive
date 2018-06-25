#include<cstdio>
#include<cmath>
#include<algorithm> 
using namespace std;
typedef long long LL;
const int p[]={0,2,3,5,7,11,13,17,19,23,29,31};

LL n,ans,num1;

void dfs(int u,LL now,LL num)
{
	if(now>n||u>11)  return; 
	if(num>num1)  num1=num,ans=now;
	if(num==num1&&now<ans)  ans=now;
	int maxn=(int)(log(n)/log(p[u]));
	dfs(u+1,now*p[u],num<<1); 
	for(int i=1;i<=maxn;i++)
	{
		now*=p[u];
		dfs(u+1,now,num*(i+1));
	}
}

int main()
{
	while(scanf("%lld",&n)!=EOF)ans=num1=0LL,dfs(1,1,1),printf("%lld",ans);
	return 0;
}
