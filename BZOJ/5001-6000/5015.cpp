#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int mod=1000000007;

LL N;
int K,ans,C[15][15],a[15];

inline int Pow(int a,int b)
{
	int ans=1;
	for(;b;b>>=1,a=(LL)a*a%mod)
		if(b&1)ans=(LL)ans*a%mod;
	return ans;
}
inline int f(int x)
{
	int ans=0;
	for(int i=K-1;~i;i--)ans=((LL)ans*x+a[i])%mod;
	return ans;
}

int main()
{
	scanf("%lld%d",&N,&K);
	for(int i=0;i<=K;i++)C[i][0]=1;
	for(int i=1;i<=K;i++)for(int j=1;j<=i;j++)C[i][j]=C[i-1][j-1]+C[i-1][j];
	for(int i=K-1;~i;i--)
	{
		a[i]=mod-C[K][i];
		for(int j=i+1;j<K;j++)a[i]=(a[i]+(LL)a[j]*C[j][i])%mod;
	}
	ans=((LL)Pow(2,(N-1)%(mod-1))*(mod+1-f(1))+f(N%mod))%mod;
	printf("%d",ans);
	return 0;
}
