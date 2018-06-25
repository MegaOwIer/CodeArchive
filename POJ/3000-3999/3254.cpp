#include<cstdio>
#include<algorithm>
using namespace std;
const int mod=100000000;

int n,m,g[15],sta[380],cnt,a,dp[15][380],ans;

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=0;i<(1<<m);i++)if((i&(i<<1))==0)sta[++cnt]=i;
	for(int i=1;i<=n;i++)for(int j=0;j<m;j++){scanf("%d",&a),g[i]<<=1;if(a)g[i]++;}
	for(int i=1;i<=cnt;i++)if(((~g[1])&sta[i])==0)dp[1][i]=1;
	for(int i=2;i<=n;i++)for(int j=1;j<=cnt;j++)if(((~g[i])&sta[j])==0)
		for(int k=1;k<=cnt;k++)if((sta[j]&sta[k])==0)dp[i][j]=(dp[i][j]+dp[i-1][k])%mod;
	for(int i=1;i<=cnt;i++)ans=(ans+dp[n][i])%mod;
	printf("%d",ans);
	return 0;
}
