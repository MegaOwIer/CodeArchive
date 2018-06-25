#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int mod=1e9+7,maxn=5e5+5;

int n,m,prime[41540],miu[maxn],cnt;
LL ans,ans0,ans1,ans2,ans3,pw[maxn],sum[maxn];
bool vis[maxn];

void init()
{
	for(int i=2;i<=n;i++)
	{
		if(!vis[i])prime[++cnt]=i,miu[i]=-1;
		for(int j=1;j<=cnt&&prime[j]*i<=n;j++)
		{
			vis[i*prime[j]]=1;
			if(i%prime[j]==0){miu[i*prime[j]]=0;break;}
			miu[i*prime[j]]=-miu[i];
		}
	}
}
inline LL Pow(LL a,int b)
{
	if(!a)return 0;
	LL ans=1;
	while(b)
	{
		if(b&1)ans=ans*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return ans;
}

int main()
{
	scanf("%d%d",&n,&m);
	if(n>m)swap(n,m);
	init(),miu[1]=1;
	for(int i=1;i<=m;i++)pw[i]=1;
	for(int d=1,i;d<=n;d++)
	{
		ans0=Pow(d,d),ans1=0;
		for(int i=1;i<=m/d;i++)pw[i]=pw[i]*i%mod,sum[i]=(sum[i-1]+pw[i])%mod;
		for(int k=1;k<=n/d;k++)if(miu[k])
			ans1=(ans1+mod+miu[k]*pw[k]*pw[k]%mod*sum[n/k/d]%mod*sum[m/k/d]%mod)%mod;
		ans=(ans+ans0*ans1)%mod;
	}
	printf("%lld",ans);
	return 0;
}
