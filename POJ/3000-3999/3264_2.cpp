#include<cstdio>
#include<algorithm>
using namespace std;

int n,q,mx[50001][20],mn[50001][20];

int ask(int l,int r)
{
	int lth=0;
	for(;(1<<lth)<=r-l+1;lth++);  lth--;
	int m=max(mx[l][lth],mx[r+1-(1<<lth)][lth]),n=min(mn[l][lth],mn[r+1-(1<<lth)][lth]);
	return m-n;
}

int main()
{
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)  {scanf("%d",&mx[i][0]);  mn[i][0]=mx[i][0];}
	for(int i=1;(1<<i)<=n;i++)  for(int j=1;(1<<i)+j<=n+1;j++)
	{
		mx[j][i]=max(mx[j][i-1],mx[j+(1<<(i-1))][i-1]);
		mn[j][i]=min(mn[j][i-1],mn[j+(1<<(i-1))][i-1]);
	}
	for(int i=1,a,b;i<=q;i++)
	{
		scanf("%d%d",&a,&b);
		printf("%d\n",ask(a,b));
	}
	return 0;
}
