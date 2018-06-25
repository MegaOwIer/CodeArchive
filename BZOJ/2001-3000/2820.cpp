#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn=10000005;

int T,n,m,prime[664580],cnt,f[maxn];
short miu[maxn];
bool vis[maxn];
long long ans;

template<typename T>
inline void read(T& x)
{
	x=0;char ch=getchar();
	while(ch<'0'||ch>'9')  ch=getchar();
	while(ch>='0'&&ch<='9')  x=x*10+ch-'0',ch=getchar();
}
void init()
{
	miu[1]=1;
	for(int i=2;i<=maxn-5;i++)
	{
		if(!vis[i])  prime[++cnt]=i,miu[i]=-1;
		for(int j=1;j<=cnt&&(LL)i*prime[j]<=maxn-5;j++)
		{
			int t=i*prime[j];vis[t]=1;
			if(i%prime[j]==0){miu[t]=0;break;}
			miu[t]=-miu[i];
		}
	}
	for(int i=1;i<=cnt;i++)  for(int j=1;j<=(maxn-5)/prime[i];j++)  f[prime[i]*j]+=miu[j];
	for(int i=2;i<=maxn-5;i++)  f[i]+=f[i-1];
}

int main()
{
	init();
	read(T);
	while(T--)
	{
		read(n),read(m),ans=0LL;
		for(int i=1,pos;i<=m&&i<=n;i=pos+1)
		{
			pos=min(m/(m/i),n/(n/i));
			ans+=(LL)(n/i)*(m/i)*(f[pos]-f[i-1]);
		}
		printf("%lld\n",ans);
	}
	return 0;
}
