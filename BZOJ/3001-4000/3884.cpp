#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn=1e7+5;

int ans[maxn],phi[maxn],prime[664600],cnt,T,n;
bool vis[maxn];
char c;

inline void read(int& x)
{
	x=0,c=getchar();
	while(!isdigit(c))c=getchar();
	while(isdigit(c))x=x*10+c-'0',c=getchar();
}
inline LL Pow(LL a,int b,int mod)
{
	LL ans=1;
	while(b)
	{
		if(b&1)ans=ans*a%mod;
		a=a*a%mod,b>>=1;
	}
	return ans;
}
inline int solve(int u)
{
	if(~ans[u])return ans[u];
	int k=0;
	while((u&1)==0)u>>=1,k++;
	int res=solve(phi[u]);
	res=(res+phi[u]-k%phi[u])%phi[u];
	res=Pow(2,res,u);
	return ans[u<<k]=(res<<k)%(u<<k);
}

int main()
{
	for(int i=2;i<=1e7;i++)
	{
		if(!vis[i])prime[++cnt]=i,phi[i]=i-1;
		for(int j=1;j<=cnt&&prime[j]*i<=1e7;j++)
		{
			vis[prime[j]*i]=1;
			if(i%prime[j]==0){phi[prime[j]*i]=phi[i]*prime[j];break;}
			phi[i*prime[j]]=phi[i]*(prime[j]-1);
		}
	}phi[1]=1;
	fill(ans+1,ans+(int)1e7+1,-1);
	read(T),ans[1]=0;
	while(T--)read(n),printf("%d\n",solve(n));
	return 0;
}
