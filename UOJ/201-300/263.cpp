#include<cstdio>
#include<algorithm>
using namespace std;

int t,k,n,m,C[2005][2005],ans,cnt[2005][2005];

void init()
{
	for(int i=0;i<=2000;i++)  C[i][0]=1;
	for(int i=1;i<=2000;i++)  for(int j=1;j<=i;j++)
	{
		C[i][j]=(C[i-1][j]+C[i-1][j-1])%k;
		cnt[i][j]=cnt[i][j-1];
		if(!C[i][j])  cnt[i][j]++;
	}
}

int main()
{
	scanf("%d%d",&t,&k);  init();
	while(t--)
	{
		scanf("%d%d",&n,&m);
		ans=0;
		for(int i=2;i<=n;i++)  ans+=cnt[i][min(i,m)];
		printf("%d\n",ans);
	}
	return 0;
}
