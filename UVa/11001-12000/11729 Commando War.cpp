#include<cstdio>
#include<functional>
#include<algorithm>
using namespace std;

int N,cnt;
struct job {int b,j;}p[1005];
bool operator < (job a,job b) {return a.j>b.j;}

int main()
{
	while(scanf("%d",&N)==1&&N)
	{
		int ans=0,st=0;
		for(int i=1;i<=N;i++)  scanf("%d%d",&p[i].b,&p[i].j);
		sort(p+1,p+N+1);
		for(int i=1;i<=N;i++)
		{
			st+=p[i].b;
			ans=max(ans,st+p[i].j);
		}
		printf("Case %d: %d\n",++cnt,ans);
	}
	return 0;
}
