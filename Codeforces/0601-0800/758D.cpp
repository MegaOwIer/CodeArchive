#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;

long long n,m=1,ans;
char k[65];

long long solve(int lt,int rt)
{
	long long ans=0;
	for(int i=lt;i<=rt;i++)  ans=ans*10+k[i]-'0';
	return ans;
}

int main()
{
	scanf("%lld%s",&n,k);
	int lt=strlen(k),now=lt-1,lt2=log10(n)+1;
	for(int i=now;i>=0;i--)
	{
		bool fl=0;
		for(int j=max(0,now-lt2+1);j<=now;j++)  if(k[j]!='0')
		{
			long long r1=solve(j,now);
			if(r1>=n)  continue;
			ans+=m*r1;  now=j-1;  fl=1;  break;
		}
		if(!fl)  now--;  m*=n;
	}
	printf("%lld\n",ans);
	return 0;
}
