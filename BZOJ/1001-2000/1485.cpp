#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn=2000505;

int prime[149050],cnt,n,mod;
bool vis[maxn];
LL ans=1,po[149050];

inline LL Pow(int a,LL b)
{
	LL res=a,ans=1LL;
	while(b)
	{
		if(b&1)ans=ans*res%mod;
		res=res*res%mod;
		b>>=1;
	}
	return ans;
}

int main()
{
	scanf("%d%d",&n,&mod);
	prime[cnt=1]=2;
	for(int i=3;i<=2000050;i+=2)  if(!vis[i])
	{
		prime[++cnt]=i;
		for(int j=i*2;j<=2000050;j+=i)vis[j]=1;
	}
	for(int i=1;prime[i]<=n*2;i++)  for(int ret=n*2/prime[i];ret;po[i]+=ret,ret/=prime[i]);
    for(int i=1;prime[i]<=n;i++)  for(int ret=n/prime[i];ret;po[i]-=ret,ret/=prime[i]);
    for(int i=1;prime[i]<=n+1;i++)  for(int ret=(n+1)/prime[i];ret;po[i]-=ret,ret/=prime[i]);
	for(int i=1;prime[i]<=n*2;i++)  ans=ans*Pow(prime[i],po[i])%mod;
	printf("%lld\n",ans);
}
