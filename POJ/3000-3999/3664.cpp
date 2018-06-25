#include<cstdio>
#include<algorithm>
#include<functional>
using namespace std;

struct cow {int id,rk1,rk2;}c[50005];
bool operator < (cow a,cow b) {return a.rk1>b.rk1;}
bool operator > (cow a,cow b) {return a.rk2>b.rk2;}
int n,k;

int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)  {scanf("%d%d",&c[i].rk1,&c[i].rk2);  c[i].id=i;}
	sort(c+1,c+n+1);  sort(c+1,c+k+1,greater<cow>());
	printf("%d",c[1].id);
	return 0;
}
